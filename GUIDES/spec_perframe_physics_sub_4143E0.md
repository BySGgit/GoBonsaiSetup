# Спека: per-frame physics/smoothing `sub_4143E0` (vtable slot +12)

Файл: `decompiled/sub_4143E0.c` (73 строки).

Цель: задокументировать покадровое обновление сглаживания света/направления на каждой секции дерева.

---

## 1. Сигнатура

```
int __thiscall sub_4143E0(int this)
```

Vtable slot +12 для `TreeSection` (base). Вызывается рекурсивно по всему дереву.

---

## 2. Псевдокод

```
void sub_4143E0(this):
    // === Шаг 1: рекурсия по детям ===
    for each child in *(this+168):
        (*child+12)(child)                    // vtable +12 рекурсивно

    // === Шаг 2: sub_414870 ===
    sub_414870()                              // глобальный побочный эффект (контекст неизвестен)

    // === Шаг 3: опциональная обработка (lazy INI) ===
    // one-time init: sub_4032D0(14) → byte_4D6356, flt_4D6358
    if byte_4D6356 != 0                       // INI flag
       AND this+172 != 0                      // has children
       AND flt_4D6358 < this+460:             // threshold < field 460
        if this+180 != 0:                     // has parent
            sub_414A70(this)                  // unknown physics sub (wind? spring?)
        sub_414BB0()                          // unknown global sub

    // === Шаг 4: debug draw (optional) ===
    // one-time init: sub_4032D0(19) → byte_4D8DA5
    if byte_4D8DA5:
        // draw line from this+24 to this+24 + direction*10
        sub_44E5D0(this+24, this+24 + direction*10, 0.0)

    // === Шаг 5: сглаживание направления (КЛЮЧЕВОЕ) ===
    // dot product двух 3D-векторов: «текущий» и «целевой» свет
    v9 = dot(this+216..224, this+196..204)
    //  = (this+216)*(this+196) + (this+220)*(this+200) + (this+224)*(this+204)

    // преобразование dot в weight для интерполяции
    v10 = (v9 + 1.0) * 0.5                   // remap [-1,1] → [0,1]
    v11 = v10 * 0.1                           // scale factor = 10%

    // линейная интерполяция prevDirection → lightResponse
    v12 = 1.0 - v11                           // (1 - 0.1*normalized_dot)
    // sub_401500: vector scale
    // sub_4013F0: vector add
    this+216 = lerp(this+216, this+196, v11)  // prevDir.x = (1-t)*prevDir.x + t*lightResp.x
    this+220 = lerp(this+220, this+200, v11)
    this+224 = lerp(this+224, this+204, v11)
    normalize(this+216..224)                  // sub_40CF00: vector normalize

    // === Шаг 6: экспоненциальное сглаживание аккумуляторов ===
    this+228 += (this+208 - this+228) * 0.1   // smooth_targetA → smoothed_lightA
    this+232 += (this+212 - this+232) * 0.1   // smooth_targetB → smoothed_lightB
```

---

## 3. Семантика полей

| Offset | Имя | Роль | Обновляется в |
|--------|-----|------|---------------|
| +196..+204 | `lightResponseVec` | Направление «отклика на свет» | `sub_40E460` (ray tracing), `sub_413F50` (init) |
| +208 | `smoothedLightA` | Сглаженный скаляр: `(dot*intensity + old*10)/11` | `sub_40E460` |
| +212 | `smoothedLightB` | Сглаженный скаляр: `(intensity + old*20)/21` | `sub_40E460` |
| +216..+224 | `prevDirectionVec` | «Предыдущее» направление, сглаживается к +196..+204 | `sub_4143E0` |
| +228 | `smoothTargetA` | Медленная копия +208 (коэфф. 0.1) | `sub_4143E0` |
| +232 | `smoothTargetB` | Медленная копия +212 (коэфф. 0.1) | `sub_4143E0` |

### Интерпретация

Поля +196..+232 — это **двухуровневая система сглаживания света**:

1. **Быстрый уровень** (+196..+212): обновляется в `sub_40E460` при ray-трассировке (несколько раз за кадр, по мере обслуживания очереди листьев).
2. **Медленный уровень** (+216..+232): сглаживается в `sub_4143E0` (один раз за кадр) с коэффициентом 0.1 — даёт плавное «привыкание» секции к свету.

---

## 4. Связь с TS

| C | TS | Статус |
|---|----|--------|
| `sub_4143E0` (slot +12) | **НЕ ПОРТИРОВАН** | Сглаживание +216..+232 не реализовано |
| Поля +196..+232 | Отсутствуют в `TreeSection` | Нужно добавить 10 float полей |
| `sub_414A70` / `sub_414BB0` | — | ✅ См. `spec_spring_wind_physics_sub_414A70_414BB0.md` |
| `sub_414870` | — | ✅ См. `spec_spring_wind_physics_sub_414A70_414BB0.md` (centroid) |

### Для паритета

Без `sub_4143E0` в TS дерево **мгновенно** реагирует на изменения света, тогда как в оригинале есть плавное сглаживание с коэффициентом ~10%. Это влияет на визуальное «качание» веток в ответ на свет и на промежуточные значения, попадающие в метаболизм `sub_416510`.

---

## 5. OPEN — ✅ ЗАКРЫТО

Все три суб-функции полностью документированы в **`spec_spring_wind_physics_sub_414A70_414BB0.md`**:

| Функция | Назначение |
|---------|-----------|
| `sub_414870` | Вычисление центра масс (centroid `+468..+476`) и суммарного веса (`totalWeight460`) для поддерева |
| `sub_414A70` | Ветровой/гравитационный крутящий момент → slerp `targetQuat320` к «провисанию» |
| `sub_414BB0` | Resistance damping → slerp `targetQuat320` обратно к `currentQuat304` |

INI-параметры шага 3:

| Адрес | Имя | Default | Роль |
|-------|-----|---------|------|
| `byte_4D6356` | (lazy init #14) | `1` | Вкл/выкл physics |
| `flt_4D6358` | (lazy init #14) | `0.001` | Минимальный `totalWeight` |
| `flt_4D8600` | `accelerationRadiusPow` | (из INI) | `pow(radius, ...)` в sub_414A70 |
| `flt_4D8604` | `resistanceRadiusPow` | (из INI) | `pow(radius + bias, ...)` в sub_414BB0 |
| `flt_4D8608` | `resistanceCoeff` | (из INI) | Линейный множитель сопротивления |
| `flt_4D635C` | `resistanceRadiusBias` | (из INI) | Смещение радиуса перед pow |

---

Готовность к TS: **да** — все шаги (1–6) полностью документированы.
