import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { TreeRoot } from "../TreeRoot";
import { GrowthController, GrowthStats } from "../GrowthController";
import { GrowthConstants } from "../config/GrowthConstants";
import { MSVCRand } from "../MSVCRand";
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
import { maybeRandomAutoCutsSub40DC902 } from "./sub40DC90RandomAutoCuts";
import { WorldGrowthState } from "../world/WorldGrowthState";
import { sub414CE0Yearly } from "./sub414CE0";
import { setSlot36SimulationDay } from "./frameState";
import {
    serviceLightTraceQueue,
    rebuildLeafQueue,
    updateLightSpatialBoundsSub450BD0,
} from "./lightTracingSub40E460";
import { perFramePhysicsSub4143E0 } from "./perFramePhysicsSub4143E0";
import { processDetachFlags } from "./detachPipelineSub40EEE0";
import { updateWorldObjectsSub40F140 } from "./worldObjectPipelineSub40F140";
import { syncGroupQuaternionsFromRotationForMetabolism } from "./transformChainSub450BD0";

export type GrowthFramePipelineParams = {
    deltaTime: number;
    timeSpeed: number;
    stats: GrowthStats;
    root: TreeSection;
    /** dword_4D7EE8 — инкремент +216 и сезон sub_40EE60 внутри run (после §2.2) */
    worldGrowth: WorldGrowthState;
    /** Сохранение/лог при смене года (sub_40DC90 §2.3) */
    onSimulationYearCrossed?: () => void;
    lightIntensity: number;
    wind: THREE.Vector3;
    treeRoots: TreeRoot[];
    /** sub_4093B0 / визуал: колебание ветра перед root.update */
    tickEnvironment: () => void;
    /** sub_40DC90 §2.2 randomAutoCuts — при включённом флаге INI */
    rng?: MSVCRand;
    /** Сцена: отсоединённые секции (sub_40EEE0 → sub_40F140) */
    scene: THREE.Scene;
};

/**
 * Один кадр симуляции дерева в порядке, близком к связке BonsaiController.update.
 * Комментарии — соответствие оригиналу (цель паритета — sub_40DC90 + слот +36 по спекам).
 *
 * Порядок sub_40DC90 §2.2–2.6: randomAutoCuts → *(v0+216)+=1 и годовой тик → сезон sub_40EE60 →
 * root+432 → слот +36 → баланс E. Метаболизм — MetabolismService (листья: processLeafMetabolism внутри); rollup — sub414E10; detach + world objects.
 */
export class GrowthFramePipeline {
    constructor(private readonly growth: GrowthController) {}

    run(p: GrowthFramePipelineParams): string[] {
        // sub_40DC90.c: весь кадр (§2.2–2.6) только при byte_4D62DC != 0
        if (!GrowthConstants.BYTE_4D62DC_UPDATE_GROWTH) {
            return [];
        }

        const {
            deltaTime,
            timeSpeed,
            stats,
            root,
            worldGrowth,
            onSimulationYearCrossed,
            lightIntensity,
            wind,
            treeRoots,
            tickEnvironment,
            rng,
            scene,
        } = p;

        // --- sub_408D60: интерполяция целей ствола / возраста (UI-статы) ---
        this.growth.animateGrowth(stats, deltaTime, timeSpeed);

        // --- Подготовка матриц для света (до sub_416510 inverse world) ---
        root.group.updateMatrixWorld(true);

        if (rng) {
            maybeRandomAutoCutsSub40DC902(root, rng);
        }

        const yearCrossed = worldGrowth.advanceSimulationDay();
        if (yearCrossed) {
            this.growth.updateYearlyTargets(stats, root);
            sub414CE0Yearly(root);
            root.sub414CE0SeedBudget428 = 1.0;
            onSimulationYearCrossed?.();
        }

        const seasonFactor = worldGrowth.seasonFactor();
        const simulationDay = worldGrowth.simulationDay;

        // Set global simulation day for branching dispatcher (mirrors dword_4D7EE8 + 216)
        setSlot36SimulationDay(simulationDay);

        // --- sub_40DC90 + sub_414E10: сброс +420/+432 на дереве, бюджет корня, веса +428, доли child+432 ---
        resetAllEnergyAggregates(root);
        syncEnergyWeight428FromGeometry(root);
        writeRootEnergyBudget432(root, stats.energy, seasonFactor);

        // sub_40DC90 §2.5: (*root+36) — distribute + virtualSlot36 dispatch (Seed→Bud→Twig lifecycle)
        // Inside this call: energy distribution, Bud→Twig conversion, twig girth/length/branch, health/death
        distributeEnergyBudget432DownTree(root, rng);

        // После слота +36: кватернион роста → Object3D (иначе sub_416510 / листья до конца кадра со старым matrixWorld)
        syncGroupQuaternionsFromRotationForMetabolism(root);
        // Актуальные matrixWorld для метаболизма (sub_416510) и лучей
        root.group.updateMatrixWorld(true);

        // --- sub_416510 (часть): свет → энергия на секциях; +436 на листьях (терминальные секции) ---
        const lightDirection = GrowthConstants.LIGHT_VECTOR.clone().normalize();
        const metabolism = this.growth.updateMetabolism(
            stats,
            root,
            lightDirection,
            lightIntensity,
            deltaTime,
        );

        // --- Scratch energy values for aggregation (stripped-down sub_416510 tail) ---
        this.growth.updateEnergyScratches(root, deltaTime);

        // --- sub_414E10: rollup +420/+436/+480/+484; хвост +424/+440/+36; затем sub_40DC90 leak ---
        aggregateEnergy420436PostOrder(root);
        applySub414E10PostOrderTail(root);
        applyGlobalEnergyPoolAfterGrowth(stats, root);

        // sub_40E230 + sub_40E460: очередь листьев → лучи, обновление +196..+212 (lightResponseVec / smoothedLight*)
        root.group.updateMatrixWorld(true);
        updateLightSpatialBoundsSub450BD0(root);
        rebuildLeafQueue(root);
        serviceLightTraceQueue(root, wind, rng);

        // --- Physics: wind/gravity torque → natural curvature; сглаживание +216..+232; light-seek на twigs ---
        perFramePhysicsSub4143E0(root, wind);

        if (rng) {
            processDetachFlags(root, rng);
            updateWorldObjectsSub40F140(scene, wind, rng);
        }

        tickEnvironment();

        const ageFactor = stats.age / 10.0;
        const dayOfYear = simulationDay % 365;

        // --- Визуальное обновление иерархии ---
        root.update(
            ageFactor,
            lightIntensity,
            {
                thickness: stats.trunkThickness,
                bend: stats.trunkBend,
                color: new THREE.Color(stats.colorR, stats.colorG, stats.colorB),
            },
            stats.health,
            wind,
            dayOfYear,
            deltaTime
        );

        root.group.updateMatrixWorld(true);
        TreeSection.syncTransformMatricesFromWorld(root);

        for (const tr of treeRoots) {
            tr.update(ageFactor, deltaTime);
        }

        return metabolism.logs;
    }
}
