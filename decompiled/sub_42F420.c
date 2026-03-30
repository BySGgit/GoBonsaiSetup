int __stdcall sub_42F420(int a1)
{
  _DWORD *v1; // edi
  int v2; // esi
  int v3; // eax

  if ( !*(_DWORD *)(a1 + 588) )
  {
    v1 = (_DWORD *)(a1 + 584);
    v2 = 1;
    do
    {
      if ( sub_42DBC0(*(_DWORD *)(a1 + 588) + 1, (int)v1) >= 0 )
        *(_DWORD *)(*v1 + 4 * (*(_DWORD *)(a1 + 588))++) = -1;
      --v2;
    }
    while ( v2 );
  }
  v3 = sub_42F380(*(_DWORD **)(a1 + 572));
  if ( *(int *)(a1 + 588) > 0 )
    **(_DWORD **)(a1 + 584) = v3;
  return 0;
}
