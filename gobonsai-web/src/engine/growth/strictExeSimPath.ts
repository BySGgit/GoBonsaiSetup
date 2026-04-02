/**
 * Режим паритета с оригинальным GoBonsai.exe (симуляция + визуал дерева без TS-only наслоений).
 *
 * Включается: `VITE_STRICT_EXE_SIM_PATH=true` (см. `BonsaiController`), либо явный флаг в `GrowthFramePipeline.run`.
 *
 * Что отключается (нет в sub_4143E0.c / не часть крутящего момента из INI):
 * - `applyTwigLightSeeking` в `perFramePhysicsSub4143E0.ts` (APPROX);
 * - покачивание веток `Date.now` + wind в `TreeSection.update`;
 * - покачивание листьев от времени в `TreeLeaf.update`;
 * - `tickEnvironment` (аналог `sub_412D20` — модуляция wind); в пайплайне вызывается **перед** `sub_4143E0`, как в `sub_4130D0.c`.
 *
 * Порядок фаз кадра см. заголовок `GrowthFramePipeline.run` (привязка к GUIDES/spec_update_growth_sub_40DC90.md).
 */
export function resolveStrictExeSimPath(override?: boolean): boolean {
    if (override !== undefined) return override;
    try {
        const env = (import.meta as unknown as { env?: Record<string, string | boolean> }).env;
        return env?.VITE_STRICT_EXE_SIM_PATH === "true" || env?.VITE_STRICT_EXE_SIM_PATH === true;
    } catch {
        return false;
    }
}
