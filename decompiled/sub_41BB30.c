void sub_41BB30()
{
  _DWORD *EngineInstance; // esi
  bool v1; // zf
  _DWORD *v2; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  EngineInstance[216] = sub_451F10;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
  v2 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  v2[234] = 0;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
}
