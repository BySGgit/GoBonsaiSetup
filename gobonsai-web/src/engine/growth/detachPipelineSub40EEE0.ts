import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { sub450C80RemoveFromParent } from "./sub450C80";

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
