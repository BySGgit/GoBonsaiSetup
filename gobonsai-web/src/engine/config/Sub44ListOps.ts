import { Sub4032WideString, sub4032D0Assign } from "./IniRegistrySub408600";

const SUB44_LIST_MAX = 0x3ffffffe; // 1073741822

export interface Sub44ListNode<T> {
    next: Sub44ListNode<T>;
    prev: Sub44ListNode<T>;
    payload: T | null;
}

export interface Sub44List<T> {
    head: Sub44ListNode<T>;
    size: number;
}

export interface Sub441E00Entry {
    rgba: [number, number, number, number];
    key: string;
}

export function sub44ListCreateNode<T>(payload: T): Sub44ListNode<T> {
    const node = {} as Sub44ListNode<T>;
    node.next = node;
    node.prev = node;
    node.payload = payload;
    return node;
}

/**
 * sub_44C360: allocate list node with explicit prev/next links.
 */
export function sub44C360CreateNode<T>(
    prev: Sub44ListNode<T>,
    next: Sub44ListNode<T>,
    payload: T,
): Sub44ListNode<T> {
    const node = sub44ListCreateNode(payload);
    node.prev = prev;
    node.next = next;
    return node;
}

function sub44ListInsertBefore<T>(
    before: Sub44ListNode<T>,
    node: Sub44ListNode<T>,
): void {
    node.prev = before.prev;
    node.next = before;
    before.prev.next = node;
    before.prev = node;
}

export function sub44ListPushBack<T>(list: Sub44List<T>, node: Sub44ListNode<T>): void {
    sub44ListInsertBefore(list.head, node);
    list.size++;
}

/**
 * sub_444090: initialize list sentinel + zero size.
 */
export function sub444090InitList<T>(): Sub44List<T> {
    const head = {} as Sub44ListNode<T>;
    head.next = head;
    head.prev = head;
    head.payload = null;
    return { head, size: 0 };
}

/**
 * sub_4440F0: destroy list nodes and reset to empty sentinel state.
 */
export function sub4440F0DestroyList<T>(list: Sub44List<T>): void {
    let it = list.head.next;
    while (it !== list.head) {
        const next = it.next;
        it.next = it;
        it.prev = it;
        it.payload = null;
        it = next;
    }
    list.head.next = list.head;
    list.head.prev = list.head;
    list.size = 0;
}

/**
 * sub_44B900: splice [first, lastExclusive) before `before`.
 * Mirrors std::list splice-style pointer surgery + size transfer.
 */
export function sub44B900SpliceRange<T>(
    movedCount: number,
    dst: Sub44List<T>,
    src: Sub44List<T>,
    before: Sub44ListNode<T>,
    first: Sub44ListNode<T>,
    lastExclusive: Sub44ListNode<T>,
): Sub44ListNode<T> {
    if (dst !== src) {
        if (SUB44_LIST_MAX - dst.size < movedCount) {
            throw new RangeError("list<T> too long");
        }
        dst.size += movedCount;
        src.size -= movedCount;
    }

    const firstPrev = first.prev;
    const lastPrev = lastExclusive.prev;
    const beforePrev = before.prev;

    // Detach from source
    firstPrev.next = lastExclusive;
    lastExclusive.prev = firstPrev;

    // Insert before destination iterator
    beforePrev.next = first;
    first.prev = beforePrev;
    lastPrev.next = before;
    before.prev = lastPrev;

    return lastExclusive;
}

/**
 * sub_44C260: merge sorted src into dst by key.
 */
export function sub44C260MergeByKey(
    dst: Sub44List<Sub441E00Entry>,
    src: Sub44List<Sub441E00Entry>,
): void {
    if (dst === src) return;

    let dstIt = dst.head.next;
    let srcIt = src.head.next;

    while (srcIt !== src.head) {
        if (dstIt === dst.head) {
            sub44B900SpliceRange(src.size, dst, src, dst.head, srcIt, src.head);
            return;
        }

        const srcKey = srcIt.payload?.key ?? "";
        const dstKey = dstIt.payload?.key ?? "";
        if (srcKey.localeCompare(dstKey) < 0) {
            const nextSrc = srcIt.next;
            sub44B900SpliceRange(1, dst, src, dstIt, srcIt, nextSrc);
            srcIt = nextSrc;
        } else {
            dstIt = dstIt.next;
        }
    }
}

/**
 * sub_44A600: initialize build/version marker string.
 */
export function sub44A600InitVersionString(a2: Sub4032WideString): Sub4032WideString {
    sub4032D0Assign(a2, "v0.276", 6);
    return a2;
}

/**
 * sub_441E00: create and insert record into sorted list by key.
 */
export function sub441E00InsertByKey(
    rgba: [number, number, number, number],
    list: Sub44List<Sub441E00Entry>,
    keyStorage: Sub4032WideString,
): Sub44ListNode<Sub441E00Entry> {
    if (list.size === SUB44_LIST_MAX) {
        throw new RangeError("list<T> too long");
    }

    let pos = list.head.next;
    while (pos !== list.head) {
        const existingKey = pos.payload?.key ?? "";
        if (keyStorage.value.localeCompare(existingKey) < 0) break;
        pos = pos.next;
    }

    const node = sub44C360CreateNode(pos.prev, pos, {
        rgba: [rgba[0], rgba[1], rgba[2], rgba[3]] as [
            number,
            number,
            number,
            number,
        ],
        key: keyStorage.value,
    });
    sub44ListInsertBefore(pos, node);
    list.size++;
    return node;
}
