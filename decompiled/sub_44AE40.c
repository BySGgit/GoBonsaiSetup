_BYTE *__cdecl sub_44AE40(_BYTE *a1, const char *a2)
{
  __int64 v2; // rdi
  int v3; // edx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  _DWORD *v13; // edi
  struct std::locale::facet *v14; // eax
  int v15; // edi
  int v16; // eax
  int v17; // esi
  void (__thiscall ***v18)(_DWORD, int); // esi
  int v19; // eax
  _DWORD *v20; // ecx
  int v21; // edx
  int *v22; // eax
  _WORD **v23; // ecx
  _WORD *v24; // eax
  __int16 v25; // ax
  unsigned __int16 (__thiscall *v26)(struct std::locale::facet *, int); // edx
  int v27; // edx
  _DWORD *v28; // ecx
  int *v29; // eax
  _WORD **v30; // ecx
  _WORD *v31; // eax
  __int16 v32; // ax
  unsigned int i; // esi
  int v34; // eax
  _DWORD *v35; // ecx
  int v36; // edx
  int *v37; // eax
  _WORD **v38; // ecx
  _WORD *v39; // eax
  __int16 v40; // ax
  int v41; // eax
  int v42; // et0
  _DWORD *v43; // ecx
  int v44; // eax
  int v45; // eax
  bool v46; // al
  _BYTE *v47; // esi
  int v48; // ecx
  int v50; // [esp+0h] [ebp-50h] BYREF
  _BYTE *v51; // [esp+10h] [ebp-40h]
  char v52; // [esp+14h] [ebp-3Ch]
  unsigned int v53; // [esp+18h] [ebp-38h]
  int v54; // [esp+1Ch] [ebp-34h]
  __int64 v55; // [esp+20h] [ebp-30h]
  int v56; // [esp+2Ch] [ebp-24h]
  struct std::locale::facet *v57; // [esp+30h] [ebp-20h]
  _BYTE v58[4]; // [esp+34h] [ebp-1Ch] BYREF
  int v59; // [esp+38h] [ebp-18h] BYREF
  int v60; // [esp+3Ch] [ebp-14h]
  int *v61; // [esp+40h] [ebp-10h]
  int v62; // [esp+4Ch] [ebp-4h]

  v61 = &v50;
  v60 = 0;
  v2 = strlen(a2);
  v3 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  v4 = *(_DWORD *)&a1[v3 + 36];
  v5 = *(_DWORD *)&a1[v3 + 32];
  v53 = v2;
  v54 = 0;
  if ( __SPAIR64__(v4, v5) <= 0 || __SPAIR64__(v4, v5) <= (unsigned int)v2 )
  {
    v6 = 0;
    HIDWORD(v55) = 0;
  }
  else
  {
    v7 = (__PAIR64__(v4, v5) - v2) >> 32;
    v6 = v5 - v2;
    HIDWORD(v55) = v7;
  }
  v8 = *(_DWORD *)&a1[v3 + 56];
  LODWORD(v55) = v6;
  v51 = a1;
  if ( v8 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(v8);
  v62 = 0;
  v9 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  if ( !*(_DWORD *)&a1[v9 + 12] )
  {
    v10 = *(_DWORD *)&a1[v9 + 60];
    if ( v10 )
    {
      sub_44DE80(v10);
      HIDWORD(v2) = v54;
    }
  }
  v11 = *(_DWORD *)a1;
  v12 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  LOBYTE(v12) = *(_DWORD *)&a1[v12 + 12] == 0;
  v52 = v12;
  v62 = 1;
  if ( (_BYTE)v12 )
  {
    v13 = sub_44DB70((int)&a1[*(_DWORD *)(v11 + 4)], v12, &v59);
    LOBYTE(v62) = 3;
    v14 = sub_44D670((int)v13);
    LOBYTE(v62) = 2;
    v15 = v59;
    v57 = v14;
    if ( v59 )
    {
      std::_Lockit::_Lockit((std::_Lockit *)v58, 0);
      v16 = *(_DWORD *)(v15 + 4);
      if ( v16 && v16 != -1 )
        *(_DWORD *)(v15 + 4) = v16 - 1;
      v17 = -(*(_DWORD *)(v15 + 4) == 0);
      std::_Lockit::~_Lockit((std::_Lockit *)v58);
      v18 = (void (__thiscall ***)(_DWORD, int))(v15 & v17);
      if ( v18 )
        (**v18)(v18, 1);
      HIDWORD(v2) = v54;
    }
    if ( (*(_DWORD *)&a1[*(_DWORD *)(*(_DWORD *)a1 + 4) + 20] & 0x1C0) != 0x40 )
    {
      while ( 1 )
      {
        if ( v55 <= 0 )
          goto LABEL_27;
        v19 = *(_DWORD *)(*(_DWORD *)a1 + 4);
        v20 = *(_DWORD **)&a1[v19 + 56];
        v21 = *(unsigned __int16 *)&a1[v19 + 64];
        if ( *(_DWORD *)v20[9] && (v22 = (int *)v20[13], *v22 > 0) )
        {
          --*v22;
          v23 = (_WORD **)v20[9];
          v24 = (*v23)++;
          *v24 = v21;
          v25 = v21;
        }
        else
        {
          v25 = (*(int (__thiscall **)(_DWORD *, int))(*v20 + 12))(v20, v21);
        }
        if ( v25 == -1 )
          break;
        --v55;
      }
      v60 |= 4u;
    }
LABEL_27:
    while ( !v60 )
    {
      if ( v2 < 0 || SHIDWORD(v2) <= 0 && !v53 )
      {
        for ( i = v55; v55 >= 0 && (SHIDWORD(v55) > 0 || i); --i )
        {
          v34 = *(_DWORD *)(*(_DWORD *)a1 + 4);
          v35 = *(_DWORD **)&a1[v34 + 56];
          v36 = *(unsigned __int16 *)&a1[v34 + 64];
          if ( *(_DWORD *)v35[9] && (v37 = (int *)v35[13], *v37 > 0) )
          {
            --*v37;
            v38 = (_WORD **)v35[9];
            v39 = (*v38)++;
            *v39 = v36;
            v40 = v36;
          }
          else
          {
            v40 = (*(int (__thiscall **)(_DWORD *, int))(*v35 + 12))(v35, v36);
          }
          if ( v40 == -1 )
          {
            v60 |= 4u;
            goto LABEL_49;
          }
          v42 = (__PAIR64__(HIDWORD(v55), i) - 1) >> 32;
          HIDWORD(v55) = v42;
        }
        break;
      }
      v26 = *(unsigned __int16 (__thiscall **)(struct std::locale::facet *, int))(*(_DWORD *)v57 + 40);
      LOBYTE(v56) = *a2;
      v27 = v26(v57, v56);
      v28 = *(_DWORD **)&a1[*(_DWORD *)(*(_DWORD *)a1 + 4) + 56];
      if ( *(_DWORD *)v28[9] && (v29 = (int *)v28[13], *v29 > 0) )
      {
        --*v29;
        v30 = (_WORD **)v28[9];
        v31 = (*v30)++;
        *v31 = v27;
        v32 = v27;
      }
      else
      {
        v32 = (*(int (__thiscall **)(_DWORD *, int))(*v28 + 12))(v28, v27);
      }
      if ( v32 == -1 )
        v60 = 4;
      HIDWORD(v2) = (__PAIR64__(HIDWORD(v2), v53--) - 1) >> 32;
      ++a2;
    }
LABEL_49:
    v41 = *(_DWORD *)(*(_DWORD *)a1 + 4);
    *(_DWORD *)&a1[v41 + 32] = 0;
    *(_DWORD *)&a1[v41 + 36] = 0;
    v62 = 1;
  }
  else
  {
    v60 = 4;
  }
  v43 = &a1[*(_DWORD *)(*(_DWORD *)a1 + 4)];
  if ( v60 )
  {
    v44 = v60 | v43[3];
    if ( !v43[14] )
      LOBYTE(v44) = v44 | 4;
    v45 = v44 & 0x17;
    v43[3] = v45;
    if ( (v45 & v43[4]) != 0 )
      sub_44DDA0(0);
  }
  v62 = 5;
  v46 = __uncaught_exception();
  v47 = v51;
  if ( !v46 )
    sub_44DBA0(v51);
  v62 = -1;
  v48 = *(_DWORD *)&v47[*(_DWORD *)(*(_DWORD *)v47 + 4) + 56];
  if ( v48 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v48 + 8))(v48);
  return a1;
}
