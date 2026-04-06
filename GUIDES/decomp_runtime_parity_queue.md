# Runtime Parity Queue (full decomp audit)

Generated: 2026-04-06T14:27:27

- Inputs: `decompiled/sub_*.c`, `GUIDES/decomp_master_manifest.csv`
- Total sub_* discovered: 1223
- Unmapped: 1160
- Runtime roots used: sub_40dc90, sub_4143e0, sub_416510, sub_417c90, sub_417ff0, sub_4188e0, sub_40e0a0, sub_40e230, sub_40e460, sub_40eee0, sub_40f140, sub_414ce0, sub_414e10, sub_408a30, sub_408d60

## Unmapped by phase

| phase | count |
| --- | ---: |
| P0-A | 12 |
| P0-B | 8 |
| P1 | 41 |
| P2 | 35 |
| P3-unreached | 1064 |

## Top 60 execution queue

| sub | phase | score | depth | mapped callers | mapped call sites | total call sites | sample callers |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| sub_401470 | P0-A | 1794 | 1 | 11 | 18 | 44 | sub_402040, sub_402310, sub_402600, sub_402880, sub_408590, sub_408a30, sub_408d60, sub_40a0e0 |
| sub_4032d0 | P0-A | 1678 | 1 | 8 | 14 | 88 | sub_4033d0, sub_409130, sub_40a8b0, sub_40dc90, sub_40e230, sub_40e460, sub_40ea30, sub_412700 |
| sub_401430 | P0-A | 1636 | 1 | 8 | 19 | 41 | sub_401690, sub_401b10, sub_402040, sub_402600, sub_408d60, sub_4093b0, sub_409910, sub_40a0e0 |
| sub_408600 | P0-A | 1522 | 1 | 7 | 11 | 47 | sub_409130, sub_40a8b0, sub_40dc90, sub_40e230, sub_40e460, sub_40ea30, sub_412d20, sub_4130d0 |
| sub_401500 | P0-A | 1455 | 1 | 6 | 10 | 25 | sub_401b10, sub_402040, sub_40bb50, sub_40c320, sub_40d1a0, sub_40e230, sub_40e460, sub_40eee0 |
| sub_4013f0 | P0-A | 1446 | 1 | 6 | 9 | 21 | sub_401690, sub_401b10, sub_402310, sub_402880, sub_40d1a0, sub_40e460, sub_411000, sub_412d20 |
| sub_40fd70 | P0-A | 1366 | 1 | 5 | 5 | 21 | sub_401ce0, sub_4038b0, sub_4039a0, sub_406ae0, sub_408600, sub_408700, sub_40cfa0, sub_40e0a0 |
| sub_408470 | P0-A | 1349 | 1 | 5 | 8 | 9 | sub_408a30, sub_40d230, sub_414a70, sub_416510, sub_417ff0, sub_418bd0 |
| sub_401180 | P0-A | 1283 | 1 | 4 | 7 | 8 | sub_401190, sub_414a70, sub_416510, sub_417ff0, sub_418bd0 |
| sub_408590 | P0-A | 1217 | 1 | 3 | 4 | 17 | sub_408a30, sub_40a0e0, sub_40a320, sub_40a440, sub_40d230, sub_40e230, sub_411000, sub_417ff0 |
| sub_4085b0 | P0-A | 1186 | 1 | 3 | 4 | 6 | sub_4093b0, sub_409910, sub_40f140, sub_414870 |
| sub_450c80 | P0-A | 1186 | 1 | 3 | 4 | 6 | sub_40eee0, sub_415c10, sub_415ed0, sub_417620, sub_417c90 |
| sub_4015f0 | P0-B | 1162 | 1 | 2 | 2 | 12 | sub_401ae0, sub_402aa0, sub_40d6c0, sub_40f140, sub_411000, sub_4139d0, sub_4146f0, sub_4153d0 |
| sub_4038b0 | P0-B | 1155 | 1 | 2 | 4 | 15 | sub_40dc90, sub_412700, sub_413350, sub_4143e0, sub_46fe60, sub_46ff10, sub_4702a0, sub_4703c0 |
| sub_451210 | P0-B | 1141 | 1 | 2 | 3 | 6 | sub_40cd30, sub_40d8c0, sub_40e0a0, sub_40f140, sub_413350 |
| sub_44e5d0 | P0-B | 1138 | 1 | 2 | 3 | 3 | sub_40e460, sub_4143e0 |
| sub_4084f0 | P0-B | 1134 | 1 | 2 | 2 | 4 | sub_408d60, sub_40d1a0, sub_414a70 |
| sub_40cf00 | P0-B | 1133 | 1 | 2 | 2 | 3 | sub_40d230, sub_40e460, sub_4143e0 |
| sub_413cf0 | P0-B | 1115 | 1 | 2 | 2 | 5 | sub_40eee0, sub_412bf0, sub_415ef0 |
| sub_40d6c0 | P1 | 1079 | 1 | 1 | 2 | 9 | sub_40e460, sub_411000, sub_4139d0, sub_415650 |
| sub_4153d0 | P1 | 1077 | 1 | 1 | 1 | 12 | sub_404c10, sub_406400, sub_408a30, sub_4102c0 |
| sub_40a310 | P1 | 1069 | 1 | 1 | 1 | 4 | sub_40bb50, sub_40c320, sub_40e460, sub_4139d0 |
| sub_4033d0 | P1 | 1068 | 1 | 1 | 1 | 3 | sub_40a8b0, sub_412d20, sub_416510 |
| sub_403410 | P1 | 1068 | 1 | 1 | 1 | 3 | sub_416510, sub_440d50 |
| sub_403ba0 | P1 | 1068 | 1 | 1 | 1 | 3 | sub_404c10, sub_406400, sub_408a30 |
| sub_401690 | P1 | 1067 | 1 | 1 | 1 | 2 | sub_402600, sub_408a30 |
| sub_401b00 | P1 | 1067 | 1 | 1 | 1 | 2 | sub_402310, sub_417ff0 |
| sub_401b10 | P1 | 1067 | 1 | 1 | 1 | 2 | sub_402600, sub_408a30 |
| sub_40fc70 | P1 | 1066 | 1 | 1 | 1 | 1 | sub_40eee0 |
| sub_40fcf0 | P1 | 1066 | 1 | 1 | 1 | 1 | sub_40eee0 |
| sub_401dd0 | P1 | 970 | 2 | 0 | 0 | 70 | sub_471e90, sub_471ea0, sub_471eb0, sub_472010, sub_472040, sub_472070, sub_472080, sub_472090 |
| sub_401730 | P0-B | 786 | 2 | 2 | 3 | 11 | sub_4017d0, sub_401830, sub_402bc0, sub_403a90, sub_4079c0, sub_40a200, sub_40f8f0 |
| sub_4017d0 | P1 | 721 | 2 | 1 | 2 | 11 | sub_401730, sub_401830, sub_402bc0, sub_4079c0, sub_40a200, sub_40f8f0 |
| sub_4037b0 | P1 | 719 | 2 | 0 | 0 | 19 | sub_401ce0, sub_4032d0, sub_4038b0, sub_4039a0, sub_408600, sub_40cfa0, sub_40ffc0, sub_4403f0 |
| sub_43fd00 | P1 | 688 | 2 | 0 | 0 | 28 | sub_401ce0, sub_401dd0, sub_4038b0, sub_4039a0, sub_406770, sub_407bb0, sub_407eb0, sub_408600 |
| sub_408450 | P1 | 687 | 2 | 1 | 1 | 2 | sub_408470, sub_450a80 |
| sub_403580 | P1 | 687 | 2 | 0 | 0 | 7 | sub_4032d0, sub_4036f0, sub_4037b0, sub_444b50, sub_4468b0, sub_44a460, sub_44bc80 |
| sub_40fa00 | P1 | 669 | 2 | 1 | 1 | 4 | sub_40fcf0, sub_4142b0, sub_417220, sub_418e40 |
| sub_4015b0 | P1 | 667 | 2 | 1 | 1 | 2 | sub_402880, sub_40d6d0 |
| sub_451320 | P1 | 666 | 2 | 1 | 1 | 1 | sub_450e30 |
| sub_4720e0 | P1 | 666 | 1 | 1 | 1 | 1 | sub_40dc90 |
| sub_4720f0 | P1 | 666 | 1 | 1 | 1 | 1 | sub_40dc90 |
| sub_472100 | P1 | 666 | 1 | 1 | 1 | 1 | sub_40dc90 |
| sub_472110 | P1 | 666 | 1 | 1 | 1 | 1 | sub_40dc90 |
| sub_472170 | P1 | 666 | 1 | 1 | 1 | 1 | sub_40e230 |
| sub_472180 | P1 | 666 | 1 | 1 | 1 | 1 | sub_40e460 |
| sub_472410 | P1 | 666 | 1 | 1 | 1 | 1 | sub_4143e0 |
| sub_472420 | P1 | 666 | 1 | 1 | 1 | 1 | sub_4143e0 |
| sub_472460 | P1 | 666 | 1 | 1 | 1 | 1 | sub_416510 |
| sub_472470 | P1 | 666 | 1 | 1 | 1 | 1 | sub_416510 |
| sub_472480 | P1 | 666 | 1 | 1 | 1 | 1 | sub_416510 |
| sub_472490 | P1 | 666 | 1 | 1 | 1 | 1 | sub_416510 |
| sub_4724a0 | P1 | 666 | 1 | 1 | 1 | 1 | sub_417c90 |
| sub_4724b0 | P1 | 666 | 1 | 1 | 1 | 1 | sub_417ff0 |
| sub_44a640 | P1 | 646 | 2 | 0 | 0 | 6 | sub_401ce0, sub_4038b0, sub_4039a0, sub_408600, sub_40cfa0, sub_40ffc0 |
| sub_4014b0 | P1 | 643 | 2 | 0 | 0 | 3 | sub_401690, sub_408450 |
| sub_4015d0 | P1 | 643 | 2 | 0 | 0 | 3 | sub_401b00, sub_402040, sub_40a310 |
| sub_401120 | P1 | 627 | 2 | 0 | 0 | 7 | sub_401180, sub_40a320, sub_40a440 |
| sub_401610 | P1 | 621 | 2 | 0 | 0 | 1 | sub_401b10 |
| sub_403b40 | P2 | 372 | 3 | 1 | 2 | 2 | sub_403a90 |

Machine-readable queue: `GUIDES/decomp_runtime_parity_queue.csv`.

Recommendation: execute in strict order by `phase` then `priority_score`.
