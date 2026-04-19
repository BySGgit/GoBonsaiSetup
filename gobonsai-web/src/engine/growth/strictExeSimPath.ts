/**
 * Режим паритета с оригинальным GoBonsai.exe (симуляция + визуал дерева без TS-only наслоений).
 *
 * Включается: `VITE_STRICT_EXE_SIM_PATH=true` (см. `BonsaiController`), либо явный флаг в `GrowthFramePipeline.run`.
 *
 * Что отключается (нет в sub_4143E0.c / не часть крутящего момента из INI):
 * - TS-only фототропизм twig в `perFramePhysicsSub4143E0.ts` (убран из runtime пути);
 * - покачивание веток `Date.now` + wind в `TreeSection.update`;
 * - покачивание листьев от времени в `TreeLeaf.update`;
 * - TS-only визуальные надстройки, не влияющие на exe-путь ресурсов/иерархии.
 *
 * `tickEnvironment` (аналог `sub_412D20`) в parity-пути не отключается
 * и вызывается перед `sub_4143E0`, как в `sub_4130D0.c`.
 *
 * Порядок фаз кадра см. заголовок `GrowthFramePipeline.run` (привязка к GUIDES/spec_update_growth_sub_40DC90.md).
 */
export function resolveStrictExeSimPath(override?: boolean): boolean {
    if (override !== undefined) return override;
    try {
        const env = (import.meta as unknown as { env?: Record<string, string | boolean> }).env;
        const raw = env?.VITE_STRICT_EXE_SIM_PATH;
        if (raw === "true" || raw === true) return true;
        if (raw === "false" || raw === false) return false;
        // Parity-first default when env key is absent.
        return true;
    } catch {
        // Safe default for parity-first porting: keep strict EXE path enabled
        // unless explicitly disabled by caller/env override.
        return true;
    }
}
