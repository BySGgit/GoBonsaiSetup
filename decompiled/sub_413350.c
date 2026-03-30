void sub_413350()
{
  _DWORD *v0; // ebx
  _DWORD *EngineInstance; // esi
  int v2; // edi
  _DWORD *v3; // esi
  int v4; // esi
  _DWORD *v5; // esi
  int v6; // esi
  _DWORD *v7; // esi
  int v8; // esi
  float *v9; // ebx
  float *v10; // esi
  void (__thiscall *v11)(float *, float *, _DWORD); // edx
  float *v12; // ecx
  float v13; // [esp+1ACh] [ebp-1C8h]
  float *v14; // [esp+1C4h] [ebp-1B0h] BYREF
  float v15; // [esp+1C8h] [ebp-1ACh] BYREF
  float v16; // [esp+1CCh] [ebp-1A8h]
  float v17; // [esp+1D0h] [ebp-1A4h]
  float v18; // [esp+1D4h] [ebp-1A0h]
  _DWORD v19[2]; // [esp+1D8h] [ebp-19Ch] BYREF
  float v20[3]; // [esp+1E0h] [ebp-194h] BYREF
  float v21[4]; // [esp+1ECh] [ebp-188h] BYREF
  void *v22; // [esp+1FCh] [ebp-178h] BYREF
  float v23; // [esp+200h] [ebp-174h] BYREF
  float v24; // [esp+204h] [ebp-170h]
  float v25; // [esp+208h] [ebp-16Ch]
  int v26; // [esp+20Ch] [ebp-168h]
  unsigned int v27; // [esp+210h] [ebp-164h]
  float v28[3]; // [esp+218h] [ebp-15Ch] BYREF
  float v29[3]; // [esp+224h] [ebp-150h] BYREF
  float v30[3]; // [esp+230h] [ebp-144h] BYREF
  _DWORD v31[26]; // [esp+23Ch] [ebp-138h] BYREF
  _BYTE v32[64]; // [esp+2A4h] [ebp-D0h] BYREF
  _BYTE v33[64]; // [esp+2E4h] [ebp-90h] BYREF
  _BYTE v34[64]; // [esp+324h] [ebp-50h] BYREF
  int v35; // [esp+370h] [ebp-4h]

  v0 = dword_4D82D0;
  v14 = (float *)dword_4D82D0;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = EngineInstance[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)v2 + 268))(v2, 0, 1, 4);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)v2 + 268))(v2, 0, 2, 2);
  (*(void (__stdcall **)(int, _DWORD, int, _DWORD))(*(_DWORD *)v2 + 268))(v2, 0, 3, 0);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)v2 + 268))(v2, 0, 4, 4);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)v2 + 268))(v2, 0, 5, 2);
  (*(void (__stdcall **)(int, _DWORD, int, _DWORD))(*(_DWORD *)v2 + 268))(v2, 0, 6, 0);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)v2 + 276))(v2, 0, 6, 2);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)v2 + 276))(v2, 0, 5, 2);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)v2 + 276))(v2, 0, 7, 2);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v2 + 228))(v2, 145, 1);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v2 + 228))(v2, 147, 1);
  (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v2 + 228))(v2, 26, 0);
  (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v2 + 228))(v2, 29, 0);
  if ( (dword_4DBC8C & 1) == 0 )
  {
    dword_4DBC8C |= 1u;
    v35 = 0;
    v27 = 7;
    v26 = 0;
    LOWORD(v22) = 0;
    sub_4032D0(L"specularEnable", (int)&v22, 0xEu);
    LOBYTE(v35) = 1;
    sub_4038B0(&v22, (int)&unk_4DBC68, (int)&byte_4D6338);
    if ( v27 >= 8 )
      operator delete(v22);
    atexit(sub_472400);
    v35 = -1;
  }
  (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v2 + 228))(v2, 29, (unsigned __int8)byte_4D6338);
  (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v2 + 228))(v2, 139, 0);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v2 + 228))(v2, 27, 1);
  (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v2 + 228))(v2, 15, 0);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)v2 + 276))(v2, 0, 1, 1);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)v2 + 276))(v2, 0, 2, 1);
  sub_44E030(dword_4D7EEC);
  (*(void (__thiscall **)(_DWORD *))(v0[8] + 20))(v0 + 8);
  v15 = 0.0;
  v16 = 0.0;
  v17 = 0.0;
  v18 = 1.0;
  memset(v31, 0, sizeof(v31));
  *(float *)&v31[19] = 1000.0;
  *(float *)&v31[1] = 0.0;
  v31[0] = 3;
  *(float *)&v31[2] = 0.0;
  *(float *)&v31[3] = 0.0;
  *(float *)&v31[4] = 1.0;
  *(float *)&v31[16] = flt_4D538C;
  *(float *)&v31[17] = flt_4D5390;
  *(float *)&v31[18] = flt_4D5394;
  v3 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = v3[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, _DWORD, _DWORD *))(*(_DWORD *)v4 + 204))(v4, 0, v31);
  v5 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v6 = v5[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, _DWORD, int))(*(_DWORD *)v6 + 212))(v6, 0, 1);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v2 + 228))(v2, 139, -1);
  sub_44E830();
  v7 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v8 = v7[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v8 + 228))(v8, 7, 0);
  v9 = v14;
  v14 = (float *)*((_DWORD *)v14 + 65);
  sub_451210(v19, (unsigned int *)&v14);
  if ( v19[0] != dword_4D8C10 )
  {
    v10 = *(float **)(v19[0] + 12);
    if ( v10 )
    {
      if ( (dword_4D7CF8 & 1) == 0 )
      {
        dword_4D7CF8 |= 1u;
        v35 = 2;
        sub_4079C0();
        v35 = -1;
      }
      if ( byte_4D8225[11 * *((_DWORD *)v10 + 1)] && !(_BYTE)word_4D8CA3 && !byte_4D7F9D )
      {
        *(float *)&v22 = 1.0;
        v23 = flt_4D638C;
        v24 = 0.0;
        v25 = 0.60000002;
        v20[2] = 0.60000002;
        *(float *)&v19[1] = 0.0;
        v20[0] = flt_4D638C;
        v20[1] = 1.0;
        v21[0] = 1.0;
        v21[1] = 0.94999999;
        v21[2] = 0.0;
        v21[3] = 0.30000001;
        v15 = 1.0;
        v16 = 1.0;
        v17 = 1.0;
        v18 = 0.2;
        v13 = 1.3;
        v11 = *(void (__thiscall **)(float *, float *, _DWORD))(*(_DWORD *)v10 + 28);
        if ( v10[111] < 0.69999999 )
        {
          v11(v10, v21, LODWORD(v13));
          v12 = &v23;
        }
        else
        {
          v11(v10, &v15, LODWORD(v13));
          v12 = v20;
        }
        (*(void (__thiscall **)(float *, float *))(*(_DWORD *)v10 + 24))(v10, v12);
      }
    }
  }
  (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v2 + 228))(v2, 7, 0);
  (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v2 + 228))(v2, 14, 0);
  v29[0] = 0.0;
  v29[1] = 0.0;
  v29[2] = -10.0;
  v30[0] = 0.0;
  v30[1] = 0.0;
  v30[2] = 0.0;
  v28[0] = 0.0;
  v28[1] = 1.0;
  v28[2] = 0.0;
  D3DXMatrixLookAtLH(v32, v29, v30, v28);
  (*(void (__stdcall **)(int, int, _BYTE *))(*(_DWORD *)v2 + 176))(v2, 2, v32);
  D3DXMatrixOrthoLH(v34, 1.0, 1.0, 1.0, 100.0);
  (*(void (__stdcall **)(int, int, _BYTE *))(*(_DWORD *)v2 + 176))(v2, 3, v34);
  if ( v9[66] < 1.0 )
  {
    *(float *)&v22 = 0.0;
    v23 = 0.0;
    v24 = 0.0;
    v25 = 1.0 - v9[66];
    D3DXMatrixScaling(v33, LODWORD(flt_4D63B0), LODWORD(flt_4D63B0), LODWORD(flt_4D63B0));
    sub_44F2A0(
      (float *)&v22,
      (int)v33,
      dword_4D8040[0],
      dword_4D7FA0,
      dword_4D7FA8,
      dword_4D7FA4,
      dword_4D7FB0,
      dword_4D7FB4);
  }
}
