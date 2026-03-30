int __cdecl _strnicmp_l(const char *String1, const char *String2, size_t MaxCount, _locale_t Locale)
{
  int result; // eax
  const char *v5; // esi
  int v6; // edi
  int v7; // eax
  __crt_locale_pointers Localea; // [esp+Ch] [ebp-10h] BYREF
  int v9; // [esp+14h] [ebp-8h]
  char v10; // [esp+18h] [ebp-4h]

  if ( !MaxCount )
    return 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&Localea, (struct localeinfo_struct *)Locale);
  if ( String1 && (v5 = String2) != 0 )
  {
    if ( MaxCount <= 0x7FFFFFFF )
    {
      if ( *((_DWORD *)Localea.locinfo + 5) )
      {
        do
        {
          v6 = _tolower_l((unsigned __int8)v5[String1 - String2], &Localea);
          v7 = _tolower_l(*(unsigned __int8 *)v5++, &Localea);
          --MaxCount;
        }
        while ( MaxCount && v6 && v6 == v7 );
        result = v6 - v7;
      }
      else
      {
        result = __ascii_strnicmp(String1, String2, MaxCount);
      }
      if ( v10 )
        *(_DWORD *)(v9 + 112) &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( v10 )
        *(_DWORD *)(v9 + 112) &= ~2u;
      return 0x7FFFFFFF;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( v10 )
      *(_DWORD *)(v9 + 112) &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}
