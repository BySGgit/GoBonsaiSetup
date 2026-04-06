import { GrowthConstants } from "../config/GrowthConstants";
import { sub40FDE0 } from "../math/Sub40FDE0";

let dword4D8D1C = 0;
let palette4D8D20 = new Float32Array(8 * 4);

function initSub413DF0PaletteOnce(): void {
  if ((dword4D8D1C & 1) !== 0) return;
  dword4D8D1C |= 1;

  palette4D8D20 = new Float32Array([
    0.0, 0.0, 0.0, 1.0,
    1.0, 0.0, 0.0, 1.0,
    1.0, GrowthConstants.FLT_4D63B0 as number, 0.0, 1.0,
    1.0, 1.0, 0.0, 1.0,
    0.0, GrowthConstants.FLT_4D62E8 as number, 0.2, 1.0,
    0.0, 0.0, 1.0, 1.0,
    0.69999999, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0,
  ]);
}

/**
 * sub_413DF0: lazy-init fixed 8-key RGBA palette and interpolate by t.
 * sub_413df0
 */
export function sub413DF0InterpolateRgba(
  out: Float32Array | number[],
  t: number,
): Float32Array | number[] {
  initSub413DF0PaletteOnce();
  sub40FDE0(8, out, palette4D8D20, t);
  return out;
}

export function resetSub413DF0StateForTests(): void {
  dword4D8D1C = 0;
  palette4D8D20 = new Float32Array(8 * 4);
}

export function getSub413DF0StateForTests(): { dword4D8D1C: number } {
  return { dword4D8D1C };
}
