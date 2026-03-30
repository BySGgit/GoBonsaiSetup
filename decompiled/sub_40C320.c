int __fastcall sub_40C320(int a1, int a2, float *a3)
{
  int result; // eax
  double v6; // st7
  int v7; // eax
  double v8; // st6
  int i; // edx
  _BYTE *v10; // eax
  _BYTE *v11; // edi
  int v12; // ecx
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  float v16; // edx
  double v17; // st6
  float v18; // [esp+D0h] [ebp-3B8h]
  float v20; // [esp+DCh] [ebp-3ACh]
  float v21; // [esp+E0h] [ebp-3A8h]
  float v22; // [esp+E4h] [ebp-3A4h]
  float v23; // [esp+E8h] [ebp-3A0h]
  float v24[3]; // [esp+ECh] [ebp-39Ch] BYREF
  float v25[3]; // [esp+F8h] [ebp-390h] BYREF
  float v26[3]; // [esp+104h] [ebp-384h] BYREF
  float v27; // [esp+110h] [ebp-378h] BYREF
  float v28; // [esp+114h] [ebp-374h]
  float v29; // [esp+118h] [ebp-370h]
  float v30[3]; // [esp+11Ch] [ebp-36Ch] BYREF
  _BYTE v31[68]; // [esp+128h] [ebp-360h] BYREF
  _DWORD v32[9]; // [esp+16Ch] [ebp-31Ch] BYREF
  _BYTE v33[64]; // [esp+190h] [ebp-2F8h] BYREF
  _BYTE v34[36]; // [esp+1D0h] [ebp-2B8h] BYREF
  _BYTE v35[36]; // [esp+1F4h] [ebp-294h] BYREF
  _BYTE v36[36]; // [esp+218h] [ebp-270h] BYREF
  _BYTE v37[36]; // [esp+23Ch] [ebp-24Ch] BYREF
  float v38[9]; // [esp+260h] [ebp-228h] BYREF
  _BYTE v39[36]; // [esp+284h] [ebp-204h] BYREF
  float v40[9]; // [esp+2A8h] [ebp-1E0h] BYREF
  _BYTE v41[36]; // [esp+2CCh] [ebp-1BCh] BYREF
  float v42[9]; // [esp+2F0h] [ebp-198h] BYREF
  float v43[9]; // [esp+314h] [ebp-174h] BYREF
  float v44[9]; // [esp+338h] [ebp-150h] BYREF
  _BYTE v45[36]; // [esp+35Ch] [ebp-12Ch] BYREF
  float v46[9]; // [esp+380h] [ebp-108h] BYREF
  float v47[9]; // [esp+3A4h] [ebp-E4h] BYREF
  float v48[9]; // [esp+3C8h] [ebp-C0h] BYREF
  _BYTE v49[36]; // [esp+3ECh] [ebp-9Ch] BYREF
  float v50[11]; // [esp+458h] [ebp-30h] BYREF

  result = dword_4D7E9C - 50;
  if ( dword_4D7E98 <= (unsigned int)(dword_4D7E9C - 50) )
  {
    D3DXMatrixScaling(v33, *(float *)(a2 + 444), *(float *)(a2 + 444), 0.0);
    D3DXMatrixMultiply(v31, v33, a2 + 104);
    v6 = sub_415020(a2);
    v7 = *(_DWORD *)(a1 + 180);
    v8 = *(float *)(a1 + 448) * flt_4D52D8;
    v18 = v8;
    if ( v7 )
      v18 = flt_4D52D8 * *(float *)(v7 + 448) * *(float *)(a1 + 296) + a3[8] + v8;
    qmemcpy(v34, a3, sizeof(v34));
    qmemcpy(v35, a3, sizeof(v35));
    D3DXVec3TransformCoord(v32, &unk_4D8378, v31);
    D3DXVec3TransformNormal(&v32[3], &unk_4D8378, v31);
    v32[6] = (unsigned __int8)(int)(v6 * 255.0)
           | (((unsigned __int8)(int)(v6 * 255.0) | (((int)(v6 * 255.0) | 0xFFFFFF00) << 8)) << 8);
    *(float *)&v32[7] = 0.0;
    *(float *)&v32[8] = v18;
    qmemcpy(v36, v32, sizeof(v36));
    qmemcpy(v37, a3 + 9, sizeof(v37));
    D3DXVec3TransformCoord(v38, &unk_4D8384, v31);
    D3DXVec3TransformNormal(&v38[3], &unk_4D8384, v31);
    v38[7] = 0.16666667;
    LODWORD(v38[6]) = (unsigned __int8)(int)(v6 * 255.0)
                    | (((unsigned __int8)(int)(v6 * 255.0) | (((int)(v6 * 255.0) | 0xFFFFFF00) << 8)) << 8);
    v38[8] = v18;
    qmemcpy(v39, a3 + 18, sizeof(v39));
    D3DXVec3TransformCoord(v40, &unk_4D8390, v31);
    D3DXVec3TransformNormal(&v40[3], &unk_4D8390, v31);
    v40[7] = 0.33333334;
    v40[8] = v18;
    LODWORD(v40[6]) = (unsigned __int8)(int)(v6 * 255.0)
                    | (((unsigned __int8)(int)(v6 * 255.0) | (((int)(v6 * 255.0) | 0xFFFFFF00) << 8)) << 8);
    qmemcpy(v41, a3 + 27, sizeof(v41));
    D3DXVec3TransformCoord(v42, &unk_4D839C, v31);
    D3DXVec3TransformNormal(&v42[3], &unk_4D839C, v31);
    v42[7] = flt_4D63B0;
    v42[8] = v18;
    LODWORD(v42[6]) = (unsigned __int8)(int)(v6 * 255.0)
                    | (((unsigned __int8)(int)(v6 * 255.0) | (((int)(v6 * 255.0) | 0xFFFFFF00) << 8)) << 8);
    qmemcpy(v43, a3 + 36, sizeof(v43));
    D3DXVec3TransformCoord(v44, &unk_4D83A8, v31);
    D3DXVec3TransformNormal(&v44[3], &unk_4D83A8, v31);
    v44[7] = 0.66666669;
    LODWORD(v44[6]) = (unsigned __int8)(int)(v6 * 255.0)
                    | (((unsigned __int8)(int)(v6 * 255.0) | (((int)(v6 * 255.0) | 0xFFFFFF00) << 8)) << 8);
    v44[8] = v18;
    qmemcpy(v45, a3 + 45, sizeof(v45));
    D3DXVec3TransformCoord(v46, &unk_4D83B4, v31);
    D3DXVec3TransformNormal(&v46[3], &unk_4D83B4, v31);
    v46[7] = 0.83333331;
    LODWORD(v46[6]) = (unsigned __int8)(int)(v6 * 255.0)
                    | (((unsigned __int8)(int)(v6 * 255.0) | (((int)(v6 * 255.0) | 0xFFFFFF00) << 8)) << 8);
    v46[8] = v18;
    qmemcpy(v47, a3, sizeof(v47));
    v47[7] = 1.0;
    qmemcpy(v48, v36, sizeof(v48));
    v48[7] = 1.0;
    qmemcpy(v49, v48, sizeof(v49));
    for ( i = 0; i < 576; i += 144 )
    {
      v10 = &v35[i];
      qmemcpy((void *)(i + dword_4D7EC0), &v34[i], 0x24u);
      qmemcpy((void *)(i + dword_4D7EC0 + 36), &v35[i], 0x24u);
      qmemcpy(&v35[i + 72 - (_DWORD)v35 + dword_4D7EC0], &v35[i + 36], 0x24u);
      v11 = &v35[i + 108 - (_DWORD)v35 + dword_4D7EC0];
      qmemcpy(v11, v10 + 72, 0x24u);
    }
    v12 = a2;
    v20 = *(float *)(a2 + 448);
    v13 = sub_40A310(v12, v26);
    v14 = sub_401500(v24, v13, v20);
    v15 = sub_401470(v25, v14, 1.1);
    v22 = v15[1];
    v21 = *v15;
    v16 = v15[2];
    qmemcpy((void *)(dword_4D7EC0 + 576), v49, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 612), v49, 0x24u);
    v23 = v16;
    *(float *)(dword_4D7EC0 + 640) = 0.0;
    v27 = 0.0;
    v28 = 0.0;
    v29 = 1.0;
    v30[0] = 0.0;
    v30[1] = 0.0;
    v30[2] = flt_4D63B0;
    D3DXVec3TransformCoord(v50, &v27, v31);
    D3DXVec3TransformNormal(&v50[3], &v27, v31);
    v50[7] = 0.0;
    v50[8] = 0.0;
    LODWORD(v50[6]) = (unsigned __int8)(int)(v6 * 255.0)
                    | (((unsigned __int8)(int)(v6 * 255.0) | (((int)(v6 * 255.0) | 0xFFFFFF00) << 8)) << 8);
    D3DXVec3TransformCoord(v50, v30, v31);
    v50[3] = v27;
    v50[0] = v50[0] + v21;
    v50[1] = v50[1] + v22;
    v50[2] = v50[2] + v23;
    v50[7] = 0.16666667;
    v50[4] = v28;
    v50[5] = v29;
    v50[8] = v18 + 0.5;
    v17 = flt_4D63B0;
    qmemcpy((void *)(dword_4D7EC0 + 648), v50, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 684), v38, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 720), v40, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 756), v40, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 792), v50, 0x24u);
    *(float *)(dword_4D7EC0 + 820) = v17;
    qmemcpy((void *)(dword_4D7EC0 + 828), v42, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 864), v44, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 900), v44, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 936), v50, 0x24u);
    *(float *)(dword_4D7EC0 + 964) = 0.83333331;
    qmemcpy((void *)(dword_4D7EC0 + 972), v46, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 1008), v48, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 1044), v48, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 1080), v50, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 1116), v50, 0x24u);
    result = dword_4D7EC0;
    *(float *)(dword_4D7EC0 + 1144) = 0.16666667;
    dword_4D7EC0 += 1152;
    dword_4D7E98 += 32;
  }
  return result;
}
