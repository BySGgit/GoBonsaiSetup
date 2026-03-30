double __cdecl _strtod_l(const char *String, char **EndPtr, _locale_t Locale)
{
  const char *v3; // esi
  double *v6; // eax
  double *v7; // ecx
  int v8; // eax
  double v9; // st7
  __crt_locale_pointers v10; // [esp+Ch] [ebp-34h] BYREF
  int v11; // [esp+14h] [ebp-2Ch]
  char v12; // [esp+18h] [ebp-28h]
  double v13; // [esp+1Ch] [ebp-24h]
  char v14[24]; // [esp+24h] [ebp-1Ch] BYREF

  v3 = String;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v10, (struct localeinfo_struct *)Locale);
  if ( EndPtr )
    *EndPtr = (char *)String;
  if ( !String )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( v12 )
      *(_DWORD *)(v11 + 112) &= ~2u;
    return 0.0;
  }
  while ( *((int *)v10.locinfo + 43) <= 1
        ? *(_WORD *)(*((_DWORD *)v10.locinfo + 50) + 2 * *(unsigned __int8 *)v3) & 8
        : _isctype_l(*(unsigned __int8 *)v3, 8, &v10) )
    ++v3;
  v6 = (double *)_fltin2(v14, v3, &v10);
  v7 = v6;
  if ( EndPtr )
    *EndPtr = (char *)&v3[*((_DWORD *)v6 + 1)];
  v8 = *(_DWORD *)v6;
  if ( (*(_DWORD *)v7 & 0x240) != 0 )
  {
    v13 = 0.0;
    if ( EndPtr )
      *EndPtr = (char *)String;
    goto LABEL_24;
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
    goto LABEL_24;
  }
  v13 = v9;
  *_errno() = 34;
LABEL_24:
  if ( v12 )
    *(_DWORD *)(v11 + 112) &= ~2u;
  return v13;
}
