import { describe, expect, it } from "vitest";
import {
  getSub413DF0StateForTests,
  resetSub413DF0StateForTests,
  sub413DF0InterpolateRgba,
} from "./sub413DF0Palette";

describe("sub_413DF0 palette parity", () => {
  it("lazy-initializes once and interpolates key colors", () => {
    resetSub413DF0StateForTests();
    expect(getSub413DF0StateForTests().dword4D8D1C & 1).toBe(0);

    const out0 = new Float32Array(4);
    sub413DF0InterpolateRgba(out0, 0);
    expect(getSub413DF0StateForTests().dword4D8D1C & 1).toBe(1);
    expect(Array.from(out0)).toEqual([0, 0, 0, 1]);

    const out1 = new Float32Array(4);
    sub413DF0InterpolateRgba(out1, 1);
    expect(Array.from(out1)).toEqual([1, 1, 1, 1]);
  });

  it("matches middle segment interpolation shape", () => {
    const out = new Float32Array(4);
    sub413DF0InterpolateRgba(out, 0.5);

    expect(out[0]).toBeGreaterThanOrEqual(0);
    expect(out[0]).toBeLessThanOrEqual(1);
    expect(out[1]).toBeGreaterThanOrEqual(0);
    expect(out[1]).toBeLessThanOrEqual(1);
    expect(out[2]).toBeGreaterThanOrEqual(0);
    expect(out[2]).toBeLessThanOrEqual(1);
    expect(out[3]).toBeCloseTo(1.0, 6);
  });
});

