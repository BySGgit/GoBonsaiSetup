import {
    Sub4015F0Out,
    Sub4015F0Source,
    sub4015B0ExtractBasisY,
    sub4015D0ExtractBasisZ,
    sub4015F0ExtractTranslation,
} from "../math/Sub4015F0";
import { byte4D8225ForSectionType } from "../config/GrowthConstants";
import { sub4079C0EnsureInitialized } from "../config/SectionTypeRegistrySub401730";

export type SectionSpatialLike = {
    transformMatrix: Sub4015F0Source;
    children?: ReadonlyArray<SectionSpatialLike>;
};

export type Aabb6 = [number, number, number, number, number, number];
export type Sphere4 = [number, number, number, number];
export type Vec3Like = Readonly<[number, number, number]> | { x: number; y: number; z: number };
export type SectionBoundsLike = {
    center24: Vec3Like;
    meshScalar36: number;
    children?: ReadonlyArray<SectionBoundsLike>;
};
export type Sub401B00Like = {
    matrix40: Sub4015F0Source;
};
export type Sub403BA0Like = {
    children?: ReadonlyArray<{
        sectionRuntimeType4: number;
        twigRadius444: number;
    }>;
};

function vec3X(v: Vec3Like): number {
    return "x" in v ? v.x : v[0];
}

function vec3Y(v: Vec3Like): number {
    return "x" in v ? v.y : v[1];
}

function vec3Z(v: Vec3Like): number {
    return "x" in v ? v.z : v[2];
}

/**
 * sub_40D6C0:
 *   sub_4015F0(out, this+104)
 */
export function sub40D6C0ExtractTranslation(
    a1: SectionSpatialLike,
    out: Sub4015F0Out,
): Sub4015F0Out {
    return sub4015F0ExtractTranslation(out, a1.transformMatrix);
}

/**
 * sub_40A310:
 *   sub_4015D0(out, this+104)
 */
export function sub40A310ExtractBasisZ(
    a1: SectionSpatialLike,
    out: Sub4015F0Out,
): Sub4015F0Out {
    return sub4015D0ExtractBasisZ(out, a1.transformMatrix);
}

/**
 * sub_40D6D0:
 *   sub_4015B0(out, this+104)
 */
export function sub40D6D0ExtractBasisY(
    a1: SectionSpatialLike,
    out: Sub4015F0Out,
): Sub4015F0Out {
    return sub4015B0ExtractBasisY(out, a1.transformMatrix);
}

/**
 * sub_4153D0:
 *   y = sub_4015F0(this+104)[1];
 *   return max(y, max(child...)).
 */
export function sub4153D0FindMaxWorldY(thisSection: SectionSpatialLike): number {
    const local: [number, number, number] = [0, 0, 0];
    sub40D6C0ExtractTranslation(thisSection, local);
    let maxY = local[1];
    const children = thisSection.children ?? [];
    for (const child of children) {
        const childY = sub4153D0FindMaxWorldY(child);
        if (childY > maxY) maxY = childY;
    }
    return maxY;
}

/** sub_401610: merge `a1` bounds into `a2` (min/min/min + max/max/max). */
export function sub401610MergeAabb(a1: Readonly<Aabb6>, a2: Aabb6): void {
    if (a2[0] > a1[0]) a2[0] = a1[0];
    if (a2[1] > a1[1]) a2[1] = a1[1];
    if (a2[2] > a1[2]) a2[2] = a1[2];
    if (a2[3] < a1[3]) a2[3] = a1[3];
    if (a2[4] < a1[4]) a2[4] = a1[4];
    if (a2[5] < a1[5]) a2[5] = a1[5];
}

/**
 * sub_401B10: subtree AABB from this+24 (center) and this+36 (extent scalar).
 * Child boxes are recursively merged via sub_401610.
 */
export function sub401B10BuildSubtreeAabb(thisSection: SectionBoundsLike, out: Aabb6): Aabb6 {
    const cx = vec3X(thisSection.center24);
    const cy = vec3Y(thisSection.center24);
    const cz = vec3Z(thisSection.center24);
    const r = Number(thisSection.meshScalar36);

    out[0] = cx - r;
    out[1] = cy - r;
    out[2] = cz - r;
    out[3] = cx + r;
    out[4] = cy + r;
    out[5] = cz + r;

    const children = thisSection.children ?? [];
    for (const child of children) {
        const childBox: Aabb6 = [0, 0, 0, 0, 0, 0];
        sub401B10BuildSubtreeAabb(child, childBox);
        sub401610MergeAabb(childBox, out);
    }

    return out;
}

/** sub_401690: convert AABB[6] -> sphere [cx, cy, cz, radius]. */
export function sub401690AabbToSphere(aabb: Readonly<Aabb6>, out: Sphere4): Sphere4 {
    const hx = (aabb[3] - aabb[0]) * 0.5;
    const hy = (aabb[4] - aabb[1]) * 0.5;
    const hz = (aabb[5] - aabb[2]) * 0.5;

    out[0] = aabb[0] + hx;
    out[1] = aabb[1] + hy;
    out[2] = aabb[2] + hz;
    out[3] = Math.sqrt(hx * hx + hy * hy + hz * hz);
    return out;
}

/** sub_401B00: wrapper to sub_4015D0(out, this+40). */
export function sub401B00ExtractBasisZ(thisLike: Sub401B00Like, out: Sub4015F0Out): Sub4015F0Out {
    return sub4015D0ExtractBasisZ(out, thisLike.matrix40);
}

/**
 * sub_403BA0 (core): first child diameter gate by byte_4D8225.
 * Caller should pass `a1+240` owner section equivalent.
 */
export function sub403BA0FirstChildDiameter(ownerSection: Sub403BA0Like | null | undefined): number {
    if (!ownerSection) return 0.0;
    const firstChild = ownerSection.children?.[0] ?? null;
    if (!firstChild) return 0.0;

    sub4079C0EnsureInitialized();
    if (!byte4D8225ForSectionType(firstChild.sectionRuntimeType4)) {
        return 0.0;
    }
    const r = Number(firstChild.twigRadius444);
    return r + r;
}
