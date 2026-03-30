_BYTE *__stdcall sub_442CA0(_BYTE *a1, int a2)
{
  int v2; // ecx
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  _DWORD *v7; // eax
  struct std::locale::facet *v8; // eax
  int v9; // esi
  int v10; // eax
  int v11; // edi
  void (__thiscall ***v12)(_DWORD, int); // edi
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  int v16; // esi
  _DWORD *v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  _DWORD v22[6]; // [esp+0h] [ebp-40h] BYREF
  char v23; // [esp+18h] [ebp-28h]
  int v24; // [esp+1Ch] [ebp-24h] BYREF
  _BYTE v25[4]; // [esp+20h] [ebp-20h] BYREF
  int v26; // [esp+24h] [ebp-1Ch] BYREF
  int v27; // [esp+28h] [ebp-18h]
  struct std::locale::facet *v28; // [esp+2Ch] [ebp-14h]
  _DWORD *v29; // [esp+30h] [ebp-10h]
  int v30; // [esp+3Ch] [ebp-4h]

  v29 = v22;
  v2 = *(_DWORD *)&a1[*(_DWORD *)(*(_DWORD *)a1 + 4) + 56];
  v27 = 0;
  v22[5] = a1;
  if ( v2 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 4))(v2);
  v30 = 0;
  v3 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  if ( !*(_DWORD *)&a1[v3 + 12] )
  {
    v4 = *(_DWORD *)&a1[v3 + 60];
    if ( v4 )
      sub_44DE80(v4);
  }
  v5 = *(_DWORD *)a1;
  v6 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  LOBYTE(v6) = *(_DWORD *)&a1[v6 + 12] == 0;
  v23 = v6;
  v30 = 1;
  if ( (_BYTE)v6 )
  {
    v7 = sub_44DB70((int)&a1[*(_DWORD *)(v5 + 4)], v6, &v26);
    LOBYTE(v30) = 2;
    v8 = sub_44B280((int)v7);
    LOBYTE(v30) = 1;
    v9 = v26;
    v28 = v8;
    if ( v26 )
    {
      std::_Lockit::_Lockit((std::_Lockit *)v25, 0);
      v10 = *(_DWORD *)(v9 + 4);
      if ( v10 && v10 != -1 )
        *(_DWORD *)(v9 + 4) = v10 - 1;
      v11 = -(*(_DWORD *)(v9 + 4) == 0);
      std::_Lockit::~_Lockit((std::_Lockit *)v25);
      v12 = (void (__thiscall ***)(_DWORD, int))(v9 & v11);
      if ( v12 )
        (**v12)(v12, 1);
    }
    v13 = *(_DWORD *)a1;
    LOBYTE(v30) = 3;
    v14 = *(_DWORD *)(v13 + 4);
    v15 = *(_DWORD *)&a1[v14 + 56];
    v16 = *(_DWORD *)v28;
    LOBYTE(v24) = 0;
    (*(void (__thiscall **)(struct std::locale::facet *, int *, int, int, _BYTE *, _DWORD, int))(v16 + 28))(
      v28,
      &v24,
      v24,
      v15,
      &a1[v14],
      *(unsigned __int16 *)&a1[v14 + 64],
      a2);
    if ( (_BYTE)v24 )
      v27 = 4;
    v30 = 1;
  }
  v17 = &a1[*(_DWORD *)(*(_DWORD *)a1 + 4)];
  if ( v27 )
  {
    v18 = v27 | v17[3];
    if ( !v17[14] )
      LOBYTE(v18) = v18 | 4;
    v19 = v18 & 0x17;
    v17[3] = v19;
    if ( (v19 & v17[4]) != 0 )
      sub_44DDA0(0);
  }
  v30 = 5;
  if ( !__uncaught_exception() )
    sub_44DBA0(a1);
  v30 = -1;
  v20 = *(_DWORD *)&a1[*(_DWORD *)(*(_DWORD *)a1 + 4) + 56];
  if ( v20 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v20 + 8))(v20);
  return a1;
}
