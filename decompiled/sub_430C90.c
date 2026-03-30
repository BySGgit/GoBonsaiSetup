int __fastcall sub_430C90(LONG *a1, int a2, int a3, float a4)
{
  LONG v6; // edx
  LONG v7; // eax
  LONG v8; // ecx
  int v9; // edx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  unsigned int v13; // eax
  int v14; // ecx
  int v15; // ecx
  int v16; // eax
  float v17; // [esp+2Ch] [ebp-1DCh]
  float v18; // [esp+30h] [ebp-1D8h]
  unsigned int *v19; // [esp+50h] [ebp-1B8h]
  float v20; // [esp+50h] [ebp-1B8h]
  float v21; // [esp+54h] [ebp-1B4h]
  float v22; // [esp+58h] [ebp-1B0h]
  float v23; // [esp+58h] [ebp-1B0h]
  float v24; // [esp+5Ch] [ebp-1ACh]
  int v25; // [esp+60h] [ebp-1A8h]
  int v26; // [esp+64h] [ebp-1A4h]
  int v27; // [esp+68h] [ebp-1A0h]
  int v28; // [esp+6Ch] [ebp-19Ch]
  float left; // [esp+74h] [ebp-194h]
  float top; // [esp+78h] [ebp-190h]
  _DWORD v32[26]; // [esp+80h] [ebp-188h] BYREF
  struct tagRECT rc; // [esp+E8h] [ebp-120h] BYREF
  _BYTE v34[64]; // [esp+F8h] [ebp-110h] BYREF
  _BYTE v35[64]; // [esp+138h] [ebp-D0h] BYREF
  _BYTE v36[64]; // [esp+178h] [ebp-90h] BYREF
  _BYTE v37[76]; // [esp+1B8h] [ebp-50h] BYREF

  if ( 0.0 == *(float *)(a3 + 64) )
    return 0;
  v25 = *(_DWORD *)(a3 + 12);
  v26 = *(_DWORD *)(a3 + 16);
  v27 = *(_DWORD *)(a3 + 20);
  v28 = *(_DWORD *)(a3 + 24);
  v6 = a1[1];
  rc.left = *a1;
  v7 = a1[2];
  v8 = a1[3];
  rc.top = v6;
  v9 = *(_DWORD *)(a2 + 540);
  rc.right = v7;
  v10 = *(_DWORD *)(a2 + 536);
  rc.bottom = v8;
  OffsetRect(&rc, v10, v9);
  OffsetRect(&rc, (rc.right - rc.left) / 2, (rc.bottom - rc.top) / 2);
  if ( *(_BYTE *)(a2 + 21) )
    OffsetRect(&rc, 0, *(_DWORD *)(a2 + 552));
  v11 = *(_DWORD *)(a2 + 572);
  if ( !v11 )
    return -2147467259;
  v19 = *(unsigned int **)(*(_DWORD *)(v11 + 68) + 4 * *(_DWORD *)(*(_DWORD *)(a2 + 584) + 4 * *(_DWORD *)a3));
  if ( !v19 )
    return -2147467259;
  v12 = *(_DWORD *)(a2 + 572);
  v22 = (float)*(unsigned int *)(v12 + 40);
  v24 = (float)*(unsigned int *)(v12 + 44);
  left = (float)rc.left;
  top = (float)rc.top;
  v18 = (float)(rc.bottom - rc.top);
  v17 = (float)(rc.right - rc.left);
  D3DXMatrixScaling(v34, LODWORD(v17), LODWORD(v18), 1.0);
  v21 = v24 - top;
  D3DXMatrixTranslation(v36, LODWORD(left), LODWORD(v21), LODWORD(a4));
  D3DXMatrixOrthoOffCenterLH(v37, 0.0, LODWORD(v22), 0.0, LODWORD(v24), LODWORD(flt_4CA5E8), 10.0);
  (*(void (__stdcall **)(_DWORD, _BYTE *))(**(_DWORD **)(*(_DWORD *)(a2 + 572) + 36) + 44))(
    *(_DWORD *)(*(_DWORD *)(a2 + 572) + 36),
    v37);
  D3DXMatrixMultiply(v35, v34, v36);
  qmemcpy(v32, v35, 0x40u);
  v32[24] = v19[137];
  v13 = v19[134];
  v20 = (float)v19[133];
  v23 = (float)v13;
  v14 = *(_DWORD *)(a3 + 52);
  v32[21] = *(_DWORD *)(a3 + 56);
  v32[20] = v14;
  v15 = *(_DWORD *)(a3 + 64);
  v32[25] = 0;
  v32[23] = v15;
  *(float *)&v32[16] = (double)v25 / v20;
  *(float *)&v32[17] = (double)v26 / v23;
  v32[22] = *(_DWORD *)(a3 + 60);
  v16 = *(_DWORD *)(a2 + 572);
  *(float *)&v32[18] = (double)(v27 - v25) / v20;
  *(float *)&v32[19] = (double)(v28 - v26) / v23;
  return (*(int (__stdcall **)(_DWORD, _DWORD *, int))(**(_DWORD **)(v16 + 36) + 16))(*(_DWORD *)(v16 + 36), v32, 1);
}
