LRESULT __stdcall fn(int code, WPARAM wParam, _DWORD *lParam)
{
  int v3; // eax
  int v5; // eax
  HHOOK v6; // eax
  int EngineInstance; // esi
  HHOOK v8; // esi

  if ( code )
  {
    EngineInstance = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v8 = *(HHOOK *)(EngineInstance + 700);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    return CallNextHookEx(v8, code, wParam, (LPARAM)lParam);
  }
  else if ( wParam >= 0x100
         && wParam <= 0x101
         && (v3 = GetEngineInstance(), !sub_41A010(v3))
         && (*lParam == 91 || *lParam == 92) )
  {
    return 1;
  }
  else
  {
    v5 = GetEngineInstance();
    v6 = (HHOOK)sub_419F50(v5);
    return CallNextHookEx(v6, 0, wParam, (LPARAM)lParam);
  }
}
