int sub_41F750()
{
  int *EngineInstance; // esi
  int v1; // esi
  IDirect3D9 *v2; // esi
  _DWORD *v4; // edi
  bool v5; // zf

  EngineInstance = (int *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = *EngineInstance;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v1 )
  {
    if ( !sub_437FE0() )
      return -2147219199;
    if ( !Direct3DCreate9 )
      return -2147219199;
    v2 = Direct3DCreate9(0x20u);
    if ( !v2 )
      return -2147219199;
    v4 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v5 = byte_4CA649 == 0;
    *v4 = v2;
    if ( !v5 )
      LeaveCriticalSection(&CriticalSection);
  }
  return 0;
}
