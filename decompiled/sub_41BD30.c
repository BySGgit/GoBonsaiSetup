void sub_41BD30()
{
  _DWORD *EngineInstance; // esi
  bool v1; // zf
  _DWORD *v2; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  EngineInstance[222] = sub_451EA0;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
  v2 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  v2[240] = 0;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
}
