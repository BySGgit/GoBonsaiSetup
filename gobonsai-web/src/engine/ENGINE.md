# Движок `gobonsai-web/src/engine` — карта файлов

Цель: **с первого взгляда** видеть, какой модуль за что отвечает и к каким сабам C / спекам он относится. Порядок разделов — от точки входа книз по слоям.

---

## Точка входа кадра

| Файл | Роль |
|------|------|
| `BonsaiController.ts` | Оркестратор: `updateClock`, `syncEnergyFromStats`, **`GrowthFramePipeline.run`** (+216 и год внутри пайплайна). |
| `growth/GrowthFramePipeline.ts` | `run()`: animate → матрицы → randomAutoCuts → **+216 / год / sub_414CE0** → сезон → **`sub414E10`** → метаболизм → рост → rollup → визуал. |
| `world/WorldGrowthState.ts` | `dword_4D7EE8`: `energyPool` (+196), `simulationDay` (+216, +1 за кадр как в sub_40DC90), `seasonFactor()` = sub_40EE60(+216). |
| `world/seasonCurveSub40EE60.ts` | Чистая функция сезона — **`sub_40EE60`**, таблица в `GrowthConstants.FLT_4B786C_MONTH`. |
| `components/BonsaiViewer.vue` (вне `engine`) | Three.js: сцена, камера, создаёт `BonsaiController`, передаёт свет/настройки. |

**Связь с оригиналом:** бюджет `+432`, распределение по детям и rollup `+420/+436` частично перенесены (`sub40DC90PoolBalance.ts`, **`growth/sub414E10.ts`**). Полный виртуальный слот `+36` по типам секций — в работе. Спека: `GUIDES/spec_update_growth_sub_40DC90.md`.

---

## Подсистемы (крупными блоками)

```
 BonsaiController.update()
        │
        updateClock ──► syncEnergyFromStats → GrowthFramePipeline (+216/год внутри) → syncEnergyFromStats
        │
        ▼
 GrowthFramePipeline.run()
        │
        ├─► animateGrowth (sub_408D60) → updateMatrixWorld
        ├─► maybeRandomAutoCuts (§2.2) → +216 / год / sub_414CE0 / onYear
        ├─► seasonFactor (sub_40EE60) → reset, +428, +432, distribute
        ├─► MetabolismService → updateSectionGrowth → +444/+448 sync
        ├─► rollup sub_414E10 (+420/+436/хвост), applyGlobalEnergyPool
        ├─► tickEnvironment → TreeSection.update + TreeRoot
        └─► syncTransformMatricesFromWorld

 worldGrowth.seasonFactor()  ←  sub_40EE60 → writeRootEnergyBudget432
```

---

## Корневые файлы (`engine/`)

| Файл | Ответственность | Ориентир C / GUIDES |
|------|-----------------|---------------------|
| `BonsaiController.ts` | Часы, `worldGrowth`, делегирование кадра в `GrowthFramePipeline`; обрезка, полив, сохранение. | `sub_40DC90` (агрегат — в работе) |
| `TreeSection.ts` | Узел дерева: дети, меши, поля смещений C (`+76`…`+114`), **`+420/+432/+436`** (энергетика кадра), кватернионы, рекурсивный `update`, геометрия веток. | `TreeSection*`, `sub_416510`, `sub_4093B0`, vtable +36/+16… |
| `TreeRoot.ts` | Визуальные корни в горшке (отдельное дерево мешей, не `TreeSection`). | APPROX: корни в оригинале — отдельная логика |
| `TreeLeaf.ts` | Лист: меш, параметры. | Leaf-спеки |
| `TreeFlower.ts` | Цветок (если используется). | По мере порта |
| `GrowthController.ts` | Обёртка: стартовые статы (`initStats`), годовые цели, `animateGrowth`, делегирование в `GrowthService` / `BranchingService` / рост секций / метаболизм. | `sub_408880`, `sub_408D60`, части роста |
| `GrowthService.ts` | Интерполяция возраста/толщины/изгиба/цвета (анимация целей). | `sub_408D60.c` |
| `BranchingService.ts` | Боковое ветвление по энергии/нормам роста. | `sub_4188E0` |
| `MetabolismService.ts` | Свет → энергия по ветке, здоровье, флаги пропуска роста. | `sub_416510` (свет, ветка) |
| `SectionColorService.ts` | Цвет сегмента через таблицу ключей. | `sub_40FDE0`, фрагменты `sub_416510` |
| `GeometryService.ts` | Цилиндр сегмента, UV, вспомогательные меши. | `sub_4093B0` |
| `TreeConstants.ts` | Общие числовые константы дерева (сегменты, уровни и т.д.). | Сводка из декомпила / настройка |
| `TreeState.ts` | Интерфейсы состояния ствола/ветки для UI и типов. | Не саб, удобство TS |
| `TreeInterfaces.ts` | Соответствие полей структуры секции смещениям C (`ITreeSectionData` и др.). | Карта полей |
| `MSVCRand.ts` | ГПСЧ как MSVC `rand()`. | MSVCRT |
| `BonsaiAudio.ts` | Звук (вода/срез и т.д.). | Не симуляция дерева |
| `PotService.ts` | Геометрия горшка/поддона. | Визуал |
| `EnvironmentService.ts` | Земля, трава, окружение. | Визуал; куски в духе `sub_4093B0` для почвы |

---

## Конфигурация и константы

| Файл | Ответственность |
|------|-----------------|
| `config/GrowthConstants.ts` | Пороги роста, `FLT_*`, **`FLT_4B786C_MONTH`**, `ENERGY_USE_RATE` / `ENERGY_LEAK` / `FLT_4D7EF4`; **`BYTE_4D62DC_UPDATE_GROWTH`** — при `false` весь `GrowthFramePipeline.run` пропускается (как `if (byte_4D62DC)` в `sub_40DC90`). |
| `v2/BonsaiConfig.ts` | Конфиг альтернативного/упрощённого дерева (v2). |
| `__fixtures__/parityReferenceFromExe.ts` | Эталонные числа с оригинального exe (IDA), без автотеста до готовности порта. |

---

## Состояние мира и кадр роста (`engine/world/`, `engine/growth/`)

| Файл | Ответственность | Ориентир C |
|------|-----------------|------------|
| `world/WorldGrowthState.ts` | Пул энергии и день симуляции; `seasonFactor()`. | `dword_4D7EE8` +196 / +216 |
| `world/seasonCurveSub40EE60.ts` | Сезонный множитель. | `sub_40EE60` |
| `growth/GrowthFramePipeline.ts` | Сборка одного кадра дерева (`run`); при выключенном `updateGrowth` — пустой кадр. | `sub_40DC90` + обход секций |
| `growth/sub40DC90PoolBalance.ts` | Запись `root+432`, сброс агрегатов по дереву, баланс `E` и `energyLeak`. | `sub_40DC90` §2.4–2.6 (частично) |
| `growth/sub40DC90RandomAutoCuts.ts` | §2.2 `randomAutoCuts` (INI, rand() меньше 0.01); список `dword_4D8C10` — заглушка. | `sub_40DC90` §2.2 |
| `growth/sub414E10.ts` | Веса `+428`, `child+432`, rollup `+420/+436/+480/+484`, хвост `+424/+440`, `this+36` от `+444/+448`. | `sub_414E10` |
| `growth/sub414CE0.ts` | Годовый virtual `+40`: обнуление накопителя `+424` по дереву; `root.sub414CE0SeedBudget428` (=1) после тика. | `sub_414CE0` (частично) |

---

## Математика (`engine/math/`)

| Файл | Ответственность | Ориентир C |
|------|-----------------|------------|
| `MathTypes.ts` | Алиасы типов (Float32, D3DX*). | D3DX |
| `TransformService.ts` | Матрицы, yaw/pitch/roll, вспомогательные преобразования. | `sub_401540`, `D3DX*` |
| `Sub40FDE0.ts` | Интерполяция RGBA по ключам. | `sub_40FDE0` |
| `Sub416510Rotation.ts` | Кватернионный блок / prevData / «blob80» для согласования с `sub_416510`. | `sub_416510` |

---

## Ветка `v2/` (отдельный путь данных)

| Файл | Ответственность |
|------|-----------------|
| `v2/BonsaiNode.ts` | Узел упрощённого дерева. |
| `v2/BonsaiTree.ts` | Сборка дерева v2. |
| `v2/BonsaiMeshBuilder.ts` | Меши для v2. |
| `v2/BonsaiConfig.ts` | Настройки v2. |
| `v2/index.ts` | Реэкспорт v2. |

Используется, если в UI включён сценарий v2; **основной путь паритета** — `TreeSection` + `BonsaiController`.

---

## Как читать код дальше

1. **Порядок кадра** — `BonsaiController.update()` → `GrowthFramePipeline.run()` (пошагово в коде).  
2. **Поле секции** — `TreeInterfaces.ts` + комментарии в `TreeSection.ts`.  
3. **Конкретный саб** — grep по `sub_XXXXXX` в `engine/` и сверка с `GUIDES/spec_*.md`.  
4. **Глобальная матрица покрытия** — `GUIDES/c_truth_coverage_matrix.md`.

---

## История изменений карты

При добавлении файла — **одна строка** в соответствующую таблицу выше (не расползать дублями по README).
