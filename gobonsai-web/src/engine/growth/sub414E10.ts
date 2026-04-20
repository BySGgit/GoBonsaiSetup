import { TreeSection } from "../TreeSection";
import { GrowthConstants } from "../config/GrowthConstants";
import { sub4079C0EnsureInitialized } from "../config/SectionTypeRegistrySub401730";
import { Float32 } from "../math/MathTypes";
import { TREE_CONSTANTS } from "../TreeConstants";
import { MSVCRand } from "../MSVCRand";
import { runVirtualSlot36Tree } from "./virtualSlot36";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { writeUnifiedBudget428 } from "./sub414CE0";

/**
 * sub_414E10.c вЂ” Р±Р°Р·РѕРІС‹Р№ СЃР»РѕС‚ +36 РґР»СЏ TreeSection: СЃР±СЂРѕСЃ +420/+436/+480/+484, РґРѕР»Рё child+432
 * РѕС‚ parent+432 РїРѕ РІРµСЃР°Рј this+428, СЃСѓРјРјРёСЂРѕРІР°РЅРёРµ РґРµС‚РµР№, С…РІРѕСЃС‚ +424/+440/+36.
 *
 * Р’РµС‚РєР° `dword_4D7CF8` + sub_4079C0: РѕРґРЅРѕРєСЂР°С‚РЅС‹Р№ side-effect РІ exe; РІ TS РЅРµ РїРµСЂРµРЅРѕСЃРёС‚СЃСЏ,
 * С„РёРєСЃРёСЂСѓРµС‚СЃСЏ С„Р»Р°РіРѕРј `lazy4079C0Triggered` РїСЂРё РїРµСЂРІРѕРј СѓР·Р»Рµ СЃ СЂРѕРґРёС‚РµР»РµРј (СЌРєРІРёРІР°Р»РµРЅС‚ this+180).
 */

/** РЎРѕРѕС‚РІРµС‚СЃС‚РІСѓРµС‚ В«РіР»РѕР±Р°Р»СЊРЅС‹Р№ Р±РёС‚ СѓСЃС‚Р°РЅРѕРІР»РµРЅВ» РїРѕСЃР»Рµ РїРµСЂРІРѕРіРѕ sub_4079C0 РІ РїСЂРѕС†РµСЃСЃРµ. */
let lazy4079C0Triggered = false;

function u32(x: number): number {
    return x >>> 0;
}

/** decompiled/sub_414E10.c:16вЂ“19 вЂ” РїСЂРё РЅРµРЅСѓР»РµРІРѕРј СЂРѕРґРёС‚РµР»Рµ Рё СЃР±СЂРѕС€РµРЅРЅРѕРј Р±РёС‚Рµ dword_4D7CF8 РІС‹Р·С‹РІР°РµС‚СЃСЏ sub_4079C0. */
function maybeRunLazy4079C0Once(root: TreeSection): void {
    if (lazy4079C0Triggered) return;
    const stack: TreeSection[] = [root];
    while (stack.length) {
        const s = stack.pop()!;
        if (s.parent != null) {
            sub4079C0EnsureInitialized();
            lazy4079C0Triggered = true;
            return;
        }
        for (const c of s.children) stack.push(c);
    }
}

/** this+188 == 1 вЂ” СЃРµРєС†РёСЏ В«РѕС‚С†РµРїР»РµРЅР°В», РІ C sub_414E10 РЅРµ С‚СЂРѕРіР°РµС‚ СѓР·РµР» (spec_detach_pipeline). */
function skipDetached(section: TreeSection): boolean {
    return section.worldDetached188;
}

/**
 * РџСЂРѕРєСЃРё РґР»СЏ this+428 вЂ” РІРµСЃ РґРѕР»Рё Р±СЋРґР¶РµС‚Р° Сѓ СЂРµР±С‘РЅРєР°; РІ exe СЃРІСЏР·Р°РЅ СЃ СЂР°РґРёСѓСЃРѕРј/СЌРЅРµСЂРіРёРµР№ РїРѕР±РµРіР°.
 * РЎРёРЅС…СЂРѕРЅРёР·РёСЂСѓРµРј РёР· РіРµРѕРјРµС‚СЂРёРё РїРµСЂРµРґ СЂР°СЃРїСЂРµРґРµР»РµРЅРёРµРј +432.
 */
export function syncEnergyWeight428FromGeometry(root: TreeSection): void {
    const walk = (s: TreeSection): void => {
        const liveBase = Math.max(1e-6, s.twigRadius444 as number);
        const ctorTaper =
            (s.branchBaseRadius as number) > 1e-6
                ? (s.branchTipRadius as number) / (s.branchBaseRadius as number)
                : 1.0;
        const liveTip = Math.max(1e-6, liveBase * ctorTaper);
        const w = liveBase + liveTip;
        writeUnifiedBudget428(s, Math.max(1e-6, w));
        for (const c of s.children) walk(c);
    };
    walk(root);
}

/**
 * this+444 / this+448 вЂ” РґРѕ РїРѕР»РЅРѕРіРѕ sub_417C90/sub_418BD0 СЃРёРЅС…СЂРѕРЅРёР·РёСЂСѓРµРј РёР· С‚РµРєСѓС‰РµР№ РіРµРѕРјРµС‚СЂРёРё TS
 * (СЂР°РґРёСѓСЃ РѕСЃРЅРѕРІР°РЅРёСЏ Рё РґР»РёРЅР° СЃРµРіРјРµРЅС‚Р° РїРѕ branchPosition Г— HEIGHT_FACTOR).
 */
export function syncTwigFloat444448FromGeometry(root: TreeSection): void {
    const { GEOMETRY } = TREE_CONSTANTS;
    const walk = (s: TreeSection): void => {
        if ((s.twigRadius444 as number) <= 0) {
            s.twigRadius444 = s.branchBaseRadius as Float32;
        }
        if ((s.twigLength448 as number) <= 0) {
            const len =
                GEOMETRY.HEIGHT_FACTOR * Math.max(0.05, s.branchPosition as number);
            s.twigLength448 = len as Float32;
        }
        for (const c of s.children) walk(c);
    };
    walk(root);
}

/**
 * sub_414E10: v10 = sum(child+428); child+432 = share * parent+432; Р·Р°С‚РµРј (*child+36)(child).
 * Р РµР°Р»РёР·Р°С†РёСЏ вЂ” runVirtualSlot36Tree (virtualSlot36.ts): РїРѕСЂСЏРґРѕРє РєР°Рє РІ C.
 */
export function distributeEnergyBudget432DownTree(
    root: TreeSection,
    rng?: MSVCRand,
    /** *(_BYTE *)(dword_4D7EE8 + 220) вЂ” СЃРј. WorldGrowthState.worldFlagByte220, sub_415C10 */
    worldFlagByte220 = false,
): void {
    maybeRunLazy4079C0Once(root);
    runVirtualSlot36Tree(root, rng, worldFlagByte220);
}

/**
 * Р›РёСЃС‚: +420 РёР· growthScratchA Г— РјР°СЃС€С‚Р°Р± (РїСЂРѕРєСЃРё sub_416510 в†’ this+420).
 * РЈР·РµР» СЃ РґРµС‚СЊРјРё: СЃСѓРјРјС‹ РґРµС‚РµР№ РґР»СЏ +420/+436/+480/+484; +480 СѓС‡РёС‚С‹РІР°РµС‚ spawnDelta480 (sub_4188E0 ++);
 * РІРЅСѓС‚СЂРµРЅРЅРёР№ СѓР·РµР»: +484 += 1 РїРѕСЃР»Рµ СЃСѓРјРјС‹ РґРµС‚РµР№ (sub_417C90 ++ РїРѕСЃР»Рµ sub_414E10 РІ twig).
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
 * РҐРІРѕСЃС‚ sub_414E10.c:53вЂ“59 вЂ” РїРѕСЃС‚-РѕСЂРґРµСЂ: +424 += +420, +440 += 1, this+36 = max(+444, +448*0.5).
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

/** РђР»РёР°СЃ РґР»СЏ СЃРѕРІРјРµСЃС‚РёРјРѕСЃС‚Рё СЃ СЂР°РЅРЅРёРјРё РІС‹Р·РѕРІР°РјРё. */
export const applySub414E10Tail424440 = applySub414E10PostOrderTail;

