_BYTE *__stdcall sub_442AB0(_BYTE *a1, unsigned __int16 a2)
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
  int v13; // eax
  int v14; // edx
  int v15; // esi
  _DWORD *v16; // ecx
  int v17; // eax
  int v18; // eax
  int v19; // ecx
  _DWORD v21[6]; // [esp+0h] [ebp-40h] BYREF
  char v22; // [esp+18h] [ebp-28h]
  int v23; // [esp+1Ch] [ebp-24h] BYREF
  _BYTE v24[4]; // [esp+20h] [ebp-20h] BYREF
  int v25; // [esp+24h] [ebp-1Ch] BYREF
  int v26; // [esp+28h] [ebp-18h]
  struct std::locale::facet *v27; // [esp+2Ch] [ebp-14h]
  _DWORD *v28; // [esp+30h] [ebp-10h]
  int v29; // [esp+3Ch] [ebp-4h]

  v28 = v21;
  v2 = *(_DWORD *)&a1[*(_DWORD *)(*(_DWORD *)a1 + 4) + 56];
  v26 = 0;
  v21[5] = a1;
  if ( v2 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 4))(v2);
  v29 = 0;
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
  v22 = v6;
  v29 = 1;
  if ( (_BYTE)v6 )
  {
    v7 = sub_44DB70((int)&a1[*(_DWORD *)(v5 + 4)], v6, &v25);
    LOBYTE(v29) = 2;
    v8 = sub_44B280((int)v7);
    LOBYTE(v29) = 1;
    v9 = v25;
    v27 = v8;
    if ( v25 )
    {
      std::_Lockit::_Lockit((std::_Lockit *)v24, 0);
      v10 = *(_DWORD *)(v9 + 4);
      if ( v10 && v10 != -1 )
        *(_DWORD *)(v9 + 4) = v10 - 1;
      v11 = -(*(_DWORD *)(v9 + 4) == 0);
      std::_Lockit::~_Lockit((std::_Lockit *)v24);
      v12 = (void (__thiscall ***)(_DWORD, int))(v9 & v11);
      if ( v12 )
        (**v12)(v12, 1);
    }
    LOBYTE(v29) = 3;
    v13 = *(_DWORD *)(*(_DWORD *)a1 + 4);
    v14 = *(_DWORD *)&a1[v13 + 56];
    v15 = *(_DWORD *)v27;
    LOBYTE(v23) = 0;
    (*(void (__thiscall **)(struct std::locale::facet *, int *, int, int, _BYTE *, _DWORD, _DWORD))(v15 + 24))(
      v27,
      &v23,
      v23,
      v14,
      &a1[v13],
      *(unsigned __int16 *)&a1[v13 + 64],
      a2);
    if ( (_BYTE)v23 )
      v26 = 4;
    v29 = 1;
  }
  v16 = &a1[*(_DWORD *)(*(_DWORD *)a1 + 4)];
  if ( v26 )
  {
    v17 = v26 | v16[3];
    if ( !v16[14] )
      LOBYTE(v17) = v17 | 4;
    v18 = v17 & 0x17;
    v16[3] = v18;
    if ( (v18 & v16[4]) != 0 )
      sub_44DDA0(0);
  }
  v29 = 5;
  if ( !__uncaught_exception() )
    sub_44DBA0(a1);
  v29 = -1;
  v19 = *(_DWORD *)&a1[*(_DWORD *)(*(_DWORD *)a1 + 4) + 56];
  if ( v19 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v19 + 8))(v19);
  return a1;
}
