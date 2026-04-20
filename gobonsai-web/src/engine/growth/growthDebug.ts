import { TreeSection } from "../TreeSection";
import { SectionRuntimeType } from "../SectionRuntimeType";

function readLocalStorageFlag(key: string): boolean {
    if (typeof window === "undefined") return false;
    try {
        return window.localStorage.getItem(key) === "1";
    } catch {
        return false;
    }
}

function readLocalStorageInt(key: string, fallback: number): number {
    if (typeof window === "undefined") return fallback;
    try {
        const raw = window.localStorage.getItem(key);
        if (!raw) return fallback;
        const n = Number.parseInt(raw, 10);
        return Number.isFinite(n) ? n : fallback;
    } catch {
        return fallback;
    }
}

export function growthDebugEnabled(): boolean {
    return readLocalStorageFlag("gobonsai_debug_growth_chain");
}

export function growthDebugFrameModulo(): number {
    return Math.max(1, readLocalStorageInt("gobonsai_debug_growth_chain_mod", 1));
}

export function growthDebugSectionLabel(section: TreeSection | null | undefined): string {
    if (!section) return "null";
    const type = section.sectionRuntimeType4;
    const level = section.level;
    const childCount = section.children.length;
    return `id${section.debugId}:t${type}@L${level}#${childCount}`;
}

export function growthDebugStructuralChildCount(section: TreeSection): number {
    let n = 0;
    for (const child of section.children) {
        if (child.sectionRuntimeType4 !== SectionRuntimeType.TreeSectionLeaf) {
            n++;
        }
    }
    return n;
}

export function growthDebugLog(tag: string, payload: Record<string, unknown>): void {
    if (!growthDebugEnabled()) return;
    console.log(`[GrowthChain:${tag}]`, payload);
}
