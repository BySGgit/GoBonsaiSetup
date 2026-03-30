void sub_426710()
{
  _BYTE *EngineInstance; // esi
  char v1; // bl
  _DWORD *v2; // esi
  int v3; // esi
  HWND v4; // eax
  int v5; // [esp+10h] [ebp-4h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[862];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v1 )
  {
    v2 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v3 = v2[94];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    (*(void (__stdcall **)(int, int *, _DWORD))(*(_DWORD *)v3 + 44))(v3, &v5, 0);
    sub_426190(v5);
    v4 = (HWND)sub_41B5D0();
    ShowWindow(v4, 5);
  }
}
