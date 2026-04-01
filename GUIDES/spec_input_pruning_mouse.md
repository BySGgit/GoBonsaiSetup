# Спека: ввод мышью, обрезка и камера — полная цепочка

Файлы: `decompiled/sub_41D000.c` (WndProc), `decompiled/sub_403C50.c` (UI подсказки),
`decompiled/sub_414270.c`, `decompiled/sub_418E40.c`, `decompiled/sub_4142B0.c`.

Цель: задокументировать полную цепочку от события мыши до `sub_40EEE0` (detach).

---

## 1. Подтверждённые строки UI

В `decompiled/sub_403C50.c` (и `full.c`) в подсказках управления:

- **ЛКМ удерживать** — Quick Trim
- **СКМ клик** — Slow Cut
- **ПКМ удерживать** — поворот камеры
- **Колёсико** — зум
- **Двойной ПКМ** — Close-Up Mode

Также упоминается пункт меню **Auto Trim** (`sub_42FBA0` с строкой `L"Auto Trim"`).

---

## 2. WndProc: `sub_41D000` — маршрутизация событий мыши

### 2.1. Клавиатура (Msg 256/257/260/261)

```
if Msg == 256 (WM_KEYDOWN) or Msg == 260 (WM_SYSKEYDOWN):
    isDown = true
elif Msg == 257 (WM_KEYUP) or Msg == 261 (WM_SYSKEYUP):
    isDown = false

engine = GetEngineInstance()
engine[1008 + (wParam & 0xFF)] = isDown         // таблица нажатых клавиш
callback = engine+876                            // keyCallback(key, isDown, isAlt, userData)
if callback: callback(wParam, isDown, altFlag, engine+948)
```

### 2.2. Мышь (Msg 512–525)

Обработка мыши начинается при `Msg ∈ {512(MOUSEMOVE), 513(LBUTTONDOWN), 514(LBUTTONUP), 515(LBUTTONDBLCLK), 516(RBUTTONDOWN), 517(RBUTTONUP), 518(RBUTTONDBLCLK), 519(MBUTTONDOWN), 520(MBUTTONUP), 521(MBUTTONDBLCLK), 522(MOUSEWHEEL), 523..525}`:

```
x = LOWORD(lParam)
y = HIWORD(lParam)
if Msg == 522 (MOUSEWHEEL):
    ScreenToClient(hWnd, &point)                 // колёсико даёт screen coords
    x, y = point.x, point.y

wheelDelta = (Msg == 522) ? HIWORD(wParam) : 0

// Разбор модификаторов
leftBtn   = wParam & MK_LBUTTON
rightBtn  = wParam & MK_RBUTTON
midBtn    = wParam & MK_MBUTTON
shift     = wParam & MK_SHIFT
ctrl      = wParam & MK_CONTROL

// Записать состояние в engine
engine = GetEngineInstance()
engine.byte[1520] = leftBtn
engine.byte[1521] = midBtn
engine.byte[1522] = rightBtn
engine.byte[1523] = shift
engine.byte[1524] = ctrl

// Вызвать MOUSE callback (engine+880)
mouseCallback = *(engine + 880)                  // fn(leftBtn, rightBtn, midBtn, shift, ctrl, wheelDelta, x, y, userData)
if mouseCallback:
    mouseCallback(leftBtn, rightBtn, midBtn, shift, ctrl, wheelDelta, x, y, *(engine+952))
```

### 2.3. MsgProc callback (engine+884)

После mouse callback вызывается **общий MsgProc**:

```
msgProc = *(engine + 884)                        // fn(hWnd, Msg, wParam, lParam, &eaten, userData)
if msgProc:
    result = msgProc(hWnd, Msg, wParam, lParam, &eaten, *(engine+956))
    if eaten: return result
// иначе → маршрутизация по Msg (switch)
```

### 2.4. WM_MOUSEMOVE (0x200) — vtable +44

```
if isActive && !isWindowed:
    if sub_41B490():                             // hasD3DDevice?
        device = sub_41B510()
        if device:
            GetCursorPos(&point)
            device->vtable[44](device, point.x, point.y, 0)  // cursor notification
```

Это D3D device callback, вероятно для **hover-подсветки** (отслеживание позиции курсора над деревом).

---

## 3. Цепочка обрезки: мышь → пометка → detach

### Ключевое наблюдение

В статическом декомпиле **нет прямого пути** `mouse_click → sub_40EEE0`. Обрезка работает через **двухэтапный** механизм:

### Этап 1: Пометка секции (`this+236 = 1`)

Связь `mouseCallback` (engine+880) → игровой код выполняется через **функциональные указатели**, которые устанавливаются при инициализации и в статическом `full.c` **не присваиваются** (только обнуляются). Это CDXUT-фреймворк.

На основе поведения (UI-подсказки + vtable slot +44):
1. **Quick Trim (ЛКМ)**: каждый кадр при зажатой ЛКМ → raycast от курсора → найти ближайшую секцию → `*(section+236) = 1`
2. **Slow Cut (СКМ)**: одиночный клик → raycast → `*(section+236) = 1`
3. **Auto Trim**: по таймеру → автоматическая пометка самых длинных/перегруженных веток

Raycast реализуется через `D3DXVec3TransformCoord` / `D3DXMatrixInverse` (sub_4085B0, sub_408A30), **без** `D3DXIntersect` (не найден в импортах). Вероятно ручной raycast по иерархии bounding volumes (sub_450E30 / sub_450CD0).

### Этап 2: Проверка пометки в update-цикле

Три функции проверяют `this+236` и вызывают `sub_40EEE0`:

#### `sub_414270` (vtable slot +48 для TreeSection base)
```
void sub_414270(this):
    for each child in this.168:
        child.vtable[48](child)                  // рекурсия
    if this.236:                                 // помечен?
        sub_40EEE0(this)                         // → detach pipeline
```

#### `sub_418E40` (vtable slot +48 для TreeSectionTwig)
```
void sub_418E40(this):
    if this.236:                                 // помечен?
        parent = this.180
        if parent == NULL
           OR !byte_4D8228[11 * parent.4]:       // родитель не «тупиковый»
            if sub_415650(this):                 // можно ли отсечь?
                sub_418D50(this)                 // спец. логика twig detach

    for each child in this.168:
        child.vtable[48](child)                  // рекурсия

    if this.236:                                 // повторная проверка
        sub_40EEE0(this)                         // → detach pipeline
```

#### `sub_4142B0` — альтернативный путь (Auto Trim?)
```
void sub_4142B0(this):
    // Ходит вверх по цепочке this+45 (parent?) пока не найдёт
    // секцию с radius >= 0.7 или sub_4154B0() > 1
    // Затем: если byte_4D8225 → sub_40EEE0(this)
```

---

## 4. Vtable slot +44 — пометка для detach

Документирован в `spec_vtable_slot_44.md`. Устанавливает `this+236 = 1`.

---

## 5. Полная схема

```
┌──────────────┐     ┌───────────────────┐     ┌──────────────┐
│  WndProc     │     │ Game Callback     │     │ Update Cycle │
│  sub_41D000  │────►│ (engine+880)      │────►│ vtable[48]   │
│              │     │ raycast → mark    │     │ sub_414270   │
│ Msg=513..525 │     │ this+236 = 1      │     │ sub_418E40   │
│ → engine     │     │                   │     │              │
│   [1520-1524]│     │ (не в static      │     │ if this+236: │
│ → callback   │     │  decompile)       │     │   sub_40EEE0 │
└──────────────┘     └───────────────────┘     └──────────────┘
```

---

## 6. Порт в TS (Three.js)

Для веб-версии не нужен 1:1 порт WndProc. Рекомендуемая архитектура:

```typescript
// Raycast через Three.js
const raycaster = new THREE.Raycaster();

function onMouseDown(event: MouseEvent) {
  const mouse = new THREE.Vector2(
    (event.clientX / window.innerWidth) * 2 - 1,
    -(event.clientY / window.innerHeight) * 2 + 1
  );
  raycaster.setFromCamera(mouse, camera);

  const intersects = raycaster.intersectObjects(treeMeshes, true);
  if (intersects.length > 0) {
    const section = meshToSection.get(intersects[0].object);
    if (section) {
      if (event.button === 0) {
        // Quick Trim (ЛКМ)
        section.markedForDetach236 = true;
      } else if (event.button === 1) {
        // Slow Cut (СКМ)
        section.markedForDetach236 = true;
      }
    }
  }
}

// В update loop
function processDetachMarks(root: TreeSection) {
  for (const child of root.children) {
    processDetachMarks(child);
  }
  if (root.markedForDetach236) {
    detachSection(root);  // sub_40EEE0 equivalent
  }
}
```

### Отличия Quick Trim vs Slow Cut

| Режим | Поведение | Реализация в TS |
|-------|----------|-----------------|
| **Quick Trim** | ЛКМ зажата → пометка каждый кадр | `mousedown` + `mousemove` при зажатой ЛКМ |
| **Slow Cut** | СКМ клик → одиночная пометка | Один `mousedown` event |
| **Auto Trim** | Автоматически по таймеру/правилу | `sub_4142B0` → отсечение перегруженных веток |

---

## 7. Необнаруженное в декомпиле

| Элемент | Статус | Влияние на паритет |
|---------|--------|--------------------|
| Конкретный game callback (engine+880) | Не привязан к адресу | Для TS — Three.js Raycaster, не нужен 1:1 |
| Raycast по BVH (ручной) | Вероятно sub_450E30/sub_450CD0 | Three.js Raycaster заменяет |
| Подсветка секции при hover | vtable+44 в WM_MOUSEMOVE | Можно реализовать через Three.js hover |
| «Цвета обрезки» (красный/жёлтый/синий/белый) | UI-элемент, не core logic | Визуальный feedback |

---

## 8. Статус

**✅ ЗАКРЫТО для паритета роста/физики**: цепочка `пометка → sub_40EEE0` полностью документирована в `spec_vtable_slot_44.md` + `spec_detach_pipeline_sub_40EEE0.md` + данный документ.

**Для UX-паритета**: Three.js Raycaster + обработчики `mousedown`/`mousemove` покрывают функциональность Quick Trim / Slow Cut. Auto Trim через `sub_4142B0`.

---

Готовность к TS: **да** — архитектура ясна, raycast через Three.js, detach через существующий pipeline.
