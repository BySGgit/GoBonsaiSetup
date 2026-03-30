void __cdecl __free_lconv_mon(int a1)
{
  void *v1; // esi

  if ( a1 )
  {
    if ( *(_UNKNOWN **)(a1 + 12) != off_4C91E4 )
      free(*(void **)(a1 + 12));
    if ( *(_UNKNOWN **)(a1 + 16) != off_4C91E8 )
      free(*(void **)(a1 + 16));
    if ( *(_UNKNOWN **)(a1 + 20) != off_4C91EC )
      free(*(void **)(a1 + 20));
    if ( *(_UNKNOWN **)(a1 + 24) != off_4C91F0 )
      free(*(void **)(a1 + 24));
    if ( *(_UNKNOWN **)(a1 + 28) != off_4C91F4 )
      free(*(void **)(a1 + 28));
    if ( *(_UNKNOWN **)(a1 + 32) != off_4C91F8 )
      free(*(void **)(a1 + 32));
    if ( *(_UNKNOWN **)(a1 + 36) != off_4C91FC )
      free(*(void **)(a1 + 36));
    if ( *(_UNKNOWN **)(a1 + 56) != off_4C9210 )
      free(*(void **)(a1 + 56));
    if ( *(_UNKNOWN **)(a1 + 60) != off_4C9214 )
      free(*(void **)(a1 + 60));
    if ( *(_UNKNOWN **)(a1 + 64) != off_4C9218 )
      free(*(void **)(a1 + 64));
    if ( *(_UNKNOWN **)(a1 + 68) != off_4C921C )
      free(*(void **)(a1 + 68));
    if ( *(_UNKNOWN **)(a1 + 72) != off_4C9220 )
      free(*(void **)(a1 + 72));
    v1 = *(void **)(a1 + 76);
    if ( v1 != off_4C9224 )
      free(v1);
  }
}
