unsigned int __cdecl _wcstombs_l_helper(
        CHAR *a1,
        LPCWCH lpWideCharStr,
        unsigned int cchWideChar,
        struct localeinfo_struct *a4)
{
  LPCWCH v4; // esi
  unsigned int result; // eax
  UINT *v6; // edi
  unsigned int v8; // ecx
  LPCWCH v9; // eax
  unsigned int v10; // eax
  int v11; // edx
  signed int v12; // ecx
  CHAR v13; // cl
  WCHAR v14; // cx
  LPCWCH v15; // edx
  signed int v16; // [esp+Ch] [ebp-30h]
  signed int v17; // [esp+10h] [ebp-2Ch]
  unsigned int v18; // [esp+18h] [ebp-24h]
  UINT *v19; // [esp+1Ch] [ebp-20h] BYREF
  int v20; // [esp+24h] [ebp-18h]
  char v21; // [esp+28h] [ebp-14h]
  BOOL UsedDefaultChar; // [esp+2Ch] [ebp-10h] BYREF
  CHAR MultiByteStr[8]; // [esp+30h] [ebp-Ch] BYREF

  v4 = lpWideCharStr;
  UsedDefaultChar = 0;
  if ( a1 && !cchWideChar )
    return 0;
  if ( !lpWideCharStr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v19, a4);
  if ( !a1 )
  {
    if ( !v19[5] )
    {
      v14 = *lpWideCharStr;
      result = 0;
      v15 = lpWideCharStr;
      while ( v14 )
      {
        if ( v14 > 0xFFu )
          goto LABEL_50;
        ++result;
        v14 = *++v15;
      }
      goto LABEL_12;
    }
    result = WideCharToMultiByte(v19[1], 0, lpWideCharStr, -1, 0, 0, 0, &UsedDefaultChar);
    if ( !result )
      goto LABEL_50;
    goto LABEL_27;
  }
  v6 = v19;
  if ( !v19[5] )
  {
    result = 0;
    if ( cchWideChar )
    {
      while ( *v4 <= 0xFFu )
      {
        a1[result] = *(_BYTE *)v4;
        if ( *v4++ )
        {
          if ( ++result < cchWideChar )
            continue;
        }
        goto LABEL_12;
      }
      goto LABEL_50;
    }
    goto LABEL_12;
  }
  if ( v19[43] == 1 )
  {
    v8 = cchWideChar;
    if ( cchWideChar )
    {
      v9 = lpWideCharStr;
      do
      {
        if ( !*v9 )
          break;
        ++v9;
        --v8;
      }
      while ( v8 );
      if ( v8 && !*v9 )
        cchWideChar = v9 - lpWideCharStr + 1;
    }
    result = WideCharToMultiByte(v19[1], 0, lpWideCharStr, cchWideChar, a1, cchWideChar, 0, &UsedDefaultChar);
    if ( result && !UsedDefaultChar )
    {
      if ( a1[result - 1] )
        goto LABEL_12;
      goto LABEL_28;
    }
    goto LABEL_50;
  }
  result = WideCharToMultiByte(v19[1], 0, lpWideCharStr, -1, a1, cchWideChar, 0, &UsedDefaultChar);
  v18 = result;
  if ( result )
  {
LABEL_27:
    if ( !UsedDefaultChar )
    {
LABEL_28:
      --result;
LABEL_12:
      if ( v21 )
        *(_DWORD *)(v20 + 112) &= ~2u;
      return result;
    }
LABEL_50:
    *_errno() = 42;
    if ( v21 )
      *(_DWORD *)(v20 + 112) &= ~2u;
    return -1;
  }
  if ( UsedDefaultChar || GetLastError() != 122 )
    goto LABEL_50;
  if ( cchWideChar )
  {
    do
    {
      v10 = WideCharToMultiByte(v6[1], 0, v4, 1, MultiByteStr, v6[43], 0, &UsedDefaultChar);
      v11 = v10;
      v16 = v10;
      if ( !v10 || UsedDefaultChar || v10 > 5 )
        goto LABEL_50;
      result = v18;
      if ( v11 + v18 > cchWideChar )
        goto LABEL_12;
      v12 = 0;
      v17 = 0;
      if ( v11 > 0 )
      {
        do
        {
          v13 = MultiByteStr[v12];
          a1[result] = v13;
          if ( !v13 )
            goto LABEL_12;
          v12 = v17 + 1;
          ++result;
          v17 = v12;
          v18 = result;
        }
        while ( v12 < v16 );
      }
      ++v4;
    }
    while ( result < cchWideChar );
  }
  if ( v21 )
    *(_DWORD *)(v20 + 112) &= ~2u;
  return v18;
}
