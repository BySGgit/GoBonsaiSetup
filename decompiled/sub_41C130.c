int sub_41C130()
{
  _BYTE *EngineInstance; // esi
  bool v1; // zf
  int v2; // ebx
  int v3; // ebp
  _DWORD *v4; // esi
  int v5; // ebp
  int v6; // ebx
  _DWORD *v7; // esi
  _DWORD *v8; // eax
  _BYTE *v9; // esi
  const WCHAR *CommandLineW; // eax
  HMODULE LibraryW; // eax
  HMODULE v12; // esi
  BOOL (__stdcall *SetProcessDPIAware)(); // eax
  LARGE_INTEGER v14; // kr00_8
  _BYTE *v15; // esi
  int v17; // [esp-18h] [ebp-64h]
  int v18; // [esp-14h] [ebp-60h]
  int v19; // [esp-10h] [ebp-5Ch]
  int v20; // [esp-Ch] [ebp-58h]
  int v21; // [esp-8h] [ebp-54h]
  int v22; // [esp-4h] [ebp-50h]
  int v23; // [esp+10h] [ebp-3Ch] BYREF
  int v24; // [esp+14h] [ebp-38h]
  int pvParam; // [esp+18h] [ebp-34h] BYREF
  int v26; // [esp+1Ch] [ebp-30h]
  LARGE_INTEGER PerformanceCount; // [esp+20h] [ebp-2Ch] BYREF
  int v28; // [esp+2Ch] [ebp-20h] BYREF
  int v29; // [esp+30h] [ebp-1Ch]
  int v30; // [esp+34h] [ebp-18h]
  int v31; // [esp+38h] [ebp-14h]
  int v32; // [esp+3Ch] [ebp-10h]
  int v33; // [esp+40h] [ebp-Ch]

  byte_4CA649 = 0;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  EngineInstance[775] = 1;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
  InitCommonControls();
  pvParam = 8;
  v26 = 0;
  SystemParametersInfoW(0x3Au, 8u, &pvParam, 0);
  v2 = pvParam;
  v3 = v26;
  v4 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  v4[177] = v2;
  v4[178] = v3;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
  v23 = 8;
  v24 = 0;
  SystemParametersInfoW(0x34u, 8u, &v23, 0);
  v5 = v23;
  v6 = v24;
  v7 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  v7[179] = v5;
  v7[180] = v6;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
  v28 = 24;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  SystemParametersInfoW(0x32u, 0x18u, &v28, 0);
  v17 = v28;
  v18 = v29;
  v19 = v30;
  v20 = v31;
  v21 = v32;
  v22 = v33;
  v8 = GetEngineInstance();
  sub_41A050(v8, v17, v18, v19, v20, v21, v22);
  v9 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v9[754] = 1;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  CommandLineW = GetCommandLineW();
  sub_41C3D0(CommandLineW);
  LibraryW = LoadLibraryW(L"user32.dll");
  v12 = LibraryW;
  if ( LibraryW )
  {
    SetProcessDPIAware = GetProcAddress(LibraryW, "SetProcessDPIAware");
    if ( SetProcessDPIAware )
      SetProcessDPIAware();
    FreeLibrary(v12);
  }
  if ( (dword_4D8DF8 & 1) == 0 )
  {
    dword_4D8DF8 |= 1u;
    sub_4375D0();
  }
  v14.QuadPart = qword_4D8DE0;
  if ( !qword_4D8DE0 )
  {
    QueryPerformanceCounter(&PerformanceCount);
    v14 = PerformanceCount;
  }
  qword_4D8DF0 = v14.QuadPart;
  qword_4D8DE8 = v14.QuadPart;
  qword_4D8DE0 = 0;
  byte_4D8DD1 = 0;
  v15 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v15[772] = 1;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return 0;
}
