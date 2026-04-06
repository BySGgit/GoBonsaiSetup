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

/**
 * sub_4015D0:
 *   out[0] = matrix[8]
 *   out[1] = matrix[9]
 *   out[2] = matrix[10]
 */
export function sub4015D0ExtractBasisZ(
    out: Sub4015F0Out,
    source: Sub4015F0Source,
): Sub4015F0Out {
    const e = asMatrixElements(source);
    const x = Number(e[8] ?? 0);
    const y = Number(e[9] ?? 0);
    const z = Number(e[10] ?? 0);
    if (out instanceof THREE.Vector3) {
        out.set(x, y, z);
    } else {
        out[0] = x;
        out[1] = y;
        out[2] = z;
    }
    return out;
}

/**
 * sub_4015B0:
 *   out[0] = matrix[4]
 *   out[1] = matrix[5]
 *   out[2] = matrix[6]
 */
export function sub4015B0ExtractBasisY(
    out: Sub4015F0Out,
    source: Sub4015F0Source,
): Sub4015F0Out {
    const e = asMatrixElements(source);
    const x = Number(e[4] ?? 0);
    const y = Number(e[5] ?? 0);
    const z = Number(e[6] ?? 0);
    if (out instanceof THREE.Vector3) {
        out.set(x, y, z);
    } else {
        out[0] = x;
        out[1] = y;
        out[2] = z;
    }
    return out;
}
