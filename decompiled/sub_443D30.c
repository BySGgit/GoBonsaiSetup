int *__stdcall sub_443D30(int *a1, int a2)
{
  int v2; // ecx
  _DWORD *v3; // eax
  struct std::locale::facet *v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // edi
  void (__thiscall ***v8)(_DWORD, int); // edi
  int v9; // eax
  int v10; // ecx
  _DWORD *v11; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // ecx
  int v16; // [esp+0h] [ebp-48h] BYREF
  _BYTE v17[4]; // [esp+14h] [ebp-34h] BYREF
  int v18; // [esp+18h] [ebp-30h]
  int *v19; // [esp+1Ch] [ebp-2Ch]
  char v20; // [esp+20h] [ebp-28h]
  int v21; // [esp+28h] [ebp-20h] BYREF
  int v22; // [esp+2Ch] [ebp-1Ch] BYREF
  int v23; // [esp+30h] [ebp-18h] BYREF
  struct std::locale::facet *v24; // [esp+34h] [ebp-14h]
  int *v25; // [esp+38h] [ebp-10h]
  int v26; // [esp+44h] [ebp-4h]

  v25 = &v16;
  v23 = 0;
  v2 = *(int *)((char *)a1 + *(_DWORD *)(*a1 + 4) + 56);
  v19 = a1;
  if ( v2 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 4))(v2);
  v26 = 0;
  v20 = sub_44D8E0((int)a1);
  v26 = 1;
  if ( v20 )
  {
    v3 = sub_44DB70((int)a1 + *(_DWORD *)(*a1 + 4), *a1, &v22);
    LOBYTE(v26) = 2;
    v4 = sub_44B3D0((int)v3);
    LOBYTE(v26) = 1;
    v5 = v22;
    v24 = v4;
    if ( v22 )
    {
      std::_Lockit::_Lockit((std::_Lockit *)&v21, 0);
      v6 = *(_DWORD *)(v5 + 4);
      if ( v6 && v6 != -1 )
        *(_DWORD *)(v5 + 4) = v6 - 1;
      v7 = -(*(_DWORD *)(v5 + 4) == 0);
      std::_Lockit::~_Lockit((std::_Lockit *)&v21);
      v8 = (void (__thiscall ***)(_DWORD, int))(v5 & v7);
      if ( v8 )
        (**v8)(v8, 1);
    }
    LOBYTE(v26) = 3;
    v9 = *(_DWORD *)(*a1 + 4);
    v10 = *(int *)((char *)a1 + v9 + 56);
    LOBYTE(v21) = 1;
    LOBYTE(v18) = v10 == 0;
    (*(void (__thiscall **)(struct std::locale::facet *, _BYTE *, int, int, _DWORD, int, int, int *, int))(*(_DWORD *)v24 + 16))(
      v24,
      v17,
      v10,
      v18,
      0,
      v21,
      (int)a1 + v9,
      &v23,
      a2);
    v26 = 1;
  }
  v11 = (int *)((char *)a1 + *(_DWORD *)(*a1 + 4));
  if ( v23 )
  {
    v12 = v23 | v11[3];
    if ( !v11[14] )
      LOBYTE(v12) = v12 | 4;
    v13 = v12 & 0x17;
    v11[3] = v13;
    if ( (v13 & v11[4]) != 0 )
      sub_44DDA0(0);
  }
  v26 = -1;
  v14 = *(int *)((char *)a1 + *(_DWORD *)(*a1 + 4) + 56);
  if ( v14 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 8))(v14);
  return a1;
}
