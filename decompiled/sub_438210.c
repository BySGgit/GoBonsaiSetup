BOOL __userpurge sub_438210@<eax>(struct tagMONITORINFO *a1@<esi>, HMONITOR a2)
{
  HMODULE ModuleHandleW; // edi
  BOOL (__stdcall *GetMonitorInfoW)(HMONITOR, LPMONITORINFO); // eax
  int SystemMetrics; // eax
  LONG v6; // ecx
  LONG v7; // edx
  LONG v8; // eax
  _DWORD pvParam[4]; // [esp+8h] [ebp-B0h] BYREF
  struct _OSVERSIONINFOA VersionInformation; // [esp+18h] [ebp-A0h] BYREF

  if ( byte_4D8DA6 || (byte_4D8DA6 = 1, (ModuleHandleW = GetModuleHandleW(L"USER32")) == 0) )
  {
    GetMonitorInfoW = (BOOL (__stdcall *)(HMONITOR, LPMONITORINFO))dword_4D8DA8;
  }
  else
  {
    memset(&VersionInformation.dwMajorVersion, 0, 0x90u);
    VersionInformation.dwOSVersionInfoSize = 148;
    GetVersionExA(&VersionInformation);
    if ( VersionInformation.dwPlatformId == 2 )
      GetMonitorInfoW = (BOOL (__stdcall *)(HMONITOR, LPMONITORINFO))GetProcAddress(ModuleHandleW, "GetMonitorInfoW");
    else
      GetMonitorInfoW = (BOOL (__stdcall *)(HMONITOR, LPMONITORINFO))GetProcAddress(ModuleHandleW, "GetMonitorInfoA");
    dword_4D8DA8 = (int)GetMonitorInfoW;
  }
  if ( GetMonitorInfoW )
    return GetMonitorInfoW(a2, a1);
  if ( a2 != (HMONITOR)305397826 || !a1 || a1->cbSize < 0x28 || !SystemParametersInfoA(0x30u, 0, pvParam, 0) )
    return 0;
  a1->rcMonitor.left = 0;
  a1->rcMonitor.top = 0;
  a1->rcMonitor.right = GetSystemMetrics(0);
  SystemMetrics = GetSystemMetrics(1);
  v6 = pvParam[1];
  v7 = pvParam[2];
  a1->rcMonitor.bottom = SystemMetrics;
  a1->rcWork.left = pvParam[0];
  v8 = pvParam[3];
  a1->rcWork.top = v6;
  a1->rcWork.right = v7;
  a1->rcWork.bottom = v8;
  a1->dwFlags = 1;
  return 1;
}
