import { describe, expect, it } from "vitest";
import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { branchingDispatcherSub417F40 } from "./branchingDispatcherSub417F40";
import { setSlot36SimulationDay } from "./frameState";

class CountingRand extends MSVCRand {
  public calls = 0;

  randFloat(): number {
    this.calls += 1;
    return super.randFloat();
  }
}

describe("sub_417F40 dispatcher parity", () => {
  it("does not enter apical path when only child is Leaf (C childCount logic)", () => {
    const rng = new CountingRand(123);
    setSlot36SimulationDay(730); // ~2 years world time bucket

    const twig = new TreeSection(null, 0, new MSVCRand(1), 0.08);
    twig.sectionRuntimeType4 = SectionRuntimeType.TreeSectionTwig;
    twig.energyTickCounter440 = 400; // yearsSinceBranch >= 1
    twig.twigRadius444 = 0.08; // avoid lateral branch gate (>0.2)
    twig.energyBudget432 = 2.0;
    twig.energySpent436 = 0.0;

    const leaf = new TreeSection(twig, 1, new MSVCRand(2), 0.02);
    leaf.sectionRuntimeType4 = SectionRuntimeType.TreeSectionLeaf;
    twig.children.push(leaf);

    const childCountBefore = twig.children.length;
    const spentBefore = twig.energySpent436 as number;
    const spawnBefore = twig.spawnDelta480;

    branchingDispatcherSub417F40(twig, rng);

    expect(twig.children.length).toBe(childCountBefore);
    expect(twig.energySpent436).toBeCloseTo(spentBefore, 6);
    expect(twig.spawnDelta480).toBe(spawnBefore);
    expect(rng.calls).toBe(0);
  });
});

