int __usercall sub_435790@<eax>(const unsigned __int16 *a1@<eax>, int a2@<esi>)
{
  int v2; // eax
  int result; // eax
  const WCHAR *v4; // [esp-4h] [ebp-8h]

  sub_436D90((const void **)(a2 + 80), a1);
  v4 = *(const WCHAR **)(a2 + 80);
  *(_DWORD *)(a2 + 304) = 0;
  v2 = lstrlenW(v4);
  sub_435650(v2, (_DWORD *)a2);
  result = *(_DWORD *)(a2 + 292);
  *(_DWORD *)(a2 + 300) = result;
  return result;
}
