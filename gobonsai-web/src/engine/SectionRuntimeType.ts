/**
 * `*(_DWORD *)(TreeSection* + 4)` — класс секции (spec_initial_sprout_growth.md §1, rdata).
 * Используется в byte_4D8229/822A, виртуальном слоте +36/+40 и т.д.
 */
export enum SectionRuntimeType {
  /** базовый TreeSection (ствол/ветвь) */
  TreeSection = 5,
  TreeSectionBud = 6,
  TreeSectionLeaf = 7,
  /** корневой росток — sub_417220, слот +36 → sub_417440 */
  TreeSectionSeed = 8,
  TreeSectionStump = 9,
  TreeSectionTwig = 10,
}
