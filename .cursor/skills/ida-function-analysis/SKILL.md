---
name: ida-function-analysis
description: >-
  Decompiles an IDA function, explains control flow, lists inputs/outputs/side
  effects, follows xrefs for context, and suggests descriptive names. Use when
  analyzing sub_*, one function in a binary, or when the user asks to explain
  decompiled logic, callers/callees, or rename candidates.
---

# IDA Function Analysis

## When to apply

User gives an address, symbol (`sub_40FDE0`), or pseudocode snippet from IDA/Ghidra.

## Workflow

1. **Decompile** — Open the function in the decompiler; if MCP IDA is available, use it to fetch decompilation and disassembly for the exact address.
2. **High-level logic** — Summarize in 3–8 sentences: purpose, main branches, loops, early exits, error paths.
3. **Contract** — Fill the table:
   - **Inputs**: registers/stack args, globals read, implicit context (e.g. `this`/struct ptr).
   - **Outputs**: return value, out-parameters, flags or status written.
   - **Side effects**: memory writes, I/O, callbacks, allocator calls, thread/API calls.
4. **Xrefs** — List **code xrefs to** (callers) and **code xrefs from** (callees worth naming). Note data xrefs if they clarify globals/vtables.
5. **Rename suggestions** — Propose `verbNoun` / domain names for the function and for unclear callees; keep original `sub_` names in parentheses until accepted.

## Output template

```markdown
## Function: `sub_XXXXXX` @ 0x...

### Summary
...

### Inputs / Outputs / Side effects
| Kind | Detail |
|------|--------|
| Inputs | ... |
| Outputs | ... |
| Side effects | ... |

### Related (xrefs)
- Callers: ...
- Callees: ...

### Suggested names
- `sub_XXXXXX` → ...
```

## Notes

- Distinguish **definite** behavior from **speculative** (mark speculative).
- If decompilation is wrong or truncated, cross-check disassembly for calling convention and tail calls.
