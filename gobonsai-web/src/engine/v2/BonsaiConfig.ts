/**
 * Все конфигурационные параметры из оригинального GoBonsai.
 * Извлечены из full.c (sub_406AE0 вызовы) и rdata.
 * Имена точно соответствуют строкам в бинарнике.
 */
export const BonsaiConfig = {
    // --- Physics (full.c:5324-5360) ---
    gravity: 9.8,                    // flt_4D52F0
    density: 1.0,                    // flt_4D85FC
    leafWeight: 0.01,                // flt_4D860C
    accelerationRadiusPow: 2.0,      // flt_4D8600
    resistanceRadiusPow: 4.0,        // flt_4D8604
    resistanceCoeff: 1.0,            // flt_4D8608

    // --- Segment sizing (full.c:5362-5388) ---
    minSegmentSize: 0.01,            // flt_4D85E8
    maxSegmentSize: 0.1,             // flt_4D85EC
    minLeafSize: 0.005,              // flt_4D85F0
    maxLeafSize: 0.05,               // flt_4D85F4
    maxBudSize: 0.02,                // flt_4D85F8

    // --- Growth rates (full.c:5392-5406) ---
    lengthGrowRate: 0.1,             // flt_4D8614
    lengthGrowRatePow: 0.5,          // flt_4D8640
    radiusGrowRate: 0.01,            // flt_4D8618 - used in sub_417C90:20

    // --- Energy system (full.c:5408-5448) ---
    minBudEnergy: 0.001,             // flt_4D862C - порог для создания побегов
    maxBudEnergy: 0.1,               // flt_4D8630 - макс энергия почки
    leafEnergyProduction: 0.01,      // flt_4D8634
    apicalGrowthStrength: 0.7,       // flt_4D8638 - сила апикального роста
    energyRebalancePercent: 0.1,     // flt_4D863C
    energyAllowancePow: 2.0,         // flt_4D8628
    lightAdjustBudStemCoeff: 0.5,    // flt_4D8610

    // --- Update loop (full.c:12736-12762) ---
    energyUseRate: 1.0,              // flt_4D62E0
    energyLeak: 0.99,                // flt_4D62E4 - множитель утечки энергии

    // --- Metabolism (sub_416510.c, sub_417C90.c) ---
    healthEnergyAdjustment: 0.001,   // flt_4D6428 - шаг изменения здоровья
    quaternionSlerpRate: 0.05,        // flt_4D8624 - скорость интерполяции вращения
    directLightPercent: 0.5,          // flt_4D8CF0

    // --- Branching (sub_417FF0.c) ---
    randomBudRotation: 0.3,          // flt_4D642C

    // --- Rendering (sub_4093B0.c) ---
    radialSegments: 32,               // цикл в sub_4093B0:210 (v9 > 32)
    barkSpecular: 0.3,                // flt_4D62B4
    leafSpecular: 0.1,                // flt_4D62B8
    soilSpecular: 0.2,                // flt_4D62B0

    // --- Global flags ---
    updateGrowth: true,               // byte_4D62DC
    randomAutoCuts: false,            // byte_4D8CED
};

/**
 * Тип узла дерева (sub_408700.c:29)
 * a2+4 = type
 */
export enum NodeType {
    ROOT = 0,
    STEM = 1,
    LEAF = 2,
}
