_locale_t __cdecl _create_locale(int Category, const char *Locale)
{
  __crt_locale_pointers *v2; // esi
  struct __crt_locale_data *v4; // eax
  struct __crt_multibyte_data *v5; // eax

  if ( (unsigned int)Category > 5 || !Locale )
    return 0;
  v2 = (__crt_locale_pointers *)_calloc_crt(8, 1);
  if ( !v2 )
  {
LABEL_4:
    *_errno() = 12;
    return 0;
  }
  v4 = (struct __crt_locale_data *)_calloc_crt(216, 1);
  v2->locinfo = v4;
  if ( !v4 )
  {
    free(v2);
    goto LABEL_4;
  }
  v5 = (struct __crt_multibyte_data *)_calloc_crt(544, 1);
  v2->mbcinfo = v5;
  if ( !v5 )
  {
    free(v2->locinfo);
    free(v2);
    goto LABEL_4;
  }
  _copytlocinfo_nolock(v2->locinfo, dword_4C9A88);
  if ( _setlocale_nolock(Category, v2->locinfo, (char *)Locale) )
  {
    if ( !_setmbcp_nolock(*((_DWORD *)v2->locinfo + 1), v2->mbcinfo) )
    {
      *(_DWORD *)v2->mbcinfo = 1;
      *(_DWORD *)v2->mbcinfo = 1;
      return v2;
    }
    free(v2->mbcinfo);
    __removelocaleref((volatile LONG *)v2->locinfo);
    __freetlocinfo(v2->locinfo);
    free(v2);
  }
  else
  {
    __removelocaleref((volatile LONG *)v2->locinfo);
    __freetlocinfo(v2->locinfo);
    free(v2);
  }
  return 0;
}
