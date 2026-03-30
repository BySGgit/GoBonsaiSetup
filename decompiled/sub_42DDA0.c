void __stdcall sub_42DDA0(int a1)
{
  int v1; // ebx

  sub_42DF90(a1);
  if ( (*(int *)(a1 + 600) <= 0 || *(_DWORD *)(a1 + 596)) && *(_DWORD *)(a1 + 596) )
  {
    free(*(void **)(a1 + 596));
    *(_DWORD *)(a1 + 596) = 0;
  }
  *(_DWORD *)(a1 + 604) = 0;
  *(_DWORD *)(a1 + 600) = 0;
  if ( (*(int *)(a1 + 588) <= 0 || *(_DWORD *)(a1 + 584)) && *(_DWORD *)(a1 + 584) )
  {
    free(*(void **)(a1 + 584));
    *(_DWORD *)(a1 + 584) = 0;
  }
  *(_DWORD *)(a1 + 592) = 0;
  *(_DWORD *)(a1 + 588) = 0;
  v1 = 0;
  if ( *(int *)(a1 + 624) <= 0 )
    goto LABEL_34;
  do
  {
    if ( *(_DWORD *)(*(_DWORD *)(a1 + 620) + 4 * v1) )
      operator delete(*(void **)(*(_DWORD *)(a1 + 620) + 4 * v1));
    ++v1;
  }
  while ( v1 < *(_DWORD *)(a1 + 624) );
  if ( *(int *)(a1 + 624) <= 0 || *(_DWORD *)(a1 + 620) )
  {
LABEL_34:
    if ( *(_DWORD *)(a1 + 620) )
    {
      free(*(void **)(a1 + 620));
      *(_DWORD *)(a1 + 620) = 0;
    }
  }
  *(_DWORD *)(a1 + 628) = 0;
  *(_DWORD *)(a1 + 624) = 0;
  if ( *(_DWORD *)(a1 + 620) )
  {
    free(*(void **)(a1 + 620));
    *(_DWORD *)(a1 + 620) = 0;
  }
  *(_DWORD *)(a1 + 628) = 0;
  *(_DWORD *)(a1 + 624) = 0;
  if ( (*(int *)(a1 + 612) <= 0 || *(_DWORD *)(a1 + 608)) && *(_DWORD *)(a1 + 608) )
  {
    free(*(void **)(a1 + 608));
    *(_DWORD *)(a1 + 608) = 0;
  }
  *(_DWORD *)(a1 + 616) = 0;
  *(_DWORD *)(a1 + 612) = 0;
  if ( (*(int *)(a1 + 600) <= 0 || *(_DWORD *)(a1 + 596)) && *(_DWORD *)(a1 + 596) )
  {
    free(*(void **)(a1 + 596));
    *(_DWORD *)(a1 + 596) = 0;
  }
  *(_DWORD *)(a1 + 604) = 0;
  *(_DWORD *)(a1 + 600) = 0;
  if ( *(int *)(a1 + 588) <= 0 || *(_DWORD *)(a1 + 584) )
  {
    if ( *(_DWORD *)(a1 + 584) )
    {
      free(*(void **)(a1 + 584));
      *(_DWORD *)(a1 + 584) = 0;
    }
  }
  *(_DWORD *)(a1 + 592) = 0;
  *(_DWORD *)(a1 + 588) = 0;
}
