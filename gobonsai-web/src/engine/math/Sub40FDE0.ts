import { Float32 } from './MathTypes';

/**
 * sub_40FDE0.c — интерполяция RGBA по таблице ключей (по 4 float на ключ подряд).
 * keyCount ≥ 1; a4 — параметр интерполяции (в C: age/110, energy и т.д.).
 */
export function sub40FDE0(
    keyCount: number,
    rgbaOut: Float32Array | number[],
    keyData: Float32Array | ArrayLike<number>,
    a4: Float32
): void {
    const a1 = keyCount;
    if (a1 < 1) {
        rgbaOut[0] = 1;
        rgbaOut[1] = 1;
        rgbaOut[2] = 1;
        rgbaOut[3] = 1;
        return;
    }

    const v5 = a1 - 1;
    const v19 = a1 - 1;
    const v8 = v19 * a4;
    const v6 = v19;

    const setOut = (r: number, g: number, b: number, a: number) => {
        rgbaOut[0] = r;
        rgbaOut[1] = g;
        rgbaOut[2] = b;
        rgbaOut[3] = a;
    };

    if (Math.abs(v8 - v6) < 1e-6) {
        const idx = (a1 - 1) * 4;
        setOut(keyData[idx], keyData[idx + 1], keyData[idx + 2], keyData[idx + 3]);
        return;
    }

    let v14 = v8 | 0;
    let v21 = v14;
    if (v14 >= v5) {
        v14 = a1 - 2;
        v21 = v14;
    }
    const v22 = v8 - v21;
    let v16: number;
    if (v22 >= 0.0) {
        v16 = v22 > 1.0 ? 1.0 : v22;
    } else {
        v16 = 0.0;
    }

    const base = v14 * 4;
    const v15_0 = keyData[base];
    const v15_1 = keyData[base + 1];
    const v15_2 = keyData[base + 2];
    const v15_3 = keyData[base + 3];
    const v15_4 = keyData[base + 4];
    const v15_5 = keyData[base + 5];
    const v15_6 = keyData[base + 6];
    const v15_7 = keyData[base + 7];

    const r = (v15_4 - v15_0) * v16 + v15_0;
    const g = (v15_5 - v15_1) * v16 + v15_1;
    const b = (v15_6 - v15_2) * v16 + v15_2;
    const a = v16 * (v15_7 - v15_3) + v15_3;
    setOut(r, g, b, a);
}
