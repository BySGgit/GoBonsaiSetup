import { beforeEach, describe, expect, it } from "vitest";
import {
    getSub44E5D0Snapshot,
    resetSub44E5D0StateForTests,
    seedSub44E5D0FreePool,
    sub44E5D0Enqueue,
    sub44E5D0SetBaseTime,
} from "./Sub44E5D0Pool";

describe("sub_44E5D0 pool parity helper", () => {
    beforeEach(() => {
        resetSub44E5D0StateForTests();
    });

    it("does nothing for negative time offset", () => {
        seedSub44E5D0FreePool(1);
        const ok = sub44E5D0Enqueue(
            { x: 1, y: 2, z: 3, w: 4 },
            { x: 5, y: 6, z: 7 },
            { x: 8, y: 9, z: 10 },
            -0.1,
        );
        expect(ok).toBe(false);
        const snap = getSub44E5D0Snapshot();
        expect(snap.freeSize).toBe(1);
        expect(snap.activeSize).toBe(0);
    });

    it("moves one entry from free to active and copies payload", () => {
        seedSub44E5D0FreePool(1);
        sub44E5D0SetBaseTime(12.5);
        const ok = sub44E5D0Enqueue(
            { x: 1, y: 2, z: 3, w: 4 },
            { x: 5, y: 6, z: 7 },
            { x: 8, y: 9, z: 10 },
            0.25,
        );
        expect(ok).toBe(true);
        const snap = getSub44E5D0Snapshot();
        expect(snap.freeSize).toBe(0);
        expect(snap.activeSize).toBe(1);
        expect(snap.activePayloads[0].a2Vec).toEqual({ x: 5, y: 6, z: 7 });
        expect(snap.activePayloads[0].a3Vec).toEqual({ x: 8, y: 9, z: 10 });
        expect(snap.activePayloads[0].a1Quat).toEqual({ x: 1, y: 2, z: 3, w: 4 });
        expect(snap.activePayloads[0].time40).toBeCloseTo(12.75, 6);
    });
});
