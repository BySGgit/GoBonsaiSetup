import * as THREE from "three";
import { describe, expect, it } from "vitest";
import {
    sub4015B0ExtractBasisY,
    sub4015D0ExtractBasisZ,
    sub4015F0ExtractTranslation,
} from "./Sub4015F0";

describe("sub_4015F0 parity helper", () => {
    it("extracts translation from Matrix4 elements[12..14]", () => {
        const m = new THREE.Matrix4().makeTranslation(1.25, -2.5, 7.75);
        const out = new THREE.Vector3();
        const result = sub4015F0ExtractTranslation(out, m);
        expect(result).toBe(out);
        expect(out.x).toBeCloseTo(1.25, 6);
        expect(out.y).toBeCloseTo(-2.5, 6);
        expect(out.z).toBeCloseTo(7.75, 6);
    });

    it("supports raw 16-float matrix storage", () => {
        const raw = new Float32Array(16);
        raw[12] = -3;
        raw[13] = 4;
        raw[14] = 5.5;
        const out: [number, number, number] = [0, 0, 0];
        const result = sub4015F0ExtractTranslation(out, raw);
        expect(result).toBe(out);
        expect(out).toEqual([-3, 4, 5.5]);
    });

    it("extracts basis-Z from Matrix4 elements[8..10] (sub_4015D0)", () => {
        const m = new THREE.Matrix4().makeRotationY(Math.PI / 2);
        const out = new THREE.Vector3();
        const result = sub4015D0ExtractBasisZ(out, m);
        expect(result).toBe(out);
        expect(out.x).toBeCloseTo(1, 6);
        expect(out.y).toBeCloseTo(0, 6);
        expect(out.z).toBeCloseTo(0, 6);
    });

    it("extracts basis-Y from Matrix4 elements[4..6] (sub_4015B0)", () => {
        const m = new THREE.Matrix4().makeRotationZ(Math.PI / 2);
        const out = new THREE.Vector3();
        const result = sub4015B0ExtractBasisY(out, m);
        expect(result).toBe(out);
        expect(out.x).toBeCloseTo(-1, 6);
        expect(out.y).toBeCloseTo(0, 6);
        expect(out.z).toBeCloseTo(0, 6);
    });
});
