import { TreeSection } from "../TreeSection";
import { Float32 } from "../math/MathTypes";
import { sub413DF0InterpolateRgba } from "./sub413DF0Palette";

/**
 * sub_4151B0 — material/color resolver with ease-out curve.
 *
 * Curve: f(x) = 1 - (1 - x)^6
 * Palette: 8-point RGBA interpolated via sub_40FDE0.
 * Modes (dword_4D8644): 0/1 = no change, 2 = production, 3 = budget, 4 = spent, 5 = health.
 */

export interface RGBA {
    r: number;
    g: number;
    b: number;
    a: number;
}

/** Current color mode — mirrors dword_4D8644 */
let _colorMode = 0;

export function setMaterialColorMode(mode: number): void {
    _colorMode = mode;
}

export function getMaterialColorMode(): number {
    return _colorMode;
}

/** f(x) = 1 - (1 - x)^6 — ease-out curve */
function materialEaseOut(value: number): number {
    const x = Math.max(0, Math.min(1, value / 20.0));
    const t = 1.0 - Math.pow(1.0 - x, 6.0);
    return Math.max(0, Math.min(1, t));
}

const _tmpRgba413DF0 = new Float32Array(4);

/**
 * sub_4151B0: resolve material color for a section.
 * Returns null if mode 0/1 (use default color).
 */
export function resolveMaterialColor(section: TreeSection): RGBA | null {
    if (_colorMode <= 1) return null;

    let t: number;
    switch (_colorMode) {
        case 2: t = materialEaseOut(section.energyProduction420 as number); break;
        case 3: t = materialEaseOut(section.energyBudget432 as number); break;
        case 4: t = materialEaseOut(section.energySpent436 as number); break;
        case 5: t = Math.max(0, Math.min(1, section.healthEnergy456 as number)); break;
        default: return null;
    }

    sub413DF0InterpolateRgba(_tmpRgba413DF0, t);
    return {
        r: _tmpRgba413DF0[0],
        g: _tmpRgba413DF0[1],
        b: _tmpRgba413DF0[2],
        a: _tmpRgba413DF0[3],
    };
}

/**
 * Apply material color to a section's visual state (colorR/G/B).
 * Called from the draw/update pipeline.
 */
export function applyMaterialColorToSection(section: TreeSection): void {
    const color = resolveMaterialColor(section);
    if (color) {
        section.colorR = color.r as Float32;
        section.colorG = color.g as Float32;
        section.colorB = color.b as Float32;
    }
}
