int __stdcall sub_444C00(char *a1, _WORD *a2, unsigned int a3)
{
  char *v4; // ebp
  unsigned int v6; // eax
  unsigned int v7; // edi
  char *v8; // eax
  unsigned int v9; // ecx
  _WORD *v10; // edx
  unsigned int v11; // esi
  char *v12; // ecx
  int v13; // eax
  char *v14; // [esp+18h] [ebp+Ch]

  v4 = a1;
  if ( !a3 )
    return 0;
  v6 = *((_DWORD *)a1 + 4);
  if ( v6 && a3 <= v6 )
  {
    v7 = 1 - a3 + v6;
    if ( *((_DWORD *)a1 + 5) < 8u )
      v8 = a1;
    else
      v8 = *(char **)a1;
    while ( 1 )
    {
      v14 = v8;
      v9 = v7;
      if ( !v7 )
        break;
      while ( *(_WORD *)v8 != *a2 )
      {
        v8 += 2;
        if ( !--v9 )
          return -1;
      }
      if ( !v8 )
        break;
      v10 = a2;
      v11 = a3;
      v12 = v8;
      if ( !a3 )
      {
LABEL_17:
        if ( *((_DWORD *)v4 + 5) < 8u )
          v13 = v8 - v4;
        else
          v13 = (int)&v8[-*(_DWORD *)v4];
        return v13 >> 1;
      }
      while ( *(_WORD *)v12 == *v10 )
      {
        v12 += 2;
        ++v10;
        if ( !--v11 )
          goto LABEL_16;
      }
      if ( (*(_WORD *)v12 < *v10 ? 0xFFFFFFFE : 0) == 0xFFFFFFFF )
      {
LABEL_16:
        v4 = a1;
        goto LABEL_17;
      }
      v4 = a1;
      v7 += -1 - ((v8 - v14) >> 1);
      v8 += 2;
    }
  }
  return -1;
}
