int __cdecl _wcsnicmp_l(const wchar_t *String1, const wchar_t *String2, size_t MaxCount, _locale_t Locale)
{
  int result; // eax
  wint_t *v5; // ebx
  wint_t *v6; // edi
  int v7; // ebx
  unsigned int v8; // eax
  wint_t v9; // si
  unsigned int v10; // eax
  __crt_locale_pointers v11; // [esp+8h] [ebp-10h] BYREF
  int v12; // [esp+10h] [ebp-8h]
  char v13; // [esp+14h] [ebp-4h]

  result = 0;
  if ( MaxCount )
  {
    v5 = (wint_t *)String1;
    if ( String1 && (v6 = (wint_t *)String2) != 0 )
    {
      _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v11, (struct localeinfo_struct *)Locale);
      if ( *((_DWORD *)v11.locinfo + 5) )
      {
        do
        {
          v9 = _towlower_l(*v5, &v11);
          LOWORD(v10) = _towlower_l(*v6, &v11);
          ++v5;
          ++v6;
          --MaxCount;
        }
        while ( MaxCount && v9 && v9 == (_WORD)v10 );
      }
      else
      {
        v7 = (char *)String1 - (char *)String2;
        do
        {
          v8 = *(wint_t *)((char *)v6 + v7);
          if ( v8 < 0x41 || v8 > 0x5A )
            v9 = *(wint_t *)((char *)v6 + v7);
          else
            v9 = v8 + 32;
          v10 = *v6;
          if ( v10 >= 0x41 && v10 <= 0x5A )
            LOWORD(v10) = v10 + 32;
          ++v6;
          --MaxCount;
        }
        while ( MaxCount && v9 && v9 == (_WORD)v10 );
      }
      result = v9 - (unsigned __int16)v10;
      if ( v13 )
        *(_DWORD *)(v12 + 112) &= ~2u;
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
