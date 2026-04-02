import * as THREE from "three";
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
  worldFlagByte220 = false,
): void {
  const visit = (section: TreeSection): void => {
    if (skipDetached(section)) return;

    if (section.sectionRuntimeType4 === SectionRuntimeType.TreeSectionSeed) {
      maybeSeedSpawnSub417440(section, rng);
    }

    const children = section.children;
    const n = children.length;
    if (n === 0) {
      postDispatchByType(section, rng, worldFlagByte220);
      return;
    }

    let v10 = 0;
    for (const c of children) {
      if (!skipDetached(c)) v10 += c.energyWeight428 as number;
    }

    // Snapshot: child handlers may mutate the array (budQuietDetachSub415ED0,
    // sub415C10ConvertBudToTwig). EXE's linked-list advances pointer before
    // calling the handler; TS needs a shallow copy for the same safety.
    const snap = children.slice();
    for (const c of snap) {
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
    for (const c of section.children) {
      if (!skipDetached(c)) {
        sum420 += c.energyProduction420 as number;
        sum436 += c.energySpent436 as number;
      }
    }
    section.energyProduction420 = sum420 as Float32;
    section.energySpent436 = sum436 as Float32;

    postDispatchByType(section, rng, worldFlagByte220);
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
  worldFlagByte220: boolean,
): void {
  switch (section.sectionRuntimeType4) {
    case SectionRuntimeType.TreeSectionBud:
      budAfterSub414E10From415EF0(section, rng, worldFlagByte220);
      break;
    case SectionRuntimeType.TreeSectionTwig:
      twigUpdateSub417C90(section, rng);
      break;
    case SectionRuntimeType.TreeSectionLeaf:
      // sub_416510 для листьев выполняется в MetabolismService.processLeafMetabolism (после matrixWorld).
      break;
  }
}

// ─── sub_415ED0: bud quiet detach (vtable+44 for buds) ──────────────
/**
 * EXE sub_415ED0: when budget == 0 (winter), the bud and its entire subtree
 * are quietly orphaned — NOT the falling-animation markedForDetach236 path.
 *
 * Flow: sub_450C80 (remove from parent) → sub_401A50 (set worldDetached188=1)
 *       → sub_401A70 (recursively worldDetach + orphan all children).
 */
function budQuietDetachSub415ED0(bud: TreeSection): void {
  if (bud.parent) {
    const idx = bud.parent.children.indexOf(bud);
    if (idx !== -1) bud.parent.children.splice(idx, 1);
    if (bud.group.parent) bud.group.parent.remove(bud.group);
    bud.parent = null;
  }
  markWorldDetachedRecursive(bud);
}

function markWorldDetachedRecursive(section: TreeSection): void {
  section.worldDetached188 = true;
  for (const child of section.children) {
    markWorldDetachedRecursive(child);
    child.parent = null;
  }
  section.children.length = 0;
}

// ─── sub_415EF0: Bud +36 post-dispatch ─────────────────────────────

/**
 * sub_415EF0.c: after sub_414E10(this), check if bud should convert to twig.
 *
 * EXE flow (decompiled sub_415EF0):
 *   1. *(this+108)==0 → sub_415ED0 (quiet detach, NOT markedForDetach236).
 *   2. *(this+120) = 1 (rollupDword480).
 *   3. if maxGrowth(+113) <= twigRadius(+111):
 *        girth reached max → normalize budget, check PARENT twig,
 *        spawn new twig if parent is not growing.
 *   4. else: grow girth: twigRadius += min(maxE, budget) * flt_4D8620.
 *
 * Chain model (EXE): [seed] → [twig1] → [twig2] → ... → [bud]
 * The bud is always at the tip. sub_416300 checks the bud's PARENT (the last
 * twig in the chain). When it finishes growing → spawn next continuation twig.
 */
function budAfterSub414E10From415EF0(
  bud: TreeSection,
  rng: MSVCRand | undefined,
  worldFlagByte220: boolean,
): void {
  const budget = bud.energyBudget432 as number;

  if (budget === 0.0) {
    budQuietDetachSub415ED0(bud);
    return;
  }

  const twigRadius = bud.twigRadius444 as number;
  const maxGrowth = bud.maxGrowth as number;

  bud.rollupDword480 = 1;

  if (maxGrowth <= twigRadius) {
    // §3: girth reached max → check for twig spawning
    const minE = GrowthConstants.FLT_4D862C as number;
    const maxE = GrowthConstants.FLT_4D8630 as number;
    const v7 = Math.max(
      0,
      Math.min(1, (budget - minE) / (maxE - minE)),
    );

    // sub_416300: check bud's PARENT — in chain model the parent twig gates spawning
    const parentSection = bud.parent;
    const activeParentTwig = parentSection
      ? (byte4D822AForSectionType(parentSection.sectionRuntimeType4) ? parentSection : null)
      : null;

    if (activeParentTwig === null || !activeParentTwig.growthFlag512) {
      sub415C10ConvertBudToTwig(bud, v7, rng, worldFlagByte220);
    }
  } else {
    // §4: girth still growing — sub_415EF0.c else-branch
    const maxE = GrowthConstants.FLT_4D8630 as number;
    const growRate = GrowthConstants.FLT_4D8620 as number;
    const capped = maxE <= budget ? maxE : budget;
    let newRadius = twigRadius + capped * growRate;
    if (maxGrowth <= newRadius) {
      newRadius = maxGrowth;
    }
    if (newRadius < 0) newRadius = 0;
    bud.twigRadius444 = newRadius as Float32;
  }
}

// ─── sub_415C10: Bud → Twig conversion (chain model) ────────────────

/**
 * sub_415C10.c: create continuation twig and re-parent bud.
 *
 * EXE chain model:
 *   Before: [parent] → [bud]
 *   After:  [parent] → [newTwig] → [bud]
 *
 * The new twig takes the bud's place in the parent's child list.
 * The bud becomes a child of the new twig (always at the chain tip).
 * Quaternion of the new twig = combined twig*bud rotation.
 * Bud's quaternion is reset to identity for the next growth phase.
 */
function sub415C10ConvertBudToTwig(
  bud: TreeSection,
  normalizedEnergy: number,
  rng: MSVCRand | undefined,
  worldFlagByte220: boolean,
): number {
  if (!rng) return 0;

  const budParent = bud.parent;

  // sub_413CF0: check if parent is a registered twig-like type
  let v4: TreeSection | null = null;
  if (budParent) {
    v4 = byte4D8225ForSectionType(budParent.sectionRuntimeType4) ? budParent : null;
  }

  // Early exit: world flag + leafCount > 2 + parent is valid twig → kill parent
  if (v4 !== null && worldFlagByte220 && bud.leafCount516 > 2) {
    v4.markedForDetach236 = true;
    return 0;
  }

  // ── Step 1: Remove bud from its current parent's children ──
  if (budParent) {
    const idx = budParent.children.indexOf(bud);
    if (idx !== -1) budParent.children.splice(idx, 1);
    if (bud.group.parent) bud.group.parent.remove(bud.group);
    bud.parent = null;
  }

  // ── Step 2: Create new twig as child of bud's former parent ──
  const yawJitter = rng.randFloat() * 0.1 - 0.05;

  const minSeg = GrowthConstants.FLT_4D85E8 as number;
  const maxSeg = GrowthConstants.FLT_4D85EC as number;
  const randomScale = rng.randFloat() * 0.2 + 0.9;
  const maxSegSize =
    (minSeg + (maxSeg - minSeg) * normalizedEnergy) * randomScale;

  const newTwig = new TreeSection(
    budParent,
    bud.level,
    rng,
    GrowthConstants.FLT_4D861C_INITIAL_TWIG_GIRTH as number,
  );
  newTwig.sectionRuntimeType4 = SectionRuntimeType.TreeSectionTwig;

  // sub_417BB0: initial yaw jitter rotation
  TransformService.rotationYawPitchRoll(
    newTwig.targetRotation,
    yawJitter,
    0,
    0,
  );

  newTwig.twigRadius444 = GrowthConstants.FLT_4D861C_INITIAL_TWIG_GIRTH;
  newTwig.twigLength448 = 0 as Float32;
  newTwig.maxGrowth = maxSegSize as Float32;
  newTwig.energyWeight428 = 1.0 as Float32;
  newTwig.growthFlag512 = true;

  // Add twig to budParent's scene graph and child list
  if (budParent) {
    budParent.children.push(newTwig);
    budParent.group.add(newTwig.group);
    newTwig.updateAttachmentPosition(budParent);
  }

  // ── Step 3: Add bud as child of new twig ──
  newTwig.children.push(bud);
  bud.parent = newTwig;
  newTwig.group.add(bud.group);
  bud.updateAttachmentPosition(newTwig);

  // ── Step 4: Combined quaternion — D3DXQuaternionMultiply(result, twig, bud) ──
  const combinedQuat = _tmpQuat.multiplyQuaternions(
    newTwig.targetRotation,
    bud.rotationQuaternion,
  );
  newTwig.rotationQuaternion.copy(combinedQuat);
  newTwig.rotation.copy(combinedQuat);
  newTwig.targetRotation.copy(combinedQuat);
  Sub416510Rotation.syncBlob80FromQuaternion(newTwig);

  // ── Step 5: Copy energy fields from bud to twig ──
  newTwig.energyProduction420 = bud.energyProduction420;
  newTwig.energyAccumulator424 = bud.energyAccumulator424;

  // ── Step 6: Reset bud's quaternion to identity ──
  bud.rotationQuaternion.identity();
  bud.rotation.identity();
  bud.targetRotation.identity();
  Sub416510Rotation.syncBlob80FromQuaternion(bud);

  // sub_415C10: *(v3+296) = 1.0; *(a1+296) = 1.0
  newTwig.meshScalar36 = 1.0 as Float32;

  // ── Step 7: Spawn 2 symmetric leaves on the new twig ──
  sub415AB0SpawnLeaves(bud, newTwig, normalizedEnergy, rng);

  return 1;
}

const _tmpQuat = new THREE.Quaternion();

// ─── sub_415AB0: spawn 2 symmetric leaves at bud→twig conversion ───

/**
 * sub_415AB0.c: a1 (ESI) = bud, a2 = normalizedEnergy.
 * Leaves are created as children of the newly created twig (bud's parent
 * in the chain model). The bud tracks the leaf angle and count.
 */
function sub415AB0SpawnLeaves(
  bud: TreeSection,
  parentTwig: TreeSection,
  normalizedEnergy: number,
  rng: MSVCRand,
): void {
  const angleIncrement = (rng.randFloat() * 0.2 + 0.9) * (Math.PI / 2);
  bud.leafSpawnAngle += angleIncrement;
  if (bud.leafSpawnAngle > 2 * Math.PI) {
    bud.leafSpawnAngle -= 2 * Math.PI;
  }

  const angle = bud.leafSpawnAngle;
  const dirX = Math.sin(angle);
  const dirZ = Math.cos(angle);

  createLeafSection(parentTwig, normalizedEnergy, dirX, 0, dirZ, rng);
  createLeafSection(parentTwig, normalizedEnergy, -dirX, 0, -dirZ, rng);

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
  worldFlagByte220 = false,
): void {
  runVirtualSlot36Tree(section, rng, worldFlagByte220);
}
