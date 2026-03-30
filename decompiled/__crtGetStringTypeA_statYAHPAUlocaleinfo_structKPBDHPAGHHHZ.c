BOOL __cdecl __crtGetStringTypeA_stat(
        struct localeinfo_struct *a1,
        DWORD dwInfoType,
        LPCCH lpMultiByteStr,
        int cbMultiByte,
        LPWORD lpCharType,
        UINT CodePage,
        int a7)
{
  void *v7; // ebx
  int v8; // eax
  int v9; // edi
  unsigned int v11; // eax
  void *v12; // esp
  _DWORD *v13; // eax
  int v14; // eax
  _DWORD v15[3]; // [esp+0h] [ebp-14h] BYREF
  BOOL StringTypeW; // [esp+Ch] [ebp-8h]

  v7 = 0;
  StringTypeW = 0;
  if ( !CodePage )
    CodePage = *(_DWORD *)(*(_DWORD *)a1 + 4);
  v8 = MultiByteToWideChar(CodePage, 8 * (a7 != 0) + 1, lpMultiByteStr, cbMultiByte, 0, 0);
  v9 = v8;
  if ( !v8 )
    return 0;
  if ( v8 <= 0 || (unsigned int)v8 > 0x7FFFFFF0 )
    goto LABEL_14;
  v11 = 2 * v8 + 8;
  if ( v11 > 0x400 )
  {
    v13 = malloc(2 * v9 + 8);
    if ( v13 )
    {
      *v13 = 56797;
      goto LABEL_12;
    }
  }
  else
  {
    v12 = alloca(v11);
    v13 = v15;
    if ( v15 )
    {
      v15[0] = 52428;
LABEL_12:
      v13 += 2;
    }
  }
  v7 = v13;
LABEL_14:
  if ( !v7 )
    return 0;
  memset(v7, 0, 2 * v9);
  v14 = MultiByteToWideChar(CodePage, 1u, lpMultiByteStr, cbMultiByte, (LPWSTR)v7, v9);
  if ( v14 )
    StringTypeW = GetStringTypeW(dwInfoType, (LPCWCH)v7, v14, lpCharType);
  _freea(v7);
  return StringTypeW;
}
