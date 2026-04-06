import {
    Sub4032WideString,
    sub403410Reset,
} from "./IniRegistrySub408600";
import { Sub44List } from "./Sub44ListOps";

/**
 * sub_446B40: reset wide-string records in [startIndex, endIndex).
 */
export function sub446B40ResetWideRange(
    items: Sub4032WideString[],
    startIndex = 0,
    endIndex = items.length,
): void {
    const from = Math.max(0, startIndex);
    const to = Math.min(items.length, Math.max(from, endIndex));
    for (let i = from; i < to; i++) {
        sub403410Reset(items[i]);
    }
}

/**
 * sub_444140: destroy intrusive list nodes and reset sentinel links/size.
 * Optional callback mirrors per-node payload cleanup before node free.
 */
export function sub444140DestroyList<T>(
    list: Sub44List<T>,
    resetPayload?: (payload: T) => void,
): void {
    const head = list.head;
    let it = head.next;
    head.next = head;
    head.prev = head;
    list.size = 0;

    while (it !== head) {
        const next = it.next;
        if (resetPayload && it.payload !== null) {
            resetPayload(it.payload);
        }
        it.next = it;
        it.prev = it;
        it = next;
    }
}

export interface Sub444CE0BucketState {
    table4: Array<unknown | null>;
    bucketCount8: number;
    activeCount12: number;
    refCount16: number;
}

/**
 * sub_444CE0: release bucket table storage and drop refcounted active count.
 */
export function sub444CE0DestroyBucketState(state: Sub444CE0BucketState): void {
    while (state.refCount16 > 0) {
        state.refCount16--;
        if (state.refCount16 === 0) {
            state.activeCount12 = 0;
        }
    }
    const limit = Math.min(state.bucketCount8, state.table4.length);
    for (let i = 0; i < limit; i++) {
        state.table4[i] = null;
    }
    state.table4 = [];
    state.bucketCount8 = 0;
}
