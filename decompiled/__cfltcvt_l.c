int __cdecl _cfltcvt_l(_DWORD *a1, char *Str, int a3, int a4, size_t Size, int a6, struct localeinfo_struct *a7)
{
  switch ( a4 )
  {
    case 'e':
    case 'E':
      return _cftoe_l(a1, Str, a3, Size, a6, a7);
    case 'f':
      return _cftof_l(a1, Str, a3, Size, a7);
    case 'a':
    case 'A':
      return _cftoa_l(a1, Str, a3, Size, a6, a7);
  }
  return _cftog_l(a1, Str, a3, Size, a6, a7);
}
