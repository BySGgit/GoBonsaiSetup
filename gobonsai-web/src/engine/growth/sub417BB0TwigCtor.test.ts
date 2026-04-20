import * as THREE from "three";
import { describe, expect, it } from "vitest";
import { MSVCRand } from "../MSVCRand";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { TreeSection } from "../TreeSection";
import { GrowthConstants } from "../config/GrowthConstants";
import { sub417BB0CreateTwig, sub417BB0SampleMaxGrowth } from "./sub417BB0TwigCtor";

describe("sub_417BB0 twig ctor parity", () => {
  it("samples max growth with MSVC-rand formula", () => {
    const rngA = new MSVCRand(12345);
    const rngB = new MSVCRand(12345);
    const minSeg = GrowthConstants.FLT_4D85E8 as number;
    const maxSeg = GrowthConstants.FLT_4D85EC as number;
    const base = (maxSeg - minSeg) * 0.4 + minSeg;
    const expected = base * (rngB.randFloat() * 0.2000000476837158 + 0.8999999761581421);

    const sampled = sub417BB0SampleMaxGrowth(0.4, rngA);
    expect(sampled).toBeCloseTo(expected, 6);
  });

  it("creates twig type with template and yaw/pitch/roll applied", () => {
    const rng = new MSVCRand(7);
    const parent = new TreeSection(null, 0, new MSVCRand(1), 0.2);
    const template = new THREE.Matrix4().makeTranslation(1, 2, 3);

    const twig = sub417BB0CreateTwig(
      template,
      parent,
      1,
      0.5,
      [0.1, 0.0, 0.0],
      0.08,
      rng,
    );

    expect(twig.sectionRuntimeType4).toBe(SectionRuntimeType.TreeSectionTwig);
    expect(twig.growthFlag512).toBe(false);
    expect(twig.energyWeight428).toBe(1);
    expect(twig.localTemplate240.elements).toEqual(template.elements);
    expect(twig.maxGrowth).toBeGreaterThan(0);
    expect(twig.rotationQuaternion.x).toBeCloseTo(twig.targetRotation.x, 6);
    expect(twig.rotationQuaternion.y).toBeCloseTo(twig.targetRotation.y, 6);
    expect(twig.rotationQuaternion.z).toBeCloseTo(twig.targetRotation.z, 6);
    expect(twig.rotationQuaternion.w).toBeCloseTo(twig.targetRotation.w, 6);
  });

  it("can preserve exact local-template attachment mode for continuation twig", () => {
    const rng = new MSVCRand(9);
    const parent = new TreeSection(null, 0, new MSVCRand(1), 0.2);
    const template = new THREE.Matrix4().makeTranslation(0, 0.7, 1.0);

    const twig = sub417BB0CreateTwig(
      template,
      parent,
      1,
      0.5,
      [0.1, 0.0, 0.0],
      0.08,
      rng,
      true,
    );

    expect(twig.useExactLocalTemplateAttachment240).toBe(true);
    expect(twig.localTemplate240.elements).toEqual(template.elements);
  });
});
