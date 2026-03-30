void __stdcall sub_428190(int a1)
{
  HWND v1; // eax
  int EngineInstance; // esi
  bool v3; // zf
  int *v4; // esi
  int v5; // esi
  _DWORD *v6; // esi
  int v7; // esi
  int v8; // esi
  int v9; // esi
  int v10; // esi
  char v11; // bl

  v1 = (HWND)sub_41B5D0();
  if ( v1 )
    SendMessageW(v1, 0x10u, 0, 0);
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = byte_4CA649 == 0;
  *(_DWORD *)(EngineInstance + 768) = a1;
  if ( !v3 )
    LeaveCriticalSection(&CriticalSection);
  sub_426B70(1);
  sub_424DB0(1);
  v4 = (int *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v5 = *v4;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v5 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v5 + 8))(v5);
  v6 = (_DWORD *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = byte_4CA649 == 0;
  *v6 = 0;
  if ( !v3 )
    LeaveCriticalSection(&CriticalSection);
  v7 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v8 = *(_DWORD *)(v7 + 352);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v8 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v8 + 8))(v8);
  v9 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = byte_4CA649 == 0;
  *(_DWORD *)(v9 + 352) = 0;
  if ( !v3 )
    LeaveCriticalSection(&CriticalSection);
  v10 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v11 = *(_BYTE *)(v10 + 860);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v11 )
    sub_4389F0();
}
