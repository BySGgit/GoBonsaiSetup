import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { GrowthConstants } from "../config/GrowthConstants";
import { Float32 } from "../math/MathTypes";
import { TransformService } from "../math/TransformService";
import { sub4084F0NormalizeInPlaceReturnLen } from "../math/Vec3Sub40xPrimitives";
import { growthDebugEnabled, growthDebugLog, growthDebugSectionLabel } from "./growthDebug";

/**
 * sub_418BD0.c - twig length growth (called when growthFlag512 == true).
 *
 * Formula: twigLength448 += pow(clamp01((spent-minE)/(maxE-minE)), pow_) * rate
 * When twigLength448 >= maxGrowth (this+452): clamp and clear growthFlag512 -> branching.
 *
 * Also slerps the twig orientation toward light direction.
 */

const _tmpVec = new THREE.Vector3();
const _tmpAxis = new THREE.Vector3();
const _upVec = new THREE.Vector3(0, 1, 0);
const _tmpQuat = new THREE.Quaternion();
const _tmpInv418BD0 = new THREE.Matrix4();
const _tmpM3FromInv418BD0 = new THREE.Matrix3();

export function twigLengthGrowthSub418BD0(
    section: TreeSection,
    _rng: MSVCRand | undefined,
): void {
    slerpTowardLight(section);

    const budget = section.energyBudget432 as number;
    const cap = GrowthConstants.FLT_4D8630 as number;
    section.energySpent436 = Math.min(cap, budget) as Float32;

    const minE = GrowthConstants.FLT_4D862C as number;
    let v6 = ((section.energySpent436 as number) - minE) / (cap - minE);
    v6 = Math.max(0, Math.min(1, v6));

    const powExp = GrowthConstants.FLT_4D8640 as number;
    const rate = GrowthConstants.FLT_4D8614 as number;
    const increment = Math.pow(v6, powExp) * rate;
    section.twigLength448 = ((section.twigLength448 as number) + increment) as Float32;

    if (growthDebugEnabled() && section.isContinuation) {
        growthDebugLog("length_growth", {
            section: growthDebugSectionLabel(section),
            budget432: Number((section.energyBudget432 as number).toFixed(5)),
            spent436: Number((section.energySpent436 as number).toFixed(5)),
            minE: Number(minE.toFixed(5)),
            cap: Number(cap.toFixed(5)),
            normalized: Number(v6.toFixed(5)),
            powExp: Number(powExp.toFixed(5)),
            rate: Number(rate.toFixed(5)),
            increment: Number(increment.toFixed(5)),
            length448: Number((section.twigLength448 as number).toFixed(5)),
            maxGrowth: Number((section.maxGrowth as number).toFixed(5)),
            growthFlag512BeforeClamp: section.growthFlag512,
        });
    }

    if ((section.twigLength448 as number) >= (section.maxGrowth as number)) {
        section.twigLength448 = section.maxGrowth;
        section.growthFlag512 = false;
        if (growthDebugEnabled() && section.isContinuation) {
            growthDebugLog("length_growth_clamp", {
                section: growthDebugSectionLabel(section),
                length448: Number((section.twigLength448 as number).toFixed(5)),
                maxGrowth: Number((section.maxGrowth as number).toFixed(5)),
                energyTickCounter440: Number((section.energyTickCounter440 as number).toFixed(5)),
                rollup484: section.rollupDword484 >>> 0,
            });
        }
    }
}

function slerpTowardLight(section: TreeSection): void {
    const slerpFactor = GrowthConstants.FLT_4D8610 as number;
    if (slerpFactor <= 0) return;

    _tmpInv418BD0.copy(section.transformMatrix);
    _tmpM3FromInv418BD0.setFromMatrix4(_tmpInv418BD0);
    _tmpVec.copy(section.lightResponseVec).applyMatrix3(_tmpM3FromInv418BD0);
    if (sub4084F0NormalizeInPlaceReturnLen(_tmpVec) <= 0) return;

    _tmpAxis.crossVectors(_upVec, _tmpVec);
    if (sub4084F0NormalizeInPlaceReturnLen(_tmpAxis) <= 0) return;

    const dot = Math.max(-1, Math.min(1, _upVec.dot(_tmpVec)));
    const angle = Math.acos(dot);

    TransformService.rotationAxis(_tmpQuat, _tmpAxis, angle);
    TransformService.slerp(
        section.rotationQuaternion,
        section.rotationQuaternion,
        _tmpQuat,
        slerpFactor as Float32,
    );
    section.rotationQuaternion.normalize();
}
