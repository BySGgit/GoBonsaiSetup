import { TreeSection } from "../TreeSection";
import { GrowthConstants } from "../config/GrowthConstants";
import { Float32 } from "../math/MathTypes";
import { WorldGrowthState } from "../world/WorldGrowthState";

/**
 * Фрагмент логики sub_40DC90.c (§2.4–2.6): бюджет root+432, затем после «слота +36»
 * агрегаты +420 / +436 и обновление глобального пула E с energyLeak.
 *
 * Распределение +432 и rollup — см. growth/sub414E10.ts (sub_414E10).
 *
 * Глобальный пул E — `*(v0+196)` в exe; в TS это `GrowthStats.energy`.
 * Локальная энергия секции — `this+114` (`TreeSection.energy`); метаболизм и дети
 * меняют локальные значения, а `sub_40DC90` пересчитывает глобальный пул по корню
 * после rollup `root+420` / `root+436`.
 */

/** sub_40DC90: *(root+432) = E * energyUseRate * season
 *  EXE: no clamping — negative pool yields negative budget, which
 *  propagates down and naturally throttles growth without permanently
 *  killing the tree. */
export function writeRootEnergyBudget432(
    root: TreeSection,
    poolEnergy: number,
    seasonFactor: number
): void {
    const rate = GrowthConstants.ENERGY_USE_RATE as number;
    root.energyBudget432 = poolEnergy * rate * seasonFactor;
}

/** Сумма sub_416510 «текущего тика» growthScratchA по всему дереву — прокси для +420 до полного rollup как в C */
export function sumGrowthScratchAProduction420(root: TreeSection): number {
    let s = 0;
    const walk = (n: TreeSection): void => {
        s += n.growthScratchA;
        for (const c of n.children) walk(c);
    };
    walk(root);
    return s;
}

/** sub_414E10: перед кадром обнуляем +420/+436/+480/+484 и кадровый spawn (как вход в слот +36). */
export function resetAllEnergyAggregates(root: TreeSection): void {
    const walk = (s: TreeSection): void => {
        s.energyProduction420 = 0;
        s.energySpent436 = 0;
        s.rollupDword480 = 0;
        s.rollupDword484 = 0;
        s.spawnDelta480 = 0;
        for (const c of s.children) walk(c);
    };
    walk(root);
}

/**
 * Перед циклом `sub_40DC90` внутри одного `sub_4130D0`: обнуляем scratch метаболизма,
 * чтобы N тиков не множили один и тот же вклад +420 (метаболизм идёт после цикла).
 */
export function clearGrowthScratchATree(root: TreeSection): void {
    const walk = (s: TreeSection): void => {
        s.growthScratchA = 0 as Float32;
        for (const c of s.children) walk(c);
    };
    walk(root);
}

/** @deprecated Используйте resetAllEnergyAggregates — сброс только корня недостаточен для sub_414E10 */
export function resetRootEnergyAggregates(root: TreeSection): void {
    resetAllEnergyAggregates(root);
}

/**
 * Устаревший rollup только в корень из growthScratchA — заменён на aggregateEnergy420436PostOrder (sub414E10).
 * Оставлено для отладки сравнения.
 */
export function rollupFrameEnergy420(root: TreeSection): void {
    const raw = sumGrowthScratchAProduction420(root);
    const scale = GrowthConstants.SUB40DC90_PRODUCTION_FROM_SCRATCH_SCALE as number;
    root.energyProduction420 = raw * scale;
}

/**
 * sub_40DC90: E = (E - root+436 + root+420) * energyLeak
 * exe trace: energyPool196 абсолютная шкала (~74.6 при старте), leak ≈ 0.998.
 * root.energy пишем нормализованным [0,1] для metabolism/health.
 *
 * NOTE: EXE does NOT clamp pool to 0 — a negative pool shrinks toward 0
 * via the 0.998 leak factor, and leaf photosynthesis (prod) gradually
 * recovers it.  The old `if (e < 0) e = 0` created a permanent death
 * spiral where the tree could never recover from energy depletion.
 */
export function applyGlobalEnergyPoolAfterGrowth(
    worldGrowth: WorldGrowthState,
    root: TreeSection,
    options?: { strictExeParity?: boolean },
): void {
    const spent = root.energySpent436;
    const prod = root.energyProduction420;
    let e = worldGrowth.energyPool - spent + prod;
    e *= GrowthConstants.ENERGY_LEAK as number;
    // Gameplay stabilizer (TS-only): keep global pool within 100% reference band.
    // Strict parity path must match exe behavior and skip this cap.
    if (!options?.strictExeParity) {
        const maxPool = GrowthConstants.INITIAL_ENERGY_POOL_196 as number;
        if (e > maxPool) e = maxPool;
    }
    worldGrowth.energyPool = e;
    root.energy = worldGrowth.normalizedEnergy as Float32;
}
