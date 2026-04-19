import { TreeSection } from "../TreeSection";
import {
  byte4D8225ForSectionType,
  byte4D8228ForSectionType,
  byte4D8229ForSectionType,
  byte4D822AForSectionType,
} from "../config/GrowthConstants";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { MSVCRand } from "../MSVCRand";
import { sub450C80RemoveFromParent } from "./sub450C80";
import {
  detachImmediatelySub40EEE0,
  markWorldManagedSub401A50,
} from "./detachPipelineSub40EEE0";

/**
 * sub_4154B0:
 * counts children with healthEnergy456 != 0 and type in byte_4D8229/822A sets.
 */
function countActiveBudOrTwigChildrenSub4154B0(section: TreeSection): number {
  let count = 0;
  for (const child of section.children) {
    if ((child.healthEnergy456 as number) === 0.0) continue;
    const t = child.sectionRuntimeType4 | 0;
    if (byte4D822AForSectionType(t) || byte4D8229ForSectionType(t)) count++;
  }
  return count;
}

/**
 * slot +44 for Bud (sub_415ED0):
 * unlink from parent then mark world-managed recursively (quiet detach).
 */
function budQuietDetachSub415ED0(bud: TreeSection): void {
  if (bud.parent) {
    if (sub450C80RemoveFromParent(bud, bud.parent)) {
      if (bud.group.parent) bud.group.parent.remove(bud.group);
    }
    bud.parent = null;
  }
  bud.markedForDetach236 = false;
  markWorldManagedSub401A50(bud);
}

/**
 * slot +44 for TreeSection/Twig/Leaf/Stump (sub_4142B0).
 */
function slot44DetachSub4142B0(section: TreeSection, rng?: MSVCRand): void {
  let current: TreeSection | null = section;

  while (current) {
    let parentCandidate: TreeSection | null = current.parent;
    if (!parentCandidate || !byte4D8225ForSectionType(parentCandidate.sectionRuntimeType4)) {
      parentCandidate = null;
    }

    if (
      !parentCandidate ||
      (parentCandidate.twigRadius444 as number) >= 0.69999999 ||
      countActiveBudOrTwigChildrenSub4154B0(parentCandidate) > 1
    ) {
      break;
    }

    current = parentCandidate;
    if (current && byte4D8228ForSectionType(current.sectionRuntimeType4)) {
      return;
    }
  }

  if (!current) return;
  if (!byte4D8225ForSectionType(current.sectionRuntimeType4)) return;

  if (rng) {
    detachImmediatelySub40EEE0(current, rng);
  } else {
    // Fallback for call sites without RNG: defer to end-of-frame detach pass.
    current.markedForDetach236 = true;
  }
}

/**
 * vtable slot +44 dispatcher for gameplay section types.
 */
export function invokeSlot44ForSection(section: TreeSection, rng?: MSVCRand): void {
  switch (section.sectionRuntimeType4) {
    case SectionRuntimeType.TreeSectionBud:
      budQuietDetachSub415ED0(section);
      break;
    case SectionRuntimeType.TreeSectionSeed:
      // seed vtable slot +44 is nullsub
      break;
    default:
      slot44DetachSub4142B0(section, rng);
      break;
  }
}
