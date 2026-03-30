int __fastcall sub_40AC70(float *a1, int a2, float a3)
{
  int result; // eax
  float v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  double v10; // st7
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  float v16; // [esp+78h] [ebp-CCh]
  float v17; // [esp+78h] [ebp-CCh]
  float v18; // [esp+78h] [ebp-CCh]
  float v19; // [esp+78h] [ebp-CCh]
  float v20; // [esp+78h] [ebp-CCh]
  float v21; // [esp+78h] [ebp-CCh]
  float v22; // [esp+78h] [ebp-CCh]
  float v23; // [esp+78h] [ebp-CCh]
  float v24; // [esp+78h] [ebp-CCh]
  float v25; // [esp+78h] [ebp-CCh]
  float v26; // [esp+7Ch] [ebp-C8h]
  float v27; // [esp+7Ch] [ebp-C8h]
  float v28; // [esp+7Ch] [ebp-C8h]
  float v29; // [esp+7Ch] [ebp-C8h]
  float v30; // [esp+7Ch] [ebp-C8h]
  float v31; // [esp+7Ch] [ebp-C8h]
  float v32; // [esp+7Ch] [ebp-C8h]
  float v33; // [esp+7Ch] [ebp-C8h]
  float v34; // [esp+7Ch] [ebp-C8h]
  float v35; // [esp+7Ch] [ebp-C8h]
  float v36; // [esp+80h] [ebp-C4h]
  float v37; // [esp+80h] [ebp-C4h]
  float v38; // [esp+80h] [ebp-C4h]
  float v39; // [esp+80h] [ebp-C4h]
  float v40; // [esp+80h] [ebp-C4h]
  float v41; // [esp+80h] [ebp-C4h]
  float v42; // [esp+80h] [ebp-C4h]
  float v43; // [esp+80h] [ebp-C4h]
  float v44; // [esp+80h] [ebp-C4h]
  float v45; // [esp+80h] [ebp-C4h]
  float v46[9]; // [esp+8Ch] [ebp-B8h] BYREF
  float v47[9]; // [esp+B0h] [ebp-94h] BYREF
  float v48[9]; // [esp+D4h] [ebp-70h] BYREF
  float v49[9]; // [esp+F8h] [ebp-4Ch] BYREF
  float v50[9]; // [esp+11Ch] [ebp-28h] BYREF

  result = dword_4D7EB4 - 50;
  if ( dword_4D7EB0 <= (unsigned int)(dword_4D7EB4 - 50) )
  {
    LODWORD(v5) = (unsigned __int8)(int)(a3 * 255.0 * a1[2])
                | (((unsigned __int8)(int)(a1[1] * (a3 * 255.0)) | (((int)(*a1 * (a3 * 255.0)) | 0xFFFFFF00) << 8)) << 8);
    D3DXVec3TransformCoord(v46, &dword_4D83C0, a2);
    D3DXVec3TransformNormal(&v46[3], &dword_4D83CC, a2);
    v46[7] = flt_4D8418;
    v46[8] = flt_4D841C;
    v46[6] = v5;
    D3DXVec3TransformCoord(v47, &dword_4D8540, a2);
    D3DXVec3TransformNormal(&v47[3], &dword_4D854C, a2);
    v47[7] = flt_4D8598;
    v47[8] = flt_4D859C;
    v47[6] = v5;
    D3DXVec3TransformCoord(v48, &dword_4D8420, a2);
    D3DXVec3TransformNormal(&v48[3], &dword_4D842C, a2);
    v48[7] = flt_4D8478;
    v48[8] = flt_4D847C;
    v48[6] = v5;
    D3DXVec3TransformCoord(v49, &dword_4D8480, a2);
    D3DXVec3TransformNormal(&v49[3], &dword_4D848C, a2);
    v49[7] = flt_4D84D8;
    v49[8] = flt_4D84DC;
    v49[6] = v5;
    D3DXVec3TransformCoord(v50, &dword_4D84E0, a2);
    D3DXVec3TransformNormal(&v50[3], &dword_4D84EC, a2);
    v50[7] = flt_4D8538;
    v50[6] = v5;
    v50[8] = flt_4D853C;
    qmemcpy((void *)dword_4D7EC4, v46, 0x24u);
    qmemcpy((void *)(dword_4D7EC4 + 36), v46, 0x24u);
    qmemcpy((void *)(dword_4D7EC4 + 72), v47, 0x24u);
    qmemcpy((void *)(dword_4D7EC4 + 108), v48, 0x24u);
    qmemcpy((void *)(dword_4D7EC4 + 144), v49, 0x24u);
    qmemcpy((void *)(dword_4D7EC4 + 180), v49, 0x24u);
    qmemcpy((void *)(dword_4D7EC4 + 216), v47, 0x24u);
    qmemcpy((void *)(dword_4D7EC4 + 252), v50, 0x24u);
    qmemcpy((void *)(dword_4D7EC4 + 288), v47, 0x24u);
    qmemcpy((void *)(dword_4D7EC4 + 324), v46, 0x24u);
    qmemcpy((void *)(dword_4D7EC4 + 360), v46, 0x24u);
    v16 = -v46[3];
    v26 = -v46[4];
    v36 = -v46[5];
    v6 = dword_4D7EC4;
    *(float *)(dword_4D7EC4 + 372) = v16;
    *(float *)(v6 + 376) = v26;
    *(float *)(v6 + 380) = v36;
    *(float *)(dword_4D7EC4 + 384) = v5;
    qmemcpy((void *)(dword_4D7EC4 + 396), v47, 0x24u);
    v17 = -v47[3];
    v27 = -v47[4];
    v37 = -v47[5];
    v7 = dword_4D7EC4;
    *(float *)(dword_4D7EC4 + 408) = v17;
    *(float *)(v7 + 412) = v27;
    *(float *)(v7 + 416) = v37;
    *(float *)(dword_4D7EC4 + 420) = v5;
    qmemcpy((void *)(dword_4D7EC4 + 432), v48, 0x24u);
    v18 = -v48[3];
    v28 = -v48[4];
    v38 = -v48[5];
    v8 = dword_4D7EC4;
    *(float *)(dword_4D7EC4 + 444) = v18;
    *(float *)(v8 + 448) = v28;
    *(float *)(v8 + 452) = v38;
    *(float *)(dword_4D7EC4 + 456) = v5;
    qmemcpy((void *)(dword_4D7EC4 + 468), v49, 0x24u);
    v19 = -v49[3];
    v9 = dword_4D7EC4;
    v29 = -v49[4];
    v10 = v49[5];
    *(float *)(dword_4D7EC4 + 480) = v19;
    *(float *)(v9 + 484) = v29;
    v39 = -v10;
    *(float *)(v9 + 488) = v39;
    *(float *)(dword_4D7EC4 + 492) = v5;
    qmemcpy((void *)(dword_4D7EC4 + 504), v49, 0x24u);
    v20 = -v49[3];
    v30 = -v49[4];
    v40 = -v49[5];
    v11 = dword_4D7EC4;
    *(float *)(dword_4D7EC4 + 516) = v20;
    *(float *)(v11 + 520) = v30;
    *(float *)(v11 + 524) = v40;
    *(float *)(dword_4D7EC4 + 528) = v5;
    qmemcpy((void *)(dword_4D7EC4 + 540), v47, 0x24u);
    v21 = -v47[3];
    v31 = -v47[4];
    v41 = -v47[5];
    v12 = dword_4D7EC4;
    *(float *)(dword_4D7EC4 + 552) = v21;
    *(float *)(v12 + 556) = v31;
    *(float *)(v12 + 560) = v41;
    *(float *)(dword_4D7EC4 + 564) = v5;
    qmemcpy((void *)(dword_4D7EC4 + 576), v50, 0x24u);
    v22 = -v50[3];
    v32 = -v50[4];
    v42 = -v50[5];
    v13 = dword_4D7EC4;
    *(float *)(dword_4D7EC4 + 588) = v22;
    *(float *)(v13 + 592) = v32;
    *(float *)(v13 + 596) = v42;
    *(float *)(dword_4D7EC4 + 600) = v5;
    qmemcpy((void *)(dword_4D7EC4 + 612), v47, 0x24u);
    v23 = -v47[3];
    v33 = -v47[4];
    v43 = -v47[5];
    v14 = dword_4D7EC4;
    *(float *)(dword_4D7EC4 + 624) = v23;
    *(float *)(v14 + 628) = v33;
    *(float *)(v14 + 632) = v43;
    *(float *)(dword_4D7EC4 + 636) = v5;
    qmemcpy((void *)(dword_4D7EC4 + 648), v46, 0x24u);
    v24 = -v46[3];
    v34 = -v46[4];
    v44 = -v46[5];
    v15 = dword_4D7EC4;
    *(float *)(dword_4D7EC4 + 660) = v24;
    *(float *)(v15 + 664) = v34;
    *(float *)(v15 + 668) = v44;
    *(float *)(dword_4D7EC4 + 672) = v5;
    qmemcpy((void *)(dword_4D7EC4 + 684), v46, 0x24u);
    v25 = -v46[3];
    v35 = -v46[4];
    v45 = -v46[5];
    result = dword_4D7EC4;
    *(float *)(dword_4D7EC4 + 696) = v25;
    *(float *)(result + 700) = v35;
    *(float *)(result + 704) = v45;
    *(float *)(dword_4D7EC4 + 708) = v5;
    dword_4D7EC4 += 720;
    dword_4D7EB0 += 20;
  }
  return result;
}
