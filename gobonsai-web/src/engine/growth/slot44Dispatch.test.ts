import { describe, expect, it } from "vitest";
import { MSVCRand } from "../MSVCRand";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { TreeSection } from "../TreeSection";
import { clearWorldObjects, getWorldObjects } from "./detachPipelineSub40EEE0";
import { invokeSlot44ForSection } from "./slot44Dispatch";

describe("slot+44 dispatch parity", () => {
  it("bud path (sub_415ED0) performs quiet detach", () => {
    const parent = new TreeSection(null, 0, new MSVCRand(1), 0.2);
    parent.sectionRuntimeType4 = SectionRuntimeType.TreeSectionSeed;

    const bud = new TreeSection(parent, 1, new MSVCRand(2), 0.01);
    bud.sectionRuntimeType4 = SectionRuntimeType.TreeSectionBud;
    parent.children.push(bud);

    const child = new TreeSection(bud, 2, new MSVCRand(3), 0.01);
    child.sectionRuntimeType4 = SectionRuntimeType.TreeSectionLeaf;
    bud.children.push(child);

    invokeSlot44ForSection(bud, new MSVCRand(4));

    expect(parent.children.includes(bud)).toBe(false);
    expect(bud.parent).toBeNull();
    expect(bud.worldDetached188).toBe(true);
    expect(child.worldDetached188).toBe(true);
    expect(bud.children.length).toBe(0);
  });

  it("seed path (nullsub_1) is no-op", () => {
    const seed = new TreeSection(null, 0, new MSVCRand(11), 0.2);
    seed.sectionRuntimeType4 = SectionRuntimeType.TreeSectionSeed;
    seed.markedForDetach236 = false;
    seed.worldDetached188 = false;

    invokeSlot44ForSection(seed, new MSVCRand(12));

    expect(seed.markedForDetach236).toBe(false);
    expect(seed.worldDetached188).toBe(false);
    expect(seed.parent).toBeNull();
  });

  it("leaf path (sub_4142B0) climbs and detaches twig ancestor", () => {
    clearWorldObjects();

    const seed = new TreeSection(null, 0, new MSVCRand(21), 0.2);
    seed.sectionRuntimeType4 = SectionRuntimeType.TreeSectionSeed;

    const twig = new TreeSection(seed, 1, new MSVCRand(22), 0.05);
    twig.sectionRuntimeType4 = SectionRuntimeType.TreeSectionTwig;
    twig.twigRadius444 = 0.2;
    twig.healthEnergy456 = 1;
    seed.children.push(twig);

    const leaf = new TreeSection(twig, 2, new MSVCRand(23), 0.01);
    leaf.sectionRuntimeType4 = SectionRuntimeType.TreeSectionLeaf;
    leaf.healthEnergy456 = 1;
    twig.children.push(leaf);

    invokeSlot44ForSection(leaf, new MSVCRand(24));

    expect(seed.children.includes(twig)).toBe(false);
    expect(twig.parent).toBeNull();
    expect(twig.worldDetached188).toBe(true);
    expect(getWorldObjects().includes(twig)).toBe(true);

    clearWorldObjects();
  });
});

