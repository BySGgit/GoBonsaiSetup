int __cdecl sub_40BB50(float *a1)
{
  int v1; // ecx
  int result; // eax
  int v3; // edi
  double v4; // st7
  unsigned int v5; // ebp
  float *v6; // eax
  float v7; // ecx
  float v8; // edx
  int v9; // eax
  double v10; // st6
  double v11; // st7
  int v12; // edx
  _BYTE *v13; // eax
  _BYTE *v14; // edi
  double v15; // st6
  float v16; // [esp+3Ch] [ebp-37Ch]
  float v17; // [esp+3Ch] [ebp-37Ch]
  float v18; // [esp+40h] [ebp-378h]
  float v19; // [esp+44h] [ebp-374h]
  float v20; // [esp+44h] [ebp-374h]
  float v21; // [esp+48h] [ebp-370h]
  float v22; // [esp+4Ch] [ebp-36Ch]
  float v23; // [esp+50h] [ebp-368h]
  float v24; // [esp+54h] [ebp-364h]
  float v25; // [esp+58h] [ebp-360h]
  float v26; // [esp+68h] [ebp-350h] BYREF
  float v27; // [esp+6Ch] [ebp-34Ch]
  float v28; // [esp+70h] [ebp-348h]
  float v29[3]; // [esp+74h] [ebp-344h] BYREF
  _BYTE v30[64]; // [esp+80h] [ebp-338h] BYREF
  _BYTE v31[64]; // [esp+C0h] [ebp-2F8h] BYREF
  _BYTE v32[36]; // [esp+100h] [ebp-2B8h] BYREF
  _BYTE v33[36]; // [esp+124h] [ebp-294h] BYREF
  float v34[9]; // [esp+148h] [ebp-270h] BYREF
  _BYTE v35[36]; // [esp+16Ch] [ebp-24Ch] BYREF
  float v36[9]; // [esp+190h] [ebp-228h] BYREF
  _BYTE v37[36]; // [esp+1B4h] [ebp-204h] BYREF
  float v38[9]; // [esp+1D8h] [ebp-1E0h] BYREF
  _BYTE v39[36]; // [esp+1FCh] [ebp-1BCh] BYREF
  float v40[9]; // [esp+220h] [ebp-198h] BYREF
  _BYTE v41[36]; // [esp+244h] [ebp-174h] BYREF
  float v42[9]; // [esp+268h] [ebp-150h] BYREF
  _BYTE v43[36]; // [esp+28Ch] [ebp-12Ch] BYREF
  float v44[9]; // [esp+2B0h] [ebp-108h] BYREF
  float v45[9]; // [esp+2D4h] [ebp-E4h] BYREF
  float v46[9]; // [esp+2F8h] [ebp-C0h] BYREF
  _BYTE v47[36]; // [esp+31Ch] [ebp-9Ch] BYREF
  float v48[11]; // [esp+388h] [ebp-30h] BYREF

  result = dword_4D7E9C - 50;
  v3 = v1;
  if ( dword_4D7E98 <= (unsigned int)(dword_4D7E9C - 50) )
  {
    D3DXMatrixScaling(v31, *(float *)(v1 + 444), *(float *)(v1 + 444), 0.0);
    D3DXMatrixMultiply(v30, v31, v3 + 104);
    v4 = sub_415020(v3);
    v5 = (unsigned __int8)(int)(v4 * 255.0)
       | (((unsigned __int8)(int)(v4 * 255.0) | (((int)(v4 * 255.0) | 0xFFFFFF00) << 8)) << 8);
    v16 = *(float *)(v3 + 448);
    sub_40A310(v3);
    v6 = (float *)sub_401500(v16);
    v7 = v6[1];
    v19 = *v6;
    v8 = v6[2];
    v9 = *(_DWORD *)(v3 + 180);
    v23 = v19 * 1.100000023841858;
    v24 = v7 * 1.100000023841858;
    v25 = 1.100000023841858 * v8;
    v20 = v19 * 1.049999952316284;
    v21 = v7 * 1.049999952316284;
    v22 = 1.049999952316284 * v8;
    v10 = flt_4D52D8 * *(float *)(v3 + 448);
    v18 = v10;
    if ( v9 )
      v18 = flt_4D52D8 * *(float *)(v9 + 448) * *(float *)(v3 + 296) + a1[8] + v10;
    v11 = flt_4D63B0;
    if ( flt_4D63B0 > (double)*(float *)(v3 + 444) )
    {
      v17 = *(float *)(v3 + 444) + *(float *)(v3 + 444);
      v20 = v17 * v20;
      v21 = v21 * v17;
      v22 = v17 * v22;
    }
    qmemcpy(v32, a1, sizeof(v32));
    qmemcpy(v33, a1, sizeof(v33));
    qmemcpy(v34, a1, sizeof(v34));
    v34[0] = v34[0] + v20;
    v34[1] = v34[1] + v21;
    v34[2] = v34[2] + v22;
    v34[8] = v18;
    qmemcpy(v35, a1 + 9, sizeof(v35));
    qmemcpy(v36, a1 + 9, sizeof(v36));
    v36[0] = v36[0] + v20;
    v36[1] = v36[1] + v21;
    v36[2] = v36[2] + v22;
    v36[8] = v18;
    qmemcpy(v37, a1 + 18, sizeof(v37));
    qmemcpy(v38, a1 + 18, sizeof(v38));
    v38[0] = v38[0] + v20;
    v38[1] = v38[1] + v21;
    v38[2] = v38[2] + v22;
    v38[8] = v18;
    qmemcpy(v39, a1 + 27, sizeof(v39));
    qmemcpy(v40, a1 + 27, sizeof(v40));
    v40[0] = v40[0] + v20;
    v40[1] = v40[1] + v21;
    v12 = 0;
    v40[2] = v40[2] + v22;
    v40[8] = v18;
    qmemcpy(v41, a1 + 36, sizeof(v41));
    qmemcpy(v42, a1 + 36, sizeof(v42));
    v42[0] = v42[0] + v20;
    v42[1] = v42[1] + v21;
    v42[2] = v42[2] + v22;
    v42[8] = v18;
    qmemcpy(v43, a1 + 45, sizeof(v43));
    qmemcpy(v44, a1 + 45, sizeof(v44));
    v44[0] = v20 + v44[0];
    v44[1] = v21 + v44[1];
    v44[2] = v22 + v44[2];
    v44[8] = v18;
    qmemcpy(v45, a1, sizeof(v45));
    v45[7] = 1.0;
    qmemcpy(v46, v34, sizeof(v46));
    v46[7] = 1.0;
    qmemcpy(v47, v46, sizeof(v47));
    do
    {
      v13 = &v33[v12];
      qmemcpy((void *)(v12 + dword_4D7EC0), &v32[v12], 0x24u);
      qmemcpy((void *)(v12 + dword_4D7EC0 + 36), &v33[v12], 0x24u);
      qmemcpy(&v33[v12 + 72 - (_DWORD)v33 + dword_4D7EC0], &v33[v12 + 36], 0x24u);
      v14 = &v33[v12 + 108 - (_DWORD)v33 + dword_4D7EC0];
      v12 += 144;
      qmemcpy(v14, v13 + 72, 0x24u);
    }
    while ( v12 < 576 );
    qmemcpy((void *)(dword_4D7EC0 + 576), v47, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 612), v47, 0x24u);
    *(float *)(dword_4D7EC0 + 640) = 0.0;
    v26 = 0.0;
    v27 = 0.0;
    v29[0] = 0.0;
    v29[1] = 0.0;
    v28 = 1.0;
    v29[2] = v11;
    D3DXVec3TransformCoord(v48, &v26, v30);
    D3DXVec3TransformNormal(&v48[3], &v26, v30);
    v48[7] = 0.0;
    v48[8] = 0.0;
    LODWORD(v48[6]) = v5;
    D3DXVec3TransformCoord(v48, v29, v30);
    v48[0] = v48[0] + v23;
    v48[4] = v27;
    v48[3] = v26;
    v48[5] = v28;
    v48[1] = v48[1] + v24;
    v48[2] = v48[2] + v25;
    v48[7] = 0.16666667;
    v48[8] = v18 + 0.5;
    qmemcpy((void *)(dword_4D7EC0 + 648), v48, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 684), v36, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 720), v38, 0x24u);
    v15 = flt_4D63B0;
    qmemcpy((void *)(dword_4D7EC0 + 756), v38, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 792), v48, 0x24u);
    result = dword_4D7EC0;
    *(float *)(dword_4D7EC0 + 820) = v15;
    qmemcpy((void *)(dword_4D7EC0 + 828), v40, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 864), v42, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 900), v42, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 936), v48, 0x24u);
    *(float *)(dword_4D7EC0 + 964) = 0.83333331;
    qmemcpy((void *)(dword_4D7EC0 + 972), v44, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 1008), v46, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 1044), v46, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 1080), v48, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 1116), v48, 0x24u);
    *(float *)(dword_4D7EC0 + 1144) = 0.16666667;
    dword_4D7EC0 += 1152;
    dword_4D7E98 += 32;
  }
  return result;
}
