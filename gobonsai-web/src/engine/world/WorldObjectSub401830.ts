import { sub401730RegisterType } from "../config/SectionTypeRegistrySub401730";

const SUB_401830_LIST_MAX = 536_870_910;

export interface Sub401830WorldObject {
    vtableTag0: "WorldObject";
    runtimeType4: number;
    vec8: [number, number, number, number];
    vec24: [number, number, number, number];
    matrix40: number[];
    matrix104: number[];
    childrenHead168: Sub401830ChildNode;
    childrenCount172: number;
    parent180: Sub401830WorldObject | null;
    objectId184: number;
    flag188: number;
    ptr192: number;
}

export interface Sub401830ChildNode {
    next: Sub401830ChildNode;
    prev: Sub401830ChildNode;
    child: Sub401830WorldObject | null;
}

export interface Sub403230WorldNode {
    next: Sub403230WorldNode;
    prev: Sub403230WorldNode;
    objectId: number;
    objectRef: Sub401830WorldObject;
}

interface Sub402CD0IndexState {
    byId: Map<number, Sub403230WorldNode>;
}

export interface Sub402E10HashTable<T> {
    size8: number;
    bucketCount36: number;
    mask32: number;
    maxLoad40: number;
    buckets: T[][];
    entries: T[];
    hash: (entry: T) => number;
}

let dword4D82D4 = 0;
let dword4D82D8 = 0;
let dword4D82DC = 0;
let dword4CA630 = 0;
let dword4D8C14 = 0;

const dword4D8C10 = createWorldListSentinel();
const byte4D8C0C: Sub402CD0IndexState = { byId: new Map() };

function createWorldListSentinel(): Sub403230WorldNode {
    const sentinel = {} as Sub403230WorldNode;
    sentinel.next = sentinel;
    sentinel.prev = sentinel;
    sentinel.objectId = -1;
    sentinel.objectRef = null as unknown as Sub401830WorldObject;
    return sentinel;
}

function createIdentity4x4(): number[] {
    return [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1];
}

function createChildSentinel(): Sub401830ChildNode {
    const head = {} as Sub401830ChildNode;
    head.next = head;
    head.prev = head;
    head.child = null;
    return head;
}

/**
 * sub_403230: allocate list node storing `{id, object}` + prev/next links.
 */
export function sub403230CreateWorldNode(
    pair: [number, Sub401830WorldObject],
    next: Sub403230WorldNode,
    prev: Sub403230WorldNode,
): Sub403230WorldNode {
    return {
        next,
        prev,
        objectId: pair[0],
        objectRef: pair[1],
    };
}

/**
 * Simplified `sub_402CD0`: index-insert by object id into global hash map.
 */
export function sub402CD0InsertById(
    index: Sub402CD0IndexState,
    node: Sub403230WorldNode,
): { node: Sub403230WorldNode; inserted: boolean } {
    if (index.byId.has(node.objectId)) {
        return { node: index.byId.get(node.objectId)!, inserted: false };
    }
    index.byId.set(node.objectId, node);
    return { node, inserted: true };
}

/** sub_4031B0: allocate pointer-vector storage (`new T*[count]`) with guard. */
export function sub4031B0AllocatePointerVector(count: number): Array<unknown | null> {
    const c = count >>> 0;
    if (c > 0x3fffffff) {
        throw new RangeError("vector<T> too long");
    }
    return new Array(c).fill(null);
}

/** sub_403210: fill `count` cells with `value` starting at `startIndex`. */
export function sub403210FillValue<T>(
    count: number,
    value: T,
    dst: T[],
    startIndex = 0,
): number {
    const c = count >>> 0;
    for (let i = 0; i < c; i++) {
        dst[startIndex + i] = value;
    }
    return 0;
}

/** sub_4032A0: copy [srcStart, srcEnd) forward into dst at `dstStart`. */
export function sub4032A0CopyForward<T>(
    dst: T[],
    dstStart: number,
    src: T[],
    srcStart: number,
    srcEnd: number,
): number {
    let out = dstStart >>> 0;
    const from = srcStart >>> 0;
    const to = srcEnd >>> 0;
    for (let i = from; i < to; i++) {
        dst[out++] = src[i];
    }
    return out;
}

/** sub_402F60: vector insert of `count` copies of `value` at `insertIndex`. */
export function sub402F60InsertFilled<T>(
    count: number,
    vector: T[],
    insertIndex: number,
    value: T,
): void {
    const c = count >>> 0;
    if (c === 0) return;
    const idx = Math.max(0, Math.min(vector.length, insertIndex | 0));
    const chunk = new Array<T>(c);
    sub403210FillValue(c, value, chunk, 0);
    vector.splice(idx, 0, ...chunk);
}

/** sub_402EE0: splice one node from src list into dst list at `dstIndex`. */
export function sub402EE0TransferOne<T>(
    src: T[],
    dst: T[],
    srcIndex: number,
    dstIndex: number,
): T[] {
    if (src !== dst && dst.length === SUB_401830_LIST_MAX) {
        throw new RangeError("list<T> too long");
    }
    if (srcIndex < 0 || srcIndex >= src.length) {
        return dst;
    }
    const [item] = src.splice(srcIndex, 1);
    const insertAt = Math.max(0, Math.min(dst.length, dstIndex));
    dst.splice(insertAt, 0, item);
    return dst;
}

/** sub_44EDE0: erase node-at-index from list and return next index. */
export function sub44EDE0EraseAt<T>(
    list: T[],
    index: number,
): number {
    if (index < 0 || index >= list.length) {
        return index;
    }
    list.splice(index, 1);
    if (index >= list.length) {
        return Math.max(0, list.length - 1);
    }
    return index;
}

/** sub_402E10: load-factor check + bucket rehash for simplified hash state. */
export function sub402E10MaybeRehash<T>(table: Sub402E10HashTable<T>): void {
    if (table.bucketCount36 <= 0) {
        table.bucketCount36 = 1;
    }
    const load = table.size8 / table.bucketCount36;
    if (load <= table.maxLoad40) {
        return;
    }

    let newBucketCount = table.bucketCount36;
    for (let i = 0; i < 3; i++) {
        if (newBucketCount >= 0x1fffffff) {
            break;
        }
        newBucketCount *= 2;
    }

    table.bucketCount36 = newBucketCount;
    table.mask32 = newBucketCount - 1;
    table.buckets = Array.from({ length: newBucketCount }, () => []);
    for (const entry of table.entries) {
        const raw = table.hash(entry);
        const mixed = ((raw ^ 0xdeadbeef) & 0x7fffffff) >>> 0;
        const bucketIndex = mixed % newBucketCount;
        table.buckets[bucketIndex].push(entry);
    }
}

/**
 * sub_401830: WorldObject base constructor port.
 */
export function sub401830ConstructWorldObject(
    target?: Partial<Sub401830WorldObject>,
): Sub401830WorldObject {
    const objectId = dword4CA630 + 1;
    dword4CA630 = objectId;

    const obj = (target ?? {}) as Sub401830WorldObject;
    obj.vtableTag0 = "WorldObject";
    obj.runtimeType4 = 0;
    obj.vec8 = [dword4D82D4, dword4D82D8, dword4D82DC, 0];
    obj.vec24 = [dword4D82D4, dword4D82D8, dword4D82DC, 0];
    obj.matrix40 = createIdentity4x4();
    obj.matrix104 = createIdentity4x4();
    obj.childrenHead168 = createChildSentinel();
    obj.childrenCount172 = 0;
    obj.parent180 = null;
    obj.objectId184 = objectId;
    obj.flag188 = 0;
    obj.ptr192 = 0;

    sub401730RegisterType(0);

    const tail = dword4D8C10.prev;
    const node = sub403230CreateWorldNode([objectId, obj], dword4D8C10, tail);
    if (dword4D8C14 === SUB_401830_LIST_MAX) {
        throw new RangeError("list<T> too long");
    }
    dword4D8C14++;
    tail.next = node;
    dword4D8C10.prev = node;
    const inserted = sub402CD0InsertById(byte4D8C0C, node);
    if (!inserted.inserted) {
        dword4D8C14--;
    }

    return obj;
}

export function getSub401830RegistrySnapshot(): {
    nextObjectId: number;
    listSize: number;
    ids: number[];
} {
    const ids: number[] = [];
    for (let it = dword4D8C10.next; it !== dword4D8C10; it = it.next) {
        ids.push(it.objectId);
    }
    return {
        nextObjectId: dword4CA630 + 1,
        listSize: dword4D8C14,
        ids,
    };
}

export function resetSub401830StateForTests(): void {
    dword4CA630 = 0;
    dword4D8C14 = 0;
    dword4D8C10.next = dword4D8C10;
    dword4D8C10.prev = dword4D8C10;
    byte4D8C0C.byId.clear();
}
