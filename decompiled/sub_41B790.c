_DWORD *__usercall sub_41B790@<eax>(_DWORD *a1@<esi>)
{
  _DWORD *EngineInstance; // edi
  int v2; // edi
  _DWORD *v3; // edi
  int v4; // edi

  *a1 = 0;
  a1[1] = 0;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = EngineInstance[145];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  a1[2] = v2;
  v3 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = v3[146];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  a1[3] = v4;
  return a1;
}
