int __userpurge sub_4302D0@<eax>(int a1@<ecx>, float a2@<edi>, LONG *a3)
{
  LONG v3; // edx
  LONG v5; // ecx
  LONG v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  double v10; // st6
  double v11; // st5
  int v12; // esi
  float v14; // [esp+6Ch] [ebp-90h]
  float v15; // [esp+6Ch] [ebp-90h]
  float v16; // [esp+6Ch] [ebp-90h]
  float v17; // [esp+6Ch] [ebp-90h]
  int v18; // [esp+70h] [ebp-8Ch] BYREF
  struct tagRECT rc; // [esp+74h] [ebp-88h] BYREF
  float v20[29]; // [esp+84h] [ebp-78h] BYREF

  v3 = a3[1];
  rc.left = *a3;
  v5 = a3[2];
  rc.top = v3;
  v6 = a3[3];
  v7 = *(_DWORD *)(a1 + 540);
  rc.right = v5;
  v8 = *(_DWORD *)(a1 + 536);
  rc.bottom = v6;
  OffsetRect(&rc, v8, v7);
  if ( *(_BYTE *)(a1 + 21) )
    OffsetRect(&rc, 0, *(_DWORD *)(a1 + 552));
  v9 = *(_DWORD *)(a1 + 572);
  v20[4] = a2;
  v20[11] = a2;
  v20[18] = a2;
  v20[25] = a2;
  v14 = (double)rc.left - 0.5;
  v10 = v14;
  v20[0] = v14;
  v15 = (double)rc.top - 0.5;
  v11 = v15;
  v20[1] = v15;
  v20[2] = flt_4D63B0;
  v20[3] = 1.0;
  v20[5] = 0.0;
  v20[6] = 0.0;
  v16 = (double)rc.right - 0.5;
  v20[7] = v16;
  v20[8] = v11;
  v20[9] = flt_4D63B0;
  v20[10] = 1.0;
  v20[12] = 0.0;
  v20[13] = 0.0;
  v20[14] = v16;
  v17 = (double)rc.bottom - 0.5;
  v20[15] = v17;
  v20[16] = flt_4D63B0;
  v20[17] = 1.0;
  v20[19] = 0.0;
  v20[20] = 0.0;
  v20[21] = v10;
  v20[22] = v17;
  v20[23] = flt_4D63B0;
  v20[24] = 1.0;
  v20[26] = 0.0;
  v20[27] = 0.0;
  v12 = *(_DWORD *)(v9 + 60);
  (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v9 + 4) + 40))(*(_DWORD *)(v9 + 4));
  v18 = 0;
  (*(void (__stdcall **)(int, int *))(*(_DWORD *)v12 + 352))(v12, &v18);
  (*(void (__stdcall **)(int, int))(*(_DWORD *)v12 + 356))(v12, 324);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)v12 + 268))(v12, 0, 1, 3);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)v12 + 268))(v12, 0, 4, 3);
  (*(void (__stdcall **)(int, int, int, float *, int))(*(_DWORD *)v12 + 332))(v12, 6, 2, v20, 28);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)v12 + 268))(v12, 0, 1, 4);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)v12 + 268))(v12, 0, 4, 4);
  (*(void (__stdcall **)(int, int))(*(_DWORD *)v12 + 348))(v12, v18);
  (*(void (__stdcall **)(int))(*(_DWORD *)v18 + 8))(v18);
  return 0;
}
