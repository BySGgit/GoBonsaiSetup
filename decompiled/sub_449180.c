int __fastcall sub_449180(int a1, unsigned int *a2, int a3, _BYTE *a4, int a5, int a6)
{
  _DWORD *v6; // eax
  int v7; // edi
  int v8; // eax
  int v9; // esi
  void (__thiscall ***v10)(_DWORD, int); // esi
  const _Cvtvec *v11; // ebx
  __int16 Wchar; // di
  _BYTE *v13; // eax
  __int16 v14; // di
  _WORD *v15; // ebx
  int *v16; // edi
  _BYTE *v17; // ebx
  __int16 v18; // ax
  int *v19; // esi
  _Cvtvec *v20; // ebx
  __int16 v21; // di
  wchar_t v22; // di
  void **v23; // eax
  void **v24; // eax
  int v25; // ebx
  int v26; // ecx
  __int16 **v27; // eax
  __int16 v28; // ax
  int v29; // ecx
  int v30; // edi
  int v31; // edx
  int v32; // eax
  __int16 v33; // ax
  _WORD *v34; // eax
  void **v35; // eax
  void **v36; // eax
  void **v37; // eax
  __int16 v38; // ax
  int v39; // ecx
  int *v40; // edx
  __int16 **v41; // ecx
  __int16 *v42; // eax
  __int16 v43; // ax
  void **v44; // eax
  void **v45; // edx
  char v46; // cl
  void **v47; // eax
  void **v48; // eax
  int v49; // ecx
  __int16 **v50; // eax
  __int16 v51; // ax
  int v52; // ecx
  int v53; // esi
  int Byte; // edx
  int v55; // eax
  int v56; // edi
  int v57; // ecx
  __int16 **v58; // eax
  __int16 v59; // ax
  int v60; // ecx
  int *v61; // eax
  __int16 **v62; // ecx
  __int16 *v63; // eax
  __int16 v64; // ax
  _WORD *v65; // eax
  int *v66; // edi
  int v67; // ecx
  __int16 **v68; // eax
  __int16 v69; // ax
  __int16 v70; // si
  char *decimal_point; // ecx
  _WORD *v72; // eax
  int v73; // ecx
  int *v74; // edx
  __int16 **v75; // ecx
  __int16 *v76; // eax
  __int16 v77; // ax
  char v78; // al
  int v79; // ebx
  int v80; // ecx
  __int16 **v81; // eax
  __int16 v82; // ax
  int v83; // ecx
  int *v84; // edx
  __int16 **v85; // ecx
  __int16 *v86; // eax
  __int16 v87; // ax
  _WORD *v88; // eax
  unsigned __int16 v89; // bx
  unsigned __int16 v90; // si
  int v91; // ecx
  __int16 **v92; // eax
  __int16 v93; // ax
  int v94; // ecx
  int v95; // eax
  int v96; // edx
  int v97; // eax
  char v98; // dl
  _WORD *v99; // eax
  int v100; // ecx
  int *v101; // edx
  __int16 **v102; // ecx
  __int16 *v103; // eax
  __int16 v104; // ax
  int v105; // ecx
  __int16 **v106; // eax
  __int16 v107; // ax
  _Cvtvec *v108; // edi
  __int16 v109; // si
  int v110; // ecx
  __int16 **v111; // eax
  __int16 v112; // ax
  __int16 v113; // si
  _WORD *v114; // eax
  int v115; // ecx
  int *v116; // eax
  __int16 **v117; // ecx
  __int16 *v118; // eax
  __int16 v119; // ax
  int v120; // ebx
  int v121; // ecx
  __int16 **v122; // eax
  __int16 v123; // ax
  _Cvtvec *v124; // edi
  __int16 v125; // si
  _WORD *v126; // eax
  _DWORD *v127; // ecx
  int *v128; // eax
  _WORD **v129; // ecx
  __int16 *v130; // eax
  __int16 v131; // ax
  int v132; // ecx
  __int16 **v133; // eax
  __int16 v134; // ax
  __int16 v135; // si
  _WORD *v136; // eax
  int *v137; // eax
  _WORD **v138; // ecx
  __int16 *v139; // eax
  int v140; // ecx
  __int16 **v141; // eax
  __int16 v142; // ax
  int v143; // ecx
  int *v144; // edx
  __int16 **v145; // ecx
  __int16 *v146; // eax
  __int16 v147; // ax
  _WORD *v148; // eax
  int v149; // ecx
  __int16 **v150; // eax
  __int16 v151; // ax
  int v152; // ecx
  __int16 **v153; // eax
  __int16 v154; // ax
  int v155; // ecx
  __int16 **v156; // eax
  __int16 v157; // ax
  _WORD *v158; // eax
  int v159; // ecx
  int *v160; // edx
  __int16 **v161; // ecx
  __int16 *v162; // eax
  __int16 v163; // ax
  _BYTE *v164; // eax
  bool v165; // cf
  unsigned int *v166; // edx
  char v168[4]; // [esp+18h] [ebp-8Ch] BYREF
  char v169[4]; // [esp+1Ch] [ebp-88h] BYREF
  char v170[4]; // [esp+20h] [ebp-84h] BYREF
  _WORD *v171; // [esp+24h] [ebp-80h]
  mbstate_t v172; // [esp+28h] [ebp-7Ch] BYREF
  wchar_t v173[2]; // [esp+30h] [ebp-74h] BYREF
  mbstate_t v174; // [esp+34h] [ebp-70h] BYREF
  int v175; // [esp+3Ch] [ebp-68h]
  mbstate_t v176; // [esp+40h] [ebp-64h] BYREF
  wchar_t v177[2]; // [esp+48h] [ebp-5Ch] BYREF
  _BYTE *v178; // [esp+4Ch] [ebp-58h]
  _Cvtvec *v179; // [esp+50h] [ebp-54h]
  unsigned int *v180; // [esp+54h] [ebp-50h]
  int v181; // [esp+58h] [ebp-4Ch] BYREF
  void *v182[5]; // [esp+5Ch] [ebp-48h] BYREF
  unsigned int v183; // [esp+70h] [ebp-34h]
  void *v184[5]; // [esp+78h] [ebp-2Ch] BYREF
  unsigned int v185; // [esp+8Ch] [ebp-18h]
  int v186; // [esp+A0h] [ebp-4h]

  v178 = a4;
  *(_DWORD *)&v172._Byte = a1;
  v180 = a2;
  v6 = sub_44DB70(a6, a1, &v181);
  v186 = 0;
  *(_DWORD *)v173 = sub_44B520((int)v6);
  v186 = -1;
  if ( v181 )
  {
    v7 = v181;
    std::_Lockit::_Lockit((std::_Lockit *)&v172, 0);
    v8 = *(_DWORD *)(v7 + 4);
    if ( v8 && v8 != -1 )
      *(_DWORD *)(v7 + 4) = v8 - 1;
    v9 = -(*(_DWORD *)(v7 + 4) == 0);
    std::_Lockit::~_Lockit((std::_Lockit *)&v172);
    v10 = (void (__thiscall ***)(_DWORD, int))(v7 & v9);
    if ( v10 )
      (**v10)(v10, 1);
  }
  sub_44A290(*(int *)v173, (int)v184);
  v11 = (const _Cvtvec *)(a3 + 8);
  v186 = 1;
  v169[0] = 48;
  *(_DWORD *)&v174._Byte = 0;
  v172._Wchar = 0;
  v179 = (_Cvtvec *)(a3 + 8);
  _Mbrtowc(&v174._Byte, v169, 1u, &v172, (const _Cvtvec *)(a3 + 8));
  v169[0] = 97;
  *(_DWORD *)&v176._Byte = 0;
  v172._Wchar = 0;
  _Mbrtowc(&v176._Byte, v169, 1u, &v172, (const _Cvtvec *)(a3 + 8));
  v169[0] = 65;
  *(_DWORD *)v177 = 0;
  v172._Wchar = 0;
  _Mbrtowc(v177, v169, 1u, &v172, (const _Cvtvec *)(a3 + 8));
  v171 = v178;
  v169[0] = 0;
  if ( (unsigned __int8)sub_44BB00(*(int **)&v172._Byte, (int *)a5) )
    goto LABEL_13;
  v172._Wchar = 0;
  v174._Wchar = 0;
  v168[0] = 43;
  _Mbrtowc((wchar_t *)&v172, v168, 1u, &v174, v11);
  Wchar = v172._Wchar;
  if ( sub_44A1D0((int *)a5) == Wchar )
  {
    v13 = v178;
    *v178 = 43;
  }
  else
  {
    v172._Wchar = 0;
    v174._Wchar = 0;
    v168[0] = 45;
    _Mbrtowc((wchar_t *)&v172, v168, 1u, &v174, v11);
    v14 = v172._Wchar;
    if ( sub_44A1D0((int *)a5) != v14 )
      goto LABEL_13;
    v13 = v178;
    *v178 = 45;
  }
  v171 = v13 + 1;
  sub_44A230(a5);
LABEL_13:
  v15 = v171;
  v16 = *(int **)&v172._Byte;
  *v171 = 30768;
  v17 = v15 + 1;
  v171 = v17;
  v168[0] = 0;
  v175 = 0;
  v174._Wchar = 0;
  if ( !(unsigned __int8)sub_44BB00(v16, (int *)a5) )
  {
    v18 = sub_44A1D0((int *)a5);
    if ( v18 == v174._Byte )
    {
      v19 = (int *)sub_44A230(a5);
      if ( !(unsigned __int8)sub_44BB00(v16, v19)
        && ((v20 = v179,
             v172._Wchar = 0,
             v176._Wchar = 0,
             v170[0] = 120,
             _Mbrtowc((wchar_t *)&v172, v170, 1u, &v176, v179),
             v21 = v172._Wchar,
             sub_44A1D0((int *)a5) == v21)
         || (v22 = sub_44CC70(88, v20), sub_44A1D0((int *)a5) == v22)) )
      {
        sub_44A230(a5);
      }
      else
      {
        v168[0] = 1;
      }
      v17 = v171;
    }
  }
  v23 = (void **)v184[0];
  if ( v185 < 0x10 )
    v23 = v184;
  if ( *(_BYTE *)v23 == 127 )
    goto LABEL_373;
  v24 = (void **)v184[0];
  if ( v185 < 0x10 )
    v24 = v184;
  if ( *(char *)v24 <= 0 )
  {
LABEL_373:
    if ( (unsigned __int8)sub_44BB00(*(int **)&v172._Byte, (int *)a5) )
      goto LABEL_154;
    while ( 1 )
    {
      if ( !*(_BYTE *)(a5 + 4) )
      {
        v49 = *(_DWORD *)a5;
        if ( !*(_DWORD *)a5
          || ((v50 = *(__int16 ***)(v49 + 32), !*v50) || **(int **)(v49 + 48) <= 0
            ? (v51 = (*(int (__thiscall **)(int))(*(_DWORD *)v49 + 24))(v49))
            : (v51 = **v50),
              v51 == -1) )
        {
          *(_DWORD *)a5 = 0;
        }
        else
        {
          *(_WORD *)(a5 + 6) = v51;
        }
        *(_BYTE *)(a5 + 4) = 1;
      }
      v52 = *(unsigned __int16 *)(a5 + 6);
      if ( v174._Byte > (unsigned __int16)v52 || v52 > v174._Byte + 9 )
      {
        if ( v176._Byte > (unsigned __int16)v52
          || (Byte = v176._Byte, v55 = *(unsigned __int16 *)(a5 + 6), v52 > v176._Byte + 5) )
        {
          if ( v177[0] > (unsigned __int16)v52
            || (Byte = v177[0], v55 = *(unsigned __int16 *)(a5 + 6), v55 > v177[0] + 5) )
          {
LABEL_153:
            v171 = v17;
            goto LABEL_154;
          }
        }
        v53 = v55 - Byte + 10;
      }
      else
      {
        v53 = v52 - v174._Byte;
      }
      if ( v53 < 0 )
        goto LABEL_153;
      v56 = v175;
      if ( v175 < 36 )
      {
        if ( !*(_BYTE *)(a5 + 4) )
        {
          v57 = *(_DWORD *)a5;
          if ( !*(_DWORD *)a5
            || ((v58 = *(__int16 ***)(v57 + 32), !*v58) || **(int **)(v57 + 48) <= 0
              ? (v59 = (*(int (__thiscall **)(int))(*(_DWORD *)v57 + 24))(v57))
              : (v59 = **v58),
                v59 == -1) )
          {
            *(_DWORD *)a5 = 0;
          }
          else
          {
            *(_WORD *)(a5 + 6) = v59;
          }
          *(_BYTE *)(a5 + 4) = 1;
        }
        if ( *(_WORD *)(a5 + 6) != v174._Byte || v56 )
        {
          *v17++ = byte_4BBF08[v53];
          v175 = v56 + 1;
        }
      }
      else
      {
        ++v174._Wchar;
      }
      v60 = *(_DWORD *)a5;
      v168[0] = 1;
      if ( !v60
        || (!**(_DWORD **)(v60 + 32) || (v61 = *(int **)(v60 + 48), *v61 <= 0)
          ? (v64 = (*(int (__thiscall **)(int))(*(_DWORD *)v60 + 28))(v60))
          : (--*v61, v62 = *(__int16 ***)(v60 + 32), v63 = *v62, ++*v62, v64 = *v63),
            v64 == -1) )
      {
        *(_DWORD *)a5 = 0;
        *(_BYTE *)(a5 + 4) = 1;
      }
      else
      {
        *(_BYTE *)(a5 + 4) = 0;
      }
      if ( (unsigned __int8)sub_44BB00(*(int **)&v172._Byte, (int *)a5) )
      {
        v171 = v17;
        goto LABEL_145;
      }
    }
  }
  if ( v184[4] )
    v172._Wchar = (*(unsigned __int16 (__thiscall **)(_DWORD))(**(_DWORD **)v173 + 8))(*(_DWORD *)v173);
  else
    v172._Wchar = 0;
  v183 = 15;
  v182[4] = (void *)1;
  LOWORD(v182[0]) = 0;
  LOBYTE(v186) = 2;
  v25 = 0;
  if ( (unsigned __int8)sub_44BB00(*(int **)&v172._Byte, (int *)a5) )
    goto LABEL_82;
  do
  {
    if ( !*(_BYTE *)(a5 + 4) )
    {
      v26 = *(_DWORD *)a5;
      if ( !*(_DWORD *)a5
        || ((v27 = *(__int16 ***)(v26 + 32), !*v27) || **(int **)(v26 + 48) <= 0
          ? (v28 = (*(int (__thiscall **)(int))(*(_DWORD *)v26 + 24))(v26))
          : (v28 = **v27),
            v28 == -1) )
      {
        *(_DWORD *)a5 = 0;
      }
      else
      {
        *(_WORD *)(a5 + 6) = v28;
      }
      *(_BYTE *)(a5 + 4) = 1;
    }
    v29 = *(unsigned __int16 *)(a5 + 6);
    if ( v174._Byte > (unsigned __int16)v29 || v29 > v174._Byte + 9 )
    {
      if ( v176._Byte > (unsigned __int16)v29
        || (v31 = v176._Byte, v32 = *(unsigned __int16 *)(a5 + 6), v29 > v176._Byte + 5) )
      {
        if ( v177[0] > (unsigned __int16)v29 )
          goto LABEL_61;
        v31 = v177[0];
        v32 = *(unsigned __int16 *)(a5 + 6);
        if ( v32 > v177[0] + 5 )
          goto LABEL_61;
      }
      v30 = v32 - v31 + 10;
    }
    else
    {
      v30 = v29 - v174._Byte;
    }
    if ( v30 >= 0 )
    {
      v168[0] = 1;
      if ( v175 < 36 )
      {
        v33 = sub_44A1D0((int *)a5);
        if ( v33 != v174._Byte || v175 )
        {
          v34 = v171;
          *(_BYTE *)v171 = byte_4BBF08[v30];
          ++v175;
          v171 = (_WORD *)((char *)v34 + 1);
        }
      }
      else
      {
        ++v174._Wchar;
      }
      v35 = (void **)v182[0];
      if ( v183 < 0x10 )
        v35 = v182;
      if ( *((_BYTE *)v35 + v25) != 127 )
      {
        v36 = (void **)v182[0];
        if ( v183 < 0x10 )
          v36 = v182;
        ++*((_BYTE *)v36 + v25);
      }
      goto LABEL_67;
    }
LABEL_61:
    v37 = (void **)v182[0];
    if ( v183 < 0x10 )
      v37 = v182;
    if ( !*((_BYTE *)v37 + v25) )
      break;
    if ( !LOWORD(v172._Wchar) )
      break;
    v38 = sub_44A1D0((int *)a5);
    if ( v38 != LOWORD(v172._Wchar) )
      break;
    sub_448EB0(v182, 1u, 0);
    ++v25;
LABEL_67:
    v39 = *(_DWORD *)a5;
    if ( !*(_DWORD *)a5
      || (!**(_DWORD **)(v39 + 32) || (v40 = *(int **)(v39 + 48), *v40 <= 0)
        ? (v43 = (*(int (__thiscall **)(int))(*(_DWORD *)v39 + 28))(v39))
        : (--*v40, v41 = *(__int16 ***)(v39 + 32), v42 = *v41, ++*v41, v43 = *v42),
          v43 == -1) )
    {
      *(_DWORD *)a5 = 0;
      *(_BYTE *)(a5 + 4) = 1;
    }
    else
    {
      *(_BYTE *)(a5 + 4) = 0;
    }
  }
  while ( !(unsigned __int8)sub_44BB00(*(int **)&v172._Byte, (int *)a5) );
  if ( v25 )
  {
    v44 = (void **)v182[0];
    if ( v183 < 0x10 )
      v44 = v182;
    if ( *((char *)v44 + v25) <= 0 )
      v169[0] = 1;
    else
      ++v25;
  }
LABEL_82:
  v45 = (void **)v184[0];
  if ( v185 < 0x10 )
    v45 = v184;
  if ( !v169[0] )
  {
    while ( v25 )
    {
      v46 = *(_BYTE *)v45;
      if ( *(_BYTE *)v45 == 127 )
        break;
      if ( --v25 )
      {
        v47 = (void **)v182[0];
        if ( v183 < 0x10 )
          v47 = v182;
        if ( v46 != *((_BYTE *)v47 + v25) )
          goto LABEL_97;
      }
      if ( !v25 )
      {
        v48 = (void **)v182[0];
        if ( v183 < 0x10 )
          v48 = v182;
        if ( v46 < *(char *)v48 )
        {
LABEL_97:
          v169[0] = 1;
          break;
        }
      }
      if ( *((char *)v45 + 1) > 0 )
        v45 = (void **)((char *)v45 + 1);
    }
  }
  LOBYTE(v186) = 1;
  if ( v183 >= 0x10 )
    operator delete(v182[0]);
LABEL_154:
  if ( v168[0] )
  {
LABEL_145:
    if ( !v175 )
    {
      v65 = v171;
      *(_BYTE *)v171 = 48;
      v171 = (_WORD *)((char *)v65 + 1);
    }
  }
  v66 = *(int **)&v172._Byte;
  if ( !(unsigned __int8)sub_44BB00(*(int **)&v172._Byte, (int *)a5) )
  {
    if ( !*(_BYTE *)(a5 + 4) )
    {
      v67 = *(_DWORD *)a5;
      if ( !*(_DWORD *)a5
        || ((v68 = *(__int16 ***)(v67 + 32), !*v68) || **(int **)(v67 + 48) <= 0
          ? (v69 = (*(int (__thiscall **)(int))(*(_DWORD *)v67 + 24))(v67))
          : (v69 = **v68),
            v69 == -1) )
      {
        *(_DWORD *)a5 = 0;
      }
      else
      {
        *(_WORD *)(a5 + 6) = v69;
      }
      *(_BYTE *)(a5 + 4) = 1;
    }
    v70 = *(_WORD *)(a5 + 6);
    if ( v70 == (*(unsigned __int16 (**)(void))(**(_DWORD **)v173 + 4))() )
    {
      decimal_point = localeconv()->decimal_point;
      v72 = v171;
      *(_BYTE *)v171 = *decimal_point;
      v73 = *(_DWORD *)a5;
      v171 = (_WORD *)((char *)v72 + 1);
      if ( !v73
        || (!**(_DWORD **)(v73 + 32) || (v74 = *(int **)(v73 + 48), *v74 <= 0)
          ? (v77 = (*(int (__thiscall **)(int))(*(_DWORD *)v73 + 28))(v73))
          : (--*v74, v75 = *(__int16 ***)(v73 + 32), v76 = *v75, ++*v75, v77 = *v76),
            v77 == -1) )
      {
        *(_DWORD *)a5 = 0;
        *(_BYTE *)(a5 + 4) = 1;
      }
      else
      {
        *(_BYTE *)(a5 + 4) = 0;
      }
    }
  }
  if ( !v175 )
  {
    v78 = sub_44BB00(v66, (int *)a5);
    v79 = v174._Wchar;
    if ( !v78 )
    {
      do
      {
        if ( !*(_BYTE *)(a5 + 4) )
        {
          v80 = *(_DWORD *)a5;
          if ( !*(_DWORD *)a5
            || ((v81 = *(__int16 ***)(v80 + 32), !*v81) || **(int **)(v80 + 48) <= 0
              ? (v82 = (*(int (__thiscall **)(int))(*(_DWORD *)v80 + 24))(v80))
              : (v82 = **v81),
                v82 == -1) )
          {
            *(_DWORD *)a5 = 0;
          }
          else
          {
            *(_WORD *)(a5 + 6) = v82;
          }
          *(_BYTE *)(a5 + 4) = 1;
        }
        if ( *(_WORD *)(a5 + 6) != v174._Byte )
          break;
        v83 = *(_DWORD *)a5;
        --v79;
        v168[0] = 1;
        if ( !v83
          || (!**(_DWORD **)(v83 + 32) || (v84 = *(int **)(v83 + 48), *v84 <= 0)
            ? (v87 = (*(int (__thiscall **)(int))(*(_DWORD *)v83 + 28))(v83))
            : (--*v84, v85 = *(__int16 ***)(v83 + 32), v86 = *v85, ++*v85, v87 = *v86),
              v87 == -1) )
        {
          *(_DWORD *)a5 = 0;
          *(_BYTE *)(a5 + 4) = 1;
        }
        else
        {
          *(_BYTE *)(a5 + 4) = 0;
        }
      }
      while ( !(unsigned __int8)sub_44BB00(v66, (int *)a5) );
      v174._Wchar = v79;
    }
    if ( v79 < 0 )
    {
      v88 = v171;
      *(_BYTE *)v171 = 48;
      v171 = (_WORD *)((char *)v88 + 1);
      v174._Wchar = v79 + 1;
    }
  }
  if ( (unsigned __int8)sub_44BB00(v66, (int *)a5) )
  {
LABEL_228:
    if ( v168[0] )
    {
      v66 = *(int **)&v172._Byte;
      goto LABEL_230;
    }
  }
  else
  {
    v89 = v174._Byte;
    do
    {
      v90 = v176._Byte;
      if ( !*(_BYTE *)(a5 + 4) )
      {
        v91 = *(_DWORD *)a5;
        if ( !*(_DWORD *)a5
          || ((v92 = *(__int16 ***)(v91 + 32), !*v92) || **(int **)(v91 + 48) <= 0
            ? (v93 = (*(int (__thiscall **)(int))(*(_DWORD *)v91 + 24))(v91))
            : (v93 = **v92),
              v93 == -1) )
        {
          *(_DWORD *)a5 = 0;
        }
        else
        {
          *(_WORD *)(a5 + 6) = v93;
        }
        *(_BYTE *)(a5 + 4) = 1;
      }
      v94 = *(unsigned __int16 *)(a5 + 6);
      if ( v89 > (unsigned __int16)v94 || (v66 = *(int **)&v172._Byte, v94 > v89 + 9) )
      {
        if ( v90 > (unsigned __int16)v94 || (v96 = v90, v97 = *(unsigned __int16 *)(a5 + 6), v94 > v90 + 5) )
        {
          if ( v177[0] > (unsigned __int16)v94 )
            goto LABEL_228;
          v96 = v177[0];
          v97 = *(unsigned __int16 *)(a5 + 6);
          if ( v97 > v177[0] + 5 )
            goto LABEL_228;
        }
        v95 = v97 - v96 + 10;
      }
      else
      {
        v95 = v94 - v89;
      }
      if ( v95 < 0 )
        goto LABEL_228;
      if ( v175 < 36 )
      {
        v98 = byte_4BBF08[v95];
        v99 = v171;
        *(_BYTE *)v171 = v98;
        ++v175;
        v171 = (_WORD *)((char *)v99 + 1);
      }
      v100 = *(_DWORD *)a5;
      v168[0] = 1;
      if ( !v100
        || (!**(_DWORD **)(v100 + 32) || (v101 = *(int **)(v100 + 48), *v101 <= 0)
          ? (v104 = (*(int (__thiscall **)(int))(*(_DWORD *)v100 + 28))(v100))
          : (--*v101, v102 = *(__int16 ***)(v100 + 32), v103 = *v102, ++*v102, v104 = *v103),
            v104 == -1) )
      {
        *(_DWORD *)a5 = 0;
        *(_BYTE *)(a5 + 4) = 1;
      }
      else
      {
        *(_BYTE *)(a5 + 4) = 0;
      }
    }
    while ( !(unsigned __int8)sub_44BB00(v66, (int *)a5) );
LABEL_230:
    if ( !(unsigned __int8)sub_44BB00(v66, (int *)a5) )
    {
      if ( !*(_BYTE *)(a5 + 4) )
      {
        v105 = *(_DWORD *)a5;
        if ( !*(_DWORD *)a5
          || ((v106 = *(__int16 ***)(v105 + 32), !*v106) || **(int **)(v105 + 48) <= 0
            ? (v107 = (*(int (__thiscall **)(int))(*(_DWORD *)v105 + 24))(v105))
            : (v107 = **v106),
              v107 == -1) )
        {
          *(_DWORD *)a5 = 0;
        }
        else
        {
          *(_WORD *)(a5 + 6) = v107;
        }
        *(_BYTE *)(a5 + 4) = 1;
      }
      v108 = v179;
      v109 = *(_WORD *)(a5 + 6);
      v170[0] = 112;
      *(_DWORD *)v173 = 0;
      v176._Wchar = 0;
      _Mbrtowc(v173, v170, 1u, &v176, v179);
      if ( v109 == v173[0] )
        goto LABEL_253;
      if ( !*(_BYTE *)(a5 + 4) )
      {
        v110 = *(_DWORD *)a5;
        if ( !*(_DWORD *)a5
          || ((v111 = *(__int16 ***)(v110 + 32), !*v111) || **(int **)(v110 + 48) <= 0
            ? (v112 = (*(int (__thiscall **)(int))(*(_DWORD *)v110 + 24))(v110))
            : (v112 = **v111),
              v112 == -1) )
        {
          *(_DWORD *)a5 = 0;
        }
        else
        {
          *(_WORD *)(a5 + 6) = v112;
        }
        *(_BYTE *)(a5 + 4) = 1;
      }
      v113 = *(_WORD *)(a5 + 6);
      v170[0] = 80;
      *(_DWORD *)v173 = 0;
      v176._Wchar = 0;
      _Mbrtowc(v173, v170, 1u, &v176, v108);
      if ( v113 == v173[0] )
      {
LABEL_253:
        v114 = v171;
        *(_BYTE *)v171 = 112;
        v115 = *(_DWORD *)a5;
        v171 = (_WORD *)((char *)v114 + 1);
        if ( !v115
          || (!**(_DWORD **)(v115 + 32) || (v116 = *(int **)(v115 + 48), *v116 <= 0)
            ? (v119 = (*(int (__thiscall **)(int))(*(_DWORD *)v115 + 28))(v115))
            : (--*v116, v117 = *(__int16 ***)(v115 + 32), v118 = *v117, ++*v117, v119 = *v118),
              v119 == -1) )
        {
          *(_DWORD *)a5 = 0;
          *(_BYTE *)(a5 + 4) = 1;
        }
        else
        {
          *(_BYTE *)(a5 + 4) = 0;
        }
        v168[0] = 0;
        v120 = 0;
        if ( !(unsigned __int8)sub_44BB00(*(int **)&v172._Byte, (int *)a5) )
        {
          if ( !*(_BYTE *)(a5 + 4) )
          {
            v121 = *(_DWORD *)a5;
            if ( !*(_DWORD *)a5
              || ((v122 = *(__int16 ***)(v121 + 32), !*v122) || **(int **)(v121 + 48) <= 0
                ? (v123 = (*(int (__thiscall **)(int))(*(_DWORD *)v121 + 24))(v121))
                : (v123 = **v122),
                  v123 == -1) )
            {
              *(_DWORD *)a5 = 0;
            }
            else
            {
              *(_WORD *)(a5 + 6) = v123;
            }
            *(_BYTE *)(a5 + 4) = 1;
          }
          v124 = v179;
          v125 = *(_WORD *)(a5 + 6);
          *(_DWORD *)v173 = 0;
          v176._Wchar = 0;
          v170[0] = 43;
          _Mbrtowc(v173, v170, 1u, &v176, v179);
          if ( v125 == v173[0] )
          {
            v126 = v171;
            *(_BYTE *)v171 = 43;
            v127 = *(_DWORD **)a5;
            v171 = (_WORD *)((char *)v126 + 1);
            if ( v127 )
            {
              if ( *(_DWORD *)v127[8] )
              {
                v128 = (int *)v127[12];
                if ( *v128 > 0 )
                {
                  --*v128;
                  v129 = (_WORD **)v127[8];
                  v130 = (*v129)++;
                  v131 = *v130;
                  goto LABEL_293;
                }
              }
LABEL_292:
              v131 = (*(int (__thiscall **)(_DWORD *))(*v127 + 28))(v127);
              goto LABEL_293;
            }
            goto LABEL_295;
          }
          if ( !*(_BYTE *)(a5 + 4) )
          {
            v132 = *(_DWORD *)a5;
            if ( !*(_DWORD *)a5
              || ((v133 = *(__int16 ***)(v132 + 32), !*v133) || **(int **)(v132 + 48) <= 0
                ? (v134 = (*(int (__thiscall **)(int))(*(_DWORD *)v132 + 24))(v132))
                : (v134 = **v133),
                  v134 == -1) )
            {
              *(_DWORD *)a5 = 0;
            }
            else
            {
              *(_WORD *)(a5 + 6) = v134;
            }
            *(_BYTE *)(a5 + 4) = 1;
          }
          v135 = *(_WORD *)(a5 + 6);
          *(_DWORD *)v173 = 0;
          v176._Wchar = 0;
          v170[0] = 45;
          _Mbrtowc(v173, v170, 1u, &v176, v124);
          if ( v135 == v173[0] )
          {
            v136 = v171;
            *(_BYTE *)v171 = 45;
            v127 = *(_DWORD **)a5;
            v171 = (_WORD *)((char *)v136 + 1);
            if ( !v127 )
              goto LABEL_295;
            if ( !*(_DWORD *)v127[8] )
              goto LABEL_292;
            v137 = (int *)v127[12];
            if ( *v137 <= 0 )
              goto LABEL_292;
            --*v137;
            v138 = (_WORD **)v127[8];
            v139 = (*v138)++;
            v131 = *v139;
LABEL_293:
            if ( v131 == -1 )
            {
LABEL_295:
              *(_BYTE *)(a5 + 4) = 1;
              *(_DWORD *)a5 = 0;
            }
            else
            {
              *(_BYTE *)(a5 + 4) = 0;
            }
          }
        }
        if ( !(unsigned __int8)sub_44BB00(*(int **)&v172._Byte, (int *)a5) )
        {
          while ( 1 )
          {
            if ( !*(_BYTE *)(a5 + 4) )
            {
              v140 = *(_DWORD *)a5;
              if ( !*(_DWORD *)a5
                || ((v141 = *(__int16 ***)(v140 + 32), !*v141) || **(int **)(v140 + 48) <= 0
                  ? (v142 = (*(int (__thiscall **)(int))(*(_DWORD *)v140 + 24))(v140))
                  : (v142 = **v141),
                    v142 == -1) )
              {
                *(_DWORD *)a5 = 0;
              }
              else
              {
                *(_WORD *)(a5 + 6) = v142;
              }
              *(_BYTE *)(a5 + 4) = 1;
            }
            if ( *(_WORD *)(a5 + 6) != v174._Byte )
              break;
            v143 = *(_DWORD *)a5;
            v168[0] = 1;
            if ( !v143
              || (!**(_DWORD **)(v143 + 32) || (v144 = *(int **)(v143 + 48), *v144 <= 0)
                ? (v147 = (*(int (__thiscall **)(int))(*(_DWORD *)v143 + 28))(v143))
                : (--*v144, v145 = *(__int16 ***)(v143 + 32), v146 = *v145, ++*v145, v147 = *v146),
                  v147 == -1) )
            {
              *(_DWORD *)a5 = 0;
              *(_BYTE *)(a5 + 4) = 1;
            }
            else
            {
              *(_BYTE *)(a5 + 4) = 0;
            }
            if ( (unsigned __int8)sub_44BB00(*(int **)&v172._Byte, (int *)a5) )
              goto LABEL_319;
          }
          if ( !v168[0] )
            goto LABEL_320;
LABEL_319:
          v148 = v171;
          *(_BYTE *)v171 = 48;
          v171 = (_WORD *)((char *)v148 + 1);
        }
LABEL_320:
        while ( !(unsigned __int8)sub_44BB00(*(int **)&v172._Byte, (int *)a5) )
        {
          if ( !*(_BYTE *)(a5 + 4) )
          {
            v149 = *(_DWORD *)a5;
            if ( !*(_DWORD *)a5
              || ((v150 = *(__int16 ***)(v149 + 32), !*v150) || **(int **)(v149 + 48) <= 0
                ? (v151 = (*(int (__thiscall **)(int))(*(_DWORD *)v149 + 24))(v149))
                : (v151 = **v150),
                  v151 == -1) )
            {
              *(_DWORD *)a5 = 0;
            }
            else
            {
              *(_WORD *)(a5 + 6) = v151;
            }
            *(_BYTE *)(a5 + 4) = 1;
          }
          if ( v174._Byte > *(_WORD *)(a5 + 6) )
            break;
          if ( !*(_BYTE *)(a5 + 4) )
          {
            v152 = *(_DWORD *)a5;
            if ( !*(_DWORD *)a5
              || ((v153 = *(__int16 ***)(v152 + 32), !*v153) || **(int **)(v152 + 48) <= 0
                ? (v154 = (*(int (__thiscall **)(int))(*(_DWORD *)v152 + 24))(v152))
                : (v154 = **v153),
                  v154 == -1) )
            {
              *(_DWORD *)a5 = 0;
            }
            else
            {
              *(_WORD *)(a5 + 6) = v154;
            }
            *(_BYTE *)(a5 + 4) = 1;
          }
          if ( *(unsigned __int16 *)(a5 + 6) > v174._Byte + 9 )
            break;
          if ( v120 < 8 )
          {
            if ( !*(_BYTE *)(a5 + 4) )
            {
              v155 = *(_DWORD *)a5;
              if ( !*(_DWORD *)a5
                || ((v156 = *(__int16 ***)(v155 + 32), !*v156) || **(int **)(v155 + 48) <= 0
                  ? (v157 = (*(int (__thiscall **)(int))(*(_DWORD *)v155 + 24))(v155))
                  : (v157 = **v156),
                    v157 == -1) )
              {
                *(_DWORD *)a5 = 0;
              }
              else
              {
                *(_WORD *)(a5 + 6) = v157;
              }
              *(_BYTE *)(a5 + 4) = 1;
            }
            v158 = v171;
            *(_BYTE *)v171 = *(_BYTE *)(a5 + 6) - LOBYTE(v174._Byte) + 48;
            v171 = (_WORD *)((char *)v158 + 1);
            ++v120;
          }
          v159 = *(_DWORD *)a5;
          v168[0] = 1;
          if ( !v159
            || (!**(_DWORD **)(v159 + 32) || (v160 = *(int **)(v159 + 48), *v160 <= 0)
              ? (v163 = (*(int (__thiscall **)(int))(*(_DWORD *)v159 + 28))(v159))
              : (--*v160, v161 = *(__int16 ***)(v159 + 32), v162 = *v161, ++*v161, v163 = *v162),
                v163 == -1) )
          {
            *(_DWORD *)a5 = 0;
            *(_BYTE *)(a5 + 4) = 1;
          }
          else
          {
            *(_BYTE *)(a5 + 4) = 0;
          }
        }
      }
    }
  }
  if ( !v169[0] && v168[0] )
    v164 = v171;
  else
    v164 = v178;
  v165 = v185 < 0x10;
  v166 = v180;
  *v164 = 0;
  *v166 = v174._Wchar;
  if ( !v165 )
    operator delete(v184[0]);
  return 0;
}
