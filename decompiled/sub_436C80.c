char __userpurge sub_436C80@<al>(int a1@<esi>, int a2)
{
  int v2; // edi
  int v3; // eax

  if ( !lstrlenW(*(LPCWSTR *)a1) || a2 < 0 || a2 >= lstrlenW(*(LPCWSTR *)a1) )
    return 0;
  v2 = *(_DWORD *)a1 + 2 * a2;
  v3 = lstrlenW(*(LPCWSTR *)a1);
  memcpy((void *)v2, (const void *)(v2 + 2), 2 * (v3 - a2));
  *(_BYTE *)(a1 + 12) = 1;
  return 1;
}
