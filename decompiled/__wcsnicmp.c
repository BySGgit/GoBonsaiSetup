int __cdecl _wcsnicmp(const wchar_t *String1, const wchar_t *String2, size_t MaxCount)
{
  int result; // eax
  const wchar_t *v4; // ecx
  int v5; // esi
  unsigned int v6; // eax
  unsigned __int16 v7; // dx
  unsigned int v8; // eax

  if ( dword_4D6F30 )
    return _wcsnicmp_l(String1, String2, MaxCount, 0);
  result = 0;
  if ( MaxCount )
  {
    if ( String1 && (v4 = String2) != 0 )
    {
      v5 = (char *)String1 - (char *)String2;
      do
      {
        v6 = *(const wchar_t *)((char *)v4 + v5);
        if ( v6 < 0x41 || v6 > 0x5A )
          v7 = *(const wchar_t *)((char *)v4 + v5);
        else
          v7 = v6 + 32;
        v8 = *v4;
        if ( v8 >= 0x41 && v8 <= 0x5A )
          LOWORD(v8) = v8 + 32;
        ++v4;
        --MaxCount;
      }
      while ( MaxCount && v7 && v7 == (_WORD)v8 );
      return v7 - (unsigned __int16)v8;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return 0x7FFFFFFF;
    }
  }
  return result;
}
