<script setup lang="ts">
import { onMounted, ref, onUnmounted, watch } from 'vue';
import * as THREE from 'three';
import { BonsaiController } from '@/engine/BonsaiController';
import { BonsaiAudio } from '@/engine/BonsaiAudio';
import { PotService } from '@/engine/PotService';
import { EnvironmentService } from '@/engine/EnvironmentService';

import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js';
import { EffectComposer } from 'three/examples/jsm/postprocessing/EffectComposer.js';
import { RenderPass } from 'three/examples/jsm/postprocessing/RenderPass.js';
import { UnrealBloomPass } from 'three/examples/jsm/postprocessing/UnrealBloomPass.js';
import { OutputPass } from 'three/examples/jsm/postprocessing/OutputPass.js';

const props = defineProps<{
  settings: {
    timeSpeed: number;
    manualLight: boolean;
    manualLightValue: number;
    interactionMode: 'water' | 'prune' | 'wire';
  }
}>();

const canvasContainer = ref<HTMLElement | null>(null);
const emit = defineEmits(['update-stats']);

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

let highlightedBranch: THREE.Group | null = null;
const mouse = new THREE.Vector2();
const raycaster = new THREE.Raycaster();

const exportBonsai = () => {
  if (bonsai) {
    bonsai.saveState();
    const data = localStorage.getItem('gobonsai_state');
    if (data) {
      const blob = new Blob([data], { type: 'application/json' });
      const url = URL.createObjectURL(blob);
      const a = document.createElement('a');
      a.href = url;
      a.download = `bonsai_${new Date().toISOString().slice(0, 10)}.json`;
      a.click();
      URL.revokeObjectURL(url);
    }
  }
};

const importBonsai = () => {
  const input = document.createElement('input');
  input.type = 'file';
  input.accept = '.json';
  input.onchange = (e: any) => {
    const file = e.target.files[0];
    if (!file) return;
    const reader = new FileReader();
    reader.onload = (e: any) => {
      const json = e.target.result as string;
      try {
        localStorage.setItem('gobonsai_state', json);
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
  importBonsai
});

watch(() => props.settings.timeSpeed, (val) => {
  if (bonsai) bonsai.setTimeSpeed(val);
});

watch(() => props.settings.manualLightValue, (val) => {
  if (bonsai) bonsai.setLightIntensity(val);
});

onMounted(() => {
  if (!canvasContainer.value) return;

  scene = new THREE.Scene();
  scene.background = new THREE.Color(0x0a0a0a);

  camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
  camera.position.set(0, 3, 8);
  camera.lookAt(0, 2, 0);

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
  controls.maxDistance = 20;
  controls.minPolarAngle = 0;
  controls.maxPolarAngle = Math.PI / 1.8;
  controls.target.set(0, 2, 0);
  controls.update();

  const renderScene = new RenderPass(scene, camera);
  const bloomPass = new UnrealBloomPass(
    new THREE.Vector2(window.innerWidth, window.innerHeight),
    0.5, 
    0.4, 
    0.85 
  );

  composer = new EffectComposer(renderer);
  composer.addPass(renderScene);
  composer.addPass(bloomPass);
  composer.addPass(new OutputPass());

  const ambientLight = new THREE.AmbientLight(0xffffff, 0.8);
  scene.add(ambientLight);

  const hemisphereLight = new THREE.HemisphereLight(0xffffff, 0x444444, 1.2);
  scene.add(hemisphereLight);

  const directionalLight = new THREE.DirectionalLight(0xffffff, 1.5);
  directionalLight.position.set(5, 12, 8);
  directionalLight.castShadow = true;
  directionalLight.shadow.mapSize.width = 2048;
  directionalLight.shadow.mapSize.height = 2048;
  directionalLight.shadow.camera.near = 0.5;
  directionalLight.shadow.camera.far = 50;
  scene.add(directionalLight);

  const pointLight = new THREE.PointLight(0xffaa00, 0, 50);
  pointLight.position.set(-5, 5, -5);
  scene.add(pointLight);

  bonsai = new BonsaiController(scene);
  audio = new BonsaiAudio();

  bonsai.setLogCallback((msg, type) => {
    emit('update-stats', {
      logEntry: { message: msg, time: Date.now(), type }
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
      ambientLight.intensity = Math.max(0.2, bonsai.lightIntensity * 0.5);
      if (pointLight) pointLight.intensity = Math.max(0, (1 - bonsai.lightIntensity) * 0.5);
      
      const bgColorVal = new THREE.Color(0x050505).lerp(new THREE.Color(0x1a1a2e), bonsai.lightIntensity);
      scene.background = bgColorVal;

      audio.updateWind(bonsai.lightIntensity, props.settings.timeSpeed);

      emit('update-stats', {
        age: bonsai.age,
        gameTime: bonsai.gameTime,
        energy: bonsai.energy,
        health: bonsai.health,
        light: bonsai.lightIntensity
      });
    }

    updateParticles();
    updateHighlight();
    controls.update();
    composer.render();
  };

  const updateHighlight = () => {
    if (!bonsai || (props.settings.interactionMode !== 'prune' && props.settings.interactionMode !== 'wire')) {
      resetHighlight();
      return;
    }

    raycaster.setFromCamera(mouse, camera);
    const intersects = raycaster.intersectObjects(scene.children, true);
    
    let found: THREE.Group | null = null;
    for (const intersect of intersects) {
      let current: THREE.Object3D | null = intersect.object;

      if (current.userData.isSegment && current.userData.parentSection) {
        const section = current.userData.parentSection;
        if (props.settings.interactionMode === 'prune' && section === bonsai.root) {
          // Корень не режем
        } else {
          found = section.group;
          break;
        }
      }

      while (current && current !== scene) {
        if (current.userData.isTreeSection) {
          if (props.settings.interactionMode === 'prune' && current === bonsai.root.group) {
            // Корень не подсвечиваем для обрезки
          } else {
            found = current as THREE.Group;
          }
          break;
        }
        current = current.parent;
      }
      if (found) break;
    }

    if (found !== highlightedBranch) {
      resetHighlight();
      if (found) {
        highlightedBranch = found;
        setBranchHighlight(highlightedBranch, true);
      }
    }
  };

  const resetHighlight = () => {
    if (highlightedBranch) {
      setBranchHighlight(highlightedBranch, false);
      highlightedBranch = null;
    }
  };

  const setBranchHighlight = (group: THREE.Group, active: boolean) => {
    const color = props.settings.interactionMode === 'wire' ? 0x44ff44 : 0x444444;
    group.traverse((obj) => {
      if (obj instanceof THREE.Mesh && obj.material instanceof THREE.MeshStandardMaterial) {
        obj.material.emissive.setHex(active ? color : 0x000000);
        obj.material.emissiveIntensity = active ? 0.5 : 0;
      }
    });
  };

  animate();

  if (canvasContainer.value) {
    canvasContainer.value.addEventListener('click', handleCanvasClick);
    canvasContainer.value.addEventListener('mousemove', onMouseMove);
  }
  window.addEventListener('resize', onWindowResize);
});

const onMouseMove = (event: MouseEvent) => {
  if (!renderer || !canvasContainer.value) return;
  const rect = renderer.domElement.getBoundingClientRect();
  mouse.x = ((event.clientX - rect.left) / rect.width) * 2 - 1;
  mouse.y = -((event.clientY - rect.top) / rect.height) * 2 + 1;

  if (props.settings.interactionMode === 'prune') {
    canvasContainer.value.style.cursor = highlightedBranch ? 'crosshair' : 'default';
  } else {
    canvasContainer.value.style.cursor = 'pointer';
  }
};

const createEnvironment = (scene: THREE.Scene) => {
  scene.add(PotService.createPot());
  scene.add(EnvironmentService.createSoilMound());
  scene.add(EnvironmentService.createStones(5));
  scene.add(EnvironmentService.createFloor());
};

const handleCanvasClick = (event: MouseEvent) => {
  if (!bonsai || !renderer || !camera) return;
  audio.init();

  if (props.settings.interactionMode === 'water') {
    bonsai.interact();
    spawnParticles();
    audio.playWater();
  } else if (props.settings.interactionMode === 'prune') {
    const rect = renderer.domElement.getBoundingClientRect();
    const x = ((event.clientX - rect.left) / rect.width) * 2 - 1;
    const y = -((event.clientY - rect.top) / rect.height) * 2 + 1;
    raycaster.setFromCamera(new THREE.Vector2(x, y), camera);
    const intersects = raycaster.intersectObjects(scene.children, true);
    
    for (const intersect of intersects) {
      let current: THREE.Object3D | null = intersect.object;
      
      // Check for direct segment hit
      if (current.userData.isSegment && current.userData.parentSection) {
        if (bonsai.prune(current)) {
          spawnPruningParticles(intersect.point);
          audio.playPrune();
          return;
        }
      }
      
      // Check hierarchy
      while (current && current !== scene) {
        if (current.userData.isTreeSection) {
          if (bonsai.prune(current)) {
            spawnPruningParticles(intersect.point);
            audio.playPrune();
            return;
          }
        }
        current = current.parent;
      }
    }
  } else if (props.settings.interactionMode === 'wire') {
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
  particleGeometry.setAttribute('position', new THREE.BufferAttribute(particlePositions, 3));
  const particleMaterial = new THREE.PointsMaterial({
    color: 0x44aaff,
    size: 0.05,
    transparent: true,
    blending: THREE.AdditiveBlending
  });
  particles = new THREE.Points(particleGeometry, particleMaterial);
  scene.add(particles);
};

const spawnParticles = () => {
  for (let i = 0; i < PARTICLE_COUNT; i++) {
    particlePositions[i * 3] = (Math.random() - 0.5) * 0.5;
    particlePositions[i * 3 + 1] = 4 + Math.random() * 2;
    particlePositions[i * 3 + 2] = (Math.random() - 0.5) * 0.5;
    particleVelocities[i].set((Math.random() - 0.5) * 0.02, -0.05 - Math.random() * 0.05, (Math.random() - 0.5) * 0.02);
  }
  particleGeometry.attributes.position.needsUpdate = true;
};

const spawnPruningParticles = (position: THREE.Vector3) => {
  for (let i = 0; i < PARTICLE_COUNT; i++) {
    particlePositions[i * 3] = position.x + (Math.random() - 0.5) * 0.1;
    particlePositions[i * 3 + 1] = position.y + (Math.random() - 0.5) * 0.1;
    particlePositions[i * 3 + 2] = position.z + (Math.random() - 0.5) * 0.1;
    particleVelocities[i].set((Math.random() - 0.5) * 0.1, (Math.random() - 0.5) * 0.1, (Math.random() - 0.5) * 0.1);
  }
  const mat = particles.material as THREE.PointsMaterial;
  const originalColor = mat.color.clone();
  mat.color.setHex(0x5d4037);
  setTimeout(() => { mat.color.copy(originalColor); }, 1000);
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

onUnmounted(() => {
  cancelAnimationFrame(animationId);
  if (canvasContainer.value) {
    canvasContainer.value.removeEventListener('click', handleCanvasClick);
    canvasContainer.value.removeEventListener('mousemove', onMouseMove);
  }
  window.removeEventListener('resize', onWindowResize);
  renderer?.dispose();
});
</script>

<template>
  <div ref="canvasContainer" class="w-full h-full fixed inset-0 z-0"></div>
</template>
