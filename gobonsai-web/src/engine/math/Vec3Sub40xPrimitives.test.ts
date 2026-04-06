import { describe, expect, it } from "vitest";
import * as THREE from "three";
import {
    sub401120,
    sub401180,
    sub4013F0,
    sub401430,
    sub401470,
    sub401500,
    sub40CF00NormalizeInPlace,
    sub408470,
    sub4085B0TransformCoord,
    sub4084F0NormalizeInPlaceReturnLen,
    sub408590,
} from "./Vec3Sub40xPrimitives";

describe("Vec3Sub40xPrimitives", () => {
    it("sub_401430 computes a3-a2", () => {
        const out = new THREE.Vector3();
        sub401430(out, new THREE.Vector3(1, 2, 3), new THREE.Vector3(4, 7, 9));
        expect(out.toArray()).toEqual([3, 5, 6]);
    });

    it("sub_4013F0 computes a2+a3", () => {
        const out = new THREE.Vector3();
        sub4013F0(out, new THREE.Vector3(1, 2, 3), new THREE.Vector3(4, 7, 9));
        expect(out.toArray()).toEqual([5, 9, 12]);
    });

    it("sub_401470/sub_401500 scale vector", () => {
        const outA = new THREE.Vector3();
        const outB = new THREE.Vector3();
        const v = new THREE.Vector3(2, -3, 0.5);
        sub401470(outA, v, 4);
        sub401500(outB, v, 4);
        expect(outA.toArray()).toEqual([8, -12, 2]);
        expect(outB.toArray()).toEqual([8, -12, 2]);
    });

    it("sub_401120 matches decompiled handedness", () => {
        const out = new THREE.Vector3();
        sub401120(out, new THREE.Vector3(1, 0, 0), new THREE.Vector3(0, 1, 0));
        expect(out.toArray()).toEqual([0, 0, -1]);
    });

    it("sub_401180 equals sub_401120(out, a2, a1)", () => {
        const out = new THREE.Vector3();
        sub401180(out, new THREE.Vector3(1, 0, 0), new THREE.Vector3(0, 1, 0));
        expect(out.toArray()).toEqual([0, 0, 1]);
    });

    it("sub_408470 falls back to +Z on zero vector", () => {
        const out = new THREE.Vector3(5, 5, 5);
        sub408470(out, new THREE.Vector3(0, 0, 0));
        expect(out.toArray()).toEqual([0, 0, 1]);
    });

    it("sub_4084F0 returns length and normalizes in place", () => {
        const v = new THREE.Vector3(0, 3, 4);
        const len = sub4084F0NormalizeInPlaceReturnLen(v);
        expect(len).toBeCloseTo(5, 6);
        expect(v.x).toBeCloseTo(0, 6);
        expect(v.y).toBeCloseTo(0.6, 6);
        expect(v.z).toBeCloseTo(0.8, 6);
    });

    it("sub_408590 negates vector", () => {
        const out = new THREE.Vector3();
        sub408590(out, new THREE.Vector3(1.25, -2, 3));
        expect(out.toArray()).toEqual([-1.25, 2, -3]);
    });

    it("sub_4085B0 transforms coord and returns out pointer", () => {
        const out = new THREE.Vector3();
        const inVec = new THREE.Vector3(1, 2, 3);
        const m = new THREE.Matrix4().makeTranslation(10, -5, 1);
        const ret = sub4085B0TransformCoord(out, inVec, m);
        expect(ret).toBe(out);
        expect(out.toArray()).toEqual([11, -3, 4]);
    });

    it("sub_40CF00 normalizes in place and returns same ref", () => {
        const v = new THREE.Vector3(3, 0, 4);
        const ret = sub40CF00NormalizeInPlace(v);
        expect(ret).toBe(v);
        expect(v.x).toBeCloseTo(0.6, 6);
        expect(v.y).toBeCloseTo(0.0, 6);
        expect(v.z).toBeCloseTo(0.8, 6);
    });

    it("sub_40CF00 falls back to +Z for near-zero vectors", () => {
        const v = new THREE.Vector3(0, 0, 0);
        const ret = sub40CF00NormalizeInPlace(v);
        expect(ret).toBe(v);
        expect(v.toArray()).toEqual([0, 0, 1]);
    });
});
