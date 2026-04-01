import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { GrowthConstants, byte4D822AForSectionType } from "../config/GrowthConstants";
import { Float32 } from "../math/MathTypes";
import { TransformService } from "../math/TransformService";
import { Sub416510Rotation } from "../math/Sub416510Rotation";
import { getSlot36SimulationDay } from "./frameState";

/**
 * sub_417F40.c — branching dispatcher for TreeSectionTwig.
 * Called from twigUpdateSub417C90 when growthFlag512 == false.
 *
 * Decision tree:
 *   yearsSinceBranch < 1  →  do nothing
 *   yearsSinceBranch > 3 AND girth > 0.2  →  lateral (sub_4188E0)
 *   childCount <= 1 (with filter)  →  apical (sub_417FF0) or simplified (sub_418660)
 */

function sub416300Filter(section: TreeSection | null): TreeSection | null {
    if (!section) return null;
    return byte4D822AForSectionType(section.sectionRuntimeType4) ? section : null;
}

function yearsSinceBranch(section: TreeSection): number {
    const worldTime = getSlot36SimulationDay();
    const birthTime = worldTime - (section.energyTickCounter440 as number);
    return Math.floor(worldTime / 365) - Math.floor(birthTime / 365);
}

let _branchDbgCounter = 0;

export function branchingDispatcherSub417F40(
    section: TreeSection,
    rng: MSVCRand,
): void {
    const years = yearsSinceBranch(section);
    if (years < 1) return;

    if (years > 3 && (section.twigRadius444 as number) > 0.2) {
        const prevChildren = section.children.length;
        lateralBranchSub4188E0(section, rng);
        if (section.children.length > prevChildren) {
            console.log(`[Branch] LATERAL: tR=${(section.twigRadius444 as number).toFixed(3)} yrs=${years} children=${section.children.length}`);
        } else if (++_branchDbgCounter % 500 === 0) {
            const avail = (section.energyBudget432 as number) - (section.energySpent436 as number);
            console.log(`[Branch] lateral attempt #${_branchDbgCounter}: yrs=${years} tR=${(section.twigRadius444 as number).toFixed(3)} avail=${avail.toFixed(4)}`);
        }
    } else {
        const childCount = section.children.length;
        if (childCount <= 1) {
            if (childCount === 0) {
                simplifiedBranchSub418660(section, rng);
            } else {
                const firstTwig = sub416300Filter(section.children[0]);
                if (firstTwig) {
                    apicalBranchSub417FF0(section, rng);
                } else {
                    simplifiedBranchSub418660(section, rng);
                }
            }
        }
    }
}

// ─── sub_4188E0: lateral branch ─────────────────────────────────────

/**
 * sub_4188E0.c: create a lateral (side) branch Bud.
 * Trigger: available energy (budget - spent) >= minBudEnergy.
 * Probability proportional to energy surplus, clamped to [0, 0.003].
 */
function lateralBranchSub4188E0(
    section: TreeSection,
    rng: MSVCRand,
): void {
    const minE = GrowthConstants.FLT_4D862C as number;
    const maxE = GrowthConstants.FLT_4D8630 as number;
    const available = (section.energyBudget432 as number) - (section.energySpent436 as number);

    if (available < minE) return;

    let v14 = (available - minE) / (maxE - minE) * 0.003;
    v14 = Math.max(0, Math.min(0.003, v14));

    if (rng.randFloat() >= v14) return;

    const yaw = rng.randFloat() * Math.PI * 2 - Math.PI;
    const pitch = rng.randFloat() * 1.2 - 0.6;

    const bud = createBudChild(section, yaw, pitch, rng);
    if (!bud) return;

    section.energySpent436 = ((section.energySpent436 as number) + minE) as Float32;

    normalizeChildWeights(section);
}

// ─── sub_417FF0: apical/paired branching ────────────────────────────

/**
 * sub_417FF0.c: apical branching — extends the axis.
 * If section has children: creates 2 new buds with geometry.
 * If no children: falls through to sub_418660 (simplified).
 */
function apicalBranchSub417FF0(
    section: TreeSection,
    rng: MSVCRand,
): void {
    const minE = GrowthConstants.FLT_4D862C as number;
    const apicalStr = GrowthConstants.FLT_4D8638 as number;
    const available = (section.energyBudget432 as number) - (section.energySpent436 as number);

    if (available < minE) return;

    const tickFactor = Math.max(1, section.rollupDword484 - 1);
    const v33 = Math.pow(tickFactor, apicalStr);
    const cost = apicalStr * available * Math.min(1, 1.0 / v33);

    if (section.children.length === 0) {
        simplifiedBranchSub418660(section, rng);
        return;
    }

    // Paired branching: two buds at slight angles from parent axis
    const baseYaw = rng.randFloat() * Math.PI * 2;
    const spreadAngle = 0.3 + rng.randFloat() * 0.4;

    const bud1 = createBudChild(section, baseYaw + spreadAngle, -0.3, rng);
    const bud2 = createBudChild(section, baseYaw - spreadAngle + Math.PI, -0.3, rng);

    if (bud1 || bud2) {
        section.energySpent436 = ((section.energySpent436 as number) + cost) as Float32;
        normalizeChildWeights(section);
    }
}

// ─── sub_418660: simplified branching ───────────────────────────────

/**
 * sub_418660.c: simple branch — one bud, maybe a second opposite.
 * Random yaw, one child segment; if energy sufficient AND rand() < 0.2 → second bud.
 */
function simplifiedBranchSub418660(
    section: TreeSection,
    rng: MSVCRand,
): void {
    const minE = GrowthConstants.FLT_4D862C as number;
    const available = (section.energyBudget432 as number) - (section.energySpent436 as number);
    if (available < minE) return;

    const yaw = rng.randFloat() * Math.PI * 2 - Math.PI;
    const pitch = rng.randFloat() * 0.8 - 0.2;

    const bud1 = createBudChild(section, yaw, pitch, rng);
    if (!bud1) return;

    section.energySpent436 = ((section.energySpent436 as number) + minE * 0.5) as Float32;

    if (available > minE * 2 && rng.randFloat() < 0.2) {
        createBudChild(section, yaw + Math.PI, pitch, rng);
        section.energySpent436 = ((section.energySpent436 as number) + minE * 0.5) as Float32;
    }

    normalizeChildWeights(section);
}

// ─── Helpers ────────────────────────────────────────────────────────

function createBudChild(
    parent: TreeSection,
    yaw: number,
    pitch: number,
    rng: MSVCRand,
): TreeSection | null {
    const bud = new TreeSection(
        parent,
        parent.level + 1,
        rng,
        0.01,
    );
    bud.sectionRuntimeType4 = SectionRuntimeType.TreeSectionBud;
    bud.twigRadius444 = 0.01 as Float32;
    bud.twigLength448 = 0 as Float32;
    bud.energyWeight428 = 1.0 as Float32;
    bud.sub414CE0SeedBudget428 = 1.0 as Float32;
    bud.growthFlag512 = true;

    TransformService.rotationYawPitchRoll(bud.targetRotation, yaw, pitch, 0);
    bud.rotationQuaternion.copy(bud.targetRotation);
    bud.rotation.copy(bud.targetRotation);
    Sub416510Rotation.syncBlob80FromQuaternion(bud);

    parent.children.push(bud);
    bud.updateAttachmentPosition(parent);
    return bud;
}

/**
 * Normalize energyWeight428 across siblings so shares sum to ~1.
 * C: sub_4188E0 normalizes child+428 by sum of all sibling +428.
 */
function normalizeChildWeights(parent: TreeSection): void {
    let sum = 0;
    for (const c of parent.children) {
        sum += c.energyWeight428 as number;
    }
    if (sum <= 0) return;
    for (const c of parent.children) {
        c.energyWeight428 = ((c.energyWeight428 as number) / sum) as Float32;
    }
}
