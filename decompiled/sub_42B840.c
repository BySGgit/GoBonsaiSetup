int __stdcall sub_42B840(int a1, _DWORD *a2)
{
  _DWORD *v2; // edi
  int v3; // eax
  int v4; // ebx
  int result; // eax
  _DWORD *v6; // eax
  int v7; // esi
  int v8; // eax
  _DWORD *v9; // edi
  int v10; // eax
  int v11; // [esp+14h] [ebp-8h] BYREF
  int v12; // [esp+18h] [ebp-4h]

  v2 = a2;
  v3 = a2[138];
  v11 = 0;
  v4 = 0;
  result = (*(int (__stdcall **)(int, _DWORD, int *))(*(_DWORD *)v3 + 28))(v3, 0, &v11);
  if ( result == -2005270526 )
    return 0;
  while ( result >= 0 )
  {
    v6 = operator new(0x74u);
    v7 = (int)v6;
    if ( !v6 )
    {
      if ( v11 )
        (*(void (__stdcall **)(int))(*(_DWORD *)v11 + 8))(v11);
      return -2147024882;
    }
    v6[26] = 0;
    v6[27] = 0;
    v6[28] = 0;
    memset(v6, 0, 0x74u);
    (*(void (__stdcall **)(int, int))(*(_DWORD *)v11 + 28))(v11, v7 + 12);
    *(_DWORD *)(v7 + 4) = v4;
    *(_DWORD *)(v7 + 8) = v11;
    sub_42B980((char *)v7, a1);
    if ( *(int *)(v7 + 108) > 0 )
    {
      v8 = v2[140];
      v9 = v2 + 139;
      v12 = sub_42DBC0(v8 + 1, (int)v9);
      if ( v12 < 0 )
      {
        sub_42C360(v7);
        operator delete((void *)v7);
        return v12;
      }
      *(_DWORD *)(*v9 + 4 * v9[1]++) = v7;
      v2 = a2;
    }
    else
    {
      sub_42C360(v7);
      operator delete((void *)v7);
    }
    v10 = v2[138];
    ++v4;
    v11 = 0;
    result = (*(int (__stdcall **)(int, int, int *))(*(_DWORD *)v10 + 28))(v10, v4, &v11);
    if ( result == -2005270526 )
      return 0;
  }
  return result;
}
