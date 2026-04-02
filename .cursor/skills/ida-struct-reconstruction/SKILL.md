---
name: ida-struct-reconstruction
description: >-
  Merges offset evidence from multiple functions, sorts and pads a layout,
  infers field types from usage (float math, compares, derefs), detects strides
  for arrays, and outputs a struct definition. Use when building a struct from
  mined offsets or when the user asks for layout, field types, or padding
  analysis.
---

# IDA Struct Reconstruction

## When to apply

After offset mining (or user provides a flat list of offsets + usage snippets) for one logical type.

## Workflow

1. **Collect** — Union offsets from all contributing functions; dedupe; keep access size and usage notes.
2. **Sort** — Ascending by offset; compute gaps to the next known field.
3. **Infer types** (heuristic, mark confidence):
   - **Float/double**: `movss`/`movsd`, `addss`, `mulss`, comparisons with float constants, sqrt.
   - **Int/bool/enum**: integer compares, `test`/`cmp`, bit ops, small immediates, array indexing scales.
   - **Pointer**: load then indirect load/call, or offset passed as pointer; size qword on x64.
   - **Unknown**: `memcpy`-sized blocks or mixed use → `uint8_t pad[N]` or opaque blob.
4. **Arrays** — Repeated stride `k` from the same base (e.g. +0x20, +0x24, +0x28 with dword) → `T arr[n]` at start offset; `n` from range or usage.
5. **Layout** — Emit struct with explicit `/* +0x.. */` comments; document assumptions and anti-conflicts (two different types at same offset → need union or two contexts).

## Output template

```markdown
## Struct: `T_Name` (hypothesis)

### Evidence summary
- Functions: ...
- Strong offsets: ...

### Layout
```c
struct T_Name {
    /* +0x00 */ void *field_0;       // ptr: deref at sub_A
    /* +0x08 */ int field_8;         // cmp vs imm
    /* +0x0C */ float field_C;       // mulss
    /* +0x10 */ float pos[3];        // stride 4, +0x10,+0x14,+0x18
    /* +0x1C */ uint8_t pad_1C[4];
    /* +0x20 */ SomeType *field_20;
};
```

### Uncertainties
- ...
```

## Notes

- **False unions**: same offset used as float and int may mean two paths or bit reinterpretation — call it out.
- **Inheritance**: vtable at +0 often implies polymorphic type; derived fields may live at positive offsets only in subclass instances — avoid over-merging unrelated types.
