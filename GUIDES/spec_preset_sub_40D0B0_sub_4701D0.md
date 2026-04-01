# Пресет параметров дерева: `sub_40D0B0` и `sub_4701D0`

## `sub_40D0B0` — назначение 23 float в глобалы симуляции

Файл: `decompiled/sub_40D0B0.c`.

Порядок аргументов и целевые адреса:

| Параметр | Глобаль |
|----------|---------|
| `a1` | `*(float*)flt_4D85E8` — minSegmentSize |
| `a2` | `*(float*)flt_4D85EC` — maxSegmentSize |
| `a3` | `*(float*)flt_4D85F0` — minLeafSize |
| `a4` | `*(float*)flt_4D85F4` — maxLeafSize |
| `a5` | `*(float*)flt_4D85F8` — maxBudSize |
| `a6` | `*(float*)flt_4D85FC` — density |
| `a7` | `*(float*)flt_4D8600` — accelerationRadiusPow |
| `a8` | `*(float*)flt_4D8604` — resistanceRadiusPow |
| `a9` | `*(float*)flt_4D8608` — resistanceCoeff |
| `a10` | `*(float*)flt_4D860C` — leafWeight |
| `a11` | `*(float*)flt_4D8610` — lightAdjustBudStemCoeff |
| `a12` | `*(float*)flt_4D8614` — lengthGrowRate |
| `a13` | `*(float*)flt_4D8618` — radiusGrowRate |
| `a14` | `flt_4D861C` |
| `a15` | `flt_4D8620` |
| `a16` | `flt_4D8624` |
| `a17` | `*(float*)flt_4D8628` — energyAllowancePow |
| `a18` | `*(float*)flt_4D862C` — minBudEnergy |
| `a19` | `*(float*)flt_4D8630` — maxBudEnergy |
| `a20` | `*(float*)flt_4D8634` — leafEnergyProduction |
| `a21` | `*(float*)flt_4D8638` — apicalGrowthStrength |
| `a22` | `*(float*)flt_4D863C` — energyRebalancePercent |
| `a23` | `*(float*)flt_4D8640` — lengthGrowRatePow |

Возвращаемое значение: указатель `flt_4D85E8` (начало блока).

## `sub_4701D0` — единственный «вшитый» пресет

Файл: `decompiled/sub_4701D0.c`.

Вызывает `sub_40D0B0` с константами и **двумя** чтениями внешних float: `flt_4D62D8`, `flt_4D638C`, `flt_4D6358` (значения приходят из других глобалов/инициализации).

Литералы (как в C):

```
2.0, 5.0, 1.5, flt_4D62D8, 0.45, 40.0, -2.0, 1.0, 0.6, flt_4D638C,
0.0025, 0.08, 0.000015, 0.08, flt_4D638C, flt_4D6358,
1.2, 0.2, 2.0, 0.35, 0.4, 1.0, 2.0
```

## Альтернативные пресеты

По полному проходу `grep` по `decompiled/*.c`:

- **Других прямых вызовов `sub_40D0B0(` кроме тела `sub_4701D0` нет** (включая `full.c`).

Следствие: любые «альтернативные наборы» 23 параметров в бинарнике должны либо (1) писать те же глобалы **косвенно** (не найдено в явном виде), либо (2) совпадать с перезаписью через **INI** (`sub_406AE0`) после старта. Для паритета веб-порта: дефолт = результат `sub_4701D0`, затем применение ключей из `spec_ini_and_console_keys_inventory.md`.

## Связь с INI

Ключи `sub_406AE0` из §1 того инвентаря соответствуют **подмножеству** столбца «Параметр» выше (без `a14–a16`, если они не вынесены в отдельные имена — см. точные символы в IDA для `flt_4D861C`/`8620`/`8624`).
