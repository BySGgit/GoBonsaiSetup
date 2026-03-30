int __thiscall sub_421960(ID3D10Device *this)
{
  _DWORD *EngineInstance; // esi
  _DWORD *v3; // ebx
  _DWORD *v4; // esi
  int v5; // esi
  UINT v6; // esi
  D3D10_DRIVER_TYPE v7; // edi
  IDXGIAdapter *v8; // ebp
  HRESULT v9; // eax
  UINT v10; // esi
  D3D10_DRIVER_TYPE v11; // edi
  IDXGIAdapter *v12; // ebp
  int v13; // esi
  void *v14; // eax
  UINT i; // ebp
  void *v16; // eax
  void *v17; // ebx
  UINT v19; // esi
  IDXGIOutput **v20; // edi
  void *v21; // esi
  _DWORD *v22; // esi
  bool v23; // zf
  void *v24; // esi
  _DWORD *v25; // esi
  void *v26; // esi
  ID3D10Device *v27; // esi
  _DWORD *v28; // edi
  void *v29; // esi
  ID3D10Device1 *v30; // esi
  _DWORD *v31; // edi
  void *v32; // esi
  int v33; // esi
  _DWORD *v34; // edi
  int v35; // ebx
  void (__stdcall *v36)(LPCRITICAL_SECTION); // edi
  _DWORD *v37; // esi
  int v38; // esi
  _DWORD *v39; // esi
  _DWORD *v40; // esi
  int v41; // esi
  _DWORD *v42; // esi
  _DWORD *v43; // eax
  int v44; // esi
  int v45; // ecx
  _DWORD *v46; // eax
  _DWORD *v47; // edx
  void *v48; // esi
  char *v49; // esi
  char *v50; // ebx
  void *v51; // esi
  _BYTE *v52; // esi
  void *v53; // esi
  _DWORD *v54; // esi
  int (__stdcall *v55)(int, char *, int); // ebp
  int v56; // edi
  _DWORD *v57; // esi
  int v58; // edi
  _DWORD *v59; // esi
  int v60; // esi
  void *v61; // esi
  _BYTE *v62; // esi
  void *v63; // esi
  _DWORD *v64; // esi
  int v65; // esi
  _BYTE *v66; // esi
  _BYTE *v67; // esi
  _DWORD *v68; // esi
  int (__stdcall *v69)(int, int, char *, int); // esi
  int v70; // edi
  void *v71; // eax
  int v72; // eax
  _BYTE *v73; // esi
  _DWORD *v74; // esi
  int v75; // esi
  void *v76; // eax
  int v77; // [esp+48h] [ebp-50h]
  int v78; // [esp+50h] [ebp-48h]
  int v79; // [esp+50h] [ebp-48h]
  IDXGIAdapter *v80; // [esp+6Ch] [ebp-2Ch] BYREF
  ID3D10Device *v81; // [esp+70h] [ebp-28h] BYREF
  int v82; // [esp+74h] [ebp-24h] BYREF
  int v83; // [esp+78h] [ebp-20h] BYREF
  ID3D10Device1 *v84; // [esp+7Ch] [ebp-1Ch] BYREF
  _DWORD *v85; // [esp+80h] [ebp-18h]
  int v86; // [esp+84h] [ebp-14h] BYREF
  int v87; // [esp+88h] [ebp-10h]
  int v88; // [esp+94h] [ebp-4h]

  v81 = 0;
  v84 = 0;
  v86 = 0;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = (_DWORD *)EngineInstance[2];
  v85 = v3;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  sub_41F640();
  v4 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v5 = v4[88];
  v87 = v5;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)v5 + 32))(v5, 0, 0);
  if ( this )
  {
    this->lpVtbl->AddRef(this);
    v81 = this;
    goto LABEL_61;
  }
  v80 = 0;
  if ( !v3[2] && (*(int (__stdcall **)(int, _DWORD, IDXGIAdapter **))(*(_DWORD *)v5 + 28))(v5, v3[1], &v80) < 0 )
    return -2147219195;
  v6 = v3[19];
  v7 = v3[2];
  v8 = v80;
  if ( sub_4380B0()
    && D3D10CreateDevice1
    && D3D10CreateDevice1(v8, v7, 0, v6, D3D10_FEATURE_LEVEL_10_1, 0x20u, &v84) >= 0 )
  {
    v9 = v84->lpVtbl->QueryInterface(v84, &stru_4B8D2C, (void **)&v81);
  }
  else
  {
    v10 = v3[19];
    v11 = v3[2];
    v12 = v80;
    if ( !sub_4380B0() || !D3D10CreateDevice )
      return -2147219195;
    v9 = D3D10CreateDevice(v12, v11, 0, v10, 0x1Du, &v81);
  }
  v13 = v9;
  if ( v9 < 0 )
    return -2147219195;
  if ( v3[2] )
  {
    v82 = 0;
    v13 = v81->lpVtbl->QueryInterface(v81, &stru_4B8D0C, (void **)&v82);
    if ( v13 < 0 )
      goto LABEL_24;
    if ( v82 )
    {
      (*(void (__stdcall **)(int, IDXGIAdapter **))(*(_DWORD *)v82 + 28))(v82, &v80);
LABEL_24:
      if ( v82 )
        (*(void (__stdcall **)(int))(*(_DWORD *)v82 + 8))(v82);
    }
  }
  v78 = (int)v80;
  v14 = GetEngineInstance();
  sub_419690((int)v14, v78);
  if ( v13 < 0 )
    return -2147219195;
  for ( i = 0; v80->lpVtbl->EnumOutputs(v80, i, (IDXGIOutput **)&v83) >= 0; ++i )
  {
    if ( v83 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v83 + 8))(v83);
      v83 = 0;
    }
  }
  v16 = operator new[](4 * i);
  v17 = v16;
  if ( !v16 )
    return -2147024882;
  v19 = 0;
  if ( i )
  {
    v20 = (IDXGIOutput **)v16;
    do
      v80->lpVtbl->EnumOutputs(v80, v19++, v20++);
    while ( v19 < i );
  }
  if ( (dword_4D8E98 & 1) == 0 )
  {
    dword_4D8E98 |= 1u;
    v88 = 0;
    if ( !dword_4D7F04 )
    {
      v21 = operator new(0x1E80u);
      if ( v21 )
        sub_419430((int)v21);
      else
        v21 = 0;
      dword_4D7F04 = v21;
    }
    atexit(sub_4724C0);
    v88 = -1;
  }
  v22 = dword_4D7F04;
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v23 = byte_4CA649 == 0;
  v22[90] = v17;
  if ( !v23 )
    LeaveCriticalSection(&CriticalSection);
  if ( (dword_4D8E98 & 1) == 0 )
  {
    dword_4D8E98 |= 1u;
    v88 = 1;
    if ( !dword_4D7F04 )
    {
      v24 = operator new(0x1E80u);
      if ( v24 )
        sub_419430((int)v24);
      else
        v24 = 0;
      dword_4D7F04 = v24;
    }
    atexit(sub_4724C0);
    v88 = -1;
  }
  v25 = dword_4D7F04;
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v23 = byte_4CA649 == 0;
  v25[91] = i;
  if ( !v23 )
    LeaveCriticalSection(&CriticalSection);
  if ( (*(int (__stdcall **)(int, ID3D10Device *, _DWORD *, int *))(*(_DWORD *)v87 + 40))(v87, v81, v85 + 4, &v86) < 0 )
    return -2147219195;
LABEL_61:
  if ( (dword_4D8E98 & 1) == 0 )
  {
    dword_4D8E98 |= 1u;
    v88 = 2;
    if ( !dword_4D7F04 )
    {
      v26 = operator new(0x1E80u);
      if ( v26 )
        sub_419430((int)v26);
      else
        v26 = 0;
      dword_4D7F04 = v26;
    }
    atexit(sub_4724C0);
    v88 = -1;
  }
  v27 = v81;
  v28 = dword_4D7F04;
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v23 = byte_4CA649 == 0;
  v28[92] = v27;
  if ( !v23 )
    LeaveCriticalSection(&CriticalSection);
  if ( (dword_4D8E98 & 1) == 0 )
  {
    dword_4D8E98 |= 1u;
    v88 = 3;
    if ( !dword_4D7F04 )
    {
      v29 = operator new(0x1E80u);
      if ( v29 )
        sub_419430((int)v29);
      else
        v29 = 0;
      dword_4D7F04 = v29;
    }
    atexit(sub_4724C0);
    v88 = -1;
  }
  v30 = v84;
  v31 = dword_4D7F04;
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v23 = byte_4CA649 == 0;
  v31[93] = v30;
  if ( !v23 )
    LeaveCriticalSection(&CriticalSection);
  if ( (dword_4D8E98 & 1) == 0 )
  {
    dword_4D8E98 |= 1u;
    v88 = 4;
    if ( !dword_4D7F04 )
    {
      v32 = operator new(0x1E80u);
      if ( v32 )
        sub_419430((int)v32);
      else
        v32 = 0;
      dword_4D7F04 = v32;
    }
    atexit(sub_4724C0);
    v88 = -1;
  }
  v33 = v86;
  v34 = dword_4D7F04;
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v23 = byte_4CA649 == 0;
  v34[94] = v33;
  if ( !v23 )
    LeaveCriticalSection(&CriticalSection);
  v35 = (int)v85;
  if ( v85[2] == 1 )
  {
    v36 = EnterCriticalSection;
    v37 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v38 = v37[192];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( !v38 )
    {
      v39 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v39[192] = 10;
LABEL_113:
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      goto LABEL_115;
    }
  }
  else
  {
    v36 = EnterCriticalSection;
  }
  if ( !*(_DWORD *)(v35 + 8) )
  {
    v40 = GetEngineInstance();
    if ( byte_4CA649 )
      v36(&CriticalSection);
    v41 = v40[192];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v41 == 10 )
    {
      v42 = GetEngineInstance();
      if ( byte_4CA649 )
        v36(&CriticalSection);
      v42[192] = 0;
      goto LABEL_113;
    }
  }
LABEL_115:
  sub_427060();
  sub_427250();
  v43 = sub_42B3D0();
  v44 = v43[15];
  v45 = 0;
  if ( v44 <= 0 )
  {
LABEL_119:
    v47 = 0;
  }
  else
  {
    v46 = (_DWORD *)v43[14];
    while ( 1 )
    {
      v47 = (_DWORD *)*v46;
      if ( *(_DWORD *)*v46 == *(_DWORD *)(v35 + 4) )
        break;
      ++v45;
      ++v46;
      if ( v45 >= v44 )
        goto LABEL_119;
    }
  }
  sub_427CB0(*(_DWORD *)(v35 + 8), (int)(v47 + 1));
  if ( (dword_4D8E98 & 1) == 0 )
  {
    dword_4D8E98 |= 1u;
    v88 = 5;
    if ( !dword_4D7F04 )
    {
      v48 = operator new(0x1E80u);
      if ( v48 )
        sub_419430((int)v48);
      else
        v48 = 0;
      dword_4D7F04 = v48;
    }
    atexit(sub_4724C0);
    v88 = -1;
  }
  v49 = (char *)dword_4D7F04;
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v50 = v49 + 392;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( (dword_4D8E98 & 1) == 0 )
  {
    dword_4D8E98 |= 1u;
    v88 = 6;
    if ( !dword_4D7F04 )
    {
      v51 = operator new(0x1E80u);
      if ( v51 )
        sub_419430((int)v51);
      else
        v51 = 0;
      dword_4D7F04 = v51;
    }
    atexit(sub_4724C0);
    v88 = -1;
  }
  v52 = dword_4D7F04;
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v23 = byte_4CA649 == 0;
  v52[780] = 1;
  if ( !v23 )
    LeaveCriticalSection(&CriticalSection);
  if ( (dword_4D8E98 & 1) == 0 )
  {
    dword_4D8E98 |= 1u;
    v88 = 7;
    if ( !dword_4D7F04 )
    {
      v53 = operator new(0x1E80u);
      if ( v53 )
        sub_419430((int)v53);
      else
        v53 = 0;
      dword_4D7F04 = v53;
    }
    atexit(sub_4724C0);
    v88 = -1;
  }
  v54 = dword_4D7F04;
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v55 = (int (__stdcall *)(int, char *, int))v54[229];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v56 = 0;
  if ( v55 )
  {
    v57 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v58 = v57[247];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v59 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v60 = v59[92];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v56 = v55(v60, v50, v58);
  }
  if ( (dword_4D8E98 & 1) == 0 )
  {
    dword_4D8E98 |= 1u;
    v88 = 8;
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
    v88 = -1;
  }
  v62 = dword_4D7F04;
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v23 = byte_4CA649 == 0;
  v62[780] = 0;
  if ( !v23 )
    LeaveCriticalSection(&CriticalSection);
  if ( (dword_4D8E98 & 1) == 0 )
  {
    dword_4D8E98 |= 1u;
    v88 = 9;
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
    v88 = -1;
  }
  v64 = dword_4D7F04;
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v65 = v64[92];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v65 )
    return -2147467259;
  if ( v56 < 0 )
    return 4 * (v56 != -2147219197) - 2147219197;
  v66 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v23 = byte_4CA649 == 0;
  v66[778] = 1;
  if ( !v23 )
    LeaveCriticalSection(&CriticalSection);
  if ( sub_421720((int *)v81, (int)v85) < 0 )
    return -2147219193;
  v67 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v23 = byte_4CA649 == 0;
  v67[780] = 1;
  if ( !v23 )
    LeaveCriticalSection(&CriticalSection);
  v68 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v69 = (int (__stdcall *)(int, int, char *, int))v68[230];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v70 = 0;
  if ( v69 )
  {
    v71 = GetEngineInstance();
    v79 = sub_41B1E0((int)v71);
    v77 = v86;
    v72 = sub_41B550();
    v70 = v69(v72, v77, v50, v79);
  }
  v73 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v23 = byte_4CA649 == 0;
  v73[780] = 0;
  if ( !v23 )
    LeaveCriticalSection(&CriticalSection);
  v74 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v75 = v74[92];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v75 )
    return -2147467259;
  if ( v70 < 0 )
    return v70 != -2147219197 ? -2147219192 : -2147219197;
  v76 = GetEngineInstance();
  sub_41A5E0((int)v76, 1);
  return 0;
}
