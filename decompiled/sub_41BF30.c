void sub_41BF30()
{
  _DWORD *EngineInstance; // esi
  bool v1; // zf
  _DWORD *v2; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  EngineInstance[226] = sub_452800;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
  v2 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  v2[244] = 0;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
}
