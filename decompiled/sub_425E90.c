int sub_425E90()
{
  _DWORD *EngineInstance; // esi
  _BYTE *v1; // esi
  _DWORD *v2; // esi
  _DWORD *v3; // esi
  _DWORD *v4; // esi
  _DWORD *v5; // edi
  _DWORD *v6; // edi
  int (__stdcall ***v7)(_DWORD, void *, int **); // edi
  int v8; // esi
  int v9; // eax
  int v11; // esi
  int v12; // eax
  int *v13; // [esp+18h] [ebp-190h] BYREF
  int v14[24]; // [esp+1Ch] [ebp-18Ch] BYREF
  _BYTE v15[96]; // [esp+7Ch] [ebp-12Ch] BYREF
  _DWORD v16[24]; // [esp+DCh] [ebp-CCh] BYREF
  int Val[25]; // [esp+13Ch] [ebp-6Ch] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = (_BYTE *)EngineInstance[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v1 )
  {
    memset(v15, 0, sizeof(v15));
    v1 = v15;
  }
  qmemcpy(Val, v1, 0x60u);
  qmemcpy(v14, Val, sizeof(v14));
  v2 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = (_DWORD *)v2[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v3 )
  {
    memset(v16, 0, sizeof(v16));
    v3 = v16;
  }
  qmemcpy(v15, v3, sizeof(v15));
  qmemcpy(v16, v15, sizeof(v16));
  v4 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v5 = (_DWORD *)v4[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v5 && !*v5 )
  {
    if ( Val[2] == 1 )
    {
      v14[2] = 2;
    }
    else if ( Val[2] == 2 )
    {
      v14[2] = 1;
    }
LABEL_35:
    Val[0] = 1;
    Val[1] = 1;
    Val[3] = 1;
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
    v11 = sub_4283D0(Val, v14, v14);
    if ( v11 >= 0 )
    {
      v12 = sub_41E880(v14, 0, 0, 0, 0);
      v11 = v12;
      if ( v12 < 0 && v12 != -2147467260 && sub_41E880(v16, 0, 0, 0, 0) < 0 )
        sub_428190(0);
    }
    return v11;
  }
  v13 = 0;
  v6 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v7 = (int (__stdcall ***)(_DWORD, void *, int **))v6[92];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( (**v7)(v7, &unk_4B8D3C, &v13) < 0 )
  {
    if ( Val[2] )
    {
      if ( Val[2] == 1 )
        v14[2] = 0;
    }
    else
    {
      v14[2] = 1;
    }
    goto LABEL_35;
  }
  v8 = *v13;
  v9 = (*(int (__stdcall **)(int *))(*v13 + 16))(v13);
  (*(void (__stdcall **)(int *, bool))(v8 + 12))(v13, v9 == 0);
  if ( v13 )
    (*(void (__stdcall **)(int *))(*v13 + 8))(v13);
  return 0;
}
