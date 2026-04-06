export interface Sub450C80NodeLike<TNode> {
    parent: TNode | null;
    children: TNode[];
}

/**
 * sub_450C80: remove node from parent's child list.
 * Returns true only when the node is found and removed.
 */
export function sub450C80RemoveFromParent<TNode extends Sub450C80NodeLike<TNode>>(
    a1: TNode,
    a2?: TNode | null,
): boolean {
    const parent = a2 ?? a1.parent;
    if (!parent) return false;

    const idx = parent.children.indexOf(a1);
    if (idx === -1) return false;

    parent.children.splice(idx, 1);
    a1.parent = null;
    return true;
}

