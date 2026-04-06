import {
    Sub4032WideString,
    sub4032D0Assign,
    sub403410Reset,
} from "./IniRegistrySub408600";

const SUB44_STRING_MAX = 0x7ffffffe;

/**
 * sub_44BC80: append `count` UTF-16 chars from `src` to `dest`.
 */
export function sub44BC80Append(
    dest: Sub4032WideString,
    src: string,
    count: number,
): Sub4032WideString {
    const append = src.slice(0, Math.max(0, count));
    const next = dest.value + append;
    sub4032D0Assign(dest, next, next.length);
    return dest;
}

/**
 * sub_444AE0: move-assign wide string storage (`dst = src`, `src = ""`).
 */
export function sub444AE0MoveAssign(
    src: Sub4032WideString,
    dst: Sub4032WideString,
): Sub4032WideString {
    if (src === dst) return dst;
    sub4032D0Assign(dst, src.value, src.value.length);
    sub403410Reset(src);
    return dst;
}

/**
 * sub_44C210: lower-case copy for [start, end) interval.
 */
export function sub44C210CopyLowerRange(
    text: string,
    start: number,
    end: number,
): string {
    const s = Math.max(0, start);
    const e = Math.max(s, end);
    return text.slice(s, e).toLowerCase();
}

/**
 * sub_444C00: find first occurrence of `needle[0..count)` in `haystack`.
 * Returns char index, or -1 when not found.
 */
export function sub444C00FindSubstr(
    haystack: Sub4032WideString,
    needle: string | Sub4032WideString,
    count: number,
): number {
    const c = Math.max(0, count);
    if (c === 0) return 0;
    const n = typeof needle === "string" ? needle.slice(0, c) : needle.value.slice(0, c);
    return haystack.value.indexOf(n);
}

/**
 * sub_44A460: append a substring from `src` (`[pos, pos+count)`) to `dest`.
 */
export function sub44A460AppendRange(
    dest: Sub4032WideString,
    src: Sub4032WideString,
    pos: number,
    count: number,
): Sub4032WideString {
    const p = pos >>> 0;
    if (src.length16 < p) {
        throw new RangeError("invalid string position");
    }
    let copyLen = count >>> 0;
    const remaining = src.length16 - p;
    if (copyLen > remaining) {
        copyLen = remaining;
    }
    const newLen = dest.length16 + copyLen;
    if (newLen > SUB44_STRING_MAX) {
        throw new RangeError("string too long");
    }
    if (copyLen === 0) {
        return dest;
    }
    const append = src.value.slice(p, p + copyLen);
    const next = dest.value + append;
    sub4032D0Assign(dest, next, next.length);
    return dest;
}
