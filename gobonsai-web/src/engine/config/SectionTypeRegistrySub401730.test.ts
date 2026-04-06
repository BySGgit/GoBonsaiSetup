import { beforeEach, describe, expect, it } from "vitest";
import { GrowthConstants } from "./GrowthConstants";
import {
    getSectionTypeRegistryStateForTests,
    resetSectionTypeRegistryStateForTests,
    sub403B40EnsureType5Base,
    sub401730RegisterType,
    sub40FC70FilterByType7,
    sub40FCF0FilterByType8,
    sub4079C0EnsureInitialized,
    sub413CF0FilterByType5,
} from "./SectionTypeRegistrySub401730";

function clearTypeTables(): void {
    GrowthConstants.BYTE_4D8220_STRIDE11.fill(0);
    GrowthConstants.BYTE_4D8225_STRIDE11.fill(0);
    GrowthConstants.BYTE_4D8227_STRIDE11.fill(0);
    GrowthConstants.BYTE_4D8228_STRIDE11.fill(0);
}

describe("SectionTypeRegistrySub401730", () => {
    beforeEach(() => {
        resetSectionTypeRegistryStateForTests();
        clearTypeTables();
    });

    it("sub_401730 marks type flag0 and toggles byte_4D829C for type 0", () => {
        const ret = sub401730RegisterType(0);
        expect(ret).toBe(0);
        expect(GrowthConstants.BYTE_4D8220_STRIDE11[0]).toBe(1);
        expect(getSectionTypeRegistryStateForTests().byte4D829C).toBe(1);
    });

    it("sub_4079C0 ensures type 5 flags used by runtime checks", () => {
        sub4079C0EnsureInitialized();
        expect(GrowthConstants.BYTE_4D8220_STRIDE11[11 * 5]).toBe(1);
        expect(GrowthConstants.BYTE_4D8225_STRIDE11[11 * 5]).toBe(1);
        expect(getSectionTypeRegistryStateForTests().dword4D7CF8 & 1).toBe(1);
    });

    it("sub_403B40 returns base type id 5 and initializes gate once", () => {
        expect(sub403B40EnsureType5Base()).toBe(5);
        expect(sub403B40EnsureType5Base()).toBe(5);
        expect(GrowthConstants.BYTE_4D8220_STRIDE11[11 * 5]).toBe(1);
        expect(GrowthConstants.BYTE_4D8225_STRIDE11[11 * 5]).toBe(1);
        expect(getSectionTypeRegistryStateForTests().dword4D7CF8 & 1).toBe(1);
    });

    it("sub_413CF0 returns input only for registered type5 table entries", () => {
        const twigLike = { sectionRuntimeType4: 10, id: "twig" };
        const seedLike = { sectionRuntimeType4: 8, id: "seed" };

        // With cleared table, nothing passes.
        expect(sub413CF0FilterByType5(twigLike)).toBeNull();
        expect(sub413CF0FilterByType5(seedLike)).toBeNull();

        GrowthConstants.BYTE_4D8225_STRIDE11[11 * 10] = 1;
        expect(sub413CF0FilterByType5(twigLike)).toBe(twigLike);
        expect(sub413CF0FilterByType5(seedLike)).toBeNull();
    });

    it("sub_40FC70 lazily initializes leaf flag table and filters by flag #7", () => {
        const leaf = { sectionRuntimeType4: 7, id: "leaf" };
        const twig = { sectionRuntimeType4: 10, id: "twig" };

        expect(sub40FC70FilterByType7(leaf)).toBe(leaf);
        expect(sub40FC70FilterByType7(twig)).toBeNull();
        expect(GrowthConstants.BYTE_4D8227_STRIDE11[11 * 7]).toBe(1);
        expect(GrowthConstants.BYTE_4D8225_STRIDE11[11 * 7]).toBe(1);
        expect(GrowthConstants.BYTE_4D8220_STRIDE11[11 * 7]).toBe(1);
        expect(getSectionTypeRegistryStateForTests().dword4D8CD8 & 1).toBe(1);
    });

    it("sub_40FCF0 lazily initializes seed flag table and filters by flag #8", () => {
        const seed = { sectionRuntimeType4: 8, id: "seed" };
        const leaf = { sectionRuntimeType4: 7, id: "leaf" };

        expect(sub40FCF0FilterByType8(seed)).toBe(seed);
        expect(sub40FCF0FilterByType8(leaf)).toBeNull();
        expect(GrowthConstants.BYTE_4D8228_STRIDE11[11 * 8]).toBe(1);
        expect(GrowthConstants.BYTE_4D8225_STRIDE11[11 * 8]).toBe(1);
        expect(GrowthConstants.BYTE_4D8220_STRIDE11[11 * 8]).toBe(1);
        expect(getSectionTypeRegistryStateForTests().dword4D8CD0 & 1).toBe(1);
    });
});
