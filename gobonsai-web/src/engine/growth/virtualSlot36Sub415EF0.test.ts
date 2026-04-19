import { describe, expect, it } from "vitest";
import { MSVCRand } from "../MSVCRand";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { TreeSection } from "../TreeSection";
import { dispatchVirtualSlot36 } from "./virtualSlot36";

describe("sub_415EF0 bud parity", () => {
  it("uses quiet detach path when energyBudget432 is exactly zero", () => {
    const parent = new TreeSection(null, 0, new MSVCRand(1), 0.2);
    parent.sectionRuntimeType4 = SectionRuntimeType.TreeSectionTwig;

    const bud = new TreeSection(parent, 1, new MSVCRand(2), 0.01);
    bud.sectionRuntimeType4 = SectionRuntimeType.TreeSectionBud;
    parent.children.push(bud);

    bud.energyBudget432 = 0;
    bud.baseGrowth = 1;
    bud.markedForDetach236 = true;

    dispatchVirtualSlot36(bud, new MSVCRand(3), false);

    expect(bud.worldDetached188).toBe(true);
    expect(bud.parent).toBeNull();
    expect(parent.children.includes(bud)).toBe(false);
    expect(bud.markedForDetach236).toBe(false);
  });

  it("does not detach when baseGrowth is zero but energyBudget432 is positive", () => {
    const parent = new TreeSection(null, 0, new MSVCRand(11), 0.2);
    parent.sectionRuntimeType4 = SectionRuntimeType.TreeSectionTwig;

    const bud = new TreeSection(parent, 1, new MSVCRand(12), 0.01);
    bud.sectionRuntimeType4 = SectionRuntimeType.TreeSectionBud;
    parent.children.push(bud);

    bud.baseGrowth = 0;
    bud.energyBudget432 = 1.0;
    bud.twigRadius444 = 0.1;
    bud.maxGrowth = 1.0;

    dispatchVirtualSlot36(bud, new MSVCRand(13), false);

    expect(bud.worldDetached188).toBe(false);
    expect(bud.parent).toBe(parent);
    expect(parent.children.includes(bud)).toBe(true);
    expect(bud.twigRadius444).toBeGreaterThan(0.1);
  });
});

