int sub_41B8C0()
{
  int EngineInstance; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
  {
    EnterCriticalSection(&CriticalSection);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
  }
  return EngineInstance + 7292;
}
