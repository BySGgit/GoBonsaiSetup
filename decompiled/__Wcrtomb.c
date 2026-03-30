int __cdecl _Wcrtomb(char *lpMultiByteStr, wchar_t WideCharStr, mbstate_t *a3, const _Cvtvec *UsedDefaultChar)
{
  unsigned int Page; // esi
  unsigned int Mbcurmax; // edi
  int result; // eax
  __crt_locale_pointers *LocaleForCP; // eax
  int v8; // eax

  if ( UsedDefaultChar )
  {
    Page = UsedDefaultChar->_Page;
    Mbcurmax = UsedDefaultChar->_Mbcurmax;
  }
  else
  {
    Page = *(_DWORD *)(___lc_handle_func() + 8);
    Mbcurmax = ___lc_codepage_func();
  }
  if ( !Page )
  {
    if ( WideCharStr <= 0xFFu )
    {
      *lpMultiByteStr = WideCharStr;
      return 1;
    }
    goto LABEL_9;
  }
  UsedDefaultChar = 0;
  LocaleForCP = _GetLocaleForCP(Mbcurmax);
  v8 = ___mb_cur_max_l_func(LocaleForCP);
  result = WideCharToMultiByte(Mbcurmax, 0, &WideCharStr, 1, lpMultiByteStr, v8, 0, (LPBOOL)&UsedDefaultChar);
  if ( !result || UsedDefaultChar )
  {
LABEL_9:
    *_errno() = 42;
    return -1;
  }
  return result;
}
