void sub_4268E0()
{
  _BYTE *EngineInstance; // esi
  char v1; // bl
  _BYTE *v2; // esi
  char v3; // bl
  _BYTE *v4; // esi
  char v5; // bl
  HWND v6; // eax
  HMONITOR v7; // ebx
  void *v8; // eax
  int v9; // eax
  void *v10; // eax
  int v11; // [esp+14h] [ebp-D0h] BYREF
  int v12[24]; // [esp+18h] [ebp-CCh] BYREF
  int Val[25]; // [esp+78h] [ebp-6Ch] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[765];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v1 )
  {
    v2 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v3 = v2[648];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( !v3 )
    {
      v4 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v5 = v4[774];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( v5 )
      {
        if ( sub_41B9C0() )
        {
          v6 = (HWND)sub_41B5D0();
          v7 = sub_438340(v6, 1u);
          v8 = GetEngineInstance();
          if ( v7 != (HMONITOR)sub_419950((int)v8) && sub_426CB0(v7, &v11) >= 0 )
          {
            qmemcpy(v12, sub_427EC0(Val), sizeof(v12));
            if ( v12[0] )
            {
              v12[1] = v11;
              if ( sub_426E40(v7) >= 0 )
                v12[3] = v11;
            }
            else
            {
              v12[1] = v11;
            }
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
            Val[0] = 1;
            Val[1] = 1;
            if ( sub_4283D0(Val, v12, v12) >= 0 )
            {
              v9 = sub_41E880(v12, 0, 0, 0, 0);
              if ( v9 == -2147467260 )
              {
                v10 = GetEngineInstance();
                sub_41A2E0((int)v10);
              }
              else if ( v9 < 0 )
              {
                sub_428190(0);
                sub_4250D0(0, 0);
              }
            }
          }
        }
      }
    }
  }
}
