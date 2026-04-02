import { seasonFactorSub40EE60 } from "./seasonCurveSub40EE60";
import { GrowthConstants } from "../config/GrowthConstants";

/**
 * Срез глобального состояния «мира» по аналогии с dword_4D7EE8 в exe:
 * - +196 — пул энергии E (абсолютная шкала, ~74.6 при старте)
 * - +216 — счётчик дней: в exe += 1.0 за каждый вызов sub_40DC90 (updateGrowth)
 * - +220 — byte: в exe переключается консольной командой (sub_406770, case 17);
 *   при !=0 и leafCount>2 ветка sub_415C10 помечает родителя на detach вместо создания twig.
 *
 * Сезон sub_40EE60(a1) использует +216 (не непрерывное gameTime).
 */
export class WorldGrowthState {
  /** *(v0+196) — абсолютный пул энергии (exe: ~74.6 при старте, убывает) */
  public energyPool: number = GrowthConstants.INITIAL_ENERGY_POOL_196 as number;

  /** *(v0+216) — дискретный тик симуляции (+1 за кадр роста, как в exe) */
  public simulationDay = 0;

  /**
   * `flt_4D7EF8` в `sub_4130D0.c`: дробный остаток «сколько раз подряд вызвать sub_40DC90»
   * за один вызов `sub_4130D0`. Увеличивается на `FLT_4D526C * SIM_FRAME_DT` за сим-кадр.
   * Exe сбрасывает в 0 после while-цикла (подтверждено трассой).
   */
  public growthAccumulator4D7EF8 = 0;

  /**
   * *(_BYTE *)(dword_4D7EE8 + 220). В оригинале по умолчанию 0; вкл/выкл — engine callback case 17
   * (sub_406770). Читает sub_415C10, sub_404C10 (UI цвет пункта меню).
   */
  public worldFlagByte220 = false;

  /** Нормализованная энергия [0,1] для UI/health (pool / initial). */
  get normalizedEnergy(): number {
    const init = GrowthConstants.INITIAL_ENERGY_POOL_196 as number;
    return Math.min(1.0, Math.max(0, this.energyPool / init));
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
