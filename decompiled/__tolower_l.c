int __cdecl _tolower_l(int C, _locale_t Locale)
{
  struct __crt_locale_data *locinfo; // ecx
  int v4; // eax
  int result; // eax
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  __crt_locale_pointers v9; // [esp+8h] [ebp-18h] BYREF
  int v10; // [esp+10h] [ebp-10h]
  char v11; // [esp+14h] [ebp-Ch]
  WCHAR DestStr; // [esp+18h] [ebp-8h] BYREF
  CHAR MultiByteStr; // [esp+1Ch] [ebp-4h] BYREF
  char v14; // [esp+1Dh] [ebp-3h]
  char v15; // [esp+1Eh] [ebp-2h]
  int Ca; // [esp+28h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v9, (struct localeinfo_struct *)Locale);
  if ( (unsigned int)C >= 0x100 )
  {
    if ( *((int *)v9.locinfo + 43) > 1 && (Ca = C >> 8, _isleadbyte_l(BYTE1(C), &v9)) )
    {
      MultiByteStr = Ca;
      v14 = C;
      v15 = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      MultiByteStr = C;
      v14 = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           (struct localeinfo_struct *)&v9,
           *((_DWORD *)v9.locinfo + 5),
           0x100u,
           &MultiByteStr,
           v6,
           &DestStr,
           3,
           *((_DWORD *)v9.locinfo + 1),
           1);
    if ( v7 )
    {
      v8 = v7 == 1;
      result = (unsigned __int8)DestStr;
      if ( !v8 )
        result = HIBYTE(DestStr) | ((unsigned __int8)DestStr << 8);
      goto LABEL_17;
    }
  }
  else
  {
    locinfo = v9.locinfo;
    if ( *((int *)v9.locinfo + 43) <= 1 )
    {
      v4 = *(_WORD *)(*((_DWORD *)v9.locinfo + 50) + 2 * C) & 1;
    }
    else
    {
      v4 = _isctype_l(C, 1, &v9);
      locinfo = v9.locinfo;
    }
    if ( v4 )
    {
      result = *(unsigned __int8 *)(*((_DWORD *)locinfo + 51) + C);
LABEL_17:
      if ( v11 )
        *(_DWORD *)(v10 + 112) &= ~2u;
      return result;
    }
  }
  if ( v11 )
    *(_DWORD *)(v10 + 112) &= ~2u;
  return C;
}
