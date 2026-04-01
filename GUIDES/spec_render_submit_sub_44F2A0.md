# Спека: `sub_44F2A0` — submit draw call в движок (матрица + материал + буферы)

Цель: зафиксировать, как оригинал отправляет рендер для “деревянных” и вспомогательных буферов (включая `dword_4D7E70` из `sub_4093B0`).

---

## 1) Сигнатура и параметры

Файл: `decompiled/sub_44F2A0.c`

```
sub_44F2A0(a1, a2, a3, a4, a5, a6, a7, a8) -> int
```

Наблюдаемое назначение аргументов:
- `a1` — `float*` (позиция/цвет? минимум `a1[0..3]` читаются)
- `a2` — `int` (матрица 4x4, передаётся в engine как world matrix)
- `a3` — `int` (ресурс/материал/техника; устанавливается через `(*v9 + 260)(..., a3)`)
- `a4` — `int` (vertex buffer handle / stream source; подаётся в `(*v9+400)(..., a4, ...)`)
- `a5` — `int` (primitiveCount; подаётся в `(*v9+324)(..., a5)`)
- `a6` — `int` (primitiveType; подаётся в `(*v9+324)(..., a6, ...)`)
- `a7` — `int` (strideBytes; подаётся в `(*v9+400)(..., a4, ..., a7)`)
- `a8` — `int` (FVF / vertex declaration; подаётся в `(*v9+356)(..., a8)`)

Уточнение (закрыто по callsite `sub_409130/sub_409910/sub_4093B0`):
- `a6 = 5` соответствует `D3DPT_TRIANGLESTRIP`.
- `a7 = 32` соответствует stride \(8 * float32 = 32 bytes\) (формат `pos3 + normal3 + uv2`).
- `a8 = 274 (0x112)` соответствует `D3DFVF_XYZ (0x2) | D3DFVF_NORMAL (0x10) | D3DFVF_TEX1 (0x100)`.
- `a5` в этом режиме = `vertexCount - 2`, что совпадает с тем, что `sub_4093B0` увеличивает счётчик по вершинам и в конце делает `count -= 2`.

---

## 2) Последовательность вызовов (факты)

Внутри:
- получает `v9 = EngineInstance[1]` (рендер девайс/контекст)
- `(*v9 + 176)(v9, 256, a2)` — установка матрицы/констант (похоже на world transform)
- `(*v9 + 260)(v9, 0, a3)` — установка материала/техники/шейдера
- строит массив `v13[17]` из `a1[0..3]` и глобалов `dword_4CA634/638/63C/640` и `flt_4CA644`
- `(*v9 + 196)(v9, v13)` — установка констант/параметров (цвет/свет/фактор)
- `(*v9 + 400)(v9, 0, a4, 0, a7)` — установка vertex stream / буфера
- `(*v9 + 356)(v9, a8)` — установка index buffer / декларации
- `(*v9 + 324)(v9, a6, 0, a5)` — финальный draw call (тип примитива + count)

---

## 3) Связи

- `sub_409130` вызывает `sub_44F2A0(..., dword_4D7E70, dword_4D7E78, dword_4D7E74, dword_4D7E80, dword_4D7E84)` — это основной путь рендера данных, записанных `sub_4093B0`.
- `sub_418F10` (twig draw) тоже вызывает `sub_44F2A0` для своих данных (см. `decompiled/sub_418F10.c`).

---

## 4) OPEN (для 100% паритета)

1. (Снято) Семантика `a1` восстановлена как `diffuseRGBA` / `baseColorRGBA` (см. ниже).
2. (Снято) `dword_4CA634/638/63C/640` = `specularRGBA`, `flt_4CA644` = INI `specularPower`.
3. (Снято) `a4..a8` расшифрованы для tree/leaf/twig буферов (stride/FVF/primType/primCount).

Найденные callsites (для дальнейшей расшифровки аргументов):
- `sub_409130`: `sub_44F2A0((float*)&v6, this+104, dword_4D8194, dword_4D7E70, dword_4D7E78, dword_4D7E74, dword_4D7E80, dword_4D7E84)`
- `sub_417070` (Leaf draw): `..., dword_4D7FA0, dword_4D7FA8, dword_4D7FA4, dword_4D7FB0, dword_4D7FB4`
- `sub_418F10` (Twig draw): `..., dword_4D7FB8, dword_4D7FC0, dword_4D7FBC, dword_4D7FC8, dword_4D7FCC`

Расшифровка аргументов по инициализациям буферов (закрыто по `sub_44FBA0`/`sub_44F970`):
- Для leaf/bud VB (`dword_4D7FA0`):
  - `a4 = dword_4D7FA0` (VB)
  - `a5 = dword_4D7FA8 = 4` (primitiveCount)
  - `a6 = dword_4D7FA4 = 5` (primitiveType = TRIANGLESTRIP)
  - `a7 = dword_4D7FB0 = 32` (stride bytes)
  - `a8 = dword_4D7FB4 = 274 (0x112)` (FVF = XYZ|NORMAL|TEX1)
- Для twig VB (`dword_4D7FB8`):
  - `a4 = dword_4D7FB8` (VB)
  - `a5 = dword_4D7FC0 = 16` (primitiveCount)
  - `a6 = dword_4D7FBC = 5` (primitiveType = TRIANGLESTRIP)
  - `a7 = dword_4D7FC8 = 32` (stride bytes)
  - `a8 = dword_4D7FCC = 274 (0x112)` (FVF = XYZ|NORMAL|TEX1)

Создание буферов (D3D9, для контекста):
- `sub_409910` создаёт `dword_4D7E70` через `IDirect3DDevice9::CreateVertexBuffer` с `usage=0x208 (DYNAMIC|WRITEONLY)`, `pool=DEFAULT`.
- `sub_44FBA0`/`sub_44F970` создают `dword_4D7FA0`/`dword_4D7FB8` с `usage=0x8 (WRITEONLY)` и `pool=1` (D3DPOOL_MANAGED).

Уточнение по параметрам `v13[17]` (частично закрыто по callsites):
- `dword_4CA634/638/63C/640` используются как 4 float, которые выставляются перед submit:
  - `sub_409130` выставляет их в `specularSoil` (`flt_4D62B0`) и `1.0`
  - `sub_40A8B0` выставляет их в `specularBark` (`flt_4D62B4`) и `specularLeaf` (`flt_4D62B8`)
  - `sub_44E830` временно выставляет RGB=0, A=1 для отрисовки world-объектов/дебага
- `flt_4CA644` конфигурируется как INI `specularPower` (см. `sub_471CF0`) и по умолчанию `20.0`.

Рабочая интерпретация:
- `dword_4CA634/638/63C/640` = `specularRGBA` (или аналогичный вектор параметров материала в шейдере).
- `flt_4CA644` = `specularPower` (экспонента блика).

Наблюдения по `a1` (частично закрыто):
- В большинстве callsites `a1` передаётся как указатель на 4 float, где первые 3 — вектор, а 4-й — скаляр:
  - `sub_409130`: `a1 = (float*)(this + 236)` (поле объекта сцены/контроллера)
  - `sub_44E830`: `a1 = (float*)(v3 + 12)` (world-object entry: позиция/параметр)
  - `sub_411000`: перед вызовом формирует `(0,0,0, 1 - fade)` и вызывает `sub_44F2A0`
  - `sub_416EC0`/`sub_419100`: прокидывают `a2` (внешний “цвет/параметр” от вызывающего) как `a1`
- `sub_44F2A0` кладёт `a1[0..3]` в `v13[0..3]`, затем дубль `a1[0..2]` в `v13[4..6]` и ставит `v13[7] = 1.0`.

Рабочая интерпретация (до закрытия):
- `a1.xyz` — базовый цвет (diffuse/base RGB),
- `a1.w` — прозрачность/затухание (alpha/fade).

Подтверждение по `sub_411000` (закрыто):
- перед одним из вызовов `sub_44F2A0` локально формируется `v22 = 0.0; v23 = 0.0; v24 = 0.0; v25 = 1.0 - v9[66];`
- и это передаётся как `a1 = (float*)&v22` в `sub_44F2A0(...)`.
- следовательно `a1.w` используется как **прозрачность/затухание (fade)** в submit-параметрах.

Подтверждение по структуре `v13[17]` (закрыто):
- `sub_44F2A0` формирует два vec4 подряд из `a1`:
  - `v13[0..3] = (a1.xyz, a1.w)`
  - `v13[4..7] = (a1.xyz, 1.0)`
- затем кладёт specular RGBA из `dword_4CA634/638/63C/640` в `v13[8..11]`,
- затем `v13[12..15] = 0`,
- и `v13[16] = specularPower (flt_4CA644)`.

Вывод:
- `a1` — это именно `diffuseRGBA` / `baseColorRGBA` для шейдера (а не позиция/направление).

---

Конец документа.

