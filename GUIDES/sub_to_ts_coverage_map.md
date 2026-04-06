# Карта `sub_*` → TypeScript: покрытие и статус паритета

**Назначение:** единая таблица для закрытия порта: где лежит TS, насколько он совпадает с C, что добирать через IDA (`decompile` + `xrefs_to`).  
**Связанные документы:** `c_truth_coverage_matrix.md` (спеки закрыты), **`ida_extracted_truth_log.md`** (журнал выводов IDA MCP по сабам), `spec_ts_parity_verification.md` (F5), скилл `.cursor/skills/ida-function-analysis/SKILL.md`.

## Легенда статуса


| Статус | Смысл                                                                                                      |
| ------ | ---------------------------------------------------------------------------------------------------------- |
| **✅**  | Логика перенесена, нет открытых `TODO(original)` по этому сабу в указанном модуле.                         |
| **🟡** | Есть рабочий порт, но известны пробелы: `TODO` / `APPROX` / прокси-поля / отличие от порядка вызовов в C.  |
| **🔶** | Другой стек (Three.js вместо VB/D3D): формулы/семантика из спеки частично, низкоуровневый паритет не цель. |
| **⛔**  | В TS нет прямого модуля; поведение не перенесено или только через комментарии в `TreeSection`.             |


*Проценты в скобках — субъективная оценка «близости к рабочему C» для подсистемы, не замер по exe.*

---

## A. Кадр роста и энергия


| sub_*        | Файл(ы) TS                                                                                             | Статус    | Примечание                                                                                                                |
| ------------ | ------------------------------------------------------------------------------------------------------ | --------- | ------------------------------------------------------------------------------------------------------------------------- |
| `sub_40DC90` | `growth/GrowthFramePipeline.ts`, `growth/sub40DC90PoolBalance.ts`, `growth/sub40DC90RandomAutoCuts.ts` | 🟡 (~82%) | Сборка фаз кадра; часть глобального состояния `dword_4D7EE8` разнесена по `WorldGrowthState` / `frameState`.              |
| `sub_40EE60` | `world/seasonCurveSub40EE60.ts`, `world/WorldGrowthState.ts`                                           | ✅ (~95%)  | Таблица `flt_4B786C[12]`.                                                                                                 |
| `sub_414E10` | `growth/sub414E10.ts`, `growth/virtualSlot36.ts`                                                       | 🟡 (~78%) | Распределение `+432`, rollup; в TS модель обхода отличается от vtable-цепочки C. `sub_4079C0` не переносится (намеренно). |
| `sub_414CE0` | `growth/sub414CE0.ts`, `GrowthFramePipeline.ts`                                                        | 🟡 (~70%) | `+428`: два поля в TS vs одно в C — см. комментарий «слить с energyWeight428».                                            |


---

## B. Слот +36 и жизненный цикл секций


| sub_*                       | Файл(ы) TS                                                          | Статус    | Примечание                                                                                       |
| --------------------------- | ------------------------------------------------------------------- | --------- | ------------------------------------------------------------------------------------------------ |
| `sub_417440`                | `growth/virtualSlot36.ts` (`maybeSeedSpawnSub417440`)               | 🟡 (~85%) | Первая почка; геометрия bud draw (`sub_416030`) в Three.js не 1:1.                               |
| `sub_415EF0`                | `growth/virtualSlot36.ts`                                           | 🟡 (~80%) | Bud после распределения энергии.                                                                 |
| `sub_415C10`                | `growth/virtualSlot36.ts`                                           | 🟡 (~82%) | `worldFlagByte220` ← **`dword_4D7EE8+220`** (см. **`ida_extracted_truth_log.md`**); порядок детей: `children[last]` vs HEAD в C. |
| `sub_415AB0` / `sub_4163B0` | `growth/virtualSlot36.ts`                                           | 🟡 (~80%) | Два листа при конверсии.                                                                         |
| `sub_417C90`                | `growth/twigUpdateSub417C90.ts`                                     | ✅ (~88%)  | Вызов `branchingDispatcherSub417F40` при `!growthFlag512`.                                       |
| `sub_418BD0`                | `growth/twigLengthGrowthSub418BD0.ts`                               | ✅ (~90%)  | Длина `+448`, pow-формула.                                                                       |
| `sub_416510` (лист)         | `growth/leafMetabolismSub416510.ts`, `MetabolismService.ts`         | 🟡 (~65%) | Свет/энергия/production; см. **`ida_extracted_truth_log.md`** § sub_416510.                     |
| `sub_416510` (вращение)     | `math/Sub416510Rotation.ts`                                         | 🟡 (~45%) | `TODO(original): sub_416510.c:226–273`; детали и callees — **`ida_extracted_truth_log.md`**.    |
| `sub_416300`                | `growth/virtualSlot36.ts`, `growth/branchingDispatcherSub417F40.ts` | ✅         | Фильтр twig по `byte_4D822A`.                                                                    |


---

## C. Ветвление (правило паритета)


| sub_*                 | Файл(ы) TS                                                          | Статус    | Примечание                                                                                                                                                                       |
| --------------------- | ------------------------------------------------------------------- | --------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `sub_417F40`          | `growth/branchingDispatcherSub417F40.ts`                            | 🟡 (~85%) | Диспетчер.                                                                                                                                                                       |
| `sub_4188E0`          | `growth/branchingDispatcherSub417F40.ts` (`lateralBranchSub4188E0`) | 🟡 (~85%) | RNG/кватернион **`(0,v19,-v15)`**, **`+452`**, **`branchPosition≈v11`**; остаётся **`APPROX`/`TODO`**: матрица **`+240`** и roll **`v20`** (журнал § **sub_413F50**).                |
| `sub_417FF0`          | `growth/branchingDispatcherSub417F40.ts`                            | 🟡 (~85%) | Углы/матрицы — упрощение vs C; **`+452`**: по одному **`sampleMaxGrowth452Sub4159C0`** на почку в **`createBudChild`**. `TODO(original)`: полный RNG/геометрия **417FF0**.         |
| `sub_418660`          | `growth/branchingDispatcherSub417F40.ts`                            | 🟡 (~90%) | YPR **`(0,v7,-v11)`**, RNG **`v8`/`v10`**, вес второй почки **`+428`**; матрицы **`sub_4158D0`** не портируем — только выравнивание rand.                                         |
| `sub_415470`          | `growth/branchingDispatcherSub417F40.ts`                            | ✅         | Метрика лет для условия апикального ветвления.                                                                                                                                   |
| `sub_4158D0`          | —                                                                   | 🔶        | Мат4: Translation **(0, a2, a3)** + Roll **a4**; вызывается из **`sub_4188E0`** — см. журнал § **sub_4158D0**.                                                                     |
| `sub_4159C0`          | `config/GrowthConstants.ts` (`sampleMaxGrowth452Sub4159C0`), `branchingDispatcher…`, `TreeSection.createBudFromSeed` | 🟡        | Поле **`+452`** при создании почки; полный конструктор **`sub_413F50`** — журнал § **sub_413F50**.                                                                                 |
| `sub_413F50`          | частично `TreeSection` / `branchingDispatcherSub417F40`             | 🟡        | Журнал § **sub_413F50**; латераль выставляет **`maxGrowth`/`branchPosition`/YPR без `+240`**.                                                                                      |
| `sub_4188E0` (legacy) | `BranchingService.ts`                                               | 🔶        | **Не используется** основным кадром (`GrowthController` → `twigUpdateSub417C90` → dispatcher). Дублирующая/старая эвристика; при чистке порта сверить с IDA и удалить или слить. |


---

## D. Матрицы и трансформы


| sub_*        | Файл(ы) TS                                | Статус    | Примечание                                 |
| ------------ | ----------------------------------------- | --------- | ------------------------------------------ |
| `sub_450BD0` | `growth/transformChainSub450BD0.ts`       | 🟡 (~85%) | World matrix + дети; Three.js `Object3D`.  |
| `sub_4146F0` | `growth/transformChainSub450BD0.ts`       | 🟡 (~85%) | Локальная `+40` из кватерниона.            |
| `sub_401540` | `MetabolismService.ts`, косвенно Three.js | 🟡        | `D3DXVec3TransformNormal` → матрицы Three. |
| `sub_4010C0` | `math/Sub416510Rotation.ts`               | ✅         | acos с clamp dot.                          |


---

## E. Свет, лучи, hit-test


| sub_*                                      | Файл(ы) TS                        | Статус    | Примечание                                                                                  |
| ------------------------------------------ | --------------------------------- | --------- | ------------------------------------------------------------------------------------------- |
| `sub_40E230`                               | `growth/lightTracingSub40E460.ts`       | PARTIAL (~75%) | INI `directLightPercent` + ray origin/dir prep; minor distribution approximations remain.                                 |
| `sub_40E460`                               | `growth/lightTracingSub40E460.ts`       | PARTIAL (~75%) | Ray march + decay pipeline; fallback source policy (twig tips when no leaves) remains approximate.                        |
| `sub_40E0A0`                               | `growth/lightTracingSub40E460.ts`       | PARTIAL (~65%) | Queue servicing and trace dispatch; batching policy differs from strict one-leaf-per-tick path.                            |
| `sub_40D610`                               | `growth/lightTracingSub40E460.ts`       | PARTIAL (~90%) | Random unit-vector generation is ported.                                                                                   |
| `sub_40D6D0`                               | `world/SectionSpatialQueriesSub40x.ts`  | DONE           | Basis-Y extraction via `sub_4015B0` helper is ported and used in leaf decay path.                                         |
| `sub_450E30` / `sub_450CD0`                | `growth/lightTracingSub40E460.ts`       | PARTIAL (~85%) | Broad-phase + recursive hit gather; hit records now sorted through `sub_451320` port (no ad-hoc JS index sort).          |
| `sub_450860` / `sub_450970` / `sub_450A80` | `growth/lightTracingSub40E460.ts`       | PARTIAL (~80%) | Segment/sphere distance and closest-point helpers are ported.                                                              |
| `sub_44EE20`                               | `growth/lightTracingSub40E460.ts`       | PARTIAL (~85%) | Segment-vs-segment screening for twig attenuation is ported.                                                               |
| `sub_450E10`                               | `growth/Sub451320Sort.ts`               | DONE           | Comparator parity: `return b.sortT > a.sortT` (C semantics).                                                              |
| `sub_451320` / `sub_451990`                | `growth/Sub451320Sort.ts`               | PARTIAL (~90%) | Runtime path parity for hit sorting (`n <= 30`): insertion-sort branch (`sub_451990`) is used 1:1.                       |


---

## F. Физика и покадровое сглаживание


| sub_*        | Файл(ы) TS                           | Статус    | Примечание                                                                                                                 |
| ------------ | ------------------------------------ | --------- | -------------------------------------------------------------------------------------------------------------------------- |
| `sub_4143E0` | `growth/perFramePhysicsSub4143E0.ts` | 🟡 (~75%) | Центроид `sub_414870`, ветер `sub_414A70`, damping `sub_414BB0`; `**APPROX*`* phototropism twig (`applyTwigLightSeeking`). |
| `sub_414870` | `growth/perFramePhysicsSub4143E0.ts` | 🟡 (~85%) | Веса / centroid.                                                                                                           |
| `sub_414A70` | `growth/perFramePhysicsSub4143E0.ts` | 🟡 (~80%) | Крутящий момент ветра.                                                                                                     |
| `sub_414BB0` | `growth/perFramePhysicsSub4143E0.ts` | 🟡 (~80%) | Сопротивление; константа `resistanceRadiusBias` в `GrowthConstants`.                                                       |


---

## G. Detach и «мировые» объекты


| sub_*        | Файл(ы) TS                               | Статус    | Примечание                                    |
| ------------ | ---------------------------------------- | --------- | --------------------------------------------- |
| `sub_40EEE0` | `growth/detachPipelineSub40EEE0.ts`      | 🟡 (~80%) | Слот `+48` / `sub_414270` — см. спеки vtable. |
| `sub_40F140` | `growth/worldObjectPipelineSub40F140.ts` | 🟡 (~80%) | Гравитация/ветер для оторванных.              |
| `sub_414270` | логика через `processDetachFlags`        | 🟡        | Обход + флаг `+236`.                          |


---

## H. Математика, цвет, константы


| sub_*                                                                    | Файл(ы) TS                                                   | Статус    | Примечание                                                                                       |
| ------------------------------------------------------------------------ | ------------------------------------------------------------ | --------- | ------------------------------------------------------------------------------------------------ |
| `sub_40FDE0`                                                             | `math/Sub40FDE0.ts`, `growth/materialCurveSub4151B0.ts`      | ✅ (~95%)  | Интерполяция палитры RGBA.                                                                       |
| `sub_4151B0`                                                             | `growth/materialCurveSub4151B0.ts`, `SectionColorService.ts` | 🟡 (~85%) | Кривая `(1-(1-x)^6)`; цвет веток в `SectionColorService` с отсылкой к `sub_416510`/`sub_40FDE0`. |
| `sub_40D0B0` / `sub_4701D0`                                              | `config/GrowthConstants.ts`                                  | 🟡 (~92%) | 23 float; `**APPROX*`* для `flt_4D8CF0` (lazy INI в exe).                                        |
| `sub_40FAD0` / `sub_415800` / `sub_40FBA0` / `sub_413C20` / `sub_403A90` | `config/GrowthConstants.ts`                                  | ✅ (~95%)  | Таблицы флагов типов — статическая инициализация в TS.                                           |


---

## I. Геометрия и рендер (низкоуровневый паритет)


| sub_*                                      | Файл(ы) TS                                                | Статус    | Примечание                                                                   |
| ------------------------------------------ | --------------------------------------------------------- | --------- | ---------------------------------------------------------------------------- |
| `sub_4093B0`                               | `GeometryService.ts`, `TreeSection.ts` (радиусы/сегменты) | 🔶 (~50%) | Цилиндр Three.js + UV; не VB/FVF/stride как в `spec_geometry_sub_4093B0.md`. |
| `sub_44F2A0`                               | *нет* — пайплайн Three.js                                 | 🔶        | Submit D3D заменён рендером движка.                                          |
| `sub_416030` / `sub_418F10` / `sub_417070` | косвенно `TreeSection` / материалы                        | 🔶        | Draw-процедуры из спеки; в TS упрощённая визуализация.                       |


---

## J. UI / статы / инициализация дерева


| sub_*        | Файл(ы) TS                                   | Статус    | Примечание                                                             |
| ------------ | -------------------------------------------- | --------- | ---------------------------------------------------------------------- |
| `sub_408D60` | `GrowthService.ts`, `GrowthFramePipeline.ts` | 🟡 (~75%) | Интерполяция UI-статов.                                                |
| `sub_408A30` | `GrowthService.ts`, `GrowthController.ts`    | 🟡 (~70%) | Годовые цели; в `GrowthController` осознанное упрощение изгиба ствола. |
| `sub_408880` | `GrowthController.ts`                        | 🟡        | Стартовые статы.                                                       |
| `sub_417220` | `BonsaiController.ts`                        | 🟡        | Инициализация семени (тип, `+428`).                                    |


---

## K. Верификация


| Артефакт                               | Файл                                     | Статус                                                        |
| -------------------------------------- | ---------------------------------------- | ------------------------------------------------------------- |
| MSVCRT `rand`                          | `MSVCRand.ts`                            | ✅                                                             |
| Эталонные снимки root `+420/+432/+436` | `__fixtures__/parityReferenceFromExe.ts`, `parityVerification.test.ts` | 🟡 CI: фикстура + harness; сравнение с exe — `GOBONSAI_EXE_PARITY=1` (`spec_ts_parity_verification.md`). |


---

## Очередь для IDA (остаточная истина → TS)

Рекомендуемый порядок (максимальный эффект на паритет симуляции):

1. `sub_416510` — журнал § **v44** + § **второй блок**; TS: полная цепочка до **`q42·q38`** и **`slerp`**; **`TODO(original):`** матрица **`this+352`** (не только **`rotationQuaternion`**), верификация **F5**.
2. `sub_415C10` — **`+220`** закрыт в журнале и TS; осталось при необходимости сверить **первого twig-ребёнка** vs **`+168`** / HEAD списка.
3. `sub_40E230` / `sub_40E0A0` / `sub_40E460` — **очередь и INI** зафиксированы в **`ida_extracted_truth_log.md`** (§ **sub_40E0A0**, **sub_40E230**); остаётся **TS**: один лист/тик, twig-fallback или `APPROX`.
4. `sub_4143E0` — участок, заменённый в TS на `applyTwigLightSeeking`: сверить с C построчно.
5. `sub_4188E0` — **`sub_413F50`** в журнале; в TS остаётся порт **`+240` × кватернион** и смещение **`twigRadius*0.85`** по локальным осям.
6. `sub_414CE0` + поля `this+428` — одна модель памяти в TS вместо `sub414CE0SeedBudget428` + `energyWeight428`.

**Сделано вне нумерации:** `sub_418660` — углы/RNG/вес второй почки в TS по **`full.c`** (2026-04-02).

Для каждого пункта: скилл **IDA Function Analysis** → `decompile` → таблица inputs/outputs → `xrefs_to` → **запись в `ida_extracted_truth_log.md`** → правка TS с комментарием `// sub_XXXXXX.c:line` или `TODO(original)` до полного совпадения.

---

## История

- 2026-04-02: первая версия карты по текущему `gobonsai-web/src/engine` и маркерам `TODO`/`APPROX`.
- 2026-04-02: ссылка на журнал **`ida_extracted_truth_log.md`**; правка очереди IDA (убраны битые `**` в списке).
- 2026-04-02: журнал — **`sub_40E0A0` / `sub_40E230` / глобалы очереди**; **`sub_4188E0`** → **`sub_4158D0`/`sub_4159C0`**; строки таблицы E и C обновлены под журнал.
- 2026-04-02: **`sub_413F50`** в **`ida_extracted_truth_log`**; латераль в TS: порядок RNG, **`+452`**, YPR **`(0,v19,-v15)`**, **`branchPosition≈v11`**; карта C/4188E0/413F50.
- 2026-04-02: **`sampleMaxGrowth452Sub4159C0`** — дефолт в **`createBudChild`**, семя **`createBudFromSeed`** (**`sub_417440`**).
- 2026-04-02: **`sub_418660`** в TS — углы/порядок rand/вес второй почки по **`full.c`** (~19059–19122).
- 2026-04-02: **`sub_416510`** — дизасм **`v44=(0,Ty,Tz)`**; **`Sub416510Rotation`** фаза 1 для листа; очередь IDA п.1 обновлена.
- 2026-04-02: **`sub_416510`** — второй блок в TS (**`Ry`**, **`q38`**, **`q42·q38`**); **`FLT_4D6388`**; журнал § второй блок.


---

## L. Runtime Queue Closures (2026-04-06)

| sub_* | TS file(s) | Status | Notes |
| --- | --- | --- | --- |
| `sub_4013f0` | `math/Vec3Sub40xPrimitives.ts` | ✅ (~95%) | Exact vec3 add primitive. |
| `sub_401430` | `math/Vec3Sub40xPrimitives.ts` | ✅ (~95%) | Exact vec3 subtract primitive. |
| `sub_401470` | `math/Vec3Sub40xPrimitives.ts` | ✅ (~95%) | Exact vec3 scalar multiply primitive. |
| `sub_401500` | `math/Vec3Sub40xPrimitives.ts` | ✅ (~95%) | Calling-convention alias of `sub_401470`. |
| `sub_4014b0` | `math/Vec3Sub40xPrimitives.ts` | ✅ (~95%) | Vec3 divide-by-scalar primitive. |
| `sub_401180` | `math/Vec3Sub40xPrimitives.ts` | ✅ (~90%) | Cross-product wrapper over `sub_401120`. |
| `sub_408470` | `math/Vec3Sub40xPrimitives.ts` | 🟡 (~88%) | Normalize-with-fallback helper (Three.js-backed). |
| `sub_408450` | `math/Vec3Sub40xPrimitives.ts` | ✅ (~92%) | Vec3 normalize/divide helper wrapper. |
| `sub_408590` | `math/Vec3Sub40xPrimitives.ts` | ✅ (~95%) | Unary negation helper. |
| `sub_4085b0` | `math/Vec3Sub40xPrimitives.ts`, `growth/perFramePhysicsSub4143E0.ts` | ✅ (~90%) | `TransformCoord` helper extracted and wired in centroid stage. |
| `sub_4084f0` | `math/Vec3Sub40xPrimitives.ts` | ✅ (~92%) | In-place normalize + original length return. |
| `sub_40cf00` | `math/Vec3Sub40xPrimitives.ts`, `growth/perFramePhysicsSub4143E0.ts` | ✅ (~92%) | In-place normalize wrapper integrated in frame physics path. |
| `sub_4032d0` | `config/IniRegistrySub408600.ts` | ✅ (~90%) | Wide-string assign parity helper. |
| `sub_4037b0` | `config/IniRegistrySub408600.ts` | ✅ (~90%) | Wide-string substring assign helper. |
| `sub_4033d0` | `config/IniRegistrySub408600.ts` | ✅ (~90%) | Init+assign wrapper preserved explicitly. |
| `sub_403410` | `config/IniRegistrySub408600.ts` | ✅ (~90%) | Reset/clear wrapper preserved explicitly. |
| `sub_403440` | `config/IniRegistrySub408600.ts` | DONE (~92%) | Wide-string erase helper with clamp semantics and invalid-position guard; alias path in `sub_4037B0` switched to C-style two-step erase. |
| `sub_4038b0` | `config/IniRegistrySub408600.ts` | 🟡 (~86%) | INI binding registration port. |
| `sub_408600` | `config/IniRegistrySub408600.ts` | 🟡 (~85%) | Registry wiring entrypoint present. |
| `sub_40fd70` | `config/IniRegistrySub408600.ts` | ✅ (~90%) | Intrusive list node allocator wrapper. |
| `sub_43fbb0` | `config/IniRegistrySub408600.ts` | DONE (~84%) | Full registry teardown wrapper for atexit path (drops list/init state, mirrors native cleanup intent). |
| `sub_43fd00` | `config/IniRegistrySub408600.ts` | 🟡 (~60%) | Exported init hook stub for web runtime bootstrap path. |
| `sub_44a640` | `config/IniRegistrySub408600.ts` | 🟡 (~80%) | Registry intrusive-list sorting helper. |
| `sub_472560` | `config/IniRegistrySub408600.ts` | 🟡 (~55%) | Exported atexit teardown stub (non-native runtime). |
| `sub_401730` | `config/SectionTypeRegistrySub401730.ts` | ✅ (~90%) | Type registration table with explicit function boundary. |
| `sub_4017d0` | `config/SectionTypeRegistrySub401730.ts` | 🟡 (~80%) | One-time recursive static-init pattern preserved. |
| `sub_401830` | `world/WorldObjectSub401830.ts` | 🟡 (~78%) | WorldObject base constructor port with identity matrices, object-id sequencing, intrusive global list append and id-index insert. |
| `sub_403b40` | `config/SectionTypeRegistrySub401730.ts` | DONE (~92%) | Type-base wrapper returns `5` and mirrors one-time `dword_4D7CF8` gate before `sub_4079C0` call. |
| `sub_413cf0` | `config/SectionTypeRegistrySub401730.ts`, `growth/virtualSlot36.ts` | ✅ (~90%) | Parent type-5 filter integrated in slot+36 flow. |
| `sub_40d6c0` | `world/SectionSpatialQueriesSub40x.ts` | ✅ (~90%) | Translation extractor (`this+104`). |
| `sub_40a310` | `world/SectionSpatialQueriesSub40x.ts` | ✅ (~90%) | Basis-Z extractor (`this+104[8..10]`). |
| `sub_4153d0` | `world/SectionSpatialQueriesSub40x.ts` | 🟡 (~85%) | Recursive max world-Y scan wrapper. |
| `sub_44e5d0` | `world/Sub44E5D0Pool.ts` | 🟡 (~84%) | Detached-item pool enqueue path. |
| `sub_451210` | `world/Sub451210Resolver.ts` | 🟡 (~85%) | Bucketed resolver/lookup path. |
| `sub_450e10` | `growth/Sub451320Sort.ts`, `growth/lightTracingSub40E460.ts` | DONE (~92%) | Hit comparator (`sortT`) extracted and wired into tracing hit-order pass. |
| `sub_451320` | `growth/Sub451320Sort.ts`, `growth/lightTracingSub40E460.ts` | DONE (~90%) | Introsort dispatcher integrated into hit-order pipeline. |
| `sub_451460` | `growth/Sub451320Sort.ts` | DONE (~88%) | Three-way partition helper for introsort branch. |
| `sub_451720` | `growth/Sub451320Sort.ts` | DONE (~88%) | Pivot preparation helper (median-of-three / median-of-nine). |
| `sub_4517d0` | `growth/Sub451320Sort.ts` | DONE (~86%) | Heap-build helper for depth-exhaust fallback path. |
| `sub_4518f0` | `growth/Sub451320Sort.ts` | DONE (~86%) | Heap-sort extraction pass for depth-exhaust fallback path. |
| `sub_451990` | `growth/Sub451320Sort.ts` | DONE (~90%) | Insertion-sort helper used for small ranges (`<= 32`). |
| `sub_451a80` | `growth/Sub451320Sort.ts` | DONE (~86%) | Median-of-three local ordering helper. |
| `sub_451b10` | `growth/Sub451320Sort.ts` | DONE (~84%) | Sift-down heap helper retained in parity module. |
| `sub_451c10` | `growth/Sub451320Sort.ts` | DONE (~84%) | Sift-up heap helper retained in parity module. |
| `sub_441e00` | `config/Sub44ListOps.ts` | DONE (~85%) | Sorted list insertion wrapper by key (`sub441E00InsertByKey`) with fixed-capacity guard. |
| `sub_444090` | `config/Sub44ListOps.ts` | DONE (~90%) | List sentinel init wrapper (`sub444090InitList`). |
| `sub_4440f0` | `config/Sub44ListOps.ts` | DONE (~90%) | List clear/destroy wrapper (`sub4440F0DestroyList`). |
| `sub_44a600` | `config/Sub44ListOps.ts` | DONE (~90%) | Version-string init wrapper (`sub44A600InitVersionString`, `"v0.276"`). |
| `sub_44b900` | `config/Sub44ListOps.ts` | DONE (~86%) | Splice-range pointer surgery wrapper (`sub44B900SpliceRange`). |
| `sub_44c260` | `config/Sub44ListOps.ts` | DONE (~86%) | Sorted list merge wrapper by key (`sub44C260MergeByKey`). |
| `sub_44c360` | `config/Sub44ListOps.ts` | DONE (~85%) | Node creation wrapper with explicit prev/next links (`sub44C360CreateNode`). |
| `sub_44bc80` | `config/Sub44StringOps.ts` | DONE (~84%) | UTF-16 append wrapper (`sub44BC80Append`) for bounded source-length copy. |
| `sub_444ae0` | `config/Sub44StringOps.ts` | DONE (~84%) | Wide-string move-assign wrapper (`sub444AE0MoveAssign`). |
| `sub_44a460` | `config/Sub44StringOps.ts` | DONE (~86%) | Wide-string append-range helper with bounds/clamp semantics (`sub44A460AppendRange`). |
| `sub_44c210` | `config/Sub44StringOps.ts` | DONE (~84%) | Lowercase range-copy helper (`sub44C210CopyLowerRange`). |
| `sub_444c00` | `config/Sub44StringOps.ts` | DONE (~84%) | Substring-find helper with explicit count limit (`sub444C00FindSubstr`). |
| `sub_446b40` | `config/Sub44CleanupOps.ts` | DONE (~86%) | Wide-string array reset-range helper (`sub446B40ResetWideRange`). |
| `sub_444140` | `config/Sub44CleanupOps.ts` | DONE (~84%) | Intrusive-list destroy/reset helper with optional payload cleanup callback (`sub444140DestroyList`). |
| `sub_444ce0` | `config/Sub44CleanupOps.ts` | DONE (~82%) | Bucket-table teardown helper with refcount drain (`sub444CE0DestroyBucketState`). |
| `sub_450c80` | `growth/sub450C80.ts`, `growth/virtualSlot36.ts`, `growth/detachPipelineSub40EEE0.ts` | ✅ (~90%) | Parent-child unlink helper extracted and reused in detach/conversion paths. |
| `sub_403580` | `config/IniRegistrySub408600.ts` | 🟡 (~82%) | Dynamic string-capacity growth helper (`sub403580Grow`). |
| `sub_4015f0` | `math/Sub4015F0.ts` | ✅ (~92%) | Matrix translation extractor wrapper. |
| `sub_4015d0` | `math/Sub4015F0.ts` | ✅ (~92%) | Matrix basis-Z extractor wrapper. |
| `sub_402cd0` | `world/WorldObjectSub401830.ts` | 🟡 (~72%) | Simplified id-index insertion wrapper (`sub402CD0InsertById`) replacing native bucket/tree internals with JS `Map`. |
| `sub_402e10` | `world/WorldObjectSub401830.ts` | 🟡 (~74%) | Simplified load-factor rehash wrapper (`sub402E10MaybeRehash`) with native hash-mix and bucket rebuild. |
| `sub_402ee0` | `world/WorldObjectSub401830.ts` | 🟡 (~76%) | Simplified transfer/splice wrapper (`sub402EE0TransferOne`) with list-size guard semantics. |
| `sub_402f60` | `world/WorldObjectSub401830.ts` | DONE (~86%) | Vector insert-fill helper (`sub402F60InsertFilled`) mirroring repeated-value insertion semantics. |
| `sub_4031b0` | `world/WorldObjectSub401830.ts` | DONE (~88%) | Pointer-vector allocation helper (`sub4031B0AllocatePointerVector`) with max-length guard. |
| `sub_403210` | `world/WorldObjectSub401830.ts` | DONE (~90%) | Fill helper (`sub403210FillValue`) for repeated pointer/value write. |
| `sub_4032a0` | `world/WorldObjectSub401830.ts` | DONE (~90%) | Forward copy-range helper (`sub4032A0CopyForward`). |
| `sub_403230` | `world/WorldObjectSub401830.ts` | DONE (~90%) | Intrusive node allocation wrapper (`sub403230CreateWorldNode`) for global world-object list. |
| `sub_44ede0` | `world/WorldObjectSub401830.ts` | 🟡 (~76%) | Simplified erase-and-advance wrapper (`sub44EDE0EraseAt`) for node-release semantics. |
| `sub_40fa00` | `config/SectionTypeRegistrySub401730.ts` | 🟡 (~88%) | Lazy init for type-8 flag path (`byte_4D8228`) + type registration side effect. |
| `sub_40fad0` | `config/SectionTypeRegistrySub401730.ts` | 🟡 (~90%) | Lazy init for type-7 flag path (`byte_4D8227`) + type registration side effect. |
| `sub_40fc70` | `config/SectionTypeRegistrySub401730.ts` | ✅ (~92%) | Null-safe filter by `byte_4D8227[11*type]` with lazy initializer call. |
| `sub_40fcf0` | `config/SectionTypeRegistrySub401730.ts` | ✅ (~92%) | Null-safe filter by `byte_4D8228[11*type]` with lazy initializer call. |
| `sub_401610` | `world/SectionSpatialQueriesSub40x.ts` | ✅ (~94%) | AABB merge primitive (min/min/min + max/max/max). |
| `sub_401690` | `world/SectionSpatialQueriesSub40x.ts` | ✅ (~92%) | AABB-to-sphere conversion helper (`center + radius`). |
| `sub_401b10` | `world/SectionSpatialQueriesSub40x.ts` | 🟡 (~88%) | Recursive subtree AABB builder over `center24`/`meshScalar36` abstraction. |
| `sub_401b00` | `world/SectionSpatialQueriesSub40x.ts`, `growth/branchingDispatcherSub417F40.ts` | 🟡 (~86%) | `sub_4015D0(out,this+40)` wrapper now wired in branching angle path via matrix basis-Z extraction. |
| `sub_403ba0` | `world/SectionSpatialQueriesSub40x.ts` | 🟡 (~84%) | First-child diameter helper with type-5 table gate (`byte_4D8225`). |
| `sub_4015b0` | `math/Sub4015F0.ts`, `growth/lightTracingSub40E460.ts`, `world/SectionSpatialQueriesSub40x.ts` | ✅ (~92%) | Basis-Y matrix extractor (`[4..6]`), now used in leaf-decay path (`sub_40D6D0` parity). |
| `sub_440650` | `config/IniRegistrySub408600.ts` | 🟡 (~86%) | Intrusive-list erase by key comparator (wide-string compare semantics). |
| `sub_401dd0` | `config/IniRegistrySub408600.ts`, `growth/sub40DC90GrowthTick.ts`, `growth/lightTracingSub40E460.ts` | 🟡 (~84%) | Lazy init + registry erase/reset helper wired into active cleanup stubs. |
| `sub_4720e0` | `growth/sub40DC90GrowthTick.ts` | 🟡 (~90%) | Cleanup wrapper mapped to `sub_401DD0(_energyLeakMeta4DBD14)`. |
| `sub_4720f0` | `growth/sub40DC90GrowthTick.ts` | 🟡 (~90%) | Cleanup wrapper mapped to `sub_401DD0(_energyUseRateMeta4DBD38)`. |
| `sub_472100` | `growth/sub40DC90GrowthTick.ts` | 🟡 (~90%) | Cleanup wrapper mapped to `sub_401DD0(_randomAutoCutsMeta4DBD5C)`. |
| `sub_472110` | `growth/sub40DC90GrowthTick.ts` | 🟡 (~90%) | Cleanup wrapper mapped to `sub_401DD0(_updateGrowthMeta4DBD80)`. |
| `sub_472170` | `growth/lightTracingSub40E460.ts` | 🟡 (~90%) | Cleanup wrapper mapped to `sub_401DD0(_directLightPercentMeta4DBCEC)`. |
| `sub_472180` | `growth/lightTracingSub40E460.ts` | 🟡 (~90%) | Cleanup wrapper mapped to `sub_401DD0(_lightDecayAmountMeta4DBCC4)` + lazy INI init in `sub_40E460`. |
| `sub_472410` | `growth/perFramePhysicsSub4143E0.ts` | DONE (~90%) | Cleanup wrapper mapped to `sub_401DD0(_debugLightVecMeta4DBC1C)` with lazy INI init in `sub_4143E0`. |
| `sub_472420` | `growth/perFramePhysicsSub4143E0.ts` | DONE (~90%) | Cleanup wrapper mapped to `sub_401DD0(_physicsEnabledMeta4DBC40)` with lazy INI init in `sub_4143E0`. |
| `sub_472430` | `growth/perFramePhysicsSub4143E0.ts` | DONE (~90%) | Cleanup wrapper mapped to `sub_401DD0(_resistanceRadiusBiasMeta4DBBF4)` with lazy INI init in `sub_4143E0`. |
| `sub_472460` | `growth/leafMetabolismSub416510.ts` | DONE (~90%) | Cleanup wrapper mapped to `sub_401DD0(_baseGrowthMultiplierMeta4DBB14)` with lazy INI init in `sub_416510`. |
| `sub_472470` | `growth/leafMetabolismSub416510.ts` | DONE (~90%) | Cleanup wrapper mapped to `sub_401DD0(_randomGrowthFactorMeta4DBB38)` with lazy INI init in `sub_416510`. |
| `sub_472480` | `growth/leafMetabolismSub416510.ts` | DONE (~90%) | Cleanup wrapper mapped to `sub_401DD0(_lightThresholdMaxMeta4DBB5C)` with lazy INI init in `sub_416510`. |
| `sub_472490` | `growth/leafMetabolismSub416510.ts` | DONE (~90%) | Cleanup wrapper mapped to `sub_401DD0(_lightThresholdMinMeta4DBB80)` with lazy INI init in `sub_416510`. |
| `sub_4724a0` | `growth/twigUpdateSub417C90.ts` | DONE (~90%) | Cleanup wrapper mapped to `sub_401DD0(_healthEnergyAdjustmentMeta4DBAEC)` with lazy INI init in `sub_417C90`. |
| `sub_4724b0` | `growth/branchingDispatcherSub417F40.ts` | DONE (~90%) | Cleanup wrapper mapped to `sub_401DD0(_randomBudRotationMeta4DBAC4)` with lazy INI init in `sub_417FF0`. |

