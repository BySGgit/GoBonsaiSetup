<script setup lang="ts">
import { onMounted, ref, onUnmounted, watch } from 'vue';
import * as THREE from 'three';
import { BonsaiTree, BonsaiMeshBuilder } from '@/engine/v2';
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
let tree: BonsaiTree;
let audio: BonsaiAudio;
let animationId: number;
const clock = new THREE.Clock();
let particles: THREE.Points;
let particleGeometry: THREE.BufferGeometry;
let particlePositions: Float32Array;
let particleVelocities: THREE.Vector3[] = [];
const PARTICLE_COUNT = 100;

let meshRebuildTimer = 0;
const MESH_REBUILD_INTERVAL = 2.0; // Перестройка мешей каждые 2 секунды

const mouse = new THREE.Vector2();
const raycaster = new THREE.Raycaster();

const exportBonsai = () => {
  if (tree) {
    const data = JSON.stringify(tree.serialize());
    localStorage.setItem('gobonsai_v2_state', data);
    const blob = new Blob([data], { type: 'application/json' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = `bonsai_${new Date().toISOString().slice(0, 10)}.json`;
    a.click();
    URL.revokeObjectURL(url);
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
        localStorage.setItem('gobonsai_v2_state', json);
        window.location.reload();
      } catch (err) {
        console.error("Failed to import", err);
      }
    };
    reader.readAsText(file);
  };
  input.click();
};

defineExpose({ exportBonsai, importBonsai });

watch(() => props.settings.timeSpeed, (val) => {
  if (tree) tree.timeSpeed = val;
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
    0.5, 0.4, 0.85
  );

  composer = new EffectComposer(renderer);
  composer.addPass(renderScene);
  composer.addPass(bloomPass);
  composer.addPass(new OutputPass());

  // Освещение
  const ambientLight = new THREE.AmbientLight(0xffffff, 0.8);
  scene.add(ambientLight);

  const hemisphereLight = new THREE.HemisphereLight(0xffffff, 0x444444, 1.2);
  scene.add(hemisphereLight);

  const directionalLight = new THREE.DirectionalLight(0xffffff, 1.5);
  directionalLight.position.set(5, 12, 8);
  directionalLight.castShadow = true;
  directionalLight.shadow.mapSize.width = 2048;
  directionalLight.shadow.mapSize.height = 2048;
  scene.add(directionalLight);

  const pointLight = new THREE.PointLight(0xffaa00, 0, 50);
  pointLight.position.set(-5, 5, -5);
  scene.add(pointLight);

  // Инициализация дерева v2
  tree = loadOrCreateTree();
  scene.add(tree.scene);

  // Первая генерация мешей
  BonsaiMeshBuilder.buildTree(tree.root);

  audio = new BonsaiAudio();

  createEnvironment(scene);
  initParticles(scene);

  const animate = () => {
    animationId = requestAnimationFrame(animate);
    const deltaTime = clock.getDelta();

    if (tree) {
      tree.update(deltaTime);

      // DEBUG
      if (animationId % 120 === 0) {
        const s = tree.getStats();
        const stem = tree.root.children[0];
        // Считаем все Mesh-объекты в дереве
        let meshCount = 0;
        tree.scene.traverse((o: any) => { if (o.isMesh) meshCount++; });
        console.log(`[V2] day=${tree.dayOfYear.toFixed(0)} E=${s.totalEnergy.toFixed(3)} nodes=${s.nodeCount}` +
          (stem ? ` R=${stem.trunkRadius.toFixed(3)} hp=${stem.health.toFixed(1)} ch=${stem.children.length}` : '') +
          ` meshes=${meshCount} treePos=${tree.scene.position.toArray().map((v: number) => v.toFixed(1))}`);
      }

      // Периодическая перестройка мешей
      meshRebuildTimer += deltaTime;
      if (meshRebuildTimer > MESH_REBUILD_INTERVAL) {
        meshRebuildTimer = 0;
        BonsaiMeshBuilder.buildTree(tree.root);
      }

      // Обновление мешей (масштабы, вращения) каждый кадр
      BonsaiMeshBuilder.updateMeshes(tree.root);

      // Освещение
      const lightIntensity = props.settings.manualLight
        ? props.settings.manualLightValue
        : (Math.sin(tree.dayOfYear / 365 * Math.PI * 2 - Math.PI / 2) * 0.5 + 0.5);

      directionalLight.intensity = Math.max(0.1, lightIntensity * 2);
      ambientLight.intensity = Math.max(0.2, lightIntensity * 0.5);
      pointLight.intensity = Math.max(0, (1 - lightIntensity) * 0.5);

      const bgColor = new THREE.Color(0x050505).lerp(new THREE.Color(0x1a1a2e), lightIntensity);
      scene.background = bgColor;

      // Направление света для фотосинтеза
      tree.lightDirection.copy(directionalLight.position).normalize();

      audio.updateWind(lightIntensity, props.settings.timeSpeed);

      // Статистика для UI
      const stats = tree.getStats();
      emit('update-stats', {
        age: stats.age,
        gameTime: tree.dayOfYear,
        energy: stats.totalEnergy,
        health: stats.health,
        light: lightIntensity,
        nodeCount: stats.nodeCount,
        leafCount: stats.leafCount,
        waterLevel: stats.waterLevel,
      });

      // Автосохранение каждый год
      if (Math.floor(tree.dayOfYear / 365) !== Math.floor((tree.dayOfYear - deltaTime * tree.timeSpeed) / 365)) {
        saveTree();
      }
    }

    updateParticles();
    controls.update();
    composer.render();
  };

  animate();

  if (canvasContainer.value) {
    canvasContainer.value.addEventListener('click', handleCanvasClick);
    canvasContainer.value.addEventListener('mousemove', onMouseMove);
  }
  window.addEventListener('resize', onWindowResize);
});

const loadOrCreateTree = (): BonsaiTree => {
  const saved = localStorage.getItem('gobonsai_v2_state');
  if (saved) {
    try {
      const data = JSON.parse(saved);
      return BonsaiTree.deserialize(data);
    } catch (e) {
      console.error("Failed to load v2 state, creating new tree", e);
    }
  }
  return new BonsaiTree();
};

const saveTree = () => {
  if (tree) {
    localStorage.setItem('gobonsai_v2_state', JSON.stringify(tree.serialize()));
  }
};

const onMouseMove = (event: MouseEvent) => {
  if (!renderer || !canvasContainer.value) return;
  const rect = renderer.domElement.getBoundingClientRect();
  mouse.x = ((event.clientX - rect.left) / rect.width) * 2 - 1;
  mouse.y = -((event.clientY - rect.top) / rect.height) * 2 + 1;

  canvasContainer.value.style.cursor =
    props.settings.interactionMode === 'prune' ? 'crosshair' : 'pointer';
};

const createEnvironment = (scene: THREE.Scene) => {
  scene.add(PotService.createPot());
  scene.add(EnvironmentService.createSoilMound());
  scene.add(EnvironmentService.createStones(5));
  scene.add(EnvironmentService.createFloor());
};

const handleCanvasClick = (event: MouseEvent) => {
  if (!tree || !renderer || !camera) return;
  audio.init();

  if (props.settings.interactionMode === 'water') {
    tree.water();
    spawnParticles();
    audio.playWater();
  } else if (props.settings.interactionMode === 'prune') {
    // TODO: raycasting для обрезки по узлам BonsaiNode
    // Пока используем простую обрезку самого дальнего побега
    const allNodes = tree.getAllNodes();
    const stems = allNodes.filter(n => n.type === 1 && n.children.length === 0 && n.depth > 2);
    if (stems.length > 0) {
      const target = stems[Math.floor(Math.random() * stems.length)];
      tree.prune(target);
      audio.playPrune();
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
    particleVelocities[i].set(
      (Math.random() - 0.5) * 0.02,
      -0.05 - Math.random() * 0.05,
      (Math.random() - 0.5) * 0.02
    );
  }
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
  saveTree();
  if (canvasContainer.value) {
    canvasContainer.value.removeEventListener('click', handleCanvasClick);
    canvasContainer.value.removeEventListener('mousemove', onMouseMove);
  }
  window.removeEventListener('resize', onWindowResize);
  BonsaiMeshBuilder.dispose();
  renderer?.dispose();
});
</script>

<template>
  <div ref="canvasContainer" class="w-full h-full fixed inset-0 z-0"></div>
</template>
