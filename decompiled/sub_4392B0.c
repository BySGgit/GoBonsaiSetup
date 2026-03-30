int __stdcall sub_4392B0(int a1)
{
  _DWORD *EngineInstance; // esi
  _BYTE *v2; // esi
  int v3; // ecx
  int v4; // eax
  int v5; // esi
  _DWORD *v6; // edi
  _BYTE *v7; // esi
  int v8; // esi
  int v9; // eax
  int v10; // edx
  _DWORD *v11; // esi
  int result; // eax
  _DWORD *v13; // esi
  int v14; // eax
  int i; // esi
  int v16; // eax
  int v17; // esi
  int v18; // ecx
  int v19; // edx
  _DWORD *v20; // esi
  int v21; // esi
  int v22; // ecx
  int v23; // edx
  _DWORD *v24; // esi
  _DWORD *v25; // edi
  int j; // esi
  int v27; // eax
  char v28; // [esp+Fh] [ebp-C9h]
  _DWORD *v29; // [esp+10h] [ebp-C8h]
  _DWORD *v30; // [esp+10h] [ebp-C8h]
  _DWORD *v31; // [esp+14h] [ebp-C4h]
  float v32; // [esp+14h] [ebp-C4h]
  float v33; // [esp+14h] [ebp-C4h]
  _BYTE v34[96]; // [esp+18h] [ebp-C0h] BYREF
  _BYTE v35[96]; // [esp+78h] [ebp-60h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = (_BYTE *)EngineInstance[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v2 )
  {
    memset(v35, 0, sizeof(v35));
    v2 = v35;
  }
  qmemcpy(v34, v2, sizeof(v34));
  qmemcpy(&dword_4D7DF0, v34, 0x60u);
  v3 = *(_DWORD *)(a1 + 628);
  v4 = 0;
  if ( v3 <= 0 )
  {
LABEL_12:
    v6 = 0;
  }
  else
  {
    v5 = *(_DWORD *)(a1 + 624);
    while ( *(_DWORD *)(*(_DWORD *)v5 + 44) != 27 || *(_DWORD *)(*(_DWORD *)v5 + 48) != 4 )
    {
      ++v4;
      v5 += 4;
      if ( v4 >= v3 )
        goto LABEL_12;
    }
    v6 = *(_DWORD **)v5;
  }
  sub_434340((int)v6);
  if ( sub_41FD50() && *((int *)sub_428650() + 23) > 0 )
    sub_43D7E0((int *)a1, 0);
  if ( sub_41FE70() )
  {
    sub_41F640();
    v7 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v28 = v7[348];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v28 && *((int *)sub_42B3D0() + 15) > 0 )
    {
      v8 = *(_DWORD *)(a1 + 628);
      v9 = 0;
      if ( v8 <= 0 )
      {
LABEL_28:
        v11 = 0;
      }
      else
      {
        v10 = *(_DWORD *)(a1 + 624);
        while ( *(_DWORD *)(*(_DWORD *)v10 + 44) != 27 || *(_DWORD *)(*(_DWORD *)v10 + 48) != 4 )
        {
          ++v9;
          v10 += 4;
          if ( v9 >= v8 )
            goto LABEL_28;
        }
        v11 = *(_DWORD **)v10;
      }
      if ( sub_434450(v11, L"Direct3D 10") == -1 )
        sub_434240((int)L"Direct3D 10", v11, 1);
    }
  }
  if ( !v6[219] )
  {
    *(_BYTE *)(a1 + 1528) = 0;
    return 0;
  }
  sub_4344D0(v6, dword_4D7DF0);
  if ( dword_4D7DF0 )
  {
    if ( dword_4D7DF0 == 1 )
    {
      sub_439AA0(1, a1);
      v13 = sub_42B3D0();
      v29 = v13;
      sub_43E9B0((int *)a1, dword_4D7DF8);
      sub_43DAA0(a1, dword_4D7E30 != 0);
      v14 = sub_43B220();
      sub_43DC30((int *)a1, (const unsigned __int16 *)(v14 + 12), dword_4D7DFC);
      sub_43DDC0((int *)a1, *(int *)dword_4D7E00, *(int *)Args);
      sub_43E020((int *)a1, dword_4D7E08, dword_4D7E0C);
      sub_43E1D0((int *)a1, dword_4D7E10);
      sub_43E4C0((int *)a1, *(int *)dword_4D7E1C);
      sub_43E5A0((int *)a1, *(int *)dword_4D7E20);
      if ( sub_42C300((int)v13, dword_4D7DF4, dword_4D7E10, dword_4D7E30 != 0) )
      {
        if ( v13[15] )
        {
          v31 = (_DWORD *)sub_4374E0(a1 + 16, 3);
          sub_434340((int)v31);
          for ( i = 0; i < v29[15]; ++i )
          {
            v16 = *(_DWORD *)(v29[14] + 4 * i);
            sub_43D8D0((int *)a1, (const unsigned __int16 *)(v16 + 296), *(_DWORD *)v16);
          }
          sub_4344D0(v31, dword_4D7DF4);
          result = sub_43B270((int *)a1, 1);
          if ( result >= 0 )
          {
            v32 = sub_41B820();
            dbl_4D7F20 = v32;
            return 0;
          }
          return result;
        }
        return -2147219198;
      }
      return -2147024809;
    }
    return 0;
  }
  sub_439AA0(0, a1);
  v30 = sub_428650();
  sub_43D980((int *)a1, dword_4D7DF8);
  sub_43DAA0(a1, dword_4D7E24 != 0);
  sub_43E970(a1, (dword_4D7E30 & 4) != 0);
  sub_43DB80((int *)a1, dword_4D7DFC);
  sub_43DC90((int *)a1, *(int *)Args, dword_4D7E08);
  sub_43DEF0(*(int *)dword_4D7E34, a1, *(int *)dword_4D7E34);
  sub_43E120((int *)a1, dword_4D7E0C);
  sub_43E280((int *)a1, dword_4D7E2C);
  sub_43E330(a1, dword_4D7E14);
  sub_43E3E0((int *)a1, *(int *)dword_4D7E18);
  if ( (dword_4D7E00[0] & 0x10) != 0 )
  {
    sub_43E680(a1, 16);
  }
  else if ( (dword_4D7E00[0] & 0x40) != 0 )
  {
    v17 = *(_DWORD *)(a1 + 628);
    v18 = 0;
    if ( v17 <= 0 )
    {
LABEL_51:
      v20 = 0;
    }
    else
    {
      v19 = *(_DWORD *)(a1 + 624);
      while ( *(_DWORD *)(*(_DWORD *)v19 + 44) != 21 || *(_DWORD *)(*(_DWORD *)v19 + 48) != 4 )
      {
        ++v18;
        v19 += 4;
        if ( v18 >= v17 )
          goto LABEL_51;
      }
      v20 = *(_DWORD **)v19;
    }
    if ( sub_434450(v20, L"Hardware vertex processing") == -1 )
      sub_434240((int)L"Hardware vertex processing", v20, 64);
  }
  else if ( (dword_4D7E00[0] & 0x20) != 0 )
  {
    sub_43E680(a1, 32);
  }
  else if ( dword_4D7E00[0] < 0 )
  {
    v21 = *(_DWORD *)(a1 + 628);
    v22 = 0;
    if ( v21 <= 0 )
    {
LABEL_63:
      v24 = 0;
    }
    else
    {
      v23 = *(_DWORD *)(a1 + 624);
      while ( *(_DWORD *)(*(_DWORD *)v23 + 44) != 21 || *(_DWORD *)(*(_DWORD *)v23 + 48) != 4 )
      {
        ++v22;
        v23 += 4;
        if ( v22 >= v21 )
          goto LABEL_63;
      }
      v24 = *(_DWORD **)v23;
    }
    if ( sub_434450(v24, L"Mixed vertex processing") == -1 )
      sub_434240((int)L"Mixed vertex processing", v24, 128);
  }
  if ( !sub_429610(dword_4D7DF8, (int)v30, dword_4D7DF4, dword_4D7DFC, dword_4D7E0C, dword_4D7E24 != 0) )
    return -2147024809;
  if ( !v30[23] )
    return -2147219198;
  v25 = (_DWORD *)sub_4374E0(a1 + 16, 3);
  sub_434340((int)v25);
  for ( j = 0; j < v30[23]; ++j )
  {
    v27 = *(_DWORD *)(v30[22] + 4 * j);
    sub_43D8D0((int *)a1, (const unsigned __int16 *)(v27 + 1104), *(_DWORD *)v27);
  }
  sub_4344D0(v25, dword_4D7DF4);
  result = sub_43B270((int *)a1, 1);
  if ( result >= 0 )
  {
    v33 = sub_41B820();
    dbl_4D7F20 = v33;
    return 0;
  }
  return result;
}
