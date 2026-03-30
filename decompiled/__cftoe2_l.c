int __usercall _cftoe2_l@<eax>(
        _BYTE *a1@<eax>,
        unsigned int a2,
        int a3,
        int a4,
        int a5,
        char a6,
        struct localeinfo_struct *a7)
{
  int *v8; // eax
  int v10; // eax
  _BYTE *v11; // esi
  int v12; // eax
  char *v13; // esi
  rsize_t v14; // ebx
  int v15; // eax
  int v16; // [esp-4h] [ebp-1Ch]
  int v17; // [esp+8h] [ebp-10h] BYREF
  int v18; // [esp+10h] [ebp-8h]
  char v19; // [esp+14h] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v17, a7);
  if ( !a1 || !a2 )
  {
    v8 = _errno();
    v16 = 22;
LABEL_3:
    *v8 = v16;
    _invalid_parameter_noinfo();
    if ( v19 )
      *(_DWORD *)(v18 + 112) &= ~2u;
    return v16;
  }
  if ( a3 <= 0 )
    v10 = 0;
  else
    v10 = a3;
  if ( a2 <= v10 + 9 )
  {
    v8 = _errno();
    v16 = 34;
    goto LABEL_3;
  }
  if ( a6 )
    _shift(&a1[*(_DWORD *)a5 == 45], a3 > 0);
  v11 = a1;
  if ( *(_DWORD *)a5 == 45 )
  {
    *a1 = 45;
    v11 = a1 + 1;
  }
  if ( a3 > 0 )
  {
    v12 = v17;
    *v11 = v11[1];
    *++v11 = ***(_BYTE ***)(v12 + 188);
  }
  v13 = &v11[a3 + (a6 == 0)];
  if ( a2 == -1 )
    v14 = -1;
  else
    v14 = a2 + a1 - v13;
  if ( strcpy_s(v13, v14, "e+000") )
    _invoke_watson(0, 0, 0, 0, 0);
  if ( a4 )
    *v13 = 69;
  if ( **(_BYTE **)(a5 + 12) != 48 )
  {
    v15 = *(_DWORD *)(a5 + 4) - 1;
    if ( v15 < 0 )
    {
      v15 = 1 - *(_DWORD *)(a5 + 4);
      v13[1] = 45;
    }
    if ( v15 >= 100 )
    {
      v13[2] += v15 / 100;
      v15 %= 100;
    }
    if ( v15 >= 10 )
    {
      v13[3] += v15 / 10;
      LOBYTE(v15) = v15 % 10;
    }
    v13[4] += v15;
  }
  if ( (byte_4D7CE0 & 1) != 0 && v13[2] == 48 )
    memcpy(v13 + 2, v13 + 3, 3u);
  if ( v19 )
    *(_DWORD *)(v18 + 112) &= ~2u;
  return 0;
}
