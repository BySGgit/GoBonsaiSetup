# Full Technical Parity Plan (v2, concrete)

## 1) Цель

Довести TS-реализацию до воспроизводимого поведения C/EXE в runtime-контуре:

- тот же порядок вычислений в ростовом кадре,
- те же численные результаты по ключевым полям (`+420/+424/+428/+432/+436/+444/+448`),
- отсутствие скрытых approximate-путей в P0/P1 модулях.

## 2) Базовая метрика на 2026-04-06

Источник: `GUIDES/decomp_runtime_parity_queue.csv` (полный аудит callgraph).

- `sub_*` всего: `1223`
- `unmapped`: `1160`
- Фазы по unmapped:
- `P0-A`: `12`
- `P0-B`: `8`
- `P1`: `41`
- `P2`: `35`
- `P3-unreached`: `1064` (в основном не runtime-критично на текущем пути)

## 3) Правила выполнения (обязательно)

1. Один PR/патч = одна parity-цель.
2. Каждая правка привязана к `sub_xxxxxx.c` (комментарием в коде и строкой в `GUIDES`).
3. Каждый закрытый `sub_*` должен иметь минимум один численный тест/fixture.
4. Любой стабилизатор, не присутствующий в C, только под явным флагом.
5. Все приоритеты выбираются из `decomp_runtime_parity_queue.csv`, не вручную.

## 4) Фазы и конкретные шаги

### P0-A (прямые unmapped-зависимости runtime-root)

Порядок выполнения по score:

1. `sub_401470`, `sub_401430`, `sub_401500`, `sub_4013F0`, `sub_401180`, `sub_408470`, `sub_408590`
2. `sub_4032D0`, `sub_408600`, `sub_40FD70`
3. `sub_4015F0`, `sub_4038B0`, `sub_451210`, `sub_44E5D0`

Критерий выхода P0-A:

- Все 12 функций имеют статус минимум `mapped-verified` в карте покрытия.
- Для каждой есть unit/fixture тест с численной проверкой.

### P0-B (следующий прямой контур)

1. `sub_4084F0`, `sub_40CF00`, `sub_413CF0`, `sub_401730`
2. Связанные thin-wrapper/allocator функции уровня depth=2 (`sub_4037B0`, `sub_403580`, `sub_44A640`, `sub_43FD00`)

Критерий выхода P0-B:

- Устранены runtime TODO/APPROX, завязанные на эти функции.
- Паритетные тесты проходят на расширенном наборе контрольных дней.

### P1 (глубина 1–2, средний риск)

По убыванию score из CSV: `sub_40D6C0`, `sub_4153D0`, `sub_40A310`, `sub_4033D0`, `sub_403410`, `sub_403BA0`, ...

Критерий выхода P1:

- Нет unmapped в reachable depth<=2, влияющих на ростовой цикл.

### P2/P3

- P2: низкий runtime-эффект, закрывается после P1.
- P3-unreached: только после завершения runtime parity gate.

## 5) Что уже закрыто в этом цикле

1. Введён полный аудит очереди портирования:
- `tools/build_runtime_parity_queue.ps1`
- `GUIDES/decomp_runtime_parity_queue.csv`
- `GUIDES/decomp_runtime_parity_queue.md`

2. Введён one-hop dependency frontier:
- `tools/update_decomp_dependency_frontier.ps1`
- `GUIDES/decomp_dependency_frontier.csv`
- `GUIDES/decomp_dependency_frontier.md`

3. Начат P0-A utility-пакет:
- добавлен модуль `src/engine/math/Vec3Sub40xPrimitives.ts`
- подключён в `perFramePhysicsSub4143E0.ts`, `branchingDispatcherSub417F40.ts`, `twigLengthGrowthSub418BD0.ts`
- добавлены тесты `Vec3Sub40xPrimitives.test.ts`

## 6) Паритетный gate (обязательно перед переходом фазы)

Команды:

```powershell
cd gobonsai-web
npm run build
npm test -- --run
```

Дополнительно для планирования:

```powershell
powershell -ExecutionPolicy Bypass -File tools/update_decomp_dependency_frontier.ps1
powershell -ExecutionPolicy Bypass -File tools/build_runtime_parity_queue.ps1
```

Критерий приёмки:

- build + tests зелёные,
- нет новых runtime-regression по `Год/День` и энергии на контрольных сценариях,
- список приоритетов обновлён и зафиксирован в `GUIDES/decomp_runtime_parity_queue.csv`.
