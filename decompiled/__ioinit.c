int _ioinit()
{
  unsigned int v0; // eax
  unsigned int v2; // eax
  int v3; // ebx
  unsigned int *v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // eax
  int i; // edi
  int v8; // esi
  int j; // ebx
  int v10; // esi
  DWORD v11; // eax
  HANDLE StdHandle; // eax
  HANDLE v13; // edi
  DWORD FileType; // eax
  struct _STARTUPINFOW StartupInfo; // [esp+4h] [ebp-4Ch] BYREF
  HANDLE *v16; // [esp+48h] [ebp-8h]
  LPBYTE v17; // [esp+4Ch] [ebp-4h]

  GetStartupInfoW(&StartupInfo);
  v0 = _calloc_crt(32, 64);
  if ( !v0 )
    return -1;
  dword_4DCF40[0] = v0;
  uNumber = 32;
  if ( v0 < v0 + 2048 )
  {
    v2 = v0 + 5;
    do
    {
      *(_DWORD *)(v2 - 5) = -1;
      *(_WORD *)(v2 - 1) = 2560;
      *(_DWORD *)(v2 + 3) = 0;
      *(_WORD *)(v2 + 31) = 2560;
      *(_BYTE *)(v2 + 33) = 10;
      *(_DWORD *)(v2 + 51) = 0;
      *(_BYTE *)(v2 + 47) = 0;
      v2 += 64;
    }
    while ( v2 - 5 < dword_4DCF40[0] + 2048 );
  }
  if ( StartupInfo.cbReserved2 && StartupInfo.lpReserved2 )
  {
    v3 = *(_DWORD *)StartupInfo.lpReserved2;
    v17 = StartupInfo.lpReserved2 + 4;
    v16 = (HANDLE *)&StartupInfo.lpReserved2[v3 + 4];
    if ( v3 >= 2048 )
      v3 = 2048;
    if ( (int)uNumber < v3 )
    {
      v4 = (unsigned int *)&unk_4DCF44;
      while ( 1 )
      {
        v5 = _calloc_crt(32, 64);
        if ( !v5 )
          break;
        uNumber += 32;
        *v4 = v5;
        if ( v5 < v5 + 2048 )
        {
          v6 = v5 + 5;
          do
          {
            *(_DWORD *)(v6 - 5) = -1;
            *(_DWORD *)(v6 + 3) = 0;
            *(_BYTE *)(v6 + 31) &= 0x80u;
            *(_DWORD *)(v6 + 51) = 0;
            *(_WORD *)(v6 - 1) = 2560;
            *(_WORD *)(v6 + 32) = 2570;
            *(_BYTE *)(v6 + 47) = 0;
            v6 += 64;
          }
          while ( v6 - 5 < *v4 + 2048 );
        }
        ++v4;
        if ( (int)uNumber >= v3 )
          goto LABEL_19;
      }
      v3 = uNumber;
    }
LABEL_19:
    for ( i = 0; i < v3; ++v17 )
    {
      if ( *v16 != (HANDLE)-1 && *v16 != (HANDLE)-2 && (*v17 & 1) != 0 && ((*v17 & 8) != 0 || GetFileType(*v16)) )
      {
        v8 = dword_4DCF40[i >> 5] + ((i & 0x1F) << 6);
        *(_DWORD *)v8 = *v16;
        *(_BYTE *)(v8 + 4) = *v17;
        if ( !InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(v8 + 12), 0xFA0u) )
          return -1;
        ++*(_DWORD *)(v8 + 8);
      }
      ++v16;
      ++i;
    }
  }
  for ( j = 0; j < 3; ++j )
  {
    v10 = dword_4DCF40[0] + (j << 6);
    if ( *(_DWORD *)v10 == -1 || *(_DWORD *)v10 == -2 )
    {
      *(_BYTE *)(v10 + 4) = -127;
      if ( j )
        v11 = -(j != 1) - 11;
      else
        v11 = -10;
      StdHandle = GetStdHandle(v11);
      v13 = StdHandle;
      if ( StdHandle != (HANDLE)-1 && StdHandle && (FileType = GetFileType(StdHandle)) != 0 )
      {
        *(_DWORD *)v10 = v13;
        if ( (unsigned __int8)FileType == 2 )
        {
          *(_BYTE *)(v10 + 4) |= 0x40u;
        }
        else if ( (unsigned __int8)FileType == 3 )
        {
          *(_BYTE *)(v10 + 4) |= 8u;
        }
        if ( !InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(v10 + 12), 0xFA0u) )
          return -1;
        ++*(_DWORD *)(v10 + 8);
      }
      else
      {
        *(_BYTE *)(v10 + 4) |= 0x40u;
        *(_DWORD *)v10 = -2;
      }
    }
    else
    {
      *(_BYTE *)(v10 + 4) |= 0x80u;
    }
  }
  SetHandleCount(uNumber);
  return 0;
}
