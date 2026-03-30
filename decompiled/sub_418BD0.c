void __stdcall sub_418BD0(int a1)
{
  float *v1; // eax
  float *v2; // eax
  double v3; // st7
  double v4; // st7
  float v5; // [esp+Ch] [ebp-4Ch]
  float v6; // [esp+1Ch] [ebp-3Ch]
  float v7; // [esp+1Ch] [ebp-3Ch]
  float v8; // [esp+1Ch] [ebp-3Ch]
  float v9; // [esp+1Ch] [ebp-3Ch]
  float v10[3]; // [esp+20h] [ebp-38h] BYREF
  float v11[3]; // [esp+2Ch] [ebp-2Ch] BYREF
  _DWORD v12[4]; // [esp+38h] [ebp-20h] BYREF
  float v13[3]; // [esp+48h] [ebp-10h] BYREF

  sub_401540(a1 + 196, v10, a1 + 352);
  v1 = sub_401180(&flt_4D5398, v10, v11);
  sub_408470(v13, v1);
  v2 = sub_408470(v11, v10);
  v5 = sub_4010C0(&flt_4D5398, v2);
  D3DXQuaternionRotationAxis(v12, v13, LODWORD(v5));
  D3DXQuaternionSlerp(a1 + 304, a1 + 304, v12, *(_DWORD *)flt_4D8610);
  v3 = *(float *)flt_4D8630;
  if ( *(float *)flt_4D8630 >= (double)*(float *)(a1 + 432) )
    v3 = *(float *)(a1 + 432);
  *(float *)(a1 + 436) = v3;
  v6 = (*(float *)(a1 + 436) - *(float *)flt_4D862C) / (*(float *)flt_4D8630 - *(float *)flt_4D862C);
  if ( v6 >= 0.0 )
  {
    if ( v6 > 1.0 )
      v6 = 1.0;
  }
  else
  {
    v6 = 0.0;
  }
  v7 = pow(v6, *(float *)flt_4D8640);
  v8 = v7 * *(float *)flt_4D8614;
  v9 = v8 + *(float *)(a1 + 448);
  *(float *)(a1 + 448) = v9;
  if ( *(float *)(a1 + 452) <= (double)v9 )
  {
    v4 = *(float *)(a1 + 452);
    *(_BYTE *)(a1 + 512) = 0;
    *(float *)(a1 + 448) = v4;
  }
}
