HMONITOR __stdcall sub_438340(HWND a1, DWORD a2)
{
  HMODULE ModuleHandleW; // eax
  HMONITOR (__stdcall *MonitorFromWindow)(HWND, DWORD); // eax

  if ( byte_4D8DAC || (byte_4D8DAC = 1, (ModuleHandleW = GetModuleHandleW(L"USER32")) == 0) )
  {
    MonitorFromWindow = (HMONITOR (__stdcall *)(HWND, DWORD))dword_4D8DB0;
  }
  else
  {
    MonitorFromWindow = (HMONITOR (__stdcall *)(HWND, DWORD))GetProcAddress(ModuleHandleW, "MonitorFromWindow");
    dword_4D8DB0 = (int)MonitorFromWindow;
  }
  if ( MonitorFromWindow )
    return MonitorFromWindow(a1, a2);
  else
    return (HMONITOR)305397826;
}
