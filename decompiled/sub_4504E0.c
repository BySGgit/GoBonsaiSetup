void __fastcall sub_4504E0(int a1, int a2, int a3, float *a4, int a5, int a6, int a7, int a8)
{
  _DWORD *EngineInstance; // esi
  int *v9; // ebx
  int v10; // eax
  void (__stdcall *v11)(int *, int, _BYTE *); // edx
  void (__stdcall *v12)(int *, int, _BYTE *); // edx
  float v13; // [esp+34h] [ebp-204h]
  float v14; // [esp+50h] [ebp-1E8h]
  float v15; // [esp+50h] [ebp-1E8h]
  float v16[16]; // [esp+54h] [ebp-1E4h] BYREF
  int v17; // [esp+98h] [ebp-1A0h]
  int v18; // [esp+9Ch] [ebp-19Ch]
  int v19; // [esp+A0h] [ebp-198h]
  float v20[18]; // [esp+A4h] [ebp-194h] BYREF
  _BYTE v21[48]; // [esp+ECh] [ebp-14Ch] BYREF
  float v22; // [esp+11Ch] [ebp-11Ch]
  float v23; // [esp+120h] [ebp-118h]
  float v24; // [esp+124h] [ebp-114h]
  _BYTE v25[64]; // [esp+12Ch] [ebp-10Ch] BYREF
  _BYTE v26[64]; // [esp+16Ch] [ebp-CCh] BYREF
  _BYTE v27[64]; // [esp+1ACh] [ebp-8Ch] BYREF
  _BYTE v28[68]; // [esp+1ECh] [ebp-4Ch] BYREF

  v18 = a3;
  v17 = a1;
  v19 = a2;
  if ( a5 > 0 && 0.0 != a4[3] )
  {
    EngineInstance = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v9 = (int *)EngineInstance[1];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    (*(void (__stdcall **)(int *, int, _BYTE *))(*v9 + 180))(v9, 2, v26);
    (*(void (__stdcall **)(int *, int, _BYTE *))(*v9 + 180))(v9, 3, v27);
    v10 = *v9;
    v16[0] = 1.0;
    v11 = *(void (__stdcall **)(int *, int, _BYTE *))(v10 + 176);
    v16[1] = 0.0;
    v16[2] = 0.0;
    v16[3] = 0.0;
    v16[4] = 0.0;
    v16[6] = 0.0;
    v16[7] = 0.0;
    v16[8] = 0.0;
    v16[9] = 0.0;
    v16[11] = 0.0;
    v16[12] = 0.0;
    v16[13] = 0.0;
    v16[14] = 0.0;
    v16[5] = 1.0;
    v16[10] = 1.0;
    v16[15] = 1.0;
    qmemcpy(v25, v16, sizeof(v25));
    v11(v9, 2, v25);
    v12 = *(void (__stdcall **)(int *, int, _BYTE *))(*v9 + 176);
    v16[0] = 1.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    v16[3] = 0.0;
    v16[4] = 0.0;
    v16[6] = 0.0;
    v16[7] = 0.0;
    v16[8] = 0.0;
    v16[9] = 0.0;
    v16[11] = 0.0;
    v16[12] = 0.0;
    v16[13] = 0.0;
    v16[14] = 0.0;
    v16[5] = 1.0;
    v16[10] = 1.0;
    v16[15] = 1.0;
    qmemcpy(v25, v16, sizeof(v25));
    v12(v9, 3, v25);
    v14 = -2.0 / (double)dword_4CA62C;
    v13 = v14;
    v15 = 2.0 / (double)dword_4CA628;
    D3DXMatrixScaling(v21, LODWORD(v15), LODWORD(v13), 0.0);
    v22 = v22 - 1.0;
    v23 = v23 + 1.0;
    v24 = v24 + 0.0;
    D3DXMatrixMultiply(v25, v18, v21);
    qmemcpy(v28, v25, 0x40u);
    (*(void (__stdcall **)(int *, int, _BYTE *))(*v9 + 176))(v9, 256, v28);
    (*(void (__stdcall **)(int *, _DWORD, int))(*v9 + 260))(v9, 0, v17);
    v20[0] = *a4;
    v20[1] = a4[1];
    v20[2] = a4[2];
    v20[3] = a4[3];
    v20[4] = *a4;
    v20[5] = a4[1];
    v20[6] = a4[2];
    v20[7] = 1.0;
    v20[8] = 0.0;
    v20[9] = 0.0;
    v20[10] = 0.0;
    v20[11] = 0.0;
    v20[12] = 0.0;
    v20[13] = 0.0;
    v20[14] = 0.0;
    v20[15] = 0.0;
    v20[16] = 0.0;
    (*(void (__stdcall **)(int *, float *))(*v9 + 196))(v9, v20);
    (*(void (__stdcall **)(int *, _DWORD, int, _DWORD, int))(*v9 + 400))(v9, 0, v19, 0, a7);
    (*(void (__stdcall **)(int *, int))(*v9 + 356))(v9, a8);
    (*(void (__stdcall **)(int *, int, _DWORD, int))(*v9 + 324))(v9, a6, 0, a5);
    (*(void (__stdcall **)(int *, int, _BYTE *))(*v9 + 176))(v9, 2, v26);
    (*(void (__stdcall **)(int *, int, _BYTE *))(*v9 + 176))(v9, 3, v27);
  }
}
