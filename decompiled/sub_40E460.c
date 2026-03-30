void __fastcall sub_40E460(float *a1, int a2, float *a3, float a4)
{
  float *v6; // eax
  float *v7; // eax
  float *v8; // esi
  int v9; // eax
  float *v10; // eax
  int v11; // edi
  double v12; // st6
  int v13; // esi
  float *v14; // ebx
  float *v15; // eax
  float *v16; // eax
  bool v17; // zf
  int v18; // esi
  float *v19; // eax
  double v20; // st7
  float *v21; // eax
  float *v22; // ebx
  float *v23; // eax
  float *v24; // ebx
  float *v25; // eax
  void *v26; // ecx
  void *v27; // edx
  unsigned int v28; // eax
  void *v29; // ecx
  int v30; // edx
  float v31; // [esp+18h] [ebp-280h]
  float v32; // [esp+18h] [ebp-280h]
  float v33; // [esp+18h] [ebp-280h]
  float v34; // [esp+18h] [ebp-280h]
  float v35; // [esp+18h] [ebp-280h]
  double v36; // [esp+18h] [ebp-280h]
  float v37; // [esp+24h] [ebp-274h]
  float v38; // [esp+24h] [ebp-274h]
  int v39; // [esp+28h] [ebp-270h]
  int *v40; // [esp+2Ch] [ebp-26Ch]
  int v41; // [esp+30h] [ebp-268h]
  int v42; // [esp+34h] [ebp-264h] BYREF
  int v43; // [esp+38h] [ebp-260h]
  int v44; // [esp+3Ch] [ebp-25Ch]
  float v45; // [esp+40h] [ebp-258h] BYREF
  float v46; // [esp+44h] [ebp-254h]
  float v47; // [esp+48h] [ebp-250h]
  float v48; // [esp+4Ch] [ebp-24Ch]
  int v49[3]; // [esp+50h] [ebp-248h] BYREF
  float v50[6]; // [esp+5Ch] [ebp-23Ch] BYREF
  float v51[3]; // [esp+74h] [ebp-224h] BYREF
  float v52[3]; // [esp+80h] [ebp-218h] BYREF
  float v53[3]; // [esp+8Ch] [ebp-20Ch] BYREF
  float v54[3]; // [esp+98h] [ebp-200h] BYREF
  float v55[3]; // [esp+A4h] [ebp-1F4h] BYREF
  float v56[3]; // [esp+B0h] [ebp-1E8h] BYREF
  float v57[3]; // [esp+BCh] [ebp-1DCh] BYREF
  float v58[3]; // [esp+C8h] [ebp-1D0h] BYREF
  float v59[3]; // [esp+D4h] [ebp-1C4h] BYREF
  float v60[3]; // [esp+E0h] [ebp-1B8h] BYREF
  int v61; // [esp+ECh] [ebp-1ACh] BYREF
  float v62; // [esp+F0h] [ebp-1A8h]
  float v63; // [esp+F4h] [ebp-1A4h]
  void *v64[4]; // [esp+F8h] [ebp-1A0h] BYREF
  int v65; // [esp+108h] [ebp-190h]
  unsigned int v66; // [esp+10Ch] [ebp-18Ch]
  int v67[3]; // [esp+114h] [ebp-184h] BYREF
  int v68[90]; // [esp+120h] [ebp-178h] BYREF
  int v69; // [esp+294h] [ebp-4h]

  v6 = sub_401470((float *)v49, a3, 200.0);
  sub_401430((float *)&v61, v6, a1);
  v7 = sub_401470((float *)v49, a3, 200.0);
  sub_4013F0((float *)v67, v7, a1);
  v8 = (float *)v68;
  v9 = sub_450E30(*(_DWORD *)(a2 + 240), v68, (float *)&v61, (float *)v67, 30);
  v42 = v61;
  v43 = LODWORD(v62);
  v44 = LODWORD(v63);
  v39 = 0;
  if ( v9 > 0 )
  {
    v40 = v68;
    v41 = v9;
    do
    {
      if ( byte_4D7E8D )
      {
        ++v39;
        v10 = sub_401470(v59, a3, v8[1]);
        sub_4013F0((float *)v49, v10, (float *)&v61);
        if ( v39 > 0 )
        {
          v45 = a4;
          v46 = a4;
          v47 = a4;
          v48 = 0.30000001;
          sub_44E5D0(&v45, &v42, v49, flt_4D63B0);
        }
        v42 = v49[0];
        v43 = v49[1];
        v44 = v49[2];
      }
      v11 = *(_DWORD *)v8;
      v12 = *(float *)(*(_DWORD *)v8 + 208) + 0.009999999776482582;
      v13 = *(_DWORD *)v8 + 196;
      v31 = v12 * 10.0;
      v37 = a4 + 0.009999999776482582;
      v14 = sub_401470(v53, a3, v37);
      v15 = sub_401470(v51, (float *)v13, v31);
      v16 = sub_401430(v55, v14, v15);
      *(float *)v13 = *v16;
      *(float *)(v13 + 4) = v16[1];
      *(float *)(v13 + 8) = v16[2];
      sub_40CF00((float *)v13);
      v32 = *(float *)(v13 + 4) * a3[1] + *a3 * *(float *)v13 + *(float *)(v13 + 8) * a3[2];
      v38 = -v32;
      if ( v38 >= 0.0 )
      {
        if ( v38 > 1.0 )
          v38 = 1.0;
      }
      else
      {
        v38 = 0.0;
      }
      v17 = (dword_4D8CD8 & 1) == 0;
      v33 = v38 * a4 + *(float *)(v11 + 208) * 10.0;
      *(float *)(v11 + 208) = v33 / 11.0;
      *(float *)(v11 + 212) = (a4 + *(float *)(v11 + 212) * 20.0) / 21.0;
      if ( v17 )
      {
        dword_4D8CD8 |= 1u;
        v69 = 0;
        sub_40FAD0();
        v69 = -1;
      }
      v18 = byte_4D8227[11 * *(_DWORD *)(v11 + 4)] != 0 ? v11 : 0;
      if ( (dword_4D8CE0 & 1) == 0 )
      {
        dword_4D8CE0 |= 1u;
        v69 = 1;
        sub_40FBA0();
        v69 = -1;
      }
      if ( v18 )
      {
        v19 = sub_40D6D0(v11, v58);
        v34 = v19[1] * a3[1] + *a3 * *v19 + v19[2] * a3[2];
        v35 = fabs(v34);
        if ( (dword_4DBCE8 & 1) == 0 )
        {
          dword_4DBCE8 |= 1u;
          v69 = 2;
          v66 = 7;
          v65 = 0;
          LOWORD(v64[0]) = 0;
          sub_4032D0(L"lightDecayAmount", (int)v64, 0x10u);
          LOBYTE(v69) = 3;
          sub_408600(v64, (int)&unk_4DBCC4, (int)&flt_4D62EC);
          if ( v66 >= 8 )
            operator delete(v64[0]);
          atexit(sub_472180);
          v69 = -1;
        }
        v20 = (1.0 - flt_4D62EC * v35) * a4;
      }
      else
      {
        if ( (byte_4D822A[11 * *(_DWORD *)(v11 + 4)] != 0 ? v11 : 0) == 0 )
          goto LABEL_25;
        v21 = sub_40A310(v11, v57);
        v22 = sub_401500(v60, v21, *(float *)(v11 + 448));
        v23 = sub_40D6C0(v11, v52);
        v24 = sub_4013F0(v54, v22, v23);
        v25 = sub_40D6C0(v11, v56);
        v26 = *(void **)v25;
        v36 = *(float *)(v11 + 444);
        v27 = (void *)*((_DWORD *)v25 + 1);
        v64[2] = *((void **)v25 + 2);
        v28 = *((_DWORD *)v24 + 2);
        v64[0] = v26;
        v29 = *(void **)v24;
        v64[1] = v27;
        v30 = *((_DWORD *)v24 + 1);
        v66 = v28;
        v64[3] = v29;
        v65 = v30;
        v50[2] = v63;
        LODWORD(v50[0]) = v61;
        v50[1] = v62;
        v50[5] = *(float *)&v67[2];
        v50[3] = *(float *)v67;
        v50[4] = *(float *)&v67[1];
        *(float *)&v36 = v36 * v36;
        if ( *(float *)&v36 <= sub_44EE20(v50, (float *)v64) )
          goto LABEL_25;
        v20 = a4 * 0.5;
      }
      a4 = v20;
LABEL_25:
      v8 = (float *)(v40 + 3);
      v17 = v41-- == 1;
      v40 += 3;
    }
    while ( !v17 );
  }
  if ( byte_4D7E8D && a4 > 0.0 && v39 > 0 )
  {
    v45 = a4;
    v46 = a4;
    v47 = a4;
    v48 = 0.30000001;
    sub_44E5D0(&v45, &v42, v67, flt_4D63B0);
  }
}
