import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { GrowthConstants, byte4D8226ForSectionType } from "../config/GrowthConstants";
import { Float32 } from "../math/MathTypes";
import { TransformService } from "../math/TransformService";
import { sub4084F0NormalizeInPlaceReturnLen } from "../math/Vec3Sub40xPrimitives";
import { SectionRuntimeType } from "../SectionRuntimeType";

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
const _tmpVec = new THREE.Vector3();
const _tmpVec2 = new THREE.Vector3();
const _tmpAxis = new THREE.Vector3();
const _tmpQuat = new THREE.Quaternion();
const _tmpNorm3 = new THREE.Matrix3();
const _centNorm = new THREE.Vector3();
const _parentWorldQuat = new THREE.Quaternion();
const _worldQuat = new THREE.Quaternion();
const _yUp = new THREE.Vector3(0, 1, 0);
const _alignLight = new THREE.Quaternion();

/**
 * Entry point: call once per frame on the root section.
 * Mirrors sub_4143E0 recursive call pattern.
 */
export type PerFramePhysicsOptions = {
    /** false в strict-exe режиме: в C в sub_4143E0 нет блока «twig → свет» */
    twigPhototropismApprox?: boolean;
};

export function perFramePhysicsSub4143E0(
    root: TreeSection,
    wind: THREE.Vector3,
    options?: PerFramePhysicsOptions,
): void {
    walkPhysics(root, wind, options);
}

function walkPhysics(
    section: TreeSection,
    wind: THREE.Vector3,
    options?: PerFramePhysicsOptions,
): void {
    if (section.worldDetached188) return;

    // Step 1: recurse children first
    for (const child of section.children) {
        walkPhysics(child, wind, options);
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

    // В sub_4143E0.c отдельного блока «twig → свет» нет; ориентация twig — sub_416510 / слот +36.
    // APPROX(original): мягкий разворот targetRotation к prevDirectionVec (после smoothLightDirections).
    if (options?.twigPhototropismApprox !== false) {
        applyTwigLightSeeking(section);
    }

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

    // sub_414870.c: центр одной секции — середина «палки» вдоль оси роста.
    // В C половина +448 кладётся в +476 (3-я компонента, ось роста в exe); у нас сегмент — +Y (GeometryService).
    section.centroid468.set(0, (section.twigLength448 as number) * 0.5, 0);

    if (section.children.length > 0) {
        section.centroid468.multiplyScalar(section.totalWeight460);

        for (const child of section.children) {
            _tmpVec.copy(child.centroid468);
            // sub_4085B0: D3DXVec3TransformCoord(child+468, out, child+40) — полная локальная матрица ребёнка
            _tmpVec.applyMatrix4(child.group.matrix);
            _tmpVec.multiplyScalar(child.totalWeight460);
            section.centroid468.add(_tmpVec);
            section.totalWeight460 += child.totalWeight460;
        }

        if (section.totalWeight460 > 0) {
            section.centroid468.multiplyScalar(1.0 / section.totalWeight460);
        }
    }
}

/**
 * sub_4084F0.c — нормализация; при |v|≈0 → (0,0,1); возвращает исходную длину (или 0).
 */
function sub4084F0NormalizeReturnLen(v: THREE.Vector3): number {
    return sub4084F0NormalizeInPlaceReturnLen(v);
}

// ─── sub_414A70: wind/gravity torque → targetQuat (+320) ─────────────

function applyWindTorqueSub414A70(section: TreeSection, _wind: THREE.Vector3): void {
    _centNorm.copy(section.centroid468);
    const centroidLen = sub4084F0NormalizeReturnLen(_centNorm);
    if (centroidLen < 1e-10) return;

    // sub_401540(&dword_4D5314, out, this+352): D3DXVec3TransformNormal; +352 = inverse(world)
    _tmpNorm3.getNormalMatrix(section.transformMatrix);

    // sub_414A70.c: sub_401540(&dword_4D5314, …, +352) — только гравитация INI, без ветра в этом сабе.
    // Ветер сцены остаётся в TreeSection.update (sway) и в лучах sub_40E460.
    _tmpVec.copy(GRAVITY_DIRECTION);
    _tmpVec.applyNormalMatrix(_tmpNorm3);
    if (_tmpVec.lengthSq() < 1e-10) return;
    _tmpVec.normalize();

    // sub_414A70.c: sub_401120(out, gravity_local, centroid_norm) → result = -(gL × cN) = cN × gL
    _tmpAxis.crossVectors(_centNorm, _tmpVec);
    if (_tmpAxis.lengthSq() < 1e-10) return;
    _tmpAxis.normalize();

    const dot = Math.max(-1, Math.min(1, _centNorm.dot(_tmpVec)));
    const angle = Math.acos(dot);
    if (!isFinite(angle)) return;

    _tmpQuat.setFromAxisAngle(_tmpAxis, angle);

    const accelPow = GrowthConstants.FLT_4D8600 as number;
    const gScale = GrowthConstants.FLT_4D5310 as number;
    const radius = Math.max(0.001, section.twigRadius444 as number);
    let factor =
        Math.abs(Math.sin(angle))
        * (section.totalWeight460 as number)
        * centroidLen
        * Math.pow(radius, accelPow)
        * gScale;
    if (factor > 1.0) factor = 1.0; // sub_414A70.c

    section.targetRotation.slerp(_tmpQuat, factor);
    section.targetRotation.normalize();
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
    // sub_4143E0.c:57-68 — dot(+196..+204, +216..+224), v10/v11/v12, sub_401500 scale + sub_4013F0 add + sub_40CF00
    const lx = section.lightResponseVec.x;
    const ly = section.lightResponseVec.y;
    const lz = section.lightResponseVec.z;
    const px = section.prevDirectionVec.x;
    const py = section.prevDirectionVec.y;
    const pz = section.prevDirectionVec.z;
    const v9 = lx * px + ly * py + lz * pz;
    const v10 = (v9 + 1.0) * 0.5;
    const v11 = v10 * 0.10000000149011612;
    const v12 = 1.0 - v11;
    _tmpVec.set(px * v12 + lx * v11, py * v12 + ly * v11, pz * v12 + lz * v11);
    const lenSq = _tmpVec.x * _tmpVec.x + _tmpVec.y * _tmpVec.y + _tmpVec.z * _tmpVec.z;
    if (lenSq <= 1.000000013351432e-10) {
        section.prevDirectionVec.set(0, 0, 1);
    } else {
        const inv = 1 / Math.sqrt(lenSq);
        section.prevDirectionVec.set(_tmpVec.x * inv, _tmpVec.y * inv, _tmpVec.z * inv);
    }
}

/**
 * Локально поворачивает targetRotation ветки так, чтобы ось +Y приближалась к prevDirectionVec (мир).
 * Вызывается после smoothLightDirections; сила от smoothedLightA (sub_40E460).
 *
 * Мировая ориентация до догонки +320 в sub_417C90 = parentWorld · rotationQuaternion (+304), не · targetRotation.
 * Смешение «факт родителя» с «цель ребёнка» давало неверный локальный вектор света → вечное кручение и рывки.
 */
function applyTwigLightSeeking(section: TreeSection): void {
    if (section.sectionRuntimeType4 !== SectionRuntimeType.TreeSectionTwig) return;
    const w = section.smoothedLightA as number;
    if (w < 0.08 || section.prevDirectionVec.lengthSq() < 1e-10) return;

    if (section.parent) {
        section.parent.group.getWorldQuaternion(_parentWorldQuat);
    } else {
        _parentWorldQuat.identity();
    }
    _worldQuat.copy(_parentWorldQuat).multiply(section.rotationQuaternion);
    _tmpQuat.copy(_worldQuat).invert();
    _tmpVec.copy(section.prevDirectionVec).applyQuaternion(_tmpQuat);
    _tmpVec.normalize();
    if (_tmpVec.lengthSq() < 1e-10) return;

    _alignLight.setFromUnitVectors(_yUp, _tmpVec);
    // APPROX: меньший шаг — меньше дрожания от шума лучей после исправления кадра
    const t = Math.min(0.018, 0.008 + 0.014 * Math.min(1, w));
    section.targetRotation.slerp(_alignLight, t);
    section.targetRotation.normalize();
}
