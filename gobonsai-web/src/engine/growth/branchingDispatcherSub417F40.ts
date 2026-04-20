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
import { readUnifiedBudget428, writeUnifiedBudget428 } from "./sub414CE0";
import {
    growthDebugEnabled,
    growthDebugLog,
    growthDebugSectionLabel,
    growthDebugStructuralChildCount,
} from "./growthDebug";
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
const _tmpRot4158D0 = new THREE.Matrix4();
const _tmpTrans4158D0 = new THREE.Matrix4();
const _tmpOut4158D0 = new THREE.Matrix4();
const _tmpYpr417FF0 = new THREE.Matrix4();
const _tmpSub4158D0_417FF0 = new THREE.Matrix4();
const _tmpComposite417FF0 = new THREE.Matrix4();
const _tmpParentComposite417FF0 = new THREE.Matrix4();
const _tmpQuat417FF0 = new THREE.Quaternion();
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
        (section.branchBirthSimulationDay as number) / 365.0;
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
    if (growthDebugEnabled() && section.isContinuation) {
        growthDebugLog("branching_gate", {
            section: growthDebugSectionLabel(section),
            years,
            growthFlag512: section.growthFlag512,
            radius444: Number((section.twigRadius444 as number).toFixed(5)),
            length448: Number((section.twigLength448 as number).toFixed(5)),
            budget432: Number((section.energyBudget432 as number).toFixed(5)),
            spent436: Number((section.energySpent436 as number).toFixed(5)),
            structuralChildren: growthDebugStructuralChildCount(section),
            allChildren: section.children.length,
            childTypes: section.children.map((child) => child.sectionRuntimeType4),
            birthDay: Number((section.branchBirthSimulationDay as number).toFixed(2)),
            worldDay: Number(getSlot36SimulationDay().toFixed(2)),
            rollup484: section.rollupDword484 >>> 0,
        });
    }
    // Apical continuation must not stall for a full simulation year after the
    // previous segment finishes length growth. That year gate is valid for
    // older/lateral branching behavior, but for the active continuation chain
    // it freezes the trunk exactly at the point where the next segment should
    // be spawned.
    if (years < 1 && !section.isContinuation) return;

    if (years > 3 && (section.twigRadius444 as number) > 0.2) {
        lateralBranchSub4188E0(section, rng);
        return;
    }

    const structuralChildren = section.children.filter(
        (child) => child.sectionRuntimeType4 !== SectionRuntimeType.TreeSectionLeaf,
    );
    const childCount = structuralChildren.length;
    if (childCount > 1) return;

    if (childCount === 0) {
        apicalBranchSub417FF0(section, rng);
        return;
    }

    const firstTwig = sub416300Filter(structuralChildren[0] ?? null);
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
    const v22 = (section.twigRadius444 as number) * 0.8500000238418579;
    // C order in sub_4188E0:
    //   1) rand -> v15
    //   2) rand -> v19
    //   operator new
    //   3) rand -> v20 (roll jitter around v15)
    //   4) rand -> v11 (branchPosition / translateZ for sub_4158D0)
    const v20 =
        rng.randFloat() * 0.1000000014901161 -
        0.05000000074505806 +
        v15;
    const v11 = rng.randFloat();

    const bud = createBudChild(section, 0, v19, rng, {
        localTemplate240: buildLocalTemplateSub4158D0(v11, v22, -v15),
        preserveExactLocalTemplateAttachment240: true,
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
        sumWeights += readUnifiedBudget428(c);
    }

    let v24 = 1.0;
    const budget = section.energyBudget432 as number;
    if (sumWeights > 0 && budget > 1e-8) {
        const v25 = spentDelta / budget;
        if (v25 > 0 && v25 < 1) {
            v24 = (sumWeights * v25) / (1.0 - v25);
        }
    }

    writeUnifiedBudget428(bud, v24);
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

    const structuralChildren = section.children.filter(
        (child) => child.sectionRuntimeType4 !== SectionRuntimeType.TreeSectionLeaf,
    );
    const childCount = structuralChildren.length >>> 0;
    let oldChildWeight428 =
        childCount === 1 ? readUnifiedBudget428(structuralChildren[0]) : 0.0;
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
    if (growthDebugEnabled() && section.isContinuation) {
        growthDebugLog("apical_dispatch", {
            section: growthDebugSectionLabel(section),
            childCount,
            allChildren: section.children.length,
            available: Number(available.toFixed(5)),
            apicalStrength: apicalStr,
            v33: Number(v33.toFixed(5)),
            spendAttempt: Number(v17.toFixed(5)),
            oldChildWeight428: Number(oldChildWeight428.toFixed(5)),
        });
    }
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
        localTemplate240: buildApicalExistingChildTemplateSub417FF0(
            section,
            v25,
            -v31,
            v19,
        ),
        preserveExactLocalTemplateAttachment240: true,
        suppressAttachmentRuntimeFields: true,
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
        const weight = Math.max(1e-4, w1);
        writeUnifiedBudget428(bud1, weight);
        bud1.energyAccumulator424 = weight as Float32;
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
        localTemplate240: buildApicalExistingChildTemplateSub417FF0(
            section,
            v21,
            -v32,
            v22,
        ),
        preserveExactLocalTemplateAttachment240: true,
        suppressAttachmentRuntimeFields: true,
        roll: -v32,
        lateralRoll4158Z: v22,
    });
    if (bud2) {
        section.spawnDelta480 = (section.spawnDelta480 + 1) >>> 0;
        const w2 =
            (rng.randFloat() * 0.800000011920929 + 0.2000000029802322) *
            baseWeight;
        const weight = Math.max(1e-4, w2);
        writeUnifiedBudget428(bud2, weight);
        bud2.energyAccumulator424 = weight as Float32;
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
        localTemplate240: buildLocalTemplateSub4158D0(v7, 1.0, -v11),
        preserveExactLocalTemplateAttachment240: true,
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
            localTemplate240: buildLocalTemplateSub4158D0(v9, 1.0, -v12),
            preserveExactLocalTemplateAttachment240: true,
            roll: -v12,
            lateralRoll4158Z: v10,
        });
        if (bud2) {
            section.spawnDelta480 = (section.spawnDelta480 + 1) >>> 0;
            const w428 =
                (rng.randFloat() * 0.1000000238418579 + 0.8999999761581421) *
                v17;
            writeUnifiedBudget428(bud2, w428);
            bud2.energyAccumulator424 = w428 as Float32;
        }
    }
}

type CreateBudChildOpts = {
    roll?: number;
    branchPosition?: number;
    lateralTransY4158?: number;
    lateralRoll4158Z?: number;
    maxGrowth452?: number;
    localTemplate240?: THREE.Matrix4;
    preserveExactLocalTemplateAttachment240?: boolean;
    suppressAttachmentRuntimeFields?: boolean;
};

function buildLocalTemplateSub4158D0(
    translateY: number,
    translateZ: number,
    rollZ: number,
): THREE.Matrix4 {
    _tmpTrans4158D0.makeTranslation(0, translateY, translateZ);
    _tmpRot4158D0.makeRotationZ(rollZ);
    return _tmpOut4158D0.multiplyMatrices(_tmpTrans4158D0, _tmpRot4158D0).clone();
}

function buildApicalExistingChildTemplateSub417FF0(
    parent: TreeSection,
    pitch: number,
    roll: number,
    sub4158d0Roll: number,
): THREE.Matrix4 {
    _tmpSub4158D0_417FF0.copy(buildLocalTemplateSub4158D0(0.0, 1.0, sub4158d0Roll));
    _tmpQuat417FF0.setFromEuler(new THREE.Euler(pitch, 0.0, roll, "YXZ"));
    _tmpYpr417FF0.makeRotationFromQuaternion(_tmpQuat417FF0);
    _tmpComposite417FF0.multiplyMatrices(_tmpYpr417FF0, _tmpSub4158D0_417FF0);
    return _tmpParentComposite417FF0
        .multiplyMatrices(_tmpComposite417FF0, parent.localTemplate240)
        .clone();
}

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
        opts.localTemplate240 ?? parent.localTemplate240,
        [yaw, pitch, opts.roll ?? 0],
    );
    bud.sectionRuntimeType4 = SectionRuntimeType.TreeSectionBud;
    bud.twigRadius444 = 0.01 as Float32;
    bud.twigLength448 = 0 as Float32;
    bud.mesh.visible = false;
    writeUnifiedBudget428(bud, 1.0);
    bud.energyAccumulator424 = 1.0 as Float32;
    bud.growthFlag512 = true;
    bud.useExactLocalTemplateAttachment240 =
        opts.preserveExactLocalTemplateAttachment240 === true;

    if (!opts.suppressAttachmentRuntimeFields && opts.branchPosition !== undefined) {
        bud.branchPosition = opts.branchPosition as Float32;
    }
    if (!opts.suppressAttachmentRuntimeFields && opts.lateralTransY4158 !== undefined) {
        bud.lateralTransY4158 = opts.lateralTransY4158 as Float32;
    }
    if (!opts.suppressAttachmentRuntimeFields && opts.lateralRoll4158Z !== undefined) {
        bud.lateralRoll4158Z = opts.lateralRoll4158Z as Float32;
    }
    bud.maxGrowth =
        opts.maxGrowth452 !== undefined
            ? (opts.maxGrowth452 as Float32)
            : sampleMaxGrowth452Sub4159C0(rng);

    sub413F50AttachChild(parent, bud);
    bud.updateAttachmentPosition(parent);
    if (growthDebugEnabled()) {
        growthDebugLog("bud_create", {
            parent: growthDebugSectionLabel(parent),
            bud: growthDebugSectionLabel(bud),
            yaw,
            pitch,
            roll: opts.roll ?? 0,
            branchPosition: bud.branchPosition,
            lateralTransY4158: bud.lateralTransY4158,
            lateralRoll4158Z: bud.lateralRoll4158Z,
            maxGrowth452: Number((bud.maxGrowth as number).toFixed(5)),
            birthDay: Number((bud.branchBirthSimulationDay as number).toFixed(2)),
            exactTemplate: bud.useExactLocalTemplateAttachment240,
            structuralChildrenParent: growthDebugStructuralChildCount(parent),
            allChildrenParent: parent.children.length,
        });
    }
    return bud;
}
