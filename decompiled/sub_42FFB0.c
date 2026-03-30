int __stdcall sub_42FFB0(int a1)
{
  int v1; // edi
  void *v2; // eax
  int v3; // esi
  int result; // eax
  int v5; // eax
  _DWORD *v6; // edi
  int v7; // eax
  void (__thiscall *v8)(int); // edx
  void (__thiscall *v9)(int); // edx

  v1 = dword_4D7E54;
  v2 = operator new(0x148u);
  if ( v2 )
    v3 = sub_435450((int)v2, v1);
  else
    v3 = 0;
  if ( !v3 )
    return -2147024882;
  result = sub_4300A0(v1, (_DWORD *)v3);
  if ( result >= 0 )
  {
    v5 = *(_DWORD *)(v1 + 612);
    v6 = (_DWORD *)(v1 + 608);
    result = sub_42DBC0(v5 + 1, (int)v6);
    if ( result >= 0 )
    {
      *(_DWORD *)(*v6 + 4 * v6[1]++) = v3;
      v7 = *(_DWORD *)v3;
      *(_DWORD *)(v3 + 44) = a1;
      v8 = *(void (__thiscall **)(int))(v7 + 76);
      *(_DWORD *)(v3 + 8) = 0;
      *(_DWORD *)(v3 + 12) = 0;
      v8(v3);
      v9 = *(void (__thiscall **)(int))(*(_DWORD *)v3 + 76);
      *(_DWORD *)(v3 + 16) = 0;
      *(_DWORD *)(v3 + 20) = 0;
      v9(v3);
      *(_BYTE *)(v3 + 7) = 0;
      sub_435790(word_4B765C, v3);
      return 0;
    }
  }
  return result;
}
