# Runtime Parity Queue (full decomp audit)

Generated: 2026-04-06T22:31:30

- Inputs: `decompiled/sub_*.c`, `GUIDES/decomp_master_manifest.csv`
- Total sub_* discovered: 1223
- Unmapped: 1062
- Runtime roots used: sub_40dc90, sub_4143e0, sub_416510, sub_417c90, sub_417ff0, sub_4188e0, sub_40e0a0, sub_40e230, sub_40e460, sub_40eee0, sub_40f140, sub_414ce0, sub_414e10, sub_408a30, sub_408d60

## Unmapped by phase

| phase | count |
| --- | ---: |
| P3-unreached | 1062 |

## Top 60 execution queue

| sub | phase | score | depth | mapped callers | mapped call sites | total call sites | sample callers |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| sub_42dbc0 | P3-unreached | 65 |  | 0 | 0 | 65 | sub_406d10, sub_428830, sub_428dd0, sub_429000, sub_429330, sub_4293c0, sub_4294f0, sub_429810 |
| sub_44bb00 | P3-unreached | 50 |  | 0 | 0 | 50 | sub_4458e0, sub_445bd0, sub_445d60, sub_445ee0, sub_446040, sub_4461a0, sub_446300, sub_446460 |
| sub_434240 | P3-unreached | 47 |  | 0 | 0 | 47 | sub_4392b0, sub_43b270, sub_43b930, sub_43ca00, sub_43cf10, sub_43d1b0, sub_43d7e0, sub_43d8d0 |
| sub_413df0 | P3-unreached | 46 |  | 1 | 1 | 1 | sub_4151b0 |
| sub_417bb0 | P3-unreached | 46 |  | 1 | 1 | 1 | sub_415c10 |
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
| sub_44dda0 | P3-unreached | 23 |  | 0 | 0 | 23 | sub_4426b0, sub_4428a0, sub_442ab0, sub_442ca0, sub_442e90, sub_443080, sub_443270, sub_443460 |
| sub_4250d0 | P3-unreached | 22 |  | 0 | 0 | 22 | sub_41d000, sub_41e880, sub_4224f0, sub_426190, sub_4268e0 |
| sub_437110 | P3-unreached | 22 |  | 0 | 0 | 22 | sub_431990, sub_432820, sub_432a80, sub_432f30, sub_433c90, sub_434a80, sub_4350d0, sub_4361b0 |
| sub_406ae0 | P3-unreached | 21 |  | 0 | 0 | 21 | sub_403c50 |
| sub_406c20 | P3-unreached | 21 |  | 0 | 0 | 21 | sub_471ec0, sub_471ed0, sub_471ee0, sub_471ef0, sub_471f00, sub_471f10, sub_471f20, sub_471f30 |
| sub_419310 | P3-unreached | 21 |  | 0 | 0 | 21 | sub_4245e0, sub_427400, sub_427750, sub_428830, sub_42b4f0, sub_436890, sub_43d1b0, sub_43dc90 |
| sub_428650 | P3-unreached | 20 |  | 0 | 0 | 20 | sub_41ff90, sub_426cb0, sub_427400, sub_427980, sub_4283d0, sub_429bf0, sub_4383e0, sub_4392b0 |
| sub_44a1d0 | P3-unreached | 20 |  | 0 | 0 | 20 | sub_447780, sub_447d10, sub_449180 |
| sub_42b3d0 | P3-unreached | 19 |  | 0 | 0 | 19 | sub_421960, sub_426c00, sub_426cb0, sub_426e40, sub_427400, sub_427cb0, sub_4283d0, sub_42c6b0 |
| sub_42fe50 | P3-unreached | 19 |  | 0 | 0 | 19 | sub_438b90 |
| sub_41cb10 | P3-unreached | 18 |  | 0 | 0 | 18 | sub_41c3d0 |
| sub_430950 | P3-unreached | 16 |  | 0 | 0 | 16 | sub_42e630, sub_432a80, sub_432f30, sub_433c90, sub_434a80, sub_4350d0, sub_4361b0 |
| sub_430c90 | P3-unreached | 16 |  | 0 | 0 | 16 | sub_42eb50, sub_432a80, sub_432f30, sub_433c90, sub_434a80, sub_4350d0, sub_4361b0 |
| sub_41b9c0 | P3-unreached | 15 |  | 0 | 0 | 15 | sub_41d000, sub_41e880, sub_4208d0, sub_4267b0, sub_4268e0, sub_427250, sub_43ac20 |
| sub_42fba0 | P3-unreached | 15 |  | 0 | 0 | 15 | sub_403c50, sub_438b90 |
| sub_4328a0 | P3-unreached | 15 |  | 0 | 0 | 15 | sub_404c10, sub_406d10, sub_42fae0, sub_42fba0, sub_42fc70, sub_42fd50, sub_43edc0 |
| sub_435650 | P3-unreached | 15 |  | 0 | 0 | 15 | sub_435790, sub_4357d0, sub_435a60, sub_435ae0, sub_435d40, sub_435f40, sub_4361b0, sub_436890 |
| sub_41e880 | P3-unreached | 14 |  | 0 | 0 | 14 | sub_41dd60, sub_41e0b0, sub_41e700, sub_4208d0, sub_422750, sub_425b80, sub_425e90, sub_4267b0 |
| sub_41f750 | P3-unreached | 13 |  | 0 | 0 | 13 | sub_41ba20, sub_41e880, sub_41ff90, sub_426c00, sub_426cb0, sub_427f30, sub_428830, sub_429bf0 |
| sub_43f5c0 | P3-unreached | 13 |  | 0 | 0 | 13 | sub_406400, sub_4417c0 |
| sub_447710 | P3-unreached | 13 |  | 0 | 0 | 13 | sub_444ff0, sub_446c70, sub_4473b0, sub_4490d0 |
| sub_4193d0 | P3-unreached | 12 |  | 0 | 0 | 12 | sub_4192d0, sub_427980, sub_427cb0, sub_42e630, sub_42eb50, sub_436890, sub_436d90, sub_43ef30 |
| sub_41b680 | P3-unreached | 12 |  | 0 | 0 | 12 | sub_41e880, sub_427250 |
| sub_428190 | P3-unreached | 12 |  | 0 | 0 | 12 | sub_419520, sub_41e880, sub_4208d0, sub_422750, sub_425b80, sub_425e90, sub_4268e0, sub_43ef30 |
| sub_434d20 | P3-unreached | 12 |  | 0 | 0 | 12 | sub_433400, sub_434c90, sub_434da0, sub_434e10, sub_435400, sub_437460 |
| sub_436b30 | P3-unreached | 12 |  | 0 | 0 | 12 | sub_435650, sub_4361b0, sub_436e90, sub_436ed0, sub_436f60, sub_436ff0 |
| sub_4256b0 | P3-unreached | 11 |  | 0 | 0 | 11 | sub_41e0b0, sub_41e700, sub_41e880, sub_4208d0, sub_421030, sub_422750, sub_422b80 |
| sub_42f300 | P3-unreached | 11 |  | 0 | 0 | 11 | sub_403c50, sub_431990, sub_438b90 |
| sub_44ab70 | P3-unreached | 11 |  | 0 | 0 | 11 | sub_440720 |
| sub_44dba0 | P3-unreached | 11 |  | 0 | 0 | 11 | sub_4426b0, sub_4428a0, sub_442ab0, sub_442ca0, sub_442e90, sub_443080, sub_443270, sub_44a8c0 |
| sub_44de80 | P3-unreached | 11 |  | 0 | 0 | 11 | sub_4426b0, sub_4428a0, sub_442ab0, sub_442ca0, sub_442e90, sub_443080, sub_443270, sub_44a8c0 |
| sub_4019f0 | P3-unreached | 10 |  | 0 | 0 | 10 | sub_401bf0, sub_401c90, sub_401cb0, sub_408850, sub_40d860, sub_410200, sub_412070, sub_412080 |
| sub_41b4e0 | P3-unreached | 10 |  | 0 | 0 | 10 | sub_41e880 |
| sub_41b510 | P3-unreached | 10 |  | 0 | 0 | 10 | sub_41d000, sub_41f5a0, sub_41ff90, sub_4208d0, sub_427250 |
| sub_41cb90 | P3-unreached | 10 |  | 0 | 0 | 10 | sub_41c3d0 |
| sub_431020 | P3-unreached | 10 |  | 0 | 0 | 10 | sub_42e630, sub_432820, sub_432a80, sub_432f30, sub_433c90, sub_4361b0 |
| sub_434a20 | P3-unreached | 10 |  | 0 | 0 | 10 | sub_4346f0, sub_434800 |
| sub_4374e0 | P3-unreached | 10 |  | 0 | 0 | 10 | sub_4392b0, sub_43b930, sub_43c070, sub_43ca00 |
| sub_4375d0 | P3-unreached | 10 |  | 0 | 0 | 10 | sub_41c130, sub_4208d0, sub_422750, sub_4250d0, sub_435450, sub_435ee0, sub_4361b0, sub_4370c0 |
| sub_437720 | P3-unreached | 10 |  | 0 | 0 | 10 | sub_427400, sub_43db80, sub_43e120, sub_43e280 |
| sub_443d30 | P3-unreached | 10 |  | 0 | 0 | 10 | sub_440720 |
| sub_44a8c0 | P3-unreached | 10 |  | 0 | 0 | 10 | sub_440720 |
| sub_4192d0 | P3-unreached | 9 |  | 0 | 0 | 9 | sub_427980, sub_427cb0 |
| sub_4283d0 | P3-unreached | 9 |  | 0 | 0 | 9 | sub_41e0b0, sub_41e700, sub_4208d0, sub_425b80, sub_425e90, sub_4268e0, sub_426f10, sub_43b270 |

Machine-readable queue: `GUIDES/decomp_runtime_parity_queue.csv`.

Recommendation: execute in strict order by `phase` then `priority_score`.
