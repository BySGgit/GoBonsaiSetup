void __usercall sub_429270(int a1@<esi>)
{
  if ( (*(int *)(a1 + 72) <= 0 || *(_DWORD *)(a1 + 68)) && *(_DWORD *)(a1 + 68) )
  {
    free(*(void **)(a1 + 68));
    *(_DWORD *)(a1 + 68) = 0;
  }
  *(_DWORD *)(a1 + 76) = 0;
  *(_DWORD *)(a1 + 72) = 0;
  if ( (*(int *)(a1 + 60) <= 0 || *(_DWORD *)(a1 + 56)) && *(_DWORD *)(a1 + 56) )
  {
    free(*(void **)(a1 + 56));
    *(_DWORD *)(a1 + 56) = 0;
  }
  *(_DWORD *)(a1 + 64) = 0;
  *(_DWORD *)(a1 + 60) = 0;
  if ( (*(int *)(a1 + 48) <= 0 || *(_DWORD *)(a1 + 44)) && *(_DWORD *)(a1 + 44) )
  {
    free(*(void **)(a1 + 44));
    *(_DWORD *)(a1 + 44) = 0;
  }
  *(_DWORD *)(a1 + 52) = 0;
  *(_DWORD *)(a1 + 48) = 0;
  if ( (*(int *)(a1 + 36) <= 0 || *(_DWORD *)(a1 + 32)) && *(_DWORD *)(a1 + 32) )
  {
    free(*(void **)(a1 + 32));
    *(_DWORD *)(a1 + 32) = 0;
  }
  *(_DWORD *)(a1 + 40) = 0;
  *(_DWORD *)(a1 + 36) = 0;
  if ( *(int *)(a1 + 24) <= 0 || *(_DWORD *)(a1 + 20) )
  {
    if ( *(_DWORD *)(a1 + 20) )
    {
      free(*(void **)(a1 + 20));
      *(_DWORD *)(a1 + 20) = 0;
    }
  }
  *(_DWORD *)(a1 + 28) = 0;
  *(_DWORD *)(a1 + 24) = 0;
}
