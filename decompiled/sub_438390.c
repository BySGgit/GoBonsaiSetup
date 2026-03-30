HMONITOR __stdcall sub_438390(const RECT *a1)
{
  HMODULE ModuleHandleW; // eax
  HMONITOR (__stdcall *MonitorFromRect)(LPCRECT, DWORD); // eax

  if ( byte_4D8DB4 || (byte_4D8DB4 = 1, (ModuleHandleW = GetModuleHandleW(L"USER32")) == 0) )
  {
    MonitorFromRect = (HMONITOR (__stdcall *)(LPCRECT, DWORD))dword_4D8DB8;
  }
  else
  {
    MonitorFromRect = (HMONITOR (__stdcall *)(LPCRECT, DWORD))GetProcAddress(ModuleHandleW, "MonitorFromRect");
    dword_4D8DB8 = (int)MonitorFromRect;
  }
  if ( MonitorFromRect )
    return MonitorFromRect(a1, 2);
  else
    return (HMONITOR)305397826;
}
