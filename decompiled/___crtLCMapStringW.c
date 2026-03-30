int __cdecl __crtLCMapStringW(
        LCID Locale,
        DWORD dwMapFlags,
        LPCWSTR lpSrcStr,
        int cchSrc,
        LPWSTR lpDestStr,
        int cchDest)
{
  size_t v6; // eax

  v6 = cchSrc;
  if ( cchSrc > 0 )
    v6 = wcsnlen(lpSrcStr, cchSrc);
  return LCMapStringW(Locale, dwMapFlags, lpSrcStr, v6, lpDestStr, cchDest);
}
