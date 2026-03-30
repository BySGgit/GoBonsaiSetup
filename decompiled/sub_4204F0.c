int sub_4204F0()
{
  _DWORD *EngineInstance; // esi
  _BYTE *v1; // edi
  char v2; // bl
  _BYTE *v3; // edi
  bool v4; // zf
  _DWORD *v5; // edi
  void (__stdcall *v6)(int); // ebx
  _DWORD *v7; // edi
  int v8; // edi
  _BYTE *v9; // edi
  _BYTE *v10; // edi
  _DWORD *v11; // edi
  int v12; // edi
  int v13; // eax
  _BYTE *v15; // edi
  char *v16; // edi
  _DWORD *v17; // edi
  int (__stdcall *v18)(int, char *, int); // ebp
  int v19; // esi
  void (__stdcall *v20)(LPCRITICAL_SECTION); // ebx
  _DWORD *v21; // edi
  int v22; // edi
  _BYTE *v23; // edi
  _BYTE *v24; // esi
  _DWORD *v25; // esi
  void (__stdcall *v26)(int); // esi
  void *v27; // eax
  int v28; // eax
  _BYTE *v29; // esi
  _BYTE *v30; // esi
  int v31; // [esp+18h] [ebp-Ch]
  int v32; // [esp+1Ch] [ebp-8h]
  char *v33; // [esp+20h] [ebp-4h]

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v32 = EngineInstance[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v1 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = v1[779];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v2 == 1 )
  {
    v3 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    v3[780] = 1;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    v5 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v6 = (void (__stdcall *)(int))v5[225];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v6 )
    {
      v7 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v8 = v7[243];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      v6(v8);
    }
    v9 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    v9[779] = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    v10 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    v10[780] = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
  }
  v11 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v12 = v11[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v13 = (*(int (__stdcall **)(int, int))(*(_DWORD *)v32 + 64))(v32, v12 + 20);
  if ( v13 < 0 )
    return v13 != -2005530520 ? -2147219194 : -2005530520;
  sub_427060();
  sub_427250();
  v15 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = byte_4CA649 == 0;
  v15[780] = 1;
  if ( !v4 )
    LeaveCriticalSection(&CriticalSection);
  v16 = (char *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v33 = v16 + 12;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v17 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v18 = (int (__stdcall *)(int, char *, int))v17[224];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v19 = 0;
  v31 = 0;
  if ( v18 )
  {
    v20 = EnterCriticalSection;
    v21 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v22 = v21[242];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v31 = v18(v32, v33, v22);
    v19 = v31;
  }
  else
  {
    v20 = EnterCriticalSection;
  }
  v23 = GetEngineInstance();
  if ( byte_4CA649 )
    v20(&CriticalSection);
  v4 = byte_4CA649 == 0;
  v23[780] = 0;
  if ( !v4 )
    LeaveCriticalSection(&CriticalSection);
  if ( v19 >= 0 )
  {
    v30 = GetEngineInstance();
    if ( byte_4CA649 )
      v20(&CriticalSection);
    v4 = byte_4CA649 == 0;
    v30[779] = 1;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    return 0;
  }
  else
  {
    if ( v19 != -2147219197 )
      v31 = -2147219192;
    v24 = GetEngineInstance();
    if ( byte_4CA649 )
      v20(&CriticalSection);
    v4 = byte_4CA649 == 0;
    v24[780] = 1;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    v25 = GetEngineInstance();
    if ( byte_4CA649 )
      v20(&CriticalSection);
    v26 = (void (__stdcall *)(int))v25[225];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v26 )
    {
      v27 = GetEngineInstance();
      v28 = sub_41B0E0((int)v27);
      v26(v28);
    }
    v29 = GetEngineInstance();
    if ( byte_4CA649 )
      v20(&CriticalSection);
    v4 = byte_4CA649 == 0;
    v29[780] = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    return v31;
  }
}
