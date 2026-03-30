int __userpurge sub_434240@<eax>(int a1@<eax>, _DWORD *a2, int a3)
{
  _WORD *v5; // eax
  _WORD *v6; // esi
  int v7; // edx
  _WORD *v8; // eax
  int v9; // edi
  __int16 v10; // cx
  int v11; // eax
  void (__stdcall *v12)(int, _DWORD, _DWORD *, _DWORD); // ecx

  if ( !a1 )
    return -2147024809;
  v5 = operator new(0x218u);
  v6 = v5;
  if ( !v5 )
    return -2147024882;
  memset(v5, 0, 0x218u);
  v7 = 256;
  v8 = v6;
  v9 = a1 - (_DWORD)v6;
  while ( v7 != -2147483390 )
  {
    v10 = *(_WORD *)((char *)v8 + v9);
    if ( !v10 )
      break;
    *v8++ = v10;
    if ( !--v7 )
    {
      --v8;
      break;
    }
  }
  *v8 = 0;
  *((_DWORD *)v6 + 128) = a3;
  if ( sub_42DBC0(a2[219] + 1, (int)(a2 + 218)) >= 0 )
    *(_DWORD *)(a2[218] + 4 * a2[219]++) = v6;
  sub_435400((int)(a2 + 154), a2[219]);
  if ( a2[219] == 1 )
  {
    v11 = a2[6];
    a2[151] = 0;
    a2[152] = 0;
    v12 = *(void (__stdcall **)(int, _DWORD, _DWORD *, _DWORD))(v11 + 576);
    if ( v12 )
    {
      if ( *(_BYTE *)v11 )
        v12(513, a2[11], a2, *(_DWORD *)(v11 + 580));
    }
  }
  return 0;
}
