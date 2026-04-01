import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { GrowthConstants } from "../config/GrowthConstants";
import { Float32 } from "../math/MathTypes";
import { TransformService } from "../math/TransformService";

/**
 * sub_418BD0.c — twig length growth (called when growthFlag512 == true).
 *
 * Formula: twigLength448 += pow(clamp01((spent-minE)/(maxE-minE)), pow_) * rate
 * When twigLength448 >= maxGrowth (this+452): clamp and clear growthFlag512 → branching.
 *
 * Also slerps the twig orientation toward light direction.
 */

const _tmpVec = new THREE.Vector3();
const _tmpAxis = new THREE.Vector3();
const _upVec = new THREE.Vector3(0, 1, 0);
const _tmpQuat = new THREE.Quaternion();

export function twigLengthGrowthSub418BD0(
    section: TreeSection,
    _rng: MSVCRand | undefined,
): void {
    // §1: slerp orientation toward light-response direction
    slerpTowardLight(section);

    // §2: energySpent436 = min(maxBudEnergy, budget)
    const budget = section.energyBudget432 as number;
    const cap = GrowthConstants.FLT_4D8630 as number;
    section.energySpent436 = Math.min(cap, budget) as Float32;

    // §3: normalize energy
    const minE = GrowthConstants.FLT_4D862C as number;
    let v6 = ((section.energySpent436 as number) - minE) / (cap - minE);
    v6 = Math.max(0, Math.min(1, v6));

    // §4: pow + length increment
    const powExp = GrowthConstants.FLT_4D8640 as number;
    const rate = GrowthConstants.FLT_4D8614 as number;
    const increment = Math.pow(v6, powExp) * rate;
    section.twigLength448 = ((section.twigLength448 as number) + increment) as Float32;

    // §5: cap length → stop growing, start branching
    if ((section.twigLength448 as number) >= (section.maxGrowth as number)) {
        section.twigLength448 = section.maxGrowth;
        section.growthFlag512 = false;
    }
}

/**
 * sub_418BD0 step 1: slerp current quaternion toward light-response direction.
 * v_local = transformNormal(lightResponse+196, inverseWorld+352)
 * cross(up, v_local) → axis, acos(dot(up, norm(v_local))) → angle
 * target quat from axis+angle, slerp currentQuat toward it.
 */
function slerpTowardLight(section: TreeSection): void {
    const slerpFactor = GrowthConstants.FLT_4D8610 as number;
    if (slerpFactor <= 0) return;

    // sub_418BD0.c: sub_401540(+196, …, +352) — локальный вектор из lightResponse (+196), не глобальный свет.
    const worldInverse = new THREE.Matrix4().copy(section.group.matrixWorld).invert();
    _tmpVec.copy(section.lightResponseVec).applyMatrix4(worldInverse).normalize();

    if (_tmpVec.lengthSq() < 1e-10) return;

    _tmpAxis.crossVectors(_upVec, _tmpVec);
    if (_tmpAxis.lengthSq() < 1e-10) return;
    _tmpAxis.normalize();

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
