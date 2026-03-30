int __cdecl _stricmp_l(const char *String1, const char *String2, _locale_t Locale)
{
  int result; // eax
  const char *v4; // esi
  int v5; // edi
  int v6; // eax
  __crt_locale_pointers v7; // [esp+4h] [ebp-10h] BYREF
  int v8; // [esp+Ch] [ebp-8h]
  char v9; // [esp+10h] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v7, (struct localeinfo_struct *)Locale);
  if ( String1 )
  {
    v4 = String2;
    if ( String2 )
    {
      if ( *((_DWORD *)v7.locinfo + 5) )
      {
        do
        {
          v5 = _tolower_l((unsigned __int8)v4[String1 - String2], &v7);
          v6 = _tolower_l(*(unsigned __int8 *)v4++, &v7);
        }
        while ( v5 && v5 == v6 );
        result = v5 - v6;
      }
      else
      {
        result = __ascii_stricmp((unsigned __int8 *)String1, (unsigned __int8 *)String2);
      }
      if ( v9 )
        *(_DWORD *)(v8 + 112) &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( v9 )
        *(_DWORD *)(v8 + 112) &= ~2u;
      return 0x7FFFFFFF;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( v9 )
      *(_DWORD *)(v8 + 112) &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}
