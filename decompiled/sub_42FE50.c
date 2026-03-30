int __stdcall sub_42FE50(int a1, int a2, int a3, int a4)
{
  void *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  int result; // eax
  int v8; // edx
  void (__thiscall *v9)(_DWORD *); // eax
  void (__thiscall *v10)(_DWORD *); // eax

  v4 = operator new(0x378u);
  if ( !v4 )
    return -2147024882;
  v5 = (_DWORD *)sub_4332C0((int)v4, a1);
  v6 = v5;
  if ( !v5 )
    return -2147024882;
  result = sub_4300A0(a1, v5);
  if ( result >= 0 )
  {
    result = sub_42DBC0(*(_DWORD *)(a1 + 612) + 1, a1 + 608);
    if ( result >= 0 )
    {
      *(_DWORD *)(*(_DWORD *)(a1 + 608) + 4 * (*(_DWORD *)(a1 + 612))++) = v6;
      v6[11] = a2;
      v8 = *v6;
      v6[3] = a3;
      v9 = *(void (__thiscall **)(_DWORD *))(v8 + 76);
      v6[2] = 200;
      v9(v6);
      v10 = *(void (__thiscall **)(_DWORD *))(*v6 + 76);
      v6[4] = a4;
      v6[5] = 23;
      v10(v6);
      v6[13] = 0;
      *((_BYTE *)v6 + 7) = 0;
      return 0;
    }
  }
  return result;
}
