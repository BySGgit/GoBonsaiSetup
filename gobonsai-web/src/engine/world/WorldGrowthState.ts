import { seasonFactorSub40EE60 } from "./seasonCurveSub40EE60";

/**
 * Срез глобального состояния «мира» по аналогии с dword_4D7EE8 в exe:
 * - +196 — пул энергии E (зеркалим stats.energy)
 * - +216 — счётчик дней: в exe += 1.0 за каждый вызов sub_40DC90 (updateGrowth)
 *
 * Сезон sub_40EE60(a1) использует +216 (не непрерывное gameTime).
 */
export class WorldGrowthState {
    /** *(v0+196) — энергия пула (синхронизируется с stats.energy) */
    public energyPool = 1.0;

    /** *(v0+216) — дискретный тик симуляции (+1 за кадр роста, как в exe) */
    public simulationDay = 0;

    /** Синхронизировать пул из UI/stats (после применения формул кадра). */
    syncEnergyFromStats(statsEnergy: number): void {
        this.energyPool = statsEnergy;
    }

    /**
     * sub_40DC90: *(v0+216) += 1.0; возвращает true, если пересечена граница года
     * (floor(day/365) увеличился).
     */
    advanceSimulationDay(): boolean {
        const prevYear = Math.floor(this.simulationDay / 365.0);
        this.simulationDay += 1.0;
        const nextYear = Math.floor(this.simulationDay / 365.0);
        return nextYear > prevYear;
    }

    /** sub_40EE60(simulationDay) — таблица flt_4B786C */
    seasonFactor(): number {
        return seasonFactorSub40EE60(this.simulationDay);
    }
}
