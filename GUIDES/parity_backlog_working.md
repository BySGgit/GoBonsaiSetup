# Рабочий backlog паритета (P0/P1/P2)

Этот backlog привязан к:

- `GUIDES/full_technical_parity_execution_plan.md`
- `GUIDES/decomp_master_manifest.csv`
- `GUIDES/sub_to_ts_coverage_map.md`
- `GUIDES/ida_extracted_truth_log.md`

## P0 (критично для 1:1 симуляции)

## P0.1 `sub_416510` rotation parity (`this+352`)

- C-источник: `sub_416510` (+ связанные math-callees).
- TS-файлы:
  - `gobonsai-web/src/engine/math/Sub416510Rotation.ts`
  - `gobonsai-web/src/engine/growth/perFramePhysicsSub4143E0.ts`
  - `gobonsai-web/src/engine/growth/transformChainSub450BD0.ts`
- Проблема: сейчас часть rotation path аппроксимирована quaternion-веткой.
- DoD:
  - `TODO(original)` по `this+352` закрыт;
  - trace-совпадение по rotation-полям на контрольных днях;
  - обновлен `ida_extracted_truth_log.md`.

## P0.2 `sub_4188E0` и `sub_417FF0` branch geometry/RNG parity

- C-источник: `sub_4188E0`, `sub_417FF0`, `sub_4158D0`, `sub_413F50`.
- TS-файлы:
  - `gobonsai-web/src/engine/growth/branchingDispatcherSub417F40.ts`
  - `gobonsai-web/src/engine/growth/virtualSlot36.ts`
  - `gobonsai-web/src/engine/growth/transformChainSub450BD0.ts`
- Проблема: `+240` матрица и `v20` roll не доведены до C, есть approximate path.
- DoD:
  - RNG call-order и распределение `+452` совпадают с эталоном;
  - локальная матрица ветви и roll совпадают по trace;
  - нет `APPROX/TODO(original)` в ветвлении P0-пути.

## P0.3 leaf queue / light tracing (`sub_40E0A0`, `sub_40E230`, `sub_40E460`)

- TS-файлы:
  - `gobonsai-web/src/engine/growth/lightTracingSub40E460.ts`
  - `gobonsai-web/src/engine/growth/GrowthFramePipeline.ts`
- Проблема: fallback без листьев через twig tips и batch-логика расходятся с C.
- DoD:
  - strict mode без fallback-трассировки через twig tips;
  - очередь листьев обслуживается как в C (по semantics и количеству за тик);
  - `directLightPercent` и связанные константы подтверждены в trace.

## P0.4 единая модель поля `+428` (`sub_414CE0`)

- TS-файлы:
  - `gobonsai-web/src/engine/growth/sub414CE0.ts`
  - `gobonsai-web/src/engine/TreeSection.ts`
  - `gobonsai-web/src/engine/growth/sub414E10.ts`
- Проблема: split на `sub414CE0SeedBudget428` и `energyWeight428`.
- DoD:
  - единый источник истины для `+428` в runtime;
  - годовая переработка и downstream-распределение совпадают с C;
  - regression-тест для year-boundary сценария.

## P0.5 parity strict-mode hardening

- TS-файлы:
  - `gobonsai-web/src/engine/growth/strictExeSimPath.ts`
  - `gobonsai-web/src/engine/growth/sub40DC90PoolBalance.ts`
  - `gobonsai-web/src/engine/parityVerification.test.ts`
- Проблема: TS-only стабилизаторы и approximation должны быть отключаемы полностью.
- DoD:
  - strict mode исключает gameplay caps/approx effects;
  - добавлен детерминизм-гейт (same seed -> same trace).

## P1 (высокий приоритет после P0)

## P1.1 расширение parity-fixtures (F5)

- Файлы:
  - `gobonsai-web/src/engine/__fixtures__/parityReferenceFromExe.ts`
  - `gobonsai-web/src/engine/parityVerification.test.ts`
- DoD:
  - >= 12 контрольных точек по дням/сезонам;
  - сравнение root + tree rollups + world globals.

## P1.2 `sub_4143E0` полное снятие approximations

- Файл: `gobonsai-web/src/engine/growth/perFramePhysicsSub4143E0.ts`
- DoD:
  - убран approximate phototropism path в strict;
  - подтверждение по IDA и trace-метрикам.

## P1.3 transform chain parity (`sub_450BD0`, `sub_4146F0`)

- Файл: `gobonsai-web/src/engine/growth/transformChainSub450BD0.ts`
- DoD:
  - восстановлен полный `+240` composition path;
  - нет "placeholder" комментариев в critical path.

## P1.4 detach/world object consistency

- Файлы:
  - `gobonsai-web/src/engine/growth/detachPipelineSub40EEE0.ts`
  - `gobonsai-web/src/engine/growth/worldObjectPipelineSub40F140.ts`
- DoD:
  - slot+44/48 жизненный цикл полностью верифицирован на trace.

## P2 (полный технический аудит)

## P2.1 покрытие всех `sub_*` в manifest

- Источник: `GUIDES/decomp_master_manifest.csv` (1221 функций).
- DoD:
  - у каждой функции класс (`runtime`, `physics/light`, `render`, `ui/infra`);
  - статус не `unmapped` для runtime-critical класса.

## P2.2 render-only divergence notes

- Файлы: `spec_geometry_sub_4093B0.md`, `spec_render_submit_sub_44F2A0.md`.
- DoD:
  - где стек намеренно другой (Three.js vs D3D), это явно задокументировано и изолировано.

## 3) Операционный ритм

Для каждого пункта backlog:

1. IDA truth extraction (`decompile`, `xrefs_to`) -> запись в `ida_extracted_truth_log.md`.
2. Минимальный TS-патч только под этот пункт.
3. Regression-тест/trace-assert.
4. Обновление `sub_to_ts_coverage_map.md`.
5. Регенерация manifest (`tools/update_decomp_manifest.ps1`).
