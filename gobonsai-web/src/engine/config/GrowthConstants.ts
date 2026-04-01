import * as THREE from "three";
import { Float32, D3DXVECTOR3 } from "../math/MathTypes";

/**
 * Глобальные константы из decompiled/full.c (значения по умолчанию до чтения INI).
 * Старые имена (LIGHT_THRESHOLD_*) оставлены для совместимости, но не совпадают с flt_4D63B4/B8 из метаболизма.
 */
export const GrowthConstants = {
  /** byte_4D62DC — updateGrowth (INI); при false весь кадр роста в exe можно отключить */
  BYTE_4D62DC_UPDATE_GROWTH: true,
  /** byte_4D8CED — randomAutoCuts (INI; sub_40DC90 §2.2) */
  BYTE_4D8CED_RANDOM_AUTO_CUTS: false,

  /**
   * flt_4B786C[12] — месячная кривая для sub_40EE60 (full.c:1493).
   * 13-й элемент в .data — артефакт; в расчёте используются 0..11 и (i+1)%12.
   */
  FLT_4B786C_MONTH: [
    0.0, 0.0, 0.5, 1.0, 1.0, 0.5, 0.1, 0.1, 0.050000001, 0.0, 0.0, 0.0,
  ] as const,

  /** flt_4D62E0 — energyUseRate (INI; до парсера INI — 1.0 не ломает масштаб) */
  ENERGY_USE_RATE: 1.0 as Float32,
  /** flt_4D62E4 — energyLeak (после баланса +420/+436 в sub_40DC90) */
  ENERGY_LEAK: 1.0 as Float32,
  /** flt_4D7EF4 — доп. годовой множитель к пулу (sub_4123C0 пишет 0.0) */
  FLT_4D7EF4: 0.0 as Float32,

  /**
   * sub_403C50 → `energyAllowancePow` → `flt_4D8628` (sub_414CE0: pow(+424, *)).
   * В .data дефолт не зашит — до `sub_406AE0` APPROX: 1.0.
   */
  FLT_4D8628_ENERGY_ALLOWANCE_POW: 1.0 as Float32,
  /**
   * sub_403C50 → `energyRebalancePercent` → `flt_4D863C` (sub_414CE0: lerp старого +428 с pow(+424)).
   * До INI — APPROX: 0.5.
   */
  FLT_4D863C_ENERGY_REBALANCE_PERCENT: 0.5 as Float32,

  /**
   * byte_4D8229[11 * type] / byte_4D822A[11 * type] — таблицы из INI (sub_413C20 / sub_40FBA0).
   * Индекс = 11 * *(_DWORD*)(this+4). Пока нули → поведение как раньше (только обнуление +424).
   */
  BYTE_4D8229_STRIDE11: new Uint8Array(11 * 16).fill(0),
  BYTE_4D822A_STRIDE11: new Uint8Array(11 * 16).fill(0),

  /**
   * Масштаб growthScratchA → this+420 на листе (прокси sub_416510: v19 и flt_4D8634 в exe).
   * Подбирается вместе с LEAF_ENERGY_PRODUCTION при сверке агрегата +420 с IDA.
   */
  SUB40DC90_PRODUCTION_FROM_SCRATCH_SCALE: 0.1 as Float32,

  /** Масштаб суммарного расхода метаболизма → root+436 (пул 0..1). */
  SUB40DC90_METABOLISM_SPENT_SCALE: 1.0 as Float32,

  LIGHT_VECTOR: new THREE.Vector3(0.0, 1.0, 0.0) as D3DXVECTOR3,

  /** flt_4D63B0 — множитель в градиентах / росте (full.c: 0.5) */
  FLT_4D63B0: 0.5 as Float32,
  /** sub_416510.c — flt_4D63B4, порог в формуле v29 (full.c: 0.2) */
  FLT_4D63B4: 0.2 as Float32,
  /** sub_416510.c — flt_4D63B8, множитель расхода энергии (full.c: 1.0) */
  FLT_4D63B8: 1.0 as Float32,
  /** sub_416510.c — flt_4D63BC, случайный пропуск роста (full.c: 0.02) */
  FLT_4D63BC: 0.02 as Float32,
  /** sub_416510.c — flt_4D63C0, slerp (full.c: ~0.06) */
  FLT_4D63C0: 0.059999999 as Float32,
  /** sub_416510.c — flt_4D63C4, множитель прироста growthRate (full.c: 0.2) */
  FLT_4D63C4: 0.2 as Float32,
  /** sub_403C50 leafEnergyProduction — без дефолта в .data, типично 1 */
  LEAF_ENERGY_PRODUCTION: 1.0 as Float32,

  /** @deprecated см. FLT_4D63B0 */
  BASE_GROWTH_MULTIPLIER: 0.5 as Float32,
  /** @deprecated не путать с FLT_4D63B4 (метаболизм) */
  LIGHT_THRESHOLD_MIN: 0.1 as Float32,
  /** @deprecated не путать с FLT_4D63B8 (метаболизм) */
  LIGHT_THRESHOLD_MAX: 0.9 as Float32,
  /** @deprecated см. FLT_4D63BC */
  RANDOM_GROWTH_FACTOR: 0.02 as Float32,
  /** @deprecated см. FLT_4D63C4 */
  GROWTH_RATE_MULTIPLIER: 0.2 as Float32,

  SLERP_FACTOR: 0.059999999 as Float32,
  ROTATION_ADJUSTMENT: 0.050000001 as Float32,
  ANGLE_LIMIT_MIN: -1.5707964 as Float32,
  AUX_ROTATION_CONST: 0.1 as Float32,

  BRANCH_THRESHOLD_MIN: 0.5 as Float32,
  BRANCH_THRESHOLD_MAX: 1.0 as Float32,
  BRANCH_GROWTH_RATE: 0.05 as Float32,

  /** sub_416510.c:77 — порог толщины ствола для доп. убыли энергии у корня */
  METABOLISM_ROOT_THICKNESS_GATE: 0.01 as Float32,

  /**
   * sub_40D0B0 a14 → глобал `flt_4D861C`; sub_415C10.c: `*(twig + 444) = flt_4D861C` при переходе почка → `TreeSectionTwig`.
   * В full.c нет отдельного `sub_406AE0(..., &flt_4D861C)` — только пресет `sub_4701D0` → `sub_40D0B0(..., 0.079999998, ...)` как a14.
   */
  FLT_4D861C_INITIAL_TWIG_GIRTH: 0.079999998 as Float32,

  CRITICAL_ENERGY_THRESHOLD: 0.1 as Float32,
  LOW_ENERGY_THRESHOLD: 0.35 as Float32,
  HIGH_ENERGY_THRESHOLD: 0.75 as Float32,
  HEALTH_DECAY_CRITICAL: 0.015 as Float32,
  HEALTH_DECAY_LOW: 0.004 as Float32,
  HEALTH_RECOVERY_RATE: 0.008 as Float32,
  AGE_HEALTH_DECAY_START: 40 as Float32,
  AGE_HEALTH_DECAY_RATE: 0.00008 as Float32,
};

/** sub_414CE0.c: `byte_4D8229[11 * *(_DWORD *)(this + 4)]` */
export function byte4D8229ForSectionType(typeIndex: number): boolean {
  const i = 11 * typeIndex;
  const a = GrowthConstants.BYTE_4D8229_STRIDE11;
  return i >= 0 && i < a.length && a[i] !== 0;
}

/** sub_414CE0.c: `byte_4D822A[11 * *(_DWORD *)(this + 4)]` */
export function byte4D822AForSectionType(typeIndex: number): boolean {
  const i = 11 * typeIndex;
  const a = GrowthConstants.BYTE_4D822A_STRIDE11;
  return i >= 0 && i < a.length && a[i] !== 0;
}
