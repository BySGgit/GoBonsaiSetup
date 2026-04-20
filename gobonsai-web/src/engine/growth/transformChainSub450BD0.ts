import { TreeSection } from "../TreeSection";
import { Quaternion, Vector3 } from "three";
import {
    growthDebugEnabled,
    growthDebugFrameModulo,
    growthDebugLog,
    growthDebugSectionLabel,
} from "./growthDebug";

/**
 * sub_450BD0 (slot +16) + sub_4146F0 (slot +32): transform chain.
 */

const _tmpLocalPos4146F0 = new Vector3();
const _tmpLocalQuat4146F0 = new Quaternion();
const _tmpLocalScale4146F0 = new Vector3(1, 1, 1);
const _tmpCombinedQuat4146F0 = new Quaternion();
let _transformDebugCounter = 0;

/**
 * Keep scene transforms in sync before metabolism/light passes.
 */
export function syncGroupQuaternionsFromRotationForMetabolism(
    root: TreeSection,
    strictExeSimVisuals = false,
): void {
    const walk = (section: TreeSection): void => {
        if (section.worldDetached188) return;

        if (section.parent) {
            rebuildLocalTransformSub4146F0(section, strictExeSimVisuals);
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
export function rebuildLocalTransformSub4146F0(
    section: TreeSection,
    strictExeSimVisuals = false,
): void {
    if (!section.parent) return;

    section.updateAttachmentPosition(section.parent, strictExeSimVisuals);
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

    if (
        growthDebugEnabled() &&
        section.isContinuation &&
        (section.sectionRuntimeType4 === 10 || section.sectionRuntimeType4 === 6)
    ) {
        _transformDebugCounter++;
        if ((_transformDebugCounter % growthDebugFrameModulo()) === 0) {
            growthDebugLog("transform_rebuild", {
                section: growthDebugSectionLabel(section),
                parent: growthDebugSectionLabel(section.parent),
                exactTemplate: section.useExactLocalTemplateAttachment240,
                localPos: {
                    x: Number(_tmpLocalPos4146F0.x.toFixed(5)),
                    y: Number(_tmpLocalPos4146F0.y.toFixed(5)),
                    z: Number(_tmpLocalPos4146F0.z.toFixed(5)),
                },
                localQuat: {
                    x: Number(_tmpLocalQuat4146F0.x.toFixed(5)),
                    y: Number(_tmpLocalQuat4146F0.y.toFixed(5)),
                    z: Number(_tmpLocalQuat4146F0.z.toFixed(5)),
                    w: Number(_tmpLocalQuat4146F0.w.toFixed(5)),
                },
                sectionQuat: {
                    x: Number(section.rotationQuaternion.x.toFixed(5)),
                    y: Number(section.rotationQuaternion.y.toFixed(5)),
                    z: Number(section.rotationQuaternion.z.toFixed(5)),
                    w: Number(section.rotationQuaternion.w.toFixed(5)),
                },
                combinedQuat: {
                    x: Number(section.group.quaternion.x.toFixed(5)),
                    y: Number(section.group.quaternion.y.toFixed(5)),
                    z: Number(section.group.quaternion.z.toFixed(5)),
                    w: Number(section.group.quaternion.w.toFixed(5)),
                },
                radius444: Number((section.twigRadius444 as number).toFixed(5)),
                length448: Number((section.twigLength448 as number).toFixed(5)),
            });
        }
    }
}

/**
 * Propagate local transforms down the tree, then update world matrices and
 * cache inverse world matrices for light/metabolism calculations.
 */
export function propagateTransformsSub450BD0(
    root: TreeSection,
    strictExeSimVisuals = false,
): void {
    const walk = (section: TreeSection): void => {
        if (section.worldDetached188) return;

        if (section.parent) {
            rebuildLocalTransformSub4146F0(section, strictExeSimVisuals);
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
