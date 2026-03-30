char __userpurge sub_436C00@<al>(int a1@<esi>, int a2, __int16 a3)
{
  int v3; // edx
  LPCWSTR v4; // edi
  WCHAR *v5; // eax
  const WCHAR *v6; // edx
  WCHAR *i; // ecx

  if ( a2 < 0
    || a2 > lstrlenW(*(LPCWSTR *)a1)
    || lstrlenW(*(LPCWSTR *)a1) + 1 >= 0xFFFF
    || lstrlenW(*(LPCWSTR *)a1) + 1 >= *(_DWORD *)(a1 + 4) && !sub_436A80(-1, v3, a1) )
  {
    return 0;
  }
  v4 = *(LPCWSTR *)a1;
  v5 = (WCHAR *)&v4[lstrlenW(*(LPCWSTR *)a1) + 1];
  v6 = &v4[a2];
  for ( i = v5 - 1; v5 > v6; --i )
    *v5-- = *i;
  *(_WORD *)(*(_DWORD *)a1 + 2 * a2) = a3;
  *(_BYTE *)(a1 + 12) = 1;
  return 1;
}
