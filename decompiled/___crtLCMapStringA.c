int __cdecl __crtLCMapStringA(
        struct localeinfo_struct *a1,
        LCID Locale,
        DWORD dwMapFlags,
        LPCCH lpMultiByteStr,
        int cbMultiByte,
        LPWSTR lpDestStr,
        int cchDest,
        UINT CodePage,
        int a9)
{
  int result; // eax
  _BYTE v10[8]; // [esp+0h] [ebp-10h] BYREF
  int v11; // [esp+8h] [ebp-8h]
  char v12; // [esp+Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v10, a1);
  result = __crtLCMapStringA_stat(
             (struct localeinfo_struct *)v10,
             Locale,
             dwMapFlags,
             lpMultiByteStr,
             cbMultiByte,
             lpDestStr,
             cchDest,
             CodePage,
             a9);
  if ( v12 )
    *(_DWORD *)(v11 + 112) &= ~2u;
  return result;
}
