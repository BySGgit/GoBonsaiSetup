import * as THREE from "three";

export type Sub4015F0Out = THREE.Vector3 | [number, number, number];
export type Sub4015F0Source = { elements: ArrayLike<number> } | ArrayLike<number>;

function asMatrixElements(source: Sub4015F0Source): ArrayLike<number> {
    if ("elements" in source) {
        return source.elements;
    }
    return source;
}

/**
 * sub_4015F0:
 *   out[0] = matrix[12]
 *   out[1] = matrix[13]
 *   out[2] = matrix[14]
 */
export function sub4015F0ExtractTranslation(
    out: Sub4015F0Out,
    source: Sub4015F0Source,
): Sub4015F0Out {
    const e = asMatrixElements(source);
    const x = Number(e[12] ?? 0);
    const y = Number(e[13] ?? 0);
    const z = Number(e[14] ?? 0);
    if (out instanceof THREE.Vector3) {
        out.set(x, y, z);
    } else {
        out[0] = x;
        out[1] = y;
        out[2] = z;
    }
    return out;
}
