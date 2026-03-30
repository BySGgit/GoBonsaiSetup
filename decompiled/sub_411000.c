void __thiscall sub_411000(float *this)
{
  int EngineInstance; // esi
  int *v3; // ebx
  float *v4; // eax
  int v5; // eax
  void (__stdcall *v6)(int *, float *); // edx
  int v7; // eax
  _DWORD *v8; // eax
  int v9; // eax
  _DWORD *v10; // eax
  int v11; // edx
  void (__stdcall *v12)(int *, _DWORD, _DWORD *); // edx
  int v13; // eax
  _DWORD *v14; // eax
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  int v17; // eax
  int v18; // esi
  int v19; // esi
  int v20; // esi
  int v21; // esi
  int v22; // esi
  int v23; // esi
  int v24; // esi
  int v25; // esi
  int v26; // esi
  int v27; // esi
  int v28; // eax
  int v29; // eax
  float *v30; // ebx
  int v31; // esi
  int v32; // eax
  float *v34; // [esp+254h] [ebp-374h]
  float v35; // [esp+258h] [ebp-370h]
  float v36; // [esp+258h] [ebp-370h]
  int v37; // [esp+258h] [ebp-370h]
  float v38; // [esp+25Ch] [ebp-36Ch] BYREF
  float v39; // [esp+260h] [ebp-368h]
  float v40; // [esp+264h] [ebp-364h]
  float v41; // [esp+268h] [ebp-360h]
  int v42; // [esp+26Ch] [ebp-35Ch]
  float v43; // [esp+270h] [ebp-358h]
  float v44; // [esp+274h] [ebp-354h]
  float v45; // [esp+278h] [ebp-350h]
  float v46; // [esp+27Ch] [ebp-34Ch]
  float v47; // [esp+280h] [ebp-348h]
  int v48; // [esp+29Ch] [ebp-32Ch] BYREF
  int v49; // [esp+2A0h] [ebp-328h]
  int v50; // [esp+2A4h] [ebp-324h]
  float v51[4]; // [esp+2A8h] [ebp-320h] BYREF
  float v52[27]; // [esp+2B8h] [ebp-310h] BYREF
  _DWORD v53[26]; // [esp+330h] [ebp-298h] BYREF
  _DWORD v54[26]; // [esp+398h] [ebp-230h] BYREF
  _BYTE v55[64]; // [esp+400h] [ebp-1C8h] BYREF
  _BYTE v56[64]; // [esp+440h] [ebp-188h] BYREF
  _BYTE v57[64]; // [esp+480h] [ebp-148h] BYREF
  _BYTE v58[64]; // [esp+4C0h] [ebp-108h] BYREF
  _BYTE v59[64]; // [esp+500h] [ebp-C8h] BYREF
  _BYTE v60[64]; // [esp+540h] [ebp-88h] BYREF
  _BYTE v61[68]; // [esp+580h] [ebp-48h] BYREF

  if ( byte_4D52D0 )
  {
    EngineInstance = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v3 = *(int **)(EngineInstance + 4);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v4 = (float *)sub_40D6C0(dword_4D7EEC);
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))D3DXMatrixTranslation)(v61, *v4, v4[1], v4[2]);
    (*(void (__stdcall **)(int *, int, int))(*v3 + 228))(v3, 143, 1);
    (*(void (__stdcall **)(int *, int, int))(*v3 + 228))(v3, 137, 1);
    (*(void (__stdcall **)(int *, int, int))(*v3 + 228))(v3, 19, 5);
    (*(void (__stdcall **)(int *, int, int))(*v3 + 228))(v3, 20, 6);
    (*(void (__stdcall **)(int *, int, _DWORD))(*v3 + 228))(v3, 27, 0);
    (*(void (__stdcall **)(int *, int, _DWORD))(*v3 + 228))(v3, 15, 0);
    (*(void (__stdcall **)(int *, int, _DWORD))(*v3 + 228))(v3, 7, 0);
    (*(void (__stdcall **)(int *, int, _DWORD))(*v3 + 228))(v3, 14, 0);
    (*(void (__stdcall **)(int *, int, int))(*v3 + 228))(v3, 22, 2);
    (*(void (__stdcall **)(int *, _DWORD, _DWORD))(*v3 + 260))(v3, 0, 0);
    v52[0] = 1.0;
    v52[1] = 1.0;
    v52[2] = 1.0;
    v52[3] = 1.0;
    v52[4] = 1.0;
    v52[5] = 1.0;
    v52[6] = 1.0;
    v5 = *v3;
    v52[7] = 1.0;
    v6 = *(void (__stdcall **)(int *, float *))(v5 + 196);
    v52[8] = 0.0;
    v52[9] = 0.0;
    v52[10] = 0.0;
    v52[11] = 0.0;
    v52[12] = 0.0;
    v52[13] = 0.0;
    v52[14] = 0.0;
    v52[15] = 0.0;
    v52[16] = 0.0;
    v6(v3, v52);
    sub_411EA0(this);
    v48 = dword_4D5320;
    v49 = dword_4D5324;
    v50 = dword_4D5328;
    memset(v54, 0, sizeof(v54));
    v54[0] = 1;
    sub_401470(10.0);
    sub_401470(2.0);
    v7 = sub_40D6C0(dword_4D7EEC);
    v8 = (_DWORD *)sub_401430(v7);
    v54[13] = *v8;
    v54[14] = v8[1];
    v9 = v8[2];
    v43 = 1.0;
    v44 = 1.0;
    v45 = 1.0;
    *(float *)&v54[1] = 1.0;
    v46 = 1.0;
    v54[15] = v9;
    *(float *)&v54[4] = 1.0;
    *(float *)&v54[2] = 1.0;
    *(float *)&v54[3] = 1.0;
    v10 = (_DWORD *)sub_408590(&flt_4D538C);
    v54[16] = *v10;
    v54[17] = v10[1];
    v11 = v10[2];
    *(float *)&v54[19] = 100.0;
    v54[18] = v11;
    v12 = *(void (__stdcall **)(int *, _DWORD, _DWORD *))(*v3 + 204);
    *(float *)&v54[21] = 2.0;
    v12(v3, 0, v54);
    (*(void (__stdcall **)(int *, _DWORD, int))(*v3 + 212))(v3, 0, 1);
    memset(v53, 0, sizeof(v53));
    v53[0] = 3;
    sub_401470(10.0);
    sub_401470(3.0);
    v13 = sub_40D6C0(dword_4D7EEC);
    v14 = (_DWORD *)sub_4013F0(v13);
    v53[13] = *v14;
    v53[14] = v14[1];
    v53[15] = v14[2];
    v15 = (_DWORD *)sub_40FF00(&v38, v51);
    v53[1] = *v15;
    v53[2] = v15[1];
    v53[3] = v15[2];
    v53[4] = v15[3];
    *(float *)&v53[9] = v38;
    *(float *)&v53[10] = v39;
    *(float *)&v53[11] = v40;
    *(float *)&v53[12] = v41;
    v16 = (_DWORD *)sub_408590(&flt_4D538C);
    v53[16] = *v16;
    v53[17] = v16[1];
    v17 = v16[2];
    *(float *)&v53[19] = 200.0;
    v53[18] = v17;
    *(float *)&v53[21] = 1.0;
    (*(void (__stdcall **)(int *, int, _DWORD *))(*v3 + 204))(v3, 1, v53);
    (*(void (__stdcall **)(int *, int, int))(*v3 + 212))(v3, 1, 1);
    D3DXMatrixScaling(v55, 10.0, 10.0, 10.0);
    D3DXMatrixMultiply(v57, v55, v61);
    qmemcpy(v56, v57, sizeof(v56));
    (*(void (__stdcall **)(int *, int, _BYTE *))(*v3 + 176))(v3, 256, v56);
    (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)dword_4D7EC8 + 12))(dword_4D7EC8, 0);
    (*(void (__stdcall **)(int *, int, int))(*v3 + 228))(v3, 143, 1);
    (*(void (__stdcall **)(int *, int, int))(*v3 + 228))(v3, 137, 1);
    (*(void (__stdcall **)(int *, int, int))(*v3 + 228))(v3, 19, 5);
    (*(void (__stdcall **)(int *, int, int))(*v3 + 228))(v3, 20, 6);
    (*(void (__stdcall **)(int *, int, int))(*v3 + 228))(v3, 27, 1);
    (*(void (__stdcall **)(int *, int, _DWORD))(*v3 + 228))(v3, 15, 0);
    (*(void (__stdcall **)(int *, int, _DWORD))(*v3 + 228))(v3, 7, 0);
    (*(void (__stdcall **)(int *, int, _DWORD))(*v3 + 228))(v3, 14, 0);
    (*(void (__stdcall **)(int *, int, int))(*v3 + 228))(v3, 22, 3);
    v51[0] = 0.0;
    v51[1] = 0.0;
    v51[2] = 0.0;
    v51[3] = 1.0;
    memset(v52, 0, 0x68u);
    v52[19] = 1000.0;
    v52[1] = 0.0;
    v52[3] = 0.0;
    LODWORD(v52[0]) = 3;
    v52[2] = 0.0;
    v52[4] = 1.0;
    v52[16] = flt_4D538C;
    v52[17] = flt_4D5390;
    v52[18] = flt_4D5394;
    v18 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v19 = *(_DWORD *)(v18 + 4);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    (*(void (__stdcall **)(int, _DWORD, float *))(*(_DWORD *)v19 + 204))(v19, 0, v52);
    v20 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v21 = *(_DWORD *)(v20 + 4);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    (*(void (__stdcall **)(int, _DWORD, int))(*(_DWORD *)v21 + 212))(v21, 0, 1);
    v22 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v23 = *(_DWORD *)(v22 + 4);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v23 + 228))(v23, 139, -1);
    if ( byte_4CA64B )
    {
      (*(void (__stdcall **)(int *, int, int))(*v3 + 228))(v3, 20, 2);
      v24 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v25 = *(_DWORD *)(v24 + 4);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v25 + 228))(v25, 137, 0);
      v38 = 1.0;
      v39 = 1.0;
      v40 = 1.0;
      v41 = 0.0;
      v35 = *((float *)dword_4D82D0 + 67) / 365.0;
      v36 = v35 * 1.570796370506287;
      D3DXMatrixRotationAxis(v56, this + 649, LODWORD(v36));
      D3DXMatrixMultiply(v57, v56, v61);
      qmemcpy(v55, v57, sizeof(v55));
      sub_44F2A0(v55, dword_4D8040, dword_4D7ECC, dword_4D7ED4, dword_4D7ED0, dword_4D7EDC, dword_4D7EE0);
      v26 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v27 = *(_DWORD *)(v26 + 4);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v27 + 228))(v27, 137, 1);
      (*(void (__stdcall **)(int *, int, int))(*v3 + 228))(v3, 20, 6);
    }
    if ( byte_4D523F )
    {
      v48 = dword_4D5320;
      v49 = dword_4D5324;
      v50 = dword_4D5328;
      sub_401470(flt_4D52C4);
      v28 = sub_4015F0(dword_4D7EEC + 104);
      sub_401430(v28);
      D3DXMatrixScaling(v60, LODWORD(flt_4D52C8), LODWORD(flt_4D52C8), 1.0);
      v29 = sub_4015F0(dword_4D7EEC + 104);
      D3DXMatrixLookAtLH(v56, &v48, v29, &flt_4D538C);
      D3DXMatrixInverse(v57, 0, v56);
      qmemcpy(v55, v57, sizeof(v55));
      D3DXMatrixMultiply(v59, v60, v55);
      qmemcpy(v58, v59, sizeof(v58));
      sub_44F2A0(v58, dword_4D81D8, dword_4D7FA0, dword_4D7FA8, dword_4D7FA4, dword_4D7FB0, dword_4D7FB4);
    }
    if ( byte_4D523E )
    {
      v34 = this + 107;
      v37 = 10;
      do
      {
        v30 = v34 - 55;
        v42 = 5;
        do
        {
          v47 = flt_4D5280 * *v30;
          ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))D3DXMatrixScaling)(v60, *v30, LODWORD(v47), 1.0);
          v31 = sub_4015F0(dword_4D7EEC + 104);
          v32 = sub_4013F0(v34 - 3);
          D3DXMatrixLookAtLH(v58, v32, v31, &flt_4D538C);
          ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))D3DXMatrixRotationYawPitchRoll)(v56, 0.0, 0.0, v30[4]);
          D3DXMatrixInverse(v59, 0, v58);
          qmemcpy(v55, v59, sizeof(v55));
          D3DXMatrixMultiply(v57, v56, v60);
          qmemcpy(v54, v57, 0x40u);
          D3DXMatrixMultiply(v53, v54, v55);
          v38 = 1.0;
          v39 = 1.0;
          v40 = 1.0;
          qmemcpy(v52, v53, 0x40u);
          v41 = v30[6] * flt_4D52C0 * *v34;
          sub_44F2A0(v52, dword_4D810C, dword_4D7FA0, dword_4D7FA8, dword_4D7FA4, dword_4D7FB0, dword_4D7FB4);
          v30 += 11;
          --v42;
        }
        while ( v42 );
        v34 += 60;
        --v37;
      }
      while ( v37 );
    }
  }
}
