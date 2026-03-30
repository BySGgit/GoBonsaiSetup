BOOL __cdecl __crtGetStringTypeA(
        struct localeinfo_struct *a1,
        DWORD dwInfoType,
        LPCCH lpMultiByteStr,
        int cbMultiByte,
        LPWORD lpCharType,
        UINT CodePage,
        int a7,
        int a8)
{
  BOOL result; // eax
  _BYTE v9[8]; // [esp+0h] [ebp-10h] BYREF
  int v10; // [esp+8h] [ebp-8h]
  char v11; // [esp+Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v9, a1);
  result = __crtGetStringTypeA_stat(
             (struct localeinfo_struct *)v9,
             dwInfoType,
             lpMultiByteStr,
             cbMultiByte,
             lpCharType,
             CodePage,
             a8);
  if ( v11 )
    *(_DWORD *)(v10 + 112) &= ~2u;
  return result;
}
