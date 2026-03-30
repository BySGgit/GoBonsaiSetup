int __userpurge sub_42FA10@<eax>(int a1@<eax>, int a2, int a3, const void *a4)
{
  int v4; // ecx
  int v6; // eax
  _DWORD *v7; // edi
  _DWORD *v8; // edx
  _DWORD *v9; // ebx
  int v11; // eax
  int v12; // esi

  v4 = *(_DWORD *)(a2 + 624);
  v6 = 0;
  if ( v4 <= 0 )
  {
LABEL_6:
    v9 = operator new(0x74u);
    if ( v9 )
    {
      *v9 = a1;
      v9[1] = a3;
      qmemcpy(v9 + 2, a4, 0x6Cu);
      v11 = sub_42DBC0(*(_DWORD *)(a2 + 624) + 1, a2 + 620);
      if ( v11 >= 0 )
      {
        *(_DWORD *)(*(_DWORD *)(a2 + 620) + 4 * (*(_DWORD *)(a2 + 624))++) = v9;
        return 0;
      }
      else
      {
        v12 = v11;
        operator delete(v9);
        return v12;
      }
    }
    else
    {
      return -2147024882;
    }
  }
  else
  {
    v7 = *(_DWORD **)(a2 + 620);
    while ( 1 )
    {
      v8 = (_DWORD *)*v7;
      if ( *(_DWORD *)*v7 == a1 && v8[1] == a3 )
        break;
      ++v6;
      ++v7;
      if ( v6 >= v4 )
        goto LABEL_6;
    }
    qmemcpy(v8 + 2, a4, 0x6Cu);
    return 0;
  }
}
