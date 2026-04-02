---
name: ida-offset-mining
description: >-
  Scans decompiled or disassembled code for base pointer + offset patterns,
  extracts and groups offsets, tracks repeats across functions, and drafts a
  candidate struct layout. Use when reverse engineering C++ objects, finding
  field offsets, or when the user mentions ptr+offset, member access, or struct
  recovery from assembly.
---

# IDA Offset Mining

## When to apply

Analyzing one or more functions that take a struct/object pointer (`rcx`/`this`, first arg, etc.) or global base + offsets.

## Workflow

1. **Scan for pointer usage** — Identify registers or locals that hold a stable base for the object (incoming arg, `lea` base, repeated `mov` base).
2. **Extract offsets** — Collect every `base + imm`, `[base + offset]`, and decompiler forms like `*(a1 + 0x10)`. Normalize to hex offsets; note size of access (byte/word/dword/qword/float) when visible.
3. **Group by base** — One table per base symbol (e.g. `a1`, `this`, `g_Foo`). Sort offsets ascending within each group.
4. **Cross-function repeats** — For the same logical type, merge offset lists from multiple functions; highlight offsets that appear in 2+ functions (strong struct candidates).
5. **Candidate struct** — Emit a **draft** C-style struct: fields as `UNKNOWN` or guessed types; mark gaps; add confidence (high/medium/low) per field.

## Output template

```markdown
## Offset mine: `sub_XXXXXX` (and related)

### Bases
- `a1` @ entry — role: ...

### Offsets by base (`a1`)
| Offset | Access | Notes |
|--------|--------|-------|
| +0x00 | qword | vtable? |
| +0x10 | float | ... |

### Repeated across functions
- +0x10: seen in sub_A, sub_B

### Candidate struct (DRAFT)
```c
struct T_??? {
    /* +0x00 */ void *vtable; // guess
    /* +0x08 */ uint8_t pad_8[8];
    /* +0x10 */ float field_10;
};
```
```

## Notes

- **Alignment**: suspicious gaps may be padding or missed accesses; do not invent fields without evidence.
- **Arrays**: same stride repeated → note as possible array (see struct-reconstruction skill).
- Prefer **evidence lines** (one pseudocode or asm line per non-trivial offset).
