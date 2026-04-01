import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { GrowthConstants } from "../config/GrowthConstants";
import { MSVCRand } from "../MSVCRand";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { SectionColorService } from "../SectionColorService";
import { Float32 } from "../math/MathTypes";

/**
 * sub_416510 — leaf metabolism: light → energy → production → growth.
 *
 * For TreeSectionLeaf (type 7), this replaces the generic MetabolismService logic
 * with the precise C formulas for v34, energy drain, production +420, and growth +111.
 *
 * For non-leaf types, the existing MetabolismService is still used.
 */

const _inv = new THREE.Matrix4();
const _localUp = new THREE.Vector3(0, 1, 0);
const _lightLocal = new THREE.Vector3();

/**
 * Process leaf-specific metabolism for all leaf sections in the tree.
 * Call from the GrowthFramePipeline after energy distribution.
 */
export function processLeafMetabolism(
    root: TreeSection,
    lightDirection: THREE.Vector3,
    rng: MSVCRand,
    treeAge: number,
): void {
    const stack: TreeSection[] = [root];
    while (stack.length) {
        const section = stack.pop()!;
        if (section.worldDetached188) continue;

        if (section.sectionRuntimeType4 === SectionRuntimeType.TreeSectionLeaf) {
            updateLeafSub416510(section, lightDirection, rng, treeAge);
        }

        for (const child of section.children) stack.push(child);
    }
}

/**
 * sub_416510 core logic for a single leaf section.
 */
function updateLeafSub416510(
    section: TreeSection,
    lightDirection: THREE.Vector3,
    rng: MSVCRand,
    treeAge: number,
): void {
    const b4 = GrowthConstants.FLT_4D63B4 as number;
    const b8 = GrowthConstants.FLT_4D63B8 as number;
    const bC = GrowthConstants.FLT_4D63BC as number;
    const c4 = GrowthConstants.FLT_4D63C4 as number;
    const leafProd = GrowthConstants.FLT_4D8634 as number;

    // §2: compute v34 (light factor)
    _inv.copy(section.group.matrixWorld).invert();
    _lightLocal.copy(lightDirection).applyMatrix4(_inv).normalize();

    const v21 = _localUp.x * _lightLocal.x + _localUp.y * _lightLocal.y + _localUp.z * _lightLocal.z;
    const v22 = Math.abs(v21);

    let v34 = (section.metabolismLightScale as number) * v22
        + (section.metabolismLightOffset as number) * 0.5;
    v34 = Math.max(0, Math.min(1, v34));
    section.lastLightFactor = v34 as Float32;

    // §3: update energy (+114)
    // Parent budget check
    if (section.parent) {
        const parentBudget = section.parent.energyBudget432 as number;
        if (parentBudget <= 0.01) {
            const drain = rng.randFloat() * 0.025 * (1.0 - parentBudget / 0.01);
            section.energy = Math.max(0, (section.energy as number) - drain) as Float32;
        }
    }

    // Maintenance cost as function of light
    let v24 = (v34 - b4) / (0.0 - b4);
    v24 = Math.max(0, Math.min(1, v24));
    section.energy = Math.max(0, Math.min(1,
        (section.energy as number) - v24 * b8)) as Float32;

    // §4: death/skip check
    const energyVal = section.energy as number;
    if (energyVal === 0 || (1.0 - energyVal) * bC > rng.randFloat()) {
        section.markedForDetach236 = true;
        return;
    }

    // Color update
    SectionColorService.applyFrom416510(section, treeAge);

    // §5: currentGrowth = baseGrowth * energy
    section.currentGrowth = ((section.baseGrowth as number) * energyVal) as Float32;

    // §6: production +420 and accumulator +424
    const growthRate = section.growthRate as number;
    const v16 = growthRate * v34;
    const v19 = v16 * v34 * energyVal * leafProd;
    section.energyProduction420 = v19 as Float32;
    section.energyAccumulator424 = ((section.energyAccumulator424 as number) + v19) as Float32;

    // §7: growth rate increase when headroom exists
    const maxGrowth = section.maxGrowth as number;
    if (maxGrowth > growthRate) {
        const v27 = v34 * c4;
        const increment = (rng.randFloat() * 0.5 + 0.5) * (energyVal * v27);
        let newRate = growthRate + increment;
        newRate = Math.min(newRate, maxGrowth);
        section.growthRate = newRate as Float32;
        section.growthTarget = (newRate + newRate) as Float32;
    }
}
