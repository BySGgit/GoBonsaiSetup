int __usercall sub_434340@<eax>(int a1@<esi>)
{
  int i; // edi
  int v2; // ecx
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // eax

  for ( i = 0; i < *(_DWORD *)(a1 + 876); ++i )
  {
    if ( *(_DWORD *)(*(_DWORD *)(a1 + 872) + 4 * i) )
      operator delete(*(void **)(*(_DWORD *)(a1 + 872) + 4 * i));
  }
  if ( *(_DWORD *)(a1 + 872) )
  {
    free(*(void **)(a1 + 872));
    *(_DWORD *)(a1 + 872) = 0;
  }
  *(_DWORD *)(a1 + 880) = 0;
  *(_DWORD *)(a1 + 876) = 0;
  v2 = *(_DWORD *)(a1 + 764);
  *(_DWORD *)(a1 + 772) = 0;
  *(_DWORD *)(a1 + 776) = 1;
  if ( v2 < 0 || (v3 = *(_DWORD *)(a1 + 768), v3 >= 1) )
  {
    *(_DWORD *)(a1 + 764) = 0;
  }
  else if ( v3 + v2 > 1 )
  {
    *(_DWORD *)(a1 + 764) = 1 - v3;
  }
  v4 = *(_DWORD *)(a1 + 768);
  if ( v4 >= 1 )
  {
    v8 = *(_DWORD *)(a1 + 752);
    *(_BYTE *)(a1 + 696) = 0;
  }
  else
  {
    v5 = v4 * (*(_DWORD *)(a1 + 744) - *(_DWORD *)(a1 + 736));
    if ( v5 <= 8 )
      v5 = 8;
    v6 = *(_DWORD *)(a1 + 764) * (*(_DWORD *)(a1 + 744) - *(_DWORD *)(a1 + 736) - v5) / (1 - v4);
    *(_BYTE *)(a1 + 696) = 1;
    v7 = *(_DWORD *)(a1 + 736) + v6;
    *(_DWORD *)(a1 + 752) = v7;
    v8 = v5 + v7;
  }
  *(_DWORD *)(a1 + 760) = v8;
  *(_DWORD *)(a1 + 608) = -1;
  *(_DWORD *)(a1 + 604) = -1;
  return -1;
}
