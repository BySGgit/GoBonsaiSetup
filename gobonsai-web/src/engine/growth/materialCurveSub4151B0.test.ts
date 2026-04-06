import { describe, expect, it } from "vitest";
import {
  getMaterialColorMode,
  resolveMaterialColor,
  setMaterialColorMode,
} from "./materialCurveSub4151B0";

function sectionStub(): any {
  return {
    energyProduction420: 0,
    energyBudget432: 0,
    energySpent436: 0,
    healthEnergy456: 0,
  };
}

describe("sub_4151B0 material resolver", () => {
  it("returns null for disabled modes", () => {
    const s = sectionStub();
    setMaterialColorMode(0);
    expect(resolveMaterialColor(s)).toBeNull();
    setMaterialColorMode(1);
    expect(resolveMaterialColor(s)).toBeNull();
  });

  it("resolves rgba via sub_413DF0 for active modes", () => {
    const s = sectionStub();
    s.energyProduction420 = 12.5;
    setMaterialColorMode(2);
    const c2 = resolveMaterialColor(s);
    expect(c2).not.toBeNull();
    expect((c2 as any).a).toBeCloseTo(1, 6);

    s.healthEnergy456 = 0.9;
    setMaterialColorMode(5);
    const c5 = resolveMaterialColor(s);
    expect(c5).not.toBeNull();
    expect((c5 as any).a).toBeCloseTo(1, 6);
  });

  it("tracks the color mode setter/getter", () => {
    setMaterialColorMode(4);
    expect(getMaterialColorMode()).toBe(4);
  });
});

