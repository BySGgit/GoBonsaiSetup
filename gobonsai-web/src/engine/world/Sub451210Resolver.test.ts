import { beforeEach, describe, expect, it } from "vitest";
import {
    getSub451210SentinelNode,
    resetSub451210StateForTests,
    sub451210InsertNode,
    sub451210Resolve,
    sub451210ResolveKey,
} from "./Sub451210Resolver";

describe("sub_451210 resolver parity helper", () => {
    beforeEach(() => {
        resetSub451210StateForTests();
    });

    it("resolves exact key to node and sentinel for miss", () => {
        const nodeA = sub451210InsertNode(123, { id: "a" });
        const nodeB = sub451210InsertNode(456, { id: "b" });
        expect(sub451210ResolveKey(123)).toBe(nodeA);
        expect(sub451210ResolveKey(456)).toBe(nodeB);
        expect(sub451210ResolveKey(124)).toBe(getSub451210SentinelNode());
    });

    it("returns the first matching node for duplicate keys", () => {
        const first = sub451210InsertNode(777, { id: 1 });
        sub451210InsertNode(777, { id: 2 });
        expect(sub451210ResolveKey(777)).toBe(first);
    });

    it("writes resolved pointer through out parameter", () => {
        const out = { node: null as ReturnType<typeof getSub451210SentinelNode> | null };
        sub451210Resolve(out, 999);
        expect(out.node).toBe(getSub451210SentinelNode());
    });
});
