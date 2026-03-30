void __cdecl sub_426B70(char a1)
{
  int EngineInstance; // esi
  int v2; // esi
  int v3; // esi
  int v4; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = *(_DWORD *)(EngineInstance + 4);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v2 )
    sub_421030(a1);
  v3 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = *(_DWORD *)(v3 + 368);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v4 )
    sub_422B80(a1);
}
