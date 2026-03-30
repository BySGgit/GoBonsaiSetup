void __usercall sub_4296C0(int a1@<esi>)
{
  int i; // ebx
  void *v2; // edi

  for ( i = 0; i < *(_DWORD *)(a1 + 1632); ++i )
  {
    v2 = *(void **)(*(_DWORD *)(a1 + 1628) + 4 * i);
    if ( v2 )
    {
      sub_429780((int)v2);
      operator delete(v2);
    }
  }
  if ( *(_DWORD *)(a1 + 1628) )
  {
    free(*(void **)(a1 + 1628));
    *(_DWORD *)(a1 + 1628) = 0;
  }
  *(_DWORD *)(a1 + 1636) = 0;
  *(_DWORD *)(a1 + 1632) = 0;
  if ( *(_DWORD *)(a1 + 1628) )
  {
    free(*(void **)(a1 + 1628));
    *(_DWORD *)(a1 + 1628) = 0;
  }
  *(_DWORD *)(a1 + 1636) = 0;
  *(_DWORD *)(a1 + 1632) = 0;
  if ( *(int *)(a1 + 1620) <= 0 || *(_DWORD *)(a1 + 1616) )
  {
    if ( *(_DWORD *)(a1 + 1616) )
    {
      free(*(void **)(a1 + 1616));
      *(_DWORD *)(a1 + 1616) = 0;
    }
  }
  *(_DWORD *)(a1 + 1624) = 0;
  *(_DWORD *)(a1 + 1620) = 0;
}
