import * as THREE from "three";
import { describe, expect, it } from "vitest";
import { MSVCRand } from "../MSVCRand";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { TreeSection } from "../TreeSection";
import { GrowthConstants } from "../config/GrowthConstants";
import { sub413F50AttachChild, sub413F50InitSection } from "./sub413F50Ctor";

describe("sub_413F50 ctor parity helpers", () => {
  it("initializes template/quat and resets runtime accumulators", () => {
    const section = new TreeSection(null, 0, new MSVCRand(1), 0.1);
    section.energyProduction420 = 3;
    section.energySpent436 = 2;
    const template = new THREE.Matrix4().makeTranslation(2, 3, 4);

    sub413F50InitSection(section, null, template, [0.2, 0.0, -0.1]);

    expect(section.localTemplate240.elements).toEqual(template.elements);
    expect(section.energyProduction420).toBe(0);
    expect(section.energySpent436).toBe(0);
    expect(section.healthEnergy456).toBe(1);
    expect(section.transformMatrix.elements).toEqual(new THREE.Matrix4().elements);
    expect(section.lightResponseVec.x).toBe(0);
    expect(section.lightResponseVec.y).toBe(1);
    expect(section.lightResponseVec.z).toBe(0);
    expect(section.smoothedLightA).toBe(0);
    expect(section.smoothedLightB).toBe(0);
    expect(section.smoothTargetA).toBe(0);
    expect(section.smoothTargetB).toBe(0);
  });

  it("copies light response from parent when byte_4D8225 is set", () => {
    GrowthConstants.BYTE_4D8225_STRIDE11[11 * SectionRuntimeType.TreeSectionTwig] = 1;
    const parent = new TreeSection(null, 0, new MSVCRand(2), 0.2);
    parent.sectionRuntimeType4 = SectionRuntimeType.TreeSectionTwig;
    parent.lightResponseVec.set(0.4, 0.5, 0.6);
    parent.smoothedLightA = 0.7;
    parent.smoothedLightB = 0.8;

    const child = new TreeSection(null, 1, new MSVCRand(3), 0.1);
    sub413F50InitSection(child, parent, new THREE.Matrix4(), [0, 0, 0]);

    expect(child.lightResponseVec.x).toBeCloseTo(0.4, 6);
    expect(child.lightResponseVec.y).toBeCloseTo(0.5, 6);
    expect(child.lightResponseVec.z).toBeCloseTo(0.6, 6);
    expect(child.smoothedLightA).toBeCloseTo(0.7, 6);
    expect(child.smoothedLightB).toBeCloseTo(0.8, 6);
  });

  it("attaches child once and syncs scene parent", () => {
    const parent = new TreeSection(null, 0, new MSVCRand(10), 0.2);
    const child = new TreeSection(null, 1, new MSVCRand(11), 0.1);

    sub413F50AttachChild(parent, child);
    sub413F50AttachChild(parent, child);

    expect(parent.children.length).toBe(1);
    expect(parent.children[0]).toBe(child);
    expect(child.parent).toBe(parent);
    expect(child.group.parent).toBe(parent.group);
  });
});
