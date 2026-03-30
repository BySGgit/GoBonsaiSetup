void __usercall sub_428790(int a1@<eax>)
{
  sub_429560(a1);
  if ( (*(int *)(a1 + 92) <= 0 || *(_DWORD *)(a1 + 88)) && *(_DWORD *)(a1 + 88) )
  {
    free(*(void **)(a1 + 88));
    *(_DWORD *)(a1 + 88) = 0;
  }
  *(_DWORD *)(a1 + 96) = 0;
  *(_DWORD *)(a1 + 92) = 0;
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
