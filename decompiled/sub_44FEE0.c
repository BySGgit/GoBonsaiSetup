void sub_44FEE0()
{
  unsigned int v0; // ebx
  _DWORD *EngineInstance; // edi
  int v2; // edi
  double v3; // st6
  unsigned int v4; // edx
  int v5; // esi
  int v6; // ecx
  float *v7; // eax
  int v8; // edi
  int v9; // eax
  double v10; // st7
  unsigned int v11; // eax
  int v12; // edx
  float *v13; // ecx
  double v14; // rt0
  double v15; // rt1
  double v16; // st6
  unsigned int v17; // edi
  double v18; // st7
  unsigned int v19; // esi
  int v20; // edi
  _DWORD *v21; // eax
  int v22; // [esp+3Ch] [ebp-FCh] BYREF
  unsigned int v23; // [esp+40h] [ebp-F8h]
  float v24; // [esp+44h] [ebp-F4h] BYREF
  float v25; // [esp+48h] [ebp-F0h]
  float v26; // [esp+4Ch] [ebp-ECh]
  float v27; // [esp+50h] [ebp-E8h]
  float v28; // [esp+54h] [ebp-E4h]
  float v29; // [esp+58h] [ebp-E0h]
  float v30; // [esp+5Ch] [ebp-DCh]
  float v31; // [esp+60h] [ebp-D8h]
  float v32; // [esp+64h] [ebp-D4h]
  float v33; // [esp+68h] [ebp-D0h]
  float v34; // [esp+6Ch] [ebp-CCh]
  float v35; // [esp+70h] [ebp-C8h]
  float v36; // [esp+74h] [ebp-C4h]
  float v37; // [esp+78h] [ebp-C0h]
  float v38; // [esp+7Ch] [ebp-BCh]
  float v39; // [esp+80h] [ebp-B8h]
  float v40; // [esp+84h] [ebp-B4h]
  float v41; // [esp+88h] [ebp-B0h]
  float v42; // [esp+8Ch] [ebp-ACh]
  float v43; // [esp+90h] [ebp-A8h]
  float v44; // [esp+94h] [ebp-A4h]
  float v45; // [esp+98h] [ebp-A0h]
  float v46; // [esp+9Ch] [ebp-9Ch]
  float v47; // [esp+A0h] [ebp-98h]
  _DWORD v48[36]; // [esp+A4h] [ebp-94h]

  v0 = 0;
  if ( !dword_4D7FD0 )
  {
    dword_4D7FD8 = 12;
    dword_4D7FDC = 36;
    dword_4D7FD4 = 4;
    dword_4D7FE0 = 32;
    dword_4D7FE4 = 274;
    EngineInstance = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v2 = EngineInstance[1];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( (*(int (__stdcall **)(int, int, int, int, int, int *, _DWORD))(*(_DWORD *)v2 + 104))(
           v2,
           dword_4D7FDC * dword_4D7FE0,
           8,
           dword_4D7FE4,
           1,
           &dword_4D7FD0,
           0) >= 0
      && (*(int (__stdcall **)(int, _DWORD, _DWORD, int *, _DWORD))(*(_DWORD *)dword_4D7FD0 + 44))(
           dword_4D7FD0,
           0,
           0,
           &v22,
           0) >= 0 )
    {
      v24 = 1.0;
      v25 = 1.0;
      v26 = 1.0;
      v27 = 1.0;
      v28 = -1.0;
      v29 = 1.0;
      v3 = 1.0;
      v30 = -1.0;
      v31 = -1.0;
      v32 = 1.0;
      v33 = -1.0;
      v34 = 1.0;
      v35 = 1.0;
      v36 = 1.0;
      v37 = 1.0;
      v38 = -1.0;
      v39 = 1.0;
      v41 = -1.0;
      v40 = -1.0;
      v42 = -1.0;
      v43 = -1.0;
      v44 = -1.0;
      v45 = -1.0;
      v46 = 1.0;
      v47 = -1.0;
      v48[0] = 5;
      v48[8] = 3;
      v48[10] = 3;
      v48[13] = 5;
      v48[17] = 5;
      v48[18] = 5;
      v48[27] = 3;
      v48[30] = 3;
      v4 = 0;
      v48[1] = 4;
      v48[2] = 6;
      v48[3] = 7;
      v48[4] = 6;
      v48[5] = 4;
      v48[6] = 7;
      v48[7] = 4;
      v48[9] = 0;
      v48[11] = 4;
      v48[12] = 4;
      v48[14] = 0;
      v48[15] = 1;
      v48[16] = 0;
      v48[19] = 6;
      v48[20] = 1;
      v48[21] = 2;
      v48[22] = 1;
      v48[23] = 6;
      v48[24] = 6;
      v48[25] = 7;
      v48[26] = 2;
      v48[28] = 2;
      v48[29] = 7;
      v48[31] = 0;
      v48[32] = 2;
      v48[33] = 1;
      v48[34] = 2;
      v48[35] = 0;
      if ( dword_4D7FDC )
      {
        v5 = 0;
        do
        {
          v6 = v22;
          v7 = &v24 + 3 * v48[v4];
          *(float *)(v22 + v5) = *v7;
          v8 = *((_DWORD *)v7 + 1);
          v9 = *((_DWORD *)v7 + 2);
          *(_DWORD *)(v6 + v5 + 4) = v8;
          *(_DWORD *)(v6 + v5 + 8) = v9;
          ++v4;
          v5 += 32;
        }
        while ( v4 < dword_4D7FDC );
      }
      v24 = 0.0;
      v26 = -1.0;
      v25 = 0.0;
      v27 = 0.0;
      v29 = 0.0;
      v28 = 1.0;
      v30 = 1.0;
      v31 = 0.0;
      v32 = 1.0;
      v33 = 0.0;
      v34 = -1.0;
      v35 = 0.0;
      v10 = 0.0;
      v38 = 0.0;
      v36 = -1.0;
      v37 = 0.0;
      v41 = 1.0;
      v39 = 0.0;
      v40 = 0.0;
      v11 = 0;
      v12 = 0;
      v13 = &v24;
      while ( 1 )
      {
        v15 = v3;
        v16 = v10;
        *(float *)(v12 + v22 + 24) = v10;
        *(float *)(v12 + v22 + 28) = v10;
        v17 = v11 + 6;
        *(float *)(v12 + v22 + 56) = v15;
        v23 = v11 + 6;
        *(float *)(v12 + v22 + 60) = v10;
        *(float *)(v12 + v22 + 88) = v10;
        *(float *)(v12 + v22 + 92) = v15;
        *(float *)(v12 + v22 + 120) = v15;
        *(float *)(v12 + v22 + 124) = v15;
        *(float *)(v12 + v22 + 152) = v10;
        *(float *)(v12 + v22 + 156) = v15;
        *(float *)(v12 + v22 + 184) = v15;
        v18 = v15;
        *(float *)(v12 + v22 + 188) = v16;
        if ( v11 < v11 + 6 )
        {
          v19 = v0;
          v20 = 6;
          do
          {
            v21 = (_DWORD *)(v19 + v22 + 12);
            *v21 = *(_DWORD *)v13;
            v21[1] = *((_DWORD *)v13 + 1);
            v19 += 32;
            --v20;
            v21[2] = *((_DWORD *)v13 + 2);
          }
          while ( v20 );
          v17 = v23;
        }
        v0 += 192;
        v12 += 192;
        v13 += 3;
        v11 = v17;
        if ( v0 >= 0x480 )
          break;
        v14 = v16;
        v3 = v18;
        v10 = v14;
      }
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D7FD0 + 48))(dword_4D7FD0);
    }
  }
}
