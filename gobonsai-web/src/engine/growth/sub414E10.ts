import { TreeSection } from "../TreeSection";
import { GrowthConstants } from "../config/GrowthConstants";
import { Float32 } from "../math/MathTypes";
import { TREE_CONSTANTS } from "../TreeConstants";
import { MSVCRand } from "../MSVCRand";
import { runVirtualSlot36Tree } from "./virtualSlot36";
import { SectionRuntimeType } from "../SectionRuntimeType";

/**
 * sub_414E10.c — базовый слот +36 для TreeSection: сброс +420/+436/+480/+484, доли child+432
 * от parent+432 по весам this+428, суммирование детей, хвост +424/+440/+36.
 *
 * Ветка `dword_4D7CF8` + sub_4079C0: однократный side-effect в exe; в TS не переносится,
 * фиксируется флагом `lazy4079C0Triggered` при первом узле с родителем (эквивалент this+180).
 */

/** Соответствует «глобальный бит установлен» после первого sub_4079C0 в процессе. */
let lazy4079C0Triggered = false;

function u32(x: number): number {
    return x >>> 0;
}

/** decompiled/sub_414E10.c:16–19 — при ненулевом родителе и сброшенном бите dword_4D7CF8 вызывается sub_4079C0. */
function maybeRunLazy4079C0Once(root: TreeSection): void {
    if (lazy4079C0Triggered) return;
    const stack: TreeSection[] = [root];
    while (stack.length) {
        const s = stack.pop()!;
        if (s.parent != null) {
            lazy4079C0Triggered = true;
            return;
        }
        for (const c of s.children) stack.push(c);
    }
}

/** this+188 == 1 — секция «отцеплена», в C sub_414E10 не трогает узел (spec_detach_pipeline). */
function skipDetached(section: TreeSection): boolean {
    return section.worldDetached188;
}

/**
 * Прокси для this+428 — вес доли бюджета у ребёнка; в exe связан с радиусом/энергией побега.
 * Синхронизируем из геометрии перед распределением +432.
 */
export function syncEnergyWeight428FromGeometry(root: TreeSection): void {
    const walk = (s: TreeSection): void => {
        const w =
            (s.branchBaseRadius as number) + (s.branchTipRadius as number);
        s.energyWeight428 = Math.max(1e-6, w) as Float32;
        for (const c of s.children) walk(c);
    };
    walk(root);
}

/**
 * this+444 / this+448 — до полного sub_417C90/sub_418BD0 синхронизируем из текущей геометрии TS
 * (радиус основания и длина сегмента по branchPosition × HEIGHT_FACTOR).
 */
export function syncTwigFloat444448FromGeometry(root: TreeSection): void {
    const { GEOMETRY } = TREE_CONSTANTS;
    const walk = (s: TreeSection): void => {
        s.twigRadius444 = s.branchBaseRadius as Float32;
        const len =
            GEOMETRY.HEIGHT_FACTOR * Math.max(0.05, s.branchPosition as number);
        s.twigLength448 = len as Float32;
        for (const c of s.children) walk(c);
    };
    walk(root);
}

/**
 * sub_414E10: v10 = sum(child+428); child+432 = share * parent+432; затем (*child+36)(child).
 * Реализация — runVirtualSlot36Tree (virtualSlot36.ts): порядок как в C.
 */
export function distributeEnergyBudget432DownTree(
    root: TreeSection,
    rng?: MSVCRand,
    /** *(_BYTE *)(dword_4D7EE8 + 220) — см. WorldGrowthState.worldFlagByte220, sub_415C10 */
    worldFlagByte220 = false,
): void {
    maybeRunLazy4079C0Once(root);
    runVirtualSlot36Tree(root, rng, worldFlagByte220);
}

/**
 * Лист: +420 из growthScratchA × масштаб (прокси sub_416510 → this+420).
 * Узел с детьми: суммы детей для +420/+436/+480/+484; +480 учитывает spawnDelta480 (sub_4188E0 ++);
 * внутренний узел: +484 += 1 после суммы детей (sub_417C90 ++ после sub_414E10 в twig).
 */
export function aggregateEnergy420436PostOrder(root: TreeSection): void {
    const scale = GrowthConstants.SUB40DC90_PRODUCTION_FROM_SCRATCH_SCALE as number;

    const go = (section: TreeSection): void => {
        if (skipDetached(section)) return;
        const activeChildren = section.children.filter((c) => !skipDetached(c));
        if (section.children.length === 0) {
            // In C, local +420 production at this stage comes from leaf path (sub_416510).
            // Terminal non-leaf nodes should not synthesize production here.
            section.energyProduction420 =
                section.sectionRuntimeType4 === SectionRuntimeType.TreeSectionLeaf
                    ? ((section.growthScratchA as number) * scale as Float32)
                    : 0;
            section.rollupDword480 = 0;
            section.rollupDword484 = 0;
            return;
        }
        if (activeChildren.length === 0) {
            section.energyProduction420 = 0;
            section.energySpent436 = 0;
            section.rollupDword480 = 0;
            section.rollupDword484 = 0;
            return;
        }
        let p420 = 0;
        let s436 = 0;
        let s480 = 0;
        let s484 = 0;
        for (const c of activeChildren) {
            go(c);
            p420 += c.energyProduction420 as number;
            s436 += c.energySpent436 as number;
            s480 += c.rollupDword480;
            s484 += c.rollupDword484;
        }
        section.energyProduction420 = p420 as Float32;
        section.energySpent436 = s436 as Float32;
        section.rollupDword480 = u32(s480 + section.spawnDelta480);
        section.rollupDword484 = u32(s484 + 1);
    };
    go(root);
}

/**
 * Хвост sub_414E10.c:53–59 — пост-ордер: +424 += +420, +440 += 1, this+36 = max(+444, +448*0.5).
 */
export function applySub414E10PostOrderTail(root: TreeSection): void {
    const go = (section: TreeSection): void => {
        if (skipDetached(section)) return;
        for (const c of section.children) go(c);
        section.energyAccumulator424 =
            ((section.energyAccumulator424 as number) +
                (section.energyProduction420 as number)) as Float32;
        section.energyTickCounter440 =
            ((section.energyTickCounter440 as number) + 1.0) as Float32;
        const v448 = section.twigLength448 as number;
        const v444 = section.twigRadius444 as number;
        const v7 = v448 * 0.5;
        section.meshScalar36 = (v444 >= v7 ? v444 : v7) as Float32;
    };
    go(root);
}

/** Алиас для совместимости с ранними вызовами. */
export const applySub414E10Tail424440 = applySub414E10PostOrderTail;
