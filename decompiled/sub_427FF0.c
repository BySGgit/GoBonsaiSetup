BOOL sub_427FF0()
{
  _BYTE *EngineInstance; // esi
  bool v1; // zf
  _BYTE *v2; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  EngineInstance[756] = 1;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
  v2 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  v2[757] = 1;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
  return sub_427250();
}
