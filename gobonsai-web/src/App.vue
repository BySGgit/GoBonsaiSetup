<script setup lang="ts">
import { ref } from "vue";
import BonsaiViewer from "./components/BonsaiViewer.vue";
import Dashboard from "./components/Dashboard.vue";

const viewerRef = ref<any>(null);
const stats = ref({
  age: 0,
  targetAge: 0,
  gameTime: 0,
  energy: 1.0,
  health: 1.0,
  light: 1.0,
  log: [] as any[],
});

const settings = ref({
  timeSpeed: 10.0,
  manualLight: false,
  manualLightValue: 1.0,
  interactionMode: "water" as "water" | "prune" | "wire",
});

const handleUpdateStats = (newStats: any) => {
  stats.value = { ...stats.value, ...newStats };
};

const handleUpdateSettings = (newSettings: any) => {
  settings.value = { ...settings.value, ...newSettings };
};

const handleUpdateMode = (mode: "water" | "prune" | "wire") => {
  settings.value.interactionMode = mode;
};

const handleReset = () => {
  if (
    confirm(
      "Вы уверены, что хотите сбросить прогресс? Это действие необратимо.",
    )
  ) {
    localStorage.removeItem("gobonsai_state");
    localStorage.removeItem("gobonsai_v2_state");
    window.location.reload();
  }
};

const handleExport = () => {
  viewerRef.value?.exportBonsai();
};

const handleImport = () => {
  viewerRef.value?.importBonsai();
};
</script>

<template>
  <div class="w-full h-screen relative text-white selection:bg-emerald-500/30">
    <Dashboard
      :stats="stats"
      :settings="settings"
      @reset="handleReset"
      @update-settings="handleUpdateSettings"
      @update-mode="handleUpdateMode"
      @export="handleExport"
      @import="handleImport"
    />
    <BonsaiViewer
      ref="viewerRef"
      :settings="settings"
      @update-stats="handleUpdateStats"
    />
  </div>
</template>

<style>
#app {
  width: 100vw;
  height: 100vh;
}
</style>
