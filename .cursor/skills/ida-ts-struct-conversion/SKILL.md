---
name: ida-ts-struct-conversion
description: >-
  Converts a reconstructed C struct (from RE) into a TypeScript interface with
  hex offset comments and stable field names. Use when porting structs to TS
  (e.g. WASM/memory views), syncing with decompiled layouts, or when the user
  asks for interfaces from IDA-derived layouts.
---

# RE Struct → TypeScript

## When to apply

User has a C struct hypothesis (from offset mining / reconstruction) and wants TS types for the port or documentation.

## Workflow

1. **Start from the agreed C layout** — Field order and offsets must match the reconstructed struct; do not reorder for style.
2. **Map C types → TS**
   - `uint8_t` / `char` → `number` (or `Uint8Array` slice if blob).
   - `int32_t` / `uint32_t` → `number`.
   - `int64_t` / `uint64_t` / pointers → `number` or `bigint` (pick one per project; default `number` for 32-bit, `bigint` if full 64-bit identity matters).
   - `float` / `double` → `number`.
   - Nested struct → nested `interface` or flat offsets with comments (match project convention).
   - Arrays → `readonly T[]` or tuple `[T, T, T]` when length is fixed and known.
   - Opaque / padding → `unknown` or `number` with comment `// pad`.
3. **Preserve naming** — Keep IDA/RE names (`field_10`, `sub_`-derived names) unless user asked to rename; TS `camelCase` only if project rules require it—then document mapping once.
4. **Offsets as comments** — Every logical field: line comment `// +0xNN` (hex, consistent width optional).
5. **Optional: memory view note** — If used with `DataView`/WASM, add one line: endianness and alignment assumption (e.g. little-endian, 4-byte align).

## Output template

```typescript
/** Hypothesis: T_Name — keep in sync with decompiled layout */
export interface TName {
  /** +0x00 */ vtable: number; // void*
  /** +0x08 */ field8: number; // int
  /** +0x0C */ fieldC: number; // float
  /** +0x10 */ pos: readonly [number, number, number]; // float[3]
  /** +0x1C */ pad1C: number; // uint8_t[4] as opaque
  /** +0x20 */ child: number; // SomeType*
}
```

## Notes

- TS interfaces do **not** enforce memory layout at runtime; comments are the source of truth for packing.
- If two fields overlap in C (`union`), use separate TS types or `/** @union */` note and do not merge silently.
- Link back to `sub_*` or `full.c` lines in a single file-level comment when this repo requires parity tracking.
