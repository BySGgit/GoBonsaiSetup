bool __stdcall sub_451EA0(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int *EngineInstance; // esi
  int v6; // esi

  sub_41F750();
  EngineInstance = (int *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v6 = *EngineInstance;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return (*(int (__stdcall **)(int, _DWORD, _DWORD, int, int, int, int))(*(_DWORD *)v6 + 40))(
           v6,
           a1[1],
           *a1,
           a2,
           0x80000,
           3,
           a3) >= 0;
}
