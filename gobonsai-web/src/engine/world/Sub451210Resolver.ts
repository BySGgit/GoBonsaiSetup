const HASH_XOR = 0xdeadbeef;
const HASH_POS_MASK = 0x7fffffff;
const HASH_DIVISOR = 127773;
const HASH_A = 16807;
const HASH_B = 2836;

export interface Sub451210Node {
    next: Sub451210Node;
    key2: number;
    section12: unknown;
    isBucketEnd: boolean;
}

interface Sub451210Bucket {
    head: Sub451210Node;
    end: Sub451210Node;
}

interface Sub451210State {
    dword4D8C2CMask: number;
    dword4D8C30Split: number;
    dword4D8C10Sentinel: Sub451210Node;
    dword4D8C1CBuckets: Sub451210Bucket[];
}

let state = createState(0x0f, 0x08);

function createSentinel(): Sub451210Node {
    const sentinel = {} as Sub451210Node;
    sentinel.next = sentinel;
    sentinel.key2 = 0;
    sentinel.section12 = null;
    sentinel.isBucketEnd = true;
    return sentinel;
}

function createBucket(): Sub451210Bucket {
    const end = createSentinel();
    return { head: end, end };
}

function createState(mask: number, split: number): Sub451210State {
    const dword4D8C10Sentinel = createSentinel();
    const bucketCount = (mask >>> 0) + 1;
    const dword4D8C1CBuckets: Sub451210Bucket[] = [];
    for (let i = 0; i < bucketCount; i++) {
        dword4D8C1CBuckets.push(createBucket());
    }
    return {
        dword4D8C2CMask: mask >>> 0,
        dword4D8C30Split: split >>> 0,
        dword4D8C10Sentinel,
        dword4D8C1CBuckets,
    };
}

function normalizeBucketIndex(index: number): number {
    const count = state.dword4D8C1CBuckets.length;
    if (count === 0) return 0;
    let i = index % count;
    if (i < 0) i += count;
    return i;
}

function sub451210BucketIndex(rawKey: number): number {
    const mask = state.dword4D8C2CMask >>> 0;
    const split = state.dword4D8C30Split >>> 0;

    const key = ((rawKey ^ HASH_XOR) & HASH_POS_MASK) >>> 0;
    const quot = Math.floor(key / HASH_DIVISOR) >>> 0;
    const rem = key % HASH_DIVISOR;
    let seeded = HASH_A * rem - HASH_B * quot;
    if (seeded < 0) {
        seeded += 0x7fffffff;
    }
    let bucket = (seeded & mask) >>> 0;
    if (split <= bucket) {
        bucket -= (mask >>> 1) + 1;
    }
    return normalizeBucketIndex(bucket);
}

export function resetSub451210StateForTests(mask = 0x0f, split = 0x08): void {
    state = createState(mask, split);
}

export function getSub451210SentinelNode(): Sub451210Node {
    return state.dword4D8C10Sentinel;
}

export function sub451210InsertNode(key2: number, section12: unknown): Sub451210Node {
    const bucketIndex = sub451210BucketIndex(key2 >>> 0);
    const bucket = state.dword4D8C1CBuckets[bucketIndex];
    const node: Sub451210Node = {
        next: bucket.end,
        key2: key2 >>> 0,
        section12,
        isBucketEnd: false,
    };

    if (bucket.head === bucket.end || (bucket.head.key2 >>> 0) > (node.key2 >>> 0)) {
        node.next = bucket.head;
        bucket.head = node;
        return node;
    }

    let prev = bucket.head;
    while (prev.next !== bucket.end && (prev.next.key2 >>> 0) <= (node.key2 >>> 0)) {
        prev = prev.next;
    }
    node.next = prev.next;
    prev.next = node;
    return node;
}

/**
 * sub_451210:
 * resolve key payload to node pointer; returns dword_4D8C10 sentinel when not found.
 */
export function sub451210ResolveKey(keyRef2: number): Sub451210Node {
    const target = keyRef2 >>> 0;
    const bucketIndex = sub451210BucketIndex(target);
    const bucket = state.dword4D8C1CBuckets[bucketIndex];

    let it = bucket.head;
    while (it !== bucket.end) {
        const k = it.key2 >>> 0;
        if (k >= target) {
            break;
        }
        it = it.next;
    }

    if (it === bucket.end) {
        return state.dword4D8C10Sentinel;
    }
    if ((it.key2 >>> 0) !== target) {
        return state.dword4D8C10Sentinel;
    }
    return it;
}

export function sub451210Resolve(
    out: { node: Sub451210Node | null },
    keyRef2: number,
): { node: Sub451210Node | null } {
    out.node = sub451210ResolveKey(keyRef2);
    return out;
}
