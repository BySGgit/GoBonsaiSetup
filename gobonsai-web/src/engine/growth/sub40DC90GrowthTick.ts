import { TreeSection } from "../TreeSection";
import { GrowthController, GrowthStats } from "../GrowthController";
import { WorldGrowthState } from "../world/WorldGrowthState";
import { MSVCRand } from "../MSVCRand";
import { maybeRandomAutoCutsSub40DC902 } from "./sub40DC90RandomAutoCuts";
import {
    resetAllEnergyAggregates,
    writeRootEnergyBudget432,
    applyGlobalEnergyPoolAfterGrowth,
} from "./sub40DC90PoolBalance";
import {
    syncEnergyWeight428FromGeometry,
    distributeEnergyBudget432DownTree,
    aggregateEnergy420436PostOrder,
    applySub414E10PostOrderTail,
} from "./sub414E10";
import { syncGroupQuaternionsFromRotationForMetabolism } from "./transformChainSub450BD0";
import { setSlot36SimulationDay } from "./frameState";
import { sub414CE0Yearly } from "./sub414CE0";

/**
 * Один полный `sub_40DC90()` по энергии/росту (без метаболизма листьев, лучей и `sub_4143E0`).
 * После каждого тика в `sub_4130D0.c` вызывается `vtable+16` → `sub_450BD0` — делайте снаружи
 * (`propagateTransformsSub450BD0`).
 */
export function runSub40DC90GrowthTick(
    growth: GrowthController,
    stats: GrowthStats,
    root: TreeSection,
    worldGrowth: WorldGrowthState,
    onSimulationYearCrossed?: () => void,
    rng?: MSVCRand,
): void {
    if (rng) {
        maybeRandomAutoCutsSub40DC902(root, rng);
    }

    const yearCrossed = worldGrowth.advanceSimulationDay();
    if (yearCrossed) {
        growth.updateYearlyTargets(stats, root, worldGrowth);
        sub414CE0Yearly(root);
        root.sub414CE0SeedBudget428 = 1.0;
        onSimulationYearCrossed?.();
    }

    const seasonFactor = worldGrowth.seasonFactor();
    const simulationDay = worldGrowth.simulationDay;
    setSlot36SimulationDay(simulationDay);

    resetAllEnergyAggregates(root);
    syncEnergyWeight428FromGeometry(root);
    writeRootEnergyBudget432(root, worldGrowth.energyPool, seasonFactor);

    distributeEnergyBudget432DownTree(
        root,
        rng,
        worldGrowth.worldFlagByte220,
    );

    syncGroupQuaternionsFromRotationForMetabolism(root);
    root.group.updateMatrixWorld(true);
    TreeSection.syncTransformMatricesFromWorld(root);

    aggregateEnergy420436PostOrder(root);
    applySub414E10PostOrderTail(root);
    applyGlobalEnergyPoolAfterGrowth(worldGrowth, root);
}
