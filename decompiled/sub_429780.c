void __usercall sub_429780(int a1@<edi>)
{
  int i; // ebx
  void *v2; // esi

  for ( i = 0; i < *(_DWORD *)(a1 + 316); ++i )
  {
    v2 = *(void **)(*(_DWORD *)(a1 + 312) + 4 * i);
    if ( v2 )
    {
      sub_429270((int)v2);
      operator delete(v2);
    }
  }
  if ( *(_DWORD *)(a1 + 312) )
  {
    free(*(void **)(a1 + 312));
    *(_DWORD *)(a1 + 312) = 0;
  }
  *(_DWORD *)(a1 + 320) = 0;
  *(_DWORD *)(a1 + 316) = 0;
  if ( *(_DWORD *)(a1 + 312) )
  {
    free(*(void **)(a1 + 312));
    *(_DWORD *)(a1 + 312) = 0;
  }
  *(_DWORD *)(a1 + 316) = 0;
  *(_DWORD *)(a1 + 320) = 0;
}
