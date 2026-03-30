void sub_44FBA0()
{
  _DWORD *EngineInstance; // esi
  int v1; // esi
  float *v2; // eax
  float v3; // edx
  float v4; // ecx
  float *v5; // eax
  float v6; // ecx
  float v7; // edx
  float *v8; // eax
  float v9; // ecx
  float v10; // edx
  float *v11; // eax
  float v12; // edx
  float v13; // ecx
  float *v14; // eax
  float v15; // edx
  float *v16; // eax
  float *v17; // eax
  float v18; // edx
  float *v19; // eax
  float *v20; // eax
  float v21; // edx
  float v22; // ecx
  float *v23; // eax
  float v24; // ecx
  float v25; // edx
  float *v26; // eax
  float v27; // edx
  float *v28; // [esp+30h] [ebp-10h] BYREF
  float v29; // [esp+34h] [ebp-Ch]
  float v30; // [esp+38h] [ebp-8h]
  float v31; // [esp+3Ch] [ebp-4h]

  if ( !dword_4D7FA0 )
  {
    dword_4D7FA8 = 4;
    dword_4D7FAC = 6;
    dword_4D7FA4 = 5;
    dword_4D7FB0 = 32;
    dword_4D7FB4 = 274;
    EngineInstance = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v1 = EngineInstance[1];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( (*(int (__stdcall **)(int, int, int, int, int, int *, _DWORD))(*(_DWORD *)v1 + 104))(
           v1,
           dword_4D7FAC * dword_4D7FB0,
           8,
           dword_4D7FB4,
           1,
           &dword_4D7FA0,
           0) >= 0
      && (*(int (__stdcall **)(int, _DWORD, _DWORD, float **, _DWORD))(*(_DWORD *)dword_4D7FA0 + 44))(
           dword_4D7FA0,
           0,
           0,
           &v28,
           0) >= 0 )
    {
      *v28 = -1.0;
      v28[1] = 1.0;
      v30 = 0.0;
      v28[2] = 0.0;
      v31 = -1.0;
      v2 = v28;
      v3 = v30;
      v28[3] = 0.0;
      v4 = v31;
      v2[4] = v3;
      v2[5] = v4;
      v28[6] = 0.0;
      v28[7] = 0.0;
      v5 = v28;
      v31 = 0.0;
      v28[8] = 1.0;
      v6 = v31;
      v29 = 0.0;
      v5[9] = 1.0;
      v30 = 0.0;
      v7 = v29;
      v5[10] = v6;
      v31 = -1.0;
      v8 = v28;
      v9 = v30;
      v28[11] = v7;
      v10 = v31;
      v8[12] = v9;
      v8[13] = v10;
      v28[14] = 1.0;
      v28[15] = 0.0;
      v11 = v28;
      v31 = 0.0;
      v28[16] = -1.0;
      v12 = v31;
      v29 = 0.0;
      v11[17] = -1.0;
      v30 = 0.0;
      v13 = v29;
      v11[18] = v12;
      v31 = -1.0;
      v14 = v28;
      v15 = v30;
      v28[19] = v13;
      v14[20] = v15;
      v14[21] = v31;
      v28[22] = 0.0;
      v28[23] = 1.0;
      v16 = v28;
      v28[24] = 1.0;
      v16[25] = -1.0;
      v16[26] = 0.0;
      v17 = v28;
      v31 = 1.0;
      v28[27] = 0.0;
      v18 = v31;
      v17[28] = 0.0;
      v17[29] = v18;
      v28[30] = 1.0;
      v28[31] = 1.0;
      v19 = v28;
      v28[32] = -1.0;
      v19[33] = 1.0;
      v30 = 0.0;
      v19[34] = 0.0;
      v20 = v28;
      v31 = 1.0;
      v21 = v30;
      v28[35] = 0.0;
      v22 = v31;
      v20[36] = v21;
      v20[37] = v22;
      v28[38] = 0.0;
      v28[39] = 0.0;
      v23 = v28;
      v31 = 0.0;
      v28[40] = 1.0;
      v24 = v31;
      v29 = 0.0;
      v23[41] = 1.0;
      v30 = 0.0;
      v25 = v29;
      v23[42] = v24;
      v31 = 1.0;
      v26 = v28;
      v28[43] = v25;
      v27 = v31;
      v26[44] = v30;
      v26[45] = v27;
      v28[46] = 1.0;
      v28[47] = 0.0;
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D7FA0 + 48))(dword_4D7FA0);
    }
  }
}
