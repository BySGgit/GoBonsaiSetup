import {
    GrowthConstants,
    byte4D8225ForSectionType,
    byte4D8227ForSectionType,
    byte4D8228ForSectionType,
} from "./GrowthConstants";

/**
 * Minimal runtime state for decompiled type-table init helpers:
 * sub_401730 / sub_4017D0 / sub_4079C0 / sub_413CF0.
 */
let dword4D7CEC = 0;
let dword4D7CF8 = 0;
let dword4D8CD0 = 0;
let dword4D8CD8 = 0;
let byte4D829C = 0;

function setFlag0(typeIndex: number, value: number): void {
    const idx = 11 * typeIndex;
    const table = GrowthConstants.BYTE_4D8220_STRIDE11;
    if (idx >= 0 && idx < table.length) table[idx] = value;
}

function setFlag5(typeIndex: number, value: number): void {
    const idx = 11 * typeIndex;
    const table = GrowthConstants.BYTE_4D8225_STRIDE11;
    if (idx >= 0 && idx < table.length) table[idx] = value;
}

function setFlag7(typeIndex: number, value: number): void {
    const idx = 11 * typeIndex;
    const table = GrowthConstants.BYTE_4D8227_STRIDE11;
    if (idx >= 0 && idx < table.length) table[idx] = value;
}

function setFlag8(typeIndex: number, value: number): void {
    const idx = 11 * typeIndex;
    const table = GrowthConstants.BYTE_4D8228_STRIDE11;
    if (idx >= 0 && idx < table.length) table[idx] = value;
}

/** decompiled sub_4017D0: returns 0 and ensures sub_401730(0) once. */
function sub4017D0(): number {
    if ((dword4D7CEC & 1) === 0) {
        dword4D7CEC |= 1;
        const v0 = sub4017D0();
        sub401730RegisterType(v0);
    }
    return 0;
}

/** decompiled sub_401730: mark byte_4D8220[11*type] and return 11*type. */
export function sub401730RegisterType(typeIndex: number): number {
    if ((dword4D7CEC & 1) === 0) {
        dword4D7CEC |= 1;
        const v1 = sub4017D0();
        sub401730RegisterType(v1);
    }
    if (typeIndex === 0) {
        byte4D829C = 1;
    }
    const result = 11 * typeIndex;
    setFlag0(typeIndex, 1);
    if ((dword4D7CEC & 1) === 0) {
        dword4D7CEC |= 1;
        const v3 = sub4017D0();
        return sub401730RegisterType(v3);
    }
    return result;
}

function sub403A90RegisterType5(typeIndex: number): number {
    if ((dword4D7CF8 & 1) === 0) {
        dword4D7CF8 |= 1;
        const v1 = sub403B40EnsureType5Base();
        sub403A90RegisterType5(v1);
    }
    setFlag5(typeIndex, 1);
    if ((dword4D7CF8 & 1) === 0) {
        dword4D7CF8 |= 1;
        const v2 = sub403B40EnsureType5Base();
        return sub403A90RegisterType5(v2);
    }
    return sub401730RegisterType(typeIndex);
}

/** decompiled sub_403B40: one-time init gate for base type id 5. */
export function sub403B40EnsureType5Base(): number {
    if ((dword4D7CF8 & 1) === 0) {
        dword4D7CF8 |= 1;
        sub4079C0EnsureInitialized();
    }
    return 5;
}

/**
 * decompiled sub_4079C0: one-time type-table setup used by sub_413CF0.
 * TS keeps only the flags used in runtime checks (type 5, flags 0/5).
 */
export function sub4079C0EnsureInitialized(): void {
    if ((dword4D7CF8 & 1) === 0) {
        dword4D7CF8 |= 1;
        sub4079C0EnsureInitialized();
        if ((dword4D7CF8 & 1) === 0) {
            dword4D7CF8 |= 1;
            sub4079C0EnsureInitialized();
        }
    }

    // byte_4D825C = 1  -> type 5 flag #5.
    setFlag5(5, 1);

    if ((dword4D7CF8 & 1) === 0) {
        dword4D7CF8 |= 1;
        sub4079C0EnsureInitialized();
    }
    if ((dword4D7CEC & 1) === 0) {
        dword4D7CEC |= 1;
        const v0 = sub4017D0();
        sub401730RegisterType(v0);
    }

    // byte_4D8257 = 1 -> type 5 flag #0.
    setFlag0(5, 1);

    if ((dword4D7CEC & 1) === 0) {
        dword4D7CEC |= 1;
        const v1 = sub4017D0();
        sub401730RegisterType(v1);
    }
}

/**
 * decompiled sub_40FA00:
 *   lazy init guard dword_4D8CD0;
 *   sets byte_4D8228[11*8] and registers type 8 via sub_403A90(8).
 */
export function sub40FA00EnsureInitialized(): void {
    if ((dword4D8CD0 & 1) === 0) {
        dword4D8CD0 |= 1;
        sub40FA00EnsureInitialized();
        if ((dword4D8CD0 & 1) === 0) {
            dword4D8CD0 |= 1;
            sub40FA00EnsureInitialized();
        }
    }
    setFlag8(8, 1);
    sub403A90RegisterType5(8);
}

/**
 * decompiled sub_40FAD0:
 *   lazy init guard dword_4D8CD8;
 *   sets byte_4D8227[11*7] and registers type 7 via sub_403A90(7).
 */
export function sub40FAD0EnsureInitialized(): void {
    if ((dword4D8CD8 & 1) === 0) {
        dword4D8CD8 |= 1;
        sub40FAD0EnsureInitialized();
        if ((dword4D8CD8 & 1) === 0) {
            dword4D8CD8 |= 1;
            sub40FAD0EnsureInitialized();
        }
    }
    setFlag7(7, 1);
    sub403A90RegisterType5(7);
}

/**
 * decompiled sub_413CF0:
 *   if (!a1) return 0;
 *   ensure sub_4079C0 init;
 *   return byte_4D8225[11*type] ? a1 : 0;
 */
export function sub413CF0FilterByType5<T extends { sectionRuntimeType4: number }>(a1: T | null): T | null {
    if (!a1) return null;
    sub4079C0EnsureInitialized();
    return byte4D8225ForSectionType(a1.sectionRuntimeType4) ? a1 : null;
}

/**
 * decompiled sub_40FC70:
 *   if (!a1) return 0;
 *   lazy-init sub_40FAD0;
 *   return byte_4D8227[11*type] ? a1 : 0;
 */
export function sub40FC70FilterByType7<T extends { sectionRuntimeType4: number }>(a1: T | null): T | null {
    if (!a1) return null;
    if ((dword4D8CD8 & 1) === 0) {
        dword4D8CD8 |= 1;
        sub40FAD0EnsureInitialized();
    }
    return byte4D8227ForSectionType(a1.sectionRuntimeType4) ? a1 : null;
}

/**
 * decompiled sub_40FCF0:
 *   if (!a1) return 0;
 *   lazy-init sub_40FA00;
 *   return byte_4D8228[11*type] ? a1 : 0;
 */
export function sub40FCF0FilterByType8<T extends { sectionRuntimeType4: number }>(a1: T | null): T | null {
    if (!a1) return null;
    if ((dword4D8CD0 & 1) === 0) {
        dword4D8CD0 |= 1;
        sub40FA00EnsureInitialized();
    }
    return byte4D8228ForSectionType(a1.sectionRuntimeType4) ? a1 : null;
}

export function resetSectionTypeRegistryStateForTests(): void {
    dword4D7CEC = 0;
    dword4D7CF8 = 0;
    dword4D8CD0 = 0;
    dword4D8CD8 = 0;
    byte4D829C = 0;
}

export function getSectionTypeRegistryStateForTests(): Readonly<{
    dword4D7CEC: number;
    dword4D7CF8: number;
    dword4D8CD0: number;
    dword4D8CD8: number;
    byte4D829C: number;
}> {
    return {
        dword4D7CEC,
        dword4D7CF8,
        dword4D8CD0,
        dword4D8CD8,
        byte4D829C,
    };
}
