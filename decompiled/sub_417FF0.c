void __stdcall sub_417FF0(int a1)
{
  int v1; // ecx
  double v2; // st7
  int v3; // eax
  float *v4; // eax
  float *v5; // eax
  float *v6; // eax
  float *v7; // eax
  float *v8; // eax
  double v9; // st7
  void *v10; // eax
  double v11; // st7
  void *v12; // esi
  void *v13; // eax
  int v14; // esi
  float v15; // [esp+6Ch] [ebp-204h]
  float v16; // [esp+88h] [ebp-1E8h]
  float v17; // [esp+88h] [ebp-1E8h]
  float v18; // [esp+88h] [ebp-1E8h]
  float v19; // [esp+88h] [ebp-1E8h]
  int v20; // [esp+88h] [ebp-1E8h]
  float v21; // [esp+88h] [ebp-1E8h]
  float v22; // [esp+88h] [ebp-1E8h]
  float v23; // [esp+8Ch] [ebp-1E4h]
  float v24; // [esp+8Ch] [ebp-1E4h]
  float v25; // [esp+8Ch] [ebp-1E4h]
  float v26; // [esp+8Ch] [ebp-1E4h]
  float v27; // [esp+8Ch] [ebp-1E4h]
  float v28; // [esp+8Ch] [ebp-1E4h]
  float v29; // [esp+90h] [ebp-1E0h]
  float v30; // [esp+90h] [ebp-1E0h]
  float v31; // [esp+90h] [ebp-1E0h]
  float v32; // [esp+90h] [ebp-1E0h]
  float v33; // [esp+94h] [ebp-1DCh]
  float v34; // [esp+94h] [ebp-1DCh]
  float v35; // [esp+98h] [ebp-1D8h] BYREF
  float v36; // [esp+9Ch] [ebp-1D4h]
  float v37; // [esp+A0h] [ebp-1D0h]
  float v38; // [esp+A4h] [ebp-1CCh]
  float v39[3]; // [esp+A8h] [ebp-1C8h] BYREF
  float v40[3]; // [esp+B4h] [ebp-1BCh] BYREF
  void *v41[5]; // [esp+C0h] [ebp-1B0h] BYREF
  unsigned int v42; // [esp+D4h] [ebp-19Ch]
  _BYTE v43[64]; // [esp+DCh] [ebp-194h] BYREF
  _BYTE v44[64]; // [esp+11Ch] [ebp-154h] BYREF
  int v45[16]; // [esp+15Ch] [ebp-114h] BYREF
  _BYTE v46[64]; // [esp+19Ch] [ebp-D4h] BYREF
  int v47[16]; // [esp+1DCh] [ebp-94h] BYREF
  int v48[16]; // [esp+21Ch] [ebp-54h] BYREF
  int v49; // [esp+26Ch] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 172);
  v38 = 0.0;
  if ( v1 == 1 )
    v38 = *(float *)(*(_DWORD *)(**(_DWORD **)(a1 + 168) + 8) + 428);
  v33 = 1.0;
  v2 = *(float *)flt_4D8638;
  if ( *(_DWORD *)(a1 + 484) - 1 > 0 )
  {
    v3 = *(_DWORD *)(a1 + 484) - 1;
    do
    {
      --v3;
      v33 = v33 * (1.0 - v2);
    }
    while ( v3 );
  }
  v16 = *(float *)(a1 + 432) - *(float *)(a1 + 436);
  v17 = v2 * (v16 * v33);
  if ( *(float *)flt_4D862C <= (double)v17 )
  {
    *(float *)(a1 + 436) = v17 + *(float *)(a1 + 436);
    if ( v1 )
    {
      D3DXMatrixInverse(v43, 0, a1 + 104);
      qmemcpy(v44, v43, sizeof(v44));
      sub_401540(a1 + 196, &v35, (int)v44);
      v4 = sub_401180(&flt_4D5398, &v35, v40);
      sub_408470(&v35, v4);
      v5 = sub_401B00(a1, v40);
      v6 = sub_401180(&v35, v5, v39);
      sub_408470(&v35, v6);
      v7 = sub_408590(&flt_4D538C, v39);
      v29 = v7[1] * v36 + *v7 * v35 + v7[2] * v37;
      if ( v29 <= 1.0 )
      {
        if ( v29 < -1.0 )
          v29 = -1.0;
      }
      else
      {
        v29 = 1.0;
      }
      v18 = acos(v29);
      v8 = sub_408590(&flt_4D538C, v39);
      if ( sub_401180(v8, &v35, v40)[2] <= 0.0 )
        v9 = -1.0;
      else
        v9 = 1.0;
      v23 = v9;
      v30 = v23 * v18;
      if ( (dword_4DBAE8 & 1) == 0 )
      {
        dword_4DBAE8 |= 1u;
        v49 = 0;
        LOWORD(v41[0]) = 0;
        v42 = 7;
        v41[4] = 0;
        sub_4032D0(L"randomBudRotation", (int)v41, 0x11u);
        LOBYTE(v49) = 1;
        sub_408600(v41, (int)&unk_4DBAC4, (int)&flt_4D642C);
        if ( v42 >= 8 )
          operator delete(v41[0]);
        atexit(sub_4724B0);
        v49 = -1;
      }
      v24 = -flt_4D642C;
      v31 = v24 + (flt_4D642C - v24) * ((double)rand() / 32767.0) + v30;
      if ( !(*(_DWORD *)(a1 + 484) % 2) )
        v31 = v31 + 1.570796370506287;
      v25 = (double)rand() / 32767.0 * 0.5 + 1.0;
      v35 = 0.0;
      v36 = v25;
      v37 = -v31;
      v19 = (double)rand() / 32767.0 * 0.1000000014901161 - 0.05000000074505806 + v31;
      sub_4158D0(v47, 0.0, 1.0, v19);
      v10 = operator new(0x220u);
      v49 = 2;
      if ( v10 )
        v20 = sub_4159C0(v47, a1, (int)v10, (int)&v35);
      else
        v20 = 0;
      v49 = -1;
      v11 = v37;
      ++*(_DWORD *)(a1 + 480);
      v15 = v11;
      D3DXMatrixRotationYawPitchRoll(v44, 0.0, LODWORD(v25), LODWORD(v15));
      D3DXMatrixMultiply(v43, v44, v47);
      qmemcpy(v45, v43, sizeof(v45));
      D3DXMatrixMultiply(v46, v45, a1 + 104);
      v26 = *(float *)flt_4D8638 * v33;
      v34 = 1.0 - v33;
      v38 = v26 * v38 / v34;
      v27 = ((double)rand() / 32767.0 * 0.800000011920929 + 0.2000000029802322) * v38;
      *(float *)(v20 + 428) = v27;
      v32 = v31 + 3.141592741012573;
      v21 = (double)rand() / 32767.0 * 0.5 + 1.0;
      v35 = 0.0;
      v36 = v21;
      v37 = -v32;
      v28 = (double)rand() / 32767.0 * 0.1000000014901161 - 0.05000000074505806 + v32;
      sub_4158D0(v45, 0.0, 1.0, v28);
      D3DXMatrixRotationYawPitchRoll(v44, 0.0, LODWORD(v21), LODWORD(v37));
      D3DXMatrixMultiply(v43, v44, v45);
      qmemcpy(v46, v43, sizeof(v46));
      D3DXMatrixMultiply(v48, v46, a1 + 104);
      v12 = operator new(0x220u);
      v49 = 3;
      if ( v12 )
      {
        v22 = (double)rand() / 32767.0 * 0.1000000014901161 - 0.05000000074505806 + v32;
        v13 = sub_4158D0(v48, 0.0, 1.0, v22);
        v14 = sub_4159C0(v13, a1, (int)v12, (int)&v35);
      }
      else
      {
        v14 = 0;
      }
      ++*(_DWORD *)(a1 + 480);
      *(float *)(v14 + 428) = ((double)rand() / 32767.0 * 0.800000011920929 + 0.2000000029802322) * v38;
    }
    else
    {
      sub_418660(a1);
    }
  }
}
