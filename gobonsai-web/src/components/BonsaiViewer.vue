<script setup lang="ts">
import { onMounted, ref, onUnmounted, watch } from "vue";
import * as THREE from "three";
import { BonsaiController } from "@/engine/BonsaiController";
import { BonsaiAudio } from "@/engine/BonsaiAudio";
import { DEBUG_WIREFRAME, setDebugWireframe } from "@/engine/TreeSection";
import { PotService } from "@/engine/PotService";
import { EnvironmentService } from "@/engine/EnvironmentService";

import { OrbitControls } from "three/examples/jsm/controls/OrbitControls.js";
import { EffectComposer } from "three/examples/jsm/postprocessing/EffectComposer.js";
import { RenderPass } from "three/examples/jsm/postprocessing/RenderPass.js";
import { UnrealBloomPass } from "three/examples/jsm/postprocessing/UnrealBloomPass.js";
import { OutputPass } from "three/examples/jsm/postprocessing/OutputPass.js";

const props = defineProps<{
  settings: {
    timeSpeed: number;
    manualLight: boolean;
    manualLightValue: number;
    interactionMode: "water" | "prune" | "wire";
  };
}>();

const canvasContainer = ref<HTMLElement | null>(null);
const emit = defineEmits(["update-stats"]);

let renderer: THREE.WebGLRenderer;
let scene: THREE.Scene;
let camera: THREE.PerspectiveCamera;
let controls: OrbitControls;
let composer: EffectComposer;
let bonsai: BonsaiController;
let audio: BonsaiAudio;
let animationId: number;
const clock = new THREE.Clock();
let particles: THREE.Points;
let particleGeometry: THREE.BufferGeometry;
let particlePositions: Float32Array;
let particleVelocities: THREE.Vector3[] = [];
const PARTICLE_COUNT = 100;

type SectionLike = {
  group: THREE.Group;
  mesh: THREE.Group;
  children: SectionLike[];
  branchPosition: number;
  isContinuation?: boolean;
};

type HighlightState = {
  section: SectionLike;
  segmentIndex: number;
  mode: "prune" | "wire";
};

let highlightedState: HighlightState | null = null;
const highlightedMeshes = new Set<THREE.Mesh>();
const mouse = new THREE.Vector2();
const raycaster = new THREE.Raycaster();

const exportBonsai = () => {
  if (bonsai) {
    bonsai.saveState();
    const data = localStorage.getItem("gobonsai_state");
    if (data) {
      const blob = new Blob([data], { type: "application/json" });
      const url = URL.createObjectURL(blob);
      const a = document.createElement("a");
      a.href = url;
      a.download = `bonsai_${new Date().toISOString().slice(0, 10)}.json`;
      a.click();
      URL.revokeObjectURL(url);
    }
  }
};

const importBonsai = () => {
  const input = document.createElement("input");
  input.type = "file";
  input.accept = ".json";
  input.onchange = (e: any) => {
    const file = e.target.files[0];
    if (!file) return;
    const reader = new FileReader();
    reader.onload = (e: any) => {
      const json = e.target.result as string;
      try {
        localStorage.setItem("gobonsai_state", json);
        window.location.reload();
      } catch (err) {
        console.error("Failed to import", err);
      }
    };
    reader.readAsText(file);
  };
  input.click();
};

defineExpose({
  exportBonsai,
  importBonsai,
});

watch(
  () => props.settings.timeSpeed,
  (val) => {
    if (bonsai) bonsai.setTimeSpeed(val);
  },
);

watch(
  () => props.settings.manualLightValue,
  (val) => {
    if (bonsai) bonsai.setLightIntensity(val);
  },
);

onMounted(() => {
  if (!canvasContainer.value) return;

  scene = new THREE.Scene();
  scene.background = new THREE.Color(0x0a0a0a);

  camera = new THREE.PerspectiveCamera(
    75,
    window.innerWidth / window.innerHeight,
    0.1,
    1000,
  );
  camera.position.set(0, 4.2, 11.5);
  camera.lookAt(0, 1.8, 0);

  renderer = new THREE.WebGLRenderer({ antialias: true });
  renderer.setSize(window.innerWidth, window.innerHeight);
  renderer.setPixelRatio(window.devicePixelRatio);
  renderer.shadowMap.enabled = true;
  renderer.shadowMap.type = THREE.PCFSoftShadowMap;
  canvasContainer.value.appendChild(renderer.domElement);

  controls = new OrbitControls(camera, renderer.domElement);
  controls.enableDamping = true;
  controls.dampingFactor = 0.05;
  controls.minDistance = 3;
  controls.maxDistance = 28;
  controls.minPolarAngle = 0;
  controls.maxPolarAngle = Math.PI / 1.8;
  controls.target.set(0, 1.8, 0);
  controls.update();

  const renderScene = new RenderPass(scene, camera);
  const bloomPass = new UnrealBloomPass(
    new THREE.Vector2(window.innerWidth, window.innerHeight),
    0.22,
    0.35,
    0.92,
  );

  composer = new EffectComposer(renderer);
  composer.addPass(renderScene);
  composer.addPass(bloomPass);
  composer.addPass(new OutputPass());

  const ambientLight = new THREE.AmbientLight(0xfff5ee, 0.52);
  scene.add(ambientLight);

  const hemisphereLight = new THREE.HemisphereLight(0xe8f0ff, 0x4a3528, 1.05);
  scene.add(hemisphereLight);

  const directionalLight = new THREE.DirectionalLight(0xfff8f0, 1.45);
  directionalLight.position.set(5, 12, 8);
  directionalLight.castShadow = true;
  directionalLight.shadow.mapSize.width = 2048;
  directionalLight.shadow.mapSize.height = 2048;
  directionalLight.shadow.camera.near = 0.5;
  directionalLight.shadow.camera.far = 50;
  scene.add(directionalLight);

  const fillLight = new THREE.DirectionalLight(0xb8c8e8, 0.38);
  fillLight.position.set(-6, 4, -4);
  scene.add(fillLight);

  const pointLight = new THREE.PointLight(0xffcc88, 0, 50);
  pointLight.position.set(-5, 5, -5);
  scene.add(pointLight);

  bonsai = new BonsaiController(scene);
  audio = new BonsaiAudio();

  bonsai.setLogCallback((msg, type) => {
    emit("update-stats", {
      logEntry: { message: msg, time: Date.now(), type },
    });
  });

  createEnvironment(scene);
  initParticles(scene);

  const animate = () => {
    animationId = requestAnimationFrame(animate);
    const deltaTime = clock.getDelta();

    if (bonsai) {
      bonsai.update(deltaTime);

      directionalLight.intensity = Math.max(0.1, bonsai.lightIntensity * 2);
      ambientLight.intensity = Math.max(0.18, bonsai.lightIntensity * 0.42);
      fillLight.intensity = Math.max(0.08, bonsai.lightIntensity * 0.4);
      if (pointLight)
        pointLight.intensity = Math.max(0, (1 - bonsai.lightIntensity) * 0.45);

      const bgColorVal = new THREE.Color(0x050505).lerp(
        new THREE.Color(0x1a1a2e),
        bonsai.lightIntensity,
      );
      scene.background = bgColorVal;

      audio.updateWind(bonsai.lightIntensity, props.settings.timeSpeed);

      emit("update-stats", {
        age: bonsai.age,
        targetAge: bonsai.targetAge,
        gameTime: bonsai.gameTime,
        simulationDay: bonsai.simulationDay,
        energy: bonsai.energy,
        health: bonsai.health,
        light: bonsai.lightIntensity,
      });
    }

    updateParticles();
    updateHighlight();
    controls.update();
    composer.render();
  };

  const updateHighlight = () => {
    if (
      !bonsai ||
      (props.settings.interactionMode !== "prune" &&
        props.settings.interactionMode !== "wire")
    ) {
      resetHighlight();
      return;
    }

    raycaster.setFromCamera(mouse, camera);
    const intersects = raycaster.intersectObjects(scene.children, true);

    let found: HighlightState | null = null;
    for (const intersect of intersects) {
      const hit = resolveSectionHit(intersect.object);
      if (!hit) continue;
      if (
        props.settings.interactionMode === "prune" &&
        hit.section === (bonsai.root as unknown as SectionLike)
      ) {
        continue;
      }
      found = {
        section: hit.section,
        segmentIndex: hit.segmentIndex,
        mode: props.settings.interactionMode,
      };
      break;
    }

    if (!statesEqual(found, highlightedState)) {
      resetHighlight();
      if (found) {
        highlightedState = found;
        applyHighlight(found);
      }
    }
  };

  const resetHighlight = () => {
    if (highlightedMeshes.size > 0) {
      for (const mesh of highlightedMeshes) {
        if (!(mesh.material instanceof THREE.MeshStandardMaterial)) continue;
        mesh.material.emissive.setHex(0x000000);
        mesh.material.emissiveIntensity = 0;
        if (mesh.userData?.segmentOverlay && mesh.material.transparent) {
          mesh.material.opacity = 0;
        }
      }
      highlightedMeshes.clear();
    }
    highlightedState = null;
  };

  const markMesh = (mesh: THREE.Mesh, color: number, intensity: number) => {
    if (!(mesh.material instanceof THREE.MeshStandardMaterial)) return;
    mesh.material.emissive.setHex(color);
    mesh.material.emissiveIntensity = intensity;
    if (mesh.userData?.segmentOverlay && mesh.material.transparent) {
      mesh.material.opacity = Math.max(mesh.material.opacity, 0.38);
    }
    highlightedMeshes.add(mesh);
  };

  const markGroup = (group: THREE.Group, color: number, intensity: number) => {
    group.traverse((obj) => {
      if (
        obj instanceof THREE.Mesh &&
        obj.material instanceof THREE.MeshStandardMaterial
      ) {
        markMesh(obj, color, intensity);
      }
    });
  };

  const statesEqual = (a: HighlightState | null, b: HighlightState | null) => {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return (
      a.section === b.section &&
      a.segmentIndex === b.segmentIndex &&
      a.mode === b.mode
    );
  };

  const getSegmentMeshes = (section: SectionLike): THREE.Mesh[] =>
    section.mesh.children.filter(
      (child): child is THREE.Mesh =>
        child instanceof THREE.Mesh && !!child.userData?.isSegment,
    );

  const getSegmentCount = (section: SectionLike): number =>
    Math.max(1, getSegmentMeshes(section).length);

  const clampSegmentIndex = (section: SectionLike, idx: number): number =>
    Math.max(0, Math.min(getSegmentCount(section) - 1, idx));

  const collectAllDescendants = (section: SectionLike, out: SectionLike[]) => {
    for (const child of section.children ?? []) {
      out.push(child);
      collectAllDescendants(child, out);
    }
  };

  const collectPrunedDescendants = (
    section: SectionLike,
    cutRatio: number,
    out: SectionLike[],
  ) => {
    for (const child of section.children ?? []) {
      const branchPos = Number(child.branchPosition ?? 1);
      const removeNow = branchPos >= cutRatio - 1e-4 || !!child.isContinuation;
      if (removeNow) {
        out.push(child);
        collectAllDescendants(child, out);
      }
    }
  };

  const resolveSectionHit = (
    object: THREE.Object3D,
  ): { section: SectionLike; segmentIndex: number } | null => {
    let current: THREE.Object3D | null = object;
    if (current.userData?.isSegment && current.userData?.parentSection) {
      const section = current.userData.parentSection as SectionLike;
      const idx = Number(current.userData.segmentIndex);
      return {
        section,
        segmentIndex: Number.isFinite(idx) ? idx : getSegmentCount(section) - 1,
      };
    }
    while (current && current !== scene) {
      const controller = current.userData?.controller as
        | SectionLike
        | undefined;
      if (controller?.mesh && controller?.group) {
        return {
          section: controller,
          segmentIndex: getSegmentCount(controller) - 1,
        };
      }
      current = current.parent;
    }
    return null;
  };

  const applyHighlight = (state: HighlightState) => {
    if (state.mode === "wire") {
      markGroup(state.section.group, 0x44ff44, 0.5);
      return;
    }

    const segMeshes = getSegmentMeshes(state.section);
    const cutIndex = clampSegmentIndex(state.section, state.segmentIndex);
    for (const seg of segMeshes) {
      const idx = Number(seg.userData?.segmentIndex ?? 0);
      if (idx >= cutIndex) markMesh(seg, 0x444444, 0.5);
    }

    const cutRatio = (cutIndex + 1) / getSegmentCount(state.section);
    const descendants: SectionLike[] = [];
    collectPrunedDescendants(state.section, cutRatio, descendants);
    for (const node of descendants) markGroup(node.group, 0x444444, 0.5);
  };

  animate();

  if (canvasContainer.value) {
    canvasContainer.value.addEventListener("click", handleCanvasClick);
    canvasContainer.value.addEventListener("mousedown", onCanvasMouseDown);
    canvasContainer.value.addEventListener("mousemove", onMouseMove);
  }
  window.addEventListener("resize", onWindowResize);
  window.addEventListener("keydown", onKeyDown);
});

const onMouseMove = (event: MouseEvent) => {
  if (!renderer || !canvasContainer.value) return;
  const rect = renderer.domElement.getBoundingClientRect();
  mouse.x = ((event.clientX - rect.left) / rect.width) * 2 - 1;
  mouse.y = -((event.clientY - rect.top) / rect.height) * 2 + 1;

  if (props.settings.interactionMode === "prune") {
    canvasContainer.value.style.cursor = highlightedState
      ? "crosshair"
      : "default";
  } else {
    canvasContainer.value.style.cursor = "pointer";
  }
};

const createEnvironment = (scene: THREE.Scene) => {
  // DEBUG: hidden to isolate tree rendering
  scene.add(PotService.createPot());
  scene.add(EnvironmentService.createSoilMound());
  scene.add(EnvironmentService.createStones(5));
  scene.add(EnvironmentService.createFloor());
};

const tryPruneAtEvent = (event: MouseEvent, removeSection: boolean): boolean => {
  if (!bonsai || !renderer || !camera) return false;
  const rect = renderer.domElement.getBoundingClientRect();
  const x = ((event.clientX - rect.left) / rect.width) * 2 - 1;
  const y = -((event.clientY - rect.top) / rect.height) * 2 + 1;
  raycaster.setFromCamera(new THREE.Vector2(x, y), camera);
  const intersects = raycaster.intersectObjects(scene.children, true);
  const pruneOptions = {
    removeSection,
    removeTerminalSection: true,
  };

  for (const intersect of intersects) {
    let current: THREE.Object3D | null = intersect.object;

    if (current.userData.isSegment && current.userData.parentSection) {
      if (bonsai.prune(current, pruneOptions)) {
        spawnPruningParticles(intersect.point);
        audio.playPrune();
        return true;
      }
    }

    while (current && current !== scene) {
      if (current.userData.isTreeSection) {
        if (bonsai.prune(current, pruneOptions)) {
          spawnPruningParticles(intersect.point);
          audio.playPrune();
          return true;
        }
      }
      current = current.parent;
    }
  }
  return false;
};

const onCanvasMouseDown = (event: MouseEvent) => {
  if (props.settings.interactionMode !== "prune" || event.button !== 1) return;
  event.preventDefault();
  event.stopPropagation();
  audio.init();
  tryPruneAtEvent(event, true);
};

const handleCanvasClick = (event: MouseEvent) => {
  if (!bonsai || !renderer || !camera) return;
  audio.init();

  if (props.settings.interactionMode === "water") {
    bonsai.interact();
    spawnParticles();
    audio.playWater();
  } else if (props.settings.interactionMode === "prune") {
    const removeSection = event.ctrlKey;
    if (tryPruneAtEvent(event, removeSection)) return;
  } else if (props.settings.interactionMode === "wire") {
    const rect = renderer.domElement.getBoundingClientRect();
    const x = ((event.clientX - rect.left) / rect.width) * 2 - 1;
    const y = -((event.clientY - rect.top) / rect.height) * 2 + 1;
    raycaster.setFromCamera(new THREE.Vector2(x, y), camera);
    const intersects = raycaster.intersectObjects(scene.children, true);
    for (const intersect of intersects) {
      let current: THREE.Object3D | null = intersect.object;
      if (current.userData.isSegment && current.userData.parentSection) {
        if (bonsai.applyWire(current)) {
          audio.playPrune();
          return;
        }
      }
      while (current && current !== scene) {
        if (current.userData.isTreeSection) {
          if (bonsai.applyWire(current)) {
            audio.playPrune();
            return;
          }
        }
        current = current.parent;
      }
    }
  }
};

const initParticles = (scene: THREE.Scene) => {
  particleGeometry = new THREE.BufferGeometry();
  particlePositions = new Float32Array(PARTICLE_COUNT * 3);
  for (let i = 0; i < PARTICLE_COUNT; i++) {
    particlePositions[i * 3] = 0;
    particlePositions[i * 3 + 1] = -100;
    particlePositions[i * 3 + 2] = 0;
    particleVelocities.push(new THREE.Vector3());
  }
  particleGeometry.setAttribute(
    "position",
    new THREE.BufferAttribute(particlePositions, 3),
  );
  const particleMaterial = new THREE.PointsMaterial({
    color: 0x44aaff,
    size: 0.05,
    transparent: true,
    blending: THREE.AdditiveBlending,
  });
  particles = new THREE.Points(particleGeometry, particleMaterial);
  scene.add(particles);
};

const spawnParticles = () => {
  for (let i = 0; i < PARTICLE_COUNT; i++) {
    particlePositions[i * 3] = (Math.random() - 0.5) * 0.5;
    particlePositions[i * 3 + 1] = 4 + Math.random() * 2;
    particlePositions[i * 3 + 2] = (Math.random() - 0.5) * 0.5;
    particleVelocities[i].set(
      (Math.random() - 0.5) * 0.02,
      -0.05 - Math.random() * 0.05,
      (Math.random() - 0.5) * 0.02,
    );
  }
  particleGeometry.attributes.position.needsUpdate = true;
};

const spawnPruningParticles = (position: THREE.Vector3) => {
  for (let i = 0; i < PARTICLE_COUNT; i++) {
    particlePositions[i * 3] = position.x + (Math.random() - 0.5) * 0.1;
    particlePositions[i * 3 + 1] = position.y + (Math.random() - 0.5) * 0.1;
    particlePositions[i * 3 + 2] = position.z + (Math.random() - 0.5) * 0.1;
    particleVelocities[i].set(
      (Math.random() - 0.5) * 0.1,
      (Math.random() - 0.5) * 0.1,
      (Math.random() - 0.5) * 0.1,
    );
  }
  const mat = particles.material as THREE.PointsMaterial;
  const originalColor = mat.color.clone();
  mat.color.setHex(0x5d4037);
  setTimeout(() => {
    mat.color.copy(originalColor);
  }, 1000);
  particleGeometry.attributes.position.needsUpdate = true;
};

const updateParticles = () => {
  if (!particles) return;
  for (let i = 0; i < PARTICLE_COUNT; i++) {
    if (particlePositions[i * 3 + 1] > -1) {
      particlePositions[i * 3] += particleVelocities[i].x;
      particlePositions[i * 3 + 1] += particleVelocities[i].y;
      particlePositions[i * 3 + 2] += particleVelocities[i].z;
    }
  }
  particleGeometry.attributes.position.needsUpdate = true;
};

const onWindowResize = () => {
  if (!camera || !renderer || !composer) return;
  camera.aspect = window.innerWidth / window.innerHeight;
  camera.updateProjectionMatrix();
  renderer.setSize(window.innerWidth, window.innerHeight);
  composer.setSize(window.innerWidth, window.innerHeight);
};

const onKeyDown = (e: KeyboardEvent) => {
  if (e.code === "KeyW" && !e.ctrlKey && !e.altKey && !e.metaKey) {
    setDebugWireframe(!DEBUG_WIREFRAME);
    console.log(`[Debug] wireframe: ${DEBUG_WIREFRAME}`);
  }
};

onUnmounted(() => {
  cancelAnimationFrame(animationId);
  if (canvasContainer.value) {
    canvasContainer.value.removeEventListener("click", handleCanvasClick);
    canvasContainer.value.removeEventListener("mousedown", onCanvasMouseDown);
    canvasContainer.value.removeEventListener("mousemove", onMouseMove);
  }
  window.removeEventListener("resize", onWindowResize);
  window.removeEventListener("keydown", onKeyDown);
  renderer?.dispose();
});
</script>

<template>
  <div ref="canvasContainer" class="w-full h-full fixed inset-0 z-0"></div>
</template>
