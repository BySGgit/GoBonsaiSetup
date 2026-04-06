import { describe, expect, it } from "vitest";
import { createSub4032WideString } from "./IniRegistrySub408600";
import {
    sub441E00InsertByKey,
    sub444090InitList,
    sub4440F0DestroyList,
    sub44A600InitVersionString,
    sub44C260MergeByKey,
    sub44ListCreateNode,
    sub44ListPushBack,
} from "./Sub44ListOps";

describe("Sub44ListOps parity wrappers", () => {
    it("sub_44A600 writes version string", () => {
        const s = createSub4032WideString();
        sub44A600InitVersionString(s);
        expect(s.value).toBe("v0.276");
    });

    it("sub_444090/sub_4440F0 init and clear list", () => {
        const list = sub444090InitList<number>();
        sub44ListPushBack(list, sub44ListCreateNode(1));
        sub44ListPushBack(list, sub44ListCreateNode(2));
        expect(list.size).toBe(2);

        sub4440F0DestroyList(list);
        expect(list.size).toBe(0);
        expect(list.head.next).toBe(list.head);
        expect(list.head.prev).toBe(list.head);
    });

    it("sub_441E00 inserts entries sorted by key", () => {
        const list = sub444090InitList<{
            rgba: [number, number, number, number];
            key: string;
        }>();
        const a = createSub4032WideString("zeta");
        const b = createSub4032WideString("alpha");
        const c = createSub4032WideString("gamma");

        sub441E00InsertByKey([1, 1, 1, 1], list, a);
        sub441E00InsertByKey([2, 2, 2, 2], list, b);
        sub441E00InsertByKey([3, 3, 3, 3], list, c);

        const keys: string[] = [];
        for (let it = list.head.next; it !== list.head; it = it.next) {
            keys.push(it.payload?.key ?? "");
        }
        expect(keys).toEqual(["alpha", "gamma", "zeta"]);
    });

    it("sub_44C260 merges two sorted lists by key", () => {
        const dst = sub444090InitList<{ rgba: [number, number, number, number]; key: string }>();
        const src = sub444090InitList<{ rgba: [number, number, number, number]; key: string }>();

        sub441E00InsertByKey([1, 1, 1, 1], dst, createSub4032WideString("beta"));
        sub441E00InsertByKey([1, 1, 1, 1], dst, createSub4032WideString("delta"));
        sub441E00InsertByKey([1, 1, 1, 1], src, createSub4032WideString("alpha"));
        sub441E00InsertByKey([1, 1, 1, 1], src, createSub4032WideString("gamma"));

        sub44C260MergeByKey(dst, src);

        const keys: string[] = [];
        for (let it = dst.head.next; it !== dst.head; it = it.next) {
            keys.push(it.payload?.key ?? "");
        }
        expect(keys).toEqual(["alpha", "beta", "delta", "gamma"]);
        expect(src.size).toBe(0);
        expect(src.head.next).toBe(src.head);
    });
});

