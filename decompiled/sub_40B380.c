int __cdecl sub_40B380(int a1)
{
  int v1; // ecx
  int result; // eax
  int v3; // esi
  unsigned int v4; // esi
  double v5; // st7
  float v6; // [esp+98h] [ebp-90h]
  _BYTE v7[64]; // [esp+A0h] [ebp-88h] BYREF
  _BYTE v8[68]; // [esp+E0h] [ebp-48h] BYREF

  result = dword_4D7E9C - 50;
  v3 = v1;
  if ( dword_4D7E98 <= (unsigned int)(dword_4D7E9C - 50) )
  {
    D3DXMatrixScaling(v8, 0.0, 0.0, 0.0);
    D3DXMatrixMultiply(v7, v8, v3 + 104);
    v6 = 0.0 + 0.0;
    if ( v6 > 1.0 )
      v6 = 1.0;
    v4 = (unsigned __int8)(int)(v6 * 255.0)
       | (((unsigned __int8)(int)(v6 * 255.0) | (((int)(v6 * 255.0) | 0xFFFFFF00) << 8)) << 8);
    D3DXVec3TransformCoord(a1, &unk_4D8378, v7);
    D3DXVec3TransformNormal(a1 + 12, &unk_4D8378, v7);
    *(float *)(a1 + 28) = 0.0;
    *(float *)(a1 + 32) = -1.0;
    *(_DWORD *)(a1 + 24) = v4;
    D3DXVec3TransformCoord(a1 + 36, &unk_4D8384, v7);
    D3DXVec3TransformNormal(a1 + 48, &unk_4D8384, v7);
    *(float *)(a1 + 64) = 0.16666667;
    *(float *)(a1 + 68) = -1.0;
    *(_DWORD *)(a1 + 60) = v4;
    D3DXVec3TransformCoord(a1 + 72, &unk_4D8390, v7);
    D3DXVec3TransformNormal(a1 + 84, &unk_4D8390, v7);
    *(float *)(a1 + 100) = 0.33333334;
    *(float *)(a1 + 104) = -1.0;
    *(_DWORD *)(a1 + 96) = v4;
    D3DXVec3TransformCoord(a1 + 108, &unk_4D839C, v7);
    D3DXVec3TransformNormal(a1 + 120, &unk_4D839C, v7);
    v5 = flt_4D63B0;
    *(_DWORD *)(a1 + 132) = v4;
    *(float *)(a1 + 136) = v5;
    *(float *)(a1 + 140) = -1.0;
    D3DXVec3TransformCoord(a1 + 144, &unk_4D83A8, v7);
    D3DXVec3TransformNormal(a1 + 156, &unk_4D83A8, v7);
    *(float *)(a1 + 172) = 0.66666669;
    *(float *)(a1 + 176) = -1.0;
    *(_DWORD *)(a1 + 168) = v4;
    D3DXVec3TransformCoord(a1 + 180, &unk_4D83B4, v7);
    result = D3DXVec3TransformNormal(a1 + 192, &unk_4D83B4, v7);
    *(_DWORD *)(a1 + 204) = v4;
    *(float *)(a1 + 208) = 0.83333331;
    *(float *)(a1 + 212) = -1.0;
    qmemcpy((void *)dword_4D7EC0, (const void *)a1, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 36), (const void *)a1, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 72), (const void *)a1, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 108), (const void *)(a1 + 36), 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 144), (const void *)(a1 + 36), 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 180), (const void *)(a1 + 72), 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 216), (const void *)(a1 + 72), 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 252), (const void *)(a1 + 108), 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 288), (const void *)(a1 + 108), 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 324), (const void *)(a1 + 144), 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 360), (const void *)(a1 + 144), 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 396), (const void *)(a1 + 180), 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 432), (const void *)(a1 + 180), 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 468), (const void *)a1, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 504), (const void *)a1, 0x24u);
    qmemcpy((void *)(dword_4D7EC0 + 540), (const void *)a1, 0x24u);
    dword_4D7EC0 += 576;
    dword_4D7E98 += 16;
  }
  return result;
}
