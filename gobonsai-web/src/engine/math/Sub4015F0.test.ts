import * as THREE from "three";
import { describe, expect, it } from "vitest";
import { sub4015F0ExtractTranslation } from "./Sub4015F0";

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
});
