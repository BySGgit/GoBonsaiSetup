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

function swapItems<T>(arr: T[], i: number, j: number): void {
    if (i === j) return;
    const tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

/**
 * sub_451990: insertion sort for [start, end) with C comparator semantics.
 */
export function sub451990InsertionSortRange<T>(
    a1: T[],
    start: number,
    end: number,
    comparator: Sub451320Comparator<T>,
): void {
    const n = end - start;
    if (n <= 1) return;

    for (let i = start + 1; i < end; i++) {
        const item = a1[i];
        let insertAt = i;

        if (comparator(item, a1[start])) {
            while (insertAt > start) {
                a1[insertAt] = a1[insertAt - 1];
                insertAt--;
            }
            a1[start] = item;
            continue;
        }

        let j = i - 1;
        if (comparator(item, a1[j])) {
            do {
                a1[insertAt] = a1[j];
                insertAt = j;
                j--;
            } while (j >= start && comparator(item, a1[j]));
        }
        a1[insertAt] = item;
    }
}

/**
 * sub_451990: insertion sort for <= 32 elements.
 */
export function sub451990InsertionSort<T>(
    a1: T[],
    comparator: Sub451320Comparator<T>,
): void {
    sub451990InsertionSortRange(a1, 0, a1.length, comparator);
}

/**
 * sub_451A80: median-of-three ordering helper.
 */
export function sub451A80MedianOfThree<T>(
    a1: T[],
    i1: number,
    i2: number,
    i3: number,
    comparator: Sub451320Comparator<T>,
): boolean {
    if (comparator(a1[i2], a1[i1])) {
        swapItems(a1, i1, i2);
    }
    if (comparator(a1[i3], a1[i2])) {
        swapItems(a1, i2, i3);
    }
    const result = comparator(a1[i2], a1[i1]);
    if (result) {
        swapItems(a1, i1, i2);
    }
    return result;
}

/**
 * sub_451720: pivot preparation (median-of-three / median-of-nine).
 * `endInclusive` matches C-site usage (`a3 - 3`).
 */
export function sub451720SelectPivot<T>(
    a1: T[],
    start: number,
    mid: number,
    endInclusive: number,
    comparator: Sub451320Comparator<T>,
): void {
    const span = endInclusive - start;
    if (span <= 40) {
        sub451A80MedianOfThree(a1, start, mid, endInclusive, comparator);
        return;
    }

    const step = Math.floor((span + 1) / 8);
    sub451A80MedianOfThree(a1, start, start + step, start + step * 2, comparator);
    sub451A80MedianOfThree(a1, mid - step, mid, mid + step, comparator);
    sub451A80MedianOfThree(
        a1,
        endInclusive - step * 2,
        endInclusive - step,
        endInclusive,
        comparator,
    );
    sub451A80MedianOfThree(a1, start + step, mid, endInclusive - step, comparator);
}

export interface Sub451460PartitionResult {
    leftEnd: number;
    rightBegin: number;
}

/**
 * sub_451460: three-way partition around median pivot.
 * Returns `[start, leftEnd)` and `[rightBegin, end)` outer partitions.
 */
export function sub451460Partition<T>(
    a2: T[],
    start: number,
    end: number,
    comparator: Sub451320Comparator<T>,
): Sub451460PartitionResult {
    const mid = start + Math.floor((end - start) / 2);
    sub451720SelectPivot(a2, start, mid, end - 1, comparator);

    const pivot = a2[mid];
    let lt = start;
    let i = start;
    let gt = end - 1;

    while (i <= gt) {
        if (comparator(a2[i], pivot)) {
            swapItems(a2, lt, i);
            lt++;
            i++;
            continue;
        }
        if (comparator(pivot, a2[i])) {
            swapItems(a2, i, gt);
            gt--;
            continue;
        }
        i++;
    }

    return { leftEnd: lt, rightBegin: gt + 1 };
}

/**
 * sub_451C10: sift-up hole fill in heap (max-heap under C comparator semantics).
 */
export function sub451C10SiftUp<T>(
    a1: number,
    a2: T[],
    a3: number,
    a4: T,
    comparator: Sub451320Comparator<T>,
): number {
    let hole = a1;
    let parent = Math.floor((a1 - 1) / 2);
    while (a3 < hole) {
        if (!comparator(a2[parent], a4)) break;
        a2[hole] = a2[parent];
        hole = parent;
        parent = Math.floor((parent - 1) / 2);
    }
    a2[hole] = a4;
    return hole;
}

/**
 * sub_451B10: sift-down hole fill in heap (max-heap under C comparator semantics).
 */
export function sub451B10SiftDown<T>(
    a1: number,
    a2: T[],
    a3: number,
    a4: T,
    comparator: Sub451320Comparator<T>,
): void {
    let hole = a1;
    let child = hole * 2 + 2;

    while (child < a3) {
        if (comparator(a2[child], a2[child - 1])) {
            child--;
        }
        a2[hole] = a2[child];
        hole = child;
        child = hole * 2 + 2;
    }

    if (child === a3) {
        a2[hole] = a2[a3 - 1];
        hole = a3 - 1;
    }

    sub451C10SiftUp(hole, a2, a1, a4, comparator);
}

/**
 * sub_4517D0: heap build for [start, end).
 */
export function sub4517D0MakeHeap<T>(
    end: number,
    start: number,
    comparator: Sub451320Comparator<T>,
    a2: T[],
): void {
    const count = end - start;
    if (count <= 1) return;

    for (let root = Math.floor((count - 2) / 2); root >= 0; root--) {
        const temp = a2[start + root];
        let hole = root;

        while (true) {
            const left = hole * 2 + 1;
            if (left >= count) break;

            let child = left;
            const right = left + 1;
            if (
                right < count &&
                comparator(a2[start + child], a2[start + right])
            ) {
                child = right;
            }

            if (!comparator(temp, a2[start + child])) break;
            a2[start + hole] = a2[start + child];
            hole = child;
        }

        a2[start + hole] = temp;
    }
}

/**
 * sub_4518F0: heap sort for [start, end).
 */
export function sub4518F0HeapSort<T>(
    end: number,
    start: number,
    comparator: Sub451320Comparator<T>,
    a2: T[],
): void {
    if (end - start <= 1) return;

    for (let last = end - 1; last > start; last--) {
        const tmp = a2[last];
        a2[last] = a2[start];

        const heapSize = last - start;
        let hole = 0;

        while (true) {
            const left = hole * 2 + 1;
            if (left >= heapSize) break;
            let child = left;
            const right = left + 1;
            if (
                right < heapSize &&
                comparator(a2[start + child], a2[start + right])
            ) {
                child = right;
            }
            if (!comparator(tmp, a2[start + child])) break;
            a2[start + hole] = a2[start + child];
            hole = child;
        }
        a2[start + hole] = tmp;
    }
}

function sub451320SortRange<T>(
    a1: T[],
    start: number,
    end: number,
    a3: number,
    comparator: Sub451320Comparator<T>,
): void {
    let lo = start;
    let hi = end;
    let depth = a3 | 0;

    while (hi - lo > 32 && depth > 0) {
        const part = sub451460Partition(a1, lo, hi, comparator);
        depth = Math.floor(depth / 4) + Math.floor(depth / 2);

        if (part.leftEnd - lo >= hi - part.rightBegin) {
            sub451320SortRange(a1, part.rightBegin, hi, depth, comparator);
            hi = part.leftEnd;
        } else {
            sub451320SortRange(a1, lo, part.leftEnd, depth, comparator);
            lo = part.rightBegin;
        }
    }

    if (hi - lo <= 1) return;

    if (hi - lo <= 32) {
        sub451990InsertionSortRange(a1, lo, hi, comparator);
        return;
    }

    // depth exhausted: heapsort fallback
    sub4517D0MakeHeap(hi, lo, comparator, a1);
    sub4518F0HeapSort(hi, lo, comparator, a1);
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
    sub451320SortRange(a1, 0, a1.length, a3, comparator);
}
