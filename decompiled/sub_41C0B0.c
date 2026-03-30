void __cdecl sub_41C0B0(_DWORD *a1, _DWORD *a2)
{
  _DWORD *EngineInstance; // esi
  int v3; // esi
  _DWORD *v4; // esi
  int v5; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = EngineInstance[228];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  *a1 = v3;
  v4 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v5 = v4[246];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  *a2 = v5;
}
