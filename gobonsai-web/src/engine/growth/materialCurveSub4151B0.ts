import { TreeSection } from "../TreeSection";
import { GrowthConstants } from "../config/GrowthConstants";
import { Float32 } from "../math/MathTypes";

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

const BASE_GROWTH = GrowthConstants.FLT_4D63B0 as number;

const MATERIAL_PALETTE: RGBA[] = [
    { r: 0.0,        g: 0.0,        b: 0.0, a: 1.0 },  // 0: black (dead)
    { r: 1.0,        g: 0.0,        b: 0.0, a: 1.0 },  // 1: red
    { r: BASE_GROWTH, g: BASE_GROWTH, b: 0.0, a: 1.0 },  // 2: olive/brown
    { r: 1.0,        g: 1.0,        b: 1.0, a: 1.0 },  // 3: white
    { r: 0.0,        g: 0.2,        b: 1.0, a: 0.0 },  // 4: blue-green
    { r: 1.0,        g: 1.0,        b: 0.0, a: 0.0 },  // 5: yellow
    { r: 0.0,        g: 0.7,        b: 0.0, a: 0.0 },  // 6: green
    { r: 1.0,        g: 1.0,        b: 1.0, a: 1.0 },  // 7: white
];

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

/**
 * sub_40FDE0: linear interpolation across an N-point palette.
 * t ∈ [0,1] maps to segments between palette keys.
 */
function interpolatePalette(palette: RGBA[], t: number): RGBA {
    const n = palette.length;
    if (n === 0) return { r: 0, g: 0, b: 0, a: 1 };
    if (n === 1) return { ...palette[0] };

    const clamped = Math.max(0, Math.min(1, t));
    const segment = clamped * (n - 1);
    const idx = Math.floor(segment);
    const frac = segment - idx;

    if (idx >= n - 1) return { ...palette[n - 1] };

    const a = palette[idx];
    const b = palette[idx + 1];
    return {
        r: a.r + (b.r - a.r) * frac,
        g: a.g + (b.g - a.g) * frac,
        b: a.b + (b.b - a.b) * frac,
        a: a.a + (b.a - a.a) * frac,
    };
}

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

    return interpolatePalette(MATERIAL_PALETTE, t);
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
