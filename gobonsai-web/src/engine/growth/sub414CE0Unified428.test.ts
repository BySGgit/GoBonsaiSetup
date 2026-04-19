import { describe, it, expect } from "vitest";
import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { readUnifiedBudget428, writeUnifiedBudget428 } from "./sub414CE0";

describe("sub414CE0 unified +428 helpers", () => {
  it("reads runtime weight when yearly seed alias is zero", () => {
    const s = new TreeSection(null, 0, new MSVCRand(1));
    s.energyWeight428 = 2.5;
    s.sub414CE0SeedBudget428 = 0;
    expect(readUnifiedBudget428(s)).toBeCloseTo(2.5, 6);
  });

  it("reads runtime weight even if yearly seed alias diverged", () => {
    const s = new TreeSection(null, 0, new MSVCRand(2));
    s.energyWeight428 = 1.25;
    s.sub414CE0SeedBudget428 = 3.75;
    expect(readUnifiedBudget428(s)).toBeCloseTo(1.25, 6);
  });

  it("write helper keeps both aliases synchronized", () => {
    const s = new TreeSection(null, 0, new MSVCRand(3));
    writeUnifiedBudget428(s, 4.2);
    expect(s.energyWeight428).toBeCloseTo(4.2, 6);
    expect(s.sub414CE0SeedBudget428).toBeCloseTo(4.2, 6);
  });
});
