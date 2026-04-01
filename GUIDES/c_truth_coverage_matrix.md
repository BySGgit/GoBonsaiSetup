# Матрица извлечения «истины» из C (что осталось до 100% паритета)

Цель: иметь **полный список** (1) точек входа/циклов кадра, (2) виртуальных слотов vtable по `TreeSection*`, (3) констант INI/пресетов и (4) нерешённых “OPEN”, которые мешают переносу на TS без догадок.

Статусы:

- ✅ **spec**: есть восстановленная спецификация (входы/выходы/поля/константы/псевдокод)
- 🟡 **partial**: часть разобрана, остались OPEN/неясные поля
- ⛔ **todo**: ещё не разбирали

---

## 1) Глобальный цикл роста/энергии (кадр)


| Узел         | Назначение                                                                                                                                                   | Статус | Примечание                                                                             |
| ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------ | ------ | -------------------------------------------------------------------------------------- |
| `sub_40DC90` | “updateGrowth”: обновляет энергию, пишет `root+432`, вызывает virtual `+36` (update по типу секции), балансирует `root+436/root+420`, применяет `energyLeak` | ✅ spec | см. `spec_update_growth_sub_40DC90.md`                                                 |
| `sub_40EE60` | сезонный коэффициент (month curve) для `root+432` через таблицу `flt_4B786C[12]`                                                                             | ✅ spec | см. `spec_update_growth_sub_40DC90.md`                                                 |
| `sub_414E10` | перераспределение по детям: пишет `child+432 = share * parent+432`                                                                                           | ✅ spec | уже используется в `spec_initial_sprout_growth.md`                                     |
| `sub_414CE0` | virtual `+40`: “годовой/пост-агрегационный тик” (finalize `+424/+428`, затем рекурсивный вызов `(*child+40)`)                                                | ✅ spec | вызывается на границе года в `sub_40DC90` (для `TreeSectionSeed` `+40` → `sub_414CE0`) |


---

## 1.2) Рендер submit / вершинные буферы


| Узел         | Назначение                                                                  | Статус | Примечание                             |
| ------------ | --------------------------------------------------------------------------- | ------ | -------------------------------------- |
| `sub_44F2A0` | submit draw call (world matrix + material + VB/FVF/stride + draw primitive) | ✅ spec | см. `spec_render_submit_sub_44F2A0.md` |


---

## 1.1) Энергетические аккумуляторы дерева (`+420` / `+436`)


| Узел         | Назначение                                                                     | Статус | Примечание                               |
| ------------ | ------------------------------------------------------------------------------ | ------ | ---------------------------------------- |
| `sub_414E10` | сброс и суммирование `+420/+436` по детям                                      | ✅ spec | ключевой аккумулятор                     |
| `sub_418BD0` | выставляет `this+436 = min(this+432, maxBudEnergy)` во время роста длины твика | ✅ spec | трактуем как “стоимость elongation”      |
| `sub_417620` | добавляет `+436 += minBudEnergy` при создании побега                           | ✅ spec | расход на спавн                          |
| `sub_417FF0` | добавляет `+436 += v17` при апикальном/билатеральном ветвлении                 | ✅ spec | расход на ветвление                      |
| `sub_4188E0` | добавляет `+436 += v23` при боковой ветке                                      | ✅ spec | расход на ветвление                      |
| `sub_416510` | пишет production: `this+420 = v19` и интеграл `this+424 += v19`                | ✅ spec | `*((float*)this+105/106)` в `sub_416510` |


---

## 2) Виртуальные таблицы `TreeSection*` (из `decompiled/rdata.txt`)

Ниже — “истина” о том, какие сабы стоят в каких слотах. Для паритета важно понять, что есть `update`, что есть `draw`, и какой слот вызывается в каком месте глобального цикла.

### 2.1 `TreeSection` base vtable (`.rdata:004B7EF4`)

Слоты (по порядку после первого указателя vtable):

1. `__RTC_NumErrors_0`
2. `sub_415990`
3. `sub_401A50`
4. `sub_4143E0`
5. `sub_450BD0`
6. `sub_414FF0`  ← обход детей (+20 вызов в нескольких draw-процедурах)
7. `nullsub_5`
8. `sub_450B80`
9. `sub_4146F0`
10. `sub_414E10`
11. `sub_414CE0`
12. `...Concurrency...`
13. `sub_414270`
14. `sub_4142B0`
15. `sub_413F30`
16. `sub_415440`

Статус: ✅ spec (семантика слотов снята по сабам; см. ниже).

Дополнено:

- слот `+44` для base/leaf/twig/stump **не no-op**: ставит `this+236 = 1`, а дальше `sub_414270/sub_418E40` при флаге вызывают `sub_40EEE0(this)` (см. `spec_vtable_slot_44.md`, `spec_detach_pipeline_sub_40EEE0.md`).

Быстрые семантические имена (по факту чтения сабов, без догадок):

- `+4` `sub_415990`: **деструктор** `TreeSection` (ставит vftable, вызывает `sub_4019F0`, при флаге удаляет `this`).
- `+8` `sub_401A50`: **markWorldManaged**: ставит `this+188 = 1`, затем `sub_401A70(this)` (инициализация world-object поведения).
- `sub_401A70`: **detachAllChildren**: у всех детей вызывает `(*child+8)` + обнуляет `child+180` (parent), затем очищает список детей и удаляет узлы списка.
- `+12` `sub_4143E0`: **per-frame update (world/physics-ish)**: вызывает у детей `(*child+12)`, обновляет internal векторы/сглаживания; при отладочном флаге рисует/логирует.
- `+16` `sub_450BD0`: **updateWorldMatrix + propagate to children**: сначала `(*this+32)`, затем вычисляет `this+104` (world matrix) из локальной `this+40` и родителя, и вызывает у детей `(*child+16)` + цепляет матрицы в узлы.
- `+20` `sub_414FF0`: **visitChildren(slot+20)**: вызывает у всех детей их `(*child+20)` и возвращает последний результат.
- `+24` `nullsub_5`: **no-op** (пустой слот).
- `+28` `sub_450B80`: **broadcast(event)**: вызывает у детей `(*child+28)(a2,a3)`, затем вызывает `(*this+24)` (собственную реализацию события).
- `+32` `sub_4146F0`: **rebuildLocalMatrices/position**: вычисляет `this+40` / `this+352` (inverse), и пишет позицию `this+24..32` через матричные преобразования.
- `+36` `sub_414E10`: **growth update / energy aggregation** (см. отдельные спеки; у наследников слот переопределён).
- `+40` `sub_414CE0`: **yearly finalize** (finalize `+424/+428`, обходит детей `(*child+40)`).
- `+48` `sub_414270`: **post-update detach processing**: вызывает у детей `(*child+48)`, затем если `this+236!=0` → `sub_40EEE0(this)`.
- `+52` `sub_4142B0`: **auto-cut climb**: поднимается по родителям до условий и при типе `byte_4D8225[...]` делает `sub_40EEE0(this)` (см. `sub_4154B0` для подсчёта “живых” детей).
- `+56` `sub_413F30`: **growthScore**: возвращает `this+444^2 * this+448` (в декомпиле: `this[111]^2 * this[112]`).
- `+60` `sub_415440`: **countSomethingRecursive**: суммирует по детям `(*child+60)` (используется как общий “счётчик” по дереву).

Отдельно:

- `sub_4086F0`: **returns 1** (в leaf vtable стоит в последнем слоте; вероятно булевый “isRenderable/hasGeometry”, но по факту — всегда true).

Статус: ✅ spec (слоты base vtable покрыты чтением/вызовами).

### 2.2 `TreeSectionSeed` (`.rdata:004B8054`)

Ключевые отличия:

- слоты включают `sub_417300` и `sub_417440` (см. `spec_initial_sprout_growth.md`):
  - `sub_417440`: создаёт первую `Bud` при `this+432 > 0`

Статус: ✅ spec (для sprout chain).

### 2.3 `TreeSectionBud` (`.rdata:004B7F3C`)

Отличия:

- draw/геометрия: `sub_416030`
- рост/конверсия: `sub_415EF0` (вызывает `sub_415C10`)

Статус: ✅ spec (sprout->bud->twig).

### 2.4 `TreeSectionTwig` (`.rdata:004B8134`)

Отличия:

- draw/геометрия: `sub_418F10`
- update: `sub_417C90` (вызывает `sub_418BD0`, рост длины `+448`)

Статус: ✅ spec (sprout->twig length growth).

### 2.5 `TreeSectionLeaf` (`.rdata:004B800C`)

Отличия:

- draw: `sub_417070`
- “большой” update: `sub_416510` (метаболизм/цвет/кватернионы/часть роста)

Добрано:

- `sub_417070` — draw: матрица T/S/R вокруг `this+444` и вызов `sub_44F2A0`; цвет/материал через `sub_4151B0` (режим `dword_4D8644`, кривая 1-(1-x)^6).
- `sub_416EC0` — доп. draw-процедура leaf (использует `this+444`, `this+111`, pitch=2.1991148).
- `sub_416390` — slot `+56`: возвращает `this+448 * this+444 * flt_4D860C`.
- `sub_416500` — thunk на base `sub_4143E0` (slot `+12`).
- `sub_416380` — возвращает `7` (тип/ID).

Статус: ✅ spec (рантайм подтверждён writer для `typeId=7`: `sub_40FAD0` пишет `byte_4D8274=1`, то есть `byte_4D8227[11*7]=1`; ветка `lightDecayAmount` в `sub_40E460` достижима для leaf).

---

## 3) Константы INI и пресеты `sub_40D0B0`

### 3.1 INI (через `sub_406AE0`) — полный список

Статус: ✅ spec — `**GUIDES/spec_ini_and_console_keys_inventory.md`** (21 ключ дерева/физики; отдельно перечислены имена `sub_4032D0` для роста/света).

### 3.2 Preset `sub_4701D0` → `sub_40D0B0` (дефолтные значения)

Статус: ✅ spec — `**GUIDES/spec_preset_sub_40D0B0_sub_4701D0.md**` (порядок 23 float → глобалы; литералы `sub_4701D0`).

Замкнуто по декомпилу:

- **других прямых вызовов `sub_40D0B0` нет**; «альтернативный пресет» = перезапись теми же глобалами через INI после старта (или неотслеженные косвенные записи — не требуются для явного маппинга порта).

---

## 4) Топ “что осталось” для 100% паритета (самое важное)

1. ✅ `sub_40DC90` + `sub_40EE60` (энергия, порядок вызовов, флаги) — закрыто (см. `spec_update_growth_sub_40DC90.md`).
2. ✅ Полные “семантические имена” слотов base vtable `TreeSection` (чтобы переносить не “куда-то”, а в правильную точку pipeline).
3. ✅ `sub_4093B0` (геометрия/буфер вершин) 1:1. Закрыто: формат (stride/FVF/primitive), D3D9 `CreateVertexBuffer/Lock/Unlock` и связь с `sub_409910/sub_409130/sub_44F2A0`. См. `spec_geometry_sub_4093B0.md`.
4. ✅ Полный leaf pipeline: `sub_416510`, `sub_417070`, спавн/очередь — `spec_leaf_update_sub_416510.md`, `spec_leaf_spawn_and_global_leaf_list.md`.
5. ✅ Ветвление как единая система — `**GUIDES/spec_branching_dispatcher_sub_417F40.md`** (`sub_417F40` → `sub_4188E0` / `sub_417FF0` / `sub_418660`).
6. ✅ Detach/world-objects pipeline — `spec_vtable_slot_44.md`, `spec_detach_pipeline_sub_40EEE0.md` (детализация world-list при необходимости — по тем же сабам в IDA).

### Batch 2 (закрыто)

1. ✅ **Полная карта полей** `this+0..+520` — `spec_constructor_sub_413F50.md`.
2. ✅ **Полный Twig update** `sub_417C90` (girth, slerp, growth/branch, health, death) — `spec_twig_update_sub_417C90.md`.
3. ✅ **Bud→Twig конверсия** `sub_415EF0`/`sub_415C10` + спавн листьев — `spec_bud_to_twig_sub_415EF0_sub_415C10.md`.
4. ✅ **Трансформ-цепочка** `sub_450BD0`/`sub_4146F0` (slot +16/+32) — `spec_transform_chain_sub_450BD0_sub_4146F0.md`.
5. ✅ **Per-frame physics** `sub_4143E0` (slot +12, сглаживание света) — `spec_perframe_physics_sub_4143E0.md`.
6. ✅ **Leaf light tracing** `sub_40E230`→`sub_40E460`→`sub_450E30/CD0` — `spec_leaf_light_tracing_sub_40E460.md`.
7. ✅ **Draw-процедуры** Bud/Twig/Leaf/Soil (формулы масштаба) — `spec_draw_procedures.md`.
8. ✅ **World-object pipeline** `sub_40F140` (gravity, wind, cleanup) — `spec_world_object_pipeline_sub_40F140.md`.
9. ✅ **Таблицы типов** `sub_40FAD0`/`sub_401730`/`sub_403A90` — `spec_type_tables_sub_40FAD0.md`.
10. ✅ **Рост длины twig** `sub_418BD0` (pow-формула) — `spec_twig_length_growth_sub_418BD0.md`.

### Batch 3 (закрыто)

1. ✅ **Таблицы byte_4D8229/822A** — `sub_40FBA0` (Twig: #10), `sub_413C20` (Stump: #9) — обновлено в `spec_type_tables_sub_40FAD0.md`.
2. ✅ **Пружинная/ветровая физика** `sub_414A70`/`sub_414BB0`/`sub_414870` — `spec_spring_wind_physics_sub_414A70_414BB0.md`.
3. ✅ **Кривая материала** `sub_4151B0` + палитра `sub_413DF0` — `spec_material_curve_sub_4151B0.md`.
4. ✅ **Обрезка мышью** (полная цепочка WndProc → пометка → detach) — `spec_input_pruning_mouse.md`.

### Мелкие точки (закрыто)

1. ✅ `flt_4D6388 = π/2` (1.5707964), `flt_4D6430 = 0.97`, `dword_4D8040` = динамическая mesh-таблица (stride 17) — обновлено в `spec_draw_procedures.md`.
2. ✅ `sub_415800` = инициализатор **Bud (type=6)**: `byte_4D8268 = 1` → flag #6, `sub_403A90(6)` → flag #0/#5. Обновлено в `spec_type_tables_sub_40FAD0.md`.
3. ✅ `byte_4D8226` (flag #6) = **только Bud (type=6)** → «невесомый» (storedMass/totalWeight = 0 в `sub_414870`). Обновлено в `spec_spring_wind_physics_sub_414A70_414BB0.md`.

### Оставшиеся OPEN

**Нет.** Все документированные подсистемы закрыты. Порт может идти по спецификациям.

---

## 5) Ссылки на текущие спеки

- `GUIDES/spec_initial_sprout_growth.md` — seed→bud→twig, рост `+448`, маппинг `+432`.
- `GUIDES/c_truth_extraction_workflow.md` — общий процесс “сначала истина, потом TS”.
- `GUIDES/spec_update_growth_sub_40DC90.md` — updateGrowth + сезонность + virtual `+36`.
- `GUIDES/spec_energy_accumulators_420_436.md` — расход `+436`, production `+420` (writer найден).
- `GUIDES/spec_leaf_update_sub_416510.md` — свет→энергия→production `+420`→рост `+111` внутри leaf update.
- `GUIDES/spec_leaf_spawn_and_global_leaf_list.md` — bud→twig спавнит 2 листа (`sub_415AB0`/`sub_4163B0`), и как работает очередь `dword_4D866C` / обслуживание `sub_40E0A0`.
- `GUIDES/spec_vtable_slot_44.md` — что означает `(*this + 44)(this)` по типам секций.
- `GUIDES/spec_detach_pipeline_sub_40EEE0.md` — отложенная обработка “помеченных” секций через `sub_40EEE0` и флаг `this+236`.
- `GUIDES/spec_geometry_sub_4093B0.md` — генерация вершин в GPU-буфер (`dword_4D7E70`) и связь с `sub_409910/sub_409130/sub_44F2A0`.
- `GUIDES/spec_render_submit_sub_44F2A0.md` — универсальный submit draw call (матрица/материал/буферы) и связи с геометрией дерева.
- `GUIDES/spec_ini_and_console_keys_inventory.md` — полный список INI `sub_406AE0` и перечень имён `sub_4032D0` для дерева/света.
- `GUIDES/spec_preset_sub_40D0B0_sub_4701D0.md` — пресет по умолчанию и маппинг 23 параметров.
- `GUIDES/spec_branching_dispatcher_sub_417F40.md` — диспетчер и три типа ветвления.
- `GUIDES/spec_ts_parity_verification.md` — RNG (`MSVCRand`), порядок кадра, сценарии регрессии.
- `GUIDES/spec_input_pruning_mouse.md` — полная цепочка ввода: WndProc → engine callbacks → пометка +236 → detach.

### Новые (batch 2)

- `GUIDES/spec_constructor_sub_413F50.md` — конструктор TreeSection + **полная карта полей this+0..+520**.
- `GUIDES/spec_twig_update_sub_417C90.md` — полный pipeline Twig update (girth, slerp, branch/grow, health, death).
- `GUIDES/spec_bud_to_twig_sub_415EF0_sub_415C10.md` — конверсия Bud→Twig + спавн листьев (заглушка в TS).
- `GUIDES/spec_transform_chain_sub_450BD0_sub_4146F0.md` — пропагация мировых матриц + построение локальных.
- `GUIDES/spec_perframe_physics_sub_4143E0.md` — покадровое сглаживание света +196..+232.
- `GUIDES/spec_leaf_light_tracing_sub_40E460.md` — ray-march освещения: sub_40E230 → sub_40E460 → sub_450E30/CD0.
- `GUIDES/spec_draw_procedures.md` — draw-процедуры Bud/Twig/Leaf/Soil (формулы масштаба/позиции).
- `GUIDES/spec_world_object_pipeline_sub_40F140.md` — анимация отсоединённых секций (gravity, wind, clamp, cleanup).
- `GUIDES/spec_type_tables_sub_40FAD0.md` — инициализация таблиц byte_4D8220/8225/8227 по типам.
- `GUIDES/spec_twig_length_growth_sub_418BD0.md` — **точная формула** pow-роста длины twig.

### Новые (batch 3)

- `GUIDES/spec_spring_wind_physics_sub_414A70_414BB0.md` — centroid, ветровой момент, resistance damping.
- `GUIDES/spec_material_curve_sub_4151B0.md` — кривая `(1-(1-x)^6)`, палитра 8 ключей, режимы окраски.

---

## 6) Чеклист закрытия порта (F1–F5)


| Пункт                         | Статус     | Документ / код                                                                                                         |
| ----------------------------- | ---------- | ---------------------------------------------------------------------------------------------------------------------- |
| F1 Полный список INI дерева   | ✅          | `spec_ini_and_console_keys_inventory.md` §1                                                                            |
| F2 Единая система ветвления   | ✅          | `spec_branching_dispatcher_sub_417F40.md`                                                                              |
| F3 Путь пресетов              | ✅          | `spec_preset_sub_40D0B0_sub_4701D0.md` (нет альтернативного `sub_40D0B0`)                                              |
| F4 MSVCRand + порядок вызовов | ✅          | `spec_ts_parity_verification.md`; `gobonsai-web/src/engine/MSVCRand.ts`                                                |
| F5 Регрессия / числовые якоря | 🟡 процесс | Эталоны в `gobonsai-web/src/engine/__fixtures__/parityReferenceFromExe.ts`; **IDA:** `spec_f5_ida_capture_workflow.md` |
| D2 Обрезка мышью (UX)         | ✅          | `spec_input_pruning_mouse.md` (полная цепочка)                                                                         |


