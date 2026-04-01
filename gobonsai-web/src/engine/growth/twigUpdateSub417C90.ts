import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { GrowthConstants } from "../config/GrowthConstants";
import { Float32 } from "../math/MathTypes";
import { TransformService } from "../math/TransformService";
import { twigLengthGrowthSub418BD0 } from "./twigLengthGrowthSub418BD0";
import { branchingDispatcherSub417F40 } from "./branchingDispatcherSub417F40";

/**
 * sub_417C90.c — per-frame update for TreeSectionTwig (vtable slot +36, type=10).
 *
 * Called AFTER sub_414E10 (energy distribution) by the virtualSlot36 dispatcher.
 * Order: girth → slerp → length-or-branch → health → death.
 *
 * NOTE: sub_414E10 is NOT called here because virtualSlot36.ts already handles
 * energy distribution before dispatching to this function.
 */

const GIRTH_CAP = 0.1;
const HEALTH_ENERGY_ADJUSTMENT = 0.008; // flt_4D6428 from INI; default approx
const DEATH_GIRTH_SCALE = 4.0;
const DEATH_OLD_TICK_THRESHOLD = 1000;
const DEATH_THICK_TICK_THRESHOLD = 2000;
const DEATH_THICK_GIRTH_THRESHOLD = 0.1;
const DEATH_RARE_PROBABILITY = 0.01;

export function twigUpdateSub417C90(
    section: TreeSection,
    rng: MSVCRand | undefined,
): void {
    // §2: ++this+484 tick counter
    section.rollupDword484 = (section.rollupDword484 + 1) >>> 0;

    // §3: girth growth — always happens regardless of +512
    const radiusGrowRate = GrowthConstants.FLT_4D8618 as number;
    const currentRadius = section.twigRadius444 as number;
    if (currentRadius > 0) {
        let v9 = (section.energyProduction420 as number) * radiusGrowRate / currentRadius;
        if (v9 > GIRTH_CAP) v9 = GIRTH_CAP;
        section.twigRadius444 = (currentRadius + v9) as Float32;
    }

    // §4: slerp current quaternion (+304) toward target (+320)
    const slerpFactor = GrowthConstants.FLT_4D8624 as number;
    TransformService.slerp(
        section.rotationQuaternion,
        section.rotationQuaternion,
        section.targetRotation,
        slerpFactor as Float32,
    );
    section.rotationQuaternion.normalize();

    // §5: growth vs branching dispatch on +512 flag
    if (section.growthFlag512) {
        twigLengthGrowthSub418BD0(section, rng);
    } else {
        if (rng) branchingDispatcherSub417F40(section, rng);
    }

    // §6: health energy smoothing
    const minBudEnergy = GrowthConstants.FLT_4D862C as number;
    let health = section.healthEnergy456 as number;
    if ((section.energyBudget432 as number) >= minBudEnergy) {
        health += HEALTH_ENERGY_ADJUSTMENT;
    } else {
        health -= HEALTH_ENERGY_ADJUSTMENT;
    }
    section.healthEnergy456 = Math.max(0, Math.min(1, health)) as Float32;

    // §7: death / detach conditions — only effective when detach pipeline is active.
    // TODO(original): re-enable when processDetachFlags is turned on in GrowthFramePipeline.
    // Without the pipeline, markedForDetach236 is never consumed but poisons the D! debug flag.
}
