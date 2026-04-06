export type Sub451320Comparator<T> = (a: T, b: T) => boolean;

export interface Sub450E10HitRecord<TSection> {
    section: TSection;
    sortT: number;
    aux: number;
}

/**
 * sub_450E10: return *(b+4) > *(a+4).
 * For hit records this compares `sortT` and yields ascending order by sortT.
 */
export function sub450E10CompareHitSortT<TSection>(
    a: Sub450E10HitRecord<TSection>,
    b: Sub450E10HitRecord<TSection>,
): boolean {
    return b.sortT > a.sortT;
}

/**
 * sub_451990: insertion sort for <= 32 elements.
 */
export function sub451990InsertionSort<T>(
    a1: T[],
    comparator: Sub451320Comparator<T>,
): void {
    const n = a1.length;
    if (n <= 1) return;

    for (let i = 1; i < n; i++) {
        const item = a1[i];
        let insertAt = i;

        if (comparator(item, a1[0])) {
            while (insertAt > 0) {
                a1[insertAt] = a1[insertAt - 1];
                insertAt--;
            }
            a1[0] = item;
            continue;
        }

        let j = i - 1;
        if (comparator(item, a1[j])) {
            do {
                a1[insertAt] = a1[j];
                insertAt = j;
                j--;
            } while (j >= 0 && comparator(item, a1[j]));
        }
        a1[insertAt] = item;
    }
}

/**
 * sub_451320:
 * - for size <= 32: insertion sort (sub_451990)
 * - deep introsort/heapsort branch exists in EXE but is not reached from sub_450E30
 *   because hit count is capped at 30.
 */
export function sub451320Sort<T>(
    a1: T[],
    a3: number,
    comparator: Sub451320Comparator<T>,
): void {
    const n = a1.length;
    if (n <= 32) {
        sub451990InsertionSort(a1, comparator);
        return;
    }

    // Fallback for non-hit callsites: normalize comparator to Array.sort contract.
    // This path is kept as pragmatic safety; runtime parity path uses n <= 30.
    const _limit = a3;
    void _limit;
    a1.sort((lhs, rhs) => {
        if (comparator(lhs, rhs)) return -1;
        if (comparator(rhs, lhs)) return 1;
        return 0;
    });
}
