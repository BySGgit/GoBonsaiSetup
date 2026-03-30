int __cdecl sub_40B740(float *a1, int a2)
{
  int v2; // ecx
  int result; // eax
  int v4; // edi
  double v5; // st7
  unsigned int v6; // esi
  int v7; // eax
  float v8; // [esp+ACh] [ebp-94h]
  _BYTE v9[64]; // [esp+B4h] [ebp-8Ch] BYREF
  _BYTE v10[68]; // [esp+F4h] [ebp-4Ch] BYREF

  result = dword_4D7E9C - 50;
  v4 = v2;
  if ( dword_4D7E98 <= (unsigned int)(dword_4D7E9C - 50) )
  {
    D3DXMatrixScaling(v10, *(float *)(v2 + 444), *(float *)(v2 + 444), 0.0);
    D3DXMatrixMultiply(v9, v10, v4 + 104);
    v5 = sub_415020(v4);
    v6 = (unsigned __int8)(int)(v5 * 255.0)
       | (((unsigned __int8)(int)(v5 * 255.0) | (((int)(v5 * 255.0) | 0xFFFFFF00) << 8)) << 8);
    v7 = *(_DWORD *)(v4 + 180);
    v8 = 0.0;
    if ( v7 )
      v8 = *(float *)(v7 + 448) * flt_4D52D8 * *(float *)(v4 + 296) + a1[8] + flt_4D52D8 * *(float *)(v4 + 448);
    D3DXVec3TransformCoord(a2, &unk_4D8378, v9);
    D3DXVec3TransformNormal(a2 + 12, &unk_4D8378, v9);
    *(float *)(a2 + 28) = 0.0;
    *(float *)(a2 + 32) = v8;
    *(_DWORD *)(a2 + 24) = v6;
    D3DXVec3TransformCoord(a2 + 36, &unk_4D8384, v9);
    D3DXVec3TransformNormal(a2 + 48, &unk_4D8384, v9);
    *(float *)(a2 + 64) = 0.16666667;
    *(float *)(a2 + 68) = v8;
    *(_DWORD *)(a2 + 60) = v6;
    D3DXVec3TransformCoord(a2 + 72, &unk_4D8390, v9);
    D3DXVec3TransformNormal(a2 + 84, &unk_4D8390, v9);
    *(float *)(a2 + 100) = 0.33333334;
    *(float *)(a2 + 104) = v8;
    *(_DWORD *)(a2 + 96) = v6;
    D3DXVec3TransformCoord(a2 + 108, &unk_4D839C, v9);
    D3DXVec3TransformNormal(a2 + 120, &unk_4D839C, v9);
    *(float *)(a2 + 136) = flt_4D63B0;
    *(float *)(a2 + 140) = v8;
    *(_DWORD *)(a2 + 132) = v6;
    D3DXVec3TransformCoord(a2 + 144, &unk_4D83A8, v9);
    D3DXVec3TransformNormal(a2 + 156, &unk_4D83A8, v9);
    *(_DWORD *)(a2 + 168) = v6;
    *(float *)(a2 + 172) = 0.66666669;
    *(float *)(a2 + 176) = v8;
    D3DXVec3TransformCoord(a2 + 180, &unk_4D83B4, v9);
    D3DXVec3TransformNormal(a2 + 192, &unk_4D83B4, v9);
    *(_DWORD *)(a2 + 204) = v6;
    *(float *)(a2 + 208) = 0.83333331;
    *(float *)(a2 + 212) = v8;
    qmemcpy((void *)dword_4D7EC0, a1, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 36), a1, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 72), (const void *)a2, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 108), a1 + 9, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 144), (const void *)(a2 + 36), 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 180), a1 + 18, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 216), (const void *)(a2 + 72), 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 252), a1 + 27, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 288), (const void *)(a2 + 108), 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 324), a1 + 36, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 360), (const void *)(a2 + 144), 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 396), a1 + 45, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 432), (const void *)(a2 + 180), 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 468), a1, 0x24u);
    *(float *)(dword_4D7EC0 + 496) = 1.0;
    qmemcpy((void *)(dword_4D7EC0 + 504), (const void *)a2, 0x24u);
    result = dword_4D7EC0;
    *(float *)(dword_4D7EC0 + 532) = 1.0;
    qmemcpy((void *)(dword_4D7EC0 + 540), (const void *)a2, 0x24u);
    *(float *)(dword_4D7EC0 + 568) = 1.0;
    dword_4D7EC0 += 576;
    dword_4D7E98 += 16;
  }
  return result;
}
