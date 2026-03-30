int __stdcall sub_42F300(int a1, int a2, const wchar_t *a3, int a4, int a5)
{
  unsigned int v5; // eax
  _DWORD *v6; // edi
  int v7; // esi
  int v8; // eax

  v5 = *(_DWORD *)(a1 + 600);
  if ( v5 <= a2 )
  {
    v6 = (_DWORD *)(a1 + 596);
    v7 = a2 - v5 + 1;
    do
    {
      if ( sub_42DBC0(*(_DWORD *)(a1 + 600) + 1, (int)v6) >= 0 )
        *(_DWORD *)(*v6 + 4 * (*(_DWORD *)(a1 + 600))++) = -1;
      --v7;
    }
    while ( v7 );
  }
  v8 = sub_42F130(a3, *(_DWORD **)(a1 + 572), a4, a5);
  if ( a2 >= 0 && a2 < *(_DWORD *)(a1 + 600) )
    *(_DWORD *)(*(_DWORD *)(a1 + 596) + 4 * a2) = v8;
  return 0;
}
