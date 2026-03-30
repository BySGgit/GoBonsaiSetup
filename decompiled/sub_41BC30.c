void sub_41BC30()
{
  _DWORD *EngineInstance; // esi
  bool v1; // zf
  _DWORD *v2; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  EngineInstance[219] = sub_4526E0;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
  v2 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  v2[237] = 0;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
}
