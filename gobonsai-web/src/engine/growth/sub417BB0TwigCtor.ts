import * as THREE from "three";
import { MSVCRand } from "../MSVCRand";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { TreeSection } from "../TreeSection";
import { GrowthConstants } from "../config/GrowthConstants";
import { sub413F50InitSection } from "./sub413F50Ctor";
import { writeUnifiedBudget428 } from "./sub414CE0";

/**
 * sub_417BB0: max-growth sampling for new twig segment.
 * sub_417bb0
 * C: ((max-min)*a4 + min) * (rand/32767*0.2000000477 + 0.8999999762)
 */
export function sub417BB0SampleMaxGrowth(
  normalizedEnergy: number,
  rng: MSVCRand,
): number {
  const minSeg = GrowthConstants.FLT_4D85E8 as number;
  const maxSeg = GrowthConstants.FLT_4D85EC as number;
  const base = (maxSeg - minSeg) * normalizedEnergy + minSeg;
  return base * (rng.randFloat() * 0.2000000476837158 + 0.8999999761581421);
}

/**
 * sub_417BB0 parity wrapper used by sub_415C10.
 */
export function sub417BB0CreateTwig(
  localTemplate: THREE.Matrix4,
  parent: TreeSection | null,
  level: number,
  normalizedEnergy: number,
  yawPitchRoll: readonly [number, number, number],
  inheritedBaseRadius: number,
  rng: MSVCRand,
): TreeSection {
  const twig = new TreeSection(parent, level, rng, inheritedBaseRadius);
  sub413F50InitSection(
    twig,
    parent,
    localTemplate,
    [yawPitchRoll[0], yawPitchRoll[1], yawPitchRoll[2]],
  );
  twig.sectionRuntimeType4 = SectionRuntimeType.TreeSectionTwig;
  twig.maxGrowth = sub417BB0SampleMaxGrowth(normalizedEnergy, rng);
  writeUnifiedBudget428(twig, 1.0);
  twig.energyAccumulator424 = 1.0;
  twig.growthFlag512 = false;

  return twig;
}
