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
import { sub4084F0NormalizeInPlaceReturnLen, sub408590 } from "../math/Vec3Sub40xPrimitives";
import { sub401B00ExtractBasisZ } from "../world/SectionSpatialQueriesSub40x";
import { getSlot36SimulationDay } from "./frameState";
import { sub413F50AttachChild, sub413F50InitSection } from "./sub413F50Ctor";
import {
    createNumericPropertyBinding,
    createSub4032WideString,
    createSub408600Entry,
    sub401DD0DestroyIniEntry,
    sub4032D0Assign,
    sub408600Register,
    subAtexitRegister,
} from "../config/IniRegistrySub408600";

const _tmpInv417FF0 = new THREE.Matrix4();
const _tmpM3FromInv417FF0 = new THREE.Matrix3();
const _tmpLocalLight417FF0 = new THREE.Vector3();
const _tmpAxisZ417FF0 = new THREE.Vector3(0, 0, 1);
const _tmpForward417FF0 = new THREE.Vector3();
const _tmpMatrix401B00_417FF0 = new THREE.Matrix4();
const _tmpA417FF0 = new THREE.Vector3();
const _tmpB417FF0 = new THREE.Vector3();
const _tmpNegB417FF0 = new THREE.Vector3();
const _tmpCross417FF0 = new THREE.Vector3();
const _randomBudRotationMeta4DBAC4 = createSub408600Entry();
let _sub417FF0InitFlags4DBAE8 = 0;

function sub4724B0CleanupStub(): void {
    sub401DD0DestroyIniEntry(_randomBudRotationMeta4DBAC4);
}

function ensureSub417FF0IniBindings(): void {
    if ((_sub417FF0InitFlags4DBAE8 & 1) !== 0) return;
    _sub417FF0InitFlags4DBAE8 |= 1;
    const key = createSub4032WideString();
    sub4032D0Assign(key, "randomBudRotation", 0x11);
    sub408600Register(
        key,
        _randomBudRotationMeta4DBAC4,
        createNumericPropertyBinding(
            GrowthConstants,
            "FLT_4D642C_RANDOM_BUD_ROTATION",
        ),
    );
    subAtexitRegister(sub4724B0CleanupStub);
}

function sub416300Filter(section: TreeSection | null): TreeSection | null {
    if (!section) return null;
    return byte4D822AForSectionType(section.sectionRuntimeType4) ? section : null;
}

function yearsSinceBranch(section: TreeSection): number {
    const worldTime = getSlot36SimulationDay();
    const worldYears = worldTime / 365.0;
    const birthYears =
        (worldTime - (section.energyTickCounter440 as number)) / 365.0;
    // C cast-to-int truncates toward zero, not Math.floor for negatives.
    const toIntTrunc = (v: number): number => (v < 0 ? Math.ceil(v) : Math.floor(v));
    return toIntTrunc(worldYears) - toIntTrunc(birthYears);
}

function sub415470Years(section: TreeSection): number {
    return yearsSinceBranch(section);
}

/**
 * sub_417FF0 helper chain:
 * - D3DXMatrixInverse(this+104)
 * - sub_401540(+196, inverse) == D3DXVec3TransformNormal (no translation, no transpose)
 * - sub_401180(localLight, zAxis) + normalize
 * - sub_401B00(this) -> basis-Z extraction from this+40 equivalent matrix
 * - sub_401180(forward, A) + normalize
 * - angle/sign via dot/cross like decompiled chain
 */
function signedBudBaseAngleSub417FF0(section: TreeSection): number {
    _tmpInv417FF0.copy(section.transformMatrix);
    _tmpM3FromInv417FF0.setFromMatrix4(_tmpInv417FF0);
    _tmpLocalLight417FF0.copy(section.lightResponseVec).applyMatrix3(_tmpM3FromInv417FF0);
    if (sub4084F0NormalizeInPlaceReturnLen(_tmpLocalLight417FF0) <= 0) return 0;

    _tmpA417FF0.crossVectors(_tmpLocalLight417FF0, _tmpAxisZ417FF0);
    if (sub4084F0NormalizeInPlaceReturnLen(_tmpA417FF0) <= 0) return 0;

    _tmpMatrix401B00_417FF0.makeRotationFromQuaternion(section.rotationQuaternion);
    sub401B00ExtractBasisZ({ matrix40: _tmpMatrix401B00_417FF0 }, _tmpForward417FF0);
    if (sub4084F0NormalizeInPlaceReturnLen(_tmpForward417FF0) <= 0) return 0;

    _tmpB417FF0.crossVectors(_tmpForward417FF0, _tmpA417FF0);
    if (sub4084F0NormalizeInPlaceReturnLen(_tmpB417FF0) <= 0) return 0;

    sub408590(_tmpNegB417FF0, _tmpB417FF0);
    let dot = _tmpNegB417FF0.dot(_tmpA417FF0);
    if (dot > 1) dot = 1;
    else if (dot < -1) dot = -1;
    const angle = Math.acos(dot);

    _tmpCross417FF0.crossVectors(_tmpA417FF0, _tmpNegB417FF0);
    const sign = _tmpCross417FF0.z <= 0 ? -1 : 1;
    return sign * angle;
}

/**
 * sub_417F40 branching dispatcher for Twig (+36 path when growthFlag512 == false).
 */
export function branchingDispatcherSub417F40(
    section: TreeSection,
    rng: MSVCRand,
): void {
    const years = yearsSinceBranch(section);
    if (years < 1) return;

    if (years > 3 && (section.twigRadius444 as number) > 0.2) {
        lateralBranchSub4188E0(section, rng);
        return;
    }

    // EXE +172 list for this path effectively tracks branch chain children.
    // In TS leaf sections share `children`, so ignore leaves for branching gates.
    const growthChildren = section.children.filter(
        (c) => c.sectionRuntimeType4 !== SectionRuntimeType.TreeSectionLeaf,
    );
    const childCount = growthChildren.length;
    if (childCount > 1) return;

    if (childCount === 0) {
        apicalBranchSub417FF0(section, rng);
        return;
    }

    const firstTwig = sub416300Filter(growthChildren[0] ?? null);
    const okChild = firstTwig !== null && sub415470Years(firstTwig) !== 0;
    if (okChild) {
        apicalBranchSub417FF0(section, rng);
    }
}

/**
 * sub_4188E0: lateral branch bud with energy-proportional probability.
 */
function lateralBranchSub4188E0(
    section: TreeSection,
    rng: MSVCRand,
): void {
    const minE = GrowthConstants.FLT_4D862C as number;
    const maxE = GrowthConstants.FLT_4D8630 as number;
    const available =
        (section.energyBudget432 as number) - (section.energySpent436 as number);

    if (available < minE) return;

    let p = (available / maxE) * 0.0003000000142492354;
    if (p < 0) p = 0;
    else if (p > 0.003) p = 0.003;
    if (rng.randFloat() >= p) return;

    const v15 = rng.randFloat() * (Math.PI * 2) - Math.PI;
    const v19 = rng.randFloat() * 1.100000023841858 - 1.600000023841858;
    const v20 =
        rng.randFloat() * 0.1000000014901161 -
        0.05000000074505806 +
        v15;
    const v11 = rng.randFloat();
    const v22 = (section.twigRadius444 as number) * 0.8500000238418579;

    const bud = createBudChild(section, 0, v19, rng, {
        roll: -v15,
        branchPosition: v11,
        lateralTransY4158: v22,
        lateralRoll4158Z: v20,
    });
    if (!bud) return;

    section.spawnDelta480 = (section.spawnDelta480 + 1) >>> 0;

    let v17 = available;
    if (v17 > maxE) v17 = maxE;
    const spentDelta = minE + (v17 - minE) * rng.randFloat();
    section.energySpent436 =
        ((section.energySpent436 as number) + spentDelta) as Float32;

    let sumWeights = 0;
    for (const c of section.children) {
        sumWeights += c.energyWeight428 as number;
    }

    let v24 = 1.0;
    const budget = section.energyBudget432 as number;
    if (sumWeights > 0 && budget > 1e-8) {
        const v25 = spentDelta / budget;
        if (v25 > 0 && v25 < 1) {
            v24 = (sumWeights * v25) / (1.0 - v25);
        }
    }

    bud.energyWeight428 = v24 as Float32;
    bud.energyAccumulator424 = v24 as Float32;
}

/**
 * sub_417FF0: apical/paired branching.
 */
function apicalBranchSub417FF0(
    section: TreeSection,
    rng: MSVCRand,
): void {
    const minE = GrowthConstants.FLT_4D862C as number;
    const apicalStr = GrowthConstants.FLT_4D8638 as number;
    const available =
        (section.energyBudget432 as number) - (section.energySpent436 as number);

    const growthChildren = section.children.filter(
        (c) => c.sectionRuntimeType4 !== SectionRuntimeType.TreeSectionLeaf,
    );
    const childCount = growthChildren.length >>> 0;
    let oldChildWeight428 =
        childCount === 1 ? (growthChildren[0].energyWeight428 as number) : 0.0;
    // Recovery guard: old saves may contain zeroed weights from previous regressions.
    if (childCount === 1 && oldChildWeight428 <= 1e-6) {
        oldChildWeight428 = 1.0;
    }

    let v33 = 1.0;
    const roll = section.rollupDword484 >>> 0;
    for (let i = 0; i < Math.max(0, roll - 1); i++) {
        v33 *= 1.0 - apicalStr;
    }

    const v17 = apicalStr * (available * v33);
    if (v17 < minE) return;

    section.energySpent436 = ((section.energySpent436 as number) + v17) as Float32;

    if (childCount === 0) {
        simplifiedBranchSub418660(section, rng);
        return;
    }

    ensureSub417FF0IniBindings();

    const v30 = signedBudBaseAngleSub417FF0(section);
    const randBud =
        (rng.randFloat() * 2.0 - 1.0) *
        (GrowthConstants.FLT_4D642C_RANDOM_BUD_ROTATION as number);
    let v31 = randBud + v30;
    if ((section.rollupDword484 & 1) === 0) {
        v31 += Math.PI * 0.5;
    }

    const v25 = rng.randFloat() * 0.5 + 1.0;
    const v19 =
        rng.randFloat() * 0.1000000014901161 -
        0.05000000074505806 +
        v31;
    void v19;
    const bud1 = createBudChild(section, 0, v25, rng, {
        roll: -v31,
        lateralRoll4158Z: v19,
    });
    if (bud1) {
        section.spawnDelta480 = (section.spawnDelta480 + 1) >>> 0;
    }

    const denom = 1.0 - v33;
    const baseWeight =
        Math.abs(denom) > 1e-8
            ? ((apicalStr * v33) * oldChildWeight428) / denom
            : 0.0;

    if (bud1) {
        const w1 =
            (rng.randFloat() * 0.800000011920929 + 0.2000000029802322) *
            baseWeight;
        bud1.energyWeight428 = Math.max(1e-4, w1) as Float32;
    }

    const v32 = v31 + Math.PI;
    const v21 = rng.randFloat() * 0.5 + 1.0;
    const v28 =
        rng.randFloat() * 0.1000000014901161 -
        0.05000000074505806 +
        v32;
    void v28;
    const v22 =
        rng.randFloat() * 0.1000000014901161 -
        0.05000000074505806 +
        v32;
    void v22;
    const bud2 = createBudChild(section, 0, v21, rng, {
        roll: -v32,
        lateralRoll4158Z: v22,
    });
    if (bud2) {
        section.spawnDelta480 = (section.spawnDelta480 + 1) >>> 0;
        const w2 =
            (rng.randFloat() * 0.800000011920929 + 0.2000000029802322) *
            baseWeight;
        bud2.energyWeight428 = Math.max(1e-4, w2) as Float32;
    }
}

/**
 * sub_418660: simplified branch growth (used from sub_417FF0 when no children).
 */
function simplifiedBranchSub418660(
    section: TreeSection,
    rng: MSVCRand,
): void {
    const minE = GrowthConstants.FLT_4D862C as number;
    const budget = section.energyBudget432 as number;

    const v11 = rng.randFloat() * (Math.PI * 2) - Math.PI;
    const v7 = rng.randFloat() * 0.300000011920929;
    const v8 =
        rng.randFloat() * 0.1000000014901161 -
        0.05000000074505806 +
        v11;

    const bud1 = createBudChild(section, 0, v7, rng, {
        roll: -v11,
        lateralRoll4158Z: v8,
    });
    if (!bud1) return;

    section.spawnDelta480 = (section.spawnDelta480 + 1) >>> 0;

    const v17 = v7 / 0.300000011920929;
    if (minE < budget && rng.randFloat() < 0.2) {
        const v12 = v11 + Math.PI;
        const v9 = rng.randFloat() * 0.8999999463558197 + 0.4000000059604645;
        const v10 =
            rng.randFloat() * 0.1000000014901161 -
            0.05000000074505806 +
            v12;

        const bud2 = createBudChild(section, 0, v9, rng, {
            roll: -v12,
            lateralRoll4158Z: v10,
        });
        if (bud2) {
            section.spawnDelta480 = (section.spawnDelta480 + 1) >>> 0;
            const w428 =
                (rng.randFloat() * 0.1000000238418579 + 0.8999999761581421) *
                v17;
            bud2.energyWeight428 = w428 as Float32;
        }
    }
}

type CreateBudChildOpts = {
    roll?: number;
    branchPosition?: number;
    lateralTransY4158?: number;
    lateralRoll4158Z?: number;
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
    const bud = new TreeSection(parent, parent.level + 1, rng, 0.01);
    sub413F50InitSection(
        bud,
        parent,
        parent.localTemplate240,
        [yaw, pitch, opts.roll ?? 0],
    );
    bud.sectionRuntimeType4 = SectionRuntimeType.TreeSectionBud;
    bud.twigRadius444 = 0.01 as Float32;
    bud.twigLength448 = 0 as Float32;
    bud.energyWeight428 = 1.0 as Float32;
    bud.sub414CE0SeedBudget428 = 1.0 as Float32;
    bud.growthFlag512 = true;

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

    sub413F50AttachChild(parent, bud);
    bud.updateAttachmentPosition(parent);
    return bud;
}
