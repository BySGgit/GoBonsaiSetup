void __usercall sub_42DF90(int a1@<esi>)
{
  int v1; // edi
  void (__thiscall ***v2)(_DWORD, int); // ecx

  if ( dword_4D7F28 && *(_DWORD *)(dword_4D7F28 + 24) == a1 )
    dword_4D7F28 = 0;
  if ( dword_4D7F2C && *(_DWORD *)(dword_4D7F2C + 24) == a1 )
    dword_4D7F2C = 0;
  v1 = 0;
  for ( *(_DWORD *)(a1 + 16) = 0; v1 < *(_DWORD *)(a1 + 612); ++v1 )
  {
    v2 = *(void (__thiscall ****)(_DWORD, int))(*(_DWORD *)(a1 + 608) + 4 * v1);
    if ( v2 )
      (**v2)(v2, 1);
  }
  if ( *(_DWORD *)(a1 + 608) )
  {
    free(*(void **)(a1 + 608));
    *(_DWORD *)(a1 + 608) = 0;
  }
  *(_DWORD *)(a1 + 612) = 0;
  *(_DWORD *)(a1 + 616) = 0;
}
