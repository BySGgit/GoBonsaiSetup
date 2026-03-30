void __cdecl sub_41F7F0(_DWORD *a1)
{
  _DWORD *v1; // esi
  int v2; // esi
  _DWORD *v3; // esi
  int v4; // esi
  _BYTE *v5; // esi
  char v6; // bl
  _BYTE *v7; // esi
  char v8; // bl
  _BYTE *v9; // esi
  char v10; // bl
  _BYTE *v11; // esi
  char v12; // bl
  _DWORD *v13; // esi
  int v14; // esi
  _DWORD *v15; // esi
  int v16; // esi
  _DWORD *v17; // edi
  _DWORD *v18; // esi
  int v19; // esi
  _DWORD *v20; // esi
  int v21; // esi
  _BYTE *v22; // esi
  char v23; // bl
  _BYTE *v24; // esi
  char v25; // bl
  void *v26; // eax
  _DWORD *EngineInstance; // esi
  int v28; // esi
  _DWORD *v29; // esi
  int v30; // esi
  _DWORD *v31; // edi
  _BYTE *v32; // esi
  char v33; // bl
  _BYTE *v34; // esi
  char v35; // bl
  _BYTE *v36; // esi
  char v37; // bl
  void (__stdcall *v38)(LPCRITICAL_SECTION); // edi
  _BYTE *v39; // esi
  char v40; // bl
  _DWORD *v41; // esi
  int v42; // esi
  _DWORD *v43; // esi
  int v44; // esi
  _DWORD *v45; // esi
  int v46; // esi
  _DWORD *v47; // esi
  int v48; // esi

  if ( !a1 || *a1 )
  {
    EngineInstance = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v28 = EngineInstance[202];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v28 == -1 )
    {
      v31 = a1;
    }
    else
    {
      v29 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v30 = v29[202];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      v31 = a1;
      a1[1] = v30;
    }
    v32 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v33 = v32[820];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v33 )
    {
      v31[16] = 0;
      v31[18] = 2;
    }
    v34 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v35 = v34[812];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v35 )
    {
      a1[16] = 1;
      a1[18] = 0;
    }
    v36 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v37 = v36[841];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v37 )
    {
      a1[2] = 1;
      v38 = LeaveCriticalSection;
    }
    else
    {
      v39 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v40 = v39[840];
      v38 = LeaveCriticalSection;
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( v40 )
        a1[2] = 0;
    }
    v41 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v42 = v41[208];
    if ( byte_4CA649 )
      v38(&CriticalSection);
    if ( v42 )
    {
      v43 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v44 = v43[208];
      if ( byte_4CA649 )
        v38(&CriticalSection);
      a1[4] = v44;
    }
    v45 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v46 = v45[209];
    if ( byte_4CA649 )
      v38(&CriticalSection);
    if ( v46 )
    {
      v47 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v48 = v47[209];
      if ( byte_4CA649 )
        v38(&CriticalSection);
      a1[5] = v48;
    }
  }
  else
  {
    v1 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v2 = v1[202];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v2 != -1 )
    {
      v3 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v4 = v3[202];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      a1[1] = v4;
    }
    v5 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v6 = v5[820];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v6 )
      a1[13] = 0;
    v7 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v8 = v7[812];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v8 )
      a1[13] = 1;
    v9 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v10 = v9[841];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v10 )
    {
      a1[2] = 2;
    }
    else
    {
      v11 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v12 = v11[840];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( v12 )
        a1[2] = 1;
    }
    v13 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v14 = v13[208];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v14 )
    {
      v15 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v16 = v15[208];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      v17 = a1;
      a1[5] = v16;
    }
    else
    {
      v17 = a1;
    }
    v18 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v19 = v18[209];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v19 )
    {
      v20 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v21 = v20[209];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      v17[6] = v21;
    }
    v22 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v23 = v22[842];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v23 )
    {
      v17[4] = v17[4] & 0xFFFFFF8F | 0x50;
    }
    else
    {
      v24 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v25 = v24[843];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( v25 )
      {
        v17[4] = v17[4] & 0xFFFFFF8F | 0x40;
      }
      else
      {
        v26 = GetEngineInstance();
        if ( sub_41ABE0((int)v26) )
          v17[4] = v17[4] & 0xFFFFFF8F | 0x20;
      }
    }
  }
}
