void __stdcall sub_4294F0(int a1, int a2, _DWORD *a3)
{
  int i; // ebx
  int v4; // esi

  for ( i = 0; i < *(_DWORD *)(a1 + 48); ++i )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(a1 + 44) + 4 * i);
    if ( (!a3[4] || v4 != 2 && v4 != 4 && v4 != 8)
      && (!v4 || (v4 & *(_DWORD *)(a2 + 28)) != 0)
      && sub_42DBC0(a3[15] + 1, (int)(a3 + 14)) >= 0 )
    {
      *(_DWORD *)(a3[14] + 4 * a3[15]++) = v4;
    }
  }
}
