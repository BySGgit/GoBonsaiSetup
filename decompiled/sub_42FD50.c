int __userpurge sub_42FD50@<eax>(int a1@<eax>, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  _BYTE *v10; // esi
  int result; // eax
  int v12; // eax
  _DWORD *v13; // edi
  int v14; // eax
  int v15; // edx
  void (__thiscall *v16)(_BYTE *); // eax
  void (__thiscall *v17)(_BYTE *, int, int, _DWORD); // eax
  void (__thiscall *v18)(_BYTE *, int, int, _DWORD); // eax

  v10 = operator new(0x284u);
  if ( !v10 )
    return -2147024882;
  sub_432780(0, (int)v10);
  v10[600] = 0;
  *((_DWORD *)v10 + 13) = 0;
  v10[604] = 0;
  *(_DWORD *)v10 = &CDXUTRadioButton::`vftable';
  *((_DWORD *)v10 + 12) = 3;
  *((_DWORD *)v10 + 6) = a1;
  result = sub_4300A0(a1, v10);
  if ( result >= 0 )
  {
    v12 = *(_DWORD *)(a1 + 612);
    v13 = (_DWORD *)(a1 + 608);
    result = sub_42DBC0(v12 + 1, (int)v13);
    if ( result >= 0 )
    {
      *(_DWORD *)(*v13 + 4 * v13[1]++) = v10;
      *((_DWORD *)v10 + 11) = a2;
      sub_4328A0((int)v10, a4);
      *((_DWORD *)v10 + 160) = a3;
      v14 = *(_DWORD *)v10;
      *((_DWORD *)v10 + 2) = a5;
      *((_DWORD *)v10 + 3) = a6;
      (*(void (__thiscall **)(_BYTE *))(v14 + 76))(v10);
      v15 = *(_DWORD *)v10;
      *((_DWORD *)v10 + 4) = a7;
      v16 = *(void (__thiscall **)(_BYTE *))(v15 + 76);
      *((_DWORD *)v10 + 5) = a8;
      v16(v10);
      v17 = *(void (__thiscall **)(_BYTE *, int, int, _DWORD))(*(_DWORD *)v10 + 84);
      *((_DWORD *)v10 + 13) = 0;
      v17(v10, a9, 1, 0);
      v18 = *(void (__thiscall **)(_BYTE *, int, int, _DWORD))(*(_DWORD *)v10 + 84);
      v10[7] = 0;
      v18(v10, a9, 1, 0);
      return 0;
    }
  }
  return result;
}
