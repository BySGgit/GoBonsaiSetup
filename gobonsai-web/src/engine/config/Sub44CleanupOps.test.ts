import { describe, expect, it } from "vitest";
import {
    createSub4032WideString,
} from "./IniRegistrySub408600";
import {
    sub444090InitList,
    sub44C360CreateNode,
} from "./Sub44ListOps";
import {
    Sub444CE0BucketState,
    sub444140DestroyList,
    sub444CE0DestroyBucketState,
    sub446B40ResetWideRange,
} from "./Sub44CleanupOps";

describe("Sub44CleanupOps parity wrappers", () => {
    it("sub_446B40 resets strings in target range", () => {
        const a = createSub4032WideString("alpha");
        const b = createSub4032WideString("beta");
        const c = createSub4032WideString("gamma");
        sub446B40ResetWideRange([a, b, c], 1, 3);
        expect(a.value).toBe("alpha");
        expect(b.value).toBe("");
        expect(c.value).toBe("");
    });

    it("sub_444140 destroys intrusive list and invokes payload reset callback", () => {
        const list = sub444090InitList<{ key: string }>();
        const a = sub44C360CreateNode(list.head, list.head, { key: "alpha" });
        list.head.next = a;
        list.head.prev = a;
        list.size = 1;
        const b = sub44C360CreateNode(a, list.head, { key: "beta" });
        a.next = b;
        list.head.prev = b;
        list.size = 2;

        const seen: string[] = [];
        sub444140DestroyList(list, (payload) => {
            seen.push(payload.key);
            payload.key = "";
        });

        expect(list.size).toBe(0);
        expect(list.head.next).toBe(list.head);
        expect(list.head.prev).toBe(list.head);
        expect(seen.sort()).toEqual(["alpha", "beta"]);
    });

    it("sub_444CE0 releases bucket storage and drops active count", () => {
        const state: Sub444CE0BucketState = {
            table4: [{}, null, {}],
            bucketCount8: 3,
            activeCount12: 7,
            refCount16: 2,
        };
        sub444CE0DestroyBucketState(state);
        expect(state.refCount16).toBe(0);
        expect(state.activeCount12).toBe(0);
        expect(state.bucketCount8).toBe(0);
        expect(state.table4).toEqual([]);
    });
});
