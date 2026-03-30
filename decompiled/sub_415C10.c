int __stdcall sub_415C10(int a1, float a2)
{
  int v2; // esi
  int v3; // ebx
  int v4; // ecx
  int v6; // esi
  void *v7; // eax
  int v8; // esi
  _DWORD *v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // eax
  int v15; // edx
  double v16; // st7
  int v17; // [esp+8h] [ebp-4Ch]
  void *v18; // [esp+24h] [ebp-30h] BYREF
  int v19[3]; // [esp+28h] [ebp-2Ch] BYREF
  _DWORD v20[2]; // [esp+34h] [ebp-20h] BYREF
  int v21; // [esp+3Ch] [ebp-18h]
  int v22; // [esp+40h] [ebp-14h]
  int v23; // [esp+50h] [ebp-4h]

  v2 = *(_DWORD *)(a1 + 180);
  v3 = 0;
  if ( !v2 )
    goto LABEL_6;
  if ( (dword_4D7CF8 & 1) == 0 )
  {
    dword_4D7CF8 |= 1u;
    sub_4079C0();
    v23 = -1;
  }
  if ( byte_4D8225[11 * *(_DWORD *)(v2 + 4)] )
    v4 = v2;
  else
LABEL_6:
    v4 = 0;
  if ( *(_BYTE *)(dword_4D7EE8 + 220) && *(int *)(a1 + 516) > 2 && v4 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 44))(v4);
    return 0;
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 180);
    if ( v6 )
      sub_450C80((_DWORD *)a1, v6);
    v18 = (void *)rand();
    *(float *)v19 = (double)(int)v18 / 32767.0 * 0.1000000014901161 - 0.05000000074505806;
    *(float *)&v19[1] = 0.0;
    *(float *)&v19[2] = 0.0;
    *(float *)(a1 + 512) = *(float *)(a1 + 512) - 0.0;
    v7 = operator new(0x220u);
    v18 = v7;
    v23 = 1;
    if ( v7 )
      v3 = sub_417BB0((const void *)(a1 + 240), v6, (int)v7, a2, (int)v19);
    v23 = -1;
    *(float *)(v3 + 444) = flt_4D861C;
    v8 = *(_DWORD *)(v3 + 168);
    v17 = *(_DWORD *)(v8 + 4);
    v18 = (void *)a1;
    v9 = sub_40FD70((char *)v8, v17, &v18);
    v10 = *(_DWORD *)(v3 + 172);
    if ( v10 == 1073741822 )
      std::_Xlength_error("list<T> too long");
    *(_DWORD *)(v3 + 172) = v10 + 1;
    *(_DWORD *)(v8 + 4) = v9;
    *(_DWORD *)v9[1] = v9;
    *(_DWORD *)(a1 + 180) = v3;
    D3DXQuaternionMultiply(v20, v3 + 304, a1 + 304);
    v11 = v20[0];
    v12 = v20[1];
    v13 = v21;
    *(_DWORD *)(v3 + 304) = v20[0];
    *(_DWORD *)(v3 + 320) = v11;
    v14 = v21;
    *(_DWORD *)(v3 + 308) = v12;
    *(_DWORD *)(v3 + 312) = v13;
    v15 = v22;
    *(_DWORD *)(v3 + 324) = v12;
    *(_DWORD *)(v3 + 328) = v14;
    *(_DWORD *)(v3 + 316) = v15;
    *(_DWORD *)(v3 + 332) = v15;
    *(_DWORD *)(v3 + 416) = *(_DWORD *)(a1 + 416);
    *(float *)(v3 + 428) = *(float *)(a1 + 428);
    *(float *)(v3 + 420) = *(float *)(a1 + 420);
    v16 = *(float *)(a1 + 424);
    *(_BYTE *)(v3 + 512) = 1;
    *(float *)(v3 + 424) = v16;
    *(_DWORD *)(a1 + 304) = dword_4D53A4;
    *(_DWORD *)(a1 + 308) = dword_4D53A8;
    *(_DWORD *)(a1 + 312) = dword_4D53AC;
    *(_DWORD *)(a1 + 316) = dword_4D53B0;
    *(_DWORD *)(a1 + 320) = dword_4D53A4;
    *(_DWORD *)(a1 + 324) = dword_4D53A8;
    *(_DWORD *)(a1 + 328) = dword_4D53AC;
    *(_DWORD *)(a1 + 332) = dword_4D53B0;
    qmemcpy((void *)(a1 + 240), &unk_4D8BA8, 0x40u);
    *(float *)(v3 + 296) = 1.0;
    *(float *)(a1 + 296) = 1.0;
    sub_415AB0(a1, a2);
    return v3;
  }
}
