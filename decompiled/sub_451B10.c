int __usercall sub_451B10@<eax>(int a1@<eax>, int a2, int a3, _DWORD *a4, unsigned __int8 (__cdecl *a5)(int, int))
{
  int v6; // edi
  int v7; // esi
  bool i; // zf
  _DWORD *v9; // eax
  _DWORD *v10; // ecx
  _DWORD *v11; // eax
  _DWORD *v12; // ecx
  int v13; // esi
  int j; // ebp
  _DWORD *v15; // edi
  _DWORD *v16; // eax
  _DWORD *v17; // ebx
  int result; // eax

  v6 = a1;
  v7 = 2 * a1 + 2;
  for ( i = v7 == a3; v7 < a3; i = v7 == a3 )
  {
    if ( a5(a2 + 12 * v7, a2 + 12 * v7 - 12) )
      --v7;
    v9 = (_DWORD *)(a2 + 12 * v7);
    v10 = (_DWORD *)(a2 + 12 * v6);
    *v10 = *v9;
    v10[1] = v9[1];
    v6 = v7;
    v7 = 2 * v7 + 2;
    v10[2] = v9[2];
  }
  if ( i )
  {
    v11 = (_DWORD *)(a2 + 12 * a3 - 12);
    v12 = (_DWORD *)(a2 + 12 * v6);
    *v12 = *v11;
    v12[1] = v11[1];
    v12[2] = v11[2];
    v6 = a3 - 1;
  }
  v13 = (v6 - 1) / 2;
  for ( j = v6; a1 < j; v13 = (v13 - 1) / 2 )
  {
    v15 = (_DWORD *)(a2 + 12 * v13);
    if ( !a5((int)v15, (int)a4) )
      break;
    v16 = (_DWORD *)(a2 + 12 * j);
    *v16 = *v15;
    v16[1] = v15[1];
    v16[2] = v15[2];
    j = v13;
  }
  v17 = (_DWORD *)(a2 + 12 * j);
  *v17 = *a4;
  v17[1] = a4[1];
  result = a4[2];
  v17[2] = result;
  return result;
}
