int __cdecl __init_time(int a1)
{
  void **v1; // edi
  int v3; // eax

  if ( *(_DWORD *)(a1 + 32) )
  {
    v1 = (void **)_calloc_crt(1, 356);
    if ( !v1 )
      return 1;
    if ( _get_lc_time((int)v1, a1) )
    {
      __free_lc_time(v1);
      free(v1);
      return 1;
    }
    v1[45] = (void *)1;
  }
  else
  {
    v1 = (void **)&off_4C9920;
  }
  v3 = *(_DWORD *)(a1 + 212);
  if ( (_UNKNOWN **)v3 != &off_4C9920 )
    InterlockedDecrement((volatile LONG *)(v3 + 180));
  *(_DWORD *)(a1 + 212) = v1;
  return 0;
}
