int __thiscall sub_42E630(int this, float a2)
{
  double *EngineInstance; // esi
  _DWORD *v4; // eax
  int *v5; // esi
  float v6; // ebp
  float v7; // ecx
  float v8; // eax
  double v9; // st7
  int v10; // edx
  double v11; // st7
  void (__stdcall *v12)(int *, _DWORD); // eax
  double v13; // st6
  double v14; // st6
  int v15; // eax
  int v16; // eax
  int v17; // edx
  _WORD *v18; // eax
  int v19; // edx
  __int16 v20; // cx
  int v21; // edx
  _WORD *v22; // eax
  _DWORD *v23; // ecx
  int i; // esi
  _DWORD *v25; // eax
  double v27; // [esp+1D8h] [ebp-268h] BYREF
  int v28; // [esp+1E0h] [ebp-260h]
  int v29; // [esp+1E4h] [ebp-25Ch]
  float v30[20]; // [esp+1E8h] [ebp-258h] BYREF
  _WORD v31[258]; // [esp+238h] [ebp-208h] BYREF

  if ( dbl_4D7F20 > *(double *)(this + 8) )
  {
    EngineInstance = (double *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v27 = EngineInstance[82];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    *(double *)(this + 8) = v27;
    sub_42E570(this);
  }
  if ( *(_BYTE *)(this + 20) && (!*(_BYTE *)(this + 22) || *(_BYTE *)(this + 21)) )
  {
    v4 = *(_DWORD **)(this + 572);
    v5 = (int *)v4[15];
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v4 + 16))(*v4);
    (*(void (__stdcall **)(int *, int, int))(*v5 + 228))(v5, 27, 1);
    (*(void (__stdcall **)(int *, int, int))(*v5 + 228))(v5, 19, 5);
    (*(void (__stdcall **)(int *, int, int))(*v5 + 228))(v5, 20, 6);
    (*(void (__stdcall **)(int *, int, _DWORD))(*v5 + 228))(v5, 15, 0);
    (*(void (__stdcall **)(int *, int, _DWORD))(*v5 + 228))(v5, 206, 0);
    (*(void (__stdcall **)(int *, int, int))(*v5 + 228))(v5, 171, 1);
    (*(void (__stdcall **)(int *, int, int))(*v5 + 228))(v5, 168, 15);
    (*(void (__stdcall **)(int *, int, int))(*v5 + 228))(v5, 9, 2);
    (*(void (__stdcall **)(int *, int, _DWORD))(*v5 + 228))(v5, 28, 0);
    (*(void (__stdcall **)(int *, int, _DWORD))(*v5 + 228))(v5, 14, 0);
    (*(void (__stdcall **)(int *, int, int))(*v5 + 228))(v5, 8, 3);
    (*(void (__stdcall **)(int *, int, int))(*v5 + 228))(v5, 22, 3);
    (*(void (__stdcall **)(int *, _DWORD, int, int))(*v5 + 268))(v5, 0, 1, 3);
    (*(void (__stdcall **)(int *, _DWORD, int, _DWORD))(*v5 + 268))(v5, 0, 3, 0);
    (*(void (__stdcall **)(int *, _DWORD, int, int))(*v5 + 268))(v5, 0, 4, 2);
    (*(void (__stdcall **)(int *, _DWORD, int, _DWORD))(*v5 + 268))(v5, 0, 5, 0);
    (*(void (__stdcall **)(int *, _DWORD, int, int))(*v5 + 268))(v5, 0, 28, 1);
    (*(void (__stdcall **)(int *, int, int, int))(*v5 + 268))(v5, 1, 1, 1);
    (*(void (__stdcall **)(int *, int, int, int))(*v5 + 268))(v5, 1, 4, 1);
    if ( !*(_BYTE *)(this + 22) )
    {
      v6 = *(float *)(this + 556);
      v7 = *(float *)(this + 564);
      v8 = *(float *)(this + 568);
      if ( ((LODWORD(v8) | LODWORD(v7) | *(_DWORD *)(this + 560) | LODWORD(v6)) & 0xFF000000) != 0 )
      {
        v9 = (double)*(int *)(this + 536);
        v30[9] = *(float *)(this + 560);
        v10 = *v5;
        *(float *)&v27 = v9;
        v30[14] = v8;
        v11 = *(float *)&v27;
        v12 = *(void (__stdcall **)(int *, _DWORD))(v10 + 368);
        v30[0] = *(float *)&v27;
        v13 = (double)*(int *)(this + 540);
        v30[4] = v6;
        v30[19] = v7;
        *(float *)&v27 = v13;
        v14 = *(float *)&v27;
        v30[1] = *(float *)&v27;
        v30[2] = flt_4D63B0;
        v30[3] = 1.0;
        *(float *)&v27 = (double)*(int *)(this + 544) + v11;
        v30[5] = *(float *)&v27;
        v30[6] = v14;
        v30[7] = flt_4D63B0;
        v30[8] = 1.0;
        v30[10] = *(float *)&v27;
        *(float *)&v27 = v14 + (double)*(int *)(this + 548);
        v30[11] = *(float *)&v27;
        v30[12] = flt_4D63B0;
        v30[13] = 1.0;
        v30[15] = v11;
        v30[16] = *(float *)&v27;
        v30[17] = flt_4D63B0;
        v30[18] = 1.0;
        v12(v5, 0);
        (*(void (__stdcall **)(int *, _DWORD))(*v5 + 428))(v5, 0);
        (*(void (__stdcall **)(int *, int, _DWORD))(*v5 + 228))(v5, 7, 0);
        (*(void (__stdcall **)(int *, int))(*v5 + 356))(v5, 68);
        (*(void (__stdcall **)(int *, int, int, float *, int))(*v5 + 332))(v5, 6, 2, v30, 20);
      }
    }
    (*(void (__stdcall **)(int *, _DWORD, int, int))(*v5 + 268))(v5, 0, 1, 4);
    (*(void (__stdcall **)(int *, _DWORD, int, int))(*v5 + 268))(v5, 0, 2, 2);
    (*(void (__stdcall **)(int *, _DWORD, int, _DWORD))(*v5 + 268))(v5, 0, 3, 0);
    (*(void (__stdcall **)(int *, _DWORD, int, int))(*v5 + 268))(v5, 0, 4, 4);
    (*(void (__stdcall **)(int *, _DWORD, int, int))(*v5 + 268))(v5, 0, 5, 2);
    (*(void (__stdcall **)(int *, _DWORD, int, _DWORD))(*v5 + 268))(v5, 0, 6, 0);
    (*(void (__stdcall **)(int *, _DWORD, int, int))(*v5 + 276))(v5, 0, 6, 2);
    v15 = *(_DWORD *)(this + 572);
    if ( v15 )
      v16 = *(_DWORD *)(*(_DWORD *)(v15 + 68) + 4 * **(_DWORD **)(this + 584));
    else
      v16 = 0;
    (*(void (__stdcall **)(int *, _DWORD, _DWORD))(*v5 + 260))(v5, 0, *(_DWORD *)(v16 + 540));
    (*(void (__stdcall **)(_DWORD, int))(**(_DWORD **)(*(_DWORD *)(this + 572) + 4) + 32))(
      *(_DWORD *)(*(_DWORD *)(this + 572) + 4),
      1);
    if ( *(_BYTE *)(this + 21) )
    {
      v17 = *(_DWORD *)(this + 544);
      HIDWORD(v27) = -*(_DWORD *)(this + 552);
      v28 = v17;
      LODWORD(v27) = 0;
      v29 = 0;
      sub_430950(this + 632, (LONG *)&v27, this);
      LODWORD(v27) += 5;
      v18 = v31;
      v19 = 256;
      while ( v19 != -2147483390 )
      {
        v20 = *(_WORD *)((char *)v18 + this - (_DWORD)v31 + 24);
        if ( !v20 )
          break;
        *v18++ = v20;
        if ( !--v19 )
        {
          --v18;
          break;
        }
      }
      *v18 = 0;
      if ( *(_BYTE *)(this + 22) )
      {
        v21 = 256;
        v22 = v31;
        while ( *v22 )
        {
          ++v22;
          if ( !--v21 )
            goto LABEL_28;
        }
        sub_4193D0(v21, &v31[256 - v21], (int)L" (Minimized)", 0x7FFFFFFF);
      }
LABEL_28:
      sub_431020((LONG *)&v27, this, this + 632, (int)v31, 1, -1);
    }
    if ( !*(_BYTE *)(this + 22) )
    {
      v23 = (_DWORD *)dword_4D7F28;
      for ( i = 0; i < *(_DWORD *)(this + 612); ++i )
      {
        v25 = *(_DWORD **)(*(_DWORD *)(this + 608) + 4 * i);
        if ( v25 != v23 )
        {
          (*(void (__thiscall **)(_DWORD *, _DWORD))(*v25 + 12))(v25, LODWORD(a2));
          v23 = (_DWORD *)dword_4D7F28;
        }
      }
      if ( v23 && v23[6] == this )
        (*(void (__stdcall **)(_DWORD))(*v23 + 12))(LODWORD(a2));
    }
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(this + 572) + 4) + 44))(*(_DWORD *)(*(_DWORD *)(this + 572)
                                                                                                + 4));
    (*(void (__stdcall **)(_DWORD))(***(_DWORD ***)(this + 572) + 20))(**(_DWORD **)(this + 572));
  }
  return 0;
}
