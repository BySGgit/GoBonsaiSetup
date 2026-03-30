int __cdecl _mbtowc_l(wchar_t *DstCh, const char *SrcCh, size_t SrcSizeInBytes, _locale_t Locale)
{
  int result; // eax
  struct __crt_locale_data *locinfo; // eax
  int v6; // ecx
  bool v7; // zf
  __crt_locale_pointers Localea; // [esp+8h] [ebp-10h] BYREF
  int v9; // [esp+10h] [ebp-8h]
  char v10; // [esp+14h] [ebp-4h]

  if ( !SrcCh || !SrcSizeInBytes )
    return 0;
  if ( !*SrcCh )
  {
    if ( DstCh )
      *DstCh = 0;
    return 0;
  }
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&Localea, (struct localeinfo_struct *)Locale);
  if ( !*((_DWORD *)Localea.locinfo + 5) )
  {
    if ( DstCh )
      *DstCh = *(unsigned __int8 *)SrcCh;
    goto LABEL_11;
  }
  if ( _isleadbyte_l(*(unsigned __int8 *)SrcCh, &Localea) )
  {
    locinfo = Localea.locinfo;
    v6 = *((_DWORD *)Localea.locinfo + 43);
    if ( v6 > 1
      && (int)SrcSizeInBytes >= v6
      && (v7 = MultiByteToWideChar(*((_DWORD *)Localea.locinfo + 1), 9u, SrcCh, v6, DstCh, DstCh != 0) == 0,
          locinfo = Localea.locinfo,
          !v7)
      || SrcSizeInBytes >= *((_DWORD *)locinfo + 43) && SrcCh[1] )
    {
      result = *((_DWORD *)locinfo + 43);
      if ( v10 )
        *(_DWORD *)(v9 + 112) &= ~2u;
      return result;
    }
  }
  else if ( MultiByteToWideChar(*((_DWORD *)Localea.locinfo + 1), 9u, SrcCh, 1, DstCh, DstCh != 0) )
  {
LABEL_11:
    if ( v10 )
      *(_DWORD *)(v9 + 112) &= ~2u;
    return 1;
  }
  *_errno() = 42;
  if ( v10 )
    *(_DWORD *)(v9 + 112) &= ~2u;
  return -1;
}
