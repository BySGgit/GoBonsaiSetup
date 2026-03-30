int sub_41DD60()
{
  _BYTE *EngineInstance; // esi
  char v1; // bl
  _BYTE *v2; // esi
  char v3; // bl
  _BYTE *v4; // esi
  bool v5; // zf
  _BYTE *v6; // esi
  char v7; // bl
  void *v8; // eax
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  signed int v13; // esi
  void *v14; // eax
  void *v15; // eax
  void *v16; // eax
  void *v17; // eax
  void *v18; // eax
  void *v19; // eax
  void *v20; // eax
  void *v21; // eax
  void *v22; // eax
  _DWORD *v23; // esi
  int v24; // esi
  _DWORD *v25; // esi
  int v26; // esi
  _DWORD *v27; // esi
  struct tagMSG Msg; // [esp+14h] [ebp-E0h] BYREF
  _DWORD v29[24]; // [esp+30h] [ebp-C4h] BYREF
  _BYTE v30[100]; // [esp+90h] [ebp-64h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[780];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v1 )
    goto LABEL_42;
  v2 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = v2[781];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v3 )
  {
LABEL_42:
    v23 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v24 = v23[192];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( !v24 )
      goto LABEL_52;
    v25 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v26 = v25[192];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v26 == 10 )
    {
LABEL_52:
      v27 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v5 = byte_4CA649 == 0;
      v27[192] = 1;
      if ( !v5 )
        LeaveCriticalSection(&CriticalSection);
    }
    return -2147467259;
  }
  v4 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v5 = byte_4CA649 == 0;
  v4[781] = 1;
  if ( !v5 )
    LeaveCriticalSection(&CriticalSection);
  v6 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v7 = v6[774];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v7 )
  {
    v8 = GetEngineInstance();
    if ( sub_41A520((int)v8) )
    {
      v9 = GetEngineInstance();
      if ( !sub_41A3A0((int)v9) || (v10 = GetEngineInstance(), sub_41A3A0((int)v10) == 10) )
      {
LABEL_23:
        v11 = GetEngineInstance();
        sub_41A360((int)v11, 1);
        return -2147467259;
      }
      return -2147467259;
    }
    v13 = sub_41E0B0(0, 0);
    if ( v13 < 0 )
    {
      v14 = GetEngineInstance();
      if ( !sub_41A3A0((int)v14) || (v15 = GetEngineInstance(), sub_41A3A0((int)v15) == 10) )
      {
        v16 = GetEngineInstance();
        sub_41A360((int)v16, 1);
      }
      return v13;
    }
  }
  sub_41B5D0();
  v17 = GetEngineInstance();
  if ( !sub_41A3E0((int)v17)
    || (v18 = GetEngineInstance(), !sub_41A460((int)v18))
    || (v19 = GetEngineInstance(), !sub_41A4E0((int)v19)) )
  {
    v21 = GetEngineInstance();
    if ( !sub_41A3A0((int)v21) )
      goto LABEL_23;
    v22 = GetEngineInstance();
    if ( sub_41A3A0((int)v22) == 10 )
      goto LABEL_23;
    return -2147467259;
  }
  Msg.message = 0;
  PeekMessageW(&Msg, 0, 0, 0, 0);
  while ( Msg.message != 18 )
  {
    if ( PeekMessageW(&Msg, 0, 0, 0, 1u) )
    {
      TranslateMessage(&Msg);
      DispatchMessageW(&Msg);
    }
    else
    {
      sub_426B20();
      if ( byte_4D7E8E )
      {
        qmemcpy(v29, sub_427EC0(v30), sizeof(v29));
        sub_41E880(v29, 0, 0, 0, 0);
        byte_4D7E8E = 0;
      }
    }
  }
  v20 = GetEngineInstance();
  sub_41A560((int)v20, 0);
  return 0;
}
