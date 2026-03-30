void sub_450440()
{
  _DWORD *EngineInstance; // esi
  int v1; // esi

  if ( !dword_4D7FE8 )
  {
    dword_4D7FF0 = 1000;
    dword_4D7FF4 = 2000;
    dword_4D7FEC = 2;
    dword_4D7FF8 = 16;
    dword_4D7FFC = 66;
    EngineInstance = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v1 = EngineInstance[1];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    (*(void (__stdcall **)(int, int, int, int, _DWORD, int *, _DWORD))(*(_DWORD *)v1 + 104))(
      v1,
      dword_4D7FF4 * dword_4D7FF8,
      520,
      dword_4D7FFC,
      0,
      &dword_4D7FE8,
      0);
  }
}
