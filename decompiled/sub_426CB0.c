int __cdecl sub_426CB0(HMONITOR a1, _DWORD *a2)
{
  _DWORD *EngineInstance; // esi
  _DWORD *v3; // esi
  _DWORD *v4; // ebp
  int *v5; // esi
  int v6; // ebx
  int v7; // esi
  _DWORD *v8; // edi
  int *v10; // ebx
  int v11; // ebp
  _DWORD *v12; // edi
  int v13; // esi
  struct tagMONITORINFO v14; // [esp+18h] [ebp-74h] BYREF
  wchar_t String2[34]; // [esp+40h] [ebp-4Ch] BYREF

  *a2 = 0;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = (_DWORD *)EngineInstance[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v3 && !*v3 )
  {
    v4 = sub_428650();
    sub_41F750();
    v5 = (int *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v6 = *v5;
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v7 = 0;
    if ( (int)v4[23] > 0 )
    {
      while ( 1 )
      {
        v8 = *(_DWORD **)(v4[22] + 4 * v7);
        if ( (HMONITOR)(*(int (__stdcall **)(int, _DWORD))(*(_DWORD *)v6 + 60))(v6, *v8) == a1 )
          break;
        if ( ++v7 >= v4[23] )
          return -2147467259;
      }
      *a2 = *v8;
      return 0;
    }
    return -2147467259;
  }
  v14.cbSize = 104;
  sub_438210(&v14, a1);
  v10 = (int *)sub_42B3D0();
  v11 = 0;
  if ( v10[15] <= 0 )
    return -2147467259;
  while ( 1 )
  {
    v12 = *(_DWORD **)(v10[14] + 4 * v11);
    v13 = 0;
    if ( (int)v12[140] > 0 )
      break;
LABEL_20:
    if ( ++v11 >= v10[15] )
      return -2147467259;
  }
  while ( wcsncmp((const wchar_t *)(*(_DWORD *)(v12[139] + 4 * v13) + 12), String2, 0x20u) )
  {
    if ( ++v13 >= v12[140] )
      goto LABEL_20;
  }
  *a2 = *v12;
  return 0;
}
