void __usercall sub_42C0E0(int a1@<esi>)
{
  int i; // edi
  int v2; // eax
  void *v3; // ebx

  for ( i = 0; i < *(_DWORD *)(a1 + 60); ++i )
  {
    v2 = *(_DWORD *)(a1 + 56);
    v3 = *(void **)(v2 + 4 * i);
    if ( v3 )
    {
      sub_42C400(*(_DWORD *)(v2 + 4 * i));
      operator delete(v3);
    }
  }
  if ( *(_DWORD *)(a1 + 56) )
  {
    free(*(void **)(a1 + 56));
    *(_DWORD *)(a1 + 56) = 0;
  }
  *(_DWORD *)(a1 + 60) = 0;
  *(_DWORD *)(a1 + 64) = 0;
}
