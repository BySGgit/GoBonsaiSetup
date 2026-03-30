void __usercall sub_40CE80(_DWORD *a1@<esi>)
{
  _DWORD *EngineInstance; // edi
  int v2; // edi

  if ( !*a1 )
  {
    a1[2] = 0;
    a1[3] = 100000;
    a1[1] = 5;
    a1[4] = 36;
    a1[5] = 338;
    EngineInstance = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v2 = EngineInstance[1];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    (*(void (__stdcall **)(int, int, int, _DWORD, _DWORD, _DWORD *, _DWORD))(*(_DWORD *)v2 + 104))(
      v2,
      a1[3] * a1[4],
      520,
      a1[5],
      0,
      a1,
      0);
  }
}
