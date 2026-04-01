# Спека: трансформ-цепочка `sub_450BD0` (slot +16) + `sub_4146F0` (slot +32)

Файлы: `decompiled/sub_450BD0.c` (47 строк), `decompiled/sub_4146F0.c` (51 строка).

Цель: зафиксировать, как мировые матрицы пропагируются по дереву секций и как строится локальная матрица + инверс.

---

## 1. `sub_450BD0` — vtable slot +16: updateWorldMatrix + propagate

```
void sub_450BD0(this):
    // Шаг 1: пересчитать локальную матрицу
    (*this+32)(this)                          // vtable +32 = sub_4146F0 (rebuildLocalMatrices)

    // Шаг 2: мировая матрица
    parent = *(this+45*4)                     // this+180 / 4 = parent (pointer at float index 45)
    if parent != 0:
        worldMatrix = this+40 * (parent+104)  // local * parent_world
        // D3DXMatrixMultiply(temp, this+40, parent+104)
    else:
        worldMatrix = this+40                 // root: local = world

    // Шаг 3: копирование позиции из матрицы
    this+20 = this+36                         // float *(this+5) = *(this+9): bounding position.y = local.y?
    this+8  = *(this+24)                      // bound pos from matrix column
    this+12 = *(this+28)
    this+16 = *(this+32)

    // Шаг 4: записать мировую матрицу
    qmemcpy(this+104, worldMatrix, 0x40)      // 64 bytes → this+104

    // Шаг 5: пропагация на детей
    list = *(this+168)                        // children list sentinel
    for each child in list:
        (*child+16)(child)                    // рекурсивный вызов sub_450BD0
        sub_450A80(child+8, this+8)           // обновить spatial-структуру ребёнка относительно this
```

### Ключевые поля

| Offset | Роль в трансформе |
|--------|-------------------|
| +8..+20 | Bounding position (для spatial tree / raycast) |
| +36 | Bounding radius |
| +40 | Local matrix (64 bytes) |
| +104 | World matrix (64 bytes) = local × parent_world |
| +180 | Parent pointer |

---

## 2. `sub_4146F0` — vtable slot +32: rebuildLocalMatrices + position

Вызывается из `sub_450BD0` как первый шаг.

```
void sub_4146F0(this):
    parent = *(this+180)
    if parent == 0: return                    // root: nothing to rebuild

    // === Шаг 1: scale factor ===
    savedScale = *(this+296)
    *(this+296) = *(parent+448) * savedScale  // parent.twigLength * this.scale

    // === Шаг 2: quaternion → local matrix ===
    M_rot = D3DXMatrixRotationQuaternion(this+320)       // target quaternion → rotation matrix
    M_local = M_rot × *(this+240)                        // rotation × base template
    qmemcpy(this+40, M_local, 0x40)                      // → this+40 (local matrix)

    // === Шаг 3: inverse matrix ===
    if parent != 0:
        M_combined = *(this+240) × *(parent+104)         // template × parent_world
        M_inv = D3DXMatrixInverse(M_combined)
    else:
        M_inv = D3DXMatrixInverse(*(this+240))
    qmemcpy(this+352, M_inv, 0x40)                       // → this+352 (inverse)

    // === Шаг 4: restore scale ===
    *(this+296) = savedScale                  // undo temp modification

    // === Шаг 5: compute world position of section endpoint ===
    // direction = flt_4D5398 (global up vector)
    // offset along direction by this+448 (twig length)
    v4 = sub_401470(direction, &flt_4D5398, *(this+448)) // direction * length
    v5 = sub_401470(v4, flt_4D63B0)                      // * BASE_GROWTH_MULTIPLIER (0.5)
    pos_local = sub_401540(v5, this+104)                  // transform by world matrix
    pos_offset = sub_4015F0(this+104)                     // extract position from matrix
    pos_world = sub_4013F0(pos_local, pos_offset)         // local + matrix_pos

    *(this+24) = pos_world.x
    *(this+28) = pos_world.y
    *(this+32) = pos_world.z
```

### Ключевые детали

1. **Кватернион +320 → матрица**: строит вращение из target quaternion, умножает на шаблон +240. Это даёт локальную ориентацию ветки.

2. **Инверс +352**: `inverse(template × parentWorld)` — используется в `sub_416510` для перевода света в локальное пространство секции.

3. **Позиция +24..+32**: конец секции в мировых координатах — `direction * length * 0.5`, трансформированный в мир. Используется для raycast, bounding.

4. **Scale +296**: временно масштабируется на `parent.twigLength448`, потом восстанавливается. Это даёт масштабирование дочерних секций по длине родителя.

---

## 3. Связь функций и вспомогательные вызовы

| Функция | Роль |
|---------|------|
| `sub_401470(out, vec, scalar)` | `out = vec * scalar` (vector scale) |
| `sub_401540(vec, mat)` | `out = vec transformed by mat` (D3DXVec3TransformNormal) |
| `sub_4015F0(mat)` | extract position column from 4×4 matrix |
| `sub_4013F0(a, b)` | `out = a + b` (vector add) |
| `sub_450A80(childBound, parentBound)` | update spatial tree node |
| `flt_4D5398` | global «up» direction vector (often (0,0,1) or (0,1,0)) |
| `flt_4D63B0` | BASE_GROWTH_MULTIPLIER = 0.5 |

---

## 4. Связь с TS

| C | TS | Примечание |
|---|----|------------|
| `sub_450BD0` (slot +16) | `root.group.updateMatrixWorld(true)` | Three.js рекурсивно обновляет world matrices; но **sub_450A80** (spatial) не имеет аналога |
| `sub_4146F0` (slot +32) | **НЕ ПОРТИРОВАН** | Three.js не использует +240 template × quat +320; вместо этого — Euler/quaternion напрямую на Object3D |
| Inverse +352 | `MetabolismService`: `_inv.copy(matrixWorld).invert()` | Функционально эквивалентно, но через Three.js API |
| Position +24..+32 | — | Не используется в TS (raycast через Three.js Raycaster) |

### Важно для паритета

Порядок умножения матриц: `M_rot × template`, потом `local × parentWorld`. В Three.js порядок может отличаться (Object3D.matrix vs matrixWorld). Нужно убедиться, что template (+240) учитывается как «базовая ориентация» ветки, заданная при конструировании.

---

## 5. OPEN

- `flt_4D5398` — точное значение «up» вектора. По контексту `sub_4146F0` и `sub_418BD0` это (0, 0, 1) или (0, 1, 0) — проверить в `.data`.
- `sub_450A80` — обновление spatial tree. Для Three.js может быть заменено на `computeBoundingSphere` / `computeBoundingBox`, но семантика может отличаться.

---

Готовность к TS: **да** (с учётом различий Three.js API).
