int __userpurge sub_42EB50@<eax>(int a1@<edi>, int a2@<esi>, int a3, int a4, int a5, int a6)
{
  double *EngineInstance; // esi
  int v7; // eax
  int v8; // ebx
  unsigned int v9; // ecx
  unsigned int v10; // edi
  _DWORD *v11; // esi
  double v12; // st7
  float v13; // eax
  double v14; // st4
  int v15; // edx
  double v16; // st5
  float *v17; // eax
  float v18; // ecx
  float v19; // edx
  float v20; // ecx
  float v21; // edx
  unsigned int v22; // ecx
  float *v23; // eax
  float v24; // ecx
  float v25; // edx
  float v26; // ecx
  float v27; // edx
  unsigned int v28; // ecx
  float *v29; // eax
  float v30; // ecx
  float v31; // edx
  float v32; // ecx
  float v33; // edx
  float *v34; // eax
  float v35; // ecx
  float v36; // edx
  int *v37; // esi
  float v38; // edx
  int v39; // eax
  void (__stdcall *v40)(int, _DWORD, int, int, float *, char *); // edx
  unsigned int i; // esi
  int v42; // eax
  int v43; // eax
  int v44; // ecx
  int v45; // eax
  int v46; // eax
  _WORD *v47; // eax
  int v48; // edx
  __int16 v49; // cx
  int v50; // edx
  _WORD *v51; // eax
  _DWORD *v52; // ecx
  int j; // esi
  _DWORD *v54; // eax
  int v55; // eax
  int v56; // eax
  int v58; // [esp+88h] [ebp-2D8h]
  double v60; // [esp+A4h] [ebp-2BCh] BYREF
  float v61; // [esp+ACh] [ebp-2B4h] BYREF
  float v62; // [esp+B4h] [ebp-2ACh]
  float v63; // [esp+B8h] [ebp-2A8h] BYREF
  LONG v64; // [esp+BCh] [ebp-2A4h] BYREF
  int v65; // [esp+C0h] [ebp-2A0h]
  float v66; // [esp+C4h] [ebp-29Ch]
  float v67; // [esp+C8h] [ebp-298h]
  float v68[36]; // [esp+CCh] [ebp-294h] BYREF
  _WORD v69[254]; // [esp+15Ch] [ebp-204h] BYREF

  if ( dbl_4D7F20 > *(double *)(a3 + 8) )
  {
    EngineInstance = (double *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v60 = EngineInstance[82];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    *(double *)(a3 + 8) = v60;
    sub_42E570(a3);
  }
  if ( *(_BYTE *)(a3 + 20) && (!*(_BYTE *)(a3 + 22) || *(_BYTE *)(a3 + 21)) )
  {
    v7 = *(_DWORD *)(a3 + 572);
    v8 = *(_DWORD *)(v7 + 64);
    (*(void (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(v7 + 32) + 12))(*(_DWORD *)(v7 + 32), a1, a2);
    if ( !*(_BYTE *)(a3 + 22) )
    {
      v9 = *(_DWORD *)(a3 + 556);
      v10 = *(_DWORD *)(a3 + 568);
      if ( ((v10 | *(_DWORD *)(a3 + 564) | *(_DWORD *)(a3 + 560) | v9) & 0xFF000000) != 0 )
      {
        v11 = *(_DWORD **)(a3 + 572);
        v61 = *(float *)(a3 + 536);
        *((float *)&v60 + 1) = (float)(unsigned int)v11[10];
        v12 = (double)SLODWORD(v61);
        LODWORD(v61) += *(_DWORD *)(a3 + 544);
        v13 = *(float *)(a3 + 540);
        v63 = v12 * 2.0 / *((float *)&v60 + 1) - 1.0;
        v14 = (double)SLODWORD(v61);
        v61 = v13;
        *((float *)&v60 + 1) = v14 * 2.0 / *((float *)&v60 + 1) - 1.0;
        v62 = (float)(unsigned int)v11[11];
        v15 = LODWORD(v13) + *(_DWORD *)(a3 + 548);
        v16 = v62;
        v62 = 1.0 - (double)SLODWORD(v13) * 2.0 / v62;
        v61 = 1.0 - 2.0 * (double)v15 / v16;
        v68[0] = v63;
        v68[1] = v62;
        v68[2] = flt_4D63B0;
        v17 = sub_42DD40((float *)&v64, v9);
        v18 = *v17;
        v19 = v17[1];
        v68[7] = 0.0;
        v68[8] = 0.0;
        v68[3] = v18;
        v20 = v17[2];
        v68[9] = *((float *)&v60 + 1);
        v68[4] = v19;
        v21 = v17[3];
        v68[10] = v62;
        v68[5] = v20;
        v22 = *(_DWORD *)(a3 + 560);
        v68[11] = flt_4D63B0;
        v68[6] = v21;
        v23 = sub_42DD40((float *)&v64, v22);
        v24 = *v23;
        v68[16] = 1.0;
        v25 = v23[1];
        v68[17] = 0.0;
        v68[12] = v24;
        v26 = v23[2];
        v68[18] = v63;
        v68[13] = v25;
        v27 = v23[3];
        v68[19] = v61;
        v68[14] = v26;
        v28 = *(_DWORD *)(a3 + 564);
        v68[20] = flt_4D63B0;
        v68[15] = v27;
        v29 = sub_42DD40((float *)&v64, v28);
        v30 = *v29;
        v68[25] = 0.0;
        v31 = v29[1];
        v68[21] = v30;
        v32 = v29[2];
        v68[26] = 1.0;
        v68[22] = v31;
        v33 = v29[3];
        v68[27] = *((float *)&v60 + 1);
        v68[23] = v32;
        v68[24] = v33;
        v68[28] = v61;
        v68[29] = flt_4D63B0;
        v34 = sub_42DD40((float *)&v64, v10);
        v35 = *v34;
        v36 = v34[1];
        v68[34] = 1.0;
        v37 = (int *)v11[7];
        v68[35] = 1.0;
        v68[30] = v35;
        v68[32] = v34[2];
        v68[31] = v36;
        v38 = v34[3];
        v39 = *v37;
        v68[33] = v38;
        if ( (*(int (__stdcall **)(int *, int, _DWORD, float *))(v39 + 40))(v37, 4, 0, &v61) >= 0 )
        {
          qmemcpy((void *)LODWORD(v61), v68, 0x90u);
          (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a3 + 572) + 28) + 44))(*(_DWORD *)(*(_DWORD *)(a3 + 572) + 28));
        }
        v40 = *(void (__stdcall **)(int, _DWORD, int, int, float *, char *))(*(_DWORD *)v8 + 48);
        v58 = *(_DWORD *)(a3 + 572) + 28;
        LODWORD(v63) = 36;
        HIDWORD(v60) = 0;
        v40(v8, 0, 1, v58, &v63, (char *)&v60 + 4);
        (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v8 + 44))(v8, *(_DWORD *)(*(_DWORD *)(a3 + 572) + 24));
        (*(void (__stdcall **)(int, int))(*(_DWORD *)v8 + 72))(v8, 5);
        (*(void (__stdcall **)(_DWORD, LONG *))(**(_DWORD **)(*(_DWORD *)(a3 + 572) + 16) + 4))(
          *(_DWORD *)(*(_DWORD *)(a3 + 572) + 16),
          &v64);
        for ( i = 0; i < v65; ++i )
        {
          v42 = (*(int (__stdcall **)(_DWORD, unsigned int))(**(_DWORD **)(*(_DWORD *)(a3 + 572) + 16) + 16))(
                  *(_DWORD *)(*(_DWORD *)(a3 + 572) + 16),
                  i);
          (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v42 + 28))(v42, 0);
          (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v8 + 36))(v8, 4, 0);
        }
      }
    }
    v43 = *(_DWORD *)(a3 + 572);
    if ( v43 )
      v44 = *(_DWORD *)(*(_DWORD *)(v43 + 68) + 4 * **(_DWORD **)(a3 + 584));
    else
      v44 = 0;
    (*(void (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)(v43 + 20) + 100))(
      *(_DWORD *)(v43 + 20),
      *(_DWORD *)(v44 + 548));
    (*(void (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)(a3 + 572) + 36) + 12))(
      *(_DWORD *)(*(_DWORD *)(a3 + 572) + 36),
      0);
    v45 = (*(int (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)(a3 + 572) + 12) + 16))(
            *(_DWORD *)(*(_DWORD *)(a3 + 572) + 12),
            0);
    (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v45 + 28))(v45, 0);
    if ( *(_BYTE *)(a3 + 21) )
    {
      v46 = -*(_DWORD *)(a3 + 552);
      v66 = *(float *)(a3 + 544);
      v64 = 0;
      v65 = v46;
      v67 = 0.0;
      sub_430C90(&v64, a3, a3 + 632, 0.99000001);
      v64 += 5;
      v47 = v69;
      v48 = 256;
      while ( v48 != -2147483390 )
      {
        v49 = *(_WORD *)((char *)v47 + a3 - (_DWORD)v69 + 24);
        if ( !v49 )
          break;
        *v47++ = v49;
        if ( !--v48 )
        {
          --v47;
          break;
        }
      }
      *v47 = 0;
      if ( *(_BYTE *)(a3 + 22) )
      {
        v50 = 256;
        v51 = v69;
        while ( *v51 )
        {
          ++v51;
          if ( !--v50 )
            goto LABEL_31;
        }
        sub_4193D0(v50, &v69[256 - v50], (int)L" (Minimized)", 0x7FFFFFFF);
      }
LABEL_31:
      sub_431380(&v64, a3 + 632, a3, (int)v69, 1, -1);
    }
    if ( !*(_BYTE *)(a3 + 22) )
    {
      v52 = (_DWORD *)dword_4D7F28;
      for ( j = 0; j < *(_DWORD *)(a3 + 612); ++j )
      {
        v54 = *(_DWORD **)(*(_DWORD *)(a3 + 608) + 4 * j);
        if ( v54 != v52 )
        {
          (*(void (__thiscall **)(_DWORD *, int))(*v54 + 12))(v54, a6);
          v52 = (_DWORD *)dword_4D7F28;
        }
      }
      if ( v52 && v52[6] == a3 )
        (*(void (__stdcall **)(int))(*v52 + 12))(a6);
    }
    (*(void (__cdecl **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a3 + 572) + 36) + 28))(*(_DWORD *)(*(_DWORD *)(a3 + 572) + 36));
    (*(void (__cdecl **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a3 + 572) + 32) + 16))(*(_DWORD *)(*(_DWORD *)(a3 + 572) + 32));
    v55 = (*(int (__stdcall **)(_DWORD, const char *))(**(_DWORD **)(*(_DWORD *)(a3 + 572) + 8) + 52))(
            *(_DWORD *)(*(_DWORD *)(a3 + 572) + 8),
            "RestoreState");
    v56 = (*(int (__stdcall **)(int, _DWORD))(*(_DWORD *)v55 + 16))(v55, 0);
    (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v56 + 28))(v56, 0);
  }
  return 0;
}
