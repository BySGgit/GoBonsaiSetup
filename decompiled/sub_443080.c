_BYTE *__stdcall sub_443080(_BYTE *a1, float a2)
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
  int v16; // edi
  _DWORD *v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  _DWORD v22[6]; // [esp+8h] [ebp-40h] BYREF
  char v23; // [esp+20h] [ebp-28h]
  int v24; // [esp+24h] [ebp-24h] BYREF
  _BYTE v25[4]; // [esp+28h] [ebp-20h] BYREF
  int v26; // [esp+2Ch] [ebp-1Ch]
  int v27; // [esp+30h] [ebp-18h] BYREF
  int v28; // [esp+34h] [ebp-14h]
  _DWORD *v29; // [esp+38h] [ebp-10h]
  int v30; // [esp+44h] [ebp-4h]

  v29 = v22;
  v2 = *(_DWORD *)&a1[*(_DWORD *)(*(_DWORD *)a1 + 4) + 56];
  v28 = 0;
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
    v7 = sub_44DB70((int)&a1[*(_DWORD *)(v5 + 4)], v6, &v27);
    LOBYTE(v30) = 2;
    v8 = sub_44B280((int)v7);
    LOBYTE(v30) = 1;
    v9 = v27;
    v10 = v8;
    if ( v27 )
    {
      v26 = v27;
      std::_Lockit::_Lockit((std::_Lockit *)v25, 0);
      v11 = *(_DWORD *)(v9 + 4);
      if ( v11 && v11 != -1 )
        *(_DWORD *)(v9 + 4) = v11 - 1;
      v12 = -(*(_DWORD *)(v9 + 4) == 0);
      std::_Lockit::~_Lockit((std::_Lockit *)v25);
      v13 = (void (__thiscall ***)(_DWORD, int))(v26 & v12);
      if ( v13 )
        (**v13)(v13, 1);
    }
    LOBYTE(v30) = 3;
    v14 = *(_DWORD *)(*(_DWORD *)a1 + 4);
    v15 = *(_DWORD *)&a1[v14 + 56];
    v16 = *(_DWORD *)v10;
    LOBYTE(v24) = 0;
    (*(void (__thiscall **)(struct std::locale::facet *, int *, int, int, _BYTE *, _DWORD, _DWORD, _DWORD))(v16 + 12))(
      v10,
      &v24,
      v24,
      v15,
      &a1[v14],
      *(unsigned __int16 *)&a1[v14 + 64],
      COERCE_UNSIGNED_INT64(a2),
      HIDWORD(COERCE_UNSIGNED_INT64(a2)));
    if ( (_BYTE)v24 )
      v28 = 4;
    v30 = 1;
  }
  v17 = &a1[*(_DWORD *)(*(_DWORD *)a1 + 4)];
  if ( v28 )
  {
    v18 = v28 | v17[3];
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
