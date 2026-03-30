int sub_41F640()
{
  _DWORD *EngineInstance; // esi
  void *v1; // esi
  void *v2; // esi
  _DWORD *v3; // edi
  bool v4; // zf
  _BYTE *v5; // esi
  _BYTE *v7; // esi
  void *v8; // [esp+Ch] [ebp-4h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = (void *)EngineInstance[88];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v8 = v1;
  if ( v1 )
    return 0;
  if ( sub_4380B0() && CreateDXGIFactory )
    CreateDXGIFactory(&stru_4B8CFC, &v8);
  v2 = v8;
  v3 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = byte_4CA649 == 0;
  v3[88] = v2;
  if ( !v4 )
    LeaveCriticalSection(&CriticalSection);
  if ( v8 )
  {
    v7 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    v7[348] = 1;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    return 0;
  }
  v5 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = byte_4CA649 == 0;
  v5[348] = 0;
  if ( !v4 )
    LeaveCriticalSection(&CriticalSection);
  return -2147219199;
}
