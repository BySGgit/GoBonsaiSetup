char __cdecl sub_42C970(_DWORD *a1, unsigned int *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  unsigned int *v4; // esi
  int v5; // ecx
  int v6; // ebx
  int v7; // eax
  char *i; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // ebx
  int v14; // edx
  char *v15; // ebp
  double v16; // st7
  unsigned int v17; // [esp+10h] [ebp-20h]
  _DWORD v18[7]; // [esp+14h] [ebp-1Ch] BYREF
  float v19; // [esp+3Ch] [ebp+Ch]
  float v20; // [esp+3Ch] [ebp+Ch]

  v3 = a3;
  v4 = a2;
  if ( a3[1] == 1 && *a1 != *a2
    || a3[3] == 1 && a1[1] != a2[1]
    || a3[4] == 1 && a1[3] != a2[15]
    || a3[2] == 1 && a1[4] != a2[2] )
  {
    return 0;
  }
  if ( a3[7] == 1 )
  {
    v5 = a1[13];
    v6 = *(_DWORD *)(v5 + 108);
    v7 = 0;
    if ( v6 <= 0 )
      return 0;
    v17 = a2[3];
    for ( i = *(char **)(v5 + 104); ; i += 28 )
    {
      qmemcpy(v18, i, sizeof(v18));
      if ( v18[0] == v17 )
      {
        v4 = a2;
        if ( v18[1] == a2[4] )
          break;
      }
      if ( ++v7 >= v6 )
        return 0;
    }
    v3 = a3;
  }
  if ( v3[8] == 1 && a1[2] != v4[7] )
    return 0;
  if ( v3[10] == 1 )
  {
    v10 = a1[6];
    v11 = 0;
    if ( v10 <= 0 )
      return 0;
    while ( *(_DWORD *)(a1[5] + 4 * v11) != v4[10] || *(_DWORD *)(a1[8] + 4 * v11) <= v4[11] )
    {
      if ( ++v11 >= v10 )
        return 0;
    }
    v3 = a3;
  }
  if ( v3[15] == 1 )
  {
    v12 = a1[13];
    v13 = *(_DWORD *)(v12 + 108);
    v14 = 0;
    if ( v13 <= 0 )
      return 0;
    v15 = *(char **)(v12 + 104);
    v16 = (double)v4[5] / (double)v4[6];
    while ( 1 )
    {
      qmemcpy(v18, v15, sizeof(v18));
      v19 = (double)v18[2] / (double)v18[3] - v16;
      v20 = fabs(v19);
      if ( v20 < 0.1000000014901161 )
        break;
      ++v14;
      v15 += 28;
      if ( v14 >= v13 )
        return 0;
    }
  }
  return 1;
}
