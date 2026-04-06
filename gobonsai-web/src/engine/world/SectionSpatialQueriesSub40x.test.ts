import * as THREE from "three";
import { describe, expect, it } from "vitest";
import {
    Aabb6,
    Sphere4,
    sub401610MergeAabb,
    sub401690AabbToSphere,
    sub401B00ExtractBasisZ,
    sub401B10BuildSubtreeAabb,
    sub403BA0FirstChildDiameter,
    SectionSpatialLike,
    sub40A310ExtractBasisZ,
    sub40D6D0ExtractBasisY,
    sub40D6C0ExtractTranslation,
    sub4153D0FindMaxWorldY,
} from "./SectionSpatialQueriesSub40x";

function sectionWithMatrix(matrix: THREE.Matrix4, children: SectionSpatialLike[] = []): SectionSpatialLike {
    return { transformMatrix: matrix, children };
}

describe("SectionSpatialQueriesSub40x", () => {
    it("sub_40D6C0 extracts translation from this+104", () => {
        const section = sectionWithMatrix(new THREE.Matrix4().makeTranslation(2, 3.5, -1));
        const out: [number, number, number] = [0, 0, 0];
        const ret = sub40D6C0ExtractTranslation(section, out);
        expect(ret).toBe(out);
        expect(out).toEqual([2, 3.5, -1]);
    });

    it("sub_40A310 extracts basis-Z from this+104", () => {
        const section = sectionWithMatrix(new THREE.Matrix4().makeRotationX(Math.PI / 2));
        const out: [number, number, number] = [0, 0, 0];
        sub40A310ExtractBasisZ(section, out);
        expect(out[0]).toBeCloseTo(0, 6);
        expect(out[1]).toBeCloseTo(-1, 6);
        expect(out[2]).toBeCloseTo(0, 6);
    });

    it("sub_40D6D0 extracts basis-Y from this+104", () => {
        const section = sectionWithMatrix(new THREE.Matrix4().makeRotationZ(Math.PI / 2));
        const out: [number, number, number] = [0, 0, 0];
        sub40D6D0ExtractBasisY(section, out);
        expect(out[0]).toBeCloseTo(-1, 6);
        expect(out[1]).toBeCloseTo(0, 6);
        expect(out[2]).toBeCloseTo(0, 6);
    });

    it("sub_4153D0 returns max Y over section subtree", () => {
        const root = sectionWithMatrix(new THREE.Matrix4().makeTranslation(0, 1.25, 0), [
            sectionWithMatrix(new THREE.Matrix4().makeTranslation(0, 2.0, 0)),
            sectionWithMatrix(new THREE.Matrix4().makeTranslation(0, 7.75, 0), [
                sectionWithMatrix(new THREE.Matrix4().makeTranslation(0, 4.5, 0)),
            ]),
        ]);
        expect(sub4153D0FindMaxWorldY(root)).toBeCloseTo(7.75, 6);
    });

    it("sub_401610 merges child aabb into parent aabb", () => {
        const dst: Aabb6 = [0, 0, 0, 1, 1, 1];
        const src: Aabb6 = [-2, 0.5, -3, 0.5, 3, 2];
        sub401610MergeAabb(src, dst);
        expect(dst).toEqual([-2, 0, -3, 1, 3, 2]);
    });

    it("sub_401B10 builds subtree aabb using center24 + meshScalar36", () => {
        const tree = {
            center24: [0, 0, 0] as const,
            meshScalar36: 1,
            children: [
                { center24: [3, 0, 0] as const, meshScalar36: 0.5 },
                {
                    center24: [-1, 2, 0] as const,
                    meshScalar36: 0.25,
                    children: [{ center24: [-2, 3, 1] as const, meshScalar36: 0.75 }],
                },
            ],
        };
        const out: Aabb6 = [0, 0, 0, 0, 0, 0];
        sub401B10BuildSubtreeAabb(tree, out);
        expect(out[0]).toBeCloseTo(-2.75, 6);
        expect(out[1]).toBeCloseTo(-1.0, 6);
        expect(out[2]).toBeCloseTo(-1.0, 6);
        expect(out[3]).toBeCloseTo(3.5, 6);
        expect(out[4]).toBeCloseTo(3.75, 6);
        expect(out[5]).toBeCloseTo(1.75, 6);
    });

    it("sub_401690 converts aabb to center+radius sphere", () => {
        const aabb: Aabb6 = [-2, -1, 0, 2, 3, 4];
        const out: Sphere4 = [0, 0, 0, 0];
        sub401690AabbToSphere(aabb, out);
        expect(out[0]).toBeCloseTo(0, 6);
        expect(out[1]).toBeCloseTo(1, 6);
        expect(out[2]).toBeCloseTo(2, 6);
        expect(out[3]).toBeCloseTo(Math.sqrt(12), 6);
    });

    it("sub_401B00 extracts basis-Z from this+40 matrix source", () => {
        const m = new THREE.Matrix4().makeRotationX(Math.PI / 2);
        const out: [number, number, number] = [0, 0, 0];
        sub401B00ExtractBasisZ({ matrix40: m }, out);
        expect(out[0]).toBeCloseTo(0, 6);
        expect(out[1]).toBeCloseTo(-1, 6);
        expect(out[2]).toBeCloseTo(0, 6);
    });

    it("sub_403BA0 returns first child diameter only for type-5-allowed sections", () => {
        const gatedOut = {
            children: [{ sectionRuntimeType4: 4, twigRadius444: 3.0 }],
        };
        expect(sub403BA0FirstChildDiameter(gatedOut)).toBeCloseTo(0, 6);

        const allowed = {
            children: [{ sectionRuntimeType4: 5, twigRadius444: 1.75 }],
        };
        expect(sub403BA0FirstChildDiameter(allowed)).toBeCloseTo(3.5, 6);
    });
});
