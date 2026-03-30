void __cdecl __free_lconv_num(int a1)
{
  void *v1; // esi

  if ( a1 )
  {
    if ( *(char **)a1 != off_4C91D8 )
      free(*(void **)a1);
    if ( *(_UNKNOWN **)(a1 + 4) != off_4C91DC )
      free(*(void **)(a1 + 4));
    if ( *(_UNKNOWN **)(a1 + 8) != off_4C91E0 )
      free(*(void **)(a1 + 8));
    if ( *(char **)(a1 + 48) != off_4C9208 )
      free(*(void **)(a1 + 48));
    v1 = *(void **)(a1 + 52);
    if ( v1 != off_4C920C )
      free(v1);
  }
}
