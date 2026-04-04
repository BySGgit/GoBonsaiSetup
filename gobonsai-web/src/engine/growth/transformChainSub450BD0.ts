import { TreeSection } from "../TreeSection";

/**
 * sub_450BD0 (slot +16) + sub_4146F0 (slot +32): transform chain.
 *
 * Three.js handles world matrix propagation natively via updateMatrixWorld().
 * This module adds the C-specific steps:
 * - Rebuild local matrix from rotationQuaternion (+320) × template (+240)
 * - Compute inverse world matrix (+352)
 *
 * In TS, `section.transformMatrix` = inverse(world) как qmemcpy(this+352, v13) в sub_4146F0 (full.c:16819–16825).
 */

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
 *
 * IDA decompile (sub_4146F0): *(float*)(this+296) is temporarily set to
 * parent.twigLength448 × branchPosition for the matrix multiply, then restored.
 * flt_4D63B0 (0.5) is used ONLY for the endpoint midpoint (this+24..+32),
 * NOT for the attachment position.
 */
export function rebuildLocalTransformSub4146F0(section: TreeSection): void {
    if (!section.parent) return;

    section.group.quaternion.copy(section.rotationQuaternion);
    section.updateAttachmentPosition(section.parent);
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
