void sub_409910()
{
  _DWORD *EngineInstance; // esi
  int v1; // esi
  double v2; // st7
  _DWORD *v3; // esi
  int v4; // esi
  int v5; // edi
  float *v6; // eax
  int v7; // ebx
  float *v8; // esi
  float *v9; // eax
  int v10; // esi
  float *v11; // ebx
  float *v12; // eax
  float *v13; // eax
  float v14; // ecx
  float v15; // edx
  float v16; // eax
  float v17; // ecx
  float v18; // edx
  float v19; // eax
  float v20; // ecx
  float v21; // edx
  float *v22; // eax
  float v23; // ecx
  float v24; // edx
  float v25; // eax
  _DWORD *v26; // eax
  _DWORD *v27; // eax
  double v28; // st7
  int v29; // ecx
  _DWORD *v30; // eax
  _DWORD *v31; // eax
  int v32; // ecx
  double v33; // st7
  int v34; // [esp+6Ch] [ebp-180h] BYREF
  float v35; // [esp+70h] [ebp-17Ch]
  float v36; // [esp+74h] [ebp-178h]
  float v37; // [esp+78h] [ebp-174h]
  float v38; // [esp+7Ch] [ebp-170h]
  float v39; // [esp+80h] [ebp-16Ch]
  float v40; // [esp+84h] [ebp-168h]
  float v41; // [esp+88h] [ebp-164h]
  float v42; // [esp+8Ch] [ebp-160h]
  int v43; // [esp+90h] [ebp-15Ch]
  float v44; // [esp+94h] [ebp-158h]
  float v45[3]; // [esp+98h] [ebp-154h] BYREF
  float v46[3]; // [esp+A4h] [ebp-148h] BYREF
  float v47[3]; // [esp+B0h] [ebp-13Ch] BYREF
  _DWORD v48[3]; // [esp+BCh] [ebp-130h] BYREF
  _DWORD v49[3]; // [esp+C8h] [ebp-124h] BYREF
  _DWORD v50[3]; // [esp+D4h] [ebp-118h] BYREF
  _DWORD v51[3]; // [esp+E0h] [ebp-10Ch] BYREF
  float v52; // [esp+ECh] [ebp-100h] BYREF
  float v53; // [esp+F0h] [ebp-FCh]
  float v54; // [esp+F8h] [ebp-F4h] BYREF
  float v55[2]; // [esp+FCh] [ebp-F0h]
  float v56[3]; // [esp+104h] [ebp-E8h] BYREF
  float v57[3]; // [esp+110h] [ebp-DCh] BYREF
  float v58[16]; // [esp+11Ch] [ebp-D0h] BYREF
  float v59[3]; // [esp+15Ch] [ebp-90h] BYREF
  float v60; // [esp+168h] [ebp-84h] BYREF
  float v61; // [esp+16Ch] [ebp-80h]
  float v62; // [esp+170h] [ebp-7Ch]
  float v63[21]; // [esp+174h] [ebp-78h] BYREF
  float v64[4]; // [esp+1C8h] [ebp-24h] BYREF
  int v65; // [esp+1E8h] [ebp-4h]

  if ( dword_4D7E70 )
    goto LABEL_11;
  dword_4D7E78 = 0;
  dword_4D7E7C = 1000;
  dword_4D7E74 = 5;
  dword_4D7E80 = 32;
  dword_4D7E84 = 274;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( (*(int (__stdcall **)(int, int, int, int, _DWORD, int *, _DWORD))(*(_DWORD *)v1 + 104))(
         v1,
         dword_4D7E7C * dword_4D7E80,
         520,
         dword_4D7E84,
         0,
         &dword_4D7E70,
         0) >= 0 )
  {
    if ( dword_4D7EE8 )
      v2 = *(float *)(*(_DWORD *)(dword_4D7EE8 + 236) + 204);
    else
      v2 = 1.0;
    v38 = v2;
    flt_4D7E88 = v38;
    sub_4093B0();
LABEL_11:
    if ( !dword_4D7E58 )
    {
      dword_4D7E60 = 0;
      dword_4D7E64 = 2000;
      dword_4D7E5C = 5;
      dword_4D7E68 = 32;
      dword_4D7E6C = 274;
      v3 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v4 = v3[1];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      v5 = 0;
      if ( (*(int (__stdcall **)(int, int, int, int, _DWORD, int *, _DWORD))(*(_DWORD *)v4 + 104))(
             v4,
             dword_4D7E64 * dword_4D7E68,
             520,
             dword_4D7E6C,
             0,
             &dword_4D7E58,
             0) >= 0
        && (*(int (__stdcall **)(int, _DWORD, _DWORD, int *, _DWORD))(*(_DWORD *)dword_4D7E58 + 44))(
             dword_4D7E58,
             0,
             0,
             &v34,
             0) >= 0 )
      {
        v59[0] = 0.0;
        v59[1] = -0.15000001;
        v59[2] = 0.0;
        v60 = flt_4D62E8;
        v61 = -0.15000001;
        v62 = 0.0;
        v63[0] = 0.92499995;
        v63[1] = 0.0;
        v63[2] = 0.0;
        v63[3] = 1.0;
        v63[4] = 0.0;
        v63[5] = 0.0;
        v63[6] = 1.1;
        v63[7] = 0.97500002;
        v63[8] = 0.0;
        v63[9] = 1.075;
        v63[10] = 1.0;
        v63[11] = 0.0;
        v63[12] = 1.0500001;
        v63[13] = 1.0;
        v63[14] = 0.0;
        v63[15] = 1.025;
        v63[16] = 0.97500002;
        v63[17] = 0.0;
        v63[18] = 0.92500001;
        v63[19] = 0.0;
        v63[20] = 0.0;
        v64[0] = 0.0;
        v64[1] = 0.0;
        v64[2] = 0.0;
        v41 = 0.0;
        v65 = 0;
        v6 = v59;
        v7 = 9;
        do
        {
          v8 = v6 + 3;
          v9 = sub_401430(v45, v6 + 3, v6);
          v35 = v9[1] * v9[1] + *v9 * *v9 + v9[2] * v9[2];
          v35 = sqrt(v35);
          --v7;
          v6 = v8;
          v41 = v35 + v41;
        }
        while ( v7 );
        v40 = 0.0;
        v39 = 0.0;
        do
        {
          v10 = 12 * v5;
          v11 = &v59[3 * v5];
          v43 = 12 * v5;
          v12 = sub_401430(v47, &v60 + 3 * v5, v11);
          v35 = v12[1] * v12[1] + *v12 * *v12 + v12[2] * v12[2];
          v35 = sqrt(v35);
          v38 = 0.0;
          v40 = v35 + v40;
          v44 = v39;
          v39 = v40 * 0.5 / v41;
          while ( 1 )
          {
            v35 = (float)SLODWORD(v38);
            v42 = v35 * 0.015625;
            v36 = 0.015625 * (v35 * -6.283185482025146);
            D3DXMatrixRotationYawPitchRoll(v58, LODWORD(v36), 0.0, 0.0);
            v13 = v59;
            if ( v5 )
              v13 = v11 - 3;
            v14 = *v13;
            v15 = v13[1];
            v46[2] = v13[2];
            v16 = v11[2];
            v46[0] = v14;
            v17 = *v11;
            v46[1] = v15;
            v18 = v11[1];
            v56[2] = v16;
            v19 = *(float *)((char *)&v63[-1] + v10);
            v56[0] = v17;
            v20 = *(float *)((char *)&v60 + v10);
            v56[1] = v18;
            v21 = *(float *)((char *)&v61 + v10);
            v57[2] = v19;
            v57[0] = v20;
            v57[1] = v21;
            v22 = v64;
            if ( v5 != 8 )
              v22 = (float *)((char *)v63 + v10);
            v23 = *v22;
            v24 = v22[1];
            v25 = v22[2];
            v45[0] = v23;
            v45[2] = v25;
            v45[1] = v24;
            sub_401430(&v52, v57, v46);
            v37 = v52;
            v52 = -v53;
            v53 = v37;
            v26 = sub_4085B0((int)v56, v48, (int)v58);
            *(_DWORD *)v34 = *v26;
            *(_DWORD *)(v34 + 4) = v26[1];
            *(_DWORD *)(v34 + 8) = v26[2];
            v27 = sub_401540((int)&v52, v49, (int)v58);
            v28 = v42;
            v29 = v34;
            *(_DWORD *)(v34 + 12) = *v27;
            *(_DWORD *)(v29 + 16) = v27[1];
            *(_DWORD *)(v29 + 20) = v27[2];
            if ( v5 == 8 )
            {
              v37 = v28 * 6.283185482025146 + 1.570796370506287;
              v36 = sin(v37);
              *(float *)(v34 + 24) = v36 * 0.25 + 0.75;
              v36 = cos(v37);
              *(float *)(v34 + 28) = v36 * 0.5 + 0.5;
            }
            else if ( v5 )
            {
              *(float *)(v34 + 24) = v44;
              *(float *)(v34 + 28) = v28 + v28;
            }
            else
            {
              *(float *)(v34 + 24) = 0.75;
              *(float *)(v34 + 28) = flt_4D63B0;
            }
            sub_401430(&v54, v45, v56);
            v34 += 32;
            v37 = v54;
            ++dword_4D7E60;
            v54 = -v55[0];
            v55[0] = v37;
            v30 = sub_4085B0((int)v57, v51, (int)v58);
            *(_DWORD *)v34 = *v30;
            *(_DWORD *)(v34 + 4) = v30[1];
            *(_DWORD *)(v34 + 8) = v30[2];
            v31 = sub_401540((int)&v54, v50, (int)v58);
            v32 = v34;
            *(_DWORD *)(v34 + 12) = *v31;
            *(_DWORD *)(v32 + 16) = v31[1];
            *(_DWORD *)(v32 + 20) = v31[2];
            if ( v5 == 8 )
            {
              *(float *)(v34 + 24) = 0.75;
              *(float *)(v34 + 28) = flt_4D63B0;
            }
            else
            {
              if ( v5 )
              {
                *(float *)(v34 + 24) = v39;
                v33 = (v35 + v35) * 0.015625;
              }
              else
              {
                v37 = v42 * 6.283185482025146 + 1.570796370506287;
                v36 = sin(v37);
                *(float *)(v34 + 24) = v36 * 0.25 + 0.75;
                v36 = cos(v37);
                v33 = 0.5 - v36 * 0.5;
              }
              *(float *)(v34 + 28) = v33;
            }
            v34 += 32;
            ++dword_4D7E60;
            ++LODWORD(v38);
            if ( SLODWORD(v38) > 64 )
              break;
            v10 = v43;
          }
          ++v5;
        }
        while ( v5 < 9 );
        (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D7E58 + 48))(dword_4D7E58);
        if ( (unsigned int)dword_4D7E60 <= 2 )
          dword_4D7E60 = 0;
        else
          dword_4D7E60 -= 2;
        v65 = -1;
        `eh vector destructor iterator'(v59, 0xCu, 10, nullsub_1);
      }
    }
  }
}
