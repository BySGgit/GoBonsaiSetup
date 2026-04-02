import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { SectionRuntimeType } from "../SectionRuntimeType";
import {
    GrowthConstants,
    byte4D822AForSectionType,
    sampleMaxGrowth452Sub4159C0,
} from "../config/GrowthConstants";
import { Float32 } from "../math/MathTypes";
import { TransformService } from "../math/TransformService";
import { Sub416510Rotation } from "../math/Sub416510Rotation";
import { getSlot36SimulationDay } from "./frameState";

const _rollAxisZ = new THREE.Vector3(0, 0, 1);
const _rollQ4158 = new THREE.Quaternion();

/**
 * sub_417F40.c — branching dispatcher for TreeSectionTwig.
 * Called from twigUpdateSub417C90 when growthFlag512 == false.
 *
 * Decision tree:
 *   yearsSinceBranch < 1  →  do nothing
 *   yearsSinceBranch > 3 AND girth > 0.2  →  lateral (sub_4188E0)
 *   childCount <= 1 (with filter)  →  apical (sub_417FF0) or simplified (sub_418660)
 */

function sub416300Filter(section: TreeSection | null): TreeSection | null {
    if (!section) return null;
    return byte4D822AForSectionType(section.sectionRuntimeType4) ? section : null;
}

function yearsSinceBranch(section: TreeSection): number {
    const worldTime = getSlot36SimulationDay();
    const birthTime = worldTime - (section.energyTickCounter440 as number);
    return Math.floor(worldTime / 365) - Math.floor(birthTime / 365);
}

/** sub_415470.c — та же метрика «лет», что в sub_417F40, для дочерней секции (условие апикального ветвления). */
function sub415470Years(section: TreeSection): number {
    return yearsSinceBranch(section);
}

export function branchingDispatcherSub417F40(
    section: TreeSection,
    rng: MSVCRand,
): void {
    const years = yearsSinceBranch(section);
    if (years < 1) return;

    if (years > 3 && (section.twigRadius444 as number) > 0.2) {
        lateralBranchSub4188E0(section, rng);
    } else {
        // sub_417F40.c: v2<=1 && (v2!=1 || (sub_416300(first)&&sub_415470(first))) → sub_417FF0
        // Иначе ветвление не выполняется (не упрощённое sub_418660 напрямую).
        const childCount = section.children.length;
        if (childCount <= 1) {
            if (childCount === 0) {
                apicalBranchSub417FF0(section, rng);
            } else {
                const firstTwig = sub416300Filter(section.children[0]);
                const okChild =
                    firstTwig !== null && sub415470Years(firstTwig) !== 0;
                if (okChild) {
                    apicalBranchSub417FF0(section, rng);
                }
            }
        }
    }
}

// ─── sub_4188E0: lateral branch ─────────────────────────────────────

/**
 * sub_4188E0.c: create a lateral (side) branch Bud.
 * Trigger: available energy (budget - spent) >= minBudEnergy.
 * Probability proportional to energy surplus, clamped to [0, 0.003].
 */
function lateralBranchSub4188E0(
    section: TreeSection,
    rng: MSVCRand,
): void {
    const minE = GrowthConstants.FLT_4D862C as number;
    const maxE = GrowthConstants.FLT_4D8630 as number;
    const available = (section.energyBudget432 as number) - (section.energySpent436 as number);

    if (available < minE) return;

    // sub_4188E0.c: v14 = v13 / flt_4D8630 * 0.0003000000142492354; затем clamp [0, 0.003]
    // Сравнение: if (v14 > rand/32767) — у нас randFloat() ∈ [0,1] как rand/32767
    //
    // Важно: этот шанс влияет только на sub_4188E0 (боковой побег). Рост 5→8 секций у молодого
    // дерева идёт через sub_417FF0 (апикальное / пара), не через v14 — поэтому убрать веб-множитель
    // у v14 часто «не видно» в логах/форме, пока латераль ни разу не прошёл rand.
    let v14 = (available / maxE) * 0.0003;
    v14 = Math.max(0, Math.min(0.003, v14));

    if (rng.randFloat() >= v14) return;

    // full.c sub_4188E0: порядок rand после прохождения v14 — как в exe (детерминизм сидов).
    const v15 = rng.randFloat() * (Math.PI * 2) - Math.PI;
    const v19 = rng.randFloat() * 1.1 - 1.6;
    const v20 = rng.randFloat() * 0.1000000014901161 - 0.05000000074505806 + v15;
    const v12 = v20;
    const v11 = rng.randFloat();
    const maxGrowth452 = sampleMaxGrowth452Sub4159C0(rng);
    const v22 = (section.twigRadius444 as number) * 0.8500000238418579;

    // sub_413F50: YPR (0, v19, -v15); sub_4158D0(v27, v22, v11, v12) — шаблон +240 до полного порта мат4
    const bud = createBudChild(section, 0, v19, rng, {
        roll: -v15,
        branchPosition: v11,
        maxGrowth452,
        lateralTransY4158: v22,
        lateralRoll4158Z: v12,
    });
    if (!bud) return;

    section.spawnDelta480 = (section.spawnDelta480 + 1) >>> 0;

    // sub_4188E0.c: v23 = minE + (min(available,maxE)-minE)*rand; +436 += v23
    let v5 = available;
    if (maxE <= available) v5 = maxE;
    const v23 = minE + (v5 - minE) * rng.randFloat();
    section.energySpent436 = ((section.energySpent436 as number) + v23) as Float32;

    normalizeChildWeights(section);
}

// ─── sub_417FF0: apical/paired branching ────────────────────────────

/**
 * sub_417FF0.c: apical branching — extends the axis.
 * If section has children: creates 2 new buds with geometry.
 * If no children: falls through to sub_418660 (simplified).
 */
function apicalBranchSub417FF0(
    section: TreeSection,
    rng: MSVCRand,
): void {
    const minE = GrowthConstants.FLT_4D862C as number;
    const apicalStr = GrowthConstants.FLT_4D8638 as number;
    const available = (section.energyBudget432 as number) - (section.energySpent436 as number);

    // sub_417FF0.c: v33 = (1 - flt_4D8638)^(rollup484 - 1)
    let v33 = 1.0;
    const roll = section.rollupDword484 >>> 0;
    for (let i = 0; i < Math.max(0, roll - 1); i++) {
        v33 *= 1.0 - apicalStr;
    }

    // sub_417FF0.c: v17 = flt_4D8638 * (available * v33); только при v17 >= minBud
    const v17 = apicalStr * available * v33;
    if (v17 < minE) return;

    section.energySpent436 = ((section.energySpent436 as number) + v17) as Float32;

    if (section.children.length === 0) {
        simplifiedBranchSub418660(section, rng, false);
        return;
    }

    // Paired branching: два побега; стоимость уже списана (v17)
    // TODO(original): sub_417FF0.c — цепочка inverse/light/acos и несколько rand до каждой sub_4159C0; здесь упрощённые углы, но +452 как в sub_4159C0 (createBudChild).
    const baseYaw = rng.randFloat() * Math.PI * 2;
    const spreadAngle = 0.3 + rng.randFloat() * 0.4;

    const bud1 = createBudChild(section, baseYaw + spreadAngle, -0.3, rng);
    if (bud1) section.spawnDelta480 = (section.spawnDelta480 + 1) >>> 0;
    const bud2 = createBudChild(section, baseYaw - spreadAngle + Math.PI, -0.3, rng);
    if (bud2) section.spawnDelta480 = (section.spawnDelta480 + 1) >>> 0;

    if (bud1 || bud2) {
        normalizeChildWeights(section);
    }
}

// ─── sub_418660: simplified branching ───────────────────────────────

/**
 * sub_418660.c — упрощённое ветвление (full.c ~19059–19122).
 * Первая почка: v11 = rand·2π−π; v7 = rand·0.3; кватернион v13,v14,v15 = (0, v7, −v11); roll матрицы sub_4158D0 — rand·0.1−0.05+v11 (только выравнивание RNG).
 * Вторая почка: при flt_4D862C < +432 и rand<0.2 — v9 = rand·0.9+0.4, roll −(v11+π), вес +428 = (rand·0.1+0.9)·(v7/0.3).
 * @param debit436 — если false, не трогаем +436 (энергия уже списана в sub_417FF0 перед вызовом).
 */
function simplifiedBranchSub418660(
    section: TreeSection,
    rng: MSVCRand,
    debit436: boolean = true,
): void {
    const minE = GrowthConstants.FLT_4D862C as number;
    const budget = section.energyBudget432 as number;
    const available = budget - (section.energySpent436 as number);
    // Одиночный вызов sub_418660: нужен запас энергии. Из sub_417FF0: порог уже проверен (v17), +436 обновлён.
    if (debit436 && available < minE) return;

    const v11 = rng.randFloat() * (Math.PI * 2) - Math.PI;
    const v7 = rng.randFloat() * 0.300000011920929;
    const v8Roll4158D0 = rng.randFloat() * 0.1000000014901161 - 0.05000000074505806 + v11;
    void v8Roll4158D0;

    const bud1 = createBudChild(section, 0, v7, rng, { roll: -v11 });
    if (!bud1) return;

    section.spawnDelta480 = (section.spawnDelta480 + 1) >>> 0;

    if (debit436) {
        section.energySpent436 = ((section.energySpent436 as number) + minE * 0.5) as Float32;
    }

    const v17 = v7 / 0.300000011920929;
    if (minE < budget && rng.randFloat() < 0.2) {
        const v12 = v11 + Math.PI;
        const v9 = rng.randFloat() * 0.9 + 0.4;
        const v10Roll4158D0 =
            rng.randFloat() * 0.1000000014901161 - 0.05000000074505806 + v12;
        void v10Roll4158D0;

        const bud2 = createBudChild(section, 0, v9, rng, { roll: -v12 });
        if (bud2) {
            section.spawnDelta480 = (section.spawnDelta480 + 1) >>> 0;
            const w428 = (rng.randFloat() * 0.1 + 0.9) * v17;
            bud2.energyWeight428 = w428 as Float32;
        }
        if (debit436) {
            section.energySpent436 = ((section.energySpent436 as number) + minE * 0.5) as Float32;
        }
    }

    normalizeChildWeights(section);
}

// ─── Helpers ────────────────────────────────────────────────────────

/** Опции почки после sub_4159C0 / sub_413F50 (латераль задаёт всё из full.c). */
type CreateBudChildOpts = {
    roll?: number;
    branchPosition?: number;
    /** C sub_4158D0: второй аргумент Translation (twigRadius*0.85 родителя). */
    lateralTransY4158?: number;
    /** C sub_4158D0: roll (четвёртый аргумент). */
    lateralRoll4158Z?: number;
    /** C this+452: sub_4159C0 — rand в [0.8*maxBudSize, maxBudSize] */
    maxGrowth452?: number;
};

function createBudChild(
    parent: TreeSection,
    yaw: number,
    pitch: number,
    rng: MSVCRand,
    opts?: CreateBudChildOpts,
): TreeSection | null {
    opts ??= {};
    const bud = new TreeSection(
        parent,
        parent.level + 1,
        rng,
        0.01,
    );
    bud.sectionRuntimeType4 = SectionRuntimeType.TreeSectionBud;
    bud.twigRadius444 = 0.01 as Float32;
    bud.twigLength448 = 0 as Float32;
    bud.energyWeight428 = 1.0 as Float32;
    bud.sub414CE0SeedBudget428 = 1.0 as Float32;
    bud.growthFlag512 = true;

    const roll = opts.roll ?? 0;
    TransformService.rotationYawPitchRoll(bud.targetRotation, yaw, pitch, roll);
    const roll4158 = opts.lateralRoll4158Z;
    if (roll4158 !== undefined && Math.abs(roll4158) > 1e-8) {
        _rollQ4158.setFromAxisAngle(_rollAxisZ, roll4158);
        bud.targetRotation.multiply(_rollQ4158);
    }
    bud.rotationQuaternion.copy(bud.targetRotation);
    bud.rotation.copy(bud.targetRotation);
    Sub416510Rotation.syncBlob80FromQuaternion(bud);

    if (opts.branchPosition !== undefined) {
        bud.branchPosition = opts.branchPosition as Float32;
    }
    if (opts.lateralTransY4158 !== undefined) {
        bud.lateralTransY4158 = opts.lateralTransY4158 as Float32;
    }
    if (opts.lateralRoll4158Z !== undefined) {
        bud.lateralRoll4158Z = opts.lateralRoll4158Z as Float32;
    }
    bud.maxGrowth =
        opts.maxGrowth452 !== undefined
            ? (opts.maxGrowth452 as Float32)
            : sampleMaxGrowth452Sub4159C0(rng);

    parent.children.push(bud);
    bud.updateAttachmentPosition(parent);
    return bud;
}

/**
 * Normalize energyWeight428 across siblings so shares sum to ~1.
 * C: sub_4188E0 normalizes child+428 by sum of all sibling +428.
 */
function normalizeChildWeights(parent: TreeSection): void {
    let sum = 0;
    for (const c of parent.children) {
        sum += c.energyWeight428 as number;
    }
    if (sum <= 0) return;
    for (const c of parent.children) {
        c.energyWeight428 = ((c.energyWeight428 as number) / sum) as Float32;
    }
}
