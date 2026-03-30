int sub_41B5D0()
{
  int EngineInstance; // esi
  _DWORD *v1; // esi
  int v2; // esi
  int v3; // esi
  int v4; // esi
  int v5; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = *(_DWORD **)(EngineInstance + 8);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v1 && (*v1 ? (v2 = v1[16]) : (v2 = v1[13]), v2 != 1) )
  {
    v5 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = *(_DWORD *)(v5 + 564);
  }
  else
  {
    v3 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = *(_DWORD *)(v3 + 568);
  }
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return v4;
}
