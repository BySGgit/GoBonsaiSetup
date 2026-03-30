int __stdcall sub_43C7D0(int *a1)
{
  int result; // eax
  int *v2; // ebp
  int v3; // ecx
  int v4; // eax
  int v5; // edx
  _DWORD *v6; // esi
  int v7; // eax
  int i; // edi
  void *v9; // eax
  int v10; // ebx
  int v11; // ebp
  int v12; // esi
  int v13; // ecx
  int v14; // edx
  _DWORD *v15; // eax
  int v16; // ecx
  int v17; // [esp+14h] [ebp-34h]
  int v18; // [esp+18h] [ebp-30h] BYREF
  unsigned int v19; // [esp+1Ch] [ebp-2Ch] BYREF
  int v20; // [esp+20h] [ebp-28h]
  int v21; // [esp+24h] [ebp-24h]
  int v22; // [esp+28h] [ebp-20h]
  _DWORD v23[7]; // [esp+2Ch] [ebp-1Ch] BYREF

  v17 = sub_43B220();
  if ( !v17 )
    return -2147467259;
  v2 = a1;
  sub_43DE70(a1, &v18, &v19);
  *(_DWORD *)dword_4D7E00 = v18;
  *(_DWORD *)Args = v19;
  v21 = dword_4D7E08;
  v3 = a1[157];
  v4 = 0;
  v22 = dword_4D7E0C;
  if ( v3 <= 0 )
  {
LABEL_8:
    v6 = 0;
  }
  else
  {
    v5 = a1[156];
    while ( 1 )
    {
      v6 = *(_DWORD **)v5;
      if ( *(_DWORD *)(*(_DWORD *)v5 + 44) == 32 && v6[12] == 4 )
        break;
      ++v4;
      v5 += 4;
      if ( v4 >= v3 )
        goto LABEL_8;
    }
  }
  v7 = v6[219];
  for ( i = 0; i < (unsigned int)v7; ++i )
  {
    if ( i < 0 || i >= v7 )
      v9 = 0;
    else
      v9 = *(void **)(*(_DWORD *)(v6[218] + 4 * i) + 512);
    operator delete(v9);
    v7 = v6[219];
  }
  sub_434340((int)v6);
  v10 = 0;
  v20 = dword_4D7E10;
  if ( *(int *)(v17 + 108) > 0 )
  {
    v11 = 0;
    do
    {
      qmemcpy(v23, (const void *)(v11 + *(_DWORD *)(v17 + 104)), sizeof(v23));
      if ( v23[4] == v20 && v23[0] == v18 && v23[1] == v19 )
        sub_43E020(a1, v23[2], v23[3]);
      ++v10;
      v11 += 28;
    }
    while ( v10 < *(_DWORD *)(v17 + 108) );
    v2 = a1;
  }
  sub_43EAB0(v2, v21, v22);
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
    v12 = v2[157];
    v13 = 0;
    if ( v12 <= 0 )
    {
LABEL_31:
      v15 = 0;
    }
    else
    {
      v14 = v2[156];
      while ( 1 )
      {
        v15 = *(_DWORD **)v14;
        if ( *(_DWORD *)(*(_DWORD *)v14 + 44) == 11 && v15[12] == 4 )
          break;
        ++v13;
        v14 += 4;
        if ( v13 >= v12 )
          goto LABEL_31;
      }
    }
    v16 = v15[151];
    if ( v16 < 0 )
    {
      *(_DWORD *)dword_4D7E34 = 0;
      return 0;
    }
    *(_DWORD *)dword_4D7E34 = *(_DWORD *)(*(_DWORD *)(v15[218] + 4 * v16) + 512);
  }
  return 0;
}
