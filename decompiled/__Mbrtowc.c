int __cdecl _Mbrtowc(
        wchar_t *lpWideCharStr,
        const char *CodePage,
        size_t a3,
        mbstate_t *lpMultiByteStr,
        const _Cvtvec *a5)
{
  unsigned int Page; // esi
  unsigned int Mbcurmax; // eax
  _locale_t LocaleForCP; // eax
  __crt_locale_pointers *v10; // ebx
  int v11; // eax
  int v12; // eax
  UINT CodePagea; // [esp+18h] [ebp+Ch]

  if ( !CodePage || !a3 )
    return 0;
  if ( !*CodePage )
  {
    if ( lpWideCharStr )
      *lpWideCharStr = 0;
    return 0;
  }
  if ( a5 )
  {
    Page = a5->_Page;
    Mbcurmax = a5->_Mbcurmax;
  }
  else
  {
    Page = *(_DWORD *)(___lc_handle_func() + 8);
    Mbcurmax = ___lc_codepage_func();
  }
  CodePagea = Mbcurmax;
  if ( !Page )
  {
    if ( lpWideCharStr )
      *lpWideCharStr = *(unsigned __int8 *)CodePage;
    return 1;
  }
  LocaleForCP = _GetLocaleForCP(Mbcurmax);
  v10 = LocaleForCP;
  if ( lpMultiByteStr->_Wchar )
  {
    BYTE1(lpMultiByteStr->_Wchar) = *CodePage;
    if ( ___mb_cur_max_l_func(LocaleForCP) > 1
      && MultiByteToWideChar(CodePagea, 9u, (LPCCH)lpMultiByteStr, 2, lpWideCharStr, lpWideCharStr != 0) )
    {
      lpMultiByteStr->_Wchar = 0;
      return ___mb_cur_max_l_func(v10);
    }
    goto LABEL_19;
  }
  if ( LocaleForCP )
    v11 = *((_BYTE *)LocaleForCP->mbcinfo + *(unsigned __int8 *)CodePage + 29) & 4;
  else
    v11 = __pctype_func()[*(unsigned __int8 *)CodePage] & 0x8000;
  if ( !v11 )
  {
    if ( MultiByteToWideChar(CodePagea, 9u, CodePage, 1, lpWideCharStr, lpWideCharStr != 0) )
      return 1;
    goto LABEL_20;
  }
  if ( a3 >= ___mb_cur_max_l_func(v10) )
  {
    if ( ___mb_cur_max_l_func(v10) > 1 )
    {
      v12 = ___mb_cur_max_l_func(v10);
      if ( MultiByteToWideChar(CodePagea, 9u, CodePage, v12, lpWideCharStr, lpWideCharStr != 0) )
        return ___mb_cur_max_l_func(v10);
    }
    if ( CodePage[1] )
      return ___mb_cur_max_l_func(v10);
LABEL_19:
    lpMultiByteStr->_Wchar = 0;
LABEL_20:
    *_errno() = 42;
    return -1;
  }
  LOBYTE(lpMultiByteStr->_Wchar) = *CodePage;
  return -2;
}
