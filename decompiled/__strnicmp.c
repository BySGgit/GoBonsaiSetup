int __cdecl _strnicmp(const char *String1, const char *String2, size_t MaxCount)
{
  if ( dword_4D6F30 )
    return _strnicmp_l(String1, String2, MaxCount, 0);
  if ( String1 && String2 && MaxCount <= 0x7FFFFFFF )
    return __ascii_strnicmp(String1, String2, MaxCount);
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return 0x7FFFFFFF;
}
