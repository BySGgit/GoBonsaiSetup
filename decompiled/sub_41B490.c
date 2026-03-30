BOOL sub_41B490()
{
  _DWORD *EngineInstance; // esi
  _DWORD *v1; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = (_DWORD *)EngineInstance[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return v1 && !*v1;
}
