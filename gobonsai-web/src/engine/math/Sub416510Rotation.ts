import * as THREE from 'three';
import { TreeSection } from '../TreeSection';
import { GrowthConstants } from '../config/GrowthConstants';
import { TransformService } from './TransformService';

const _u = new THREE.Vector3();
const _v44 = new THREE.Vector3();
const _v51 = new THREE.Vector3();
const _w = new THREE.Vector3();
const _q42 = new THREE.Quaternion();
const _q38 = new THREE.Quaternion();
const _qCombined = new THREE.Quaternion();
const _matRy = new THREE.Matrix4();
const _f32 = new Float32Array(4);
const _u32 = new Uint32Array(_f32.buffer);

/** sub_416510.c:238-241, 255-256 */
const ANGLE_MIN = 0.30000001;
const ANGLE_MAX = 2.6500001;
/** sub_416510.c:253-262, full.c flt_4D6388 */
const V26_NEG = -1.5707964;
const V26_POS_CMP = 1.570796370506287;
const V26_CLAMP_HI = 1.5707964;

/**
 * sub_4010C0.c — acos(dot(a,b)) с зажатием dot в [-1,1].
 */
function sub4010C0(a: THREE.Vector3, b: THREE.Vector3): number {
    let d = a.x * b.x + a.y * b.y + a.z * b.z;
    if (d > 1.0) d = 1.0;
    else if (d < -1.0) d = -1.0;
    return Math.acos(d);
}

/**
 * Блок вращения из sub_416510.c (~226–273): цель — итог как в оригинале (ориентация секций),
 * а не построчное совпадение с декомпилом. Ниже — соответствие по шагам C для справки.
 * v44: в C v49/v50 не заданы — здесь геометрическая замена (YZ ⟂ U).
 * 274–282: prevData — снимок blob80 в начале кадра.
 */
export class Sub416510Rotation {
    public static apply(section: TreeSection, _trunkBend: number, _v34: number, deltaTime: number): void {
        Sub416510Rotation.snapshotPrevDataFromBlob80(section);

        // Gently slerp current orientation toward targetRotation.
        // targetRotation is set by growth (branching angles, light response, physics).
        // This replaces the broken sub_416510 rotation block that incorrectly used
        // direction vector components as Euler angles (causing 57° per-frame tilt).
        // TODO(original): fully reconstruct sub_416510.c:226-273 with correct semantics.
        const simTicks = Math.min(2, deltaTime * 60);
        const t = Math.min(1, GrowthConstants.FLT_4D63C0 * simTicks) as number;

        TransformService.slerp(
            section.rotationQuaternion,
            section.rotationQuaternion,
            section.targetRotation,
            t,
        );
        section.rotation.copy(section.rotationQuaternion);

        Sub416510Rotation.storeQuatToBlob80(section);
    }

    /** DWORD +76..+79 ← предыдущее +80..+83 (снимок в начале apply). */
    public static snapshotPrevDataFromBlob80(section: TreeSection): void {
        section.prevData0 = section.quaternionBlob80u0 >>> 0;
        section.prevData1 = section.quaternionBlob80u1 >>> 0;
        section.prevData2 = section.quaternionBlob80u2 >>> 0;
        section.prevData3 = section.quaternionBlob80u3 >>> 0;
    }

    public static storeQuatToBlob80(section: TreeSection): void {
        _f32[0] = section.rotationQuaternion.x;
        _f32[1] = section.rotationQuaternion.y;
        _f32[2] = section.rotationQuaternion.z;
        _f32[3] = section.rotationQuaternion.w;
        section.quaternionBlob80u0 = _u32[0] >>> 0;
        section.quaternionBlob80u1 = _u32[1] >>> 0;
        section.quaternionBlob80u2 = _u32[2] >>> 0;
        section.quaternionBlob80u3 = _u32[3] >>> 0;
    }

    public static initBlob80Identity(section: TreeSection): void {
        _f32[0] = 0;
        _f32[1] = 0;
        _f32[2] = 0;
        _f32[3] = 1;
        section.quaternionBlob80u0 = _u32[0] >>> 0;
        section.quaternionBlob80u1 = _u32[1] >>> 0;
        section.quaternionBlob80u2 = _u32[2] >>> 0;
        section.quaternionBlob80u3 = _u32[3] >>> 0;
    }

    public static syncBlob80FromQuaternion(section: TreeSection): void {
        Sub416510Rotation.storeQuatToBlob80(section);
    }
}
