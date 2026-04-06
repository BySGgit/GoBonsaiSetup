import { beforeEach, describe, expect, it } from "vitest";
import {
    createBooleanPropertyBinding,
    createNumericPropertyBinding,
    createSub4032WideString,
    createSub408600Entry,
    getIniRegistrySnapshot,
    resetIniRegistryForTests,
    setIniBooleanValueByKey,
    setIniNumericValueByKey,
    sub4038B0Register,
    sub4033D0InitAssign,
    sub403410Reset,
    sub4032D0Assign,
    sub4032View,
    sub401DD0DestroyIniEntry,
    sub408600Register,
} from "./IniRegistrySub408600";

describe("IniRegistrySub408600 parity helpers", () => {
    beforeEach(() => {
        resetIniRegistryForTests();
    });

    it("sub_4032D0 assigns and grows capacity above SSO", () => {
        const s = createSub4032WideString();
        sub4032D0Assign(s, "directLightPercent", 0x12);
        expect(s.value).toBe("directLightPercent");
        expect(s.length16).toBe(0x12);
        expect(s.capacity20).toBeGreaterThanOrEqual(0x12);
    });

    it("sub_4032D0 handles aliasing via source view (same storage)", () => {
        const s = createSub4032WideString("abcdef");
        sub4032D0Assign(s, sub4032View(s, 2), 3);
        expect(s.value).toBe("cde");
        expect(s.length16).toBe(3);
    });

    it("sub_4033D0 initializes small string and assigns full source", () => {
        const dest = createSub4032WideString("will-be-reset");
        dest.capacity20 = 128;
        sub4033D0InitAssign("lightDecayAmount", dest);
        expect(dest.value).toBe("lightDecayAmount");
        expect(dest.length16).toBe("lightDecayAmount".length);
        expect(dest.capacity20).toBeGreaterThanOrEqual(7);
    });

    it("sub_403410 resets to empty small-string state", () => {
        const dest = createSub4032WideString("abcdefghi");
        expect(dest.capacity20).toBeGreaterThanOrEqual(9);
        sub403410Reset(dest);
        expect(dest.value).toBe("");
        expect(dest.length16).toBe(0);
        expect(dest.capacity20).toBe(7);
    });

    it("sub_408600 lazily initializes registry once and keeps sorted keys", () => {
        const firstName = createSub4032WideString();
        sub4032D0Assign(firstName, "zeta", 4);
        const firstMeta = createSub408600Entry();
        const firstTarget = { v: 0.1 };
        sub408600Register(firstName, firstMeta, createNumericPropertyBinding(firstTarget, "v"));

        const secondName = createSub4032WideString();
        sub4032D0Assign(secondName, "alpha", 5);
        const secondMeta = createSub408600Entry();
        const secondTarget = { v: 0.2 };
        sub408600Register(secondName, secondMeta, createNumericPropertyBinding(secondTarget, "v"));

        const snap = getIniRegistrySnapshot();
        expect(snap.size).toBe(2);
        expect(snap.initCalls43FD00).toBe(1);
        expect(snap.initMask4D8EC0 & 1).toBe(1);
        expect(snap.keys).toEqual(["alpha", "zeta"]);
    });

    it("setIniNumericValueByKey writes through bound property", () => {
        const key = createSub4032WideString();
        sub4032D0Assign(key, "directLightPercent", 0x12);
        const meta = createSub408600Entry();
        const target = { value: 0.5 };
        sub408600Register(key, meta, createNumericPropertyBinding(target, "value"));

        const applied = setIniNumericValueByKey("directLightPercent", 0.75);
        expect(applied).toBe(true);
        expect(target.value).toBeCloseTo(0.75, 6);
    });

    it("sub_4038B0 registers bool entries as type 7 and applies bool values", () => {
        const key = createSub4032WideString();
        sub4032D0Assign(key, "updateGrowth", 0x0c);
        const meta = createSub408600Entry();
        const target = { value: false };
        sub4038B0Register(key, meta, createBooleanPropertyBinding(target, "value"));
        expect(meta.valueType32).toBe(7);

        const ok = setIniBooleanValueByKey("updateGrowth", true);
        expect(ok).toBe(true);
        expect(target.value).toBe(true);
    });

    it("sub_401DD0 removes matching registry entry and resets key storage", () => {
        const firstName = createSub4032WideString();
        sub4032D0Assign(firstName, "alpha", 5);
        const firstMeta = createSub408600Entry();
        sub408600Register(firstName, firstMeta, createNumericPropertyBinding({ v: 1 }, "v"));

        const secondName = createSub4032WideString();
        sub4032D0Assign(secondName, "zeta", 4);
        const secondMeta = createSub408600Entry();
        sub408600Register(secondName, secondMeta, createNumericPropertyBinding({ v: 2 }, "v"));

        sub401DD0DestroyIniEntry(secondMeta);

        const snap = getIniRegistrySnapshot();
        expect(snap.size).toBe(1);
        expect(snap.keys).toEqual(["alpha"]);
        expect(secondMeta.keyStorage20.value).toBe("");
        expect(secondMeta.keyStorage20.length16).toBe(0);
        expect(secondMeta.keyStorage20.capacity20).toBe(7);
    });
});
