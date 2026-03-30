void __usercall sub_444CE0(int a1@<esi>)
{
  int v1; // eax
  int v2; // edi
  int v3; // eax
  bool v4; // zf
  void **v5; // eax

  v1 = *(_DWORD *)(a1 + 16);
  if ( v1 )
  {
    do
    {
      if ( v1 )
      {
        *(_DWORD *)(a1 + 16) = --v1;
        if ( !v1 )
          *(_DWORD *)(a1 + 12) = 0;
      }
    }
    while ( *(_DWORD *)(a1 + 16) );
  }
  v2 = *(_DWORD *)(a1 + 8);
  while ( v2 )
  {
    v3 = *(_DWORD *)(a1 + 4);
    --v2;
    v4 = *(_DWORD *)(v3 + 4 * v2) == 0;
    v5 = (void **)(v3 + 4 * v2);
    if ( !v4 )
      operator delete(*v5);
  }
  if ( *(_DWORD *)(a1 + 4) )
    operator delete(*(void **)(a1 + 4));
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
}
