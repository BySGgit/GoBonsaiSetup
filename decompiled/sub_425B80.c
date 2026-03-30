int sub_425B80()
{
  _DWORD *EngineInstance; // esi
  _BYTE *v1; // esi
  _DWORD *v2; // esi
  _DWORD *v3; // esi
  int v4; // eax
  _DWORD *v5; // esi
  int v6; // esi
  int v7; // edi
  _DWORD *v8; // esi
  int v9; // esi
  _DWORD *v10; // esi
  int v11; // esi
  _DWORD *v12; // esi
  int result; // eax
  int v14; // eax
  int v15; // esi
  int v16[24]; // [esp+10h] [ebp-18Ch] BYREF
  _BYTE v17[96]; // [esp+70h] [ebp-12Ch] BYREF
  _DWORD v18[24]; // [esp+D0h] [ebp-CCh] BYREF
  int Val[25]; // [esp+130h] [ebp-6Ch] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = (_BYTE *)EngineInstance[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v1 )
  {
    memset(v17, 0, sizeof(v17));
    v1 = v17;
  }
  qmemcpy(Val, v1, 0x60u);
  qmemcpy(v16, Val, sizeof(v16));
  v2 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = (_DWORD *)v2[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v3 )
  {
    memset(v18, 0, sizeof(v18));
    v3 = v18;
  }
  qmemcpy(v17, v3, sizeof(v17));
  qmemcpy(v18, v17, sizeof(v18));
  if ( Val[0] )
    v16[16] = Val[16] == 0;
  else
    v16[13] = Val[13] == 0;
  v4 = v16[13];
  Val[0] = 1;
  Val[1] = 1;
  Val[3] = 2;
  Val[4] = 1;
  Val[5] = 0;
  Val[6] = 2;
  Val[8] = 0;
  Val[9] = 2;
  Val[10] = 2;
  Val[11] = 2;
  Val[12] = 2;
  Val[13] = 2;
  Val[14] = 2;
  Val[15] = 0;
  Val[16] = 2;
  if ( v16[0] )
    v4 = v16[16];
  if ( v4 == 1 )
  {
    v5 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v6 = v5[147];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v7 = v6;
    v8 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v9 = v8[148];
  }
  else
  {
    v10 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v11 = v10[145];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v7 = v11;
    v12 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v9 = v12[146];
  }
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v7 && v9 )
  {
    Val[7] = 2;
    if ( v16[0] )
    {
      v16[4] = v7;
      v16[5] = v9;
    }
    else
    {
      v16[5] = v7;
      v16[6] = v9;
    }
  }
  else
  {
    Val[7] = 0;
  }
  result = sub_4283D0(Val, v16, v16);
  if ( result >= 0 )
  {
    v14 = sub_41E880(v16, 0, 0, 0, 0);
    v15 = v14;
    if ( v14 < 0 && v14 != -2147467260 && sub_41E880(v18, 0, 0, 0, 0) < 0 )
      sub_428190(0);
    return v15;
  }
  return result;
}
