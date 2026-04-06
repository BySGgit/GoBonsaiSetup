import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { GrowthConstants } from "../config/GrowthConstants";
import { Float32 } from "../math/MathTypes";
import { TransformService } from "../math/TransformService";
import { twigLengthGrowthSub418BD0 } from "./twigLengthGrowthSub418BD0";
import { branchingDispatcherSub417F40 } from "./branchingDispatcherSub417F40";

/**
 * sub_417C90.c: per-frame update for TreeSectionTwig (vtable slot +36, type=10).
 *
 * Called after energy distribution (sub_414E10 equivalent in virtualSlot36).
 */

const GIRTH_CAP = 0.1;
const DEATH_GIRTH_SCALE = 4.0;
const DEATH_OLD_TICK_THRESHOLD = 1000;
const DEATH_THICK_TICK_THRESHOLD = 2000;
const DEATH_THICK_GIRTH_THRESHOLD = 0.1;
const DEATH_RARE_PROBABILITY = 0.01;

export function twigUpdateSub417C90(
    section: TreeSection,
    rng: MSVCRand | undefined,
): void {
    // ++this+484 tick counter
    section.rollupDword484 = (section.rollupDword484 + 1) >>> 0;

    // Girth growth: always happens regardless of +512.
    const radiusGrowRate = GrowthConstants.FLT_4D8618 as number;
    const currentRadius = section.twigRadius444 as number;
    if (currentRadius > 0) {
        let v9 =
            ((section.energyProduction420 as number) * radiusGrowRate) /
            currentRadius;
        if (v9 > GIRTH_CAP) v9 = GIRTH_CAP;
        section.twigRadius444 = (currentRadius + v9) as Float32;
    }

    // Slerp current quaternion (+304) toward target (+320).
    const slerpFactor = GrowthConstants.FLT_4D8624 as number;
    TransformService.slerp(
        section.rotationQuaternion,
        section.rotationQuaternion,
        section.targetRotation,
        slerpFactor as Float32,
    );
    section.rotationQuaternion.normalize();

    // Growth vs branching dispatch on +512 flag.
    if (section.growthFlag512) {
        twigLengthGrowthSub418BD0(section, rng);
    } else {
        if (rng) branchingDispatcherSub417F40(section, rng);
    }

    // Health smoothing with INI-driven flt_4D6428.
    const minBudEnergy = GrowthConstants.FLT_4D862C as number;
    const healthAdjust =
        GrowthConstants.FLT_4D6428_HEALTH_ENERGY_ADJUSTMENT as number;
    let health = section.healthEnergy456 as number;
    if ((section.energyBudget432 as number) >= minBudEnergy) {
        health += healthAdjust;
    } else {
        health -= healthAdjust;
    }
    section.healthEnergy456 = Math.max(0, Math.min(1, health)) as Float32;

    // sub_417C90 tail: low-health detach probability gate.
    const parent = section.parent;
    if (
        (section.healthEnergy456 as number) <= 0 &&
        parent &&
        (parent.healthEnergy456 as number) > 0 &&
        rng
    ) {
        // Prevent catastrophic trunk collapse: keep continuations/internal backbone alive.
        const canDetachByHealth =
            !section.isContinuation &&
            section.children.length === 0 &&
            section.level > 1;
        if (!canDetachByHealth) {
            return;
        }

        const r1 = rng.randFloat();
        const r2 = rng.randFloat();
        const oldTicks = section.energyTickCounter440 as number;
        const thick = section.twigRadius444 as number;
        const radiusGate = thick * DEATH_GIRTH_SCALE;

        if (
            r1 > radiusGate ||
            (((oldTicks <= DEATH_THICK_TICK_THRESHOLD ||
                thick <= DEATH_THICK_GIRTH_THRESHOLD) &&
                oldTicks > DEATH_OLD_TICK_THRESHOLD) &&
                r2 < DEATH_RARE_PROBABILITY)
        ) {
            section.markedForDetach236 = true;
        }
    }
}
