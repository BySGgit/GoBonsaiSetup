void __cdecl sub_422B80(char a1)
{
  int EngineInstance; // esi
  int v2; // esi
  int v3; // esi
  bool v4; // zf
  int v5; // esi
  char v6; // bl
  int v7; // esi
  void (__stdcall *v8)(int); // esi
  int v9; // eax
  int v10; // eax
  int v11; // esi
  int v12; // esi
  int v13; // esi
  int v14; // esi
  int v15; // esi
  int v16; // esi
  int v17; // esi
  int v18; // esi
  int v19; // esi
  int v20; // esi
  int v21; // esi
  char v22; // bl
  int v23; // esi
  void (__stdcall *v24)(int); // esi
  int v25; // eax
  int v26; // eax
  int v27; // esi
  int v28; // esi
  int v29; // esi
  int v30; // esi
  int v31; // esi
  int v32; // esi
  int v33; // esi
  int v34; // esi
  _DWORD *v35; // edi
  int v36; // esi
  unsigned int v37; // ebx
  unsigned int i; // esi
  int v39; // eax
  void *v40; // esi
  _DWORD *v41; // esi
  void *v42; // esi
  _DWORD *v43; // esi
  void *v44; // esi
  _DWORD *v45; // esi
  int v46; // esi
  void *v47; // esi
  _DWORD *v48; // esi
  void *v49; // esi
  _DWORD *v50; // esi
  int v51; // esi
  void *v52; // esi
  _DWORD *v53; // esi
  void *v54; // esi
  _DWORD *v55; // esi
  void *v56; // esi
  _DWORD *v57; // esi
  void *v58; // esi
  void *v59; // esi
  _DWORD *v60; // esi
  void *v61; // esi
  _DWORD *v62; // esi
  void *v63; // esi
  _BYTE *v64; // esi
  int v65; // [esp+30h] [ebp-10h]

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = *(_DWORD *)(EngineInstance + 368);
  v65 = v2;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v2 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v2 + 276))(v2);
    v3 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    *(_BYTE *)(v3 + 780) = 1;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    v5 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v6 = *(_BYTE *)(v5 + 779);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v6 )
    {
      v7 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v8 = *(void (__stdcall **)(int))(v7 + 924);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( v8 )
      {
        v9 = GetEngineInstance();
        v10 = sub_41B220(v9);
        v8(v10);
      }
      v11 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      *(_BYTE *)(v11 + 779) = 0;
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
    }
    v12 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v13 = *(_DWORD *)(v12 + 380);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v13 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v13 + 8))(v13);
    v14 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    *(_DWORD *)(v14 + 380) = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    v15 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v16 = *(_DWORD *)(v15 + 384);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v16 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(v16);
    v17 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    *(_DWORD *)(v17 + 384) = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    v18 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v19 = *(_DWORD *)(v18 + 388);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v19 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v19 + 8))(v19);
    v20 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    *(_DWORD *)(v20 + 388) = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    v21 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v22 = *(_BYTE *)(v21 + 778);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v22 )
    {
      v23 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v24 = *(void (__stdcall **)(int))(v23 + 928);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( v24 )
      {
        v25 = GetEngineInstance();
        v26 = sub_41B1A0(v25);
        v24(v26);
      }
      v27 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v4 = byte_4CA649 == 0;
      *(_BYTE *)(v27 + 778) = 0;
      if ( !v4 )
        LeaveCriticalSection(&CriticalSection);
    }
    v28 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    *(_BYTE *)(v28 + 780) = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    v29 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    *(_BYTE *)(v29 + 862) = 1;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    v30 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v31 = *(_DWORD *)(v30 + 376);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v31 )
    {
      (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)v31 + 40))(v31, 0, 0);
      (*(void (__stdcall **)(int))(*(_DWORD *)v31 + 8))(v31);
    }
    v32 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    *(_DWORD *)(v32 + 376) = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    v33 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    *(_BYTE *)(v33 + 862) = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    v34 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v35 = *(_DWORD **)(v34 + 360);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v36 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v37 = *(_DWORD *)(v36 + 364);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    for ( i = 0; i < v37; ++i )
    {
      v39 = v35[i];
      if ( v39 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v39 + 8))(v35[i]);
        v35[i] = 0;
      }
    }
    operator delete[](v35);
    if ( (dword_4D8E98 & 1) == 0 )
    {
      dword_4D8E98 |= 1u;
      if ( !dword_4D7F04 )
      {
        v40 = operator new(0x1E80u);
        if ( v40 )
          sub_419430((int)v40);
        else
          v40 = 0;
        dword_4D7F04 = v40;
      }
      atexit(sub_4724C0);
    }
    v41 = dword_4D7F04;
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    v41[90] = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    if ( (dword_4D8E98 & 1) == 0 )
    {
      dword_4D8E98 |= 1u;
      if ( !dword_4D7F04 )
      {
        v42 = operator new(0x1E80u);
        if ( v42 )
          sub_419430((int)v42);
        else
          v42 = 0;
        dword_4D7F04 = v42;
      }
      atexit(sub_4724C0);
    }
    v43 = dword_4D7F04;
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    v43[91] = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    if ( (dword_4D8E98 & 1) == 0 )
    {
      dword_4D8E98 |= 1u;
      if ( !dword_4D7F04 )
      {
        v44 = operator new(0x1E80u);
        if ( v44 )
          sub_419430((int)v44);
        else
          v44 = 0;
        dword_4D7F04 = v44;
      }
      atexit(sub_4724C0);
    }
    v45 = dword_4D7F04;
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v46 = v45[89];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v46 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v46 + 8))(v46);
    if ( (dword_4D8E98 & 1) == 0 )
    {
      dword_4D8E98 |= 1u;
      if ( !dword_4D7F04 )
      {
        v47 = operator new(0x1E80u);
        if ( v47 )
          sub_419430((int)v47);
        else
          v47 = 0;
        dword_4D7F04 = v47;
      }
      atexit(sub_4724C0);
    }
    v48 = dword_4D7F04;
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    v48[89] = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    sub_423640();
    if ( (dword_4D8E98 & 1) == 0 )
    {
      dword_4D8E98 |= 1u;
      if ( !dword_4D7F04 )
      {
        v49 = operator new(0x1E80u);
        if ( v49 )
          sub_419430((int)v49);
        else
          v49 = 0;
        dword_4D7F04 = v49;
      }
      atexit(sub_4724C0);
    }
    v50 = dword_4D7F04;
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v51 = v50[93];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v51 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v51 + 8))(v51);
    if ( (dword_4D8E98 & 1) == 0 )
    {
      dword_4D8E98 |= 1u;
      if ( !dword_4D7F04 )
      {
        v52 = operator new(0x1E80u);
        if ( v52 )
          sub_419430((int)v52);
        else
          v52 = 0;
        dword_4D7F04 = v52;
      }
      atexit(sub_4724C0);
    }
    v53 = dword_4D7F04;
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    v53[93] = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    if ( (*(int (__stdcall **)(int))(*(_DWORD *)v65 + 8))(v65) )
      sub_4256B0(-2147219196);
    if ( (dword_4D8E98 & 1) == 0 )
    {
      dword_4D8E98 |= 1u;
      if ( !dword_4D7F04 )
      {
        v54 = operator new(0x1E80u);
        if ( v54 )
          sub_419430((int)v54);
        else
          v54 = 0;
        dword_4D7F04 = v54;
      }
      atexit(sub_4724C0);
    }
    v55 = dword_4D7F04;
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    v55[92] = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
    if ( a1 )
    {
      if ( (dword_4D8E98 & 1) == 0 )
      {
        dword_4D8E98 |= 1u;
        if ( !dword_4D7F04 )
        {
          v56 = operator new(0x1E80u);
          if ( v56 )
            sub_419430((int)v56);
          else
            v56 = 0;
          dword_4D7F04 = v56;
        }
        atexit(sub_4724C0);
      }
      v57 = dword_4D7F04;
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v58 = (void *)v57[2];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( v58 )
        operator delete(v58);
      if ( (dword_4D8E98 & 1) == 0 )
      {
        dword_4D8E98 |= 1u;
        if ( !dword_4D7F04 )
        {
          v59 = operator new(0x1E80u);
          if ( v59 )
            sub_419430((int)v59);
          else
            v59 = 0;
          dword_4D7F04 = v59;
        }
        atexit(sub_4724C0);
      }
      v60 = dword_4D7F04;
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v4 = byte_4CA649 == 0;
      v60[2] = 0;
      if ( !v4 )
        LeaveCriticalSection(&CriticalSection);
    }
    if ( (dword_4D8E98 & 1) == 0 )
    {
      dword_4D8E98 |= 1u;
      if ( !dword_4D7F04 )
      {
        v61 = operator new(0x1E80u);
        if ( v61 )
          sub_419430((int)v61);
        else
          v61 = 0;
        dword_4D7F04 = v61;
      }
      atexit(sub_4724C0);
    }
    v62 = dword_4D7F04;
    if ( byte_4CA649 )
    {
      EnterCriticalSection(&CriticalSection);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
    }
    v4 = (dword_4D8E98 & 1) == 0;
    v62[98] = 0;
    v62[99] = 0;
    v62[100] = 0;
    v62[101] = 0;
    v62[102] = 0;
    if ( v4 )
    {
      dword_4D8E98 |= 1u;
      if ( !dword_4D7F04 )
      {
        v63 = operator new(0x1E80u);
        if ( v63 )
          sub_419430((int)v63);
        else
          v63 = 0;
        dword_4D7F04 = v63;
      }
      atexit(sub_4724C0);
    }
    v64 = dword_4D7F04;
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = byte_4CA649 == 0;
    v64[774] = 0;
    if ( !v4 )
      LeaveCriticalSection(&CriticalSection);
  }
}
