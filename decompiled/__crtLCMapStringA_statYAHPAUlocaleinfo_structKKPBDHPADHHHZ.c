int __cdecl __crtLCMapStringA_stat(
        struct localeinfo_struct *a1,
        LCID Locale,
        DWORD dwMapFlags,
        LPCCH lpMultiByteStr,
        int cbMultiByte,
        LPWSTR lpDestStr,
        int cchDest,
        UINT CodePage,
        int a9)
{
  LPCCH v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // edi
  unsigned int v15; // eax
  void *v16; // esp
  WCHAR *v17; // eax
  unsigned int v18; // eax
  void *v19; // esp
  WCHAR *v20; // edi
  WCHAR *v21; // eax
  int v22; // eax
  _DWORD v23[2]; // [esp+0h] [ebp-1Ch] BYREF
  int v24; // [esp+8h] [ebp-14h] BYREF
  int cchSrc; // [esp+Ch] [ebp-10h]
  LPWSTR lpWideCharStr; // [esp+10h] [ebp-Ch]
  int cchWideChar; // [esp+14h] [ebp-8h]

  if ( cbMultiByte > 0 )
  {
    v9 = lpMultiByteStr;
    v10 = cbMultiByte;
    while ( 1 )
    {
      --v10;
      if ( !*v9 )
        break;
      ++v9;
      if ( !v10 )
      {
        v10 = -1;
        break;
      }
    }
    v11 = cbMultiByte - v10 - 1;
    if ( v11 < cbMultiByte )
      v11 = cbMultiByte - v10;
    cbMultiByte = v11;
  }
  cchWideChar = 0;
  if ( !CodePage )
    CodePage = *(_DWORD *)(*(_DWORD *)a1 + 4);
  v12 = MultiByteToWideChar(CodePage, 8 * (a9 != 0) + 1, lpMultiByteStr, cbMultiByte, 0, 0);
  v13 = v12;
  cchSrc = v12;
  if ( !v12 )
    return 0;
  if ( v12 > 0 && 0xFFFFFFE0 / v12 >= 2 )
  {
    v15 = 2 * v12 + 8;
    if ( v15 > 0x400 )
    {
      v17 = (WCHAR *)malloc(2 * v13 + 8);
      if ( v17 )
      {
        *(_DWORD *)v17 = 56797;
        goto LABEL_20;
      }
    }
    else
    {
      v16 = alloca(v15);
      v17 = (WCHAR *)v23;
      if ( v23 )
      {
        v23[0] = 52428;
LABEL_20:
        v17 += 4;
      }
    }
    lpWideCharStr = v17;
    goto LABEL_23;
  }
  lpWideCharStr = 0;
LABEL_23:
  if ( !lpWideCharStr )
    return 0;
  if ( MultiByteToWideChar(CodePage, 1u, lpMultiByteStr, cbMultiByte, lpWideCharStr, v13) )
  {
    cchWideChar = LCMapStringW(Locale, dwMapFlags, lpWideCharStr, v13, 0, 0);
    if ( cchWideChar )
    {
      if ( (dwMapFlags & 0x400) != 0 )
      {
        if ( cchDest )
        {
          if ( cchWideChar <= cchDest )
            LCMapStringW(Locale, dwMapFlags, lpWideCharStr, v13, lpDestStr, cchDest);
        }
        goto LABEL_46;
      }
      if ( cchWideChar <= 0 || 0xFFFFFFE0 / cchWideChar < 2 )
      {
        v20 = 0;
LABEL_39:
        if ( v20 )
        {
          if ( LCMapStringW(Locale, dwMapFlags, lpWideCharStr, cchSrc, v20, cchWideChar) )
          {
            if ( cchDest )
              v22 = WideCharToMultiByte(CodePage, 0, v20, cchWideChar, (LPSTR)lpDestStr, cchDest, 0, 0);
            else
              v22 = WideCharToMultiByte(CodePage, 0, v20, cchWideChar, 0, 0, 0, 0);
            cchWideChar = v22;
          }
          _freea(v20);
        }
        goto LABEL_46;
      }
      v18 = 2 * cchWideChar + 8;
      if ( v18 > 0x400 )
      {
        v21 = (WCHAR *)malloc(2 * cchWideChar + 8);
        if ( v21 )
        {
          *(_DWORD *)v21 = 56797;
          v21 += 4;
        }
        v20 = v21;
        goto LABEL_39;
      }
      v19 = alloca(v18);
      if ( v23 )
      {
        v23[0] = 52428;
        v20 = (WCHAR *)&v24;
        goto LABEL_39;
      }
    }
  }
LABEL_46:
  _freea(lpWideCharStr);
  return cchWideChar;
}
