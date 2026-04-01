import * as THREE from "three";
import { Float32, D3DXVECTOR3 } from "../math/MathTypes";

/**
 * Type flag tables from spec_type_tables_sub_40FAD0.md.
 * Stride 11 per type; index = 11 * sectionRuntimeType.
 * Initialized by sub_40FAD0 (Leaf), sub_415800 (Bud), sub_40FBA0 (Twig),
 * sub_413C20 (Stump), sub_403A90 (base).
 */
function buildTypeTable(entries: Array<[typeId: number, value: number]>): Uint8Array {
  const t = new Uint8Array(11 * 16);
  for (const [id, v] of entries) t[11 * id] = v;
  return t;
}

/**
 * Глобальные константы из decompiled/full.c.
 * Значения по умолчанию = пресет sub_4701D0 → sub_40D0B0 (23 параметра).
 * INI-ключи из spec_ini_and_console_keys_inventory.md переопределяют подмножество.
 */
export const GrowthConstants = {
  BYTE_4D62DC_UPDATE_GROWTH: true,
  BYTE_4D8CED_RANDOM_AUTO_CUTS: false,

  FLT_4B786C_MONTH: [
    0.0, 0.0, 0.5, 1.0, 1.0, 0.5, 0.1, 0.1, 0.050000001, 0.0, 0.0, 0.0,
  ] as const,

  ENERGY_USE_RATE: 1.0 as Float32,
  ENERGY_LEAK: 1.0 as Float32,
  FLT_4D7EF4: 0.0 as Float32,

  // --- Type flag tables (spec_type_tables_sub_40FAD0.md) ---
  // flag #0: "registered" type
  BYTE_4D8220_STRIDE11: buildTypeTable([[5, 1], [6, 1], [7, 1], [9, 1], [10, 1]]),
  // flag #5: "copy parent light on construct"
  BYTE_4D8225_STRIDE11: buildTypeTable([[5, 1], [6, 1], [7, 1], [9, 1], [10, 1]]),
  // flag #6: "weightless" — Bud only (sub_414870: totalWeight=0)
  BYTE_4D8226_STRIDE11: buildTypeTable([[6, 1]]),
  // flag #7: light decay in sub_40E460 — Leaf only
  BYTE_4D8227_STRIDE11: buildTypeTable([[7, 1]]),
  // flag #9: parent energy copy in sub_414CE0 — Stump
  BYTE_4D8229_STRIDE11: buildTypeTable([[9, 1]]),
  // flag #10: geometric screening in sub_40E460, pow recalc in sub_414CE0 — Twig
  BYTE_4D822A_STRIDE11: buildTypeTable([[10, 1]]),

  // --- sub_40D0B0 preset (23 params from sub_4701D0) ---
  /** a1 → flt_4D85E8: minSegmentSize */
  FLT_4D85E8: 2.0 as Float32,
  /** a2 → flt_4D85EC: maxSegmentSize */
  FLT_4D85EC: 5.0 as Float32,
  /** a3 → flt_4D85F0: minLeafSize */
  FLT_4D85F0: 1.5 as Float32,
  /** a4 → flt_4D85F4: maxLeafSize */
  FLT_4D85F4: 4.0 as Float32,
  /** a5 → flt_4D85F8: maxBudSize */
  FLT_4D85F8: 0.45 as Float32,
  /** a6 → flt_4D85FC: density / weightCoeff */
  FLT_4D85FC: 40.0 as Float32,
  /** a7 → flt_4D8600: accelerationRadiusPow (wind torque) */
  FLT_4D8600: -2.0 as Float32,
  /** a8 → flt_4D8604: resistanceRadiusPow */
  FLT_4D8604: 1.0 as Float32,
  /** a9 → flt_4D8608: resistanceCoeff */
  FLT_4D8608: 0.6 as Float32,
  /** a10 → flt_4D860C: leafWeight (sub_416390 slot+56) */
  FLT_4D860C: 0.050000001 as Float32,
  /** a11 → flt_4D8610: lightAdjustBudStemCoeff */
  FLT_4D8610: 0.0025 as Float32,
  /** a12 → flt_4D8614: lengthGrowRate */
  FLT_4D8614: 0.08 as Float32,
  /** a13 → flt_4D8618: radiusGrowRate (twig girth in sub_417C90) */
  FLT_4D8618: 0.000015 as Float32,
  /** a14 → flt_4D861C: initial twig girth (sub_415C10) */
  FLT_4D861C_INITIAL_TWIG_GIRTH: 0.079999998 as Float32,
  /** a15 → flt_4D8620: lengthGrowPowBase (sub_418BD0: pow(budget, this)) */
  FLT_4D8620: 0.050000001 as Float32,
  /** a16 → flt_4D8624: twigSlerpFactor (sub_417C90 slerp toward light) */
  FLT_4D8624: 0.001 as Float32,
  /** a17 → flt_4D8628: energyAllowancePow (sub_414CE0: pow(+424, this)) */
  FLT_4D8628_ENERGY_ALLOWANCE_POW: 1.2 as Float32,
  /** a18 → flt_4D862C: minBudEnergy (sub_417F40 threshold) */
  FLT_4D862C: 0.2 as Float32,
  /** a19 → flt_4D8630: maxBudEnergy (sub_418BD0 delta scale) */
  FLT_4D8630: 2.0 as Float32,
  /** a20 → flt_4D8634: leafEnergyProduction */
  FLT_4D8634: 0.35 as Float32,
  /** a21 → flt_4D8638: apicalGrowthStrength */
  FLT_4D8638: 0.4 as Float32,
  /** a22 → flt_4D863C: energyRebalancePercent (sub_414CE0 lerp) */
  FLT_4D863C_ENERGY_REBALANCE_PERCENT: 1.0 as Float32,
  /** a23 → flt_4D8640: lengthGrowRatePow */
  FLT_4D8640: 2.0 as Float32,

  // --- sub_416510 metabolism constants ---
  SUB40DC90_PRODUCTION_FROM_SCRATCH_SCALE: 0.1 as Float32,
  SUB40DC90_METABOLISM_SPENT_SCALE: 1.0 as Float32,

  LIGHT_VECTOR: new THREE.Vector3(0.0, 1.0, 0.0) as D3DXVECTOR3,

  FLT_4D63B0: 0.5 as Float32,
  FLT_4D63B4: 0.2 as Float32,
  FLT_4D63B8: 1.0 as Float32,
  FLT_4D63BC: 0.02 as Float32,
  FLT_4D63C0: 0.059999999 as Float32,
  FLT_4D63C4: 0.2 as Float32,
  /** sub_40D0B0 a20 = 0.35 (leafEnergyProduction); alias for FLT_4D8634 */
  LEAF_ENERGY_PRODUCTION: 0.35 as Float32,

  /** @deprecated alias for FLT_4D63B0 */
  BASE_GROWTH_MULTIPLIER: 0.5 as Float32,
  LIGHT_THRESHOLD_MIN: 0.1 as Float32,
  LIGHT_THRESHOLD_MAX: 0.9 as Float32,
  RANDOM_GROWTH_FACTOR: 0.02 as Float32,
  GROWTH_RATE_MULTIPLIER: 0.2 as Float32,

  SLERP_FACTOR: 0.059999999 as Float32,
  ROTATION_ADJUSTMENT: 0.050000001 as Float32,
  ANGLE_LIMIT_MIN: -1.5707964 as Float32,
  AUX_ROTATION_CONST: 0.1 as Float32,

  BRANCH_THRESHOLD_MIN: 0.5 as Float32,
  BRANCH_THRESHOLD_MAX: 1.0 as Float32,
  BRANCH_GROWTH_RATE: 0.05 as Float32,

  METABOLISM_ROOT_THICKNESS_GATE: 0.01 as Float32,

  /** INI: resistanceRadiusBias (sub_414BB0) */
  FLT_4D635C: 0.1 as Float32,

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

export function byte4D8226ForSectionType(typeIndex: number): boolean {
  const i = 11 * typeIndex;
  const a = GrowthConstants.BYTE_4D8226_STRIDE11;
  return i >= 0 && i < a.length && a[i] !== 0;
}

export function byte4D8225ForSectionType(typeIndex: number): boolean {
  const i = 11 * typeIndex;
  const a = GrowthConstants.BYTE_4D8225_STRIDE11;
  return i >= 0 && i < a.length && a[i] !== 0;
}
