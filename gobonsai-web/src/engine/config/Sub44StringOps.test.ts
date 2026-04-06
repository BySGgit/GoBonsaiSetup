import { describe, expect, it } from "vitest";
import { createSub4032WideString } from "./IniRegistrySub408600";
import {
    sub444AE0MoveAssign,
    sub444C00FindSubstr,
    sub44A460AppendRange,
    sub44BC80Append,
    sub44C210CopyLowerRange,
} from "./Sub44StringOps";

describe("Sub44StringOps parity wrappers", () => {
    it("sub_44BC80 appends UTF-16 text prefix", () => {
        const dst = createSub4032WideString("ab");
        sub44BC80Append(dst, "CDEF", 2);
        expect(dst.value).toBe("abCD");
    });

    it("sub_444AE0 move-assigns and clears source", () => {
        const src = createSub4032WideString("source");
        const dst = createSub4032WideString("dst");
        sub444AE0MoveAssign(src, dst);
        expect(dst.value).toBe("source");
        expect(src.value).toBe("");
    });

    it("sub_44C210 copies lowercase range", () => {
        expect(sub44C210CopyLowerRange("AbCDeF", 1, 5)).toBe("bcde");
    });

    it("sub_444C00 finds substring with count limit", () => {
        const h = createSub4032WideString("alphabet");
        expect(sub444C00FindSubstr(h, "phaXYZ", 3)).toBe(2);
        expect(sub444C00FindSubstr(h, "zzz", 3)).toBe(-1);
        expect(sub444C00FindSubstr(h, "ignored", 0)).toBe(0);
    });

    it("sub_44A460 appends source range with clamp semantics", () => {
        const dst = createSub4032WideString("left");
        const src = createSub4032WideString("rightSide");
        sub44A460AppendRange(dst, src, 5, 0xffffffff);
        expect(dst.value).toBe("leftSide");
    });

    it("sub_44A460 throws on invalid position", () => {
        const dst = createSub4032WideString("dst");
        const src = createSub4032WideString("abc");
        expect(() => sub44A460AppendRange(dst, src, 10, 1)).toThrow("invalid string position");
    });
});
