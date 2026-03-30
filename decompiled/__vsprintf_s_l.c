int __cdecl _vsprintf_s_l(
        char *const Buffer,
        const size_t BufferCount,
        const char *const Format,
        const _locale_t Locale,
        va_list ArgList)
{
  int result; // eax

  if ( !Format )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( !Buffer || !BufferCount )
  {
    *_errno() = 22;
LABEL_10:
    _invalid_parameter_noinfo();
    return -1;
  }
  result = _vsnprintf_helper(
             (int (__cdecl *)(FILE *, int, int, int))_output_s_l,
             Buffer,
             BufferCount,
             (int)Format,
             (int)Locale,
             (int)ArgList);
  if ( result < 0 )
    *Buffer = 0;
  if ( result == -2 )
  {
    *_errno() = 34;
    goto LABEL_10;
  }
  return result;
}
