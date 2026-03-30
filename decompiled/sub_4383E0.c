DWORD *__stdcall sub_4383E0(int a1, DWORD *a2, DWORD *a3)
{
  _DWORD *EngineInstance; // esi
  _BYTE *v4; // esi
  _DWORD *v5; // eax
  int v6; // esi
  int v7; // ecx
  int v8; // eax
  _DWORD *v9; // eax
  int v10; // esi
  int v11; // ecx
  _DWORD *v12; // edx
  _DWORD *v13; // eax
  int v14; // eax
  int v15; // esi
  WCHAR *v16; // eax
  int v17; // edx
  int v18; // esi
  WCHAR v19; // cx
  DWORD *result; // eax
  _DWORD v21[24]; // [esp+18h] [ebp-3A8h] BYREF
  _BYTE v22[96]; // [esp+78h] [ebp-348h] BYREF
  DEVMODEW DevMode; // [esp+D8h] [ebp-2E8h] BYREF
  WCHAR WideCharStr[258]; // [esp+1B8h] [ebp-208h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = (_BYTE *)EngineInstance[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v4 )
  {
    memset(v22, 0, sizeof(v22));
    v4 = v22;
  }
  qmemcpy(v21, v4, sizeof(v21));
  memset(WideCharStr, 0, 512);
  memset(&DevMode, 0, sizeof(DevMode));
  DevMode.dmSize = 220;
  if ( v21[0] )
  {
    v9 = sub_42B3D0();
    v10 = v9[15];
    v11 = 0;
    if ( v10 > 0 )
    {
      v12 = (_DWORD *)v9[14];
      while ( 1 )
      {
        v13 = (_DWORD *)*v12;
        if ( *(_DWORD *)*v12 == a1 )
          break;
        ++v11;
        ++v12;
        if ( v11 >= v10 )
          goto LABEL_27;
      }
      if ( v13[140] > v21[3] )
      {
        v14 = *(_DWORD *)(v13[139] + 4 * v21[3]);
        if ( v14 )
        {
          v15 = v14 + 12;
          v16 = WideCharStr;
          v17 = 256;
          v18 = v15 - (_DWORD)WideCharStr;
          while ( v17 != -2147483390 )
          {
            v19 = *(WCHAR *)((char *)v16 + v18);
            if ( !v19 )
              break;
            *v16++ = v19;
            if ( !--v17 )
            {
              --v16;
              break;
            }
          }
          *v16 = 0;
        }
      }
    }
  }
  else
  {
    v5 = sub_428650();
    v6 = v5[23];
    v7 = 0;
    if ( v6 > 0 )
    {
      v8 = v5[22];
      while ( **(_DWORD **)v8 != a1 )
      {
        ++v7;
        v8 += 4;
        if ( v7 >= v6 )
          goto LABEL_27;
      }
      MultiByteToWideChar(0, 0, (LPCCH)(*(_DWORD *)v8 + 1028), -1, WideCharStr, 256);
      WideCharStr[255] = 0;
    }
  }
LABEL_27:
  EnumDisplaySettingsW(WideCharStr, 0xFFFFFFFE, &DevMode);
  if ( a2 )
    *a2 = DevMode.dmPelsWidth;
  result = a3;
  if ( a3 )
    *a3 = DevMode.dmPelsHeight;
  return result;
}
