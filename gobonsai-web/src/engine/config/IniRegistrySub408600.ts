/**
 * Minimal parity layer for the C-side INI/console registration pipeline:
 * sub_4032D0 + sub_408600 + sub_40FD70 (+ light stubs for sub_43FD00/sub_44A640).
 *
 * The goal is deterministic behavior and reusable helpers for runtime-critical
 * keys while staying in idiomatic TS memory model.
 */

const SUB_4032D0_SSO_CAPACITY = 7;
const SUB_4032D0_MAX_LENGTH = 0x7ffffffe;
const SUB_408600_LIST_MAX = 0x3ffffffe; // 1073741822
const UINT32_MAX = 0xffffffff;

export interface Sub4032WideString {
    value: string;
    length16: number;
    capacity20: number;
}

export interface Sub4032SourceView {
    storage: Sub4032WideString;
    offset16: number;
}

export interface SubIniValueRef {
    get(): number;
    set(next: number): void;
}

export type Sub408600ValueRef = SubIniValueRef;

export interface Sub408600Entry {
    keyStorage20: Sub4032WideString;
    valueRef28: SubIniValueRef | null;
    valueType32: number;
}

interface Sub40FD70Node {
    next: Sub40FD70Node;
    prev: Sub40FD70Node;
    payload: Sub408600Entry;
}

interface Sub408600RegistryState {
    initMask4D8EC0: number;
    listHead4D8E20: Sub40FD70Node;
    size4D8E24: number;
    initCalls43FD00: number;
    atexitHandlers: Array<() => void>;
}

const dword4D8E20 = createRegistryState();

function createRegistryState(): Sub408600RegistryState {
    const sentinelPayload = createSub408600Entry();
    const sentinel = {} as Sub40FD70Node;
    sentinel.next = sentinel;
    sentinel.prev = sentinel;
    sentinel.payload = sentinelPayload;
    return {
        initMask4D8EC0: 0,
        listHead4D8E20: sentinel,
        size4D8E24: 0,
        initCalls43FD00: 0,
        atexitHandlers: [],
    };
}

export function createSub4032WideString(initial = ""): Sub4032WideString {
    const s: Sub4032WideString = {
        value: "",
        length16: 0,
        capacity20: SUB_4032D0_SSO_CAPACITY,
    };
    if (initial.length > 0) {
        sub4032D0Assign(s, initial, initial.length);
    }
    return s;
}

export function sub4032View(storage: Sub4032WideString, offset16 = 0): Sub4032SourceView {
    return { storage, offset16 };
}

export function createSub408600Entry(): Sub408600Entry {
    return {
        keyStorage20: createSub4032WideString(),
        valueRef28: null,
        valueType32: 0,
    };
}

function sub43FD00Stub(): void {
    dword4D8E20.initCalls43FD00++;
}

function sub472560Stub(): void {
    // Runtime teardown hook placeholder.
}

export function subAtexitRegister(handler: () => void): void {
    dword4D8E20.atexitHandlers.push(handler);
}

function sub44A640SortList(): void {
    const head = dword4D8E20.listHead4D8E20;
    const nodes: Sub40FD70Node[] = [];
    for (let it = head.next; it !== head; it = it.next) {
        nodes.push(it);
    }
    if (nodes.length < 2) {
        return;
    }
    nodes.sort((a, b) =>
        a.payload.keyStorage20.value.localeCompare(b.payload.keyStorage20.value),
    );
    head.next = nodes[0];
    head.prev = nodes[nodes.length - 1];
    for (let i = 0; i < nodes.length; i++) {
        const prev = i === 0 ? head : nodes[i - 1];
        const next = i === nodes.length - 1 ? head : nodes[i + 1];
        nodes[i].prev = prev;
        nodes[i].next = next;
    }
}

function sub403580Grow(dest: Sub4032WideString, requestedLen: number): void {
    let newCap = requestedLen | 7;
    if (newCap <= SUB_4032D0_MAX_LENGTH) {
        const oldCap = dest.capacity20 >>> 0;
        const half = oldCap >>> 1;
        if (half > Math.floor(newCap / 3)) {
            newCap = half + oldCap;
            if (oldCap > SUB_4032D0_MAX_LENGTH - half) {
                newCap = SUB_4032D0_MAX_LENGTH;
            }
        }
    } else {
        newCap = requestedLen;
    }
    dest.capacity20 = newCap;
}

function setWideStringValue(dest: Sub4032WideString, next: string): Sub4032WideString {
    dest.value = next;
    dest.length16 = next.length;
    return dest;
}

export function sub4037B0AssignSubstr(
    dest: Sub4032WideString,
    src: Sub4032WideString,
    count: number,
    pos: number,
): Sub4032WideString {
    if (src.length16 < pos) {
        throw new RangeError("invalid string position");
    }
    let copyLen = src.length16 - pos;
    const c = count >>> 0;
    if (c < copyLen) {
        copyLen = c;
    }
    if (copyLen > SUB_4032D0_MAX_LENGTH) {
        throw new RangeError("string too long");
    }

    const slice = src.value.slice(pos, pos + copyLen);
    if (dest.capacity20 < copyLen) {
        sub403580Grow(dest, copyLen);
    }
    return setWideStringValue(dest, slice);
}

function resolveSource(
    source: string | Sub4032WideString | Sub4032SourceView,
): { storage: Sub4032WideString | null; text: string; offset16: number } {
    if (typeof source === "string") {
        return { storage: null, text: source, offset16: 0 };
    }
    if ("storage" in source) {
        return { storage: source.storage, text: source.storage.value, offset16: source.offset16 };
    }
    return { storage: source, text: source.value, offset16: 0 };
}

export function sub4032D0Assign(
    dest: Sub4032WideString,
    source: string | Sub4032WideString | Sub4032SourceView,
    count: number,
): Sub4032WideString {
    const c = count >>> 0;
    if (c > SUB_4032D0_MAX_LENGTH) {
        throw new RangeError("string too long");
    }
    const resolved = resolveSource(source);
    if (resolved.storage === dest) {
        return sub4037B0AssignSubstr(dest, dest, c, resolved.offset16);
    }
    if (dest.capacity20 < c) {
        sub403580Grow(dest, c);
    }
    if (c === 0) {
        return setWideStringValue(dest, "");
    }
    const next = resolved.text.slice(resolved.offset16, resolved.offset16 + c);
    return setWideStringValue(dest, next);
}

export function sub40FD70AllocateNode(
    head: Sub40FD70Node,
    tail: Sub40FD70Node,
    payload: Sub408600Entry,
): Sub40FD70Node {
    return {
        next: head,
        prev: tail,
        payload,
    };
}

export function sub408600Register(
    sourceName: Sub4032WideString,
    entry: Sub408600Entry,
    valueRef: SubIniValueRef,
): Sub408600Entry {
    return registerIniValue(sourceName, entry, valueRef, 8);
}

/**
 * sub_4038B0 — boolean INI registration path (`valueType32 = 7`).
 * Shares the same registry/list and lazy init bit as sub_408600.
 */
export function sub4038B0Register(
    sourceName: Sub4032WideString,
    entry: Sub408600Entry,
    valueRef: SubIniValueRef,
): Sub408600Entry {
    return registerIniValue(sourceName, entry, valueRef, 7);
}

function registerIniValue(
    sourceName: Sub4032WideString,
    entry: Sub408600Entry,
    valueRef: SubIniValueRef,
    valueType: number,
): Sub408600Entry {
    entry.keyStorage20.capacity20 = SUB_4032D0_SSO_CAPACITY;
    entry.keyStorage20.length16 = 0;
    entry.keyStorage20.value = "";
    sub4037B0AssignSubstr(entry.keyStorage20, sourceName, UINT32_MAX, 0);
    entry.valueRef28 = valueRef;
    entry.valueType32 = valueType;

    if ((dword4D8E20.initMask4D8EC0 & 1) === 0) {
        dword4D8E20.initMask4D8EC0 |= 1;
        sub43FD00Stub();
        subAtexitRegister(sub472560Stub);
    }

    if (dword4D8E20.size4D8E24 === SUB_408600_LIST_MAX) {
        throw new RangeError("list<T> too long");
    }

    const head = dword4D8E20.listHead4D8E20;
    const tail = head.prev;
    const node = sub40FD70AllocateNode(head, tail, entry);
    dword4D8E20.size4D8E24++;
    head.prev = node;
    node.prev.next = node;
    sub44A640SortList();
    return entry;
}

export function createNumericPropertyBinding<
    T extends object,
    K extends keyof T & string,
>(target: T, key: K): SubIniValueRef {
    const bag = target as unknown as Record<string, unknown>;
    return {
        get: () => Number(bag[key]),
        set: (next: number) => {
            bag[key] = next;
        },
    };
}

export function createBooleanPropertyBinding<
    T extends object,
    K extends keyof T & string,
>(target: T, key: K): SubIniValueRef {
    const bag = target as unknown as Record<string, unknown>;
    return {
        get: () => (bag[key] ? 1 : 0),
        set: (next: number) => {
            bag[key] = next !== 0;
        },
    };
}

export function setIniNumericValueByKey(key: string, value: number): boolean {
    const head = dword4D8E20.listHead4D8E20;
    for (let it = head.next; it !== head; it = it.next) {
        if (it.payload.keyStorage20.value === key) {
            it.payload.valueRef28?.set(value);
            return true;
        }
    }
    return false;
}

export function setIniBooleanValueByKey(key: string, value: boolean): boolean {
    return setIniNumericValueByKey(key, value ? 1 : 0);
}

export function getIniRegistrySnapshot(): {
    size: number;
    keys: string[];
    initCalls43FD00: number;
    initMask4D8EC0: number;
} {
    const keys: string[] = [];
    const head = dword4D8E20.listHead4D8E20;
    for (let it = head.next; it !== head; it = it.next) {
        keys.push(it.payload.keyStorage20.value);
    }
    return {
        size: dword4D8E20.size4D8E24,
        keys,
        initCalls43FD00: dword4D8E20.initCalls43FD00,
        initMask4D8EC0: dword4D8E20.initMask4D8EC0,
    };
}

export function resetIniRegistryForTests(): void {
    const fresh = createRegistryState();
    dword4D8E20.initMask4D8EC0 = fresh.initMask4D8EC0;
    dword4D8E20.listHead4D8E20 = fresh.listHead4D8E20;
    dword4D8E20.size4D8E24 = fresh.size4D8E24;
    dword4D8E20.initCalls43FD00 = fresh.initCalls43FD00;
    dword4D8E20.atexitHandlers = fresh.atexitHandlers;
}
