int __stdcall sub_401E70(int a1, float a2, float a3, float a4, float a5)
{
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // eax

  sub_401C10(a1, a2, a3, a4, a5);
  *(_DWORD *)a1 = &BonsaiCamera::`vftable';
  if ( (dword_4D7CF0 & 1) == 0 )
  {
    dword_4D7CF0 |= 1u;
    sub_402BC0();
  }
  *(_DWORD *)(a1 + 4) = 3;
  v5 = dword_4D82D8;
  v6 = dword_4D82DC;
  *(_DWORD *)(a1 + 364) = dword_4D82D4;
  *(_DWORD *)(a1 + 368) = v5;
  *(_DWORD *)(a1 + 372) = v6;
  *(float *)(a1 + 376) = 0.0;
  *(_BYTE *)(a1 + 420) = 0;
  *(_DWORD *)(a1 + 392) = dword_4D82D4;
  *(_DWORD *)(a1 + 396) = dword_4D82D8;
  *(_DWORD *)(a1 + 400) = dword_4D82DC;
  *(_DWORD *)(a1 + 404) = dword_4D82D4;
  *(_DWORD *)(a1 + 408) = dword_4D82D8;
  *(_DWORD *)(a1 + 412) = dword_4D82DC;
  *(float *)(a1 + 352) = 0.0;
  *(float *)(a1 + 356) = 0.0;
  *(float *)(a1 + 360) = 0.0;
  *(_BYTE *)(a1 + 388) = 0;
  *(_DWORD *)(a1 + 404) = dword_4D82D4;
  *(_DWORD *)(a1 + 408) = dword_4D82D8;
  v7 = dword_4D82DC;
  *(float *)(a1 + 416) = 0.78539819;
  *(float *)(a1 + 356) = 0.2;
  *(_DWORD *)(a1 + 412) = v7;
  *(float *)(a1 + 380) = 60.0;
  sub_402600((float *)a1);
  v8 = *(_DWORD *)(a1 + 352);
  v9 = *(_DWORD *)(a1 + 356);
  *(float *)(a1 + 384) = *(float *)(a1 + 380);
  v10 = *(_DWORD *)(a1 + 360);
  *(_DWORD *)(a1 + 212) = v8;
  *(_DWORD *)(a1 + 216) = v9;
  *(_DWORD *)(a1 + 220) = v10;
  return a1;
}
