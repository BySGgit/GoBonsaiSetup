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

        const simTicks = Math.min(2, deltaTime * 60);
        const t = Math.min(1, GrowthConstants.FLT_4D63C0 * simTicks) as number;

        const M = section.transformMatrix;

        // sub_401540(this+352): D3DXVec3TransformNormal((0,1,0), M) → v46,v47,v48
        _u.set(0, 1, 0).transformDirection(M);

        // 227-230: *(float*)&v44=0; HIDWORD(v44)=v49; v45=v50 — без v49/v50 в декомпиляции:
        // вектор в плоскости YZ, ортогональный U: (0, -uz, uy)
        _v44.set(0, -_u.z, _u.y);
        if (_v44.lengthSq() < 1e-20) {
            _v44.set(0, 1, 0);
        } else {
            _v44.normalize();
        }

        // sub_401180(&v44): sub_401120 → v51 = v44 × U (sub_401120: result = a3×a2 = v44×U)
        _v51.crossVectors(_v44, _u);

        // 232-236: только v51[0] → ±1
        _v51.x = _v51.x >= 0.0 ? 1.0 : -1.0;

        // 237: sub_4010C0(&v44, &v46)
        let v25 = sub4010C0(_v44, _u);

        // 238-248
        if (v25 >= ANGLE_MIN) {
            if (v25 > ANGLE_MAX) v25 = ANGLE_MAX;
            TransformService.rotationAxis(_q42, _v51, v25);
        } else {
            v25 = ANGLE_MIN;
            TransformService.rotationAxis(_q42, _v51, ANGLE_MIN);
        }

        const v31 = -v25;
        // 250: D3DXMatrixRotationYawPitchRoll(v52, v31, 0, 0)
        _matRy.makeRotationY(v31);

        // 251: sub_401540(v52) — выход в v38[0..2], v46..v48 остаются U
        _w.set(0, 1, 0).transformDirection(_matRy);

        // 252: sub_4010C0(v38, v46) — угол между W и U
        let v26 = sub4010C0(_w, _u);

        // 253-263
        if (v26 >= V26_NEG) {
            if (v26 > V26_POS_CMP) {
                v26 = V26_CLAMP_HI;
            }
        } else {
            v26 = V26_NEG;
        }

        // 265-266: sub_401180(v38); sub_408470() — результат не попадает в multiply (268 перезаписывает v38)

        // 267: D3DXQuaternionRotationAxis(v43, &v46, v26) — в C не участвует в multiply

        // 268: D3DXQuaternionRotationYawPitchRoll(v38, Ux, Uy, Uz)
        TransformService.rotationYawPitchRoll(_q38, _u.x, _u.y, _u.z);

        // 269: D3DXQuaternionMultiply(&v35, v42, v38)
        TransformService.multiply(_qCombined, _q42, _q38);

        // 273: D3DXQuaternionSlerp(this+320, this+320, &v39, flt_4D63C0)
        TransformService.slerp(section.rotationQuaternion, section.rotationQuaternion, _qCombined, t);
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
