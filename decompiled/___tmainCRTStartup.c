int __tmainCRTStartup()
{
  int v0; // eax
  WCHAR *v1; // eax
  int wShowWindow; // ecx
  int v3; // eax
  struct _STARTUPINFOW StartupInfo; // [esp+10h] [ebp-68h] BYREF
  int v6; // [esp+58h] [ebp-20h]
  BOOL v7; // [esp+5Ch] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+60h] [ebp-18h]

  GetStartupInfoW(&StartupInfo);
  if ( !dword_4DD05C )
    HeapSetInformation(0, HeapEnableTerminationOnCorruption, 0, 0);
  v7 = MEMORY[0x400000] == 23117
    && *(_DWORD *)(MEMORY[0x40003C] + 0x400000) == 17744
    && *(_WORD *)(MEMORY[0x40003C] + 4194328) == 267
    && *(_DWORD *)(MEMORY[0x40003C] + 4194420) > 0xEu
    && *(_DWORD *)(MEMORY[0x40003C] + 4194536) != 0;
  if ( !_heap_init() )
    fast_error_exit(28);
  if ( !_mtinit() )
    fast_error_exit(16);
  sub_45DE73();
  ms_exc.registration.TryLevel = 0;
  if ( _ioinit() < 0 )
    _amsg_exit(27);
  dword_4DD058 = (int)GetCommandLineW();
  dword_4D6F28 = (wchar_t *)__crtGetEnvironmentStringsW();
  if ( _wsetargv() < 0 )
    _amsg_exit(8);
  if ( _wsetenvp() < 0 )
    _amsg_exit(9);
  v0 = _cinit(1);
  if ( v0 )
    _amsg_exit(v0);
  v1 = (WCHAR *)_wwincmdln();
  if ( (StartupInfo.dwFlags & 1) != 0 )
    wShowWindow = StartupInfo.wShowWindow;
  else
    wShowWindow = 10;
  v3 = wWinMain((HINSTANCE)0x400000, 0, v1, wShowWindow);
  v6 = v3;
  if ( !v7 )
    exit(v3);
  _cexit();
  return v6;
}
