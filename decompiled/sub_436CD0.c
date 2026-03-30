char __userpurge sub_436CD0@<al>(int a1@<esi>, int a2, LPCWSTR lpString)
{
  int v5; // edi
  int v6; // eax
  int v7; // edx
  int v8; // eax
  LPCWSTR v9; // [esp+8h] [ebp+4h]

  if ( a2 < 0 )
    return 0;
  if ( a2 > lstrlenW(*(LPCWSTR *)a1) )
    return 0;
  v5 = lstrlenW(lpString);
  if ( v5 + lstrlenW(*(LPCWSTR *)a1) >= 0xFFFF )
    return 0;
  if ( v5 + lstrlenW(*(LPCWSTR *)a1) >= *(_DWORD *)(a1 + 4) )
  {
    v6 = lstrlenW(*(LPCWSTR *)a1);
    if ( !sub_436A80(v6 + v5 + 1, v7, a1) )
      return 0;
  }
  v9 = *(LPCWSTR *)a1;
  v8 = lstrlenW(*(LPCWSTR *)a1);
  memcpy((void *)&v9[v5 + a2], &v9[a2], 2 * (1 - a2 + v8));
  memcpy_0((void *)(2 * a2 + *(_DWORD *)a1), lpString, 2 * v5);
  *(_BYTE *)(a1 + 12) = 1;
  return 1;
}
