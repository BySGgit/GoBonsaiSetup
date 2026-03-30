int __stdcall sub_4300A0(int a1, _DWORD *a2)
{
  int v4; // ecx
  int v5; // eax
  _DWORD *v6; // eax
  const void *v7; // esi
  unsigned int v8; // eax
  unsigned int v9; // ebx
  void *v10; // esi
  int v11; // eax
  int i; // [esp+4h] [ebp-8h]
  const void *v13; // [esp+8h] [ebp-4h]
  unsigned int v14; // [esp+14h] [ebp+8h]

  if ( !a2 )
    return -2147024809;
  v4 = a1;
  a2[7] = *(_DWORD *)(a1 + 612);
  v5 = 0;
  for ( i = 0; v5 < *(_DWORD *)(a1 + 624); i = v5 )
  {
    v6 = *(_DWORD **)(*(_DWORD *)(v4 + 620) + 4 * v5);
    if ( *v6 == a2[12] )
    {
      v7 = v6 + 2;
      v8 = v6[1];
      v13 = v7;
      v14 = v8;
      if ( v7 )
      {
        v9 = a2[9];
        if ( v9 > v8 )
        {
LABEL_11:
          qmemcpy(*(void **)(a2[8] + 4 * v8), v7, 0x6Cu);
        }
        else
        {
          while ( 1 )
          {
            v10 = operator new(0x6Cu);
            if ( !v10 )
              break;
            if ( sub_42DBC0(a2[9] + 1, (int)(a2 + 8)) < 0 )
            {
              operator delete(v10);
              break;
            }
            *(_DWORD *)(a2[8] + 4 * a2[9]++) = v10;
            if ( ++v9 > v14 )
            {
              v8 = v14;
              v7 = v13;
              goto LABEL_11;
            }
          }
        }
      }
    }
    v4 = a1;
    v5 = i + 1;
  }
  v11 = (*(int (__thiscall **)(_DWORD *))(*a2 + 4))(a2);
  return v11 >= 0 ? 0 : v11;
}
