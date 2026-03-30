void __cdecl _free_locale(_locale_t Locale)
{
  struct __crt_locale_data *locinfo; // eax

  if ( Locale )
  {
    _lock(13);
    if ( Locale->mbcinfo
      && !InterlockedDecrement((volatile LONG *)Locale->mbcinfo)
      && (_UNKNOWN *)Locale->mbcinfo != &unk_4C93F8 )
    {
      free(Locale->mbcinfo);
    }
    _unlock(13);
    if ( Locale->locinfo )
    {
      _lock(12);
      __removelocaleref((volatile LONG *)Locale->locinfo);
      locinfo = Locale->locinfo;
      if ( Locale->locinfo && !*(_DWORD *)locinfo && locinfo != (struct __crt_locale_data *)&unk_4C9A88 )
        __freetlocinfo(Locale->locinfo);
      _unlock(12);
    }
    Locale->locinfo = (struct __crt_locale_data *)-1163005939;
    Locale->mbcinfo = (struct __crt_multibyte_data *)-1163005939;
    free(Locale);
  }
}
