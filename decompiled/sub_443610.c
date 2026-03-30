int __stdcall sub_443610(int a1, _WORD *a2)
{
  int v2; // ecx
  int v3; // ecx
  _DWORD *v4; // eax
  struct std::locale::facet *v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // edi
  void (__thiscall ***v9)(_DWORD, int); // edi
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  _DWORD *v13; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  int v18; // [esp+0h] [ebp-48h] BYREF
  _BYTE v19[4]; // [esp+10h] [ebp-38h] BYREF
  int v20; // [esp+14h] [ebp-34h]
  int v21; // [esp+18h] [ebp-30h]
  char v22; // [esp+1Ch] [ebp-2Ch]
  int v23; // [esp+24h] [ebp-24h] BYREF
  int v24; // [esp+28h] [ebp-20h] BYREF
  int v25; // [esp+2Ch] [ebp-1Ch] BYREF
  struct std::locale::facet *v26; // [esp+30h] [ebp-18h]
  _DWORD v27[2]; // [esp+34h] [ebp-14h] BYREF
  int v28; // [esp+44h] [ebp-4h]

  v27[1] = &v18;
  v27[0] = 0;
  v2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1 + 56);
  v21 = a1;
  if ( v2 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 4))(v2);
  v28 = 0;
  v22 = sub_44D8E0(a1);
  v28 = 1;
  if ( v22 )
  {
    v3 = *(_DWORD *)a1;
    v25 = 0;
    v4 = sub_44DB70(a1 + *(_DWORD *)(v3 + 4), v3, &v24);
    LOBYTE(v28) = 2;
    v5 = sub_44B3D0((int)v4);
    LOBYTE(v28) = 1;
    v6 = v24;
    v26 = v5;
    if ( v24 )
    {
      std::_Lockit::_Lockit((std::_Lockit *)&v23, 0);
      v7 = *(_DWORD *)(v6 + 4);
      if ( v7 && v7 != -1 )
        *(_DWORD *)(v6 + 4) = v7 - 1;
      v8 = -(*(_DWORD *)(v6 + 4) == 0);
      std::_Lockit::~_Lockit((std::_Lockit *)&v23);
      v9 = (void (__thiscall ***)(_DWORD, int))(v6 & v8);
      if ( v9 )
        (**v9)(v9, 1);
    }
    LOBYTE(v28) = 3;
    v10 = *(_DWORD *)(*(_DWORD *)a1 + 4);
    v11 = *(_DWORD *)(v10 + a1 + 56);
    LOBYTE(v23) = 1;
    LOBYTE(v20) = v11 == 0;
    (*(void (__thiscall **)(struct std::locale::facet *, _BYTE *, int, int, _DWORD, int, int, _DWORD *, int *))(*(_DWORD *)v26 + 32))(
      v26,
      v19,
      v11,
      v20,
      0,
      v23,
      a1 + v10,
      v27,
      &v25);
    v28 = 1;
    v12 = v27[0];
    if ( (v27[0] & 2) != 0 || (unsigned int)(v25 + 0x8000) > 0xFFFF )
    {
      v12 = v27[0] | 2;
      v27[0] |= 2u;
    }
    else
    {
      *a2 = v25;
    }
  }
  else
  {
    v12 = v27[0];
  }
  v13 = (_DWORD *)(a1 + *(_DWORD *)(*(_DWORD *)a1 + 4));
  if ( v12 )
  {
    v14 = v12 | v13[3];
    if ( !v13[14] )
      LOBYTE(v14) = v14 | 4;
    v15 = v14 & 0x17;
    v13[3] = v15;
    if ( (v15 & v13[4]) != 0 )
      sub_44DDA0(0);
  }
  v28 = -1;
  v16 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1 + 56);
  if ( v16 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v16 + 8))(v16);
  return a1;
}
