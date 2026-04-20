import * as THREE from "three";
import { describe, expect, it } from "vitest";
import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { branchingDispatcherSub417F40 } from "./branchingDispatcherSub417F40";
import { readUnifiedBudget428 } from "./sub414CE0";
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

  it("initializes spawned bud accumulator424 together with unified +428", () => {
    const rng = new MSVCRand(7);
    setSlot36SimulationDay(730); // >=1 year bucket, deterministic childless apical path

    const twig = new TreeSection(null, 0, new MSVCRand(8), 0.25);
    twig.sectionRuntimeType4 = SectionRuntimeType.TreeSectionTwig;
    twig.energyTickCounter440 = 400;
    twig.twigRadius444 = 0.08;
    twig.energyBudget432 = 5.0;
    twig.energySpent436 = 0.0;

    branchingDispatcherSub417F40(twig, rng);

    const bud = twig.children.find(
      (c) => c.sectionRuntimeType4 === SectionRuntimeType.TreeSectionBud,
    );
    expect(bud).toBeTruthy();
    expect(bud!.energyAccumulator424).toBeCloseTo(readUnifiedBudget428(bud!), 6);
  });

  it("preserves exact local template attachment for childless bud-pair path", () => {
    const rng = new MSVCRand(7);
    setSlot36SimulationDay(730);

    const twig = new TreeSection(null, 0, new MSVCRand(8), 0.25);
    twig.sectionRuntimeType4 = SectionRuntimeType.TreeSectionTwig;
    twig.energyTickCounter440 = 400;
    twig.twigRadius444 = 0.08;
    twig.energyBudget432 = 5.0;
    twig.energySpent436 = 0.0;

    branchingDispatcherSub417F40(twig, rng);

    const bud = twig.children.find(
      (c) => c.sectionRuntimeType4 === SectionRuntimeType.TreeSectionBud,
    );
    expect(bud).toBeTruthy();
    expect(bud!.useExactLocalTemplateAttachment240).toBe(true);

    const expectedPos = new THREE.Vector3();
    const expectedQuat = new THREE.Quaternion();
    const expectedScale = new THREE.Vector3();
    bud!.localTemplate240.decompose(expectedPos, expectedQuat, expectedScale);
    expect(bud!.group.position.x).toBeCloseTo(expectedPos.x, 6);
    expect(bud!.group.position.y).toBeCloseTo(expectedPos.y, 6);
    expect(bud!.group.position.z).toBeCloseTo(expectedPos.z, 6);
  });

  it("preserves exact local template attachment for existing-child apical path", () => {
    const rng = new MSVCRand(17);
    setSlot36SimulationDay(730);

    const twig = new TreeSection(null, 0, new MSVCRand(18), 0.25);
    twig.sectionRuntimeType4 = SectionRuntimeType.TreeSectionTwig;
    twig.energyTickCounter440 = 400;
    twig.twigRadius444 = 0.08;
    twig.energyBudget432 = 5.0;
    twig.energySpent436 = 0.0;
    twig.rollupDword484 = 1;

    const childTwig = new TreeSection(twig, 1, new MSVCRand(19), 0.05);
    childTwig.sectionRuntimeType4 = SectionRuntimeType.TreeSectionTwig;
    childTwig.energyTickCounter440 = 400;
    twig.children.push(childTwig);

    branchingDispatcherSub417F40(twig, rng);

    const spawnedBuds = twig.children.filter(
      (c) => c.sectionRuntimeType4 === SectionRuntimeType.TreeSectionBud,
    );
    expect(spawnedBuds.length).toBeGreaterThanOrEqual(2);
    for (const bud of spawnedBuds) {
      expect(bud.useExactLocalTemplateAttachment240).toBe(true);
      expect(bud.branchPosition).toBeCloseTo(1.0, 6);
      expect(bud.lateralTransY4158).toBeCloseTo(0.0, 6);
      expect(bud.lateralRoll4158Z).toBeCloseTo(0.0, 6);
      const expectedPos = new THREE.Vector3();
      const expectedQuat = new THREE.Quaternion();
      const expectedScale = new THREE.Vector3();
      bud.localTemplate240.decompose(expectedPos, expectedQuat, expectedScale);
      expect(bud.group.position.x).toBeCloseTo(expectedPos.x, 6);
      expect(bud.group.position.y).toBeCloseTo(expectedPos.y, 6);
      expect(bud.group.position.z).toBeCloseTo(expectedPos.z, 6);
    }
  });

  it("preserves exact local template attachment for lateral branch path", () => {
    const rng = new MSVCRand(23);
    setSlot36SimulationDay(365 * 5); // yearsSinceBranch > 3

    const twig = new TreeSection(null, 0, new MSVCRand(24), 0.25);
    twig.sectionRuntimeType4 = SectionRuntimeType.TreeSectionTwig;
    twig.energyTickCounter440 = 200;
    twig.twigRadius444 = 0.25; // lateral gate > 0.2
    twig.energyBudget432 = 5000.0; // force noticeable probability
    twig.energySpent436 = 0.0;

    let attempts = 0;
    while (twig.children.length === 0 && attempts < 64) {
      branchingDispatcherSub417F40(twig, rng);
      attempts++;
    }

    const bud = twig.children.find(
      (c) => c.sectionRuntimeType4 === SectionRuntimeType.TreeSectionBud,
    );
    expect(bud).toBeTruthy();
    expect(bud!.useExactLocalTemplateAttachment240).toBe(true);

    const expectedPos = new THREE.Vector3();
    const expectedQuat = new THREE.Quaternion();
    const expectedScale = new THREE.Vector3();
    bud!.localTemplate240.decompose(expectedPos, expectedQuat, expectedScale);
    expect(bud!.group.position.x).toBeCloseTo(expectedPos.x, 6);
    expect(bud!.group.position.y).toBeCloseTo(expectedPos.y, 6);
    expect(bud!.group.position.z).toBeCloseTo(expectedPos.z, 6);
  });
});
