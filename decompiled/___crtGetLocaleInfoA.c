int __cdecl __crtGetLocaleInfoA(
        struct localeinfo_struct *a1,
        LCID Locale,
        LCTYPE LCType,
        LPSTR lpMultiByteStr,
        int cbMultiByte)
{
  int result; // eax
  _BYTE v6[8]; // [esp+0h] [ebp-10h] BYREF
  int v7; // [esp+8h] [ebp-8h]
  char v8; // [esp+Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v6, a1);
  result = __crtGetLocaleInfoA_stat((struct localeinfo_struct *)v6, Locale, LCType, lpMultiByteStr, cbMultiByte);
  if ( v8 )
    *(_DWORD *)(v7 + 112) &= ~2u;
  return result;
}
