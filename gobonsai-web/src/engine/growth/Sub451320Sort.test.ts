import { describe, expect, it } from "vitest";
import {
    sub450E10CompareHitSortT,
    sub451320Sort,
    Sub450E10HitRecord,
} from "./Sub451320Sort";

type Rec = Sub450E10HitRecord<string>;

function rec(section: string, sortT: number): Rec {
    return { section, sortT, aux: 0 };
}

describe("sub_451320/sub_450E10 hit sort parity", () => {
    it("sorts by sortT ascending (C comparator semantics)", () => {
        const hits: Rec[] = [rec("c", 3), rec("a", 1), rec("b", 2)];
        sub451320Sort(hits, hits.length, sub450E10CompareHitSortT);
        expect(hits.map((h) => h.section)).toEqual(["a", "b", "c"]);
        expect(hits.map((h) => h.sortT)).toEqual([1, 2, 3]);
    });

    it("keeps equal-key order for insertion-sort path", () => {
        const hits: Rec[] = [rec("a", 1), rec("b", 1), rec("c", 2), rec("d", 2)];
        sub451320Sort(hits, hits.length, sub450E10CompareHitSortT);
        expect(hits.map((h) => h.section)).toEqual(["a", "b", "c", "d"]);
    });

    it("supports single and empty arrays", () => {
        const one: Rec[] = [rec("x", 7)];
        sub451320Sort(one, one.length, sub450E10CompareHitSortT);
        expect(one.map((h) => h.section)).toEqual(["x"]);

        const none: Rec[] = [];
        sub451320Sort(none, 0, sub450E10CompareHitSortT);
        expect(none).toEqual([]);
    });

    it("sorts ranges > 32 through introsort branch", () => {
        const hits: Rec[] = [];
        for (let i = 0; i < 96; i++) {
            const t = ((i * 17) % 31) + Math.floor(i / 9);
            hits.push(rec(`s${i}`, t));
        }

        sub451320Sort(hits, hits.length, sub450E10CompareHitSortT);

        for (let i = 1; i < hits.length; i++) {
            expect(hits[i - 1].sortT <= hits[i].sortT).toBe(true);
        }

        expect(new Set(hits.map((h) => h.section)).size).toBe(96);
    });

    it("sorts ranges > 32 when depth budget is exhausted (heap fallback)", () => {
        const hits: Rec[] = [];
        for (let i = 0; i < 64; i++) {
            const t = ((i * 23) % 19) + Math.floor(i / 8);
            hits.push(rec(`h${i}`, t));
        }

        sub451320Sort(hits, 0, sub450E10CompareHitSortT);

        for (let i = 1; i < hits.length; i++) {
            expect(hits[i - 1].sortT <= hits[i].sortT).toBe(true);
        }
    });
});
