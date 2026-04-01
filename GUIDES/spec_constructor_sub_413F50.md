# Спека: конструктор `sub_413F50` и полная карта полей `TreeSection`

Файл: `decompiled/sub_413F50.c` (102 строки).

Цель: зафиксировать **все** начальные значения полей объекта секции дерева и дать полную карту смещений `this+0..+520` для переноса в TS `TreeSection`.

---

## 1. Сигнатура

```
int __stdcall sub_413F50(int a1, int a2, const void *a3, int a4)
```

- `a1` — указатель на выделенный объект (0x200+ байт, `operator new(0x220)`)
- `a2` — указатель на родителя (может быть `0`)
- `a3` — указатель на 64-байтный блок (матрица/transform шаблон → копируется в `a1+240`)
- `a4` — указатель на `float[3]` = `{yaw, pitch, roll}` для начальных кватернионов

---

## 2. Порядок инициализации

```
sub_401830(a1)                              // базовый init (обнуление/выделение списков)
this+0   = &TreeSection::vftable            // vtable pointer
this+196 = flt_4D538C                       // light direction X (global)
this+200 = flt_4D5390                       // light direction Y
this+204 = flt_4D5394                       // light direction Z
this+208 = 0.0                              // smoothed light accumulator A
this+212 = 0.0                              // smoothed light accumulator B
this+216 = flt_4D538C                       // prev/smooth direction X
this+220 = flt_4D5390                       // prev/smooth direction Y
this+224 = flt_4D5394                       // prev/smooth direction Z
this+228 = 0.0                              // smooth accumulator A (target → +208)
this+232 = 0.0                              // smooth accumulator B (target → +212)
this+236 = 0 (byte)                         // detach flag
qmemcpy(this+240, a3, 0x40)                // 64 bytes: local transform template
D3DXQuaternionRotationYawPitchRoll(this+304, yaw, pitch, roll)   // construction quat
D3DXQuaternionRotationYawPitchRoll(this+320, yaw, pitch, roll)   // target quat (same)
this+336 = dword_4D53A4                     // identity-like quat component (0.0)
this+340 = dword_4D53A8                     // 0.0
this+344 = dword_4D53AC                     // 0.0
this+348 = dword_4D53B0                     // 1.0
qmemcpy(this+352, &unk_4D8BA8, 0x40)       // 64 bytes: inverse transform template
this+420 = 0.0                              // energyProduction420
this+424 = 0.0                              // energyAccumulator424
this+428 = 0.0                              // energyWeight428
this+432 = 0.0                              // energyBudget432
this+436 = 0.0                              // energySpent436
this+440 = 0.0                              // energyTickCounter440
this+444 = 0.0                              // twigRadius444 (girth)
this+448 = 0.0                              // twigLength448
this+456 = 1.0                              // healthEnergy456 (1 = alive)
this+460 = 0.0                              // (unused / reserved)
this+416 = 0 (dword)                        // level / segment counter
this+464 = 0.0                              // (unused)
this+468 = dword_4D82D4                     // color/material DWORD 0
this+472 = dword_4D82D8                     // color/material DWORD 1
this+476 = dword_4D82DC                     // color/material DWORD 2
this+480 = 0                                // rollupDword480 (spawn counter)
this+484 = 0                                // rollupDword484 (tick counter)
this+4   = 5                                // sectionRuntimeType (base = 5)
sub_450BD0(this)                            // updateWorldMatrix (slot +16)
```

---

## 3. Привязка к родителю (a2 != 0)

```
list = *(a2 + 168)                          // parent's children list sentinel
node = sub_40FD70(list, list+4, &a1)        // allocate list node, value = a1
*(a2 + 172) += 1                            // increment child count
*(list + 4) = node                          // insert at tail
*(node[1]) = node                           // fix prev pointer
this+180 = a2                               // parent pointer

if byte_4D8225[11 * *(a2+4)]:              // if parent type has flag #5
    this+416 = *(a2+416)                    // copy level
    this+196 = *(a2+196)                    // copy light dir X
    this+200 = *(a2+200)                    // copy light dir Y
    this+204 = *(a2+204)                    // copy light dir Z
    this+208 = *(a2+208)                    // copy smooth A
    this+212 = *(a2+212)                    // copy smooth B
    this+216 = this+196                     // sync prev dir
    this+220 = this+200
    this+224 = this+204
    this+228 = this+208                     // sync smooth target
    this+232 = this+212
```

---

## 4. Полная карта полей `this+0..+520`

Составлена из `sub_413F50` + все функции, использующие эти смещения.

| Offset | Size | Init value | Семантика | Писатели | TS field |
|--------|------|------------|-----------|----------|----------|
| +0 | 4 | vtable ptr | vftable pointer | конструкторы наследников | — (implicit) |
| +4 | 4 | 5 | `sectionRuntimeType` (5=base, 6=bud, 7=leaf, 8=seed, 9=stump, 10=twig) | конструкторы типов | `sectionRuntimeType4` |
| +8..+20 | 12 | — | bounding position (для `sub_450A80` / spatial) | `sub_450BD0` | — |
| +20 | 4 | — | bounding half-size (для raycast `sub_450CD0`) | `sub_450A80` | — |
| +24 | 4 | — | world position X | `sub_4146F0` | — |
| +28 | 4 | — | world position Y | `sub_4146F0` | — |
| +32 | 4 | — | world position Z | `sub_4146F0` | — |
| +36 | 4 | — | bounding radius (для `sub_450CD0` hit test) | `sub_450A80` | — |
| +40 | 64 | quat*template | local matrix (построена в `sub_4146F0`) | `sub_4146F0` | — |
| +104 | 64 | — | world matrix | `sub_450BD0` | `group.matrixWorld` (Three.js) |
| +168 | 4 | list sentinel | children list head (doubly-linked, node = {next, prev, value}) | `sub_413F50`, `sub_40FD70` | `children[]` |
| +172 | 4 | 0 | children count | insert/remove | `children.length` |
| +180 | 4 | a2 or 0 | parent pointer | `sub_413F50` | `parent` |
| +188 | 1 | 0 | world-managed flag (`sub_401A50` → 1) | vtable +8 | `worldDetached188` |
| +196 | 4 | flt_4D538C | light-response vector X | `sub_4143E0`, `sub_40E460`, parent copy | — |
| +200 | 4 | flt_4D5390 | light-response vector Y | same | — |
| +204 | 4 | flt_4D5394 | light-response vector Z | same | — |
| +208 | 4 | 0.0 | smoothed light accumulator A (`sub_40E460`: `(x*intensity + old*10)/11`) | `sub_40E460`, `sub_4143E0` | — |
| +212 | 4 | 0.0 | smoothed light accumulator B (`sub_40E460`: `(intensity + old*20)/21`) | `sub_40E460`, `sub_4143E0` | — |
| +216 | 4 | flt_4D538C | prev/smooth direction X (сглаживается в `sub_4143E0`) | `sub_4143E0` | — |
| +220 | 4 | flt_4D5390 | prev/smooth direction Y | same | — |
| +224 | 4 | flt_4D5394 | prev/smooth direction Z | same | — |
| +228 | 4 | 0.0 | smooth target A (→ +208) | `sub_4143E0` | — |
| +232 | 4 | 0.0 | smooth target B (→ +212) | `sub_4143E0` | — |
| +236 | 1 | 0 | detach flag (1 = помечен для `sub_40EEE0`) | vtable +44, `sub_414270` | `worldDetached188`? / отдельный |
| +240 | 64 | copy from a3 | local transform template / base matrix | `sub_413F50`, `sub_4146F0` | — |
| +268 | 4 | — | material/color DWORD (используется в `sub_409130`) | — | — |
| +296 | 4 | — | scale factor (temp в `sub_4146F0`: `parent[112] * this`) | `sub_4146F0`, `sub_415C10` | — |
| +304 | 16 | quat(yaw,pitch,roll) | current rotation quaternion | `sub_413F50`, slerp в `sub_417C90`/`sub_418BD0` | `targetRotation` |
| +320 | 16 | quat(yaw,pitch,roll) | target rotation quaternion | `sub_413F50`, `sub_416510` | — |
| +336 | 16 | (0,0,0,1) | auxiliary quaternion (identity) | `sub_413F50` | — |
| +352 | 64 | copy from unk_4D8BA8 | inverse world matrix | `sub_4146F0` | — |
| +416 | 4 | 0 | level / segment depth counter | `sub_413F50`, `++` in children ctors | `level` |
| +420 | 4 | 0.0 | `energyProduction420` (leaf: `v19` from `sub_416510`) | `sub_416510`, rollup `sub_414E10` | `energyProduction420` |
| +424 | 4 | 0.0 | `energyAccumulator424` (integral of +420 over ticks) | `sub_414E10` tail, reset in `sub_414CE0` | `energyAccumulator424` |
| +428 | 4 | 0.0 | `energyWeight428` (share weight for +432 distribution) | constructors (=1.0), `sub_414CE0` | `energyWeight428` |
| +432 | 4 | 0.0 | `energyBudget432` (distributed from parent via `sub_414E10`) | `sub_40DC90`, `sub_414E10` | `energyBudget432` |
| +436 | 4 | 0.0 | `energySpent436` (cost: elongation/spawn/branch) | `sub_418BD0`, `sub_417620`, `sub_417FF0`, `sub_4188E0`, rollup | `energySpent436` |
| +440 | 4 | 0.0 | `energyTickCounter440` (+=1 per `sub_414E10` tail; время для ветвления) | `sub_414E10` tail | `energyTickCounter440` |
| +444 | 4 | 0.0 | `twigRadius444` (girth/radius of section) | `sub_4159C0`(=0.01), `sub_415C10`(=flt_4D861C), `sub_417C90`(+=) | `twigRadius444` |
| +448 | 4 | 0.0 | `twigLength448` (accumulated length) | `sub_418BD0` (pow formula) | `twigLength448` |
| +452 | 4 | — | max segment size (from `sub_417BB0`: lerp min/maxSegmentSize * rand) | constructors | `maxGrowth`? |
| +456 | 4 | 1.0 | `healthEnergy456` (0→1; decline triggers detach in `sub_417C90`) | `sub_417C90` | — |
| +460 | 4 | 0.0 | (debug threshold in `sub_4143E0`) | — | — |
| +464 | 4 | 0.0 | (reserved) | — | — |
| +468 | 4 | dword_4D82D4 | color/material channel 0 | `sub_413F50` | — |
| +472 | 4 | dword_4D82D8 | color/material channel 1 | `sub_413F50` | — |
| +476 | 4 | dword_4D82DC | color/material channel 2 | `sub_413F50` | — |
| +480 | 4 | 0 | `rollupDword480` (sum of spawn deltas, `sub_4188E0` ++) | `sub_414E10` rollup | `rollupDword480` |
| +484 | 4 | 0 | `rollupDword484` (tick counter, `sub_417C90` ++) | `sub_414E10` rollup | `rollupDword484` |
| +488 | 4 | — | world-object velocity/position X (used in `sub_40F140`) | `sub_40F140` | — |
| +492 | 4 | — | world-object velocity/position Y | same | — |
| +496 | 4 | — | world-object velocity/position Z | same | — |
| +500 | 4 | — | world-object angular velocity X | same | — |
| +504 | 4 | — | world-object angular velocity Y | same | — |
| +508 | 4 | — | world-object angular velocity Z | same | — |
| +512 | 1/4 | — | **dual use**: Bud: growth-active byte (1=growing); Twig: angle float for leaf spawn (`sub_415AB0`) | `sub_415C10`, `sub_418BD0`, `sub_415AB0` | `ce512EnergyAllowanceScale` |
| +516 | 4 | — | leaf counter on bud (++`sub_415AB0`) | `sub_415AB0` | — |

---

## 5. Глобальные константы, используемые в конструкторе

| Адрес | Значение | Семантика |
|-------|----------|-----------|
| `flt_4D538C` | light dir X (default из .data) | Глобальный вектор света |
| `flt_4D5390` | light dir Y | — |
| `flt_4D5394` | light dir Z | — |
| `dword_4D53A4..B0` | (0, 0, 0, 1.0) | Identity quaternion |
| `unk_4D8BA8` | 64 bytes | Identity/шаблонная инвертированная матрица |
| `dword_4D82D4..DC` | color defaults | Дефолтный цвет/материал из .data |
| `byte_4D8225[11*type]` | flag #5 per type | Флаг «копировать свет/уровень от родителя» |
| `dword_4D7CF8` | lazy init bit 0 | Однократная инициализация `sub_4079C0` |

---

## 6. Связь с TS

| C | TS модуль | Примечание |
|---|-----------|------------|
| `sub_413F50` | `TreeSection` constructor | Поля +420..+484 уже есть; +196..+232, +456, +512 dual-use — нужно добавить |
| `sub_450BD0` (вызов в конце) | `group.updateMatrixWorld` | Порядок сохранён |
| Список детей `+168/+172` | `children: TreeSection[]` | Массив вместо linked list — ОК |
| `byte_4D8225` check | `GrowthConstants.BYTE_4D8225_STRIDE11` | Таблица нулевая в TS → копирование от родителя не работает |

---

## 7. OPEN

- Точные значения `flt_4D538C`/`5390`/`5394` (вектор света по умолчанию) нужно снять из `.data.txt` или IDA.
- `dword_4D82D4..DC` (дефолтный цвет) — снять из `.data`.
- `unk_4D8BA8` — 64-байтная инвертированная матрица; предположительно identity, подтвердить из `.data`.

---

Готовность к TS: **да** (при снятии 3 OPEN выше из .data).
