import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { Float32 } from "../math/MathTypes";
import {
  GrowthConstants,
  byte4D822AForSectionType,
  byte4D8225ForSectionType,
} from "../config/GrowthConstants";
import { TransformService } from "../math/TransformService";
import { Sub416510Rotation } from "../math/Sub416510Rotation";
import { twigUpdateSub417C90 } from "./twigUpdateSub417C90";

/**
 * Виртуальный слот +36 по типу секции (spec_update_growth_sub_40DC90 §2.5).
 * sub_414E10.c: для каждого ребёнка после child+432 вызывается (*child+36)(child).
 *
 * C pattern: each type's +36 slot calls sub_414E10 (distribute+recurse), then type-specific post-work.
 * TS equivalent: runVirtualSlot36Tree distributes budget & recurses, then dispatches by type.
 */

/** sub_417440.c — нет детей, this+432 > 0 → первая почка. */
export function maybeSeedSpawnSub417440(
  seed: TreeSection,
  rng: MSVCRand | undefined,
): void {
  if (seed.worldDetached188) return;
  if (seed.children.length !== 0) return;
  if ((seed.energyBudget432 as number) <= 0.0) return;
  if (!rng) return;
  const v4 = rng.randFloat() * 0.1599999964237213 - 0.07999999821186066;
  const v3 = rng.randFloat() * 0.1599999964237213 - 0.07999999821186066;
  TreeSection.createBudFromSeed(seed, rng, v4, v3);
}

function skipDetached(section: TreeSection): boolean {
  return section.worldDetached188;
}

/**
 * sub_416300: filter by byte_4D822A (Twig type check).
 * Returns section if it's a registered Twig type, null otherwise.
 */
function sub416300FilterTwig(section: TreeSection | null): TreeSection | null {
  if (!section) return null;
  return byte4D822AForSectionType(section.sectionRuntimeType4) ? section : null;
}

/**
 * Полный обход «слот +36» от узла вниз: как цепочка (*child+36) внутри sub_414E10.
 * Порядок: distribute budget → recurse children → type-specific post-dispatch.
 */
export function runVirtualSlot36Tree(
  root: TreeSection,
  rng: MSVCRand | undefined,
): void {
  const visit = (section: TreeSection): void => {
    if (skipDetached(section)) return;

    if (section.sectionRuntimeType4 === SectionRuntimeType.TreeSectionSeed) {
      maybeSeedSpawnSub417440(section, rng);
    }

    const children = section.children;
    const n = children.length;
    if (n === 0) {
      postDispatchByType(section, rng);
      return;
    }

    let v10 = 0;
    for (const c of children) {
      if (!skipDetached(c)) v10 += c.energyWeight428 as number;
    }
    for (const c of children) {
      if (skipDetached(c)) {
        c.energyBudget432 = 0 as Float32;
        continue;
      }
      const share = v10 <= 0 ? 1.0 / n : (c.energyWeight428 as number) / v10;
      c.energyBudget432 = (share *
        (section.energyBudget432 as number)) as Float32;
      visit(c);
    }

    // C: sub_414E10 post-order rollup runs BEFORE the parent's type-specific code.
    // Aggregate children's +420/+436 so the parent can read them (e.g. twig girth growth).
    let sum420 = 0;
    let sum436 = 0;
    for (const c of children) {
      if (!skipDetached(c)) {
        sum420 += c.energyProduction420 as number;
        sum436 += c.energySpent436 as number;
      }
    }
    section.energyProduction420 = sum420 as Float32;
    section.energySpent436 = sum436 as Float32;

    postDispatchByType(section, rng);
  };
  visit(root);
}

/**
 * Type-specific post-dispatch after sub_414E10 energy distribution.
 * C: each type's vtable +36 slot calls sub_414E10 then does its work.
 */
function postDispatchByType(
  section: TreeSection,
  rng: MSVCRand | undefined,
): void {
  switch (section.sectionRuntimeType4) {
    case SectionRuntimeType.TreeSectionBud:
      budAfterSub414E10From415EF0(section, rng);
      break;
    case SectionRuntimeType.TreeSectionTwig:
      twigUpdateSub417C90(section, rng);
      break;
    case SectionRuntimeType.TreeSectionLeaf:
      leafProductionInSlot36(section, rng);
      break;
  }
}

/**
 * Simplified sub_416510 leaf metabolism within the slot-36 dispatch.
 * Sets energyProduction420 (from growthRate * light * energy * leafProd)
 * and increments growthRate towards maxGrowth (§7 of sub_416510).
 *
 * Energy drain is handled separately by MetabolismService to avoid double-drain.
 * lastLightFactor comes from the previous frame (MetabolismService hasn't run yet).
 */
function leafProductionInSlot36(
  section: TreeSection,
  rng: MSVCRand | undefined,
): void {
  const v34 = Math.max(0, Math.min(1, section.lastLightFactor as number));
  const energyVal = section.energy as number;
  const leafProd = GrowthConstants.FLT_4D8634 as number;
  const c4 = GrowthConstants.FLT_4D63C4 as number;
  let gr = section.growthRate as number;

  // §7: grow growthRate towards maxGrowth when headroom exists
  const maxG = section.maxGrowth as number;
  if (maxG > gr && rng) {
    const v27 = v34 * c4;
    const increment = (rng.randFloat() * 0.5 + 0.5) * (energyVal * v27);
    gr = Math.min(gr + increment, maxG);
    section.growthRate = gr as Float32;
    section.growthTarget = (gr + gr) as Float32;
  }

  // §6: production +420
  const v16 = gr * v34;
  section.energyProduction420 = (v16 * v34 * energyVal * leafProd) as Float32;
}

// ─── sub_415EF0: Bud +36 post-dispatch ─────────────────────────────

/**
 * sub_415EF0.c: after sub_414E10(this), check if bud should convert to twig.
 * baseGrowth (+108) == 0 → dead bud → mark detach.
 * Otherwise normalize energy and check for active twig child.
 */
function budAfterSub414E10From415EF0(
  bud: TreeSection,
  rng: MSVCRand | undefined,
): void {
  if ((bud.baseGrowth as number) === 0.0) {
    bud.markedForDetach236 = true;
    return;
  }

  const minE = GrowthConstants.FLT_4D862C as number;
  const maxE = GrowthConstants.FLT_4D8630 as number;
  const v7 = Math.max(
    0,
    Math.min(1, ((bud.baseGrowth as number) - minE) / (maxE - minE)),
  );

  // C uses *(this+168) = HEAD of linked list (most recently prepended child).
  // TS uses push() (append), so the newest child is children[last].
  const newestChild = bud.children.length > 0
    ? bud.children[bud.children.length - 1]
    : null;
  const activeTwig = sub416300FilterTwig(newestChild);

  if (activeTwig === null || !activeTwig.growthFlag512) {
    sub415C10ConvertBudToTwig(bud, v7, rng);
  }
}

// ─── sub_415C10: Bud → Twig conversion ─────────────────────────────

/**
 * sub_415C10.c: create TreeSectionTwig from Bud.
 * a1 = bud, a2 = normalized energy [0..1].
 */
function sub415C10ConvertBudToTwig(
  bud: TreeSection,
  normalizedEnergy: number,
  rng: MSVCRand | undefined,
): number {
  if (!rng) return 0;

  // Early exit: frequency control via parent filter
  const parent = bud.parent;
  let v4: TreeSection | null = null;
  if (parent) {
    v4 = byte4D8225ForSectionType(parent.sectionRuntimeType4) ? parent : null;
  }
  if (v4 !== null) {
    if (bud.leafCount516 > 2) {
      v4.markedForDetach236 = true;
      return 0;
    }
  }

  // Create TreeSectionTwig
  const yawJitter = rng.randFloat() * 0.1 - 0.05;

  const minSeg = GrowthConstants.FLT_4D85E8 as number;
  const maxSeg = GrowthConstants.FLT_4D85EC as number;
  const randomScale = rng.randFloat() * 0.2 + 0.9;
  const maxSegSize =
    (minSeg + (maxSeg - minSeg) * normalizedEnergy) * randomScale;

  const newTwig = new TreeSection(
    bud,
    bud.level + 1,
    rng,
    GrowthConstants.FLT_4D861C_INITIAL_TWIG_GIRTH as number,
  );
  newTwig.sectionRuntimeType4 = SectionRuntimeType.TreeSectionTwig;

  TransformService.rotationYawPitchRoll(
    newTwig.targetRotation,
    yawJitter,
    0,
    0,
  );
  newTwig.rotationQuaternion.copy(newTwig.targetRotation);
  newTwig.rotation.copy(newTwig.targetRotation);
  Sub416510Rotation.syncBlob80FromQuaternion(newTwig);

  newTwig.twigRadius444 = GrowthConstants.FLT_4D861C_INITIAL_TWIG_GIRTH;
  newTwig.twigLength448 = 0 as Float32;
  newTwig.maxGrowth = maxSegSize as Float32;
  newTwig.energyWeight428 = 1.0 as Float32;

  // Copy energy fields from bud
  newTwig.energyProduction420 = bud.energyProduction420;
  newTwig.energyAccumulator424 = bud.energyAccumulator424;

  newTwig.growthFlag512 = true;

  bud.children.push(newTwig);
  newTwig.updateAttachmentPosition(bud);

  // Reset quaternion to identity on twig (sub_415C10: dword_4D53A4..B0)
  newTwig.prevData0 = 0;
  newTwig.prevData1 = 0;
  newTwig.prevData2 = 0;

  // Spawn 2 leaves
  sub415AB0SpawnLeaves(bud, normalizedEnergy, rng);

  return 1;
}

// ─── sub_415AB0: spawn 2 symmetric leaves at bud→twig conversion ───

function sub415AB0SpawnLeaves(
  bud: TreeSection,
  normalizedEnergy: number,
  rng: MSVCRand,
): void {
  const angleIncrement = (rng.randFloat() * 0.2 + 0.9) * (Math.PI / 2);
  bud.leafSpawnAngle += angleIncrement;
  bud.leafSpawnAngle = bud.leafSpawnAngle % (2 * Math.PI);

  const angle = bud.leafSpawnAngle;
  const dirX = Math.sin(angle);
  const dirZ = Math.cos(angle);

  const twigChild =
    bud.children.length > 0 ? bud.children[bud.children.length - 1] : bud;

  createLeafSection(twigChild, normalizedEnergy, dirX, 0, dirZ, rng);
  createLeafSection(twigChild, normalizedEnergy, -dirX, 0, -dirZ, rng);

  bud.leafCount516++;
}

/**
 * sub_4163B0: create TreeSectionLeaf child.
 * type=7, maxLeafSize from energy param, energyWeight=0.
 */
function createLeafSection(
  parentTwig: TreeSection,
  normalizedEnergy: number,
  dirX: number,
  dirY: number,
  dirZ: number,
  rng: MSVCRand,
): TreeSection {
  const minLeaf = GrowthConstants.FLT_4D85F0 as number;
  const maxLeaf = GrowthConstants.FLT_4D85F4 as number;
  const randomScale = rng.randFloat() * 0.2 + 0.9;
  const maxLeafSize =
    (minLeaf + (maxLeaf - minLeaf) * normalizedEnergy) * randomScale;

  const leaf = new TreeSection(parentTwig, parentTwig.level + 1, rng, 0.01);
  leaf.sectionRuntimeType4 = SectionRuntimeType.TreeSectionLeaf;
  leaf.maxGrowth = maxLeafSize as Float32;
  leaf.energyWeight428 = 0 as Float32;

  const yaw = Math.atan2(dirX, dirZ);
  const pitch = dirY;
  TransformService.rotationYawPitchRoll(leaf.targetRotation, yaw, pitch, 0);
  leaf.rotationQuaternion.copy(leaf.targetRotation);
  leaf.rotation.copy(leaf.targetRotation);
  Sub416510Rotation.syncBlob80FromQuaternion(leaf);

  parentTwig.children.push(leaf);
  leaf.updateAttachmentPosition(parentTwig);
  return leaf;
}

/** Один узел как корень поддерева — для тестов и внешних вызовов. */
export function dispatchVirtualSlot36(
  section: TreeSection,
  rng: MSVCRand | undefined,
): void {
  runVirtualSlot36Tree(section, rng);
}
