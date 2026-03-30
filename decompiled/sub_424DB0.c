void __cdecl sub_424DB0(char a1)
{
  int EngineInstance; // esi
  bool v2; // zf
  _DWORD *v3; // esi
  int v4; // esi
  _DWORD *v5; // eax
  int v6; // esi
  int v7; // esi
  int v8; // esi
  HHOOK v9; // esi
  int v10; // esi
  int v11; // esi
  HMODULE ModuleHandleW; // eax
  int v13; // eax
  int v14; // esi
  int v15; // esi
  _DWORD *v16; // eax
  HHOOK v17; // [esp-4h] [ebp-15Ch]
  int pvParam; // [esp+10h] [ebp-148h] BYREF
  int v19; // [esp+14h] [ebp-144h]
  int v20; // [esp+18h] [ebp-140h] BYREF
  int v21; // [esp+1Ch] [ebp-13Ch]
  int v22; // [esp+20h] [ebp-138h] BYREF
  int v23; // [esp+24h] [ebp-134h]
  struct _OSVERSIONINFOW VersionInformation; // [esp+38h] [ebp-120h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = byte_4CA649 == 0;
  *(_BYTE *)(EngineInstance + 706) = a1;
  if ( !v2 )
    LeaveCriticalSection(&CriticalSection);
  v3 = (_DWORD *)GetEngineInstance();
  if ( a1 )
  {
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    pvParam = v3[177];
    v19 = v3[178];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v4 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v20 = *(_DWORD *)(v4 + 716);
    v21 = *(_DWORD *)(v4 + 720);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v5 = (_DWORD *)GetEngineInstance();
    sub_41A0C0(v5, &v22);
    SystemParametersInfoW(0x3Bu, 8u, &pvParam, 0);
    SystemParametersInfoW(0x35u, 8u, &v20, 0);
    SystemParametersInfoW(0x33u, 0x18u, &v22, 0);
    v6 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v7 = *(_DWORD *)(v6 + 700);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v7 )
    {
      v8 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v9 = *(HHOOK *)(v8 + 700);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      UnhookWindowsHookEx(v9);
      v10 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v2 = byte_4CA649 == 0;
      *(_DWORD *)(v10 + 700) = 0;
      if ( !v2 )
        LeaveCriticalSection(&CriticalSection);
    }
  }
  else
  {
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v11 = v3[175];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( !v11 )
    {
      VersionInformation.dwOSVersionInfoSize = 276;
      GetVersionExW(&VersionInformation);
      if ( VersionInformation.dwPlatformId == 2 && VersionInformation.dwMajorVersion > 4 )
      {
        ModuleHandleW = GetModuleHandleW(0);
        v17 = SetWindowsHookExW(13, (HOOKPROC)fn, ModuleHandleW, 0);
        v13 = GetEngineInstance();
        sub_419F10(v13, (int)v17);
      }
    }
    v14 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v20 = *(_DWORD *)(v14 + 708);
    v21 = *(_DWORD *)(v14 + 712);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( (v21 & 1) == 0 )
    {
      v21 &= 0xFFFFFFF3;
      SystemParametersInfoW(0x3Bu, 8u, &v20, 0);
    }
    v15 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    pvParam = *(_DWORD *)(v15 + 716);
    v19 = *(_DWORD *)(v15 + 720);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( (v19 & 1) == 0 )
    {
      v19 &= 0xFFFFFFF3;
      SystemParametersInfoW(0x35u, 8u, &pvParam, 0);
    }
    v16 = (_DWORD *)GetEngineInstance();
    sub_41A0C0(v16, &v22);
    if ( (v23 & 1) == 0 )
    {
      v23 &= 0xFFFFFFF3;
      SystemParametersInfoW(0x33u, 0x18u, &v22, 0);
    }
  }
}
