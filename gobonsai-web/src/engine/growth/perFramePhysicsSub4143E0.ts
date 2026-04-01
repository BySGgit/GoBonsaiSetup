import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { GrowthConstants, byte4D8226ForSectionType } from "../config/GrowthConstants";
import { Float32 } from "../math/MathTypes";
import { TransformService } from "../math/TransformService";

/**
 * sub_4143E0 — per-frame physics/smoothing (vtable slot +12).
 *
 * For each section (recursive):
 * 1. Recurse into children
 * 2. Compute centroid + totalWeight (sub_414870)
 * 3. If resistance enabled and has children and weight > threshold:
 *    - Apply wind/gravity torque (sub_414A70) if has parent
 *    - Apply resistance damping (sub_414BB0)
 * 4. Smooth light direction vectors (+216..+232)
 */

const PHYSICS_ENABLED = true;                    // byte_4D6356
const PHYSICS_WEIGHT_THRESHOLD = 0.001;          // flt_4D6358
const GRAVITY_DIRECTION = new THREE.Vector3(0, -1, 0);
const GRAVITY_LENGTH = 1.0;                      // flt_4D5310

const _tmpVec = new THREE.Vector3();
const _tmpVec2 = new THREE.Vector3();
const _tmpAxis = new THREE.Vector3();
const _tmpQuat = new THREE.Quaternion();
const _tmpMat = new THREE.Matrix4();

/**
 * Entry point: call once per frame on the root section.
 * Mirrors sub_4143E0 recursive call pattern.
 */
export function perFramePhysicsSub4143E0(
    root: TreeSection,
    wind: THREE.Vector3,
): void {
    walkPhysics(root, wind);
}

function walkPhysics(section: TreeSection, wind: THREE.Vector3): void {
    if (section.worldDetached188) return;

    // Step 1: recurse children first
    for (const child of section.children) {
        walkPhysics(child, wind);
    }

    // Step 2: compute centroid + totalWeight (sub_414870)
    computeCentroidSub414870(section);

    // Step 3: optional wind/resistance physics
    if (PHYSICS_ENABLED
        && section.children.length > 0
        && section.totalWeight460 > PHYSICS_WEIGHT_THRESHOLD) {
        if (section.parent) {
            applyWindTorqueSub414A70(section, wind);
        }
        applyResistanceSub414BB0(section);
    }

    // Step 5: smooth light direction vectors
    smoothLightDirections(section);

    // Step 6: exponential smoothing of accumulators
    section.smoothTargetA = ((section.smoothTargetA as number)
        + ((section.smoothedLightA as number) - (section.smoothTargetA as number)) * 0.1) as Float32;
    section.smoothTargetB = ((section.smoothTargetB as number)
        + ((section.smoothedLightB as number) - (section.smoothTargetB as number)) * 0.1) as Float32;
}

// ─── sub_414870: centroid + totalWeight ─────────────────────────────

function vtableSlot56GrowthScore(section: TreeSection): number {
    const r = section.twigRadius444 as number;
    const l = section.twigLength448 as number;
    return r * r * l;
}

function computeCentroidSub414870(section: TreeSection): void {
    const weightCoeff = GrowthConstants.FLT_4D85FC as number;
    const mass = vtableSlot56GrowthScore(section) * weightCoeff;
    section.storedMass464 = mass;
    section.totalWeight460 = mass;

    if (byte4D8226ForSectionType(section.sectionRuntimeType4)) {
        section.storedMass464 = 0;
        section.totalWeight460 = 0;
    }

    section.centroid468.set(0, 0, (section.twigLength448 as number) * 0.5);

    if (section.children.length > 0) {
        section.centroid468.multiplyScalar(section.totalWeight460);

        for (const child of section.children) {
            _tmpVec.copy(child.centroid468);
            // Transform child centroid by child's local position/rotation
            _tmpVec.applyQuaternion(child.rotationQuaternion);
            _tmpVec.y += (child.twigLength448 as number) * (child.branchPosition as number);
            _tmpVec.multiplyScalar(child.totalWeight460);
            section.centroid468.add(_tmpVec);
            section.totalWeight460 += child.totalWeight460;
        }

        if (section.totalWeight460 > 0) {
            section.centroid468.multiplyScalar(1.0 / section.totalWeight460);
        }
    }
}

// ─── sub_414A70: wind/gravity torque → targetQuat ───────────────────

function applyWindTorqueSub414A70(section: TreeSection, wind: THREE.Vector3): void {
    const centroidLen = section.centroid468.length();
    if (centroidLen < 1e-6) return;

    // Gravity + wind in local space via inverse world
    const det = section.group.matrixWorld.determinant();
    if (Math.abs(det) < 1e-8) return;
    _tmpMat.copy(section.group.matrixWorld).invert();

    _tmpVec.copy(GRAVITY_DIRECTION).addScaledVector(wind, 0.1);
    _tmpVec.transformDirection(_tmpMat);
    if (_tmpVec.lengthSq() < 1e-10) return;
    _tmpVec.normalize();

    // Axis = cross(centroid, localGravity)
    _tmpAxis.crossVectors(section.centroid468, _tmpVec);
    if (_tmpAxis.lengthSq() < 1e-10) return;
    _tmpAxis.normalize();

    // Angle between centroid and gravity direction
    _tmpVec2.copy(section.centroid468).normalize();
    const dot = Math.max(-1, Math.min(1, _tmpVec2.dot(_tmpVec)));
    const angle = Math.acos(dot);
    if (!isFinite(angle)) return;

    _tmpQuat.setFromAxisAngle(_tmpAxis, angle);

    // Weight factor — clamped conservatively
    const accelPow = GrowthConstants.FLT_4D8600 as number;
    const radius = Math.max(0.001, section.twigRadius444 as number);
    let factor = Math.abs(Math.sin(angle)) * section.totalWeight460 * centroidLen;
    factor *= Math.pow(radius, accelPow);
    factor *= GRAVITY_LENGTH;
    factor = Math.max(0, Math.min(0.15, factor));

    section.targetRotation.slerp(_tmpQuat, factor);
}

// ─── sub_414BB0: resistance damping ─────────────────────────────────

function applyResistanceSub414BB0(section: TreeSection): void {
    const bias = GrowthConstants.FLT_4D635C as number;
    const resPow = GrowthConstants.FLT_4D8604 as number;
    const resCoeff = GrowthConstants.FLT_4D8608 as number;

    let r = (section.twigRadius444 as number) + bias;
    r = Math.pow(Math.max(0, r), resPow);
    r *= resCoeff;
    r = Math.max(0, Math.min(1, r));

    // Slerp target back toward current → resistance
    section.targetRotation.slerp(section.rotationQuaternion, r);
}

// ─── Light direction smoothing (sub_4143E0 step 5–6) ───────────────

function smoothLightDirections(section: TreeSection): void {
    const dot = section.prevDirectionVec.dot(section.lightResponseVec);
    const v10 = (dot + 1.0) * 0.5;
    const t = v10 * 0.1;

    // Lerp prevDirection toward lightResponse
    section.prevDirectionVec.lerp(section.lightResponseVec, t);
    if (section.prevDirectionVec.lengthSq() > 1e-12) {
        section.prevDirectionVec.normalize();
    }
}
