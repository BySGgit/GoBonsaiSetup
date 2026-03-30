void sub_426B20()
{
  _DWORD *EngineInstance; // esi
  _DWORD *v1; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = (_DWORD *)EngineInstance[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v1 || *v1 )
    sub_422750();
  else
    sub_4208D0();
}
