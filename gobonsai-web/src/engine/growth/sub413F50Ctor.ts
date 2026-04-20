import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { byte4D8225ForSectionType } from "../config/GrowthConstants";
import { TransformService } from "../math/TransformService";
import { Sub416510Rotation } from "../math/Sub416510Rotation";
import { Float32 } from "../math/MathTypes";
import { getSlot36SimulationDay } from "./frameState";

const _identity4x4 = new THREE.Matrix4();

/**
 * sub_413F50 parity-init for newly created sections.
 * Centralizes constructor-side field init used by Bud/Twig chain paths.
 */
export function sub413F50InitSection(
  section: TreeSection,
  parent: TreeSection | null,
  localTemplate: THREE.Matrix4,
  yawPitchRoll: readonly [number, number, number],
): void {
  section.markedForDetach236 = false;

  // sub_413F50: +196..+204 = (0,1,0), +208/+212 = 0,
  // +216..+224 = same basis, +228/+232 = 0.
  section.lightResponseVec.set(0, 1, 0);
  section.smoothedLightA = 0 as Float32;
  section.smoothedLightB = 0 as Float32;
  section.prevDirectionVec.set(0, 1, 0);
  section.smoothTargetA = 0 as Float32;
  section.smoothTargetB = 0 as Float32;

  section.localTemplate240.copy(localTemplate);
  TransformService.rotationYawPitchRoll(
    section.targetRotation,
    yawPitchRoll[0],
    yawPitchRoll[1],
    yawPitchRoll[2],
  );
  section.rotationQuaternion.copy(section.targetRotation);
  section.rotation.copy(section.targetRotation);
  Sub416510Rotation.syncBlob80FromQuaternion(section);

  section.transformMatrix.copy(_identity4x4);

  section.energyProduction420 = 0 as Float32;
  section.energyAccumulator424 = 0 as Float32;
  section.energyWeight428 = 0 as Float32;
  section.sub414CE0SeedBudget428 = 0 as Float32;
  section.energyBudget432 = 0 as Float32;
  section.energySpent436 = 0 as Float32;
  section.energyTickCounter440 = 0 as Float32;
  section.branchBirthSimulationDay = getSlot36SimulationDay() as Float32;
  section.twigRadius444 = 0 as Float32;
  section.twigLength448 = 0 as Float32;
  section.healthEnergy456 = 1 as Float32;
  section.totalWeight460 = 0;
  section.storedMass464 = 0;
  section.centroid468.set(0, 0, 0);
  section.rollupDword480 = 0;
  section.rollupDword484 = 0;
  section.growthFlag512 = false;

  if (parent && byte4D8225ForSectionType(parent.sectionRuntimeType4)) {
    section.lightResponseVec.copy(parent.lightResponseVec);
    section.smoothedLightA = parent.smoothedLightA as Float32;
    section.smoothedLightB = parent.smoothedLightB as Float32;
    section.prevDirectionVec.copy(section.lightResponseVec);
    section.smoothTargetA = section.smoothedLightA as Float32;
    section.smoothTargetB = section.smoothedLightB as Float32;
  }
}

/**
 * Parent-list attach parity from sub_413F50 child insertion path.
 */
export function sub413F50AttachChild(
  parent: TreeSection,
  child: TreeSection,
): void {
  child.parent = parent;
  if (!parent.children.includes(child)) {
    parent.children.push(child);
  }
  if (child.group.parent !== parent.group) {
    parent.group.add(child.group);
  }
}
