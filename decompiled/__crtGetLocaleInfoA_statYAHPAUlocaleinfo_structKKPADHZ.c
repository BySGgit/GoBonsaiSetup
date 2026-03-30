int __cdecl __crtGetLocaleInfoA_stat(
        struct localeinfo_struct *a1,
        LCID Locale,
        LCTYPE LCType,
        LPSTR lpMultiByteStr,
        int cbMultiByte)
{
  int v5; // esi
  int LocaleInfoW; // eax
  int v7; // ecx
  unsigned int v9; // eax
  void *v10; // esp
  WCHAR *v11; // ebx
  WCHAR *v12; // eax
  int v13; // eax
  int v14; // [esp+0h] [ebp-18h] BYREF
  int v15; // [esp+8h] [ebp-10h] BYREF
  int cchData; // [esp+Ch] [ebp-Ch]
  UINT CodePage; // [esp+10h] [ebp-8h]

  v5 = 0;
  CodePage = *(_DWORD *)(*(_DWORD *)a1 + 4);
  LocaleInfoW = GetLocaleInfoW(Locale, LCType, 0, 0);
  v7 = LocaleInfoW;
  cchData = LocaleInfoW;
  if ( !LocaleInfoW )
    return 0;
  if ( LocaleInfoW <= 0 || 0xFFFFFFE0 / LocaleInfoW < 2 )
  {
    v11 = 0;
  }
  else
  {
    v9 = 2 * LocaleInfoW + 8;
    if ( v9 > 0x400 )
    {
      v12 = (WCHAR *)malloc(2 * v7 + 8);
      if ( v12 )
      {
        *(_DWORD *)v12 = 56797;
        v12 += 4;
      }
      v11 = v12;
    }
    else
    {
      v10 = alloca(v9);
      if ( !&v14 )
        return 0;
      v14 = 52428;
      v11 = (WCHAR *)&v15;
    }
  }
  if ( !v11 )
    return 0;
  if ( GetLocaleInfoW(Locale, LCType, v11, cchData) )
  {
    if ( cbMultiByte )
      v13 = WideCharToMultiByte(CodePage, 0, v11, -1, lpMultiByteStr, cbMultiByte, 0, 0);
    else
      v13 = WideCharToMultiByte(CodePage, 0, v11, -1, 0, 0, 0, 0);
    v5 = v13;
  }
  _freea(v11);
  return v5;
}
