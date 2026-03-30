int __stdcall sub_43C070(int *a1)
{
  int v1; // edx
  int v2; // eax
  int v3; // esi
  int v4; // ecx
  unsigned __int8 v5; // cl
  int v6; // ebx
  int result; // eax
  _DWORD *v8; // eax
  int v9; // ecx
  int v10; // eax
  _DWORD *v11; // eax
  int v12; // edx
  int v13; // ecx
  _DWORD *i; // eax
  _DWORD *v15; // edi
  _DWORD *v16; // ebp
  int j; // esi
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // ecx
  _DWORD *v22; // esi
  int v23; // eax
  int k; // edi
  void *v25; // eax
  unsigned __int8 v26; // [esp+17h] [ebp-41h]
  int v27; // [esp+18h] [ebp-40h]
  int v28; // [esp+1Ch] [ebp-3Ch]
  _DWORD v29[5]; // [esp+28h] [ebp-30h] BYREF
  _DWORD v30[7]; // [esp+3Ch] [ebp-1Ch] BYREF

  v1 = a1[157];
  v2 = 0;
  if ( v1 <= 0 )
  {
LABEL_6:
    v4 = 0;
  }
  else
  {
    v3 = a1[156];
    while ( 1 )
    {
      v4 = *(_DWORD *)v3;
      if ( *(_DWORD *)(*(_DWORD *)v3 + 44) == 5 && *(_DWORD *)(v4 + 48) == 3 )
        break;
      ++v2;
      v3 += 4;
      if ( v2 >= v1 )
        goto LABEL_6;
    }
  }
  v5 = *(_BYTE *)(v4 + 604);
  v6 = v5;
  v26 = v5;
  dword_4D7E30 = v5;
  if ( v5 )
  {
    result = sub_42D830(v30, dword_4D7DF4, dword_4D7DFC);
    if ( result < 0 )
      return result;
    v8 = sub_41B790(v29);
    v9 = v8[2];
    v10 = v8[3];
    if ( v9 && v10 )
    {
      *(_DWORD *)dword_4D7E00 = v9;
    }
    else
    {
      v10 = v30[1];
      *(_DWORD *)dword_4D7E00 = v30[0];
    }
    *(_DWORD *)Args = v10;
    dword_4D7E08 = v30[2];
    dword_4D7E0C = v30[3];
  }
  v27 = dword_4D7E08;
  v28 = dword_4D7E0C;
  v11 = sub_42B3D0();
  v12 = v11[15];
  v13 = 0;
  if ( v12 <= 0 )
    return -2147467259;
  for ( i = (_DWORD *)v11[14]; ; ++i )
  {
    v15 = (_DWORD *)*i;
    if ( *(_DWORD *)*i == dword_4D7DF4 )
      break;
    if ( ++v13 >= v12 )
      return -2147467259;
  }
  if ( !v15 )
    return -2147467259;
  result = sub_43EB70(a1);
  if ( result >= 0 )
  {
    v16 = (_DWORD *)sub_4374E0((int)(a1 + 4), 34);
    sub_434340((int)v16);
    for ( j = 0; j < v15[146]; ++j )
    {
      v18 = *(_DWORD *)(v15[145] + 4 * j);
      if ( (*(_DWORD *)(v18 + 12) == 1) == v6 )
        sub_43E1D0(a1, *(_DWORD *)(v18 + 8));
    }
    sub_4344D0(v16, dword_4D7E10);
    result = sub_43CA00(a1);
    if ( result >= 0 )
    {
      if ( v26 )
      {
        v19 = a1[157];
        v20 = 0;
        if ( v19 <= 0 )
        {
LABEL_33:
          v22 = 0;
        }
        else
        {
          v21 = a1[156];
          while ( 1 )
          {
            v22 = *(_DWORD **)v21;
            if ( *(_DWORD *)(*(_DWORD *)v21 + 44) == 32 && v22[12] == 4 )
              break;
            ++v20;
            v21 += 4;
            if ( v20 >= v19 )
              goto LABEL_33;
          }
        }
        v23 = v22[219];
        for ( k = 0; k < (unsigned int)v23; ++k )
        {
          if ( k < 0 || k >= v23 )
            v25 = 0;
          else
            v25 = *(void **)(*(_DWORD *)(v22[218] + 4 * k) + 512);
          operator delete(v25);
          v23 = v22[219];
        }
        sub_434340((int)v22);
        sub_43E020(a1, v27, v28);
      }
      sub_43EAB0(a1, v27, v28);
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
  }
  return result;
}
