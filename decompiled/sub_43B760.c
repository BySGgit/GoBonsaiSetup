int __stdcall sub_43B760(int *a1)
{
  int *v1; // ebp
  int v2; // esi
  int v3; // eax
  _DWORD *v4; // edx
  int v5; // esi
  int v6; // eax
  _DWORD *v7; // edx
  int result; // eax
  char v9; // bl
  void *v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // esi
  int v15; // eax
  _DWORD *v16; // edx
  int v17; // esi
  int v18; // eax
  _DWORD *v19; // edx
  char v20; // [esp+14h] [ebp-4h]

  v1 = a1;
  if ( dword_4D7DF0 )
  {
    if ( dword_4D7DF0 == 1 )
    {
      dword_4D7DF8 = sub_43DA40((int)a1);
      v2 = a1[157];
      v3 = 0;
      if ( v2 > 0 )
      {
        v4 = (_DWORD *)a1[156];
        while ( *(_DWORD *)(*v4 + 44) != 5 )
        {
          ++v3;
          ++v4;
          if ( v3 >= v2 )
            goto LABEL_9;
        }
        (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)*v4 + 56))(*v4, 1);
      }
LABEL_9:
      v5 = a1[157];
      v6 = 0;
      if ( v5 > 0 )
      {
        v7 = (_DWORD *)a1[156];
        while ( *(_DWORD *)(*v7 + 44) != 6 )
        {
          ++v6;
          ++v7;
          if ( v6 >= v5 )
            goto LABEL_15;
        }
        (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)*v7 + 56))(*v7, 1);
      }
LABEL_15:
      sub_43DAA0((int)a1, dword_4D7E30 != 0);
      result = sub_43B930(a1);
      if ( result < 0 )
        return result;
    }
    return 0;
  }
  v9 = 0;
  dword_4D7DF8 = sub_43DA40((int)a1);
  LOBYTE(a1) = 0;
  v20 = 0;
  v10 = sub_428650();
  v11 = sub_4295B0((int)v10, dword_4D7DF4, dword_4D7DF8);
  if ( !v11 )
    return -2147467259;
  v12 = *(_DWORD *)(v11 + 316);
  if ( v12 > 0 )
  {
    v13 = *(_DWORD *)(v11 + 312);
    do
    {
      if ( *(_DWORD *)(*(_DWORD *)v13 + 16) )
        v9 = 1;
      else
        v20 = 1;
      v13 += 4;
      --v12;
    }
    while ( v12 );
    LOBYTE(a1) = v9;
  }
  v14 = v1[157];
  v15 = 0;
  if ( v14 > 0 )
  {
    v16 = (_DWORD *)v1[156];
    while ( *(_DWORD *)(*v16 + 44) != 5 )
    {
      ++v15;
      ++v16;
      if ( v15 >= v14 )
        goto LABEL_32;
    }
    (*(void (__thiscall **)(_DWORD, int *))(*(_DWORD *)*v16 + 56))(*v16, a1);
  }
LABEL_32:
  v17 = v1[157];
  v18 = 0;
  if ( v17 > 0 )
  {
    v19 = (_DWORD *)v1[156];
    while ( *(_DWORD *)(*v19 + 44) != 6 )
    {
      ++v18;
      ++v19;
      if ( v18 >= v17 )
        goto LABEL_38;
    }
    v18 = (*(int (__thiscall **)(_DWORD, char))(*(_DWORD *)*v19 + 56))(*v19, v20);
  }
LABEL_38:
  LOBYTE(v18) = dword_4D7E24 && v9;
  sub_43DAA0((int)v1, v18);
  result = sub_43B930(v1);
  if ( result >= 0 )
    return 0;
  return result;
}
