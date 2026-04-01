# Инвентарь ключей: INI (`sub_406AE0`) и консоль (`sub_4032D0`)

Источник: `decompiled/sub_403C50.c` (инициализация), отдельные сабы с `sub_4032D0(L"…")`, `decompiled/full.c`.

## 1. Физика/дерево — только через `sub_406AE0` (полный список)

Все вызовы сосредоточены в одном блоке (`sub_403C50.c` ~744–865, дубликат в `full.c` ~5327–5447). Других ключей `sub_406AE0` в декомпиле **нет**.

| Ключ INI | Глобаль назначения (куда пишет `sub_406AE0`, третий аргумент) |
|----------|----------------------------------------------------------------|
| `gravity` | `flt_4D52F0` |
| `density` | `flt_4D85FC` |
| `leafWeight` | `flt_4D860C` |
| `accelerationRadiusPow` | `flt_4D8600` |
| `resistanceRadiusPow` | `flt_4D8604` |
| `resistanceCoeff` | `flt_4D8608` |
| `minSegmentSize` | `flt_4D85E8` |
| `maxSegmentSize` | `flt_4D85EC` |
| `minLeafSize` | `flt_4D85F0` |
| `maxLeafSize` | `flt_4D85F4` |
| `maxBudSize` | `flt_4D85F8` |
| `lengthGrowRate` | `flt_4D8614` |
| `lengthGrowRatePow` | `flt_4D8640` |
| `radiusGrowRate` | `flt_4D8618` |
| `minBudEnergy` | `flt_4D862C` |
| `maxBudEnergy` | `flt_4D8630` |
| `leafEnergyProduction` | `flt_4D8634` |
| `apicalGrowthStrength` | `flt_4D8638` |
| `energyRebalancePercent` | `flt_4D863C` |
| `energyAllowancePow` | `flt_4D8628` |
| `lightAdjustBudStemCoeff` | `flt_4D8610` |

**Итого: 21 ключ** для симуляции дерева/физики.

Дополнительные параметры, влияющие на рост/свет/рендер, регистрируются **не** через `sub_406AE0`, а через отдельные глобалы и `sub_4032D0` (см. §2).

## 2. Ключи `sub_4032D0` (регистрация имён для консоли/настроек)

Это **другой канал**: строковое имя + длина → таблица команд/переменных. Ниже — **имена, встречающиеся в коде дерева/света/роста** (не полный дамп всех строк UI).

### Рост и энергия

- `updateGrowth`, `randomAutoCuts`, `energyUseRate`, `energyLeak` — `sub_40DC90`
- `directLightPercent` — `sub_40E230`
- `lightDecayAmount` — `sub_40E460`
- `lightDirectStrength`, `lightAmbientStrength` — `sub_40EA30`
- `updateTreeVerts`, `updateVertInterval` — `sub_412700`
- `lightUpdatesPerDay` — `sub_4130D0`
- `specularEnable` — `sub_413350`
- `resistanceRadiusBias` — `sub_414BB0`
- `lightAmbientCoeff`, `lightAmbientMin` — `sub_415020`
- `healthEnergyAdjustment` — `sub_417C90`
- `randomBudRotation` — `sub_417FF0` (ленивая инициализация диапазона)

### Материалы / сцена

- `specularSoil` — `sub_409130`
- `specularBark` — `sub_40A8B0`

### Отладка / небо / облака / консоль (подсистема рендера)

Полный перечень имён см. в grep по `sub_4032D0(L"` в `decompiled/sub_46FD00.c` … `sub_471CF0.c` и блоке `full.c` ~70827–71733: `viewMode`, `enableStars`, `enableClouds`, `enableSun`, `cloudWindSpeed`, `puff*`, `sunDistance`, `consoleHeight`, `help`, `list`, `clear`, `specularPower`, и т.д.

## 3. Связь с пресетом

Дефолтные числа для блока `flt_4D85E8`…`flt_4D8640` задаются **`sub_4701D0` → `sub_40D0B0`** (см. `spec_preset_sub_40D0B0_sub_4701D0.md`). INI через `sub_406AE0` **перезаписывает** те же глобалы по именам из §1.

## Статус для паритета

- Список ключей `sub_406AE0`: **полный** (замкнут по репозиторию декомпила).
- Список `sub_4032D0`: для **дерева** перечислены критичные; для UI/рендера — при необходимости расширять тем же grep.
