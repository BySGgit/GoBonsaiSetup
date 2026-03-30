_DWORD *__thiscall sub_4458E0(void *this, _DWORD *a2, int a3, int a4, int a5, int a6, int a7, int a8, bool *a9)
{
  int v9; // esi
  int v11; // ebp
  bool v12; // zf
  _DWORD *v13; // eax
  struct std::locale::facet *v14; // eax
  int v15; // edi
  int v16; // ebx
  int v17; // eax
  int v18; // esi
  void (__thiscall ***v19)(_DWORD, int); // esi
  _DWORD *v20; // eax
  _DWORD *v21; // eax
  unsigned int v22; // esi
  void *v23; // ebx
  __int16 *v24; // eax
  _DWORD *v25; // eax
  size_t v26; // eax
  int v27; // eax
  int v28; // edi
  unsigned int v29; // ebx
  int v30; // eax
  int v31; // esi
  void (__thiscall ***v32)(_DWORD, int); // esi
  _DWORD *v33; // eax
  _DWORD *result; // eax
  int v35; // edx
  int v36; // [esp+14h] [ebp-70h] BYREF
  _DWORD *v37; // [esp+18h] [ebp-6Ch]
  int v38; // [esp+1Ch] [ebp-68h] BYREF
  int v39; // [esp+20h] [ebp-64h] BYREF
  bool *v40; // [esp+24h] [ebp-60h]
  int v41; // [esp+28h] [ebp-5Ch] BYREF
  _DWORD *v42; // [esp+2Ch] [ebp-58h]
  char v43[4]; // [esp+30h] [ebp-54h] BYREF
  int v44; // [esp+34h] [ebp-50h] BYREF
  void *v45[5]; // [esp+38h] [ebp-4Ch] BYREF
  unsigned int v46; // [esp+4Ch] [ebp-38h]
  void *v47[5]; // [esp+54h] [ebp-30h] BYREF
  unsigned int v48; // [esp+68h] [ebp-1Ch]
  int v49; // [esp+80h] [ebp-4h]

  v9 = a7;
  v11 = -1;
  v12 = (*(_DWORD *)(a7 + 20) & 0x4000) == 0;
  v42 = a2;
  v37 = (_DWORD *)a8;
  v40 = a9;
  if ( v12 )
  {
    v36 = 0;
    v25 = sub_44DB70(a7, a8, &v41);
    v49 = 4;
    v26 = sub_447780(&a5, (int)v25, (int)this, v47, (int)&a3, *(_DWORD *)(v9 + 20));
    v27 = _Stoulx((int)v47, (int)&v39, v26, (int)&v36);
    v49 = -1;
    v28 = v41;
    v29 = v27;
    if ( v41 )
    {
      std::_Lockit::_Lockit((std::_Lockit *)&v38, 0);
      v30 = *(_DWORD *)(v28 + 4);
      if ( v30 && v30 != -1 )
        *(_DWORD *)(v28 + 4) = v30 - 1;
      v31 = -(*(_DWORD *)(v28 + 4) == 0);
      std::_Lockit::~_Lockit((std::_Lockit *)&v38);
      v32 = (void (__thiscall ***)(_DWORD, int))(v28 & v31);
      if ( v32 )
        (**v32)(v32, 1);
    }
    if ( (void **)v39 != v47 && !v36 && v29 <= 1 )
      v11 = v29;
  }
  else
  {
    v13 = sub_44DB70(a7, a8, &v44);
    v49 = 0;
    v14 = sub_44B520((int)v13);
    v49 = -1;
    v15 = v44;
    v16 = (int)v14;
    if ( v44 )
    {
      std::_Lockit::_Lockit((std::_Lockit *)v43, 0);
      v17 = *(_DWORD *)(v15 + 4);
      if ( v17 && v17 != -1 )
        *(_DWORD *)(v15 + 4) = v17 - 1;
      v18 = -(*(_DWORD *)(v15 + 4) == 0);
      std::_Lockit::~_Lockit((std::_Lockit *)v43);
      v19 = (void (__thiscall ***)(_DWORD, int))(v15 & v18);
      if ( v19 )
        (**v19)(v19, 1);
    }
    sub_4468B0((int)v45);
    v49 = 1;
    v20 = (_DWORD *)sub_448C00(v16, (int)v47);
    LOBYTE(v49) = 2;
    sub_44A460((char *)v45, v20, 0, 0xFFFFFFFF);
    LOBYTE(v49) = 1;
    if ( v48 >= 8 )
      operator delete(v47[0]);
    sub_444B50((int)v45, 0);
    v21 = (_DWORD *)sub_448C20(v16, (int)v47);
    LOBYTE(v49) = 3;
    sub_44A460((char *)v45, v21, 0, 0xFFFFFFFF);
    LOBYTE(v49) = 1;
    if ( v48 >= 8 )
      operator delete(v47[0]);
    v22 = v46;
    v23 = v45[0];
    v24 = (__int16 *)v45[0];
    if ( v46 < 8 )
      v24 = (__int16 *)v45;
    v11 = sub_44B670((int)&a3, v24);
    v49 = -1;
    if ( v22 >= 8 )
      operator delete(v23);
  }
  v12 = (unsigned __int8)sub_44BB00(&a5, &a3) == 0;
  v33 = v37;
  if ( !v12 )
    *v37 |= 1u;
  if ( v11 >= 0 )
    *v40 = v11 != 0;
  else
    *v33 |= 2u;
  result = v42;
  v35 = a4;
  *v42 = a3;
  result[1] = v35;
  return result;
}
