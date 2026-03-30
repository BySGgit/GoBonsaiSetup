_BYTE *__stdcall sub_443270(_BYTE *a1, double a2)
{
  int v2; // ecx
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  _DWORD *v7; // eax
  struct std::locale::facet *v8; // eax
  int v9; // edi
  struct std::locale::facet *v10; // esi
  int v11; // eax
  int v12; // edi
  void (__thiscall ***v13)(_DWORD, int); // edi
  int v14; // eax
  int v15; // edx
  int v16; // ecx
  int v17; // edi
  _DWORD *v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // ecx
  _DWORD v23[6]; // [esp+8h] [ebp-44h] BYREF
  char v24; // [esp+20h] [ebp-2Ch]
  int v25; // [esp+24h] [ebp-28h]
  _BYTE v26[4]; // [esp+28h] [ebp-24h] BYREF
  int v27; // [esp+2Ch] [ebp-20h]
  int v28; // [esp+30h] [ebp-1Ch] BYREF
  int v29; // [esp+34h] [ebp-18h]
  _DWORD *v30; // [esp+3Ch] [ebp-10h]
  int v31; // [esp+48h] [ebp-4h]

  v30 = v23;
  v2 = *(_DWORD *)&a1[*(_DWORD *)(*(_DWORD *)a1 + 4) + 56];
  v29 = 0;
  v23[5] = a1;
  if ( v2 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 4))(v2);
  v31 = 0;
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
  v24 = v6;
  v31 = 1;
  if ( (_BYTE)v6 )
  {
    v7 = sub_44DB70((int)&a1[*(_DWORD *)(v5 + 4)], v6, &v28);
    LOBYTE(v31) = 2;
    v8 = sub_44B280((int)v7);
    LOBYTE(v31) = 1;
    v9 = v28;
    v10 = v8;
    if ( v28 )
    {
      v27 = v28;
      std::_Lockit::_Lockit((std::_Lockit *)v26, 0);
      v11 = *(_DWORD *)(v9 + 4);
      if ( v11 && v11 != -1 )
        *(_DWORD *)(v9 + 4) = v11 - 1;
      v12 = -(*(_DWORD *)(v9 + 4) == 0);
      std::_Lockit::~_Lockit((std::_Lockit *)v26);
      v13 = (void (__thiscall ***)(_DWORD, int))(v27 & v12);
      if ( v13 )
        (**v13)(v13, 1);
    }
    LOBYTE(v31) = 3;
    v14 = *(_DWORD *)(*(_DWORD *)a1 + 4);
    v15 = *(_DWORD *)&a1[v14 + 56];
    v16 = *(unsigned __int16 *)&a1[v14 + 64];
    v17 = *(_DWORD *)v10;
    LOBYTE(v25) = 0;
    (*(void (__thiscall **)(struct std::locale::facet *, double *, int, int, _BYTE *, int, _DWORD, _DWORD))(v17 + 12))(
      v10,
      &a2,
      v25,
      v15,
      &a1[v14],
      v16,
      LODWORD(a2),
      HIDWORD(a2));
    if ( LOBYTE(a2) )
      v29 = 4;
    v31 = 1;
  }
  v18 = &a1[*(_DWORD *)(*(_DWORD *)a1 + 4)];
  if ( v29 )
  {
    v19 = v29 | v18[3];
    if ( !v18[14] )
      LOBYTE(v19) = v19 | 4;
    v20 = v19 & 0x17;
    v18[3] = v20;
    if ( (v20 & v18[4]) != 0 )
      sub_44DDA0(0);
  }
  v31 = 5;
  if ( !__uncaught_exception() )
    sub_44DBA0(a1);
  v31 = -1;
  v21 = *(_DWORD *)&a1[*(_DWORD *)(*(_DWORD *)a1 + 4) + 56];
  if ( v21 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v21 + 8))(v21);
  return a1;
}
