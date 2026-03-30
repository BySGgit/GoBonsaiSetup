int sub_426F10()
{
  _DWORD *EngineInstance; // esi
  unsigned __int8 (__stdcall *v1)(int); // esi
  _DWORD *v2; // edi
  int v3; // edi
  _DWORD *v4; // esi
  _DWORD *v5; // esi
  int Val[19]; // [esp+14h] [ebp-50h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = (unsigned __int8 (__stdcall *)(int))EngineInstance[217];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v1 )
  {
    v2 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v3 = v2[235];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( !v1(v3) )
      return -2147219190;
  }
  v4 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v5 = (_DWORD *)v4[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  Val[0] = 2;
  Val[1] = 2;
  Val[3] = 2;
  Val[4] = 2;
  Val[5] = 2;
  Val[6] = 2;
  Val[7] = 2;
  Val[8] = 2;
  Val[9] = 2;
  Val[10] = 2;
  Val[11] = 2;
  Val[12] = 2;
  Val[13] = 2;
  Val[14] = 2;
  Val[15] = 2;
  Val[16] = 2;
  if ( sub_4283D0(Val, v5, v5) < 0 || sub_41E880(v5, 0, 0, 1, 0) < 0 )
    return -2147219190;
  else
    return 0;
}
