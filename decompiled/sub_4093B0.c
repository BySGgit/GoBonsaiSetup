void sub_4093B0()
{
  float *v0; // eax
  int v1; // edi
  float *v2; // esi
  float *v3; // eax
  int v4; // esi
  double v5; // st7
  int v6; // esi
  float *v7; // ebx
  float *v8; // eax
  int v9; // edi
  double v10; // st7
  float *v11; // eax
  float v12; // edx
  float v13; // eax
  float v14; // edx
  float v15; // eax
  float v16; // edx
  float v17; // eax
  float v18; // edx
  float *v19; // eax
  float v20; // ecx
  float v21; // edx
  float v22; // eax
  float *v23; // eax
  float *v24; // eax
  double v25; // st7
  float v26; // ecx
  int v27; // edx
  long double v28; // st7
  float *v29; // eax
  int *v30; // eax
  int v31; // edx
  float v32; // ecx
  double v33; // st7
  double v34; // st6
  float v35; // [esp+30h] [ebp-124h]
  float v36; // [esp+30h] [ebp-124h]
  float v37; // [esp+30h] [ebp-124h]
  float v38; // [esp+30h] [ebp-124h]
  int v39; // [esp+30h] [ebp-124h]
  float v40; // [esp+30h] [ebp-124h]
  float v41; // [esp+30h] [ebp-124h]
  float v42; // [esp+30h] [ebp-124h]
  float *v43; // [esp+34h] [ebp-120h] BYREF
  float v44; // [esp+38h] [ebp-11Ch]
  float v45; // [esp+3Ch] [ebp-118h]
  int v46; // [esp+40h] [ebp-114h]
  float v47; // [esp+44h] [ebp-110h]
  float v48; // [esp+48h] [ebp-10Ch]
  float v49; // [esp+4Ch] [ebp-108h]
  float v50; // [esp+50h] [ebp-104h]
  int v51; // [esp+54h] [ebp-100h]
  float v52[3]; // [esp+58h] [ebp-FCh] BYREF
  float v53[3]; // [esp+64h] [ebp-F0h] BYREF
  int v54[3]; // [esp+70h] [ebp-E4h] BYREF
  int v55[3]; // [esp+7Ch] [ebp-D8h] BYREF
  int v56[3]; // [esp+88h] [ebp-CCh] BYREF
  float v57[3]; // [esp+94h] [ebp-C0h] BYREF
  int v58[3]; // [esp+A0h] [ebp-B4h] BYREF
  float v59; // [esp+ACh] [ebp-A8h] BYREF
  float v60; // [esp+B0h] [ebp-A4h]
  float v61; // [esp+B8h] [ebp-9Ch] BYREF
  float v62; // [esp+BCh] [ebp-98h]
  float v63[3]; // [esp+C4h] [ebp-90h] BYREF
  float v64[3]; // [esp+D0h] [ebp-84h] BYREF
  _BYTE v65[64]; // [esp+DCh] [ebp-78h] BYREF
  float v66[3]; // [esp+11Ch] [ebp-38h] BYREF
  float v67; // [esp+128h] [ebp-2Ch] BYREF
  float v68; // [esp+12Ch] [ebp-28h]
  float v69; // [esp+130h] [ebp-24h]
  float v70[3]; // [esp+134h] [ebp-20h] BYREF
  int v71; // [esp+150h] [ebp-4h]

  if ( 0.0 != flt_4D7E88
    && (*(int (__stdcall **)(int, _DWORD, _DWORD, float **, _DWORD))(*(_DWORD *)dword_4D7E70 + 44))(
         dword_4D7E70,
         0,
         0,
         &v43,
         0) >= 0 )
  {
    dword_4D7E78 = 0;
    v66[0] = 1.05;
    v66[1] = flt_4D63B0;
    v66[2] = 0.0;
    v67 = 0.69999999;
    v68 = 1.05;
    v69 = 0.0;
    v70[0] = 0.0;
    v70[1] = 1.3;
    v70[2] = 0.0;
    v49 = 0.0;
    v71 = 0;
    v0 = v66;
    v1 = 2;
    do
    {
      v2 = v0 + 3;
      v3 = sub_401430(v52, v0 + 3, v0);
      v35 = v3[1] * v3[1] + *v3 * *v3 + v3[2] * v3[2];
      v36 = sqrt(v35);
      --v1;
      v0 = v2;
      v49 = v36 + v49;
    }
    while ( v1 );
    v4 = 0;
    v48 = 0.0;
    v46 = 0;
    v47 = flt_4D7E88 * 0.02999999932944775;
    v5 = v47;
    while ( 1 )
    {
      v50 = v5;
      v6 = 12 * v4;
      v7 = (float *)((char *)v66 + v6);
      v51 = v6;
      v8 = sub_401430(v57, (float *)((char *)&v67 + v6), (float *)((char *)v66 + v6));
      v37 = v8[1] * v8[1] + *v8 * *v8 + v8[2] * v8[2];
      v38 = sqrt(v37);
      v9 = 0;
      v10 = v38 + v48;
      v39 = 0;
      v48 = v10;
      v47 = (1.0 - v48 / v49) * (flt_4D7E88 * 0.02999999932944775);
      while ( 1 )
      {
        v40 = (float)v39;
        v45 = v40 * 0.03125;
        v41 = 0.03125 * (v40 * -6.283185482025146);
        D3DXMatrixRotationYawPitchRoll(v65, LODWORD(v41), 0.0, 0.0);
        v11 = v66;
        if ( v46 )
          v11 = v7 - 3;
        v53[0] = *v11;
        v12 = v11[1];
        v53[2] = v11[2];
        v13 = v7[1];
        v53[1] = v12;
        v14 = *v7;
        v63[1] = v13;
        v15 = *(float *)((char *)&v67 + v6);
        v63[0] = v14;
        v16 = v7[2];
        v64[0] = v15;
        v17 = *(float *)((char *)&v70[-1] + v6);
        v63[2] = v16;
        v18 = *(float *)((char *)&v68 + v6);
        v64[2] = v17;
        v64[1] = v18;
        v19 = v70;
        if ( v46 != 1 )
          v19 = (float *)((char *)v70 + v6);
        v20 = *v19;
        v21 = v19[1];
        v22 = v19[2];
        v52[0] = v20;
        v52[2] = v22;
        v52[1] = v21;
        sub_401430(&v61, v64, v53);
        v44 = v61;
        v61 = -v62;
        v62 = v44;
        v23 = (float *)sub_4085B0((int)v63, v55, (int)v65);
        *v43 = *v23;
        v43[1] = v23[1];
        v43[2] = v23[2];
        v24 = (float *)sub_401540((int)&v61, v56, (int)v65);
        v25 = v45 * 6.283185482025146;
        v26 = *(float *)&v43;
        v43[3] = *v24;
        v27 = *((_DWORD *)v24 + 1);
        v45 = v25;
        v28 = v45;
        *(_DWORD *)(LODWORD(v26) + 16) = v27;
        *(float *)(LODWORD(v26) + 20) = v24[2];
        v42 = sin(v28);
        v43[6] = v42 * v50 + 0.5;
        v45 = cos(v45);
        v44 = v45;
        v43[7] = v45 * v50 + 0.5;
        sub_401430(&v59, v52, v63);
        v43 += 8;
        ++dword_4D7E78;
        v44 = v59;
        v59 = -v60;
        v60 = v44;
        v29 = (float *)sub_4085B0((int)v64, v58, (int)v65);
        *v43 = *v29;
        v43[1] = v29[1];
        v43[2] = v29[2];
        v30 = sub_401540((int)&v59, v54, (int)v65);
        v31 = *v30;
        v44 = v42;
        v32 = *(float *)&v43;
        v33 = v42;
        v34 = v47;
        *((_DWORD *)v43 + 3) = v31;
        *(_DWORD *)(LODWORD(v32) + 16) = v30[1];
        *(_DWORD *)(LODWORD(v32) + 20) = v30[2];
        v39 = ++v9;
        v43[6] = v33 * v34 + 0.5;
        v44 = v45;
        v5 = v34;
        v43[7] = v45 * v34 + 0.5;
        v43 += 8;
        ++dword_4D7E78;
        if ( v9 > 32 )
          break;
        v6 = v51;
      }
      if ( ++v46 >= 2 )
        break;
      v4 = v46;
    }
    (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D7E70 + 48))(dword_4D7E70);
    if ( (unsigned int)dword_4D7E78 <= 2 )
      dword_4D7E78 = 0;
    else
      dword_4D7E78 -= 2;
    flt_4D7E88 = 0.0;
    v71 = -1;
    `eh vector destructor iterator'(v66, 0xCu, 3, nullsub_1);
  }
}
