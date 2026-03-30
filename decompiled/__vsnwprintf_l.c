int __cdecl _vsnwprintf_l(
        wchar_t *const Buffer,
        const size_t BufferCount,
        const wchar_t *const Format,
        const _locale_t Locale,
        va_list ArgList)
{
  int result; // eax
  int v6; // edi
  FILE File; // [esp+8h] [ebp-20h] BYREF

  memset(&File, 0, sizeof(File));
  if ( Format && (!BufferCount || Buffer) )
  {
    File._flag = 66;
    File._base = (char *)Buffer;
    File._ptr = (char *)Buffer;
    if ( BufferCount <= 0x3FFFFFFF )
      File._cnt = 2 * BufferCount;
    else
      File._cnt = 0x7FFFFFFF;
    result = _woutput_l((int)&File, (int)Format, (struct localeinfo_struct *)Locale, (int)ArgList);
    v6 = result;
    if ( Buffer )
    {
      if ( --File._cnt < 0 )
        _flsbuf(0, &File);
      else
        *File._ptr++ = 0;
      if ( --File._cnt < 0 )
        _flsbuf(0, &File);
      else
        *File._ptr = 0;
      return v6;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}
