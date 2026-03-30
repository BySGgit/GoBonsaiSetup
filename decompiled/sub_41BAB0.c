BOOL sub_41BAB0()
{
  _DWORD *EngineInstance; // esi
  int v1; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return v1 != 0;
}
