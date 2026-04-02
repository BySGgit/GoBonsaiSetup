import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { TreeRoot } from "../TreeRoot";
import { GrowthController, GrowthStats } from "../GrowthController";
import { GrowthConstants } from "../config/GrowthConstants";
import { MSVCRand } from "../MSVCRand";
import {
    clearGrowthScratchATree,
} from "./sub40DC90PoolBalance";
import {
    aggregateEnergy420436PostOrder,
    applySub414E10PostOrderTail,
} from "./sub414E10";
import { WorldGrowthState } from "../world/WorldGrowthState";
import {
    serviceLightTraceQueue,
    rebuildLeafQueue,
    updateLightSpatialBoundsSub450BD0,
} from "./lightTracingSub40E460";
import { perFramePhysicsSub4143E0 } from "./perFramePhysicsSub4143E0";
import { processDetachFlags } from "./detachPipelineSub40EEE0";
import { updateWorldObjectsSub40F140 } from "./worldObjectPipelineSub40F140";
import {
    propagateTransformsSub450BD0,
    syncGroupQuaternionsFromRotationForMetabolism,
} from "./transformChainSub450BD0";
import { resolveStrictExeSimPath } from "./strictExeSimPath";
import { runSub40DC90GrowthTick } from "./sub40DC90GrowthTick";

/** sub_4130D0.c: `dword_4D8C14 > dword_4D52DC` → прирост `flt_4D7EF8` = 0 */
function sceneObjectCountExceeds4130Threshold(scene: THREE.Scene): boolean {
    const cap = GrowthConstants.DWORD_4D52DC_SCENE_OBJECT_THRESHOLD as number;
    if (cap <= 0) return false;
    let n = 0;
    scene.traverse(() => {
        n++;
    });
    return n > cap;
}

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
    /**
     * Аналог `sub_412D20` в `sub_4130D0.c`: обновление ветра/среды **сразу перед** слотом +12 (`sub_4143E0`),
     * после блока лучей (`sub_40E230`/`sub_40E460` у нас — `serviceLightTraceQueue`).
     */
    tickEnvironment: () => void;
    /** sub_40DC90 §2.2 randomAutoCuts — при включённом флаге INI */
    rng?: MSVCRand;
    /** Сцена: отсоединённые секции (sub_40EEE0 → sub_40F140) */
    scene: THREE.Scene;
    /**
     * Паритет с exe: отключить TS-only (см. `strictExeSimPath.ts`). Если не задан — `VITE_STRICT_EXE_SIM_PATH`.
     */
    strictExeSimPath?: boolean;
    /**
     * Длительность одного `sub_4130D0` (exe: `flt_4DBEE4` ≈ 1/30). Накопитель `flt_4D7EF8` += `FLT_4D526C * simFrameDt`.
     */
    simFrameDt?: number;
    /**
     * Шаг для визуала (`TreeSection.update`, корни): частота рендера. По умолчанию `deltaTime`.
     */
    renderDeltaTime?: number;
};

/**
 * Один кадр симуляции дерева.
 *
 * **Привязка к exe (см. GUIDES/spec_update_growth_sub_40DC90.md):**
 * - §2.2 randomAutoCuts → §2.3 день/год → §2.4 сезон + `root+432` → §2.5 virtual `+36` (у нас `distributeEnergyBudget432DownTree`)
 *   → затем баланс `+420/+436` и утечка (у нас `aggregateEnergy420436PostOrder` + `applyGlobalEnergyPoolAfterGrowth`).
 * **Игровой кадр exe (`sub_4130D0`, `decompiled/sub_4130D0.c`):**
 * - За один вызов `sub_4130D0` в `flt_4D7EF8` добавляется `flt_4D526C * 0.033333335` (у нас `GrowthConstants`).
 * - Пока `flt_4D7EF8 ≥ 1`: пары `sub_40DC90` → `vtable+16` (`sub_450BD0`) — реализовано как `runSub40DC90GrowthTick` + `propagateTransformsSub450BD0`.
 * - Опционально пакет света `sub_40E0A0` → `sub_40E230` → `sub_40E460` (`byte_4CA64A`).
 * - Затем хвост кадра: `sub_44E6C0` → `sub_407BB0` → **`sub_412D20`** → **`vtable+12`** (дерево: `sub_4143E0`) →
 *   `sub_412A50` → снова `vtable+16` (`sub_450BD0`) → **`vtable+48` → `sub_414270`** (`processDetachFlags` после `root.update`).
 * Частота **`sub_4130D0`**: `sub_412700` (~30 Гц) — в `BonsaiController` (`simTimeBank412700` + `SIM_FRAME_DT_SUB_412700`).
 * `sub_408D60` (animateGrowth) — на частоте рендера, не внутри `run`.
 * Метаболизм, лучи и `sub_4143E0` — один раз за вызов `run` после цикла `sub_40DC90`.
 *
 * **`strictExeSimPath`:** отключает APPROX-слои и визуальный sway — см. `strictExeSimPath.ts`.
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
            strictExeSimPath: strictOverride,
            simFrameDt: simFrameDtParam,
            renderDeltaTime: renderDeltaParam,
        } = p;

        const strictExe = resolveStrictExeSimPath(strictOverride);
        void timeSpeed; // масштаб времени — в `BonsaiController` (capped delta → sim-банк), не здесь
        const simFrameDt =
            simFrameDtParam ?? (GrowthConstants.SIM_FRAME_DT_SUB_412700 as number);
        const renderDelta = renderDeltaParam ?? deltaTime;

        // --- Подготовка матриц ---
        root.group.updateMatrixWorld(true);

        // sub_4130D0: накопитель flt_4D7EF8; целая часть = число вызовов sub_40DC90 до блока света/метаболизма
        let v8 =
            (GrowthConstants.FLT_4D526C_GAME_SPEED as number) * simFrameDt;
        if (sceneObjectCountExceeds4130Threshold(scene)) {
            v8 = 0;
        }
        worldGrowth.growthAccumulator4D7EF8 += v8;
        clearGrowthScratchATree(root);

        const maxGrowIters = GrowthConstants.MAX_SUB_40DC90_ITERATIONS_PER_4130D0;
        let growIters = 0;
        while (
            worldGrowth.growthAccumulator4D7EF8 >= 1.0 &&
            growIters < maxGrowIters
        ) {
            worldGrowth.growthAccumulator4D7EF8 -= 1.0;
            growIters++;
            runSub40DC90GrowthTick(
                this.growth,
                stats,
                root,
                worldGrowth,
                onSimulationYearCrossed,
                rng,
            );
            propagateTransformsSub450BD0(root);
        }
        // exe trace: flt_4D7EF8 = 0.0 at sub_40E0A0 entry after while-loop
        worldGrowth.growthAccumulator4D7EF8 = 0;

        // После цикла: метаболизм и rollup scratch → пул (один раз за sub_4130D0)
        root.group.updateMatrixWorld(true);
        syncGroupQuaternionsFromRotationForMetabolism(root);
        TreeSection.syncTransformMatricesFromWorld(root);

        const simulationDay = worldGrowth.simulationDay;

        // --- sub_416510 (часть): свет → энергия на секциях; +436 на листьях (терминальные секции) ---
        const lightDirection = GrowthConstants.LIGHT_VECTOR.clone().normalize();
        const metabolism = this.growth.updateMetabolism(
            stats,
            root,
            lightDirection,
            lightIntensity,
            simFrameDt,
        );

        // --- Scratch energy values for aggregation (stripped-down sub_416510 tail) ---
        this.growth.updateEnergyScratches(root, simFrameDt);

        // --- sub_414E10: rollup +420/+436/+480/+484 после метаболизма (для лучей/физики) ---
        // Pool update (leak) только внутри sub_40DC90 — НЕ повторяем снаружи.
        aggregateEnergy420436PostOrder(root);
        applySub414E10PostOrderTail(root);

        // sub_40E230 + sub_40E460: очередь листьев → лучи, обновление +196..+212 (lightResponseVec / smoothedLight*)
        root.group.updateMatrixWorld(true);
        updateLightSpatialBoundsSub450BD0(root);
        rebuildLeafQueue(root);
        serviceLightTraceQueue(root, wind, rng);

        // sub_414A70: this+352 к миру после лучей (updateMatrixWorld выше)
        TreeSection.syncTransformMatricesFromWorld(root);

        // sub_4130D0.c: sub_412D20() перед (*vtable+12) → sub_4143E0
        if (!strictExe) {
            tickEnvironment();
        }

        // --- sub_4143E0 (slot +12): centroid, 414A70/414BB0, сглаживание +216..+232 ---
        perFramePhysicsSub4143E0(root, wind, {
            twigPhototropismApprox: !strictExe,
        });

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
            renderDelta,
            strictExe,
        );

        root.group.updateMatrixWorld(true);
        TreeSection.syncTransformMatricesFromWorld(root);

        // Хвост sub_4130D0: второй vtable+16 (sub_450BD0), затем vtable+48 (sub_414270)
        propagateTransformsSub450BD0(root);

        if (rng) {
            processDetachFlags(root, rng);
            updateWorldObjectsSub40F140(scene, wind, rng);
        }

        for (const tr of treeRoots) {
            tr.update(ageFactor, renderDelta);
        }

        return metabolism.logs;
    }
}
