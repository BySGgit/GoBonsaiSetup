import { TreeSection } from "../TreeSection";
import { Float32 } from "../math/MathTypes";
import {
    GrowthConstants,
    byte4D8229ForSectionType,
    byte4D822AForSectionType,
} from "../config/GrowthConstants";

/**
 * sub_414CE0.c — virtual слот +40: годовой финал накопителей.
 *
 * До LABEL_11: при byte_4D8229 — this+428 = parent+428 * this+512;
 * при byte_4D822A — pow(+424, flt_4D8628), затем lerp старого +428 с результатом (flt_4D863C).
 * LABEL_11: this+424 = 0, затем для каждого ребёнка (*child+40).
 *
 * Ленивые sub_413C20/sub_40FBA0 (INI) в TS не вызываются — таблицы в GrowthConstants.
 * Запись в exe идёт в единый this+428; в TS годовой смысл переносим в `sub414CE0SeedBudget428`
 * (см. TODO(original): слить с energyWeight428 как в C).
 */

function readApproxC428(s: TreeSection): number {
    const seed = s.sub414CE0SeedBudget428 as number;
    if (seed !== 0) return seed;
    return s.energyWeight428 as number;
}

function applyBeforeLabel11(section: TreeSection): void {
    const t = section.sectionRuntimeType4 | 0;

    if (byte4D8229ForSectionType(t)) {
        const parent = section.parent;
        if (parent) {
            const v2 =
                readApproxC428(parent) * (section.ce512EnergyAllowanceScale as number);
            section.sub414CE0SeedBudget428 = v2 as Float32;
        }
        return;
    }

    if (byte4D822AForSectionType(t)) {
        const powExp = GrowthConstants.FLT_4D8628_ENERGY_ALLOWANCE_POW as number;
        const reb = GrowthConstants.FLT_4D863C_ENERGY_REBALANCE_PERCENT as number;
        const acc = Math.max(0, section.energyAccumulator424 as number);
        const v6 = Math.pow(acc, powExp);
        const old428 = readApproxC428(section);
        const v2 = (1.0 - reb) * old428 + reb * v6;
        section.sub414CE0SeedBudget428 = v2 as Float32;
    }
}

export function sub414CE0Yearly(root: TreeSection): void {
    const walk = (section: TreeSection): void => {
        applyBeforeLabel11(section);
        section.energyAccumulator424 = 0 as Float32;
        for (const c of section.children) {
            walk(c);
        }
    };
    walk(root);
}
