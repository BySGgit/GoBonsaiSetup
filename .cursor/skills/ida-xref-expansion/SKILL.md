---
name: ida-xref-expansion
description: >-
  From a function or address, enumerates code/data xrefs, clusters call sites
  by role (init, update, render, etc.), and maps the subsystem. Use when tracing
  who calls what, mapping a feature across the binary, or when the user asks for
  xref graphs, callers, or usage categories.
---

# IDA Xref Expansion

## When to apply

User names a function, vtable, global, or VA and wants the surrounding call graph or “what uses this.”

## Workflow

1. **Anchor** — Resolve symbol to exact address; note segment (text/data/rdata).
2. **Collect xrefs**
   - **To** this address: callers, data refs, vtable slots, string refs.
   - **From** this function: callees, loads of globals, constant pool refs.
3. **Cluster by usage** — Group xrefs into buckets (examples):
   - **Init / ctor**: one-time setup, called from startup or allocator paths.
   - **Update / tick**: called from main loop, timer, or `Update`-like parent.
   - **Render / draw**: paired with graphics API, present, or scene build.
   - **IO / load**: file, registry, network.
   - **Utility**: small helpers, unclear → mark **unclassified**.
4. **Summarize** — For each cluster: 1–2 sentences + representative functions (names/addresses).
5. **Depth** — If user asks “expand,” recurse one level on high-value callees/callers only (avoid exponential listing).

## Output template

```markdown
## Xref expansion: `sub_XXXXXX` @ 0x...

### Xrefs to (incoming)
| From | Kind | Cluster |
|------|------|---------|
| sub_A @ 0x... | call | update |

### Xrefs from (outgoing)
| To | Kind | Cluster |
|----|------|---------|
| sub_B @ 0x... | call | render |

### Clusters
- **Init**: ...
- **Update**: ...
- **Render**: ...
- **Other / unknown**: ...

### Next hops (optional)
- Worth opening: ...
```

## Notes

- **Data xrefs** often explain globals and vtables; **code xrefs** explain control flow.
- Labels like init/update/render are **hypotheses** until backed by callee names or API strings.
- If IDA MCP is available, prefer it for xref lists and decompilation at each hop.
