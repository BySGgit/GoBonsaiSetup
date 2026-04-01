/**
 * Эталонные снимки с оригинального GoBonsai.exe (IDA, скрипт из GUIDES/spec_f5_ida_capture_workflow.md).
 * Условия: глобал dword_4D7EE8 по адресу 0x4D7EE8 (без сдвига ASLR в этой сессии).
 * W и R — как в выводе IDA; поля — float у корня дерева (root+420/432/436).
 *
 * Только хранение эталона для будущей регрессии. Автотесты против этих чисел — после того,
 * как TS-движок будет доведён до соответствия спекам (см. spec_ts_parity_verification.md §3.1).
 */

/** Указатель на объект «мир» (для справки; в TS не обязан совпадать). */
export const parityRefW = 0x0258e428;

/** Указатель на корневую секцию (для справки). */
export const parityRefRootR = 0x0258e768;

export interface ParitySnapshot {
    /** Время: *(float*)(W + 216) */
    worldTime: number;
    root420: number;
    root432: number;
    root436: number;
}

/** Останов на sub_40DC90, первый снятый снимок */
export const paritySnapshotA: ParitySnapshot = {
    worldTime: 108.0,
    root420: 1.715135931968689,
    root432: 1.7341139316558838,
    root436: 1.7341139316558838,
};

/** Тот же процесс, через 7 тиков симуляции (115 − 108) */
export const paritySnapshotB: ParitySnapshot = {
    worldTime: 115.0,
    root420: 1.7246016263961792,
    root432: 1.7062835693359375,
    root436: 1.7062835693359375,
};

/** Разница по времени между снимками (должна совпадать с числом вызовов sub_40DC90 между остановами). */
export const parityDeltaTicksBetweenAB = paritySnapshotB.worldTime - paritySnapshotA.worldTime; // 7
