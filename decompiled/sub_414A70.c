int __stdcall sub_414A70(int a1)
{
  int v1; // ecx
  int v2; // edx
  float *v3; // eax
  float *v4; // eax
  double v6; // [esp+20h] [ebp-50h] BYREF
  int v7; // [esp+28h] [ebp-48h]
  float v8; // [esp+34h] [ebp-3Ch]
  float v9[3]; // [esp+38h] [ebp-38h] BYREF
  float v10[3]; // [esp+44h] [ebp-2Ch] BYREF
  _DWORD v11[4]; // [esp+50h] [ebp-20h] BYREF
  float v12[3]; // [esp+60h] [ebp-10h] BYREF

  v1 = *(_DWORD *)(a1 + 472);
  v2 = *(_DWORD *)(a1 + 476);
  LODWORD(v6) = *(_DWORD *)(a1 + 468);
  HIDWORD(v6) = v1;
  v7 = v2;
  v8 = sub_4084F0((float *)&v6);
  sub_401540((int)&dword_4D5314, v9, a1 + 352);
  v3 = sub_401180((float *)&v6, v9, v10);
  sub_408470(v12, v3);
  v4 = sub_408470(v10, v9);
  *(float *)&v6 = sub_4010C0((float *)&v6, v4);
  D3DXQuaternionRotationAxis(v11, v12, LODWORD(v6));
  *(float *)&v6 = sin(*(float *)&v6);
  *(float *)&v6 = fabs(*(float *)&v6);
  v6 = *(float *)&v6 * *(float *)(a1 + 460) * v8;
  v8 = pow(*(float *)(a1 + 444), *(float *)flt_4D8600);
  *(float *)&v6 = v8 * v6 * flt_4D5310;
  if ( *(float *)&v6 > 1.0 )
    *(float *)&v6 = 1.0;
  return D3DXQuaternionSlerp(a1 + 320, a1 + 320, v11, LODWORD(v6));
}
