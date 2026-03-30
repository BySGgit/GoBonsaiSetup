wint_t __cdecl _towlower_l(wint_t C, _locale_t Locale)
{
  wint_t result; // ax
  int v3; // esi
  LCID v4; // ecx
  bool v5; // zf
  int v6; // [esp+0h] [ebp-14h] BYREF
  int v7; // [esp+8h] [ebp-Ch]
  char v8; // [esp+Ch] [ebp-8h]
  WCHAR DestStr; // [esp+10h] [ebp-4h] BYREF

  result = -1;
  if ( C != 0xFFFF )
  {
    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v6, (struct localeinfo_struct *)Locale);
    v3 = v6;
    v4 = *(_DWORD *)(v6 + 20);
    if ( v4 )
    {
      if ( C >= 0x100u )
      {
        v5 = __crtLCMapStringW(v4, 0x100u, &C, 1, &DestStr, 1) == 0;
        result = C;
        if ( !v5 )
          result = DestStr;
      }
      else
      {
        v5 = iswctype(C, 1u) == 0;
        result = C;
        if ( !v5 )
          result = *(unsigned __int8 *)(*(_DWORD *)(v3 + 204) + C);
      }
    }
    else
    {
      result = C;
      if ( (unsigned __int16)(C - 65) <= 0x19u )
        result = C + 32;
    }
    if ( v8 )
      *(_DWORD *)(v7 + 112) &= ~2u;
  }
  return result;
}
