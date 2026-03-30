int __usercall sub_42D980@<eax>(signed int a1@<edx>, int a2@<esi>)
{
  unsigned int v2; // edi
  int v4; // ecx
  int v5; // eax
  signed int v6; // eax
  void *v7; // eax

  v2 = a1;
  if ( (unsigned int)a1 >= 0x20000000 )
    return -2147024809;
  if ( a1 )
  {
    if ( !*(_DWORD *)a2 || a1 > *(_DWORD *)(a2 + 8) )
    {
      v4 = *(_DWORD *)(a2 + 8);
      v5 = 16;
      if ( v4 )
        v5 = *(_DWORD *)(a2 + 8);
      if ( (unsigned int)(v4 + v5) > 0x7FFFFFFF )
        v5 = 0x7FFFFFFF - v4;
      v6 = v4 + v5;
      if ( a1 <= v6 )
        v2 = v6;
      if ( 0xFFFFFFFF / v2 < 4 )
        return -2147024809;
      v7 = realloc(*(void **)a2, 4 * v2);
      if ( !v7 )
        return -2147024882;
      *(_DWORD *)a2 = v7;
      *(_DWORD *)(a2 + 8) = v2;
    }
    return 0;
  }
  else
  {
    if ( *(_DWORD *)a2 )
    {
      free(*(void **)a2);
      *(_DWORD *)a2 = v2;
    }
    *(_DWORD *)(a2 + 8) = 0;
    *(_DWORD *)(a2 + 4) = 0;
    return 0;
  }
}
