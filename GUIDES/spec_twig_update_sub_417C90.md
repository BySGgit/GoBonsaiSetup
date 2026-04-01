# Спека: полный Twig update `sub_417C90`

Файл: `decompiled/sub_417C90.c` (89 строк).

Цель: единый pipeline покадрового обновления секции типа `TreeSectionTwig` (vtable slot +36 для twig).

---

## 1. Сигнатура

```
void __thiscall sub_417C90(int this)
```

`this` — указатель на `TreeSectionTwig` (type id = 10).

---

## 2. Псевдокод (без шума)

```
// === Шаг 1: распределение энергии и rollup ===
sub_414E10(this)                              // energy distribution + aggregation
++this+484                                    // rollupDword484 (tick counter)

// === Шаг 2: прирост радиуса (girth) ===
v9 = (this+420) * flt_4D8618 / (this+444)    // production * radiusGrowRate / currentRadius
if v9 > 0.1:
    v9 = flt_4CA5E8                           // cap at aux rotation constant
this+444 += v9                                // twigRadius444 grows

// === Шаг 3: slerp ориентации ===
D3DXQuaternionSlerp(this+304, this+304, this+320, flt_4D8624)
D3DXQuaternionNormalize(this+304, this+304)

// === Шаг 4: ветка по флагу +512 (рост длины vs ветвление) ===
if this+512 (byte):                           // growth-active flag
    if this+172 == 0:                         // no children yet
        parent = this+180
        if parent:
            sub_450C80(this, parent)           // spatial update with parent
        (*this+8)(this)                        // vtable+8: markWorldManaged
    sub_418BD0(this)                           // length growth (see spec_twig_length_growth)
else:
    sub_417F40(this)                           // branching dispatcher (see spec_branching_dispatcher)

// === Шаг 5: lazy INI — healthEnergyAdjustment ===
// one-time: sub_4032D0(L"healthEnergyAdjustment", ...) → flt_4D6428

// === Шаг 6: healthEnergy456 smoothing ===
if this+432 >= flt_4D862C:                    // budget >= minBudEnergy
    this+456 += flt_4D6428                    // increase healthEnergy
else:
    this+456 -= flt_4D6428                    // decrease healthEnergy
clamp(this+456, 0.0, 1.0)

// === Шаг 7: death / detach conditions ===
if this+456 <= 0.0 AND *(this+180)+456 > 0.0:    // dead but parent alive
    v10 = this+444 * 4.0
    if rand()/32767 > v10:                         // probability inversely proportional to girth
        sub_40EEE0(this)                            // detach
    elif (this+440 > 2000 OR this+444 > 0.1) AND this+440 > 1000:
        if rand()/32767 < 0.01:                    // rare random death for old/thick sections
            sub_40EEE0(this)
```

---

## 3. Константы

| Адрес | Семантика | Default | Источник |
|-------|-----------|---------|----------|
| `flt_4D8618` | `radiusGrowRate` | из `sub_40D0B0` (a13) | INI/preset |
| `flt_4CA5E8` | aux rotation / girth cap | 0.1 | .rdata |
| `flt_4D8624` | twig slerp factor | из `sub_40D0B0` (a15) | INI/preset |
| `flt_4D862C` | `minBudEnergy` | 0.2 | preset |
| `flt_4D6428` | `healthEnergyAdjustment` | из INI | lazy init |

---

## 4. Ключевые наблюдения для TS

1. **Порядок операций**: `sub_414E10` → girth growth → slerp → length/branch → health → death. В TS нужно точно сохранить этот порядок.

2. **Двойная роль +512**: когда `byte(+512) = 1` (установлен в `sub_415C10` при конверсии bud→twig), секция **растёт в длину** (`sub_418BD0`). Когда `+512 = 0` (либо изначально, либо после достижения maxLength), секция **ветвится** (`sub_417F40`). Это критический переключатель.

3. **Прирост радиуса** происходит **всегда**, вне зависимости от +512. Формула: `production * radiusGrowRate / currentRadius` с cap.

4. **healthEnergy456** — это **не** health из TS `MetabolismService`. Это плавный индикатор 0→1, зависящий только от `this+432 >= minBudEnergy`. При падении до 0 при живом родителе → detach с вероятностью.

5. **Detach в `sub_417C90`**: два пути — (a) вероятность обратно пропорциональна girth (тонкие ветки умирают чаще), (b) для старых (>1000 ticks) толстых веток — 1% шанс.

---

## 5. Связь с TS

| C | TS модуль | Статус |
|---|-----------|--------|
| `sub_414E10` | `sub414E10.ts` | Портирован |
| `++this+484` | `rollupDword484` | Портирован в `aggregateEnergy420436PostOrder` |
| Girth growth | **НЕ ПОРТИРОВАН** | Нет в `GrowthFramePipeline` / `GrowthController` |
| Slerp | `Sub416510Rotation.ts` / `TransformService` | Частично |
| `sub_418BD0` | **Заглушка** | Линейная формула вместо pow — см. spec_twig_length_growth |
| `sub_417F40` | `BranchingService` | Переписана эвристиками, не 1:1 |
| healthEnergy456 | **НЕ ПОРТИРОВАН** | В TS есть `health` но это другая механика |
| Detach conditions | **НЕ ПОРТИРОВАН** | `sub_40EEE0` не вызывается |

---

## 6. OPEN

- `sub_450C80(this, parent)` — обновление spatial-структуры при detach без детей. Семантика: вероятно BVH/AABB update. Для Three.js — аналог `updateMatrixWorld`.
- `flt_4D6428` default из INI — снять значение.

---

Готовность к TS: **да** (все формулы и ветвления ясны).
