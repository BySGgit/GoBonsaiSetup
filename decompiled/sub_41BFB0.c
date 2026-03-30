void sub_41BFB0()
{
  _DWORD *EngineInstance; // esi
  bool v1; // zf
  _DWORD *v2; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  EngineInstance[227] = sub_452220;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
  v2 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  v2[245] = 0;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
}
