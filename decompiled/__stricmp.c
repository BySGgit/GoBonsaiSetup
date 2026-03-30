int __cdecl _stricmp(const char *String1, const char *String2)
{
  if ( dword_4D6F30 )
    return _stricmp_l(String1, String2, 0);
  if ( String1 && String2 )
    return __ascii_stricmp((unsigned __int8 *)String1, (unsigned __int8 *)String2);
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return 0x7FFFFFFF;
}
