char sub_41FD50()
{
  int EngineInstance; // esi
  char v1; // bl
  int v2; // esi
  char v3; // bl
  int v4; // eax
  int v5; // esi
  int v6; // esi
  int v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = *(_BYTE *)(EngineInstance + 750);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v2 = GetEngineInstance();
  if ( v1 )
  {
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v3 = *(_BYTE *)(v2 + 748);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    LOBYTE(v4) = v3;
  }
  else
  {
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v5 = *(_DWORD *)(v2 + 888);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v5 )
      goto LABEL_25;
    v6 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v7 = *(_DWORD *)(v6 + 892);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v7
      || (v8 = GetEngineInstance(), sub_41AE20(v8))
      || (v9 = GetEngineInstance(), sub_41AE60(v9))
      || (v10 = GetEngineInstance(), sub_41AEA0(v10))
      || (v11 = GetEngineInstance(), (v4 = sub_41AEE0(v11)) != 0) )
    {
LABEL_25:
      LOBYTE(v4) = 1;
    }
  }
  return v4;
}
