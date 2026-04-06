import * as THREE from "three";

/**
 * Exact low-level vec3 primitives mirrored from decompiled C helpers.
 * These are intentionally tiny and explicit so higher-level growth code
 * can reuse one canonical implementation.
 */

export const SUB_4084F0_EPS = 1.000000013351432e-10;

/** sub_401430: out = a3 - a2 */
export function sub401430(out: THREE.Vector3, a2: THREE.Vector3, a3: THREE.Vector3): THREE.Vector3 {
    out.set(a3.x - a2.x, a3.y - a2.y, a3.z - a2.z);
    return out;
}

/** sub_4013F0: out = a2 + a3 */
export function sub4013F0(out: THREE.Vector3, a2: THREE.Vector3, a3: THREE.Vector3): THREE.Vector3 {
    out.set(a2.x + a3.x, a2.y + a3.y, a2.z + a3.z);
    return out;
}

/** sub_401470: out = a2 * a3 */
export function sub401470(out: THREE.Vector3, a2: THREE.Vector3, a3: number): THREE.Vector3 {
    out.set(a2.x * a3, a2.y * a3, a2.z * a3);
    return out;
}

/** sub_401500: calling-convention variant of sub_401470 */
export function sub401500(out: THREE.Vector3, a2: THREE.Vector3, a3: number): THREE.Vector3 {
    return sub401470(out, a2, a3);
}

/** sub_4014B0: out = a2 / a3 */
export function sub4014B0(out: THREE.Vector3, a2: THREE.Vector3, a3: number): THREE.Vector3 {
    const inv = 1.0 / a3;
    out.set(a2.x * inv, a2.y * inv, a2.z * inv);
    return out;
}

/** sub_401120: out = a2 x a3 */
export function sub401120(out: THREE.Vector3, a2: THREE.Vector3, a3: THREE.Vector3): THREE.Vector3 {
    out.set(
        a2.z * a3.y - a2.y * a3.z,
        a2.x * a3.z - a3.x * a2.z,
        a2.y * a3.x - a2.x * a3.y,
    );
    return out;
}

/** sub_401180: out = a2 x a1 (thin wrapper around sub_401120) */
export function sub401180(out: THREE.Vector3, a1: THREE.Vector3, a2: THREE.Vector3): THREE.Vector3 {
    return sub401120(out, a2, a1);
}

/**
 * sub_408470: normalized copy with fallback to +Z for near-zero vectors.
 * Returns the output vector.
 */
export function sub408470(out: THREE.Vector3, a2: THREE.Vector3): THREE.Vector3 {
    const lenSq = a2.x * a2.x + a2.y * a2.y + a2.z * a2.z;
    const len = Math.sqrt(lenSq);
    if (len <= SUB_4084F0_EPS) {
        out.set(0, 0, 1);
        return out;
    }
    return sub408450(out, a2, len);
}

/** sub_408450: out = a1 / a3 */
export function sub408450(out: THREE.Vector3, a1: THREE.Vector3, a3: number): THREE.Vector3 {
    return sub4014B0(out, a1, a3);
}

/**
 * sub_4084F0 semantic used in physics code: normalize in place and return original len.
 * On near-zero input writes (0,0,1) and returns 0.
 */
export function sub4084F0NormalizeInPlaceReturnLen(v: THREE.Vector3): number {
    const lenSq = v.x * v.x + v.y * v.y + v.z * v.z;
    const len = Math.sqrt(lenSq);
    if (len <= SUB_4084F0_EPS) {
        v.set(0, 0, 1);
        return 0;
    }
    const inv = 1 / len;
    v.multiplyScalar(inv);
    return len;
}

/**
 * sub_40CF00: normalize in place with the same near-zero fallback as sub_4084F0,
 * but returns the input pointer.
 */
export function sub40CF00NormalizeInPlace(v: THREE.Vector3): THREE.Vector3 {
    sub4084F0NormalizeInPlaceReturnLen(v);
    return v;
}

/** sub_4085B0: D3DXVec3TransformCoord(out, a1, a3) */
export function sub4085B0TransformCoord(
    out: THREE.Vector3,
    a1: THREE.Vector3,
    a3: THREE.Matrix4,
): THREE.Vector3 {
    out.copy(a1).applyMatrix4(a3);
    return out;
}

/** sub_408590: out = -a1 */
export function sub408590(out: THREE.Vector3, a1: THREE.Vector3): THREE.Vector3 {
    return sub401470(out, a1, -1.0);
}
