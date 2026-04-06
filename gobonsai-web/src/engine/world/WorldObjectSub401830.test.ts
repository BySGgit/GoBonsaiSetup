import { beforeEach, describe, expect, it } from "vitest";
import {
    getSub401830RegistrySnapshot,
    resetSub401830StateForTests,
    sub402E10MaybeRehash,
    sub402EE0TransferOne,
    sub402F60InsertFilled,
    sub4031B0AllocatePointerVector,
    sub403210FillValue,
    sub4032A0CopyForward,
    sub44EDE0EraseAt,
    sub401830ConstructWorldObject,
    sub402CD0InsertById,
    sub403230CreateWorldNode,
} from "./WorldObjectSub401830";

describe("WorldObjectSub401830 parity wrappers", () => {
    beforeEach(() => {
        resetSub401830StateForTests();
    });

    it("sub_401830 initializes base fields and appends object to global list", () => {
        const a = sub401830ConstructWorldObject();
        const b = sub401830ConstructWorldObject();

        expect(a.vtableTag0).toBe("WorldObject");
        expect(a.runtimeType4).toBe(0);
        expect(a.matrix40).toEqual([1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]);
        expect(a.matrix104).toEqual([1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]);
        expect(a.objectId184).toBe(1);
        expect(b.objectId184).toBe(2);

        const snap = getSub401830RegistrySnapshot();
        expect(snap.listSize).toBe(2);
        expect(snap.ids).toEqual([1, 2]);
    });

    it("sub_403230 builds intrusive node with explicit links", () => {
        const obj = sub401830ConstructWorldObject();
        const sentinel = sub403230CreateWorldNode([0, obj], null as never, null as never);
        sentinel.next = sentinel;
        sentinel.prev = sentinel;
        const n = sub403230CreateWorldNode([123, obj], sentinel, sentinel);
        expect(n.objectId).toBe(123);
        expect(n.objectRef).toBe(obj);
        expect(n.next).toBe(sentinel);
        expect(n.prev).toBe(sentinel);
    });

    it("sub_402CD0 rejects duplicate id inserts", () => {
        const obj = sub401830ConstructWorldObject();
        const index = { byId: new Map<number, ReturnType<typeof sub403230CreateWorldNode>>() };
        const n1 = sub403230CreateWorldNode([42, obj], null as never, null as never);
        const n2 = sub403230CreateWorldNode([42, obj], null as never, null as never);
        const first = sub402CD0InsertById(index, n1);
        const second = sub402CD0InsertById(index, n2);
        expect(first.inserted).toBe(true);
        expect(second.inserted).toBe(false);
        expect(second.node).toBe(n1);
    });

    it("sub_4031B0 allocates pointer-vector storage", () => {
        const vec = sub4031B0AllocatePointerVector(4);
        expect(vec).toEqual([null, null, null, null]);
    });

    it("sub_403210 and sub_4032A0 fill/copy helper semantics", () => {
        const dst = [0, 0, 0, 0];
        sub403210FillValue(2, 7, dst, 1);
        expect(dst).toEqual([0, 7, 7, 0]);

        const out: number[] = [];
        const end = sub4032A0CopyForward(out, 0, [9, 8, 7, 6], 1, 3);
        expect(end).toBe(2);
        expect(out).toEqual([8, 7]);
    });

    it("sub_402F60 inserts repeated values and sub_402EE0 transfers one", () => {
        const vec = [1, 4];
        sub402F60InsertFilled(2, vec, 1, 9);
        expect(vec).toEqual([1, 9, 9, 4]);

        const src = [10, 11, 12];
        const dst = [20];
        sub402EE0TransferOne(src, dst, 1, 1);
        expect(src).toEqual([10, 12]);
        expect(dst).toEqual([20, 11]);
    });

    it("sub_44EDE0 erases element and returns next index", () => {
        const list = [100, 200, 300];
        const next = sub44EDE0EraseAt(list, 1);
        expect(list).toEqual([100, 300]);
        expect(next).toBe(1);
    });

    it("sub_402E10 rehashes buckets when load factor is exceeded", () => {
        const table = {
            size8: 4,
            bucketCount36: 2,
            mask32: 1,
            maxLoad40: 1.0,
            buckets: [[], []] as number[][],
            entries: [1, 2, 3, 4],
            hash: (x: number) => x,
        };
        sub402E10MaybeRehash(table);
        expect(table.bucketCount36).toBeGreaterThan(2);
        expect(table.mask32).toBe(table.bucketCount36 - 1);
        const total = table.buckets.reduce((acc, b) => acc + b.length, 0);
        expect(total).toBe(4);
    });
});
