# Спека: конверсия Bud → Twig (`sub_415EF0` + `sub_415C10`)

Файлы: `decompiled/sub_415EF0.c` (50 строк), `decompiled/sub_415C10.c` (108 строк).

Цель: полный pseudocode для реализации `budAfterSub414E10From415EF0` в `virtualSlot36.ts` — сейчас это **заглушка**.

---

## 1. `sub_415EF0` — виртуальный слот +36 для TreeSectionBud

Вызывается из цепочки `(*child+36)(child)` внутри `sub_414E10`.

```
void sub_415EF0(this):                        // this = TreeSectionBud
    sub_414E10(this)                          // base: distribute + aggregate

    if this+108 == 0.0:                       // baseGrowth == 0
        (*this+44)(this)                      // vtable +44: mark for detach (dead bud)
        return

    // нормализованная энергия почки
    v7 = clamp01((this+108 - flt_4D862C) / (flt_4D8630 - flt_4D862C))
    //   = clamp01((baseGrowth - minBudEnergy) / (maxBudEnergy - minBudEnergy))
    //   minBudEnergy = 0.2, maxBudEnergy = 2.0

    // проверка: есть ли «следующий» дочерний twig, и ещё ли он растёт
    v4 = sub_416300(*(this+45))               // first child filtered by byte_4D822A
    if v4 == 0 OR *(byte)(v4+512) == 0:      // no active twig child, or child stopped growing
        sub_415C10(this, v7)                  // convert bud → twig
```

### Константы

| Адрес | Имя | Default |
|-------|-----|---------|
| `flt_4D862C` | `minBudEnergy` | 0.2 |
| `flt_4D8630` | `maxBudEnergy` | 2.0 |

### `sub_416300(section)` — фильтр по типу

```
if section != 0 AND byte_4D822A[11 * *(section+4)] != 0:
    return section
else:
    return 0
```

---

## 2. `sub_415C10` — создание TreeSectionTwig из Bud

```
int sub_415C10(a1, a2):                       // a1 = bud, a2 = normalized energy [0..1]
    // === Ранний выход: контроль частоты ===
    v2 = *(a1 + 180)                          // parent
    if v2:
        v4 = byte_4D8225[11 * *(v2+4)] ? v2 : 0
    else:
        v4 = 0

    if v4 != 0:
        if *(byte)(dword_4D7EE8 + 220) != 0  // global flag
           AND *(a1 + 516) > 2                // leaf count > 2
           AND v4 != 0:
            (*(v4) + 44)(v4)                  // vtable +44 on parent: mark detach
            return 0                          // no twig created

    // === Создание TreeSectionTwig ===
    newTwig = operator new(0x220)

    v19[0] = rand()/32767.0 * 0.1 - 0.05     // small random yaw
    v19[1] = 0.0
    v19[2] = 0.0

    sub_417BB0(a1+240, ???, newTwig, a2, v19) // constructor TreeSectionTwig
    // inside sub_417BB0:
    //   sub_413F50(newTwig, ...) with yaw/pitch/roll from v19
    //   *(newTwig+4) = 10                    // type = Twig
    //   *(newTwig+452) = lerp(flt_4D85E8, flt_4D85EC, a2) * (rand()*0.2 + 0.9)
    //                  = lerp(minSegmentSize, maxSegmentSize, energy) * randomScale
    //   *(newTwig+428) = 1.0

    // === Post-construction setup ===
    *(float*)(newTwig + 444) = flt_4D861C     // initial girth (0.08)

    // Insert twig into bud's children list
    sub_40FD70(*(a1+168), ..., &newTwig)

    // Reset construction quaternion to identity
    *(newTwig+304..332):
        dword_4D53A4 = 0, dword_4D53A8 = 0, dword_4D53AC = 0, dword_4D53B0 = 1.0

    // Copy scalar fields from bud to twig
    *(newTwig+420) = *(a1+420)                // energyProduction
    *(newTwig+424) = *(a1+424)                // energyAccumulator
    *(newTwig+416) = *(a1+416)                // level
    *(newTwig+428) = 1.0                      // energyWeight

    // Activate growth
    *(byte)(newTwig + 512) = 1                // growth-active flag → sub_418BD0 will run

    // Scale factors
    *(float)(newTwig + 296) = 1.0
    *(float)(a1 + 296) = 1.0                  // reset parent scale too

    // === Spawn 2 leaves ===
    sub_415AB0(a1, a2)                        // creates 2 symmetric leaves
    return 1
```

---

## 3. `sub_415AB0` — спавн листьев при конверсии

```
void sub_415AB0(a1, a2):                      // a1 = bud, a2 = energy param
    // Rotate spawn angle
    *(a1+512) += (rand() * 0.2 / 32767 + 0.9) * π/2     // ~90° с рандомом
    normalize *(a1+512) to [0, 2π]

    angle = *(a1+512)

    // Direction vector from angle
    v6 = sub_4158D0(v6, 0, 1, angle)         // axis/direction from angle

    // Create leaf 1
    leaf1 = operator new(0x220)
    sub_4163B0(a1_twig_child, leaf1, a2, v6) // constructor TreeSectionLeaf

    // Create leaf 2 (opposite direction)
    sub_4163B0(a1_twig_child, leaf2, a2, -v6) // angle + π

    ++*(a1 + 516)                             // increment leaf counter
```

---

## 4. `sub_4163B0` — конструктор TreeSectionLeaf

```
void sub_4163B0(parentTwig, leafObj, a3, a4):
    // base constructor
    vftable = TreeSectionLeaf::vftable
    *(leafObj+4) = 7                          // type = Leaf
    *(leafObj+512..524) = 1.0                 // color multipliers = white

    // Max leaf size from energy parameter
    *(leafObj+452) = lerp(flt_4D85F0, flt_4D85F4, a3) * (rand()*0.2/32767 + 0.9)
    //             = lerp(minLeafSize, maxLeafSize, energy) * randomScale

    *(leafObj+428) = 0.0                      // energyWeight = 0 (leaf doesn't redistribute)

    // Insert into global leaf queue
    node = sub_40FD70(dword_4D866C, tail, &payload)
    ++dword_4D8670                            // global leaf count
```

---

## 5. Константы (сводная)

| Адрес | Имя | Default (из `sub_4701D0` → `sub_40D0B0`) |
|-------|-----|-------------------------------------------|
| `flt_4D862C` | minBudEnergy | 0.2 |
| `flt_4D8630` | maxBudEnergy | 2.0 |
| `flt_4D861C` | initialTwigGirth | 0.08 |
| `flt_4D85E8` | minSegmentSize | 2.0 |
| `flt_4D85EC` | maxSegmentSize | 5.0 |
| `flt_4D85F0` | minLeafSize | из preset |
| `flt_4D85F4` | maxLeafSize | из preset |

---

## 6. Связь с TS

| C | TS | Статус |
|---|----|--------|
| `sub_415EF0` | `budAfterSub414E10From415EF0` в `virtualSlot36.ts` | **Заглушка** — нужно реализовать |
| `sub_415C10` | — | **Не портирован** |
| `sub_415AB0` / `sub_4163B0` | `TreeLeaf` constructor | Частично (листья создаются, но без очереди `dword_4D866C`) |
| `sub_416300` filter | — | Нужно: `byte_4D822A[11*type]` проверка |
| `byte(+512) = 1` | — | Нужно: активация роста длины после конверсии |

---

## 7. OPEN

- `sub_4158D0(out, 0, 1, angle)` — построение direction vector от угла. Вероятно: `(sin(angle), 0, cos(angle))` или аналог. Проверить в `sub_4158D0.c`.
- `flt_4D85F0` / `flt_4D85F4` — точные дефолты из `sub_4701D0`.

---

Готовность к TS: **да** (заглушка заменяется полным кодом).
