int __stdcall sub_42FF00(int a1, int a2)
{
  int v2; // edi
  void *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int result; // eax
  int v7; // eax
  _DWORD *v8; // edi
  int v9; // eax
  void (__thiscall *v10)(_DWORD *); // edx
  void (__thiscall *v11)(_DWORD *); // edx

  v2 = dword_4D7E54;
  v3 = operator new(0x7Cu);
  if ( !v3 )
    return -2147024882;
  v4 = (_DWORD *)sub_434540((int)v3, v2);
  v5 = v4;
  if ( !v4 )
    return -2147024882;
  result = sub_4300A0(v2, v4);
  if ( result >= 0 )
  {
    v7 = *(_DWORD *)(v2 + 612);
    v8 = (_DWORD *)(v2 + 608);
    result = sub_42DBC0(v7 + 1, (int)v8);
    if ( result >= 0 )
    {
      *(_DWORD *)(*v8 + 4 * v8[1]++) = v5;
      v9 = *v5;
      v5[11] = a1;
      v10 = *(void (__thiscall **)(_DWORD *))(v9 + 76);
      v5[2] = 0;
      v5[3] = 0;
      v10(v5);
      v11 = *(void (__thiscall **)(_DWORD *))(*v5 + 76);
      v5[4] = 0;
      v5[5] = 0;
      v11(v5);
      *((_BYTE *)v5 + 7) = 0;
      sub_4349C0(v5);
      sub_407B10(a2, v5);
      (*(void (__thiscall **)(_DWORD *))(*v5 + 76))(v5);
      return 0;
    }
  }
  return result;
}
