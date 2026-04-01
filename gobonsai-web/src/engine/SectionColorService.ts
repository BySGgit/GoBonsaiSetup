import { TreeSection } from './TreeSection';
import { GrowthConstants } from './config/GrowthConstants';
import { sub40FDE0 } from './math/Sub40FDE0';

const _rgba = new Float32Array(4);

/**
 * sub_416510.c:166–224 — цвет ветки через sub_40FDE0 и фиксированные ключи из стека v43.
 * Порядок записи float в v43 — full.c ~18133–18140 и ~18150–18164.
 */
export class SectionColorService {
    /** full.c:18133–18140 — два одинаковых RGBA-ключа (оба flt_4D63B0, 1,0,1); t = age/110 */
    private static buildHighEnergyKeys(): Float32Array {
        const b0 = GrowthConstants.FLT_4D63B0;
        return new Float32Array([b0, 1.0, 0.0, 1.0, b0, 1.0, 0.0, 1.0]);
    }

    /**
     * full.c:18150–18164 — итоговые индексы 0..11 после всех присваиваний в v43.
     * Ключи sub_40FDE0: 3×RGBA.
     */
    private static readonly LOW_ENERGY_KEYS = new Float32Array([
        0.69, 0.40000001, GrowthConstants.AUX_ROTATION_CONST, 1.0,
        1.0, GrowthConstants.AUX_ROTATION_CONST, GrowthConstants.ROTATION_ADJUSTMENT, 1.0,
        1.0, 1.0, 0.0, 1.0
    ]);

    public static applyFrom416510(section: TreeSection, treeAge: number): void {
        const energy = section.energy;
        const age = treeAge;

        if (energy >= 1.0 - 1e-5) {
            if (age >= 110.0) {
                section.colorR = 0.30000001;
                section.colorG = 1.0;
                section.colorB = 0.2;
                section.colorA = 1.0;
            } else {
                const t = Math.min(1.0, age / 110.0);
                sub40FDE0(2, _rgba, SectionColorService.buildHighEnergyKeys(), t);
                section.colorR = _rgba[0];
                section.colorG = _rgba[1];
                section.colorB = _rgba[2];
                section.colorA = _rgba[3];
            }
        } else {
            sub40FDE0(3, _rgba, SectionColorService.LOW_ENERGY_KEYS, energy);
            section.colorR = _rgba[0];
            section.colorG = _rgba[1];
            section.colorB = _rgba[2];
            section.colorA = _rgba[3];
        }

        section.colorR = Math.min(1, Math.max(0, section.colorR));
        section.colorG = Math.min(1, Math.max(0, section.colorG));
        section.colorB = Math.min(1, Math.max(0, section.colorB));
        section.colorA = Math.min(1, Math.max(0, section.colorA));
    }
}
