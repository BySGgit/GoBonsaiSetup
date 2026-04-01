import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { GrowthConstants } from "../config/GrowthConstants";

/**
 * sub_450BD0 (slot +16) + sub_4146F0 (slot +32): transform chain.
 *
 * Three.js handles world matrix propagation natively via updateMatrixWorld().
 * This module adds the C-specific steps:
 * - Rebuild local matrix from targetQuat (+320) × template (+240)
 * - Compute inverse world matrix (+352)
 * - Compute section endpoint world position (+24..+32)
 *
 * In TS, we map these to Three.js Object3D quaternion/position and store
 * the inverse separately in section.transformMatrix.
 */

const _tmpMat = new THREE.Matrix4();
const _tmpVec = new THREE.Vector3();

/**
 * После virtual slot +36 (slerp +320→+304 в sub_417C90 и т.д.), до sub_416510:
 * в exe мировая матрица уже отражает текущий кватернион; в TS `group` иначе обновляется
 * только в `TreeSection.update` в конце кадра — свет/метаболизм видели бы старую ориентацию.
 */
export function syncGroupQuaternionsFromRotationForMetabolism(root: TreeSection): void {
    const walk = (section: TreeSection): void => {
        if (section.worldDetached188) return;
        section.group.quaternion.copy(section.rotationQuaternion);
        for (const child of section.children) {
            walk(child);
        }
    };
    walk(root);
}

/**
 * sub_4146F0 equivalent: rebuild section's local transform from quaternion.
 * Call before updateMatrixWorld to ensure the local matrix reflects
 * the current targetQuat/rotationQuaternion.
 */
export function rebuildLocalTransformSub4146F0(section: TreeSection): void {
    if (!section.parent) return;

    // Apply the current rotation quaternion to the Object3D
    section.group.quaternion.copy(section.rotationQuaternion);

    // Position: along parent's Y axis based on branchPosition * parent twig length
    const parentLength = section.parent.twigLength448 as number;
    const attachY = parentLength * (section.branchPosition as number)
        * GrowthConstants.FLT_4D63B0 as number;
    section.group.position.set(0, Math.max(0, attachY), 0);
}

/**
 * Propagate local transforms down the tree, then call Three.js updateMatrixWorld.
 * After that, store inverse world matrices for light/metabolism calculations.
 */
export function propagateTransformsSub450BD0(root: TreeSection): void {
    const walk = (section: TreeSection): void => {
        if (section.worldDetached188) return;

        rebuildLocalTransformSub4146F0(section);

        for (const child of section.children) {
            walk(child);
        }
    };
    walk(root);

    // Let Three.js propagate world matrices
    root.group.updateMatrixWorld(true);

    // Store inverse world matrices for sub_416510 etc.
    const storeInverse = (section: TreeSection): void => {
        if (section.worldDetached188) return;
        section.transformMatrix.copy(section.group.matrixWorld).invert();
        for (const child of section.children) {
            storeInverse(child);
        }
    };
    storeInverse(root);
}
