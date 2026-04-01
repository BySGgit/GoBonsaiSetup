# Спека: рост длины twig `sub_418BD0`

Файл: `decompiled/sub_418BD0.c` (49 строк).

Цель: зафиксировать **точную формулу** прироста длины побега (`this+448`), которая в TS заменена линейной аппроксимацией.

---

## 1. Сигнатура

```
void __stdcall sub_418BD0(int a1)
```

`a1` — указатель на `TreeSectionTwig`. Вызывается из `sub_417C90` при `byte(a1+512) == 1`.

---

## 2. Псевдокод

```
void sub_418BD0(a1):
    // === Шаг 1: slerp ориентации к «естественному» направлению ===
    // Вычислить ось и угол от текущего direction к глобальному «вверх»
    v_local = D3DXVec3TransformNormal(*(a1+196), *(a1+352))    // light-response в локальных коорд.
    cross = cross(flt_4D5398, v_local)                          // cross(up, localDir)
    axis = normalize(cross)
    angle = acos(dot(flt_4D5398, normalize(v_local)))           // угол между up и localDir

    quat_target = D3DXQuaternionRotationAxis(axis, angle)
    D3DXQuaternionSlerp(a1+304, a1+304, quat_target, flt_4D8610)
    //                  current   current  target      twigOrientSlerp

    // === Шаг 2: записать стоимость в +436 ===
    budget = *(a1+432)                        // energyBudget432
    cap = flt_4D8630                          // maxBudEnergy (2.0)
    *(a1+436) = min(cap, budget)              // energySpent436 = min(2.0, budget)

    // === Шаг 3: нормализация энергии ===
    v6 = (*(a1+436) - flt_4D862C) / (flt_4D8630 - flt_4D862C)
    //  = (spent - minBudEnergy) / (maxBudEnergy - minBudEnergy)
    //  = (spent - 0.2) / (2.0 - 0.2)
    v6 = clamp(v6, 0.0, 1.0)

    // === Шаг 4: pow + прирост длины ===
    v7 = pow(v6, flt_4D8640)                  // pow(normalized, lengthGrowRatePow)
    //   lengthGrowRatePow = 2.0 (default)
    v8 = v7 * flt_4D8614                      // * lengthGrowRate (0.08)
    *(a1+448) += v8                           // twigLength448 += increment

    // === Шаг 5: cap длины ===
    if *(a1+448) >= *(a1+452):                // если длина >= maxSegmentSize
        *(a1+448) = *(a1+452)                 // clamp
        *(byte)(a1+512) = 0                   // STOP growing → next frame will call sub_417F40
```

---

## 3. Формула (одна строка)

```
twigLength448 += pow(
    clamp01((min(maxBudEnergy, energyBudget432) - minBudEnergy) / (maxBudEnergy - minBudEnergy)),
    lengthGrowRatePow
) * lengthGrowRate
```

При достижении `maxSegmentSize` (`this+452`) длина фиксируется и `byte(+512)` сбрасывается → секция переходит к ветвлению.

---

## 4. Константы

| Адрес | Имя | Default (из `sub_4701D0`) | INI ключ |
|-------|-----|---------------------------|----------|
| `flt_4D862C` | `minBudEnergy` | 0.2 | — |
| `flt_4D8630` | `maxBudEnergy` | 2.0 | — |
| `flt_4D8614` | `lengthGrowRate` | 0.08 | `lengthGrowRate` |
| `flt_4D8640` | `lengthGrowRatePow` | 2.0 | — |
| `flt_4D8610` | `twigOrientSlerp` | из preset | — |
| `flt_4D5398` | up vector | global | — |

---

## 5. Шаг 1: ориентация (подробности)

Этот шаг направляет растущий побег к свету через slerp:

1. `v_local` = `light-response vector (+196)` трансформированный в **локальное** пространство секции через inverse матрицу `(+352)`
2. `cross(up, v_local)` даёт ось вращения
3. `acos(dot(up, normalize(v_local)))` даёт угол
4. Создаётся кватернион вращения на этот угол вокруг оси
5. Текущий кватернион `+304` slerp'ится к нему с коэффициентом `flt_4D8610`

Результат: побег **плавно поворачивается** к свету.

### Вспомогательные функции

| Функция | Роль |
|---------|------|
| `sub_401540(vec, mat)` | `D3DXVec3TransformNormal` |
| `sub_401180(a, b, out)` | `cross(a, b)` |
| `sub_408470(vec)` | `normalize(vec)` |
| `sub_4010C0(a, b)` | `acos(dot(a, b))` |

---

## 6. Сравнение с текущим TS

### В C (оригинал)

```
increment = pow(clamp01((E-0.2)/1.8), 2.0) * 0.08
twigLength += increment
if twigLength >= maxSegmentSize: stop
```

Характер: **квадратичный** рост при малой энергии, **линейный** при максимальной. Порог 0.2 означает, что при энергии < 0.2 рост нулевой.

### В TS (текущий)

```
growthProgress = growthRate / maxGrowth
currentHeightScale = growthProgress * HEIGHT_FACTOR
```

Характер: **линейный** от 0 до maxGrowth. Нет pow, нет порога, нет связи с `energyBudget432`.

### Визуальная разница

В C рост начинается медленно (квадратичная кривая), ускоряется при накоплении энергии, и резко останавливается при `maxSegmentSize`. В TS рост линейный и равномерный — дерево выглядит более «механическим».

---

## 7. Связь с TS

| C | TS | Статус |
|---|----|--------|
| `sub_418BD0` | `GrowthController.updateSectionGrowth` | **Неверная формула** (линейная vs pow) |
| `this+448 += pow(...)` | `growthRate += ...` | Нужно заменить на формулу с `energyBudget432` |
| `this+452` (max) | `maxGrowth` | Маппинг корректный |
| `byte(+512) = 0` при cap | — | Нет переключения growth→branch |
| Slerp к свету | `Sub416510Rotation` | Частично (без inverse +352 transform) |
| `this+436 = min(cap, budget)` | `energySpent436` | Нужно добавить |

---

## 8. Рекомендация для TS

```typescript
function twigLengthGrowth(section: TreeSection, constants: GrowthConstants): void {
    const budget = section.energyBudget432;
    const cap = constants.FLT_4D8630_MAX_BUD_ENERGY;       // 2.0
    const minE = constants.FLT_4D862C_MIN_BUD_ENERGY;      // 0.2
    const rate = constants.FLT_4D8614_LENGTH_GROW_RATE;     // 0.08
    const pow_ = constants.FLT_4D8640_LENGTH_GROW_RATE_POW; // 2.0

    section.energySpent436 = Math.min(cap, budget);

    let v6 = (section.energySpent436 - minE) / (cap - minE);
    v6 = Math.max(0, Math.min(1, v6));

    const increment = Math.pow(v6, pow_) * rate;
    section.twigLength448 += increment;

    if (section.twigLength448 >= section.maxSegmentSize452) {
        section.twigLength448 = section.maxSegmentSize452;
        section.growthActiveFlag512 = false;  // switch to branching
    }
}
```

---

Готовность к TS: **да** (формула полностью ясна, рекомендация включена).
