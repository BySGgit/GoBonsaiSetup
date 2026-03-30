int __usercall __check_float_string@<eax>(void **a1@<edi>, size_t *a2@<esi>, int a3, void *Src, _DWORD *a5)
{
  size_t v5; // eax
  int v6; // eax
  void *v8; // eax

  v5 = *a2;
  if ( a3 == *a2 )
  {
    if ( *a1 == Src )
    {
      v6 = _calloc_crt(v5, 4);
      *a1 = (void *)v6;
      if ( !v6 )
        return 0;
      *a5 = 1;
      memcpy_0(*a1, Src, 2 * *a2);
    }
    else
    {
      v8 = _recalloc_crt(*a1, v5, 4u);
      if ( !v8 )
        return 0;
      *a1 = v8;
    }
    *a2 *= 2;
  }
  return 1;
}
