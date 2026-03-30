void __usercall sub_429560(int a1@<edi>)
{
  int i; // ebx
  void *v2; // esi

  for ( i = 0; i < *(_DWORD *)(a1 + 92); ++i )
  {
    v2 = *(void **)(*(_DWORD *)(a1 + 88) + 4 * i);
    if ( v2 )
    {
      sub_4296C0((int)v2);
      operator delete(v2);
    }
  }
  if ( *(_DWORD *)(a1 + 88) )
  {
    free(*(void **)(a1 + 88));
    *(_DWORD *)(a1 + 88) = 0;
  }
  *(_DWORD *)(a1 + 92) = 0;
  *(_DWORD *)(a1 + 96) = 0;
}
