void *__usercall sub_4357D0@<eax>(int a1@<esi>)
{
  int v1; // eax
  int v2; // ebx
  int v3; // edi
  void *result; // eax
  WCHAR *v5; // ebp
  int v6; // eax
  const WCHAR *v7; // [esp-8h] [ebp-14h]
  int v8; // [esp+8h] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 292);
  v2 = *(_DWORD *)(a1 + 300);
  v3 = v1;
  if ( v1 >= v2 )
  {
    v3 = *(_DWORD *)(a1 + 300);
    if ( v1 > v2 )
      v2 = *(_DWORD *)(a1 + 292);
  }
  sub_435650(v3, (_DWORD *)a1);
  result = *(void **)(a1 + 292);
  *(_DWORD *)(a1 + 300) = result;
  if ( v3 < v2 )
  {
    v8 = v2 - v3;
    do
    {
      result = (void *)lstrlenW(*(LPCWSTR *)(a1 + 80));
      if ( result && v3 >= 0 )
      {
        result = (void *)lstrlenW(*(LPCWSTR *)(a1 + 80));
        if ( v3 < (int)result )
        {
          v7 = *(const WCHAR **)(a1 + 80);
          v5 = (WCHAR *)&v7[v3];
          v6 = lstrlenW(v7);
          result = memcpy(v5, v5 + 1, 2 * (v6 - v3));
          *(_BYTE *)(a1 + 92) = 1;
        }
      }
      --v8;
    }
    while ( v8 );
  }
  return result;
}
