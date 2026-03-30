int __stdcall sub_43C650(int *a1)
{
  _DWORD *v1; // eax
  int v2; // edx
  int v3; // ecx
  _DWORD *i; // eax
  _DWORD *v5; // edi
  int result; // eax
  int v7; // edx
  int v8; // eax
  int v9; // esi
  _DWORD *v10; // ebx
  int v11; // ebp
  int v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // [esp+14h] [ebp-14h] BYREF
  int v16; // [esp+18h] [ebp-10h] BYREF
  int v17; // [esp+1Ch] [ebp-Ch]
  _DWORD *v18; // [esp+20h] [ebp-8h]
  int v19; // [esp+24h] [ebp-4h]

  v1 = sub_428650();
  v2 = v1[23];
  v3 = 0;
  if ( v2 <= 0 )
    return -2147467259;
  for ( i = (_DWORD *)v1[22]; ; ++i )
  {
    v5 = (_DWORD *)*i;
    if ( *(_DWORD *)*i == dword_4D7DF4 )
      break;
    if ( ++v3 >= v2 )
      return -2147467259;
  }
  if ( !v5 )
    return -2147467259;
  sub_43DD40(a1, &v15, (unsigned int *)&v16);
  dword_4D7E08 = v16;
  *(_DWORD *)Args = v15;
  v7 = a1[157];
  v8 = 0;
  v19 = *(_DWORD *)dword_4D7E34;
  if ( v7 <= 0 )
  {
LABEL_13:
    v10 = 0;
    v18 = 0;
  }
  else
  {
    v9 = a1[156];
    while ( *(_DWORD *)(*(_DWORD *)v9 + 44) != 11 || *(_DWORD *)(*(_DWORD *)v9 + 48) != 4 )
    {
      ++v8;
      v9 += 4;
      if ( v8 >= v7 )
        goto LABEL_13;
    }
    v10 = *(_DWORD **)v9;
    v18 = *(_DWORD **)v9;
  }
  sub_434340((int)v10);
  v11 = dword_4D7DFC;
  v12 = 0;
  v17 = 0;
  if ( (int)v5[405] > 0 )
  {
    do
    {
      v13 = v5[404];
      v14 = *(_DWORD *)(v13 + v12);
      if ( *(_DWORD *)(v12 + v13 + 12) == v11 && v14 == v15 && *(_DWORD *)(v13 + v12 + 4) == v16 )
        sub_43DEF0(v14, (int)a1, *(_DWORD *)(v13 + v12 + 8));
      v12 += 16;
      ++v17;
    }
    while ( v17 < v5[405] );
    v10 = v18;
  }
  sub_4344D0(v10, v19);
  if ( dword_4D7DF0 )
  {
    result = dword_4D7DF0 - 1;
    if ( dword_4D7DF0 == 1 )
    {
      dword_4D7E08 = 0;
      dword_4D7E0C = 1;
      return result;
    }
  }
  else
  {
    *(_DWORD *)dword_4D7E34 = sub_43DFD0((int)a1);
  }
  return 0;
}
