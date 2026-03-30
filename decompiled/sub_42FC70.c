int __userpurge sub_42FC70@<eax>(int a1@<eax>, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _BYTE *v9; // esi
  int result; // eax
  int v11; // eax
  _DWORD *v12; // edi
  int v13; // edx
  void (__thiscall *v14)(_BYTE *); // eax
  int v15; // eax
  int v16; // edx
  void (__thiscall *v17)(_BYTE *, _DWORD, _DWORD); // eax

  v9 = operator new(0x280u);
  if ( !v9 )
    return -2147024882;
  sub_432780(0, (int)v9);
  v9[600] = 0;
  *((_DWORD *)v9 + 13) = 0;
  *(_DWORD *)v9 = &CDXUTCheckBox::`vftable';
  *((_DWORD *)v9 + 12) = 2;
  *((_DWORD *)v9 + 6) = a1;
  v9[604] = 0;
  result = sub_4300A0(a1, v9);
  if ( result >= 0 )
  {
    v11 = *(_DWORD *)(a1 + 612);
    v12 = (_DWORD *)(a1 + 608);
    result = sub_42DBC0(v11 + 1, (int)v12);
    if ( result >= 0 )
    {
      *(_DWORD *)(*v12 + 4 * v12[1]++) = v9;
      *((_DWORD *)v9 + 11) = a2;
      sub_4328A0((int)v9, a3);
      v13 = *(_DWORD *)v9;
      *((_DWORD *)v9 + 2) = a4;
      v14 = *(void (__thiscall **)(_BYTE *))(v13 + 76);
      *((_DWORD *)v9 + 3) = a5;
      v14(v9);
      v15 = *(_DWORD *)v9;
      *((_DWORD *)v9 + 4) = a6;
      *((_DWORD *)v9 + 5) = a7;
      (*(void (__thiscall **)(_BYTE *))(v15 + 76))(v9);
      v16 = *(_DWORD *)v9;
      *((_DWORD *)v9 + 13) = a8;
      v17 = *(void (__thiscall **)(_BYTE *, _DWORD, _DWORD))(v16 + 80);
      v9[7] = 0;
      v17(v9, 0, 0);
      return 0;
    }
  }
  return result;
}
