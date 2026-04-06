import { describe, it, expect } from "vitest";
import * as THREE from "three";
import { MSVCRand } from "./MSVCRand";
import { GrowthController } from "./GrowthController";
import { GrowthFramePipeline } from "./growth/GrowthFramePipeline";
import { TreeSection } from "./TreeSection";
import { WorldGrowthState } from "./world/WorldGrowthState";
import { SectionRuntimeType } from "./SectionRuntimeType";
import { Sub416510Rotation } from "./math/Sub416510Rotation";
import { TreeRoot } from "./TreeRoot";
import { GrowthConstants } from "./config/GrowthConstants";
import {
  parityDay0,
  parityEnergyPoolByDay,
} from "./__fixtures__/parityReferenceFromExe";

function createMinimalGrowthHarness(seed: number) {
  const rng = new MSVCRand(seed);
  const growth = new GrowthController(rng);
  const stats = growth.initStats();
  const root = new TreeSection(null, 0, rng);
  root.sectionRuntimeType4 = SectionRuntimeType.TreeSectionSeed;
  root.sub414CE0SeedBudget428 = 1.0;
  root.targetRotation.identity();
  root.rotationQuaternion.identity();
  root.rotation.identity();
  Sub416510Rotation.syncBlob80FromQuaternion(root);
  const scene = new THREE.Scene();
  scene.add(root.group);
  const worldGrowth = new WorldGrowthState();
  const pipeline = new GrowthFramePipeline(growth);
  const wind = new THREE.Vector3(0.004, 0, 0.002);
  return { rng, growth, stats, root, scene, worldGrowth, pipeline, wind };
}

function runGrowthFrames(
  h: ReturnType<typeof createMinimalGrowthHarness>,
  count: number,
  deltaTime: number,
): void {
  for (let i = 0; i < count; i++) {
    h.pipeline.run({
      deltaTime,
      timeSpeed: 1,
      stats: h.stats,
      root: h.root,
      worldGrowth: h.worldGrowth,
      lightIntensity: 1,
      wind: h.wind,
      treeRoots: [] as TreeRoot[],
      tickEnvironment: () => {},
      rng: h.rng,
      scene: h.scene,
      strictExeSimPath: true,
    });
  }
}

function collectParityTrace(
  h: ReturnType<typeof createMinimalGrowthHarness>,
  frames: number,
  deltaTime: number,
): Array<{
  day: number;
  pool: number;
  budget432: number;
  spent436: number;
  prod420: number;
}> {
  const out: Array<{
    day: number;
    pool: number;
    budget432: number;
    spent436: number;
    prod420: number;
  }> = [];
  for (let i = 0; i < frames; i++) {
    runGrowthFrames(h, 1, deltaTime);
    out.push({
      day: h.worldGrowth.simulationDay,
      pool: h.worldGrowth.energyPool,
      budget432: h.root.energyBudget432 as number,
      spent436: h.root.energySpent436 as number,
      prod420: h.root.energyProduction420 as number,
    });
  }
  return out;
}

describe("parityReferenceFromExe: начальное состояние", () => {
  it("energyPool начинается с exe-значения ≈74.609", () => {
    const h = createMinimalGrowthHarness(42);
    expect(h.worldGrowth.energyPool).toBeCloseTo(parityDay0.energyPool196, 2);
  });

  it("simulationDay начинается с 0", () => {
    const h = createMinimalGrowthHarness(42);
    expect(h.worldGrowth.simulationDay).toBe(0);
  });
});

describe("минимальный harness GrowthFramePipeline", () => {
  it("sub_4130D0 ×3: с reset flt_4D7EF8 → ровно 3 дня за 3 кадра", () => {
    const h = createMinimalGrowthHarness(42);
    expect(h.worldGrowth.simulationDay).toBe(0);
    runGrowthFrames(h, 3, 1 / 60);
    // flt_4D7EF8 += 50*(1/30) = 1.6666 за кадр, subtract 1 → sub_40DC90 ×1, reset to 0.
    expect(h.worldGrowth.simulationDay).toBe(3);
  });

  it("flt_4D7EF8 = 0 после каждого кадра (exe trace подтверждение)", () => {
    const h = createMinimalGrowthHarness(42);
    runGrowthFrames(h, 1, 1 / 60);
    expect(h.worldGrowth.growthAccumulator4D7EF8).toBe(0);
  });
});

describe("energy pool decay ×0.998 (childless root)", () => {
  it("пул убывает по кривой pool * 0.998 (±1e-2) за первые 5 дней", () => {
    const h = createMinimalGrowthHarness(42);
    const initialPool = h.worldGrowth.energyPool;
    expect(initialPool).toBeCloseTo(parityDay0.energyPool196, 2);

    for (let day = 1; day <= 5; day++) {
      runGrowthFrames(h, 1, 1 / 60);
      const expected = parityDay0.energyPool196 * Math.pow(0.998, day);
      expect(h.worldGrowth.energyPool).toBeCloseTo(expected, 1);
    }
  });

  it("ENERGY_LEAK = 0.998", () => {
    expect(GrowthConstants.ENERGY_LEAK).toBeCloseTo(0.998, 6);
  });

  it("INITIAL_ENERGY_POOL_196 ≈ 74.609", () => {
    expect(GrowthConstants.INITIAL_ENERGY_POOL_196).toBeCloseTo(74.609, 2);
  });
});

describe("strict parity determinism", () => {
  it("одинаковый seed даёт идентичный trace ключевых полей", () => {
    const a = createMinimalGrowthHarness(1337);
    const b = createMinimalGrowthHarness(1337);
    // Keep test in node-safe window before first leaf spawn (TreeLeaf uses document/canvas).
    const ta = collectParityTrace(a, 20, 1 / 60);
    const tb = collectParityTrace(b, 20, 1 / 60);
    expect(tb).toEqual(ta);
  });
});
