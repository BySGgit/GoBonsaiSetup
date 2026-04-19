import { describe, expect, it } from "vitest";
import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { twigUpdateSub417C90 } from "./twigUpdateSub417C90";
import { clearWorldObjects, getWorldObjects } from "./detachPipelineSub40EEE0";

class SequenceRand extends MSVCRand {
  private readonly seq: number[];
  public calls = 0;

  constructor(values: number[]) {
    super(1);
    this.seq = values.slice();
  }

  randFloat(): number {
    const value = this.seq[this.calls] ?? 0;
    this.calls += 1;
    return value;
  }
}

describe("sub_417C90 parity updates", () => {
  it("applies girth cap even when current radius is zero", () => {
    const rng = new MSVCRand(10);
    const section = new TreeSection(null, 0, rng, 0.1);
    section.growthFlag512 = false;
    section.twigRadius444 = 0;
    section.energyProduction420 = 10;
    section.healthEnergy456 = 1;

    twigUpdateSub417C90(section, undefined);

    expect(section.twigRadius444).toBeCloseTo(0.1, 6);
  });

  it("does not auto-detach dead continuation twig", () => {
    clearWorldObjects();

    const rng = new SequenceRand([0.9]);
    const parent = new TreeSection(null, 0, new MSVCRand(1), 0.2);
    const section = new TreeSection(parent, 1, new MSVCRand(2), 0.05);
    const child = new TreeSection(section, 2, new MSVCRand(3), 0.03);

    parent.children.push(section);
    section.children.push(child);
    section.isContinuation = true;
    section.healthEnergy456 = 0;
    parent.healthEnergy456 = 1;
    section.twigRadius444 = 0.05;
    section.energyTickCounter440 = 1200;
    section.growthFlag512 = true;

    twigUpdateSub417C90(section, rng);

    expect(section.parent).toBe(parent);
    expect(section.worldDetached188).toBe(false);
    expect(parent.children.includes(section)).toBe(true);
    expect(getWorldObjects().includes(section)).toBe(false);

    clearWorldObjects();
  });

  it("matches childCount==0 branch: detach from parent and set worldDetached before length growth", () => {
    const parent = new TreeSection(null, 0, new MSVCRand(31), 0.2);
    const section = new TreeSection(parent, 1, new MSVCRand(32), 0.05);
    parent.children.push(section);

    section.growthFlag512 = true;
    section.energyBudget432 = 1.0;
    section.energySpent436 = 0.0;
    section.twigLength448 = 0.0;
    section.maxGrowth = 5.0;

    twigUpdateSub417C90(section, undefined);

    expect(section.parent).toBeNull();
    expect(parent.children.includes(section)).toBe(false);
    expect(section.worldDetached188).toBe(true);
    expect(section.twigLength448).toBeGreaterThan(0);
  });

  it("does not detach continuation twig in childCount==0 growth branch", () => {
    const parent = new TreeSection(null, 0, new MSVCRand(41), 0.2);
    const section = new TreeSection(parent, 1, new MSVCRand(42), 0.05);
    parent.children.push(section);

    section.growthFlag512 = true;
    section.isContinuation = true;
    section.energyBudget432 = 1.0;
    section.energySpent436 = 0.0;
    section.twigLength448 = 0.0;
    section.maxGrowth = 5.0;

    twigUpdateSub417C90(section, undefined);

    expect(section.parent).toBe(parent);
    expect(parent.children.includes(section)).toBe(true);
    expect(section.worldDetached188).toBe(false);
  });

  it("matches C-style lazy second rand call in detach branch", () => {
    clearWorldObjects();

    const parentA = new TreeSection(null, 0, new MSVCRand(11), 0.2);
    const sectionA = new TreeSection(parentA, 1, new MSVCRand(12), 0.05);
    const childA = new TreeSection(sectionA, 2, new MSVCRand(13), 0.03);
    parentA.children.push(sectionA);
    sectionA.children.push(childA);
    sectionA.healthEnergy456 = 0;
    parentA.healthEnergy456 = 1;
    sectionA.twigRadius444 = 0.05;
    sectionA.energyTickCounter440 = 1500;
    sectionA.growthFlag512 = true;
    const rngA = new SequenceRand([0.99]);

    twigUpdateSub417C90(sectionA, rngA);

    // 1 (detach gate) + 6 (detach impulse vectors)
    expect(rngA.calls).toBe(7);

    const parentB = new TreeSection(null, 0, new MSVCRand(21), 0.2);
    const sectionB = new TreeSection(parentB, 1, new MSVCRand(22), 0.05);
    const childB = new TreeSection(sectionB, 2, new MSVCRand(23), 0.03);
    parentB.children.push(sectionB);
    sectionB.children.push(childB);
    sectionB.healthEnergy456 = 0;
    parentB.healthEnergy456 = 1;
    sectionB.twigRadius444 = 0.3; // radiusGate=1.2 -> first random does not detach
    sectionB.energyTickCounter440 = 1500;
    sectionB.growthFlag512 = true;
    const rngB = new SequenceRand([0.2, 0.001]);

    twigUpdateSub417C90(sectionB, rngB);

    // 2 (detach gate + rare gate) + 6 (detach impulse vectors)
    expect(rngB.calls).toBe(8);

    clearWorldObjects();
  });
});
