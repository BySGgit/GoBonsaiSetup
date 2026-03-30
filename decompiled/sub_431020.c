int __userpurge sub_431020@<eax>(LONG *a1@<ecx>, int a2@<edi>, int a3@<esi>, int a4, char a5, int a6)
{
  int result; // eax
  LONG v7; // eax
  LONG v8; // edx
  LONG v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // ebp
  double v15; // st7
  int v16; // ebx
  double v17; // st4
  double v18; // st6
  int v19; // edx
  double v20; // rtt
  double v21; // st4
  double v22; // st6
  double v23; // rt0
  int v24; // eax
  int v25; // eax
  int v26; // [esp+26h] [ebp-7Ch]
  struct tagRECT rc; // [esp+3Ah] [ebp-68h] BYREF
  struct tagRECT v28; // [esp+4Ah] [ebp-58h] BYREF
  float v29[17]; // [esp+5Ah] [ebp-48h] BYREF

  if ( 0.0 == *(float *)(a3 + 104) )
    return 0;
  v7 = a1[1];
  rc.left = *a1;
  v8 = a1[2];
  rc.top = v7;
  v9 = a1[3];
  v10 = *(_DWORD *)(a2 + 540);
  rc.right = v8;
  v11 = *(_DWORD *)(a2 + 536);
  rc.bottom = v9;
  OffsetRect(&rc, v11, v10);
  if ( *(_BYTE *)(a2 + 21) )
    OffsetRect(&rc, 0, *(_DWORD *)(a2 + 552));
  v12 = *(_DWORD *)(a2 + 572);
  v29[14] = 0.0;
  v29[13] = 0.0;
  v29[12] = 0.0;
  v29[11] = 0.0;
  v29[9] = 0.0;
  v29[8] = 0.0;
  v29[7] = 0.0;
  v29[6] = 0.0;
  v29[4] = 0.0;
  v29[3] = 0.0;
  v29[2] = 0.0;
  v29[1] = 0.0;
  v29[15] = 1.0;
  v29[10] = 1.0;
  v29[5] = 1.0;
  v29[0] = 1.0;
  (*(void (__stdcall **)(_DWORD, float *))(**(_DWORD **)(v12 + 4) + 20))(*(_DWORD *)(v12 + 4), v29);
  v13 = *(_DWORD *)(a2 + 572);
  if ( v13 )
    v14 = *(_DWORD *)(*(_DWORD *)(v13 + 80) + 4 * *(_DWORD *)(*(_DWORD *)(a2 + 596) + 4 * *(_DWORD *)(a3 + 4)));
  else
    v14 = 0;
  v15 = 255.0;
  if ( a5 )
  {
    v28 = rc;
    OffsetRect(&v28, 1, 1);
    result = (*(int (__stdcall **)(_DWORD, _DWORD, int, int, struct tagRECT *, _DWORD, unsigned int))(**(_DWORD **)(v14 + 528) + 60))(
               *(_DWORD *)(v14 + 528),
               *(_DWORD *)(*(_DWORD *)(a2 + 572) + 4),
               a4,
               a6,
               &v28,
               *(_DWORD *)(a3 + 8),
               (unsigned int)(__int64)(*(float *)(a3 + 104) * 255.0) << 24);
    if ( result < 0 )
      return result;
    v15 = 255.0;
  }
  if ( *(float *)(a3 + 92) < 1.0 )
  {
    if ( *(float *)(a3 + 92) > 0.0 )
      v16 = (__int64)(*(float *)(a3 + 92) * v15 + 0.5);
    else
      v16 = 0;
  }
  else
  {
    v16 = 255;
  }
  v17 = 1.0;
  v18 = 0.0;
  if ( *(float *)(a3 + 96) < 1.0 )
  {
    if ( *(float *)(a3 + 96) > 0.0 )
      v26 = (__int64)(*(float *)(a3 + 96) * v15 + 0.5);
    else
      v26 = 0;
    v17 = 1.0;
    v18 = 0.0;
  }
  else
  {
    v26 = 255;
  }
  if ( v17 > *(float *)(a3 + 100) )
  {
    v20 = v17;
    v21 = v18;
    v22 = v20;
    if ( v21 < *(float *)(a3 + 100) )
      v19 = (__int64)(*(float *)(a3 + 100) * v15 + 0.5);
    else
      v19 = 0;
    v23 = v21;
    v17 = v22;
    v18 = v23;
  }
  else
  {
    v19 = 255;
  }
  if ( v17 > *(float *)(a3 + 104) )
  {
    if ( v18 < *(float *)(a3 + 104) )
      v24 = (__int64)(v15 * *(float *)(a3 + 104) + 0.5);
    else
      v24 = 0;
  }
  else
  {
    v24 = 255;
  }
  v25 = (*(int (__stdcall **)(_DWORD, _DWORD, int, int, struct tagRECT *, _DWORD, int))(**(_DWORD **)(v14 + 528) + 60))(
          *(_DWORD *)(v14 + 528),
          *(_DWORD *)(*(_DWORD *)(a2 + 572) + 4),
          a4,
          a6,
          &rc,
          *(_DWORD *)(a3 + 8),
          v19 | ((v26 | ((v16 | (v24 << 8)) << 8)) << 8));
  return v25 >= 0 ? 0 : v25;
}
