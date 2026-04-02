import * as THREE from 'three';
import { TreeSection } from '../TreeSection';
import { GrowthConstants } from '../config/GrowthConstants';
import { SectionRuntimeType } from '../SectionRuntimeType';
import { TransformService } from './TransformService';

const _tFull = new THREE.Vector3();
const _normalMat352 = new THREE.Matrix3();
const _u = new THREE.Vector3();
const _upW = new THREE.Vector3();
const _cross = new THREE.Vector3();
const _axis = new THREE.Vector3();
const _t2 = new THREE.Vector3();
const _q42 = new THREE.Quaternion();
const _q38 = new THREE.Quaternion();
const _qComb = new THREE.Quaternion();
const _f32 = new Float32Array(4);
const _u32 = new Uint32Array(_f32.buffer);

/** sub_416510.c:238-241, 255-256 */
const ANGLE_MIN = 0.30000001;
const ANGLE_MAX = 2.6500001;
/** sub_416510.c:18199–18209 — сравнения с π/2 */
const V26_CMP_LO = -1.570796370506287;
const V26_CMP_HI = 1.570796370506287;
const V26_CLAMP_LO = -1.5707964;

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
 * sub_408470.c — нормализация; при |v|≈0 → (0,0,1).
 */
function sub408470Vec3(v: THREE.Vector3): void {
    const len = v.length();
    if (len <= 1.000000013351432e-10) {
        v.set(0, 0, 1);
    } else {
        v.multiplyScalar(1 / len);
    }
}

/**
 * sub_416510.c ~226–273 — вращение листа.
 * IDA: GUIDES/ida_extracted_truth_log.md § «разрешение HIDWORD(v44) / v49»; второй блок 0x416C20–0x416CF8.
 *
 * Первый шаг: `sub_401540(+196, …, this+352)`; +352 = `section.transformMatrix` (синк до метаболизма в GrowthFramePipeline).
 * В C после `D3DXQuaternionRotationAxis(v43,…)` идёт `D3DXQuaternionRotationYawPitchRoll(v38, n.x,n.y,n.z)`;
 * `D3DXQuaternionMultiply` использует только **q42·q38** (ось v43 в exe не участвует в multiply).
 */
export class Sub416510Rotation {
    public static apply(section: TreeSection, _trunkBend: number, _v34: number, deltaTime: number): void {
        Sub416510Rotation.snapshotPrevDataFromBlob80(section);

        if (section.sectionRuntimeType4 === SectionRuntimeType.TreeSectionTwig) {
            section.rotation.copy(section.rotationQuaternion);
            Sub416510Rotation.storeQuatToBlob80(section);
            return;
        }

        if (section.sectionRuntimeType4 === SectionRuntimeType.TreeSectionLeaf) {
            Sub416510Rotation.applyLeafRotationSub416510(section);
            section.rotation.copy(section.rotationQuaternion);
            Sub416510Rotation.storeQuatToBlob80(section);
            return;
        }

        const simTicks = Math.min(2, deltaTime * 60);
        const t = Math.min(1, (GrowthConstants.FLT_4D63C0 as number) * simTicks);

        TransformService.slerp(
            section.rotationQuaternion,
            section.rotationQuaternion,
            section.targetRotation,
            t,
        );
        section.rotation.copy(section.rotationQuaternion);

        Sub416510Rotation.storeQuatToBlob80(section);
    }

    /** sub_416510.c:18199–18209 (LABEL_49). */
    private static clampV26Sub416510(a: number): number {
        const hi = GrowthConstants.FLT_4D6388 as number;
        if (a < V26_CMP_LO) return V26_CLAMP_LO;
        if (a > V26_CMP_HI) return hi;
        return a;
    }

    /**
     * Полная цепочка до D3DXQuaternionSlerp(+320, +320, q42·q38, flt_4D63C0).
     */
    private static applyLeafRotationSub416510(section: TreeSection): void {
        _normalMat352.getNormalMatrix(section.transformMatrix);
        _tFull.copy(section.lightResponseVec).applyNormalMatrix(_normalMat352);

        _u.set(0, _tFull.y, _tFull.z);
        const uLen2 = _u.lengthSq();
        if (uLen2 < 1e-24) {
            return;
        }
        _u.multiplyScalar(1 / Math.sqrt(uLen2));

        _upW.copy(GrowthConstants.LIGHT_VECTOR);

        _cross.crossVectors(_u, _upW);
        _axis.set(_cross.x >= 0 ? 1 : -1, _cross.y, _cross.z);
        const axLen2 = _axis.lengthSq();
        if (axLen2 < 1e-24) {
            return;
        }
        _axis.multiplyScalar(1 / Math.sqrt(axLen2));

        const ang1 = Math.max(ANGLE_MIN, Math.min(ANGLE_MAX, sub4010C0(_upW, _u)));
        _q42.setFromAxisAngle(_axis, ang1);

        _t2.copy(_tFull);
        _t2.applyAxisAngle(_upW, -ang1);

        // full.c:18198–18209: v26 для мёртвого D3DXQuaternionRotationAxis(v43, n, v26); в multiply только q42·q38
        void Sub416510Rotation.clampV26Sub416510(sub4010C0(_upW, _t2));

        _cross.crossVectors(_t2, _upW);
        sub408470Vec3(_cross);

        TransformService.rotationYawPitchRoll(_q38, _cross.x, _cross.y, _cross.z);
        _qComb.copy(_q42).multiply(_q38);

        TransformService.slerp(
            section.rotationQuaternion,
            section.rotationQuaternion,
            _qComb,
            GrowthConstants.FLT_4D63C0 as number,
        );
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
