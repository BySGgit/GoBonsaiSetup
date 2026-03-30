void __cdecl sub_421030(char a1)
{
  int EngineInstance; // esi
  int v2; // edi
  int v3; // edi
  bool v4; // zf
  int v5; // edi
  char v6; // bl
  int v7; // edi
  void (__stdcall *v8)(int); // edi
  int v9; // eax
  int v10; // eax
  int v11; // edi
  int v12; // edi
  char v13; // bl
  int v14; // edi
  void (__stdcall *v15)(int); // edi
  int v16; // eax
  int v17; // eax
  int v18; // edi
  int v19; // edi
  int v20; // esi
  int v21; // esi
  void *v22; // esi
  int v23; // esi
  _DWORD *v24; // esi
  int v25; // esi
  void *v26; // esi
  int v27; // esi
  int v28; // [esp+Ch] [ebp-4h]

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = *(_DWORD *)(EngineInstance + 4);
  v28 = v2;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v2 )
  {
    v3 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    *(_BYTE *)(v3 + 780) = 1;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    v5 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v6 = *(_BYTE *)(v5 + 779);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v6 == 1 )
    {
      v7 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v8 = *(void (__stdcall **)(int))(v7 + 900);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( v8 )
      {
        v9 = GetEngineInstance();
        v10 = sub_41B0E0(v9);
        v8(v10);
      }
      v11 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v4 = byte_4CA649 == 0;
      *(_BYTE *)(v11 + 779) = 0;
      if ( !v4 )
        LeaveCriticalSection(&CriticalSection);
    }
    v12 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v13 = *(_BYTE *)(v12 + 778);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v13 == 1 )
    {
      v14 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v15 = *(void (__stdcall **)(int))(v14 + 904);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( v15 )
      {
        v16 = GetEngineInstance();
        v17 = sub_41B120(v16);
        v15(v17);
      }
      v18 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v4 = byte_4CA649 == 0;
      *(_BYTE *)(v18 + 778) = 0;
      if ( !v4 )
        LeaveCriticalSection(&CriticalSection);
    }
    v19 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    *(_BYTE *)(v19 + 780) = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    if ( (*(int (__stdcall **)(int))(*(_DWORD *)v28 + 8))(v28) )
      sub_4256B0(-2147219196);
    v20 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    *(_DWORD *)(v20 + 4) = 0;
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( a1 )
    {
      v21 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v22 = *(void **)(v21 + 8);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( v22 )
        operator delete(v22);
      v23 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      *(_DWORD *)(v23 + 8) = 0;
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
    }
    v24 = (_DWORD *)GetEngineInstance();
    if ( byte_4CA649 )
    {
      EnterCriticalSection(&CriticalSection);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
    }
    v24[3] = 0;
    v24[4] = 0;
    v24[5] = 0;
    v24[6] = 0;
    v24[7] = 0;
    v24[8] = 0;
    v24[9] = 0;
    v24[10] = 0;
    v25 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v26 = (void *)(v25 + 44);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    memset(v26, 0, 0x130u);
    v27 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    *(_BYTE *)(v27 + 774) = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
  }
}
