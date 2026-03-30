int __usercall sub_430950@<eax>(int a1@<edx>, LONG *a2@<ecx>, int a3@<edi>)
{
  int v5; // edx
  int v6; // eax
  int v7; // edx
  LONG v8; // eax
  LONG v9; // edx
  LONG v10; // eax
  LONG v11; // ecx
  int v12; // edx
  int v13; // eax
  int v14; // eax
  int v15; // ebx
  double v16; // st7
  double v17; // st4
  double v18; // rt2
  double v19; // st4
  double v20; // st6
  int v21; // edx
  double v22; // rt1
  double v23; // st4
  double v24; // st7
  double v25; // rt2
  int v26; // eax
  float v27; // [esp+1Ch] [ebp-90h]
  float v28; // [esp+20h] [ebp-8Ch]
  int v29; // [esp+20h] [ebp-8Ch]
  int v30; // [esp+2Ch] [ebp-80h]
  struct tagRECT rc; // [esp+30h] [ebp-7Ch] BYREF
  float left; // [esp+40h] [ebp-6Ch] BYREF
  float top; // [esp+44h] [ebp-68h]
  float v34; // [esp+48h] [ebp-64h]
  int v35; // [esp+4Ch] [ebp-60h] BYREF
  int v36; // [esp+50h] [ebp-5Ch]
  int v37; // [esp+54h] [ebp-58h]
  int v38; // [esp+58h] [ebp-54h]
  _BYTE v39[76]; // [esp+5Ch] [ebp-50h] BYREF

  if ( 0.0 == *(float *)(a1 + 64) )
    return 0;
  v5 = *(_DWORD *)(a1 + 16);
  v35 = *(_DWORD *)(a1 + 12);
  v6 = *(_DWORD *)(a1 + 20);
  v36 = v5;
  v7 = *(_DWORD *)(a1 + 24);
  v37 = v6;
  v8 = *a2;
  v38 = v7;
  v9 = a2[1];
  rc.left = v8;
  v10 = a2[2];
  v11 = a2[3];
  rc.top = v9;
  v12 = *(_DWORD *)(a3 + 540);
  rc.right = v10;
  v13 = *(_DWORD *)(a3 + 536);
  rc.bottom = v11;
  OffsetRect(&rc, v13, v12);
  if ( *(_BYTE *)(a3 + 21) )
    OffsetRect(&rc, 0, *(_DWORD *)(a3 + 552));
  v14 = *(_DWORD *)(a3 + 572);
  v15 = 0;
  if ( !v14 )
    return -2147467259;
  v30 = *(_DWORD *)(*(_DWORD *)(v14 + 68) + 4 * *(_DWORD *)(*(_DWORD *)(a3 + 584) + 4 * *(_DWORD *)a1));
  if ( !v30 )
    return -2147467259;
  v28 = (double)(rc.right - rc.left) / (double)(v37 - v35);
  v27 = (double)(rc.bottom - rc.top) / (double)(v38 - v36);
  D3DXMatrixScaling(v39, LODWORD(v28), LODWORD(v27), 1.0);
  (*(void (__stdcall **)(_DWORD, _BYTE *))(**(_DWORD **)(*(_DWORD *)(a3 + 572) + 4) + 20))(
    *(_DWORD *)(*(_DWORD *)(a3 + 572) + 4),
    v39);
  left = (float)rc.left;
  top = (float)rc.top;
  v16 = 0.0;
  v34 = 0.0;
  left = left / v28;
  top = top / v27;
  v17 = 0.5;
  if ( *(float *)(a1 + 52) < 1.0 )
  {
    if ( *(float *)(a1 + 52) > 0.0 )
      v29 = (__int64)(*(float *)(a1 + 52) * 255.0 + 0.5);
    else
      v29 = 0;
    v17 = 0.5;
    v16 = 0.0;
  }
  else
  {
    v29 = 255;
  }
  v18 = v17;
  v19 = 1.0;
  v20 = v18;
  if ( *(float *)(a1 + 56) < 1.0 )
  {
    if ( v16 < *(float *)(a1 + 56) )
      v15 = (__int64)(*(float *)(a1 + 56) * 255.0 + v20);
    v19 = 1.0;
  }
  else
  {
    v15 = 255;
  }
  if ( v19 > *(float *)(a1 + 60) )
  {
    v22 = v19;
    v23 = v16;
    v24 = v22;
    if ( v23 < *(float *)(a1 + 60) )
      v21 = (__int64)(*(float *)(a1 + 60) * 255.0 + v20);
    else
      v21 = 0;
    v25 = v23;
    v19 = v24;
    v16 = v25;
  }
  else
  {
    v21 = 255;
  }
  if ( v19 > *(float *)(a1 + 64) )
  {
    if ( v16 < *(float *)(a1 + 64) )
      v26 = (__int64)(255.0 * *(float *)(a1 + 64) + v20);
    else
      v26 = 0;
  }
  else
  {
    v26 = 255;
  }
  return (*(int (__stdcall **)(_DWORD, _DWORD, int *, _DWORD, float *, int))(**(_DWORD **)(*(_DWORD *)(a3 + 572) + 4)
                                                                           + 36))(
           *(_DWORD *)(*(_DWORD *)(a3 + 572) + 4),
           *(_DWORD *)(v30 + 540),
           &v35,
           0,
           &left,
           v21 | ((v15 | ((v29 | (v26 << 8)) << 8)) << 8));
}
