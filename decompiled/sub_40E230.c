void __userpurge sub_40E230(float *a1@<edi>, int a2)
{
  int *v2; // eax
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  int *v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  float v10; // edx
  float v11; // eax
  float *v12; // eax
  float *v13; // eax
  float v14; // [esp+24h] [ebp-ACh]
  float v15; // [esp+24h] [ebp-ACh]
  float v16; // [esp+28h] [ebp-A8h]
  float v17; // [esp+2Ch] [ebp-A4h] BYREF
  float v18; // [esp+30h] [ebp-A0h]
  float v19; // [esp+34h] [ebp-9Ch]
  int v20; // [esp+38h] [ebp-98h] BYREF
  int v21; // [esp+3Ch] [ebp-94h]
  int v22; // [esp+40h] [ebp-90h]
  float v23[3]; // [esp+44h] [ebp-8Ch] BYREF
  float v24[3]; // [esp+50h] [ebp-80h] BYREF
  void *v25[5]; // [esp+5Ch] [ebp-74h] BYREF
  unsigned int v26; // [esp+70h] [ebp-60h]
  _BYTE v27[68]; // [esp+78h] [ebp-58h] BYREF
  int v28; // [esp+CCh] [ebp-4h]

  if ( (dword_4DBD10 & 1) == 0 )
  {
    dword_4DBD10 |= 1u;
    v28 = 0;
    v25[4] = 0;
    LOWORD(v25[0]) = 0;
    v26 = 7;
    sub_4032D0(L"directLightPercent", (int)v25, 0x12u);
    LOBYTE(v28) = 1;
    sub_408600(v25, (int)&unk_4DBCEC, (int)&flt_4D8CF0);
    if ( v26 >= 8 )
      operator delete(v25[0]);
    atexit(sub_472170);
    v28 = -1;
  }
  v14 = (double)rand() / 32767.0 * 1.570796370506287 + 0.0;
  v16 = (double)rand() / 32767.0 * 6.283185482025146 + 0.0;
  D3DXMatrixRotationYawPitchRoll(v27, LODWORD(v16), LODWORD(v14), 0.0);
  v2 = sub_401540((int)&flt_4D5398, &v17, (int)v27);
  v3 = *v2;
  v4 = v2[1];
  v5 = v2[2];
  v20 = v3;
  v21 = v4;
  v22 = v5;
  if ( flt_4D8CF0 > (double)rand() / 32767.0 )
  {
    v6 = (int *)sub_408590(&flt_4D538C, &v17);
    v7 = *v6;
    v8 = v6[1];
    v9 = v6[2];
    v20 = v7;
    v21 = v8;
    v22 = v9;
  }
  v10 = a1[3];
  v15 = a1[5];
  v11 = a1[4];
  v17 = a1[2];
  v18 = v10;
  v19 = v11;
  v12 = sub_40D610(v24);
  v13 = sub_401500(v23, v12, v15);
  v17 = *v13 + v17;
  v18 = v13[1] + v18;
  v19 = v13[2] + v19;
  sub_40E460(&v17, a2, (float *)&v20, 1.0);
}
