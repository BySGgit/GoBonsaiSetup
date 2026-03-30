char __cdecl sub_42A020(_DWORD *a1, int a2, _DWORD *a3)
{
  _DWORD *v3; // ebp
  int v5; // eax
  int v6; // edi
  int v7; // ecx
  _DWORD *i; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  bool v12; // cc
  int v13; // eax
  char v14; // bl
  int v15; // esi
  _DWORD *v16; // ecx
  int v17; // edx
  int v18; // eax
  int v19; // eax
  char v20; // bl
  int v21; // esi
  _DWORD *v22; // ecx
  int v23; // edx
  int v24; // eax
  int v25; // eax
  int v26; // esi
  int v27; // ecx
  int j; // eax
  _DWORD *v29; // ecx
  int v30; // eax

  v3 = a1;
  if ( a3[1] == 1 && *a1 != *(_DWORD *)a2
    || a3[3] == 1 && a1[1] != *(_DWORD *)(a2 + 4)
    || a3[4] == 1 && a1[4] != *(_DWORD *)(a2 + 48)
    || a3[5] == 1 && a1[2] != *(_DWORD *)(a2 + 8)
    || a3[6] == 1 && (*(_BYTE *)(a2 + 12) & 0x40) != 0 && (*(_DWORD *)(a1[21] + 36) & 0x10000) == 0 )
  {
    return 0;
  }
  if ( a3[7] == 1 )
  {
    v5 = a1[20];
    v6 = *(_DWORD *)(v5 + 1620);
    v7 = 0;
    if ( v6 <= 0 )
      return 0;
    for ( i = *(_DWORD **)(v5 + 1616); i[3] != a1[2] || *i != *(_DWORD *)(a2 + 16) || i[1] != *(_DWORD *)(a2 + 20); i += 4 )
    {
      if ( ++v7 >= v6 )
        return 0;
    }
    v3 = a1;
  }
  if ( a3[8] == 1 && v3[3] != *(_DWORD *)(a2 + 24) )
    return 0;
  if ( a3[10] == 1 )
  {
    v9 = v3[9];
    v10 = 0;
    if ( v9 <= 0 )
      return 0;
    v11 = v3[8];
    while ( 1 )
    {
      if ( *(_DWORD *)(v11 + 4 * v10) == *(_DWORD *)(a2 + 32) )
      {
        v12 = *(_DWORD *)(v3[11] + 4 * v10) <= *(_DWORD *)(a2 + 36);
        v3 = a1;
        if ( !v12 )
          break;
      }
      if ( ++v10 >= v9 )
        return 0;
    }
  }
  if ( a3[12] == 1 )
  {
    if ( a3[13] == 1 && *(_DWORD *)(a2 + 56) && !sub_42D910(v3 + 5, (_DWORD *)(a2 + 56)) )
      return 0;
    v13 = *(_DWORD *)(a2 + 56);
    if ( v13 )
    {
      v14 = 0;
      switch ( v13 )
      {
        case 'F':
        case 'P':
          v15 = 16;
          break;
        case 'G':
        case 'R':
          v15 = 32;
          break;
        case 'I':
          v15 = 15;
          break;
        case 'K':
        case 'M':
        case 'O':
        case 'S':
          v15 = 24;
          break;
        default:
          v15 = 0;
          break;
      }
      if ( (int)v3[6] <= 0 )
        return 0;
      v16 = (_DWORD *)v3[5];
      v17 = v3[6];
      do
      {
        switch ( *v16 )
        {
          case 'F':
          case 'P':
            v18 = 16;
            break;
          case 'G':
          case 'R':
            v18 = 32;
            break;
          case 'I':
            v18 = 15;
            break;
          case 'K':
          case 'M':
          case 'O':
          case 'S':
            v18 = 24;
            break;
          default:
            v18 = 0;
            break;
        }
        if ( v18 == v15 )
          v14 = 1;
        ++v16;
        --v17;
      }
      while ( v17 );
      if ( !v14 )
        return 0;
    }
  }
  if ( a3[13] == 1 )
  {
    v19 = *(_DWORD *)(a2 + 56);
    if ( v19 )
    {
      v20 = 0;
      switch ( v19 )
      {
        case 'I':
          v21 = 1;
          break;
        case 'K':
        case 'S':
          v21 = 8;
          break;
        case 'O':
          v21 = 4;
          break;
        default:
          v21 = 0;
          break;
      }
      if ( (int)v3[6] <= 0 )
        return 0;
      v22 = (_DWORD *)v3[5];
      v23 = v3[6];
      do
      {
        switch ( *v22 )
        {
          case 'I':
            v24 = 1;
            break;
          case 'K':
          case 'S':
            v24 = 8;
            break;
          case 'O':
            v24 = 4;
            break;
          default:
            v24 = 0;
            break;
        }
        if ( v24 == v21 )
          v20 = 1;
        ++v22;
        --v23;
      }
      while ( v23 );
      if ( !v20 )
        return 0;
    }
  }
  if ( a3[15] == 1 )
  {
    v25 = v3[20];
    v26 = *(_DWORD *)(v25 + 1620);
    v27 = 0;
    if ( v26 <= 0 )
      return 0;
    for ( j = *(_DWORD *)(v25 + 1616); *(_DWORD *)(j + 12) != v3[2] || *(_DWORD *)(j + 8) != *(_DWORD *)(a2 + 64); j += 16 )
    {
      if ( ++v27 >= v26 )
        return 0;
    }
  }
  if ( a3[16] == 1 )
  {
    if ( (int)v3[15] <= 0 )
      return 0;
    v29 = (_DWORD *)v3[14];
    v30 = 0;
    while ( *(_DWORD *)(a2 + 68) != *v29 )
    {
      ++v30;
      ++v29;
      if ( v30 >= v3[15] )
        return 0;
    }
    if ( v30 == -1 )
      return 0;
  }
  return 1;
}
