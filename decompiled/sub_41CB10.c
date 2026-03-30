char __cdecl sub_41CB10(const wchar_t **a1, wchar_t *String2)
{
  signed int v2; // esi
  const wchar_t *v3; // eax
  int v5; // ecx

  v2 = wcslen(String2);
  v3 = *a1;
  while ( *v3++ )
    ;
  if ( v3 - (*a1 + 1) < v2 )
    return 0;
  if ( _wcsnicmp(*a1, String2, v2) )
    return 0;
  v5 = (*a1)[v2];
  if ( (_WORD)v5 )
  {
    if ( v5 != 58 )
      return 0;
  }
  *a1 += v2;
  return 1;
}
