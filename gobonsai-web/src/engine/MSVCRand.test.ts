import { describe, it, expect } from "vitest";
import { MSVCRand } from "./MSVCRand";

/**
 * Классическая последовательность MSVC rand() при seed=1 (см. spec_ts_parity_verification.md §1).
 * Первое значение после первого вызова rand().
 */
const MSVC_SEED1_FIRST15 = [
  41, 18467, 6334, 26500, 19169, 15724, 11478, 29358, 26962, 24464, 5705, 28145,
  23281, 16827, 9961,
];

describe("MSVCRand", () => {
  it("совпадает с MSVC rand() для seed=1 (первые 15 вызовов)", () => {
    const r = new MSVCRand(1);
    for (let i = 0; i < MSVC_SEED1_FIRST15.length; i++) {
      expect(r.rand()).toBe(MSVC_SEED1_FIRST15[i]);
    }
  });

  it("srand сбрасывает последовательность", () => {
    const r = new MSVCRand(1);
    r.rand();
    r.srand(1);
    expect(r.rand()).toBe(MSVC_SEED1_FIRST15[0]);
  });

  it("randFloat = rand() / 32767", () => {
    const r = new MSVCRand(1);
    expect(r.randFloat()).toBeCloseTo(MSVC_SEED1_FIRST15[0] / 32767.0, 10);
  });
});
