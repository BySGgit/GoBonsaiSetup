import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { GrowthConstants } from "../config/GrowthConstants";
import { Float32 } from "../math/MathTypes";
import { TransformService } from "../math/TransformService";
import { twigLengthGrowthSub418BD0 } from "./twigLengthGrowthSub418BD0";
import { branchingDispatcherSub417F40 } from "./branchingDispatcherSub417F40";
import {
    detachFromParentAndMarkWorldManagedSub417C90,
    detachImmediatelySub40EEE0,
} from "./detachPipelineSub40EEE0";
import {
    createNumericPropertyBinding,
    createSub4032WideString,
    createSub408600Entry,
    sub401DD0DestroyIniEntry,
    sub4032D0Assign,
    sub408600Register,
    subAtexitRegister,
} from "../config/IniRegistrySub408600";

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
const _healthEnergyAdjustmentMeta4DBAEC = createSub408600Entry();
let _sub417C90InitFlags4DBB10 = 0;
const _fallbackRngSub417C90 = new MSVCRand(1);

function sub4724A0CleanupStub(): void {
    sub401DD0DestroyIniEntry(_healthEnergyAdjustmentMeta4DBAEC);
}

function ensureSub417C90IniBindings(): void {
    if ((_sub417C90InitFlags4DBB10 & 1) !== 0) return;
    _sub417C90InitFlags4DBB10 |= 1;
    const key = createSub4032WideString();
    sub4032D0Assign(key, "healthEnergyAdjustment", 0x16);
    sub408600Register(
        key,
        _healthEnergyAdjustmentMeta4DBAEC,
        createNumericPropertyBinding(
            GrowthConstants,
            "FLT_4D6428_HEALTH_ENERGY_ADJUSTMENT",
        ),
    );
    subAtexitRegister(sub4724A0CleanupStub);
}

export function twigUpdateSub417C90(
    section: TreeSection,
    rng: MSVCRand | undefined,
): void {
    const rand = rng ?? _fallbackRngSub417C90;

    // ++this+484 tick counter
    section.rollupDword484 = (section.rollupDword484 + 1) >>> 0;

    // Girth growth: always happens regardless of +512.
    const radiusGrowRate = GrowthConstants.FLT_4D8618 as number;
    const currentRadius = section.twigRadius444 as number;
    let v9 =
        ((section.energyProduction420 as number) * radiusGrowRate) /
        currentRadius;
    if (!Number.isFinite(v9) || v9 > GIRTH_CAP) v9 = GIRTH_CAP;
    section.twigRadius444 = (currentRadius + v9) as Float32;

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
        // In the current TS port this path was severing the active apical chain:
        // a terminal continuation twig naturally has no children while it is still
        // extending in length. Detaching it here visually "cuts" the trunk.
        //
        // Keep the detach behavior only for non-continuation twigs until the exact
        // world-managed semantics of the original path are reproduced end-to-end.
        if (section.children.length === 0) {
            if (!section.isContinuation) {
                detachFromParentAndMarkWorldManagedSub417C90(section);
            }
        }
        twigLengthGrowthSub418BD0(section, rng);
    } else {
        branchingDispatcherSub417F40(section, rand);
    }

    ensureSub417C90IniBindings();

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
        !section.isContinuation
    ) {
        const oldTicks = section.energyTickCounter440 as number;
        const thick = section.twigRadius444 as number;
        const radiusGate = thick * DEATH_GIRTH_SCALE;
        const detachByRadius = rand.randFloat() > radiusGate;
        let detachByRare = false;
        if (
            !detachByRadius &&
            (oldTicks <= DEATH_THICK_TICK_THRESHOLD ||
                thick <= DEATH_THICK_GIRTH_THRESHOLD) &&
            oldTicks > DEATH_OLD_TICK_THRESHOLD
        ) {
            detachByRare = rand.randFloat() < DEATH_RARE_PROBABILITY;
        }

        if (detachByRadius || detachByRare) {
            detachImmediatelySub40EEE0(section, rand);
        }
    }
}
