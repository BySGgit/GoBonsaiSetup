import { describe, expect, it } from "vitest";
import { sub450C80RemoveFromParent } from "./sub450C80";

type Node = {
    name: string;
    parent: Node | null;
    children: Node[];
};

function makeNode(name: string): Node {
    return { name, parent: null, children: [] };
}

describe("sub450C80RemoveFromParent", () => {
    it("removes node from parent list and nulls parent when found", () => {
        const parent = makeNode("p");
        const childA = makeNode("a");
        const childB = makeNode("b");
        childA.parent = parent;
        childB.parent = parent;
        parent.children.push(childA, childB);

        const ok = sub450C80RemoveFromParent(childA, parent);
        expect(ok).toBe(true);
        expect(childA.parent).toBeNull();
        expect(parent.children).toEqual([childB]);
    });

    it("returns false and keeps parent link when node is not in list", () => {
        const parent = makeNode("p");
        const orphan = makeNode("x");
        orphan.parent = parent;

        const ok = sub450C80RemoveFromParent(orphan, parent);
        expect(ok).toBe(false);
        expect(orphan.parent).toBe(parent);
        expect(parent.children).toEqual([]);
    });

    it("returns false for null parent", () => {
        const node = makeNode("x");
        const ok = sub450C80RemoveFromParent(node);
        expect(ok).toBe(false);
        expect(node.parent).toBeNull();
    });
});

