int __stdcall sub_43B5A0(int *a1)
{
  int v1; // esi
  int v2; // eax
  int v3; // edx
  _DWORD *v4; // ebx
  _DWORD *v5; // eax
  int v6; // edx
  int v7; // ecx
  _DWORD *i; // eax
  _DWORD *v9; // esi
  int result; // eax
  int j; // edi
  int v12; // esi
  int v13; // eax
  int v14; // edx
  _DWORD *v15; // ebx
  _DWORD *v16; // eax
  int v17; // edx
  int v18; // ecx
  _DWORD *k; // eax
  _DWORD *v20; // esi
  int m; // edi

  if ( dword_4D7DF0 )
  {
    if ( dword_4D7DF0 != 1 )
      return 0;
    dword_4D7DF4 = sub_43D930((int)a1);
    v1 = a1[157];
    v2 = 0;
    if ( v1 <= 0 )
    {
LABEL_8:
      v4 = 0;
    }
    else
    {
      v3 = a1[156];
      while ( *(_DWORD *)(*(_DWORD *)v3 + 44) != 4 || *(_DWORD *)(*(_DWORD *)v3 + 48) != 4 )
      {
        ++v2;
        v3 += 4;
        if ( v2 >= v1 )
          goto LABEL_8;
      }
      v4 = *(_DWORD **)v3;
    }
    sub_434340((int)v4);
    v5 = sub_42B3D0();
    v6 = v5[15];
    v7 = 0;
    if ( v6 > 0 )
    {
      for ( i = (_DWORD *)v5[14]; ; ++i )
      {
        v9 = (_DWORD *)*i;
        if ( *(_DWORD *)*i == dword_4D7DF4 )
          break;
        if ( ++v7 >= v6 )
          return -2147467259;
      }
      if ( v9 )
      {
        for ( j = 0; j < v9[143]; ++j )
          sub_43E9B0(a1, *(_DWORD *)(*(_DWORD *)(v9[142] + 4 * j) + 4));
        sub_4344D0(v4, dword_4D7DF8);
        result = sub_43B760(a1);
        if ( result < 0 )
          return result;
        return 0;
      }
    }
    return -2147467259;
  }
  dword_4D7DF4 = sub_43D930((int)a1);
  v12 = a1[157];
  v13 = 0;
  if ( v12 <= 0 )
  {
LABEL_25:
    v15 = 0;
  }
  else
  {
    v14 = a1[156];
    while ( *(_DWORD *)(*(_DWORD *)v14 + 44) != 4 || *(_DWORD *)(*(_DWORD *)v14 + 48) != 4 )
    {
      ++v13;
      v14 += 4;
      if ( v13 >= v12 )
        goto LABEL_25;
    }
    v15 = *(_DWORD **)v14;
  }
  sub_434340((int)v15);
  v16 = sub_428650();
  v17 = v16[23];
  v18 = 0;
  if ( v17 <= 0 )
    return -2147467259;
  for ( k = (_DWORD *)v16[22]; ; ++k )
  {
    v20 = (_DWORD *)*k;
    if ( *(_DWORD *)*k == dword_4D7DF4 )
      break;
    if ( ++v18 >= v17 )
      return -2147467259;
  }
  if ( !v20 )
    return -2147467259;
  for ( m = 0; m < v20[408]; ++m )
    sub_43D980(a1, *(_DWORD *)(*(_DWORD *)(v20[407] + 4 * m) + 4));
  sub_4344D0(v15, dword_4D7DF8);
  result = sub_43B760(a1);
  if ( result >= 0 )
    return 0;
  return result;
}
