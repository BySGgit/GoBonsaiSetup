int sub_41B590()
{
  _DWORD *EngineInstance; // esi
  int v1; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[94];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return v1;
}
