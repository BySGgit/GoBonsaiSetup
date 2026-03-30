int sub_41BA20()
{
  int *EngineInstance; // esi
  int v1; // esi

  sub_41F750();
  EngineInstance = (int *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = *EngineInstance;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return v1;
}
