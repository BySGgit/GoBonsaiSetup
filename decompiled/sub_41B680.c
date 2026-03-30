int sub_41B680()
{
  _DWORD *EngineInstance; // esi
  int v1; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[141];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return v1;
}
