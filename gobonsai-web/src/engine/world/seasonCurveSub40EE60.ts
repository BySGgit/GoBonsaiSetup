/**
 * sub_40EE60 — сезонный коэффициент по дню года.
 * GUIDES/spec_update_growth_sub_40DC90.md §1
 * Таблица: flt_4B786C[12] в full.c
 */
import { GrowthConstants } from "../config/GrowthConstants";

export function seasonFactorSub40EE60(dayAccum: number): number {
    const year = dayAccum / 365.0;
    const yearFrac = year - Math.floor(year);
    const month = yearFrac * 12.0;
    const monthIndex = Math.floor(month) % 12;
    const t = month - Math.floor(month);
    const table = GrowthConstants.FLT_4B786C_MONTH;
    const next = (monthIndex + 1) % 12;
    return table[monthIndex] + (table[next] - table[monthIndex]) * t;
}
