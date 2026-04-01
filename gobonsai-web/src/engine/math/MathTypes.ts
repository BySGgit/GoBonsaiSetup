import * as THREE from 'three';

/**
 * C-style type aliases for clarity during migration.
 * Maps original C/DirectX types to TypeScript/Three.js equivalents.
 */

// Primitives
export type Float32 = number;
export type Int32 = number;
export type UInt32 = number;
export type Byte = number;

// DirectX Math Types (used in original C code)
export type D3DXVECTOR3 = THREE.Vector3;
export type D3DXQUATERNION = THREE.Quaternion;
export type D3DXMATRIX = THREE.Matrix4;

// Semantic Engine Types
export type Vector3 = THREE.Vector3;
export type Quaternion = THREE.Quaternion;
export type Matrix4 = THREE.Matrix4;
export type ColorRGBA = { r: Float32; g: Float32; b: Float32; a: Float32 };
