import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { GrowthConstants, byte4D8226ForSectionType } from "../config/GrowthConstants";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { Float32 } from "../math/MathTypes";

/**
 * sub_40E230 + sub_40E460 — light tracing pipeline.
 *
 * Each frame: pick one leaf from queue, generate a ray (random or direct light),
 * march through the tree collecting hits, updating lightResponseVec (+196..+212)
 * on each intersected section, applying decay through leaves and twigs.
 *
 * Simplified for Three.js: instead of AABB raycast (sub_450E30/sub_450CD0),
 * we do a recursive bounding-sphere test against tree sections.
 */

const DIRECT_LIGHT_PERCENT = 0.5; // flt_4D8CF0 — APPROX default
const LIGHT_DECAY_AMOUNT = 0.4;   // flt_4D62EC
const MAX_HITS = 30;
const RAY_LENGTH = 200.0;

const _tmpVec = new THREE.Vector3();
const _tmpDir = new THREE.Vector3();
const _tmpPos = new THREE.Vector3();
const _hitSections: TreeSection[] = [];
const _hitDistances: number[] = [];

/** Global leaf queue — round-robin through all leaf-type sections */
let _leafQueue: TreeSection[] = [];
let _leafQueueIndex = 0;

export function rebuildLeafQueue(root: TreeSection): void {
    _leafQueue = [];
    _leafQueueIndex = 0;
    const stack: TreeSection[] = [root];
    while (stack.length) {
        const s = stack.pop()!;
        if (s.worldDetached188) continue;
        if (s.sectionRuntimeType4 === SectionRuntimeType.TreeSectionLeaf) {
            _leafQueue.push(s);
        }
        for (const c of s.children) stack.push(c);
    }
}

/**
 * sub_40E0A0 equivalent: service one leaf per tick from the queue.
 * Call once per frame from the pipeline.
 */
export function serviceLightTraceQueue(
    root: TreeSection,
    rng: MSVCRand,
    wind: THREE.Vector3,
): void {
    if (_leafQueue.length === 0) return;

    _leafQueueIndex = _leafQueueIndex % _leafQueue.length;
    const leaf = _leafQueue[_leafQueueIndex];
    _leafQueueIndex++;

    if (leaf.worldDetached188) return;

    // sub_40E230: build ray from leaf position
    const pos = new THREE.Vector3();
    leaf.group.getWorldPosition(pos);

    let dir: THREE.Vector3;
    if (rng.randFloat() < DIRECT_LIGHT_PERCENT) {
        dir = GrowthConstants.LIGHT_VECTOR.clone().normalize();
    } else {
        const pitch = rng.randFloat() * Math.PI * 0.5;
        const yaw = rng.randFloat() * Math.PI * 2;
        dir = new THREE.Vector3(
            Math.sin(pitch) * Math.cos(yaw),
            Math.cos(pitch),
            Math.sin(pitch) * Math.sin(yaw),
        ).normalize();
    }

    // sub_40E460: ray-march
    rayMarchSub40E460(root, pos, dir, 1.0);
}

/**
 * sub_40E460: march a ray through the tree, updating light fields on hit sections.
 */
function rayMarchSub40E460(
    root: TreeSection,
    pos: THREE.Vector3,
    dir: THREE.Vector3,
    initialIntensity: number,
): void {
    // Collect hits by recursive bounding sphere test
    _hitSections.length = 0;
    _hitDistances.length = 0;
    collectHits(root, pos, dir);

    // Sort by distance descending (farthest first, like C)
    const indices = _hitSections.map((_, i) => i);
    indices.sort((a, b) => _hitDistances[b] - _hitDistances[a]);

    let intensity = initialIntensity;

    for (const i of indices) {
        const section = _hitSections[i];

        // 3a: update lightResponseVec
        const rate = (section.smoothedLightA as number + 0.01) * 10.0;
        _tmpVec.copy(dir).multiplyScalar(intensity + 0.01);
        _tmpVec.addScaledVector(section.lightResponseVec, rate);
        if (_tmpVec.lengthSq() > 1e-12) _tmpVec.normalize();
        section.lightResponseVec.copy(_tmpVec);

        // 3b: dot product
        const dot = section.lightResponseVec.dot(dir);
        const x = Math.max(0, Math.min(1, -dot));

        // 3c: update smoothed accumulators
        section.smoothedLightA = ((x * intensity + (section.smoothedLightA as number) * 10.0) / 11.0) as Float32;
        section.smoothedLightB = ((intensity + (section.smoothedLightB as number) * 20.0) / 21.0) as Float32;

        // 3e: decay intensity by section type
        const typeId = section.sectionRuntimeType4;
        if (typeId === SectionRuntimeType.TreeSectionLeaf) {
            // Leaf decay
            _tmpDir.set(0, 1, 0).applyQuaternion(section.group.quaternion).normalize();
            const absDot = Math.abs(_tmpDir.dot(dir));
            intensity *= (1.0 - LIGHT_DECAY_AMOUNT * absDot);
        } else if (typeId === SectionRuntimeType.TreeSectionTwig) {
            // Twig geometric shielding
            const radius = section.twigRadius444 as number;
            const sectionPos = new THREE.Vector3();
            section.group.getWorldPosition(sectionPos);
            const distSq = distancePointToRaySq(sectionPos, pos, dir);
            if (radius * radius > distSq) {
                intensity *= 0.5;
            }
        }

        if (intensity < 0.01) break;
    }
}

/**
 * Recursive hit collection against bounding spheres.
 * Simplified sub_450CD0 equivalent.
 */
function collectHits(
    section: TreeSection,
    rayOrigin: THREE.Vector3,
    rayDir: THREE.Vector3,
): void {
    if (_hitSections.length >= MAX_HITS) return;
    if (section.worldDetached188) return;

    const sectionPos = new THREE.Vector3();
    section.group.getWorldPosition(sectionPos);

    const boundRadius = Math.max(
        section.twigRadius444 as number,
        section.twigLength448 as number * 0.5,
        0.1,
    );
    const distSq = distancePointToRaySq(sectionPos, rayOrigin, rayDir);

    if (distSq < boundRadius * boundRadius * 4) {
        _hitSections.push(section);
        _hitDistances.push(sectionPos.distanceTo(rayOrigin));
    }

    for (const child of section.children) {
        collectHits(child, rayOrigin, rayDir);
    }
}

function distancePointToRaySq(
    point: THREE.Vector3,
    rayOrigin: THREE.Vector3,
    rayDir: THREE.Vector3,
): number {
    _tmpPos.copy(point).sub(rayOrigin);
    const t = _tmpPos.dot(rayDir);
    _tmpPos.copy(rayDir).multiplyScalar(t).add(rayOrigin).sub(point);
    return _tmpPos.lengthSq();
}
