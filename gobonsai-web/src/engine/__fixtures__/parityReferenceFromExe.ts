/**
 * Эталонные снимки с оригинального GoBonsai.exe (IDA trace: GoBonsai.exe_gobonsai_trace.jsonl).
 * Условия: dword_4D7EE8 → мир 0x262b498, корень 0x262b7d8; без ASLR.
 * flt_4D526C = 50, SIM_DT ≈ 0.0333 → flt_4D7EF8 = 0.6666 при sub_40DC90.
 * Трасса: 2501 записей, дни 0–46.
 *
 * Регрессия: см. `parityVerification.test.ts`.
 */

export interface ParitySnapshot {
    simulationDay: number;
    energyPool196: number;
    childCount172: number;
    energyBudget432: number;
    energySpent436: number;
    energyProduction420: number;
    rollupDword480: number;
    rollupDword484: number;
    flt_4D7EF8: number;
}

/** seq 1: sub_412700, самое начало — корень без детей */
export const parityDay0: ParitySnapshot = {
    simulationDay: 0,
    energyPool196: 74.60920715,
    childCount172: 0,
    energyBudget432: 0,
    energySpent436: 0,
    energyProduction420: 0,
    rollupDword480: 0,
    rollupDword484: 0,
    flt_4D7EF8: 0,
};

/**
 * seq 1644→1645: sub_40DC90 день 30 → первый ребёнок при day=31.
 * Это снимок ПОСЛЕ sub_40DC90 (вход в sub_40E0A0).
 */
export const parityDay31: ParitySnapshot = {
    simulationDay: 31,
    energyPool196: 70.05237579,
    childCount172: 1,
    energyBudget432: 0.06737298,
    energySpent436: 0.06737298,
    energyProduction420: 0,
    rollupDword480: 1,
    rollupDword484: 0,
    flt_4D7EF8: 0,
};

/**
 * seq 2427+: день 45 — «скриншот HUD» (45 Days, 2 Leaves, 0.01" Height).
 * rollupDword484 впервые = 1 (второй лист/бутон в дереве).
 */
export const parityDay45: ParitySnapshot = {
    simulationDay: 45,
    energyPool196: 57.75484848,
    childCount172: 1,
    energyBudget432: 1.42138267,
    energySpent436: 1.42138267,
    energyProduction420: 0,
    rollupDword480: 1,
    rollupDword484: 1,
    flt_4D7EF8: 0,
};

/**
 * seq 2486: день 46 (первый кадр после «скриншотного» состояния).
 * energyProduction420 впервые != 0 — вклад листа.
 */
export const parityDay46: ParitySnapshot = {
    simulationDay: 46,
    energyPool196: 56.18097687,
    childCount172: 1,
    energyBudget432: 1.47947311,
    energySpent436: 1.47947311,
    energyProduction420: 0.01818814,
    rollupDword480: 1,
    rollupDword484: 1,
    flt_4D7EF8: 0,
};

/** Энергетический пул по дням — для проверки decay-кривой 0.998 */
export const parityEnergyPoolByDay: Array<[day: number, pool: number]> = [
    [0, 74.60920715],
    [1, 74.45999146],
    [2, 74.31107330],
    [3, 74.16245270],
    [4, 74.01412964],
    [5, 73.86610413],
    [10, 73.13040161],
    [15, 72.40202332],
    [18, 71.96847534],
    [30, 70.26013184],
    [31, 70.05237579],
    [45, 57.75484848],
    [46, 56.18097687],
];
