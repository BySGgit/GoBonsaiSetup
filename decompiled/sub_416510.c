void __thiscall sub_416510(char *this)
{
  double v2; // st6
  double v3; // st7
  double v4; // st7
  double v5; // rt0
  double v6; // st6
  _DWORD *v7; // eax
  double v8; // st6
  _DWORD *v9; // eax
  __int64 v10; // kr00_8
  float v11; // ecx
  double v12; // st7
  double v13; // st7
  int v14; // eax
  int v15; // ecx
  double v16; // st7
  int v17; // edx
  double v18; // st5
  double v19; // st6
  double v20; // st7
  float v21; // [esp+6Ch] [ebp-11Ch]
  float v22; // [esp+6Ch] [ebp-11Ch]
  float v23; // [esp+6Ch] [ebp-11Ch]
  float v24; // [esp+6Ch] [ebp-11Ch]
  float v25; // [esp+6Ch] [ebp-11Ch]
  float v26; // [esp+6Ch] [ebp-11Ch]
  float v27; // [esp+6Ch] [ebp-11Ch]
  int v28; // [esp+70h] [ebp-118h]
  float v29; // [esp+70h] [ebp-118h]
  float v30; // [esp+70h] [ebp-118h]
  float v31; // [esp+70h] [ebp-118h]
  float v32; // [esp+70h] [ebp-118h]
  float v33; // [esp+70h] [ebp-118h]
  float v34; // [esp+74h] [ebp-114h]
  float v35; // [esp+78h] [ebp-110h] BYREF
  __int64 v36; // [esp+7Ch] [ebp-10Ch]
  float v37; // [esp+84h] [ebp-104h]
  _BYTE v38[16]; // [esp+88h] [ebp-100h] BYREF
  float v39; // [esp+98h] [ebp-F0h] BYREF
  __int64 v40; // [esp+9Ch] [ebp-ECh]
  float v41; // [esp+A4h] [ebp-E4h]
  _BYTE v42[16]; // [esp+A8h] [ebp-E0h] BYREF
  void *v43[16]; // [esp+B8h] [ebp-D0h] BYREF
  double v44; // [esp+F8h] [ebp-90h] BYREF
  float v45; // [esp+100h] [ebp-88h]
  float v46; // [esp+10Ch] [ebp-7Ch] BYREF
  float v47; // [esp+110h] [ebp-78h]
  float v48; // [esp+114h] [ebp-74h]
  int v49; // [esp+11Ch] [ebp-6Ch]
  float v50; // [esp+120h] [ebp-68h]
  float v51[3]; // [esp+124h] [ebp-64h] BYREF
  _BYTE v52[68]; // [esp+130h] [ebp-58h] BYREF
  int v53; // [esp+184h] [ebp-4h]

  sub_414E10();
  v28 = *((_DWORD *)this + 45);
  D3DXMatrixInverse(v43, 0, this + 104);
  qmemcpy(v52, v43, 0x40u);
  sub_401540(v52);
  v21 = v47 * flt_4D5390 + v46 * flt_4D538C + v48 * flt_4D5394;
  v22 = fabs(v21);
  v34 = *((float *)this + 52) * v22 + *((float *)this + 53) * 0.5;
  if ( v34 >= 0.0 )
  {
    if ( v34 > 1.0 )
      v34 = 1.0;
    v2 = 0.0;
    v3 = 1.0;
  }
  else
  {
    v2 = 0.0;
    v3 = 1.0;
    v34 = 0.0;
  }
  if ( *(float *)(v28 + 432) <= 0.0099999998 )
  {
    v23 = *(float *)(v28 + 432);
    v44 = *((float *)this + 114);
    *((float *)this + 114) = v44 - (double)rand() / 32767.0 * 0.02500000037252903 * (1.0 - v23 / 0.009999999776482582);
    v3 = 1.0;
    v2 = 0.0;
  }
  if ( (dword_4DBBA4 & 1) == 0 )
  {
    dword_4DBBA4 |= 1u;
    v53 = 0;
    v43[5] = (void *)7;
    v43[4] = 0;
    LOWORD(v43[0]) = 0;
    sub_4032D0(12);
    LOBYTE(v53) = 1;
    sub_408600(&unk_4DBB80, &flt_4D63B4);
    if ( v43[5] >= (void *)8 )
      operator delete(v43[0]);
    atexit(sub_472490);
    v53 = -1;
    v3 = 1.0;
    v2 = 0.0;
  }
  if ( (dword_4DBBA4 & 2) == 0 )
  {
    dword_4DBBA4 |= 2u;
    v53 = 2;
    LOWORD(v43[0]) = 0;
    v43[5] = (void *)7;
    v43[4] = 0;
    sub_4032D0(16);
    LOBYTE(v53) = 3;
    sub_408600(&unk_4DBB5C, &flt_4D63B8);
    if ( v43[5] >= (void *)8 )
      operator delete(v43[0]);
    atexit(sub_472480);
    v53 = -1;
    v3 = 1.0;
    v2 = 0.0;
  }
  v29 = (v34 - flt_4D63B4) / (0.0 - flt_4D63B4);
  if ( v29 >= v2 )
  {
    if ( v29 <= v3 )
      v24 = (v34 - flt_4D63B4) / (0.0 - flt_4D63B4);
    else
      v24 = v3;
  }
  else
  {
    v24 = v2;
  }
  *((float *)this + 114) = *((float *)this + 114) - v24 * flt_4D63B8;
  if ( v2 <= *((float *)this + 114) )
  {
    v5 = v2;
    v6 = v3;
    v4 = v5;
    if ( v6 < *((float *)this + 114) )
      *((float *)this + 114) = v6;
  }
  else
  {
    v4 = v2;
    *((float *)this + 114) = v2;
  }
  if ( (dword_4DBBA4 & 4) == 0 )
  {
    dword_4DBBA4 |= 4u;
    v53 = 4;
    v43[5] = (void *)7;
    v43[4] = 0;
    LOWORD(v43[0]) = 0;
    sub_4032D0(20);
    LOBYTE(v53) = 5;
    sub_408600(&unk_4DBB38, &flt_4D63BC);
    if ( v43[5] >= (void *)8 )
      operator delete(v43[0]);
    atexit(sub_472470);
    v53 = -1;
    v4 = 0.0;
  }
  if ( v4 >= *((float *)this + 114) || (1.0 - *((float *)this + 114)) * flt_4D63BC > (double)rand() / 32767.0 )
  {
    (*(void (__thiscall **)(char *))(*(_DWORD *)this + 44))(this);
    return;
  }
  v35 = 0.30000001;
  *(float *)&v36 = 1.0;
  *((float *)&v36 + 1) = 0.2;
  v37 = 1.0;
  if ( *((float *)this + 114) >= 1.0 )
  {
    if ( *((float *)this + 110) >= 110.0 )
    {
      v10 = v36;
      *((float *)this + 128) = v35;
      v11 = v37;
      *(_QWORD *)(this + 516) = v10;
      *((float *)this + 131) = v11;
    }
    else
    {
      v8 = *((float *)this + 110) / 110.0;
      v43[8] = (void *)LODWORD(v35);
      *(_QWORD *)&v43[9] = v36;
      v43[11] = (void *)LODWORD(v37);
      v30 = v8;
      *(float *)v43 = flt_4D63B0;
      *(float *)&v43[1] = 1.0;
      *(float *)&v43[2] = 0.0;
      *(float *)&v43[6] = 0.0;
      *(float *)&v43[3] = 1.0;
      *(float *)&v43[5] = 1.0;
      *(float *)&v43[7] = 1.0;
      *(float *)&v43[4] = flt_4D63B0;
      v9 = (_DWORD *)sub_40FDE0((int)v43, v30);
      *((_DWORD *)this + 128) = *v9;
      *((_DWORD *)this + 129) = v9[1];
      *((_DWORD *)this + 130) = v9[2];
      *((_DWORD *)this + 131) = v9[3];
    }
  }
  else
  {
    *(float *)v43 = 0.69;
    *(float *)&v43[1] = 0.40000001;
    v43[12] = (void *)LODWORD(v35);
    *(float *)&v43[2] = flt_4CA5E8;
    *(float *)&v43[5] = flt_4CA5E8;
    *(_QWORD *)&v43[13] = v36;
    *(float *)&v43[3] = 1.0;
    *(float *)&v43[4] = 1.0;
    *(float *)&v43[6] = flt_4D638C;
    v43[15] = (void *)LODWORD(v37);
    *(float *)&v43[7] = 1.0;
    *(float *)&v43[8] = 1.0;
    *(float *)&v43[9] = 1.0;
    *(float *)&v43[10] = 0.0;
    *(float *)&v43[11] = 1.0;
    v7 = (_DWORD *)sub_40FDE0((int)v43, *((float *)this + 114));
    *((_DWORD *)this + 128) = *v7;
    *((_DWORD *)this + 129) = v7[1];
    *((_DWORD *)this + 130) = v7[2];
    *((_DWORD *)this + 131) = v7[3];
  }
  *((float *)this + 109) = *((float *)this + 108) * *((float *)this + 114);
  sub_401540(this + 352);
  *(float *)&v44 = 0.0;
  HIDWORD(v44) = v49;
  v45 = v50;
  D3DXVec3Normalize(&v44, &v44);
  sub_401180(&v44);
  if ( v51[0] >= 0.0 )
    v12 = 1.0;
  else
    v12 = -1.0;
  v51[0] = v12;
  v25 = sub_4010C0(&v44);
  if ( v25 >= 0.30000001 )
  {
    if ( v25 > 2.6500001 )
      v25 = 2.6500001;
    D3DXQuaternionRotationAxis(v42, v51, LODWORD(v25));
  }
  else
  {
    v25 = 0.30000001;
    D3DXQuaternionRotationAxis(v42, v51, 0.30000001);
  }
  v31 = -v25;
  D3DXMatrixRotationYawPitchRoll(v52, LODWORD(v31), 0.0, 0.0);
  sub_401540(v52);
  v26 = sub_4010C0(v38);
  if ( v26 >= -1.570796370506287 )
  {
    if ( v26 <= 1.570796370506287 )
      goto LABEL_49;
    v13 = flt_4D6388;
  }
  else
  {
    v13 = -1.5707964;
  }
  v26 = v13;
LABEL_49:
  sub_401180(v38);
  sub_408470();
  D3DXQuaternionRotationAxis(v43, &v46, LODWORD(v26));
  D3DXQuaternionRotationYawPitchRoll(v38, LODWORD(v46), LODWORD(v47), LODWORD(v48));
  D3DXQuaternionMultiply(&v35, v42, v38);
  v40 = v36;
  v39 = v35;
  v41 = v37;
  D3DXQuaternionSlerp(this + 320, this + 320, &v39, LODWORD(flt_4D63C0));
  v14 = *((_DWORD *)this + 81);
  v15 = *((_DWORD *)this + 82);
  v16 = *((float *)this + 111) * v34;
  *((_DWORD *)this + 76) = *((_DWORD *)this + 80);
  v17 = *((_DWORD *)this + 83);
  *((_DWORD *)this + 77) = v14;
  *((_DWORD *)this + 78) = v15;
  v18 = *((float *)this + 114);
  *((_DWORD *)this + 79) = v17;
  v19 = v16 * v34 * v18 * *(float *)flt_4D8634;
  v20 = v34;
  v32 = v19;
  *((float *)this + 105) = v32;
  *((float *)this + 106) = v32 + *((float *)this + 106);
  if ( *((float *)this + 113) > (double)*((float *)this + 111) )
  {
    if ( (dword_4DBBA4 & 8) == 0 )
    {
      dword_4DBBA4 |= 8u;
      v53 = 6;
      sub_4033D0(v43);
      LOBYTE(v53) = 7;
      sub_408600(&unk_4DBB14, &flt_4D63C4);
      sub_403410();
      atexit(sub_472460);
      v20 = v34;
    }
    v27 = v20 * flt_4D63C4;
    v33 = ((double)rand() / 32767.0 * 0.5 + 0.5) * (*((float *)this + 114) * v27) + *((float *)this + 111);
    *((float *)this + 111) = v33;
    if ( *((float *)this + 113) < (double)v33 )
      *((float *)this + 111) = *((float *)this + 113);
    *((float *)this + 112) = *((float *)this + 111) + *((float *)this + 111);
  }
}
