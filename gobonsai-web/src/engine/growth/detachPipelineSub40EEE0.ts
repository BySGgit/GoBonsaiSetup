import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { sub450C80RemoveFromParent } from "./sub450C80";
import { GrowthConstants } from "../config/GrowthConstants";

/**
 * sub_40EEE0 — detach pipeline.
 *
 * When a section has markedForDetach236 = true, this pipeline:
 * 1. Removes the section from its parent's children list
 * 2. Transfers it to the world object list (for falling animation)
 * 3. Sets worldDetached188 = true
 *
 * **sub_414270** (`decompiled/sub_414270.c`, vtable **+48** на `TreeSectionSeed` / Leaf и др.):
 * обход детей `this+168`, на каждом ребёнке `(*(child->vftable+48))(child)`; в конце, если `this+236`,
 * `sub_40EEE0(this)`. У нас массив `children` и тот же пост-обход.
 */

/** Global list of detached sections for world-object animation */
const _worldObjects: TreeSection[] = [];

export function getWorldObjects(): readonly TreeSection[] {
    return _worldObjects;
}

export function clearWorldObjects(): void {
    for (const obj of _worldObjects) {
        if (obj.group.parent) obj.group.parent.remove(obj.group);
    }
    _worldObjects.length = 0;
}

/**
 * Хвост кадра `sub_4130D0`: после второго `vtable+16` (`sub_450BD0`) на сцене — `vtable+48` → `sub_414270`.
 * Post-order: дети, затем отсоединение при `markedForDetach236`.
 */
export function processDetachFlags(root: TreeSection, rng: MSVCRand): void {
    processDetachRecursive(root, rng);
}

/**
 * sub_401A50: sets this+188 and applies sub_401A70 recursive child detach semantics.
 */
export function markWorldManagedSub401A50(section: TreeSection): void {
    section.worldDetached188 = true;
    markChildrenWorldManagedSub401A70(section);
}

/**
 * Helper used by sub_417C90 branch:
 * if childCount==0 -> sub_450C80(this,parent) + (*this+8)(this == sub_401A50).
 */
export function detachFromParentAndMarkWorldManagedSub417C90(
    section: TreeSection,
): void {
    if (section.parent) {
        sub450C80RemoveFromParent(section, section.parent);
    }
    markWorldManagedSub401A50(section);
}

/**
 * Immediate sub_40EEE0 path used by C parity branches (for example in sub_417C90).
 * Keeps the same detach mechanics as deferred flag processing.
 */
export function detachImmediatelySub40EEE0(
    section: TreeSection,
    rng: MSVCRand,
): void {
    if (!section.parent) return;
    detachSection(section, rng);
}

function processDetachRecursive(section: TreeSection, rng: MSVCRand): void {
    // Process children first (iterate backwards to safely remove)
    for (let i = section.children.length - 1; i >= 0; i--) {
        processDetachRecursive(section.children[i], rng);
    }

    if (section.markedForDetach236 && section.parent) {
        detachSection(section, rng);
    }
}

/**
 * sub_40EEE0 core: detach section from parent, transfer to world objects.
 */
function detachSection(section: TreeSection, rng: MSVCRand): void {
    const parent = section.parent;
    if (!parent) return;

    // sub_450C80: unlink from parent list
    if (!sub450C80RemoveFromParent(section, parent)) return;

    // sub_40EEE0 fast path in C when flt_4D526C == 150:
    // no debris/world-object push, only detach + mark world managed.
    if ((GrowthConstants.FLT_4D526C_GAME_SPEED as number) === 150.0) {
        markWorldManagedSub401A50(section);
        section.markedForDetach236 = false;
        return;
    }

    // Keep world position: reparent group to scene root
    const worldPos = new THREE.Vector3();
    section.group.getWorldPosition(worldPos);
    const worldQuat = new THREE.Quaternion();
    section.group.getWorldQuaternion(worldQuat);

    if (section.group.parent) {
        section.group.parent.remove(section.group);
    }

    // Store the world transform as local (it's now a root-level object)
    section.group.position.copy(worldPos);
    section.group.quaternion.copy(worldQuat);

    // Initialize velocity with small random impulse
    section.velocity488.set(
        (rng.randFloat() - 0.5) * 0.2,
        rng.randFloat() * 0.1,
        (rng.randFloat() - 0.5) * 0.2,
    );
    section.angularVelocity500.set(
        (rng.randFloat() - 0.5) * 0.05,
        (rng.randFloat() - 0.5) * 0.05,
        (rng.randFloat() - 0.5) * 0.05,
    );

    section.worldDetached188 = true;
    section.markedForDetach236 = false;

    _worldObjects.push(section);
}

function markChildrenWorldManagedSub401A70(section: TreeSection): void {
    const children = section.children.slice();
    for (const child of children) {
        markWorldManagedSub401A50(child);
        child.parent = null;
    }
    section.children.length = 0;
}
