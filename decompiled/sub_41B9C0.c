bool sub_41B9C0()
{
  _DWORD *EngineInstance; // esi
  _DWORD *v1; // esi
  int v3; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = (_DWORD *)EngineInstance[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v1 )
    return 1;
  if ( *v1 )
    v3 = v1[16];
  else
    v3 = v1[13];
  return v3 == 1;
}
