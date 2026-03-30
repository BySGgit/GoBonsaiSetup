int __userpurge sub_42FBA0@<eax>(int a1@<eax>, int a2, int a3, int a4, int a5, int a6, int a7, int a8, char a9)
{
  _DWORD *v10; // esi
  int result; // eax
  int v12; // eax
  _DWORD *v13; // edi
  int v14; // edx
  void (__thiscall *v15)(_DWORD *); // eax
  int v16; // eax

  v10 = operator new(0x25Cu);
  if ( !v10 )
    return -2147024882;
  sub_432780(0, (int)v10);
  *v10 = &CDXUTButton::`vftable';
  v10[12] = 0;
  v10[6] = a1;
  *((_BYTE *)v10 + 600) = 0;
  v10[13] = 0;
  result = sub_4300A0(a1, v10);
  if ( result >= 0 )
  {
    v12 = *(_DWORD *)(a1 + 612);
    v13 = (_DWORD *)(a1 + 608);
    result = sub_42DBC0(v12 + 1, (int)v13);
    if ( result >= 0 )
    {
      *(_DWORD *)(*v13 + 4 * v13[1]++) = v10;
      v10[11] = a2;
      sub_4328A0((int)v10, a3);
      v14 = *v10;
      v10[2] = a4;
      v15 = *(void (__thiscall **)(_DWORD *))(v14 + 76);
      v10[3] = a5;
      v15(v10);
      v16 = *v10;
      v10[4] = a6;
      v10[5] = a7;
      (*(void (__thiscall **)(_DWORD *))(v16 + 76))(v10);
      v10[13] = a8;
      *((_BYTE *)v10 + 7) = a9;
      return 0;
    }
  }
  return result;
}
