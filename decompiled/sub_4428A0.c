_BYTE *__stdcall sub_4428A0(_BYTE *a1, unsigned __int16 a2)
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
  int v15; // eax
  int v16; // edi
  _DWORD *v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  int v22; // [esp-10h] [ebp-50h]
  int v23; // [esp-8h] [ebp-48h]
  _DWORD v24[5]; // [esp+0h] [ebp-40h] BYREF
  char v25; // [esp+14h] [ebp-2Ch]
  _BYTE v26[4]; // [esp+18h] [ebp-28h] BYREF
  struct std::locale::facet *v27; // [esp+1Ch] [ebp-24h]
  int v28; // [esp+20h] [ebp-20h]
  _BYTE v29[4]; // [esp+24h] [ebp-1Ch] BYREF
  int v30; // [esp+28h] [ebp-18h] BYREF
  int v31; // [esp+2Ch] [ebp-14h]
  _DWORD *v32; // [esp+30h] [ebp-10h]
  int v33; // [esp+3Ch] [ebp-4h]
  int v34; // [esp+4Ch] [ebp+Ch]

  v32 = v24;
  v2 = *(_DWORD *)&a1[*(_DWORD *)(*(_DWORD *)a1 + 4) + 56];
  v31 = 0;
  v24[4] = a1;
  if ( v2 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 4))(v2);
  v33 = 0;
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
  v25 = v6;
  v33 = 1;
  if ( (_BYTE)v6 )
  {
    v7 = sub_44DB70((int)&a1[*(_DWORD *)(v5 + 4)], v6, &v30);
    LOBYTE(v33) = 2;
    v8 = sub_44B280((int)v7);
    LOBYTE(v33) = 1;
    v9 = v30;
    v27 = v8;
    if ( v30 )
    {
      std::_Lockit::_Lockit((std::_Lockit *)v29, 0);
      v10 = *(_DWORD *)(v9 + 4);
      if ( v10 && v10 != -1 )
        *(_DWORD *)(v9 + 4) = v10 - 1;
      v11 = -(*(_DWORD *)(v9 + 4) == 0);
      std::_Lockit::~_Lockit((std::_Lockit *)v29);
      v12 = (void (__thiscall ***)(_DWORD, int))(v9 & v11);
      if ( v12 )
        (**v12)(v12, 1);
    }
    v13 = *(_DWORD *)a1;
    v14 = *(_DWORD *)&a1[*(_DWORD *)(*(_DWORD *)a1 + 4) + 20] & 0xE00;
    if ( v14 == 1024 || v14 == 2048 )
      v34 = a2;
    else
      v34 = (__int16)a2;
    LOBYTE(v33) = 3;
    v15 = *(_DWORD *)(v13 + 4);
    v16 = *(_DWORD *)v27;
    v23 = *(unsigned __int16 *)&a1[v15 + 64];
    v22 = *(_DWORD *)&a1[v15 + 56];
    LOBYTE(v28) = 0;
    (*(void (__thiscall **)(struct std::locale::facet *, _BYTE *, int, int, _BYTE *, int, int))(v16 + 28))(
      v27,
      v26,
      v28,
      v22,
      &a1[v15],
      v23,
      v34);
    if ( v26[0] )
      v31 = 4;
    v33 = 1;
  }
  v17 = &a1[*(_DWORD *)(*(_DWORD *)a1 + 4)];
  if ( v31 )
  {
    v18 = v31 | v17[3];
    if ( !v17[14] )
      LOBYTE(v18) = v18 | 4;
    v19 = v18 & 0x17;
    v17[3] = v19;
    if ( (v19 & v17[4]) != 0 )
      sub_44DDA0(0);
  }
  v33 = 5;
  if ( !__uncaught_exception() )
    sub_44DBA0(a1);
  v33 = -1;
  v20 = *(_DWORD *)&a1[*(_DWORD *)(*(_DWORD *)a1 + 4) + 56];
  if ( v20 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v20 + 8))(v20);
  return a1;
}
