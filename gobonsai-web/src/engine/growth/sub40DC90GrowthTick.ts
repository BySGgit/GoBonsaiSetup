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
    distributeEnergyBudget432DownTree,
    aggregateEnergy420436PostOrder,
    applySub414E10PostOrderTail,
} from "./sub414E10";
import { syncGroupQuaternionsFromRotationForMetabolism } from "./transformChainSub450BD0";
import { setSlot36SimulationDay } from "./frameState";
import { sub414CE0Yearly } from "./sub414CE0";
import { GrowthConstants } from "../config/GrowthConstants";
import {
    createBooleanPropertyBinding,
    createNumericPropertyBinding,
    createSub4032WideString,
    createSub408600Entry,
    sub401DD0DestroyIniEntry,
    sub4032D0Assign,
    sub4038B0Register,
    sub408600Register,
    subAtexitRegister,
} from "../config/IniRegistrySub408600";

let _sub40DC90InitMask4DBDA4 = 0;
const _updateGrowthMeta4DBD80 = createSub408600Entry();
const _randomAutoCutsMeta4DBD5C = createSub408600Entry();
const _energyUseRateMeta4DBD38 = createSub408600Entry();
const _energyLeakMeta4DBD14 = createSub408600Entry();

/** sub_472110 -> sub_401DD0(&unk_4DBD80) */
function sub472110CleanupStub(): void {
    sub401DD0DestroyIniEntry(_updateGrowthMeta4DBD80);
}
/** sub_472100 -> sub_401DD0(&unk_4DBD5C) */
function sub472100CleanupStub(): void {
    sub401DD0DestroyIniEntry(_randomAutoCutsMeta4DBD5C);
}
/** sub_4720F0 -> sub_401DD0(&unk_4DBD38) */
function sub4720F0CleanupStub(): void {
    sub401DD0DestroyIniEntry(_energyUseRateMeta4DBD38);
}
/** sub_4720E0 -> sub_401DD0(&unk_4DBD14) */
function sub4720E0CleanupStub(): void {
    sub401DD0DestroyIniEntry(_energyLeakMeta4DBD14);
}

function ensureSub40DC90IniInits(): void {
    if ((_sub40DC90InitMask4DBDA4 & 1) === 0) {
        _sub40DC90InitMask4DBDA4 |= 1;
        const key = createSub4032WideString();
        sub4032D0Assign(key, "updateGrowth", 0x0c);
        sub4038B0Register(
            key,
            _updateGrowthMeta4DBD80,
            createBooleanPropertyBinding(GrowthConstants, "BYTE_4D62DC_UPDATE_GROWTH"),
        );
        subAtexitRegister(sub472110CleanupStub);
    }

    if ((_sub40DC90InitMask4DBDA4 & 2) === 0) {
        _sub40DC90InitMask4DBDA4 |= 2;
        const key = createSub4032WideString();
        sub4032D0Assign(key, "randomAutoCuts", 0x0e);
        sub4038B0Register(
            key,
            _randomAutoCutsMeta4DBD5C,
            createBooleanPropertyBinding(GrowthConstants, "BYTE_4D8CED_RANDOM_AUTO_CUTS"),
        );
        subAtexitRegister(sub472100CleanupStub);
    }

    if ((_sub40DC90InitMask4DBDA4 & 4) === 0) {
        _sub40DC90InitMask4DBDA4 |= 4;
        const key = createSub4032WideString();
        sub4032D0Assign(key, "energyUseRate", 0x0d);
        sub408600Register(
            key,
            _energyUseRateMeta4DBD38,
            createNumericPropertyBinding(GrowthConstants, "ENERGY_USE_RATE"),
        );
        subAtexitRegister(sub4720F0CleanupStub);
    }

    if ((_sub40DC90InitMask4DBDA4 & 8) === 0) {
        _sub40DC90InitMask4DBDA4 |= 8;
        const key = createSub4032WideString();
        sub4032D0Assign(key, "energyLeak", 0x0a);
        sub408600Register(
            key,
            _energyLeakMeta4DBD14,
            createNumericPropertyBinding(GrowthConstants, "ENERGY_LEAK"),
        );
        subAtexitRegister(sub4720E0CleanupStub);
    }
}

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
    strictExeParity?: boolean,
): void {
    ensureSub40DC90IniInits();

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
    applyGlobalEnergyPoolAfterGrowth(worldGrowth, root, {
        strictExeParity: strictExeParity === true,
    });
}
