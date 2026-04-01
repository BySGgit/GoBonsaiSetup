# Спека: трассировка света на листьях `sub_40E230` + `sub_40E460` + `sub_450E30`/`sub_450CD0`

Файлы: `sub_40E230.c` (79), `sub_40E460.c` (214), `sub_450E30.c` (22), `sub_450CD0.c` (52).

Цель: полная спецификация системы освещения листьев через ray-march по дереву.

---

## 1. Обзор pipeline

```
Каждый кадр:
  sub_40E0A0()                                // обслуживание очереди листьев
    ↓ (один leaf за тик)
  sub_40E230(leaf_data, world)                // построить луч, выбрать направление
    ↓
  sub_40E460(pos, world, dir, 1.0)            // ray-march: обновить +208/+212 секций, затухание
    ↓
  sub_450E30(root, hits, p0, p1, 30)          // собрать до 30 пересечений
    ↓
  sub_450CD0(section, p0, p1, delta, lenSq)   // рекурсивный обход AABB
```

---

## 2. `sub_40E230` — построение луча из leaf-данных

```
void sub_40E230(a1, a2):                      // a1 = float* (leaf payload), a2 = world context
    // Lazy INI: "directLightPercent" → flt_4D8CF0
    
    // Случайное направление
    pitch = rand()/32767 * π/2                // [0, π/2]
    yaw = rand()/32767 * 2π                   // [0, 2π]
    M_rot = D3DXMatrixRotationYawPitchRoll(yaw, pitch, 0)
    dir = D3DXVec3TransformNormal(flt_4D5398, M_rot)     // up vector rotated randomly

    // С вероятностью directLightPercent — заменить на прямой свет
    if flt_4D8CF0 > rand()/32767:
        dir = sub_408590(&flt_4D538C)         // global light direction (normalized)

    // Позиция: из payload
    pos.x = a1[2]
    pos.y = a1[3]
    pos.z = a1[4]
    
    // Смещение по некоторому вектору
    offset = sub_40D610() * a1[5]             // direction * scale
    pos += offset

    // Запустить трассировку
    sub_40E460(&pos, a2, &dir, 1.0)           // intensity = 1.0
```

### Константы

| Адрес | Имя | Default |
|-------|-----|---------|
| `flt_4D8CF0` | `directLightPercent` | из INI (типично 0.3–0.7) |
| `flt_4D5398` | up vector | (0,0,1) или (0,1,0) |
| `flt_4D538C..94` | light direction XYZ | global |

---

## 3. `sub_40E460` — ray-march с затуханием

```
void sub_40E460(pos, world, dir, intensity):
    // === Шаг 1: построить луч ===
    p0 = pos + dir * 200                      // far point forward
    p1 = pos - dir * 200                      // far point backward

    // === Шаг 2: собрать пересечения ===
    hitCount = sub_450E30(*(world+240), hits, p0, p1, 30)   // max 30 hits
    // hits sorted by hit[1] descending

    // === Шаг 3: обработка каждого hit ===
    for i = 0..hitCount-1:
        section = hits[i*3 + 0]               // pointer to TreeSection
        stepDist = hits[i*3 + 1]              // distance parameter
        closeDist = hits[i*3 + 2]             // closest distance

        // --- 3a: обновить light-response vector секции ---
        rate = (*(section+208) + 0.01) * 10.0
        newVec = dir * (intensity + 0.01) + *(section+196..204) * rate
        *(section+196..204) = normalize(newVec)

        // --- 3b: dot product ---
        dot = *(section+196..204) · dir
        x = clamp01(-dot)

        // --- 3c: обновить сглаженные аккумуляторы ---
        *(section+208) = (x * intensity + *(section+208) * 10.0) / 11.0
        *(section+212) = (intensity + *(section+212) * 20.0) / 21.0

        // --- 3d: lazy init sub_40FAD0 (type tables) ---

        // --- 3e: затухание intensity по типу секции ---
        isLeafType = byte_4D8227[11 * *(section+4)]    // flag #7
        isTwigType = byte_4D822A[11 * *(section+4)]    // flag #10

        if isLeafType:
            // LEAF DECAY: через lightDecayAmount
            leafDir = sub_40D6D0(section)     // normalized direction vector
            absDot = abs(leafDir · dir)
            // lazy INI: "lightDecayAmount" → flt_4D62EC (default 0.4)
            intensity = (1.0 - flt_4D62EC * absDot) * intensity

        elif isTwigType:
            // TWIG DECAY: геометрическое экранирование
            twigEnd = sub_40A310(section)     // twig endpoint
            twigEndScaled = twigEnd + dir * *(section+448)   // offset by length
            twigCenter = sub_40D6C0(section)  // center position
            twigFar = twigCenter + twigEndScaled
            twigNear = sub_40D6C0(section)

            radiusSq = *(section+444) ^ 2
            distSq = sub_44EE20(lineSegment(p0,p1), twigNear..twigFar)  // line-to-line distance²

            if radiusSq > distSq:
                intensity *= 0.5              // ray passes through twig → halve intensity

        // else: no decay for this section type

    // === Шаг 4: debug draw ===
    if byte_4D7E8D AND intensity > 0 AND hitCount > 0:
        sub_44E5D0(color=(intensity,intensity,intensity,0.3), ...)
```

---

## 4. `sub_450E30` — обёртка raycast

```
int sub_450E30(root, outHits, p0, p1, maxHits):
    if root == 0: root = dword_4D7EE4        // global scene root
    dword_4D82B4 = maxHits                    // limit
    dword_4D82B0 = outHits                    // output buffer
    dword_4D82B8 = 0                          // hit counter

    delta = p0 - p1                           // ray vector
    lenSq = dot(delta, delta)                 // squared length

    sub_450CD0(root, p0, p1, delta, lenSq)    // recursive collection
    
    dword_4D82AC += dword_4D82B8              // global hit counter
    sort(outHits, hitCount, by: hit[1] descending)   // sub_451320 + sub_450E10
    return dword_4D82B8
```

---

## 5. `sub_450CD0` — рекурсивный обход AABB

```
void sub_450CD0(section, p0, p1, delta, lenSq):
    if hitCount >= maxHits: return
    if *(section+20) == 0.0: return           // zero bounding size → skip

    boundRadius = *(section+20)
    boundRadiusSq = boundRadius * boundRadius

    // Быстрый тест: расстояние от луча до bounding sphere
    distToBound = sub_450860(delta, p0, section+8, p1, lenSq)
    if boundRadiusSq < distToBound: return    // miss bounding sphere

    // Точный тест: ближайшая точка на луче к section+24 (world pos)
    closeDist = sub_450970(t_out, delta, p0, section+24, p1, lenSq)
    innerRadius = *(section+36)
    innerRadiusSq = innerRadius * innerRadius

    if innerRadiusSq > closeDist:             // close enough → hit
        t = sqrt(lenSq) * t_out               // parameter along ray
        dist = sqrt(closeDist)

        // write hit to buffer
        hits[hitCount] = { section, t, dist }
        hitCount++

    // Recurse into children
    for each child in *(section+168):
        sub_450CD0(child, p0, p1, delta, lenSq)
```

### Формат hit (12 bytes)

| Offset | Type | Содержание |
|--------|------|-----------|
| +0 | int | `section` pointer |
| +4 | float | `t` — parameter along ray (scaled) |
| +8 | float | `dist` — closest distance to section center |

---

## 6. Вспомогательные функции

| Функция | Роль |
|---------|------|
| `sub_450860(delta, p0, bound_center, p1, lenSq)` | Distance² from ray to bounding sphere center |
| `sub_450970(t_out, delta, p0, point, p1, lenSq)` | Closest distance² from point to ray segment, with parameter `t` |
| `sub_40D6D0(section)` | Normalized direction of leaf (from fields) |
| `sub_40D6C0(section)` | Center position of section |
| `sub_40A310(section)` | Endpoint of twig (from matrix/length) |
| `sub_44EE20(line1, line2)` | Squared distance between two line segments |
| `sub_408590(lightDir)` | Normalize global light direction |

---

## 7. Связь с TS

| C | TS | Статус |
|---|----|--------|
| `sub_40E0A0` (queue service) | **НЕ ПОРТИРОВАН** | Очередь листьев не существует |
| `sub_40E230` | **НЕ ПОРТИРОВАН** | Нет ray-based освещения |
| `sub_40E460` | **НЕ ПОРТИРОВАН** | Нет ray-march с затуханием |
| `sub_450E30/450CD0` | **НЕ ПОРТИРОВАН** | Нет AABB raycast по дереву |
| Поля +196..+212 | Отсутствуют | Нужно добавить в TreeSection |
| `byte_4D8227`, `byte_4D822A` | Нули в `GrowthConstants` | Нужно заполнить (см. spec_type_tables) |

### Для паритета

Это **критическая** подсистема: без неё свет на секциях вычисляется как простой dot product в `MetabolismService`, а в оригинале — через полноценную ray-трассировку с затуханием через листья и тени от веток. Это фундаментально меняет распределение энергии по дереву.

---

## 8. OPEN

- `sub_40D610()` в `sub_40E230` — вектор смещения для позиции. Нужно проверить в `sub_40D610.c`.
- `flt_4D8CF0` default для `directLightPercent` — снять из `.data` или установить 0.5 как APPROX.
- `flt_4D62EC` default для `lightDecayAmount` — из `.data`: 0.4.
- `sub_414870()` — вызывается в `sub_4143E0` перед physics; может быть связана с очередью листьев.

---

Готовность к TS: **да** (полный pseudocode для всей цепочки).
