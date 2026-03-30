int _wsetenvp()
{
  wchar_t *v0; // esi
  int v1; // edi
  wchar_t **v3; // ebx
  wchar_t *i; // esi
  size_t v5; // eax
  rsize_t v6; // edi
  wchar_t *v7; // eax

  v0 = dword_4D6F28;
  v1 = 0;
  if ( !dword_4D6F28 )
    return -1;
  while ( *v0 )
  {
    if ( *v0 != 61 )
      ++v1;
    v0 += wcslen(v0) + 1;
  }
  v3 = (wchar_t **)_calloc_crt(v1 + 1, 4);
  dword_4D7288 = v3;
  if ( !v3 )
    return -1;
  for ( i = dword_4D6F28; ; i += v6 )
  {
    if ( !*i )
    {
      free(dword_4D6F28);
      dword_4D6F28 = 0;
      *v3 = 0;
      dword_4DD040 = 1;
      return 0;
    }
    v5 = wcslen(i);
    v6 = v5 + 1;
    if ( *i != 61 )
      break;
LABEL_14:
    ;
  }
  v7 = (wchar_t *)_calloc_crt(v5 + 1, 2);
  *v3 = v7;
  if ( v7 )
  {
    if ( wcscpy_s(v7, v6, i) )
      _invoke_watson(0, 0, 0, 0, 0);
    ++v3;
    goto LABEL_14;
  }
  free(dword_4D7288);
  dword_4D7288 = 0;
  return -1;
}
