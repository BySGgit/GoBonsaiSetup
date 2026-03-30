int __stdcall sub_43C2F0(int *a1)
{
  int *v1; // ebx
  int v2; // esi
  int v3; // eax
  int *v4; // edx
  _DWORD *v5; // eax
  int v6; // edx
  int v7; // ecx
  _DWORD *i; // eax
  _DWORD *v9; // esi
  int result; // eax
  int v11; // edi
  int v12; // ecx
  int v13; // edx
  int v14; // eax
  int v15; // ebp
  int v16; // edi
  int v17; // eax
  DWORD v18; // ebx
  int v19; // ecx
  int v20; // edx
  int v21; // eax
  int v22; // esi
  int v23; // ecx
  int *v24; // edx
  void *v25; // eax
  int v26; // esi
  unsigned __int8 v27; // al
  int v28; // edi
  char v29; // bl
  int j; // ebp
  _DWORD *v31; // eax
  int v32; // esi
  int v33; // eax
  _DWORD *v34; // edx
  char v35; // [esp+13h] [ebp-1Dh]
  _DWORD *v36; // [esp+14h] [ebp-1Ch]
  _DWORD *v37; // [esp+14h] [ebp-1Ch]
  float v38; // [esp+18h] [ebp-18h]
  float v39; // [esp+1Ch] [ebp-14h]
  float v40; // [esp+1Ch] [ebp-14h]
  float v41; // [esp+1Ch] [ebp-14h]
  DWORD v42; // [esp+20h] [ebp-10h] BYREF
  DWORD v43[3]; // [esp+24h] [ebp-Ch] BYREF

  if ( dword_4D7DF0 )
    return 0;
  v1 = a1;
  dword_4D7DFC = sub_43DBE0((int)a1);
  v2 = a1[157];
  v3 = 0;
  if ( v2 <= 0 )
  {
LABEL_7:
    v36 = 0;
    sub_434340(0);
  }
  else
  {
    v4 = (int *)a1[156];
    while ( *(_DWORD *)(*v4 + 44) != 9 || *(_DWORD *)(*v4 + 48) != 4 )
    {
      ++v3;
      ++v4;
      if ( v3 >= v2 )
        goto LABEL_7;
    }
    v36 = (_DWORD *)*v4;
    sub_434340(*v4);
  }
  v5 = sub_428650();
  v6 = v5[23];
  v7 = 0;
  if ( v6 <= 0 )
    return -2147467259;
  for ( i = (_DWORD *)v5[22]; ; ++i )
  {
    v9 = (_DWORD *)*i;
    if ( *(_DWORD *)*i == dword_4D7DF4 )
      break;
    if ( ++v7 >= v6 )
      return -2147467259;
  }
  if ( !v9 )
    return -2147467259;
  v11 = a1[157];
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_22:
    v14 = 0;
  }
  else
  {
    v13 = a1[156];
    while ( 1 )
    {
      v14 = *(_DWORD *)v13;
      if ( *(_DWORD *)(*(_DWORD *)v13 + 44) == 26 && *(_DWORD *)(v14 + 48) == 2 )
        break;
      ++v12;
      v13 += 4;
      if ( v12 >= v11 )
      {
        v1 = a1;
        goto LABEL_22;
      }
    }
    v1 = a1;
  }
  v35 = *(_BYTE *)(v14 + 604);
  sub_4383E0(dword_4D7DF4, &v42, v43);
  v15 = 0;
  v38 = (double)v42 / (double)v43[0];
  if ( (int)v9[405] > 0 )
  {
    v16 = 0;
    do
    {
      v17 = v9[404];
      v18 = *(_DWORD *)(v17 + v16 + 8);
      v19 = *(_DWORD *)(v17 + v16);
      v20 = *(_DWORD *)(v17 + v16 + 4);
      v21 = *(_DWORD *)(v16 + v17 + 12);
      v43[1] = v18;
      if ( v21 == dword_4D7DFC )
      {
        if ( v35
          || (v39 = (double)(unsigned int)v19 / (double)(unsigned int)v20,
              v40 = v38 - v39,
              v41 = fabs(v40),
              v41 < 0.05000000074505806) )
        {
          sub_43DC90(a1, v19, v20);
        }
      }
      ++v15;
      v16 += 16;
    }
    while ( v15 < v9[405] );
    v1 = a1;
  }
  sub_4344D0(v36, *(unsigned __int16 *)Args | ((unsigned __int16)dword_4D7E08 << 16));
  result = sub_43C650(v1);
  if ( result >= 0 )
  {
    v22 = v1[157];
    v23 = 0;
    if ( v22 <= 0 )
    {
LABEL_37:
      v37 = 0;
      sub_434340(0);
    }
    else
    {
      v24 = (int *)v1[156];
      while ( *(_DWORD *)(*v24 + 44) != 13 || *(_DWORD *)(*v24 + 48) != 4 )
      {
        ++v23;
        ++v24;
        if ( v23 >= v22 )
          goto LABEL_37;
      }
      v37 = (_DWORD *)*v24;
      sub_434340(*v24);
    }
    v25 = sub_428650();
    v26 = sub_4295B0((int)v25, dword_4D7DF4, dword_4D7DF8);
    if ( !v26 )
      return -2147467259;
    v27 = sub_43DB40((int)v1);
    v28 = 0;
    v29 = 0;
    for ( j = v27; v28 < *(_DWORD *)(v26 + 316); ++v28 )
    {
      v31 = *(_DWORD **)(*(_DWORD *)(v26 + 312) + 4 * v28);
      if ( v31[4] == j && v31[2] == dword_4D7DFC )
      {
        sub_43E120(a1, v31[3]);
        v29 = 1;
      }
    }
    sub_4344D0(v37, dword_4D7E0C);
    result = sub_43CA00(a1);
    if ( result >= 0 )
    {
      if ( v29 )
        return 0;
      v32 = a1[157];
      v33 = 0;
      if ( v32 > 0 )
      {
        v34 = (_DWORD *)a1[156];
        while ( *(_DWORD *)(*v34 + 44) != 5 )
        {
          ++v33;
          ++v34;
          if ( v33 >= v32 )
            goto LABEL_54;
        }
        (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)*v34 + 56))(*v34, 0);
      }
LABEL_54:
      if ( !dword_4D7E24 )
        return 0;
      sub_43DAA0((int)a1, 0);
      result = sub_43B930(a1);
      if ( result >= 0 )
        return 0;
    }
  }
  return result;
}
