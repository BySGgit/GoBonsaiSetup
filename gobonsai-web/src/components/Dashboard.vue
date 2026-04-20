<script setup lang="ts">
import {
  TreePine,
  Clock,
  Target,
  TrendingUp,
  Zap,
  Heart,
  Sun,
  Scissors,
  Droplets,
  Leaf,
  ThermometerSnowflake,
  Waves,
  Flower2,
  Download,
  Upload,
} from "lucide-vue-next";
import { computed } from "vue";

const emit = defineEmits([
  "reset",
  "update-settings",
  "update-mode",
  "export",
  "import",
  "toggle-debug",
]);

const props = defineProps<{
  stats: {
    age: number;
    targetAge: number;
    gameTime: number;
    simulationDay: number;
    energy: number;
    health: number;
    light: number;
    log: {
      message: string;
      time: number;
      type: "info" | "warning" | "success";
    }[];
  };
  debug: boolean;
  settings: {
    timeSpeed: number;
    manualLight: boolean;
    manualLightValue: number;
    interactionMode: "water" | "prune" | "wire";
  };
}>();
const seasonInfo = computed(() => {
  const day = ((Math.floor(props.stats.simulationDay) % 365) + 365) % 365;
  if (day >= 60 && day < 150)
    return { name: "Весна", icon: Flower2, color: "text-pink-400" };
  if (day >= 150 && day < 240)
    return { name: "Лето", icon: Sun, color: "text-yellow-400" };
  if (day >= 240 && day < 330)
    return { name: "Осень", icon: Leaf, color: "text-orange-500" };
  return { name: "Зима", icon: ThermometerSnowflake, color: "text-blue-400" };
});
</script>

<template>
  <div class="fixed top-6 left-6 z-10 w-64">
    <div
      class="bg-black/60 backdrop-blur-md border border-white/10 rounded-2xl p-5 text-white shadow-2xl"
    >
      <div class="flex items-center gap-2 mb-6 border-b border-white/10 pb-3">
        <TreePine class="text-emerald-400 w-6 h-6" />
        <h1 class="text-lg font-bold tracking-tight">GoBonsai RE</h1>
      </div>

      <div class="grid grid-cols-1 gap-4">
        <div class="flex flex-col gap-1">
          <div
            class="flex items-center gap-2 text-xs font-medium text-white/50 uppercase tracking-wider"
          >
            <TrendingUp class="w-3.5 h-3.5" />
            <span>Возраст</span>
          </div>
          <div class="text-2xl font-mono font-bold text-emerald-400">
            {{ stats.age.toFixed(4) }}
          </div>
        </div>

        <div class="grid grid-cols-2 gap-4">
          <div class="flex flex-col gap-1">
            <div
              class="flex items-center gap-2 text-xs font-medium text-white/50 uppercase tracking-wider"
            >
              <Zap class="w-3.5 h-3.5 text-yellow-400" />
              <span>Энергия</span>
            </div>
            <div class="text-lg font-mono font-semibold text-yellow-400">
              {{ (stats.energy * 100).toFixed(0) }}%
            </div>
          </div>
          <div class="flex flex-col gap-1">
            <div
              class="flex items-center gap-2 text-xs font-medium text-white/50 uppercase tracking-wider"
            >
              <Heart class="w-3.5 h-3.5 text-red-400" />
              <span>Здоровье</span>
            </div>
            <div class="text-lg font-mono font-semibold text-red-400">
              {{ (stats.health * 100).toFixed(0) }}%
            </div>
          </div>
        </div>

        <div class="flex flex-col gap-1">
          <div
            class="flex items-center gap-2 text-xs font-medium text-white/50 uppercase tracking-wider"
          >
            <Sun class="w-3.5 h-3.5 text-orange-400" />
            <span>Освещенность</span>
          </div>
          <div
            class="w-full bg-white/10 h-1.5 rounded-full mt-1 overflow-hidden"
          >
            <div
              class="bg-orange-400 h-full transition-all duration-300"
              :style="{ width: `${Math.min(100, stats.light * 100)}%` }"
            ></div>
          </div>
        </div>

        <div class="flex flex-col gap-1 pt-2 border-t border-white/5">
          <div class="flex items-center justify-between">
            <div
              class="flex items-center gap-2 text-xs font-medium text-white/50 uppercase tracking-wider"
            >
              <Target class="w-3.5 h-3.5" />
              <span>Целевой возраст</span>
            </div>
            <span class="text-sm font-mono text-blue-400"
              >{{ stats.targetAge.toFixed(2) }} лет</span
            >
          </div>
        </div>

        <div class="flex items-center justify-between pt-1">
          <div
            class="flex items-center gap-2 text-xs font-medium text-white/50 uppercase tracking-wider"
          >
            <component
              :is="seasonInfo.icon"
              class="w-3.5 h-3.5"
              :class="seasonInfo.color"
            />
            <span>Сезон</span>
          </div>
          <span class="text-sm font-mono font-bold" :class="seasonInfo.color">
            {{ seasonInfo.name }}
          </span>
        </div>

        <div class="flex items-center justify-between pt-1">
          <div
            class="flex items-center gap-2 text-xs font-medium text-white/50 uppercase tracking-wider"
          >
            <Clock class="w-3.5 h-3.5" />
            <span>Год / День</span>
          </div>
          <span class="text-sm font-mono text-amber-400">
            {{ Math.floor(props.stats.simulationDay / 365) + 1 }} /
            {{ ((Math.floor(props.stats.simulationDay) % 365) + 365) % 365 }}
          </span>
        </div>
      </div>

      <!-- Interaction Mode -->
      <div class="mt-6 pt-4 border-t border-white/10 flex gap-2">
        <button
          @click="$emit('update-mode', 'water')"
          :class="
            settings.interactionMode === 'water'
              ? 'bg-blue-500/40 border-blue-500/50 text-blue-300'
              : 'bg-white/5 border-white/10 text-white/40'
          "
          class="flex-1 py-2 rounded-xl border flex flex-col items-center gap-1 transition-all cursor-pointer group"
        >
          <Droplets
            class="w-4 h-4"
            :class="
              settings.interactionMode === 'water'
                ? 'text-blue-400'
                : 'group-hover:text-blue-400/60'
            "
          />
          <span class="text-[9px] font-bold uppercase tracking-widest"
            >Полив</span
          >
        </button>
        <button
          @click="$emit('update-mode', 'prune')"
          :class="
            settings.interactionMode === 'prune'
              ? 'bg-orange-500/40 border-orange-500/50 text-orange-300'
              : 'bg-white/5 border-white/10 text-white/40'
          "
          class="flex-1 py-2 rounded-xl border flex flex-col items-center gap-1 transition-all cursor-pointer group"
        >
          <Scissors
            class="w-4 h-4"
            :class="
              settings.interactionMode === 'prune'
                ? 'text-orange-400'
                : 'group-hover:text-orange-400/60'
            "
          />
          <span class="text-[9px] font-bold uppercase tracking-widest"
            >Обрезка</span
          >
        </button>
        <button
          @click="$emit('update-mode', 'wire')"
          :class="
            settings.interactionMode === 'wire'
              ? 'bg-emerald-500/40 border-emerald-500/50 text-emerald-300'
              : 'bg-white/5 border-white/10 text-white/40'
          "
          class="flex-1 py-2 rounded-xl border flex flex-col items-center gap-1 transition-all cursor-pointer group"
        >
          <Waves
            class="w-4 h-4"
            :class="
              settings.interactionMode === 'wire'
                ? 'text-emerald-400'
                : 'group-hover:text-emerald-400/60'
            "
          />
          <span class="text-[9px] font-bold uppercase tracking-widest"
            >Проволока</span
          >
        </button>
      </div>

      <!-- Settings Panel -->
      <div class="mt-6 pt-4 border-t border-white/10 space-y-4">
        <div class="flex flex-col gap-2">
          <div
            class="flex justify-between text-[10px] font-bold uppercase tracking-widest text-white/40"
          >
            <span>Скорость времени</span>
            <span>x{{ settings.timeSpeed }}</span>
          </div>
          <input
            type="range"
            min="0.1"
            max="10"
            step="0.1"
            :value="settings.timeSpeed"
            @input="
              $emit('update-settings', {
                timeSpeed: parseFloat(
                  ($event.target as HTMLInputElement).value,
                ),
              })
            "
            class="w-full h-1.5 bg-white/10 rounded-lg appearance-none cursor-pointer accent-emerald-500"
          />
        </div>

        <div class="flex flex-col gap-2">
          <div
            class="flex justify-between items-center text-[10px] font-bold uppercase tracking-widest text-white/40"
          >
            <span>Ручной свет</span>
            <button
              @click="
                $emit('update-settings', { manualLight: !settings.manualLight })
              "
              :class="
                settings.manualLight ? 'text-emerald-400' : 'text-white/20'
              "
              class="transition-colors cursor-pointer"
            >
              {{ settings.manualLight ? "ВКЛ" : "ВЫКЛ" }}
            </button>
          </div>
          <input
            v-if="settings.manualLight"
            type="range"
            min="0"
            max="1.5"
            step="0.01"
            :value="settings.manualLightValue"
            @input="
              $emit('update-settings', {
                manualLightValue: parseFloat(
                  ($event.target as HTMLInputElement).value,
                ),
              })
            "
            class="w-full h-1.5 bg-white/10 rounded-lg appearance-none cursor-pointer accent-orange-400"
          />
        </div>
      </div>

      <!-- Дневник садовода -->
      <div
        v-if="stats.log && stats.log.length > 0"
        class="mt-6 pt-4 border-t border-white/10"
      >
        <div
          class="text-[10px] font-bold uppercase tracking-widest text-white/40 mb-3 flex items-center gap-2"
        >
          <span>Дневник садовода</span>
        </div>
        <div class="space-y-2 max-h-32 overflow-hidden relative">
          <div
            v-for="(entry, index) in stats.log"
            :key="entry.time"
            class="text-[11px] leading-tight transition-all duration-500 animate-in fade-in slide-in-from-left-2"
            :class="{
              'text-blue-300': entry.type === 'info',
              'text-orange-400': entry.type === 'warning',
              'text-emerald-400': entry.type === 'success',
              'opacity-100': index === 0,
              'opacity-60': index === 1,
              'opacity-30': index >= 2,
            }"
          >
            {{ entry.message }}
          </div>
        </div>
      </div>

      <div class="mt-8 pt-4 border-t border-white/10 flex flex-col gap-3">
        <div class="grid grid-cols-2 gap-2">
          <button
            @click="$emit('export')"
            class="flex items-center justify-center gap-2 py-2 bg-white/5 hover:bg-white/10 border border-white/10 rounded-xl text-white/60 text-[10px] font-bold uppercase tracking-widest transition-all cursor-pointer"
          >
            <Download class="w-3.5 h-3.5" />
            Экспорт
          </button>
          <button
            @click="$emit('import')"
            class="flex items-center justify-center gap-2 py-2 bg-white/5 hover:bg-white/10 border border-white/10 rounded-xl text-white/60 text-[10px] font-bold uppercase tracking-widest transition-all cursor-pointer"
          >
            <Upload class="w-3.5 h-3.5" />
            Импорт
          </button>
        </div>
        <button
          @click="$emit('reset')"
          class="w-full py-2 bg-red-500/20 hover:bg-red-500/40 border border-red-500/50 rounded-xl text-red-400 text-xs font-bold uppercase tracking-widest transition-all cursor-pointer"
        >
          Сбросить бонсай
        </button>
        <button
          @click="$emit('toggle-debug')"
          class="w-full py-2 bg-red-500/20 hover:bg-red-500/40 border border-red-500/50 rounded-xl text-red-400 text-xs font-bold uppercase tracking-widest transition-all cursor-pointer"
        >
          Дебаг ({{ debug ? "ВКЛ" : "ВЫКЛ" }})
        </button>
        <div
          class="text-[10px] text-white/30 text-center uppercase tracking-widest font-bold"
        >
          Образовательный RE Проект
        </div>
      </div>
    </div>
  </div>
</template>
