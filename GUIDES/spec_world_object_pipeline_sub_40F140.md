# Спека: world-object pipeline `sub_40F140`

Файл: `decompiled/sub_40F140.c` (307 строк).

Цель: задокументировать жизненный цикл отсоединённых секций (ветки после `sub_40EEE0`) в мировом списке.

---

## 1. Контекст вызова

`sub_40F140` вызывается каждый кадр из главного game loop. `this` — указатель на мировой контекст (структура с полем `+51` = `+204` = список world-objects).

---

## 2. Два режима работы

### Режим A: `flt_4D526C == 150.0` (режим сброса)

```
for each node in list(this+204):
    payload = node[2]
    resolved = sub_451210(&out, &payload)     // resolve to section pointer
    if resolved != dword_4D8C10:              // not sentinel
        section = *(resolved + 12)
        if section:
            (*section+8)(section)             // vtable +8: markWorldManaged → cleanup
    remove node from list
    --*(this+208)                             // decrement world object count
```

Полная очистка: все world-objects удаляются, ресурсы освобождаются.

### Режим B: нормальный (анимация отсоединённых секций)

```
for each node in list(this+204):
    payload = node[2]
    resolved = sub_451210(&out, &payload)
    if resolved == dword_4D8C10 OR *(resolved+12) == 0:
        remove node from list
        continue

    section = *(resolved + 12)

    // --- Извлечь текущее состояние ---
    M = copy(section+40, 64 bytes)            // local matrix
    pos = sub_4015F0(M)                       // extract position from matrix
    velocity = { *(section+488), *(section+492), *(section+496) }
    angularVel = { *(section+500), *(section+504), *(section+508) }

    // --- Lazy init sub_40FAD0 (type tables) ---

    // --- Обновить velocity/position по типу ---
    isLeafType = byte_4D8227[11 * *(section+4)]

    if isLeafType:
        // LEAF: рандомный дрейф + гравитация
        velocity.y -= 0.025                   // gravity
        randomScale = rand()/32767 * 0.5 + 0.5
        velocity += dword_4D8A68 * 0.09 * randomScale   // wind push
        velocity += rand_noise * 0.12         // xyz noise [-0.12, +0.12]
        angularVel += rand_noise * 0.05       // rotation noise [-0.05, +0.05]
    else:
        // BRANCH: медленное падение + затухание
        velocity.y -= 0.1                     // stronger gravity
        velocity += dword_4D8A68 * 0.03       // wind (weaker)
        angularVel *= 0.98                    // damping

    // --- Записать обратно ---
    *(section+488..508) = velocity, angularVel

    // --- Ограничения (clamp) ---
    velocity.xyz = clamp(velocity.xyz, -5.0, +5.0)
    angularVel.xyz = clamp(angularVel.xyz, -0.2, +0.2)

    // --- Обновить позицию ---
    pos += velocity

    // --- Пересборка матрицы ---
    M[12] = pos.x
    M[13] = pos.y
    M[14] = pos.z

    // Rotation: translate to origin → rotate → translate back
    T = D3DXMatrixTranslation(pos)
    R = D3DXMatrixRotationYawPitchRoll(angularVel.x, angularVel.y, angularVel.z)
    T_inv = inverse(T)
    M_rot = T_inv × R × T
    M_final = M × M_rot

    // Записать и обновить
    qmemcpy(section+40, M_final, 64)         // local matrix
    (*section+12)(section)                    // vtable +12: per-frame physics
    (*section+16)(section)                    // vtable +16: updateWorldMatrix

    // --- Удаление при падении ниже -100 ---
    if pos.y < -100.0:
        remove node from list
        --*(this+208)
        (*section+8)(section)                 // vtable +8: cleanup/delete
```

---

## 3. Ключевые константы

| Значение | Назначение |
|----------|-----------|
| 150.0 (`flt_4D526C`) | Режим сброса: при установке = 150 все world-objects удаляются |
| -5.0..+5.0 | Clamp позиционной скорости |
| -0.2..+0.2 | Clamp угловой скорости |
| 0.025 | Gravity для листьев |
| 0.1 | Gravity для веток |
| 0.98 | Damping для угловой скорости веток |
| 0.12 | Амплитуда случайного шума позиции (листья) |
| 0.05 | Амплитуда случайного шума вращения (листья) |
| 0.09 | Scale ветра для листьев |
| 0.03 | Scale ветра для веток |
| -100.0 | Y threshold для удаления (объект «упал» за экран) |
| `dword_4D8A68` | Wind direction vector (global) |

---

## 4. Поля секции для world-objects

| Offset | Назначение |
|--------|-----------|
| +40 | local matrix (перезаписывается каждый кадр) |
| +488 | velocity X |
| +492 | velocity Y |
| +496 | velocity Z |
| +500 | angular velocity X (yaw rate) |
| +504 | angular velocity Y (pitch rate) |
| +508 | angular velocity Z (roll rate) |

---

## 5. Связь с `sub_40EEE0` (detach)

При отсоединении (`sub_40EEE0`) секция:
1. Копирует текущий трансформ (40 байт от `+26` → `+10` в клоне)
2. Вставляется в мировой список через `sub_40FD70`
3. `++*(world+208)` (счётчик world-objects)

После этого `sub_40F140` берёт управление: каждый кадр обновляет позицию/вращение, применяет гравитацию и ветер, и удаляет при падении ниже -100.

---

## 6. Связь с TS

| C | TS | Статус |
|---|----|--------|
| `sub_40F140` | **НЕ ПОРТИРОВАН** | World-object анимация не существует |
| World object list | — | Нет структуры для «отрезанных» секций |
| Gravity/wind на detached | — | Отсоединённые ветки просто исчезают в TS |
| `flt_4D526C = 150` reset | — | Нет механизма полной очистки |

### Для паритета

Без этой подсистемы отрезанные ветки **мгновенно исчезают** вместо того, чтобы красиво падать с вращением и ветром. Это чисто визуальный эффект, но заметный для UX.

---

## 7. OPEN

- `sub_451210` — resolver для payload→section pointer. Вероятно обёртка вокруг weak reference / handle.
- `dword_4D8A68` — wind vector. Проверить инициализацию (вероятно в `sub_408880`).
- `dword_4D8C10` — sentinel value для «пустого» узла.

---

Готовность к TS: **да** (анимация простая: gravity + wind + clamp + cleanup).
