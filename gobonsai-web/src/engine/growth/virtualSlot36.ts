import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { Float32 } from "../math/MathTypes";

/**
 * Виртуальный слот +36 по типу секции (spec_update_growth_sub_40DC90 §2.5).
 * sub_414E10.c: для каждого ребёнка после child+432 вызывается (*child+36)(child).
 * Корень: TreeSectionSeed — сначала sub_417440 (почка), затем тело sub_414E10.
 *
 * Оценка готовности порта к 1:1 с GoBonsai.exe (дерево/кадр/энергия/vtable): ~42%.
 */

/** sub_417440.c — нет детей, this+432 > 0 → первая почка. */
export function maybeSeedSpawnSub417440(
    seed: TreeSection,
    rng: MSVCRand | undefined,
): void {
    if (seed.worldDetached188) return;
    if (seed.children.length !== 0) return;
    if ((seed.energyBudget432 as number) <= 0.0) return;
    if (!rng) return;
    const v4 = rng.randFloat() * 0.1599999964237213 - 0.07999999821186066;
    const v3 = rng.randFloat() * 0.1599999964237213 - 0.07999999821186066;
    TreeSection.createBudFromSeed(seed, rng, v4, v3);
}

function skipDetached(section: TreeSection): boolean {
    return section.worldDetached188;
}

/**
 * Полный обход «слот +36» от узла вниз: как цепочка (*child+36) внутри sub_414E10.
 * Заменяет плоское distribute без рекурсии по типам.
 */
export function runVirtualSlot36Tree(
    root: TreeSection,
    rng: MSVCRand | undefined,
): void {
    const visit = (section: TreeSection): void => {
        if (skipDetached(section)) return;

        if (section.sectionRuntimeType4 === SectionRuntimeType.TreeSectionSeed) {
            maybeSeedSpawnSub417440(section, rng);
        }

        const children = section.children;
        const n = children.length;
        if (n === 0) return;

        let v10 = 0;
        for (const c of children) {
            if (!skipDetached(c)) v10 += c.energyWeight428 as number;
        }
        for (const c of children) {
            if (skipDetached(c)) {
                c.energyBudget432 = 0 as Float32;
                continue;
            }
            const share =
                v10 <= 0 ? 1.0 / n : (c.energyWeight428 as number) / v10;
            c.energyBudget432 = (share *
                (section.energyBudget432 as number)) as Float32;
            visit(c);
        }

        if (section.sectionRuntimeType4 === SectionRuntimeType.TreeSectionBud) {
            budAfterSub414E10From415EF0(section, rng);
        }
    };
    visit(root);
}

/**
 * sub_415EF0.c после sub_414E10(this): рост почки / sub_415C10 при условиях.
 * TODO(original): +108/+111/+113, flt_4D862C/4D8630/4D8620, sub_416300, +512, слот +44.
 */
function budAfterSub414E10From415EF0(
    _bud: TreeSection,
    _rng: MSVCRand | undefined,
): void {
    void _bud;
    void _rng;
}

/** Один узел как корень поддерева — для тестов и внешних вызовов. */
export function dispatchVirtualSlot36(
    section: TreeSection,
    rng: MSVCRand | undefined,
): void {
    runVirtualSlot36Tree(section, rng);
}
