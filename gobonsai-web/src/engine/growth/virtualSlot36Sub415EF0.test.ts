import { describe, expect, it } from "vitest";
import { MSVCRand } from "../MSVCRand";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { TreeSection } from "../TreeSection";
import { dispatchVirtualSlot36 } from "./virtualSlot36";

describe("sub_415EF0 bud parity", () => {
  const originalDocument = globalThis.document;

  class CountingRand extends MSVCRand {
    public calls = 0;

    randFloat(): number {
      this.calls += 1;
      return super.randFloat();
    }
  }

  function installCanvasStub(): void {
    (globalThis as unknown as { document?: { createElement: (tag: string) => unknown } }).document = {
      createElement: (tag: string) => {
        if (tag !== "canvas") {
          throw new Error(`unexpected tag: ${tag}`);
        }
        return {
          width: 0,
          height: 0,
          getContext: () => ({
            clearRect() {},
            save() {},
            restore() {},
            translate() {},
            rotate() {},
            scale() {},
            createLinearGradient: () => ({ addColorStop() {} }),
            fillStyle: null,
            strokeStyle: null,
            lineWidth: 0,
            beginPath() {},
            ellipse() {},
            moveTo() {},
            bezierCurveTo() {},
            quadraticCurveTo() {},
            closePath() {},
            fill() {},
            stroke() {},
          }),
        };
      },
    };
  }

  function restoreDocument(): void {
    (globalThis as unknown as { document?: unknown }).document = originalDocument;
  }

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

  it("creates continuation twig from exact-template bud without copying attachment runtime fields", () => {
    installCanvasStub();
    const root = new TreeSection(null, 0, new MSVCRand(21), 0.2);
    root.sectionRuntimeType4 = SectionRuntimeType.TreeSectionTwig;
    root.growthFlag512 = false;

    const bud = new TreeSection(root, 1, new MSVCRand(22), 0.01);
    bud.sectionRuntimeType4 = SectionRuntimeType.TreeSectionBud;
    bud.useExactLocalTemplateAttachment240 = true;
    bud.localTemplate240.makeTranslation(0.12, 0.85, 0.33);
    bud.branchPosition = 0.37;
    bud.lateralTransY4158 = 0.19;
    bud.lateralRoll4158Z = 0.44;
    bud.energyBudget432 = 1.0;
    bud.maxGrowth = 0.05;
    bud.twigRadius444 = 0.05;
    root.children.push(bud);

    dispatchVirtualSlot36(bud, new MSVCRand(23), false);

    const newTwig = root.children.find(
      (c) => c !== bud && c.sectionRuntimeType4 === SectionRuntimeType.TreeSectionTwig,
    );
    expect(newTwig).toBeTruthy();
    expect(newTwig!.useExactLocalTemplateAttachment240).toBe(true);
    expect(newTwig!.branchPosition).toBeCloseTo(1.0, 6);
    expect(newTwig!.lateralTransY4158).toBeCloseTo(0.0, 6);
    expect(newTwig!.lateralRoll4158Z).toBeCloseTo(0.0, 6);
    const leaves = newTwig!.children.filter(
      (c) => c.sectionRuntimeType4 === SectionRuntimeType.TreeSectionLeaf,
    );
    expect(leaves.length).toBe(2);
    for (const leaf of leaves) {
      expect(leaf.useExactLocalTemplateAttachment240).toBe(true);
    }
    restoreDocument();
  });

  it("does not let leaf visual setup advance gameplay RNG stream", () => {
    installCanvasStub();
    const root = new TreeSection(null, 0, new MSVCRand(31), 0.2);
    root.sectionRuntimeType4 = SectionRuntimeType.TreeSectionTwig;
    root.growthFlag512 = false;

    const bud = new TreeSection(root, 1, new MSVCRand(32), 0.01);
    bud.sectionRuntimeType4 = SectionRuntimeType.TreeSectionBud;
    bud.energyBudget432 = 1.0;
    bud.maxGrowth = 0.05;
    bud.twigRadius444 = 0.05;
    root.children.push(bud);

    const rng = new CountingRand(33);
    dispatchVirtualSlot36(bud, rng, false);

    expect(rng.calls).toBe(5);
    restoreDocument();
  });
});
