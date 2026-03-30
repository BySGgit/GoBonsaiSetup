double __cdecl _wcstod_l(const wchar_t *String, wchar_t **EndPtr, _locale_t Locale)
{
  const wchar_t *v3; // ebx
  wchar_t i; // ax
  double *v6; // eax
  double *v7; // ecx
  int v8; // eax
  double v9; // st7
  _BYTE v10[8]; // [esp+Ch] [ebp-34h] BYREF
  int v11; // [esp+14h] [ebp-2Ch]
  char v12; // [esp+18h] [ebp-28h]
  double v13; // [esp+1Ch] [ebp-24h]
  char v14[24]; // [esp+24h] [ebp-1Ch] BYREF

  v3 = String;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v10, (struct localeinfo_struct *)Locale);
  if ( EndPtr )
    *EndPtr = (wchar_t *)String;
  if ( !String )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( v12 )
      *(_DWORD *)(v11 + 112) &= ~2u;
    return 0.0;
  }
  for ( i = *String; iswctype(i, 8u); i = *v3 )
    ++v3;
  v6 = (double *)_wfltin2(v14, v3, v10);
  v7 = v6;
  if ( EndPtr )
    *EndPtr = (wchar_t *)&v3[*((_DWORD *)v6 + 1)];
  v8 = *(_DWORD *)v6;
  if ( (*(_DWORD *)v7 & 0x240) != 0 )
  {
    v13 = 0.0;
    if ( EndPtr )
      *EndPtr = (wchar_t *)String;
    goto LABEL_22;
  }
  if ( (v8 & 0x81) != 0 )
  {
    v9 = dbl_4C9B70;
    if ( *v3 == 45 )
      v9 = -dbl_4C9B70;
  }
  else if ( (v8 & 0x100) == 0 || (v9 = 0.0, 0.0 != v7[2]) )
  {
    v13 = v7[2];
    goto LABEL_22;
  }
  v13 = v9;
  *_errno() = 34;
LABEL_22:
  if ( v12 )
    *(_DWORD *)(v11 + 112) &= ~2u;
  return v13;
}
