# Runtime Parity Queue (full decomp audit)

Generated: 2026-04-06T19:41:44

- Inputs: `decompiled/sub_*.c`, `GUIDES/decomp_master_manifest.csv`
- Total sub_* discovered: 1223
- Unmapped: 1108
- Runtime roots used: sub_40dc90, sub_4143e0, sub_416510, sub_417c90, sub_417ff0, sub_4188e0, sub_40e0a0, sub_40e230, sub_40e460, sub_40eee0, sub_40f140, sub_414ce0, sub_414e10, sub_408a30, sub_408d60

## Unmapped by phase

| phase | count |
| --- | ---: |
| P1 | 10 |
| P2 | 34 |
| P3-unreached | 1064 |

## Top 60 execution queue

| sub | phase | score | depth | mapped callers | mapped call sites | total call sites | sample callers |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| sub_451320 | P1 | 666 | 2 | 1 | 1 | 1 | sub_450e30 |
| sub_472410 | P1 | 666 | 1 | 1 | 1 | 1 | sub_4143e0 |
| sub_472420 | P1 | 666 | 1 | 1 | 1 | 1 | sub_4143e0 |
| sub_472460 | P1 | 666 | 1 | 1 | 1 | 1 | sub_416510 |
| sub_472470 | P1 | 666 | 1 | 1 | 1 | 1 | sub_416510 |
| sub_472480 | P1 | 666 | 1 | 1 | 1 | 1 | sub_416510 |
| sub_472490 | P1 | 666 | 1 | 1 | 1 | 1 | sub_416510 |
| sub_4724a0 | P1 | 666 | 1 | 1 | 1 | 1 | sub_417c90 |
| sub_4724b0 | P1 | 666 | 1 | 1 | 1 | 1 | sub_417ff0 |
| sub_441e00 | P2 | 405 | 3 | 1 | 5 | 20 | sub_43fd00, sub_4401a0, sub_440720, sub_440d50, sub_441ef0, sub_442410 |
| sub_44b900 | P2 | 388 | 3 | 1 | 1 | 3 | sub_44a640, sub_44c260 |
| sub_44c260 | P2 | 378 | 3 | 1 | 3 | 3 | sub_44a640 |
| sub_403440 | P2 | 375 | 3 | 1 | 2 | 5 | sub_4037b0, sub_440d50, sub_44bfe0 |
| sub_403b40 | P2 | 372 | 3 | 1 | 2 | 2 | sub_403a90 |
| sub_4440f0 | P2 | 372 | 3 | 1 | 2 | 2 | sub_44a640 |
| sub_401830 | P2 | 371 | 3 | 1 | 1 | 6 | sub_401c10, sub_408700, sub_40d6f0, sub_4100e0, sub_413f50, sub_451d70 |
| sub_43fbb0 | P2 | 366 | 3 | 1 | 1 | 1 | sub_472560 |
| sub_444090 | P2 | 366 | 3 | 1 | 1 | 1 | sub_44a640 |
| sub_44a600 | P2 | 366 | 3 | 1 | 1 | 1 | sub_43fd00 |
| sub_451460 | P2 | 321 | 3 | 0 | 0 | 1 | sub_451320 |
| sub_4517d0 | P2 | 321 | 3 | 0 | 0 | 1 | sub_451320 |
| sub_4518f0 | P2 | 321 | 3 | 0 | 0 | 1 | sub_451320 |
| sub_451990 | P2 | 321 | 3 | 0 | 0 | 1 | sub_451320 |
| sub_472430 | P1 | 266 | 2 | 1 | 1 | 1 | sub_414bb0 |
| sub_42dbc0 | P3-unreached | 65 |  | 0 | 0 | 65 | sub_406d10, sub_428830, sub_428dd0, sub_429000, sub_429330, sub_4293c0, sub_4294f0, sub_429810 |
| sub_402cd0 | P2 | 62 | 4 | 0 | 0 | 2 | sub_401830, sub_402e10 |
| sub_44bb00 | P3-unreached | 50 |  | 0 | 0 | 50 | sub_4458e0, sub_445bd0, sub_445d60, sub_445ee0, sub_446040, sub_4461a0, sub_446300, sub_446460 |
| sub_444ae0 | P2 | 48 | 4 | 0 | 0 | 8 | sub_440d50, sub_444e90, sub_444ff0, sub_44a600 |
| sub_434240 | P3-unreached | 47 |  | 0 | 0 | 47 | sub_4392b0, sub_43b270, sub_43b930, sub_43ca00, sub_43cf10, sub_43d1b0, sub_43d7e0, sub_43d8d0 |
| sub_413df0 | P3-unreached | 46 |  | 1 | 1 | 1 | sub_4151b0 |
| sub_417bb0 | P3-unreached | 46 |  | 1 | 1 | 1 | sub_415c10 |
| sub_446b40 | P2 | 45 | 4 | 0 | 0 | 5 | sub_43fbb0, sub_440d50, sub_4442b0, sub_446a30 |
| sub_444140 | P2 | 42 | 4 | 0 | 0 | 2 | sub_43fbb0, sub_442640 |
| sub_44bc80 | P2 | 42 | 4 | 0 | 0 | 2 | sub_44a600, sub_44b1c0 |
| sub_44a460 | P2 | 41.67 | 5 | 0 | 0 | 5 | sub_4458e0, sub_44b1c0, sub_44bc80 |
| sub_451a80 | P2 | 41.67 | 5 | 0 | 0 | 5 | sub_451720 |
| sub_403230 | P2 | 41 | 4 | 0 | 0 | 1 | sub_401830 |
| sub_444ce0 | P2 | 41 | 4 | 0 | 0 | 1 | sub_43fbb0 |
| sub_44c360 | P2 | 41 | 4 | 0 | 0 | 1 | sub_441e00 |
| sub_451720 | P2 | 41 | 4 | 0 | 0 | 1 | sub_451460 |
| sub_451b10 | P2 | 41 | 4 | 0 | 0 | 1 | sub_4518f0 |
| sub_451c10 | P2 | 41 | 4 | 0 | 0 | 1 | sub_4517d0 |
| sub_402e10 | P2 | 37.67 | 5 | 0 | 0 | 1 | sub_402cd0 |
| sub_402ee0 | P2 | 37.67 | 5 | 0 | 0 | 1 | sub_402cd0 |
| sub_44ede0 | P2 | 37.67 | 5 | 0 | 0 | 1 | sub_402cd0 |
| sub_4032a0 | P2 | 36.5 | 7 | 0 | 0 | 4 | sub_402f60 |
| sub_402f60 | P2 | 36.29 | 6 | 0 | 0 | 2 | sub_402e10, sub_451110 |
| sub_4031b0 | P2 | 34.5 | 7 | 0 | 0 | 2 | sub_402f60, sub_4082f0 |
| sub_403210 | P2 | 34.5 | 7 | 0 | 0 | 2 | sub_402f60 |
| sub_41b5d0 | P3-unreached | 34 |  | 0 | 0 | 34 | sub_407bb0, sub_41d000, sub_41dd60, sub_41e880, sub_4224f0, sub_4256b0, sub_426190, sub_426710 |
| sub_42fae0 | P3-unreached | 33 |  | 0 | 0 | 33 | sub_403c50, sub_438b90 |
| sub_434340 | P3-unreached | 33 |  | 0 | 0 | 33 | sub_433370, sub_4392b0, sub_43b270, sub_43b5a0, sub_43b930, sub_43c070, sub_43c2f0, sub_43c650 |
| sub_44db70 | P3-unreached | 32 |  | 0 | 0 | 32 | sub_4426b0, sub_4428a0, sub_442ab0, sub_442ca0, sub_442e90, sub_443080, sub_443270, sub_443460 |
| sub_434450 | P3-unreached | 30 |  | 0 | 0 | 30 | sub_4392b0, sub_43b270, sub_43b930, sub_43ca00, sub_43cf10, sub_43d1b0, sub_43d7e0, sub_43d8d0 |
| sub_41b6c0 | P3-unreached | 29 |  | 0 | 0 | 29 | sub_41e880 |
| sub_42fa10 | P3-unreached | 28 |  | 0 | 0 | 28 | sub_431990 |
| sub_4371f0 | P3-unreached | 28 |  | 0 | 0 | 28 | sub_431990 |
| sub_419430 | P3-unreached | 27 |  | 0 | 0 | 27 | sub_421960, sub_422b80, sub_42a8d0, sub_42bdd0, sub_42d070, sub_44f510 |
| sub_444b50 | P3-unreached | 24 |  | 0 | 0 | 24 | sub_440d50, sub_4417c0, sub_4458e0, sub_44bfe0 |
| sub_4344d0 | P3-unreached | 23 |  | 0 | 0 | 23 | sub_4392b0, sub_43b270, sub_43b5a0, sub_43b930, sub_43c070, sub_43c2f0, sub_43c650, sub_43ca00 |

Machine-readable queue: `GUIDES/decomp_runtime_parity_queue.csv`.

Recommendation: execute in strict order by `phase` then `priority_score`.
