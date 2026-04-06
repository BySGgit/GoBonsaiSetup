const SUB_44E5D0_LIST_MAX = 0x3ffffffe; // 1073741822

export interface Sub44E5D0Vec3 {
    x: number;
    y: number;
    z: number;
}

export interface Sub44E5D0Vec4 extends Sub44E5D0Vec3 {
    w: number;
}

export interface Sub44E5D0Payload {
    a2Vec: Sub44E5D0Vec3;
    a3Vec: Sub44E5D0Vec3;
    a1Quat: Sub44E5D0Vec4;
    time40: number;
}

interface Sub44E5D0Node {
    next: Sub44E5D0Node;
    prev: Sub44E5D0Node;
    payload: Sub44E5D0Payload;
}

interface Sub44E5D0State {
    dword4D8B68ActiveHead: Sub44E5D0Node;
    dword4D8B6CActiveSize: number;
    dword4D8B74FreeHead: Sub44E5D0Node;
    dword4D8B78FreeSize: number;
    flt4D8B4CBaseTime: number;
}

let state = createState();

function createSentinelNode(payload: Sub44E5D0Payload): Sub44E5D0Node {
    const node = {} as Sub44E5D0Node;
    node.next = node;
    node.prev = node;
    node.payload = payload;
    return node;
}

function createPayload(): Sub44E5D0Payload {
    return {
        a2Vec: { x: 0, y: 0, z: 0 },
        a3Vec: { x: 0, y: 0, z: 0 },
        a1Quat: { x: 0, y: 0, z: 0, w: 1 },
        time40: 0,
    };
}

function createState(): Sub44E5D0State {
    const active = createSentinelNode(createPayload());
    const free = createSentinelNode(createPayload());
    return {
        dword4D8B68ActiveHead: active,
        dword4D8B6CActiveSize: 0,
        dword4D8B74FreeHead: free,
        dword4D8B78FreeSize: 0,
        flt4D8B4CBaseTime: 0,
    };
}

function insertAtTail(head: Sub44E5D0Node, node: Sub44E5D0Node): void {
    const tail = head.prev;
    node.next = head;
    node.prev = tail;
    tail.next = node;
    head.prev = node;
}

function popHead(head: Sub44E5D0Node): Sub44E5D0Node | null {
    const first = head.next;
    if (first === head) {
        return null;
    }
    first.prev.next = first.next;
    first.next.prev = first.prev;
    first.next = first;
    first.prev = first;
    return first;
}

export function resetSub44E5D0StateForTests(): void {
    state = createState();
}

export function sub44E5D0SetBaseTime(time: number): void {
    state.flt4D8B4CBaseTime = time;
}

export function seedSub44E5D0FreePool(count: number): void {
    const n = Math.max(0, Math.floor(count));
    for (let i = 0; i < n; i++) {
        const node: Sub44E5D0Node = createSentinelNode(createPayload());
        insertAtTail(state.dword4D8B74FreeHead, node);
        state.dword4D8B78FreeSize++;
    }
}

/**
 * sub_44E5D0:
 * consume one node from free-list and append a filled payload into active-list.
 */
export function sub44E5D0Enqueue(
    a1: Sub44E5D0Vec4,
    a2: Sub44E5D0Vec3,
    a3: Sub44E5D0Vec3,
    a4: number,
): boolean {
    if (a4 < 0 || state.dword4D8B78FreeSize <= 0) {
        return false;
    }

    const freeNode = popHead(state.dword4D8B74FreeHead);
    if (!freeNode) {
        return false;
    }
    state.dword4D8B78FreeSize--;

    if (state.dword4D8B6CActiveSize === SUB_44E5D0_LIST_MAX) {
        throw new RangeError("list<T> too long");
    }

    const activeNode: Sub44E5D0Node = createSentinelNode(freeNode.payload);
    insertAtTail(state.dword4D8B68ActiveHead, activeNode);
    state.dword4D8B6CActiveSize++;

    activeNode.payload.a2Vec.x = a2.x;
    activeNode.payload.a2Vec.y = a2.y;
    activeNode.payload.a2Vec.z = a2.z;
    activeNode.payload.a3Vec.x = a3.x;
    activeNode.payload.a3Vec.y = a3.y;
    activeNode.payload.a3Vec.z = a3.z;
    activeNode.payload.a1Quat.x = a1.x;
    activeNode.payload.a1Quat.y = a1.y;
    activeNode.payload.a1Quat.z = a1.z;
    activeNode.payload.a1Quat.w = a1.w;
    activeNode.payload.time40 = state.flt4D8B4CBaseTime + a4;
    return true;
}

export function getSub44E5D0Snapshot(): {
    activeSize: number;
    freeSize: number;
    activePayloads: Sub44E5D0Payload[];
} {
    const activePayloads: Sub44E5D0Payload[] = [];
    const head = state.dword4D8B68ActiveHead;
    for (let it = head.next; it !== head; it = it.next) {
        activePayloads.push({
            a2Vec: { ...it.payload.a2Vec },
            a3Vec: { ...it.payload.a3Vec },
            a1Quat: { ...it.payload.a1Quat },
            time40: it.payload.time40,
        });
    }
    return {
        activeSize: state.dword4D8B6CActiveSize,
        freeSize: state.dword4D8B78FreeSize,
        activePayloads,
    };
}
