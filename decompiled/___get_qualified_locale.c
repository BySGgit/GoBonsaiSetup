int __cdecl __get_qualified_locale(DWORD Value, _WORD *a2, LPSTR lpLCData)
{
  DWORD *v3; // edi
  const char **v4; // ebx
  _BYTE *v5; // eax
  int v6; // ecx
  const char *v7; // ebx
  const char *v8; // ebx
  LCID UserDefaultLCID; // eax
  UINT v10; // eax
  __int16 v11; // si
  int Valuea; // [esp+14h] [ebp+8h]

  v3 = _getptd() + 39;
  if ( !Value )
  {
    v3[2] |= 0x104u;
LABEL_23:
    UserDefaultLCID = GetUserDefaultLCID();
    v3[6] = UserDefaultLCID;
    v3[7] = UserDefaultLCID;
    goto LABEL_24;
  }
  *v3 = Value;
  v4 = (const char **)(v3 + 1);
  v3[1] = Value + 64;
  if ( Value != -64 && *(_BYTE *)(Value + 64) )
    TranslateName((int)&off_475990, 22, (const char **)v3 + 1);
  v5 = (_BYTE *)*v3;
  v3[2] = 0;
  if ( !v5 || !*v5 )
  {
    v8 = *v4;
    if ( !v8 || !*v8 )
    {
      v3[2] = 260;
      goto LABEL_23;
    }
    v3[5] = strlen(v8) == 3;
    EnumSystemLocalesA(CountryEnumProc, 1u);
    if ( (v3[2] & 4) == 0 )
      v3[2] = 0;
LABEL_24:
    if ( !v3[2] )
      return 0;
    goto LABEL_25;
  }
  if ( *v4 && **v4 )
    GetLcidFromLangCountry((int)v3);
  else
    GetLcidFromLanguage((int)v3);
  if ( !v3[2] )
  {
    if ( TranslateName((int)&off_475788, 64, (const char **)v3) )
    {
      v7 = *v4;
      if ( v7 && *v7 )
        GetLcidFromLangCountry((int)v3);
      else
        GetLcidFromLanguage((int)v3);
    }
    goto LABEL_24;
  }
LABEL_25:
  v10 = ProcessCodePage(v6, (int)v3, Value != 0 ? (const char *)(Value + 128) : 0);
  v11 = v10;
  Valuea = v10;
  if ( !v10 || v10 == 65000 || v10 == 65001 || !IsValidCodePage((unsigned __int16)v10) || !IsValidLocale(v3[6], 1u) )
    return 0;
  if ( a2 )
  {
    *a2 = *((_WORD *)v3 + 12);
    a2[1] = *((_WORD *)v3 + 14);
    a2[2] = v11;
  }
  if ( !lpLCData )
    return 1;
  if ( *a2 == 2068 )
  {
    if ( strcpy_s(lpLCData, 0x40u, "Norwegian-Nynorsk") )
      _invoke_watson(0, 0, 0, 0, 0);
  }
  else if ( !GetLocaleInfoA(v3[6], 0x1001u, lpLCData, 64) )
  {
    return 0;
  }
  if ( GetLocaleInfoA(v3[7], 0x1002u, lpLCData + 64, 64) )
  {
    _itoa_s(Valuea, lpLCData + 128, 0x10u, 10);
    return 1;
  }
  return 0;
}
