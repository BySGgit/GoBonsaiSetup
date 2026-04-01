import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { getWorldObjects, clearWorldObjects } from "./detachPipelineSub40EEE0";

/**
 * sub_40F140 — world object pipeline for detached sections.
 *
 * Each frame: for each detached section, apply gravity + wind + noise,
 * update position/rotation, remove when fallen below Y=-100.
 */

const LEAF_GRAVITY = 0.025;
const BRANCH_GRAVITY = 0.1;
const LEAF_WIND_SCALE = 0.09;
const BRANCH_WIND_SCALE = 0.03;
const LEAF_POS_NOISE = 0.12;
const LEAF_ROT_NOISE = 0.05;
const BRANCH_ANGULAR_DAMPING = 0.98;
const VEL_CLAMP = 5.0;
const ANGVEL_CLAMP = 0.2;
const REMOVAL_Y = -100.0;

const _tmpEuler = new THREE.Euler();

/**
 * Call once per frame. Updates all world objects (detached sections).
 * Adds them to the provided scene group so they're visible.
 */
export function updateWorldObjectsSub40F140(
    sceneGroup: THREE.Group,
    wind: THREE.Vector3,
    rng: MSVCRand,
): void {
    const objects = getWorldObjects() as TreeSection[];

    for (let i = objects.length - 1; i >= 0; i--) {
        const section = objects[i];

        // Ensure it's in the scene
        if (!section.group.parent) {
            sceneGroup.add(section.group);
        }

        const isLeaf = section.sectionRuntimeType4 === SectionRuntimeType.TreeSectionLeaf;
        const vel = section.velocity488;
        const angVel = section.angularVelocity500;

        if (isLeaf) {
            vel.y -= LEAF_GRAVITY;
            const randScale = rng.randFloat() * 0.5 + 0.5;
            vel.addScaledVector(wind, LEAF_WIND_SCALE * randScale);
            vel.x += (rng.randFloat() - 0.5) * LEAF_POS_NOISE * 2;
            vel.y += (rng.randFloat() - 0.5) * LEAF_POS_NOISE * 2;
            vel.z += (rng.randFloat() - 0.5) * LEAF_POS_NOISE * 2;
            angVel.x += (rng.randFloat() - 0.5) * LEAF_ROT_NOISE * 2;
            angVel.y += (rng.randFloat() - 0.5) * LEAF_ROT_NOISE * 2;
            angVel.z += (rng.randFloat() - 0.5) * LEAF_ROT_NOISE * 2;
        } else {
            vel.y -= BRANCH_GRAVITY;
            vel.addScaledVector(wind, BRANCH_WIND_SCALE);
            angVel.multiplyScalar(BRANCH_ANGULAR_DAMPING);
        }

        // Clamp
        vel.x = Math.max(-VEL_CLAMP, Math.min(VEL_CLAMP, vel.x));
        vel.y = Math.max(-VEL_CLAMP, Math.min(VEL_CLAMP, vel.y));
        vel.z = Math.max(-VEL_CLAMP, Math.min(VEL_CLAMP, vel.z));
        angVel.x = Math.max(-ANGVEL_CLAMP, Math.min(ANGVEL_CLAMP, angVel.x));
        angVel.y = Math.max(-ANGVEL_CLAMP, Math.min(ANGVEL_CLAMP, angVel.y));
        angVel.z = Math.max(-ANGVEL_CLAMP, Math.min(ANGVEL_CLAMP, angVel.z));

        // Update position
        section.group.position.add(vel);

        // Update rotation
        _tmpEuler.set(angVel.x, angVel.y, angVel.z, 'YXZ');
        section.group.quaternion.multiply(
            new THREE.Quaternion().setFromEuler(_tmpEuler),
        );

        // Remove if fallen below threshold
        if (section.group.position.y < REMOVAL_Y) {
            if (section.group.parent) section.group.parent.remove(section.group);
            objects.splice(i, 1);
        }
    }
}
