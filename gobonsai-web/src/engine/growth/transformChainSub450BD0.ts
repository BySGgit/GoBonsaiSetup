import { TreeSection } from "../TreeSection";
import { Quaternion, Vector3 } from "three";

/**
 * sub_450BD0 (slot +16) + sub_4146F0 (slot +32): transform chain.
 */

const _tmpLocalPos4146F0 = new Vector3();
const _tmpLocalQuat4146F0 = new Quaternion();
const _tmpLocalScale4146F0 = new Vector3(1, 1, 1);
const _tmpCombinedQuat4146F0 = new Quaternion();

/**
 * Keep scene transforms in sync before metabolism/light passes.
 */
export function syncGroupQuaternionsFromRotationForMetabolism(
    root: TreeSection,
): void {
    const walk = (section: TreeSection): void => {
        if (section.worldDetached188) return;

        if (section.parent) {
            rebuildLocalTransformSub4146F0(section);
        } else {
            section.group.quaternion.copy(section.rotationQuaternion);
        }

        for (const child of section.children) {
            walk(child);
        }
    };
    walk(root);
}

/**
 * sub_4146F0-style local transform rebuild from +240 template and rotation.
 */
export function rebuildLocalTransformSub4146F0(section: TreeSection): void {
    if (!section.parent) return;

    section.updateAttachmentPosition(section.parent);
    section.localTemplate240.decompose(
        _tmpLocalPos4146F0,
        _tmpLocalQuat4146F0,
        _tmpLocalScale4146F0,
    );
    section.group.position.copy(_tmpLocalPos4146F0);
    _tmpCombinedQuat4146F0.multiplyQuaternions(
        _tmpLocalQuat4146F0,
        section.rotationQuaternion,
    );
    section.group.quaternion.copy(_tmpCombinedQuat4146F0);
    section.group.scale.copy(_tmpLocalScale4146F0);
}

/**
 * Propagate local transforms down the tree, then update world matrices and
 * cache inverse world matrices for light/metabolism calculations.
 */
export function propagateTransformsSub450BD0(root: TreeSection): void {
    const walk = (section: TreeSection): void => {
        if (section.worldDetached188) return;

        if (section.parent) {
            rebuildLocalTransformSub4146F0(section);
        } else {
            section.group.quaternion.copy(section.rotationQuaternion);
        }

        for (const child of section.children) {
            walk(child);
        }
    };
    walk(root);

    root.group.updateMatrixWorld(true);

    const storeInverse = (section: TreeSection): void => {
        if (section.worldDetached188) return;
        section.transformMatrix.copy(section.group.matrixWorld).invert();
        for (const child of section.children) {
            storeInverse(child);
        }
    };
    storeInverse(root);
}
