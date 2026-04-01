# Спека: пружинная/ветровая физика `sub_414A70` + `sub_414BB0` + `sub_414870`

Файлы: `decompiled/sub_414A70.c`, `decompiled/sub_414BB0.c`, `decompiled/sub_414870.c`.

Цель: задокументировать механику «ветрового / гравитационного» провисания веток и сопротивление по радиусу.

---

## 1. Когда вызывается (контекст в `sub_4143E0`, vtable slot +12)

```
// Шаг 3 в sub_4143E0 (после рекурсии и sub_414870):
if byte_4D6356 != 0                           // INI flag "resistance enabled"
   AND this+172 != 0                          // has children
   AND flt_4D6358 < this+460:                 // threshold (0.001) < totalWeight460
    if this+180 != 0:                         // has parent
        sub_414A70(this)                      // ← ветровой крутящий момент
    sub_414BB0(this)                          // ← сопротивление (damping)
```

### INI-параметры

| Адрес | INI ключ | Default | Роль |
|-------|----------|---------|------|
| `byte_4D6356` | (lazy init #14, `sub_4038B0`) | `1` | Вкл/выкл всей подсистемы |
| `flt_4D6358` | (lazy init #14, `sub_4038B0`) | `0.001` | Минимальный `totalWeight460` для срабатывания |

---

## 2. `sub_414870` — вычисление центра масс и totalWeight

Вызывается **перед** `sub_414A70`/`sub_414BB0` для каждой секции.

```
void sub_414870(section):
    // Шаг 1: масса = vtable+56(section) * flt_4D85FC
    mass = section.vtable_56() * flt_4D85FC       // INI "weightCoeff" (a6 в sub_40D0B0)
    section.464 = mass                             // storedMass464
    section.460 = mass                             // totalWeight460

    // Шаг 2: проверка byte_4D8226[11 * sectionType]
    if byte_4D8226[11 * section.4]:               // flag #6 = "weightless"
        section.464 = 0.0                          // Bud (type=6) — единственный тип с flag #6
        section.460 = 0.0                          // → почки не имеют массы

    // Шаг 3: инициализация центра масс (centroid)
    section.468 = 0.0                              // centroidX
    section.472 = 0.0                              // centroidY
    section.476 = section.448 * 0.5                // centroidZ = length/2

    // Шаг 4: если есть дети — суммирование
    if section.172 != 0:                           // has children
        // масштабировать centroid на totalWeight
        section.468 *= section.460
        section.472 *= section.460
        section.476 *= section.460

        for each child in section.168:
            // трансформировать child.centroid в локальное пр-во через child.localMatrix(+40)
            localCentroid = transformCoord(child.468..476, child.40)
            // взвешенное суммирование
            weighted = localCentroid * child.460
            section.468 += weighted.x
            section.472 += weighted.y
            section.476 += weighted.z
            section.460 += child.460

        // нормализовать centroid на суммарный вес
        if section.460 > 0:
            inv = 1.0 / section.460
            section.468 *= inv
            section.472 *= inv
            section.476 *= inv
```

### Семантика полей

| Offset | Имя | Роль |
|--------|-----|------|
| +460 | `totalWeight460` | Суммарная масса секции + всех потомков |
| +464 | `storedMass464` | Масса одной секции (без детей) |
| +468..+476 | `centroid468` | Центр масс поддерева (в локальных координатах) |

---

## 3. `sub_414A70` — ветровой/гравитационный крутящий момент

```
void sub_414A70(section):
    // Шаг 1: длина вектора centroid
    centroidLen = length(section.468..476)

    // Шаг 2: глобальный вектор гравитации → локальное пространство
    //   dword_4D5314..4D531C = «гравитационное» направление (из sub_40D1A0)
    //   section+352 = inverseWorldMatrix
    localGravity = transformNormal(dword_4D5314, section.352)

    // Шаг 3: ось вращения = cross(centroid, localGravity)
    axis = cross(centroid, localGravity)
    axisNorm = normalize(axis)

    // Шаг 4: угол между centroid и localGravity
    gravityNorm = normalize(localGravity)
    angle = angleBetween(centroid, gravityNorm)     // sub_4010C0

    // Шаг 5: кватернион вокруг оси
    qRot = D3DXQuaternionRotationAxis(axisNorm, angle)

    // Шаг 6: весовой коэффициент
    factor = |sin(angle)| * section.460 * centroidLen
    factor *= pow(section.444, flt_4D8600)          // INI "accelerationRadiusPow"
    factor *= flt_4D5310                            // длина гравит. вектора (обычно ~1.0)
    factor = clamp(factor, 0, 1)

    // Шаг 7: slerp целевого кватерниона к ветровому
    section.320 = slerp(section.320, qRot, factor)
```

### INI-параметры

| Адрес | INI ключ | Слот `sub_40D0B0` | Роль |
|-------|----------|-------------------|------|
| `flt_4D8600` | `accelerationRadiusPow` | a7 | Экспонента для `pow(radius, ...)` — чем толще, тем больше рычаг |
| `flt_4D5310` | (из `sub_40D1A0`) | — | Длина гравитационного вектора (скалярный множитель) |

### Глобальный вектор `dword_4D5314..531C`

Вычисляется в `sub_40D1A0`:
```
gravityRaw = (dword_4D5304, dword_4D5308, dword_4D530C)   // raw вход
flt_4D5300 = length(gravityRaw)
blended = scale(flt_4D52F4, flt_4D52F0) + gravityRaw
(dword_4D5314, dword_4D5318, dword_4D531C) = blended
flt_4D5310 = length(blended)
```

---

## 4. `sub_414BB0` — сопротивление (damping/resistance)

```
void sub_414BB0(section):
    // Lazy INI:
    //   "resistanceRadiusBias" → flt_4D635C (смещение радиуса)

    // Шаг 1: фактор сопротивления из радиуса
    r = section.444 + flt_4D635C                   // INI "resistanceRadiusBias"
    r = pow(r, flt_4D8604)                         // INI "resistanceRadiusPow"
    r *= flt_4D8608                                // INI "resistanceCoeff"
    r = clamp(r, 0, 1)

    // Шаг 2: slerp targetQuat обратно к currentQuat
    //   Чем толще ветка → r ближе к 1 → больше сопротивление
    section.320 = slerp(section.320, section.304, r)
```

### INI-параметры

| Адрес | INI ключ | Слот `sub_40D0B0` | Роль |
|-------|----------|-------------------|------|
| `flt_4D635C` | `resistanceRadiusBias` | — (standalone) | Смещение радиуса перед `pow` |
| `flt_4D8604` | `resistanceRadiusPow` | a8 | Экспонента сопротивления |
| `flt_4D8608` | `resistanceCoeff` | a9 | Линейный множитель |

### Интерпретация

`sub_414BB0` — это **демпфирование**: целевой кватернион (`+320`) `slerp`-ится обратно к текущему (`+304`). Чем толще ветка (больше `+444`), тем сильнее возврат → тонкие ветки «провисают» под гравитацией, толстые — стоят.

---

## 5. Полная цепочка в `sub_4143E0` (шаг 3)

```
sub_414870(section)          // пересчёт centroid + totalWeight
if resistance_enabled:
    if has_parent:
        sub_414A70(section)  // крутящий момент от гравитации → targetQuat
    sub_414BB0(section)      // сопротивление → возврат targetQuat к currentQuat
```

Результат: `section.320` (targetQuat) сдвигается к «провисанию» (`sub_414A70`) и частично возвращается к текущей ориентации (`sub_414BB0`). Затем в `sub_417C90` / `sub_416510` / перестроении матриц `section.304` (currentQuat) сглаживается к `section.320`.

---

## 6. Связь с TS

| C | TS | Статус |
|---|----|--------|
| `sub_414870` | — | **НЕ ПОРТИРОВАН** — centroid + totalWeight не вычисляются |
| `sub_414A70` | — | **НЕ ПОРТИРОВАН** — ветровой момент отсутствует |
| `sub_414BB0` | — | **НЕ ПОРТИРОВАН** — resistance damping отсутствует |
| Поля +460, +464, +468..+476 | Частично в `TreeSection` | +460 есть как `totalWeight`, +464/+468..+476 отсутствуют |
| `flt_4D8600..4D8608` | `GrowthConstants` | Нет этих констант |

### TS рекомендация

```typescript
function computeCentroid(section: TreeSection): void {
  const mass = section.vtableSlot56() * GC.FLT_4D85FC;
  section.storedMass464 = mass;
  section.totalWeight460 = mass;

  if (GC.BYTE_4D8226_STRIDE11[11 * section.sectionRuntimeType]) {
    section.storedMass464 = 0;
    section.totalWeight460 = 0;
  }

  section.centroid468.set(0, 0, section.length448 * 0.5);

  if (section.children.size > 0) {
    section.centroid468.multiplyScalar(section.totalWeight460);
    const tmp = new THREE.Vector3();
    for (const child of section.children) {
      tmp.copy(child.centroid468).applyMatrix4(child.localMatrix40);
      tmp.multiplyScalar(child.totalWeight460);
      section.centroid468.add(tmp);
      section.totalWeight460 += child.totalWeight460;
    }
    if (section.totalWeight460 > 0) {
      section.centroid468.multiplyScalar(1.0 / section.totalWeight460);
    }
  }
}

function applyWindTorque(section: TreeSection): void {
  const centroidLen = section.centroid468.length();
  const localGrav = globalGravityVec.clone()
    .applyMatrix4(section.inverseWorldMatrix352);

  const axis = new THREE.Vector3()
    .crossVectors(section.centroid468, localGrav).normalize();
  const gravNorm = localGrav.clone().normalize();
  const angle = section.centroid468.angleTo(gravNorm);

  const qRot = new THREE.Quaternion()
    .setFromAxisAngle(axis, angle);

  let factor = Math.abs(Math.sin(angle))
    * section.totalWeight460 * centroidLen;
  factor *= Math.pow(section.twigRadius444, GC.FLT_4D8600);
  factor *= globalGravityLength;
  factor = Math.min(factor, 1.0);

  section.targetQuat320.slerp(qRot, factor);
}

function applyResistance(section: TreeSection): void {
  let r = section.twigRadius444 + GC.FLT_4D635C;
  r = Math.pow(r, GC.FLT_4D8604);
  r *= GC.FLT_4D8608;
  r = Math.min(r, 1.0);
  section.targetQuat320.slerp(section.currentQuat304, r);
}
```

---

Готовность к TS: **да** — все формулы полностью ясны.
