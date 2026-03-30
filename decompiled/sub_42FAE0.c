int __userpurge sub_42FAE0@<eax>(int a1@<eax>, int a2, int a3, int a4, int a5, int a6, int a7, int *a8)
{
  void *v9; // esi
  int v10; // esi
  int result; // eax
  int v12; // eax
  _DWORD *v13; // edi
  int v14; // edx
  void (__thiscall *v15)(int); // eax
  int v16; // eax

  v9 = operator new(0x258u);
  if ( v9 )
    v10 = sub_432780(a1, (int)v9);
  else
    v10 = 0;
  if ( a8 )
    *a8 = v10;
  if ( !v10 )
    return -2147024882;
  result = sub_4300A0(a1, (_DWORD *)v10);
  if ( result >= 0 )
  {
    v12 = *(_DWORD *)(a1 + 612);
    v13 = (_DWORD *)(a1 + 608);
    result = sub_42DBC0(v12 + 1, (int)v13);
    if ( result >= 0 )
    {
      *(_DWORD *)(*v13 + 4 * v13[1]++) = v10;
      *(_DWORD *)(v10 + 44) = a2;
      sub_4328A0(v10, a3);
      v14 = *(_DWORD *)v10;
      *(_DWORD *)(v10 + 8) = a4;
      v15 = *(void (__thiscall **)(int))(v14 + 76);
      *(_DWORD *)(v10 + 12) = a5;
      v15(v10);
      v16 = *(_DWORD *)v10;
      *(_DWORD *)(v10 + 16) = a6;
      *(_DWORD *)(v10 + 20) = a7;
      (*(void (__thiscall **)(int))(v16 + 76))(v10);
      *(_BYTE *)(v10 + 7) = 0;
      return 0;
    }
  }
  return result;
}
