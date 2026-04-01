import * as THREE from 'three';
import { Float32, D3DXQUATERNION, D3DXVECTOR3 } from './MathTypes';

/**
 * TransformService
 * Reconstructs quaternion and rotation logic from C codebase.
 * Covers: sub_408470.c and quaternion parts of sub_416510.c
 */
export class TransformService {
    /**
     * D3DXQuaternionRotationAxis equivalent
     * Creates a quaternion that rotates around an arbitrary axis.
     */
    public static rotationAxis(out: D3DXQUATERNION, axis: D3DXVECTOR3, angle: Float32): void {
        out.setFromAxisAngle(axis, angle);
    }

    /**
     * D3DXQuaternionRotationYawPitchRoll equivalent
     * Note: Three.js uses Euler angles, we map Yaw/Pitch/Roll to Y/X/Z respectively.
     */
    public static rotationYawPitchRoll(out: D3DXQUATERNION, yaw: Float32, pitch: Float32, roll: Float32): void {
        // In DirectX, Yaw is around Y, Pitch is around X, Roll is around Z
        out.setFromEuler(new THREE.Euler(pitch, yaw, roll, 'YXZ'));
    }

    /**
     * D3DXQuaternionMultiply equivalent
     */
    public static multiply(out: D3DXQUATERNION, q1: D3DXQUATERNION, q2: D3DXQUATERNION): void {
        out.multiplyQuaternions(q1, q2);
    }

    /**
     * D3DXQuaternionSlerp equivalent
     * Spherical linear interpolation between two quaternions.
     */
    public static slerp(out: D3DXQUATERNION, q1: D3DXQUATERNION, q2: D3DXQUATERNION, t: Float32): void {
        out.copy(q1).slerp(q2, t);
    }

    /**
     * sub_401180.c equivalent (Vector normalization)
     */
    public static normalizeVector(v: D3DXVECTOR3): void {
        v.normalize();
    }

    /**
     * sub_4010C0.c equivalent (Vector length / magnitude)
     */
    public static vectorLength(v: D3DXVECTOR3): Float32 {
        return v.length();
    }
}
