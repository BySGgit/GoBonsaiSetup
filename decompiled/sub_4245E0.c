void sub_4245E0()
{
  _BYTE *EngineInstance; // esi
  char v1; // bl
  float *v2; // ebx
  _DWORD *v3; // esi
  int v4; // esi
  _DWORD *v5; // esi
  int v6; // esi
  _DWORD *v7; // esi
  int v8; // esi
  _DWORD *v9; // esi
  int v10; // esi
  _DWORD *v11; // esi
  int v12; // esi
  _DWORD *v13; // esi
  int v14; // esi
  _DWORD *v15; // esi
  int v16; // esi
  _DWORD *v17; // esi
  int v18; // esi
  _DWORD *v19; // esi
  int v20; // esi
  _DWORD *v21; // esi
  int v22; // esi
  _DWORD *v23; // esi
  int v24; // esi
  _DWORD *v25; // esi
  int v26; // esi
  _DWORD *v27; // esi
  int v28; // esi
  _DWORD *v29; // esi
  int v30; // esi
  _DWORD *v31; // esi
  int v32; // esi
  _DWORD *v33; // esi
  int v34; // esi
  _DWORD *v35; // esi
  int v36; // esi
  _DWORD *v37; // esi
  int v38; // esi
  char *v39; // esi
  wchar_t *v40; // esi
  float v41; // [esp+1C0h] [ebp-4h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[755];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v1 )
  {
    v2 = (float *)GetEngineInstance();
    if ( byte_4CA649 )
    {
      EnterCriticalSection(&CriticalSection);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
    }
    v3 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = v3[104];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v4 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v4 + 36))(v4, &v41, 4, 1) >= 0 )
      v2[122] = v41;
    v5 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v6 = v5[105];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v6 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v6 + 36))(v6, &v41, 4, 1) >= 0 )
      v2[123] = v41;
    v7 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v8 = v7[106];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v8 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v8 + 36))(v8, &v41, 4, 1) >= 0 )
      v2[124] = v41;
    v9 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v10 = v9[107];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v10 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v10 + 36))(v10, &v41, 4, 1) >= 0 )
      v2[125] = v41;
    v11 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v12 = v11[108];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v12 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v12 + 36))(v12, &v41, 4, 1) >= 0 )
      v2[126] = v41;
    v13 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v14 = v13[109];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v14 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v14 + 36))(v14, &v41, 4, 1) >= 0 )
      v2[127] = v41;
    v15 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v16 = v15[110];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v16 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v16 + 36))(v16, &v41, 4, 1) >= 0 )
      v2[128] = v41;
    v17 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v18 = v17[111];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v18 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v18 + 36))(v18, &v41, 4, 1) >= 0 )
      v2[129] = v41;
    v19 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v20 = v19[112];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v20 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v20 + 36))(v20, &v41, 4, 1) >= 0 )
      v2[130] = v41;
    v21 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v22 = v21[113];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v22 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v22 + 36))(v22, &v41, 4, 1) >= 0 )
      v2[131] = v41;
    v23 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v24 = v23[114];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v24 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v24 + 36))(v24, &v41, 4, 1) >= 0 )
      v2[132] = v41;
    v25 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v26 = v25[115];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v26 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v26 + 36))(v26, &v41, 4, 1) >= 0 )
      v2[133] = v41;
    v27 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v28 = v27[116];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v28 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v28 + 36))(v28, &v41, 4, 1) >= 0 )
      v2[134] = v41;
    v29 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v30 = v29[117];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v30 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v30 + 36))(v30, &v41, 4, 1) >= 0 )
      v2[135] = v41;
    v31 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v32 = v31[118];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v32 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v32 + 36))(v32, &v41, 4, 1) >= 0 )
      v2[136] = v41;
    v33 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v34 = v33[119];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v34 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v34 + 36))(v34, &v41, 4, 1) >= 0 )
      v2[137] = v41;
    v35 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v36 = v35[120];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v36 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v36 + 36))(v36, &v41, 4, 1) >= 0 )
      v2[138] = v41;
    v37 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v38 = v37[121];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v38 && (*(int (__stdcall **)(int, float *, int, int))(*(_DWORD *)v38 + 36))(v38, &v41, 4, 1) >= 0 )
      v2[139] = v41;
    v39 = (char *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v40 = (wchar_t *)(v39 + 3196);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    sub_419310(
      v40,
      aGpuidleFVertex,
      v2[122],
      v2[123],
      v2[124],
      v2[125],
      v2[126],
      v2[127],
      v2[128],
      v2[129],
      v2[130],
      v2[131],
      v2[132],
      v2[133],
      v2[134],
      v2[135],
      v2[136],
      v2[137],
      v2[138],
      v2[139]);
  }
}
