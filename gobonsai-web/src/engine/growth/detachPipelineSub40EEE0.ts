import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";

/**
 * sub_40EEE0 — detach pipeline.
 *
 * When a section has markedForDetach236 = true, this pipeline:
 * 1. Removes the section from its parent's children list
 * 2. Transfers it to the world object list (for falling animation)
 * 3. Sets worldDetached188 = true
 *
 * Called from sub_414270 (vtable slot +48) after processing children.
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
 * Process detach flags on the entire tree (sub_414270 equivalent).
 * Post-order: process children first, then check this section.
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

    // Remove from parent's children
    const idx = parent.children.indexOf(section);
    if (idx !== -1) parent.children.splice(idx, 1);

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
    section.parent = null;

    _worldObjects.push(section);
}
