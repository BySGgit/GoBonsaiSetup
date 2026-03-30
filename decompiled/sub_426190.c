void __cdecl sub_426190(int a1)
{
  void *EngineInstance; // esi
  HWND v2; // eax
  _DWORD *v3; // edi
  _DWORD *v4; // esi
  _DWORD *v5; // edi
  _BYTE *v6; // edi
  bool v7; // zf
  _DWORD *v8; // edi
  void (__stdcall *v9)(int); // ebx
  _DWORD *v10; // edi
  int v11; // edi
  _BYTE *v12; // edi
  _DWORD *v13; // edi
  int v14; // edi
  _DWORD *v15; // edi
  _DWORD *v16; // edi
  int v17; // edi
  _DWORD *v18; // edi
  _DWORD *v19; // edi
  int v20; // edi
  _DWORD *v21; // edi
  int v22; // eax
  _BYTE *v23; // edi
  char v24; // bl
  _BYTE *v25; // edi
  char *v26; // edi
  char *v27; // esi
  _DWORD *v28; // edi
  int (__stdcall *v29)(int *, int, char *, int); // ebp
  int v30; // edi
  void (__stdcall *v31)(LPCRITICAL_SECTION); // ebx
  _DWORD *v32; // edi
  int v33; // edi
  _BYTE *v34; // esi
  _BYTE *v35; // esi
  _DWORD *v36; // esi
  void (__stdcall *v37)(int); // esi
  void *v38; // eax
  int v39; // eax
  _BYTE *v40; // esi
  int v41; // [esp+2Ch] [ebp-1Ch]
  int *v42; // [esp+30h] [ebp-18h]
  struct tagRECT Rect; // [esp+34h] [ebp-14h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v42 = (int *)*((_DWORD *)EngineInstance + 92);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v2 = (HWND)sub_41B5D0();
  GetClientRect(v2, &Rect);
  v3 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = (_DWORD *)v3[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v5 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v41 = v5[94];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v4[16] = a1 == 0;
  v6 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v7 = byte_4CA649 == 0;
  v6[780] = 1;
  if ( !v7 )
    LeaveCriticalSection(&CriticalSection);
  v8 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v9 = (void (__stdcall *)(int))v8[231];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v9 )
  {
    v10 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v11 = v10[248];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v9(v11);
  }
  v12 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v7 = byte_4CA649 == 0;
  v12[780] = 0;
  if ( !v7 )
    LeaveCriticalSection(&CriticalSection);
  v13 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v14 = v13[95];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v14 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v14 + 8))(v14);
  v15 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v15[95] = 0;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v16 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v17 = v16[96];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v17 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v17 + 8))(v17);
  v18 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v18[96] = 0;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v19 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v20 = v19[97];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v20 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v20 + 8))(v20);
  v21 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v21[97] = 0;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v22 = 0;
  if ( a1 )
    v22 = 2;
  (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)v41 + 52))(v41, v4[14], 0, 0, v4[8], v22);
  v23 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v24 = v23[413];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v24 )
  {
    v4[4] = Rect.right;
    v4[5] = Rect.bottom;
  }
  sub_427060();
  sub_427400();
  if ( sub_421720(v42, (int)v4) >= 0 )
  {
    sub_427250();
    v25 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v7 = byte_4CA649 == 0;
    v25[780] = 1;
    if ( !v7 )
      LeaveCriticalSection(&CriticalSection);
    v26 = (char *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v27 = v26 + 392;
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v28 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v29 = (int (__stdcall *)(int *, int, char *, int))v28[230];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v30 = 0;
    if ( v29 )
    {
      v31 = EnterCriticalSection;
      v32 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v33 = v32[248];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      v30 = v29(v42, v41, v27, v33);
    }
    else
    {
      v31 = EnterCriticalSection;
    }
    v34 = GetEngineInstance();
    if ( byte_4CA649 )
      v31(&CriticalSection);
    v7 = byte_4CA649 == 0;
    v34[780] = 0;
    if ( !v7 )
      LeaveCriticalSection(&CriticalSection);
    v35 = GetEngineInstance();
    if ( v30 >= 0 )
    {
      if ( byte_4CA649 )
        v31(&CriticalSection);
      v7 = byte_4CA649 == 0;
      v35[779] = 1;
      if ( !v7 )
        LeaveCriticalSection(&CriticalSection);
      sub_4250D0(0, 0);
    }
    else
    {
      if ( byte_4CA649 )
        v31(&CriticalSection);
      v7 = byte_4CA649 == 0;
      v35[780] = 1;
      if ( !v7 )
        LeaveCriticalSection(&CriticalSection);
      v36 = GetEngineInstance();
      if ( byte_4CA649 )
        v31(&CriticalSection);
      v37 = (void (__stdcall *)(int))v36[231];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( v37 )
      {
        v38 = GetEngineInstance();
        v39 = sub_41B1E0((int)v38);
        v37(v39);
      }
      v40 = GetEngineInstance();
      if ( byte_4CA649 )
        v31(&CriticalSection);
      v7 = byte_4CA649 == 0;
      v40[780] = 0;
      if ( !v7 )
        LeaveCriticalSection(&CriticalSection);
      sub_4250D0(0, 0);
      PostQuitMessage(0);
    }
  }
}
