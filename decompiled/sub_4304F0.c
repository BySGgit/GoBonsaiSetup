int __fastcall sub_4304F0(unsigned int a1, int a2, int a3, LONG *a4)
{
  LONG v4; // ecx
  LONG v5; // edx
  LONG v6; // eax
  int v7; // ecx
  int v8; // edx
  unsigned int *v9; // eax
  unsigned int v10; // ebp
  int v11; // edx
  double v12; // st5
  unsigned int v13; // eax
  double v14; // st4
  double v15; // st3
  double v16; // st5
  int v17; // eax
  unsigned int i; // esi
  int v19; // eax
  float v22; // [esp+4Ch] [ebp-E8h]
  float v23; // [esp+4Ch] [ebp-E8h]
  float v24; // [esp+4Ch] [ebp-E8h]
  float v25; // [esp+4Ch] [ebp-E8h]
  float v26; // [esp+50h] [ebp-E4h]
  float v27; // [esp+50h] [ebp-E4h]
  float v28; // [esp+50h] [ebp-E4h]
  float v29; // [esp+50h] [ebp-E4h]
  float v30; // [esp+54h] [ebp-E0h]
  float v31; // [esp+54h] [ebp-E0h]
  float v32; // [esp+54h] [ebp-E0h]
  float v33; // [esp+54h] [ebp-E0h]
  float v34; // [esp+58h] [ebp-DCh]
  float v35; // [esp+58h] [ebp-DCh]
  float v36; // [esp+58h] [ebp-DCh]
  float v37; // [esp+64h] [ebp-D0h]
  float v38; // [esp+64h] [ebp-D0h]
  float v39; // [esp+64h] [ebp-D0h]
  float v40; // [esp+68h] [ebp-CCh]
  int v41; // [esp+6Ch] [ebp-C8h] BYREF
  float v42; // [esp+70h] [ebp-C4h]
  float v43; // [esp+74h] [ebp-C0h]
  float *v44; // [esp+78h] [ebp-BCh] BYREF
  int v45; // [esp+7Ch] [ebp-B8h] BYREF
  float v46[36]; // [esp+80h] [ebp-B4h] BYREF
  _BYTE v47[4]; // [esp+110h] [ebp-24h] BYREF
  unsigned int v48; // [esp+114h] [ebp-20h]
  struct tagRECT rc; // [esp+11Ch] [ebp-18h] BYREF

  v4 = a4[1];
  rc.left = *a4;
  v5 = a4[2];
  v6 = a4[3];
  rc.top = v4;
  v7 = *(_DWORD *)(a3 + 540);
  rc.right = v5;
  v8 = *(_DWORD *)(a3 + 536);
  rc.bottom = v6;
  OffsetRect(&rc, v8, v7);
  if ( *(_BYTE *)(a3 + 21) )
    OffsetRect(&rc, 0, *(_DWORD *)(a3 + 552));
  v9 = *(unsigned int **)(a3 + 572);
  v10 = v9[16];
  v37 = (float)v9[10];
  v11 = v9[11];
  v42 = (double)rc.left * 2.0 / v37 - 1.0;
  v43 = (double)rc.right * 2.0 / v37 - 1.0;
  v12 = (double)(int)v9[11];
  if ( v11 < 0 )
    v12 = v12 + 4294967300.0;
  v38 = v12;
  v13 = a1;
  v40 = 1.0 - (double)rc.top * 2.0 / v38;
  v39 = 1.0 - 2.0 * (double)rc.bottom / v38;
  v46[0] = v42;
  v46[1] = v40;
  v46[2] = flt_4D63B0;
  v22 = (double)BYTE2(a1) / 255.0;
  v14 = v22;
  v26 = v22;
  v23 = (double)BYTE1(v13) / 255.0;
  v15 = v23;
  v30 = v23;
  v24 = (double)(unsigned __int8)v13 / 255.0;
  v46[3] = v26;
  v46[4] = v30;
  v46[5] = v24;
  v16 = v24;
  v25 = (double)HIBYTE(v13) / 255.0;
  v46[7] = 0.0;
  v46[6] = v25;
  v46[8] = 0.0;
  v46[9] = v43;
  v46[10] = v40;
  v46[11] = flt_4D63B0;
  v27 = v14;
  v31 = v15;
  v46[12] = v27;
  v34 = v16;
  v46[13] = v31;
  v46[14] = v34;
  v46[16] = 1.0;
  v46[15] = v25;
  v46[17] = 0.0;
  v46[18] = v42;
  v46[19] = v39;
  v46[20] = flt_4D63B0;
  v28 = v14;
  v32 = v15;
  v46[21] = v28;
  v35 = v16;
  v46[22] = v32;
  v46[23] = v35;
  v46[25] = 0.0;
  v46[24] = v25;
  v46[26] = 1.0;
  v46[27] = v43;
  v46[28] = v39;
  v46[29] = flt_4D63B0;
  v29 = v14;
  v33 = v15;
  v36 = v16;
  v46[34] = 1.0;
  v46[35] = 1.0;
  v46[30] = v29;
  v46[33] = v25;
  v46[31] = v33;
  v17 = *(_DWORD *)(*(_DWORD *)(a3 + 572) + 28);
  v46[32] = v36;
  if ( (*(int (__stdcall **)(int, int, _DWORD, float **))(*(_DWORD *)v17 + 40))(v17, 4, 0, &v44) >= 0 )
  {
    qmemcpy(v44, v46, 0x90u);
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a3 + 572) + 28) + 44))(*(_DWORD *)(*(_DWORD *)(a3 + 572)
                                                                                               + 28));
  }
  (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a3 + 572) + 36) + 20))(*(_DWORD *)(*(_DWORD *)(a3 + 572) + 36));
  (*(void (__stdcall **)(unsigned int, int *))(*(_DWORD *)v10 + 180))(v10, &v41);
  (*(void (__stdcall **)(unsigned int, int *))(*(_DWORD *)v10 + 200))(v10, &v45);
  (*(void (__stdcall **)(unsigned int, _DWORD))(*(_DWORD *)v10 + 44))(v10, *(_DWORD *)(*(_DWORD *)(a3 + 572) + 24));
  (*(void (__stdcall **)(unsigned int, int))(*(_DWORD *)v10 + 72))(v10, 5);
  (*(void (__stdcall **)(_DWORD, _BYTE *))(**(_DWORD **)(*(_DWORD *)(a3 + 572) + 12) + 4))(
    *(_DWORD *)(*(_DWORD *)(a3 + 572) + 12),
    v47);
  for ( i = 0; i < v48; ++i )
  {
    v19 = (*(int (__stdcall **)(_DWORD, unsigned int))(**(_DWORD **)(*(_DWORD *)(a3 + 572) + 12) + 16))(
            *(_DWORD *)(*(_DWORD *)(a3 + 572) + 12),
            i);
    (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v19 + 28))(v19, 0);
    (*(void (__stdcall **)(unsigned int, int, _DWORD))(*(_DWORD *)v10 + 36))(v10, 4, 0);
  }
  (*(void (__stdcall **)(unsigned int, int))(*(_DWORD *)v10 + 44))(v10, v41);
  (*(void (__stdcall **)(unsigned int, int))(*(_DWORD *)v10 + 72))(v10, v45);
  if ( v41 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v41 + 8))(v41);
  return 0;
}
