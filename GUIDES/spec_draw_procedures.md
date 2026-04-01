# Спека: draw-процедуры по типам секций

Файлы: `sub_416030.c` (61), `sub_418F10.c` (61), `sub_417070.c` (43), `sub_409130.c` (70), `sub_4151B0.c` (95).

Цель: зафиксировать точные формулы масштаба/позиции/материала для каждого типа секции при отрисовке.

---

## 1. Общий паттерн всех draw-процедур

```
1. Построить final_matrix = Scale × Rotate × Translate × worldMatrix(this+104)
2. Получить материал/цвет через sub_4151B0(this)
3. Отправить в рендер через sub_44F2A0(material, matrix, meshId, vb, stride, fvf, primCount, primType)
4. Рекурсивно вызвать vtable+20 на всех детях
```

---

## 2. `sub_416030` — Draw Bud (TreeSectionBud, type=6)

Два прохода (два полушария почки):

### Проход 1
```
offset_z = this+448 + this+444               // length + radius
T = D3DXMatrixTranslation(0, 0, offset_z)
S = D3DXMatrixScaling(this+444, this+444, this+444)     // uniform scale = radius
R = D3DXMatrixRotationYawPitchRoll(0, flt_4D6388, 0)   // pitch rotation
final = R × S × T × (this+104)

material = sub_4151B0(this)
sub_44F2A0(material, final, dword_4D8040, dword_4D7FA0, dword_4D7FA8, dword_4D7FA4, dword_4D7FB0, dword_4D7FB4)
```

### Проход 2
```
R2 = D3DXMatrixRotationYawPitchRoll(0, 0, flt_4D6388)  // roll rotation (different axis)
final2 = R_original × R2 × S × T × (this+104)

sub_44F2A0(material, final2, same mesh/VB params)
```

### Поля и константы
- `this+444` — radius (girth) почки
- `this+448` — accumulated length (offset вдоль Z)
- `flt_4D6388` — rotation angle (из .data)
- `dword_4D8040` — mesh/primitive ID для почки
- `dword_4D7FA0..FB4` — VB handle, stride, FVF, primCount, primType

---

## 3. `sub_418F10` — Draw Twig (TreeSectionTwig, type=10)

Один проход:

```
T = D3DXMatrixTranslation(0, 0, 1.0)
S = D3DXMatrixScaling(this+444, this+444, this+448 * 0.51)    // XY = radius, Z = half-length

// Custom base matrix (gradient/UV deformation)
M_base = [
    flt_4D6430, 0,          0, 0,
    0,          flt_4D6430, 0, 0,
    0,          0,          1, 0.03,
    0,          0,          0.03, 1
]

final = M_base × T × S × (this+104)

material = sub_4151B0(this)
sub_44F2A0(material, final, dword_4D8040, dword_4D7FB8, dword_4D7FC0, dword_4D7FBC, dword_4D7FC8, dword_4D7FCC)
```

### Поля и константы
- `this+444` — radius
- `this+448` — length (multiplied by 0.51 for half)
- `flt_4D6430` — scale factor for UV/gradient
- `dword_4D7FB8..FCC` — **другой** набор VB (не тот, что у bud/leaf)

### Ключевое отличие
Twig использует **кастомную базовую матрицу** с элементами `0.03` в позициях [2][3] и [3][2] — это создаёт лёгкий UV-сдвиг / скос для градиентной текстуры вдоль побега.

---

## 4. `sub_417070` — Draw Leaf (TreeSectionLeaf, type=7)

Один проход (упрощённый вариант `sub_416030`):

```
T = D3DXMatrixTranslation(0, 0, this+444)    // offset by radius
S = D3DXMatrixScaling(this+444, this+444, this+444)     // uniform = radius
R = D3DXMatrixRotationYawPitchRoll(0, flt_4D6388, 0)

final = R × S × T × (this+104)

material = sub_4151B0(this)
sub_44F2A0(material, final, dword_4D8040, dword_4D7FA0, dword_4D7FA8, dword_4D7FA4, dword_4D7FB0, dword_4D7FB4)
```

### Отличие от Bud
- Translate по Z = **только** `this+444` (без `+448`)
- **Один** проход (не два)
- Тот же набор VB что и у Bud

---

## 5. `sub_409130` — Draw Soil (грунт/почва)

Не относится к дереву — рисует подложку/землю. Два прохода с render states:

```
// D3D9 render states
SetRenderState(27, 0)     // D3DRS_ALPHABLENDENABLE = FALSE
SetRenderState(7, 1)      // D3DRS_DITHERENABLE = TRUE
SetRenderState(14, 1)     // D3DRS_ZWRITEENABLE = TRUE
SetRenderState(22, 3)     // D3DRS_SHADEMODE = GOURAUD
SetRenderState(143, 1)    // D3DRS_SRGBWRITEENABLE = TRUE

// Проход 1: основная земля
color = *(this+268)       // material color DWORD
sub_44F2A0(color, this+104, dword_4D8150, dword_4D7E58, ...)

// Проход 2: specular overlay
// lazy INI: "specularSoil" → flt_4D62B0
specular = flt_4D62B0
diffuse = flt_4D63B0      // BASE_GROWTH_MULTIPLIER = 0.5
sub_44F2A0({specular, specular, specular, 1.0}, this+104, dword_4D8194, dword_4D7E70, ...)

// Reset
SetRenderState(143, 0)    // SRGB off
```

---

## 6. `sub_4151B0` — Material/Color resolver

Используется во всех draw-процедурах для получения материала секции:

- Читает `dword_4D8644` (режим окраски)
- Применяет кривую `(1 - (1-x)^6)` к параметру (maturity/energy)
- Возвращает RGBA для diffuse/specular

Полный разбор в `sub_4151B0.c` (95 строк) — требуется для паритета цвета.

---

## 7. Сводная таблица draw-процедур

| Тип | Vtable slot +20 | Translate Z | Scale XY | Scale Z | Проходов | VB set |
|-----|-----------------|-------------|----------|---------|----------|--------|
| Bud (6) | `sub_416030` | +444 + +448 | +444 | +444 | 2 | `4D7FA0..` |
| Leaf (7) | `sub_417070` | +444 | +444 | +444 | 1 | `4D7FA0..` |
| Twig (10) | `sub_418F10` | 1.0 | +444 | +448 × 0.51 | 1 | `4D7FB8..` |
| Base (5) | через `sub_4093B0` + `sub_44F2A0` | — | — | — | — | dynamic VB |
| Soil | `sub_409130` | — | — | — | 2 | `4D7E58..` / `4D7E70..` |

---

## 8. Связь с TS

| C | TS | Статус |
|---|----|--------|
| `sub_416030` (Bud draw) | `GeometryService` / `TreeSection.update` | Частично: геометрия есть, но формулы масштаба не 1:1 |
| `sub_418F10` (Twig draw) | same | Кастомная матрица с 0.03 не реализована |
| `sub_417070` (Leaf draw) | `TreeLeaf` | Размер через Three.js, не через формулу |
| `sub_409130` (Soil) | `EnvironmentService` / `PotService` | Упрощённо |
| `sub_4151B0` (material) | `SectionColorService` + `Sub40FDE0` | ✅ `spec_material_curve_sub_4151B0.md` |

---

## 9. OPEN — ✅ ЗАКРЫТО

- ✅ `flt_4D6388 = 1.5707964` = **π/2** (90°). Используется в `D3DXMatrixRotationYawPitchRoll` для поворота геометрии Bud/Leaf. Подтверждено: `.data:004D6388 dd 1.5707964`.
- ✅ `flt_4D6430 = 0.97000003` ≈ **0.97**. Диагональный scale в кастомной базовой матрице Twig (создаёт лёгкое сжатие по XY для UV-градиента). Подтверждено: `.data:004D6430 dd 0.97000003`.
- ✅ `dword_4D8040` — **динамическая таблица mesh-ресурсов** (stride 17). Заполняется при создании D3D9 вершинных буферов, не статическая константа. В TS заменяется Three.js `BufferGeometry` объектами.
- ✅ `sub_4151B0` полный разбор кривой → **`spec_material_curve_sub_4151B0.md`**

---

Готовность к TS: **да** — все константы и формулы полностью известны.
