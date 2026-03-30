int __fastcall sub_447D10(_BYTE *a1, unsigned int *a2, int a3, int a4, int a5, int a6)
{
  int v7; // ecx
  _DWORD *v9; // eax
  struct std::locale::facet *v10; // eax
  unsigned int Wchar; // edi
  int v12; // eax
  int v13; // esi
  void (__thiscall ***v14)(_DWORD, int); // esi
  const _Cvtvec *v15; // ebx
  wchar_t v16; // di
  int v17; // eax
  wchar_t v18; // di
  void **v19; // eax
  void **v20; // eax
  int v21; // ebx
  int v22; // ecx
  __int16 **v23; // eax
  __int16 v24; // ax
  unsigned __int16 v25; // ax
  signed int v26; // edi
  __int16 v27; // ax
  char v28; // al
  char v29; // cl
  char *v30; // eax
  void **v31; // eax
  void **v32; // eax
  void **v33; // eax
  __int16 v34; // di
  void **v35; // eax
  void **v36; // edx
  char v37; // cl
  void **v38; // eax
  void **v39; // eax
  int *v40; // edi
  char *v41; // eax
  int v42; // ecx
  __int16 **v43; // eax
  __int16 v44; // ax
  int v45; // ebx
  int v46; // ecx
  __int16 **v47; // eax
  __int16 v48; // ax
  int v49; // ecx
  __int16 **v50; // eax
  __int16 v51; // ax
  __int16 v52; // ax
  char v53; // al
  char v54; // cl
  char *v55; // eax
  __int16 v56; // si
  char *decimal_point; // ecx
  char *v58; // eax
  int v59; // ecx
  int *v60; // edx
  __int16 **v61; // ecx
  __int16 *v62; // eax
  __int16 v63; // ax
  char v64; // al
  int v65; // ebx
  int v66; // ecx
  __int16 **v67; // eax
  __int16 v68; // ax
  int v69; // ecx
  int *v70; // edx
  __int16 **v71; // ecx
  __int16 *v72; // eax
  __int16 v73; // ax
  char *v74; // eax
  int v75; // ecx
  __int16 **v76; // eax
  __int16 v77; // ax
  wchar_t v78; // bx
  int v79; // ecx
  __int16 **v80; // eax
  __int16 v81; // ax
  int v82; // ecx
  __int16 **v83; // eax
  __int16 v84; // ax
  char *v85; // eax
  int v86; // ecx
  int *v87; // edx
  __int16 **v88; // ecx
  __int16 *v89; // eax
  __int16 v90; // ax
  int v91; // ecx
  __int16 **v92; // eax
  __int16 v93; // ax
  const _Cvtvec *v94; // ebx
  __int16 v95; // si
  int v96; // ecx
  __int16 **v97; // eax
  __int16 v98; // ax
  __int16 v99; // si
  char *v100; // eax
  int v101; // ecx
  int *v102; // eax
  __int16 **v103; // ecx
  __int16 *v104; // eax
  __int16 v105; // ax
  int v106; // ecx
  __int16 **v107; // eax
  __int16 v108; // ax
  __int16 v109; // si
  char *v110; // eax
  _DWORD *v111; // ecx
  int *v112; // eax
  _WORD **v113; // ecx
  __int16 *v114; // eax
  __int16 v115; // ax
  int v116; // ecx
  __int16 **v117; // eax
  __int16 v118; // ax
  __int16 v119; // si
  char *v120; // eax
  int *v121; // eax
  _WORD **v122; // ecx
  __int16 *v123; // eax
  int *v124; // edi
  int v125; // ecx
  __int16 **v126; // eax
  __int16 v127; // ax
  wchar_t v128; // bx
  int v129; // ecx
  int *v130; // eax
  __int16 **v131; // ecx
  __int16 *v132; // eax
  __int16 v133; // ax
  char *v134; // eax
  char *v135; // eax
  int v136; // ecx
  __int16 **v137; // eax
  __int16 v138; // ax
  int v139; // ecx
  __int16 **v140; // eax
  __int16 v141; // ax
  int v142; // ecx
  __int16 **v143; // eax
  __int16 v144; // ax
  char *v145; // eax
  int v146; // ecx
  int *v147; // edx
  __int16 **v148; // ecx
  __int16 *v149; // eax
  __int16 v150; // ax
  char *v151; // eax
  bool v152; // cf
  char v153[4]; // [esp+18h] [ebp-7Ch] BYREF
  char v154[4]; // [esp+1Ch] [ebp-78h] BYREF
  char v155[4]; // [esp+20h] [ebp-74h] BYREF
  char *v156; // [esp+24h] [ebp-70h]
  wchar_t v157[2]; // [esp+28h] [ebp-6Ch] BYREF
  wchar_t v158[2]; // [esp+2Ch] [ebp-68h] BYREF
  signed int v159; // [esp+30h] [ebp-64h]
  mbstate_t v160; // [esp+34h] [ebp-60h] BYREF
  mbstate_t v161; // [esp+3Ch] [ebp-58h] BYREF
  mbstate_t v162; // [esp+44h] [ebp-50h] BYREF
  void *v163[5]; // [esp+4Ch] [ebp-48h] BYREF
  unsigned int v164; // [esp+60h] [ebp-34h]
  void *v165[5]; // [esp+68h] [ebp-2Ch] BYREF
  unsigned int v166; // [esp+7Ch] [ebp-18h]
  int v167; // [esp+90h] [ebp-4h]

  v7 = *(_DWORD *)(a6 + 20) & 0x3000;
  *(_DWORD *)&v162._Byte = a1;
  *(_DWORD *)&v161._Byte = a5;
  if ( v7 == 12288 )
    return sub_449180(a5, a2, a3, a1, a4, a6);
  v9 = sub_44DB70(a6, v7, &v162);
  v167 = 0;
  v10 = sub_44B520((int)v9);
  v167 = -1;
  Wchar = v162._Wchar;
  v161._Wchar = (unsigned int)v10;
  if ( v162._Wchar )
  {
    std::_Lockit::_Lockit((std::_Lockit *)&v160, 0);
    v12 = *(_DWORD *)(Wchar + 4);
    if ( v12 && v12 != -1 )
      *(_DWORD *)(Wchar + 4) = v12 - 1;
    v13 = -(*(_DWORD *)(Wchar + 4) == 0);
    std::_Lockit::~_Lockit((std::_Lockit *)&v160);
    v14 = (void (__thiscall ***)(_DWORD, int))(Wchar & v13);
    if ( v14 )
      (**v14)(v14, 1);
  }
  sub_44A290(v161._Wchar, (int)v165);
  v167 = 1;
  v15 = (const _Cvtvec *)(a3 + 8);
  *(_DWORD *)v158 = 0;
  v160._Wchar = 0;
  v155[0] = 48;
  *(_DWORD *)&v160._Byte = a3 + 8;
  _Mbrtowc(v158, v155, 1u, &v160, (const _Cvtvec *)(a3 + 8));
  v156 = *(char **)&v162._Byte;
  v155[0] = 0;
  if ( !(unsigned __int8)sub_44BB00(*(int **)&v161._Byte, (int *)a4) )
  {
    *(_DWORD *)v157 = 0;
    v160._Wchar = 0;
    v153[0] = 43;
    _Mbrtowc(v157, v153, 1u, &v160, v15);
    v16 = v157[0];
    if ( sub_44A1D0((int *)a4) == v16 )
    {
      v17 = *(_DWORD *)&v162._Byte;
      **(_BYTE **)&v162._Byte = 43;
    }
    else
    {
      *(_DWORD *)v157 = 0;
      v160._Wchar = 0;
      v153[0] = 45;
      _Mbrtowc(v157, v153, 1u, &v160, v15);
      v18 = v157[0];
      if ( sub_44A1D0((int *)a4) != v18 )
        goto LABEL_15;
      v17 = *(_DWORD *)&v162._Byte;
      **(_BYTE **)&v162._Byte = 45;
    }
    v156 = (char *)(v17 + 1);
    sub_44A230(a4);
  }
LABEL_15:
  v153[0] = 0;
  v159 = 0;
  *(_DWORD *)v157 = 0;
  v19 = (void **)v165[0];
  if ( v166 < 0x10 )
    v19 = v165;
  if ( *(_BYTE *)v19 != 127 )
  {
    v20 = (void **)v165[0];
    if ( v166 < 0x10 )
      v20 = v165;
    if ( *(char *)v20 > 0 )
    {
      if ( v165[4] )
        v160._Wchar = (*(unsigned __int16 (__thiscall **)(unsigned int))(*(_DWORD *)v161._Wchar + 8))(v161._Wchar);
      else
        v160._Wchar = 0;
      v164 = 15;
      v163[4] = (void *)1;
      LOWORD(v163[0]) = 0;
      LOBYTE(v167) = 2;
      v21 = 0;
      if ( (unsigned __int8)sub_44BB00(*(int **)&v161._Byte, (int *)a4) )
        goto LABEL_61;
      while ( 1 )
      {
        if ( !*(_BYTE *)(a4 + 4) )
        {
          v22 = *(_DWORD *)a4;
          if ( !*(_DWORD *)a4
            || ((v23 = *(__int16 ***)(v22 + 32), !*v23) || **(int **)(v22 + 48) <= 0
              ? (v24 = (*(int (__thiscall **)(int))(*(_DWORD *)v22 + 24))(v22))
              : (v24 = **v23),
                v24 == -1) )
          {
            *(_DWORD *)a4 = 0;
          }
          else
          {
            *(_WORD *)(a4 + 6) = v24;
          }
          *(_BYTE *)(a4 + 4) = 1;
        }
        if ( v158[0] > *(_WORD *)(a4 + 6) || (v25 = sub_44A1D0((int *)a4), v25 > v158[0] + 9) )
        {
          v33 = (void **)v163[0];
          if ( v164 < 0x10 )
            v33 = v163;
          if ( !*((_BYTE *)v33 + v21) || (v34 = v160._Wchar) == 0 || sub_44A1D0((int *)a4) != v34 )
          {
LABEL_55:
            if ( v21 )
            {
              v35 = (void **)v163[0];
              if ( v164 < 0x10 )
                v35 = v163;
              if ( *((char *)v35 + v21) <= 0 )
                v155[0] = 1;
              else
                ++v21;
            }
LABEL_61:
            v36 = (void **)v165[0];
            if ( v166 < 0x10 )
              v36 = v165;
            if ( !v155[0] )
            {
              while ( v21 )
              {
                v37 = *(_BYTE *)v36;
                if ( *(_BYTE *)v36 == 127 )
                  break;
                if ( --v21 )
                {
                  v38 = (void **)v163[0];
                  if ( v164 < 0x10 )
                    v38 = v163;
                  if ( v37 != *((_BYTE *)v38 + v21) )
                    goto LABEL_76;
                }
                if ( !v21 )
                {
                  v39 = (void **)v163[0];
                  if ( v164 < 0x10 )
                    v39 = v163;
                  if ( v37 < *(char *)v39 )
                  {
LABEL_76:
                    v155[0] = 1;
                    break;
                  }
                }
                if ( *((char *)v36 + 1) > 0 )
                  v36 = (void **)((char *)v36 + 1);
              }
            }
            LOBYTE(v167) = 1;
            if ( v164 >= 0x10 )
              operator delete(v163[0]);
            v40 = *(int **)&v161._Byte;
LABEL_80:
            if ( v153[0] )
              goto LABEL_81;
            goto LABEL_83;
          }
          sub_448EB0(v163, 1u, 0);
          ++v21;
        }
        else
        {
          v26 = v159;
          v153[0] = 1;
          if ( v159 < 36 )
          {
            v27 = sub_44A1D0((int *)a4);
            if ( v27 != v158[0] || v26 )
            {
              v28 = sub_44A1D0((int *)a4);
              v29 = 48 - LOBYTE(v158[0]) + v28;
              v30 = v156;
              *v156 = v29;
              ++v159;
              v156 = v30 + 1;
            }
          }
          else
          {
            ++*(_DWORD *)v157;
          }
          v31 = (void **)v163[0];
          if ( v164 < 0x10 )
            v31 = v163;
          if ( *((_BYTE *)v31 + v21) != 127 )
          {
            v32 = (void **)v163[0];
            if ( v164 < 0x10 )
              v32 = v163;
            ++*((_BYTE *)v32 + v21);
          }
        }
        sub_44A230(a4);
        if ( (unsigned __int8)sub_44BB00(*(int **)&v161._Byte, (int *)a4) )
          goto LABEL_55;
      }
    }
  }
  v40 = *(int **)&v161._Byte;
  if ( !(unsigned __int8)sub_44BB00(*(int **)&v161._Byte, (int *)a4) )
  {
    v45 = v159;
    do
    {
      if ( !*(_BYTE *)(a4 + 4) )
      {
        v46 = *(_DWORD *)a4;
        if ( !*(_DWORD *)a4
          || ((v47 = *(__int16 ***)(v46 + 32), !*v47) || **(int **)(v46 + 48) <= 0
            ? (v48 = (*(int (__thiscall **)(int))(*(_DWORD *)v46 + 24))(v46))
            : (v48 = **v47),
              v48 == -1) )
        {
          *(_DWORD *)a4 = 0;
        }
        else
        {
          *(_WORD *)(a4 + 6) = v48;
        }
        *(_BYTE *)(a4 + 4) = 1;
      }
      if ( v158[0] > *(_WORD *)(a4 + 6) )
        goto LABEL_120;
      if ( !*(_BYTE *)(a4 + 4) )
      {
        v49 = *(_DWORD *)a4;
        if ( !*(_DWORD *)a4
          || ((v50 = *(__int16 ***)(v49 + 32), !*v50) || **(int **)(v49 + 48) <= 0
            ? (v51 = (*(int (__thiscall **)(int))(*(_DWORD *)v49 + 24))(v49))
            : (v51 = **v50),
              v51 == -1) )
        {
          *(_DWORD *)a4 = 0;
        }
        else
        {
          *(_WORD *)(a4 + 6) = v51;
        }
        *(_BYTE *)(a4 + 4) = 1;
      }
      if ( *(unsigned __int16 *)(a4 + 6) > v158[0] + 9 )
      {
LABEL_120:
        v159 = v45;
        goto LABEL_80;
      }
      if ( v45 < 36 )
      {
        v52 = sub_44A1D0((int *)a4);
        if ( v52 != v158[0] || v45 )
        {
          v53 = sub_44A1D0((int *)a4);
          v54 = 48 - LOBYTE(v158[0]) + v53;
          v55 = v156;
          *v156 = v54;
          v156 = v55 + 1;
          ++v45;
        }
      }
      else
      {
        ++*(_DWORD *)v157;
      }
      v153[0] = 1;
      sub_44A230(a4);
    }
    while ( !(unsigned __int8)sub_44BB00(v40, (int *)a4) );
    v159 = v45;
LABEL_81:
    if ( !v159 )
    {
      v41 = v156;
      *v156 = 48;
      v156 = v41 + 1;
    }
  }
LABEL_83:
  if ( !(unsigned __int8)sub_44BB00(v40, (int *)a4) )
  {
    if ( !*(_BYTE *)(a4 + 4) )
    {
      v42 = *(_DWORD *)a4;
      if ( !*(_DWORD *)a4
        || ((v43 = *(__int16 ***)(v42 + 32), !*v43) || **(int **)(v42 + 48) <= 0
          ? (v44 = (*(int (__thiscall **)(int))(*(_DWORD *)v42 + 24))(v42))
          : (v44 = **v43),
            v44 == -1) )
      {
        *(_DWORD *)a4 = 0;
      }
      else
      {
        *(_WORD *)(a4 + 6) = v44;
      }
      *(_BYTE *)(a4 + 4) = 1;
    }
    v56 = *(_WORD *)(a4 + 6);
    if ( v56 == (*(unsigned __int16 (**)(void))(*(_DWORD *)v161._Wchar + 4))() )
    {
      decimal_point = localeconv()->decimal_point;
      v58 = v156;
      *v156 = *decimal_point;
      v59 = *(_DWORD *)a4;
      v156 = v58 + 1;
      if ( !v59
        || (!**(_DWORD **)(v59 + 32) || (v60 = *(int **)(v59 + 48), *v60 <= 0)
          ? (v63 = (*(int (__thiscall **)(int))(*(_DWORD *)v59 + 28))(v59))
          : (--*v60, v61 = *(__int16 ***)(v59 + 32), v62 = *v61, ++*v61, v63 = *v62),
            v63 == -1) )
      {
        *(_DWORD *)a4 = 0;
        *(_BYTE *)(a4 + 4) = 1;
      }
      else
      {
        *(_BYTE *)(a4 + 4) = 0;
      }
    }
  }
  if ( !v159 )
  {
    v64 = sub_44BB00(v40, (int *)a4);
    v65 = *(_DWORD *)v157;
    if ( !v64 )
    {
      do
      {
        if ( !*(_BYTE *)(a4 + 4) )
        {
          v66 = *(_DWORD *)a4;
          if ( !*(_DWORD *)a4
            || ((v67 = *(__int16 ***)(v66 + 32), !*v67) || **(int **)(v66 + 48) <= 0
              ? (v68 = (*(int (__thiscall **)(int))(*(_DWORD *)v66 + 24))(v66))
              : (v68 = **v67),
                v68 == -1) )
          {
            *(_DWORD *)a4 = 0;
          }
          else
          {
            *(_WORD *)(a4 + 6) = v68;
          }
          *(_BYTE *)(a4 + 4) = 1;
        }
        if ( *(_WORD *)(a4 + 6) != v158[0] )
          break;
        v69 = *(_DWORD *)a4;
        --v65;
        v153[0] = 1;
        if ( !v69
          || (!**(_DWORD **)(v69 + 32) || (v70 = *(int **)(v69 + 48), *v70 <= 0)
            ? (v73 = (*(int (__thiscall **)(int))(*(_DWORD *)v69 + 28))(v69))
            : (--*v70, v71 = *(__int16 ***)(v69 + 32), v72 = *v71, ++*v71, v73 = *v72),
              v73 == -1) )
        {
          *(_DWORD *)a4 = 0;
          *(_BYTE *)(a4 + 4) = 1;
        }
        else
        {
          *(_BYTE *)(a4 + 4) = 0;
        }
      }
      while ( !(unsigned __int8)sub_44BB00(v40, (int *)a4) );
      *(_DWORD *)v157 = v65;
    }
    if ( v65 < 0 )
    {
      v74 = v156;
      *v156 = 48;
      v156 = v74 + 1;
      *(_DWORD *)v157 = v65 + 1;
    }
  }
  if ( !(unsigned __int8)sub_44BB00(v40, (int *)a4) )
  {
    v161._Wchar = v159;
    while ( 1 )
    {
      if ( !*(_BYTE *)(a4 + 4) )
      {
        v75 = *(_DWORD *)a4;
        if ( !*(_DWORD *)a4
          || ((v76 = *(__int16 ***)(v75 + 32), !*v76) || **(int **)(v75 + 48) <= 0
            ? (v77 = (*(int (__thiscall **)(int))(*(_DWORD *)v75 + 24))(v75))
            : (v77 = **v76),
              v77 == -1) )
        {
          *(_DWORD *)a4 = 0;
        }
        else
        {
          *(_WORD *)(a4 + 6) = v77;
        }
        *(_BYTE *)(a4 + 4) = 1;
      }
      v78 = v158[0];
      if ( v158[0] > *(_WORD *)(a4 + 6) )
        break;
      if ( !*(_BYTE *)(a4 + 4) )
      {
        v79 = *(_DWORD *)a4;
        if ( !*(_DWORD *)a4
          || ((v80 = *(__int16 ***)(v79 + 32), !*v80) || **(int **)(v79 + 48) <= 0
            ? (v81 = (*(int (__thiscall **)(int))(*(_DWORD *)v79 + 24))(v79))
            : (v81 = **v80),
              v81 == -1) )
        {
          *(_DWORD *)a4 = 0;
        }
        else
        {
          *(_WORD *)(a4 + 6) = v81;
        }
        *(_BYTE *)(a4 + 4) = 1;
      }
      if ( *(unsigned __int16 *)(a4 + 6) > v78 + 9 )
        break;
      if ( (int)v161._Wchar < 36 )
      {
        if ( !*(_BYTE *)(a4 + 4) )
        {
          v82 = *(_DWORD *)a4;
          if ( !*(_DWORD *)a4
            || ((v83 = *(__int16 ***)(v82 + 32), !*v83) || **(int **)(v82 + 48) <= 0
              ? (v84 = (*(int (__thiscall **)(int))(*(_DWORD *)v82 + 24))(v82))
              : (v84 = **v83),
                v84 == -1) )
          {
            *(_DWORD *)a4 = 0;
          }
          else
          {
            *(_WORD *)(a4 + 6) = v84;
          }
          *(_BYTE *)(a4 + 4) = 1;
        }
        v85 = v156;
        *v156 = *(_BYTE *)(a4 + 6) - v78 + 48;
        ++v161._Wchar;
        v156 = v85 + 1;
      }
      v86 = *(_DWORD *)a4;
      v153[0] = 1;
      if ( !v86
        || (!**(_DWORD **)(v86 + 32) || (v87 = *(int **)(v86 + 48), *v87 <= 0)
          ? (v90 = (*(int (__thiscall **)(int))(*(_DWORD *)v86 + 28))(v86))
          : (--*v87, v88 = *(__int16 ***)(v86 + 32), v89 = *v88, ++*v88, v90 = *v89),
            v90 == -1) )
      {
        *(_DWORD *)a4 = 0;
        *(_BYTE *)(a4 + 4) = 1;
      }
      else
      {
        *(_BYTE *)(a4 + 4) = 0;
      }
      if ( (unsigned __int8)sub_44BB00(v40, (int *)a4) )
        goto LABEL_207;
    }
  }
  if ( !v153[0] )
    goto LABEL_342;
LABEL_207:
  if ( !(unsigned __int8)sub_44BB00(v40, (int *)a4) )
  {
    if ( !*(_BYTE *)(a4 + 4) )
    {
      v91 = *(_DWORD *)a4;
      if ( !*(_DWORD *)a4
        || ((v92 = *(__int16 ***)(v91 + 32), !*v92) || **(int **)(v91 + 48) <= 0
          ? (v93 = (*(int (__thiscall **)(int))(*(_DWORD *)v91 + 24))(v91))
          : (v93 = **v92),
            v93 == -1) )
      {
        *(_DWORD *)a4 = 0;
      }
      else
      {
        *(_WORD *)(a4 + 6) = v93;
      }
      *(_BYTE *)(a4 + 4) = 1;
    }
    v94 = *(const _Cvtvec **)&v160._Byte;
    v95 = *(_WORD *)(a4 + 6);
    v154[0] = 101;
    v160._Wchar = 0;
    v162._Wchar = 0;
    _Mbrtowc((wchar_t *)&v160, v154, 1u, &v162, *(const _Cvtvec **)&v160._Byte);
    if ( v95 == LOWORD(v160._Wchar) )
      goto LABEL_230;
    if ( !*(_BYTE *)(a4 + 4) )
    {
      v96 = *(_DWORD *)a4;
      if ( !*(_DWORD *)a4
        || ((v97 = *(__int16 ***)(v96 + 32), !*v97) || **(int **)(v96 + 48) <= 0
          ? (v98 = (*(int (__thiscall **)(int))(*(_DWORD *)v96 + 24))(v96))
          : (v98 = **v97),
            v98 == -1) )
      {
        *(_DWORD *)a4 = 0;
      }
      else
      {
        *(_WORD *)(a4 + 6) = v98;
      }
      *(_BYTE *)(a4 + 4) = 1;
    }
    v99 = *(_WORD *)(a4 + 6);
    v154[0] = 69;
    *(_DWORD *)&v160._Byte = 0;
    v162._Wchar = 0;
    _Mbrtowc(&v160._Byte, v154, 1u, &v162, v94);
    if ( v99 == v160._Byte )
    {
LABEL_230:
      v100 = v156;
      *v156 = 101;
      v101 = *(_DWORD *)a4;
      v156 = v100 + 1;
      if ( !v101
        || (!**(_DWORD **)(v101 + 32) || (v102 = *(int **)(v101 + 48), *v102 <= 0)
          ? (v105 = (*(int (__thiscall **)(int))(*(_DWORD *)v101 + 28))(v101))
          : (--*v102, v103 = *(__int16 ***)(v101 + 32), v104 = *v103, ++*v103, v105 = *v104),
            v105 == -1) )
      {
        *(_DWORD *)a4 = 0;
        *(_BYTE *)(a4 + 4) = 1;
      }
      else
      {
        *(_BYTE *)(a4 + 4) = 0;
      }
      v153[0] = 0;
      v159 = 0;
      if ( (unsigned __int8)sub_44BB00(*(int **)&v161._Byte, (int *)a4) )
        goto LABEL_273;
      if ( !*(_BYTE *)(a4 + 4) )
      {
        v106 = *(_DWORD *)a4;
        if ( !*(_DWORD *)a4
          || ((v107 = *(__int16 ***)(v106 + 32), !*v107) || **(int **)(v106 + 48) <= 0
            ? (v108 = (*(int (__thiscall **)(int))(*(_DWORD *)v106 + 24))(v106))
            : (v108 = **v107),
              v108 == -1) )
        {
          *(_DWORD *)a4 = 0;
        }
        else
        {
          *(_WORD *)(a4 + 6) = v108;
        }
        *(_BYTE *)(a4 + 4) = 1;
      }
      v109 = *(_WORD *)(a4 + 6);
      v154[0] = 43;
      *(_DWORD *)&v160._Byte = 0;
      v162._Wchar = 0;
      _Mbrtowc(&v160._Byte, v154, 1u, &v162, v94);
      if ( v109 == v160._Byte )
      {
        v110 = v156;
        *v156 = 43;
        v111 = *(_DWORD **)a4;
        v156 = v110 + 1;
        if ( !v111 )
          goto LABEL_272;
        if ( *(_DWORD *)v111[8] )
        {
          v112 = (int *)v111[12];
          if ( *v112 > 0 )
          {
            --*v112;
            v113 = (_WORD **)v111[8];
            v114 = (*v113)++;
            v115 = *v114;
            goto LABEL_270;
          }
        }
      }
      else
      {
        if ( !*(_BYTE *)(a4 + 4) )
        {
          v116 = *(_DWORD *)a4;
          if ( !*(_DWORD *)a4
            || ((v117 = *(__int16 ***)(v116 + 32), !*v117) || **(int **)(v116 + 48) <= 0
              ? (v118 = (*(int (__thiscall **)(int))(*(_DWORD *)v116 + 24))(v116))
              : (v118 = **v117),
                v118 == -1) )
          {
            *(_DWORD *)a4 = 0;
          }
          else
          {
            *(_WORD *)(a4 + 6) = v118;
          }
          *(_BYTE *)(a4 + 4) = 1;
        }
        v119 = *(_WORD *)(a4 + 6);
        v154[0] = 45;
        *(_DWORD *)&v160._Byte = 0;
        v161._Wchar = 0;
        _Mbrtowc(&v160._Byte, v154, 1u, &v161, v94);
        if ( v119 != v160._Byte )
          goto LABEL_273;
        v120 = v156;
        *v156 = 45;
        v111 = *(_DWORD **)a4;
        v156 = v120 + 1;
        if ( !v111 )
          goto LABEL_272;
        if ( *(_DWORD *)v111[8] )
        {
          v121 = (int *)v111[12];
          if ( *v121 > 0 )
          {
            --*v121;
            v122 = (_WORD **)v111[8];
            v123 = (*v122)++;
            v115 = *v123;
            goto LABEL_270;
          }
        }
      }
      v115 = (*(int (__thiscall **)(_DWORD *))(*v111 + 28))(v111);
LABEL_270:
      if ( v115 != -1 )
      {
        *(_BYTE *)(a4 + 4) = 0;
LABEL_273:
        v124 = *(int **)&v161._Byte;
        if ( (unsigned __int8)sub_44BB00(*(int **)&v161._Byte, (int *)a4) )
        {
          v128 = v158[0];
        }
        else
        {
          while ( 1 )
          {
            if ( !*(_BYTE *)(a4 + 4) )
            {
              v125 = *(_DWORD *)a4;
              if ( !*(_DWORD *)a4
                || ((v126 = *(__int16 ***)(v125 + 32), !*v126) || **(int **)(v125 + 48) <= 0
                  ? (v127 = (*(int (__thiscall **)(int))(*(_DWORD *)v125 + 24))(v125))
                  : (v127 = **v126),
                    v127 == -1) )
              {
                *(_DWORD *)a4 = 0;
              }
              else
              {
                *(_WORD *)(a4 + 6) = v127;
              }
              *(_BYTE *)(a4 + 4) = 1;
            }
            v128 = v158[0];
            if ( *(_WORD *)(a4 + 6) != v158[0] )
              break;
            v129 = *(_DWORD *)a4;
            v153[0] = 1;
            if ( !v129
              || (!**(_DWORD **)(v129 + 32) || (v130 = *(int **)(v129 + 48), *v130 <= 0)
                ? (v133 = (*(int (__thiscall **)(int))(*(_DWORD *)v129 + 28))(v129))
                : (--*v130, v131 = *(__int16 ***)(v129 + 32), v132 = *v131, ++*v131, v133 = *v132),
                  v133 == -1) )
            {
              *(_DWORD *)a4 = 0;
              *(_BYTE *)(a4 + 4) = 1;
            }
            else
            {
              *(_BYTE *)(a4 + 4) = 0;
            }
            if ( (unsigned __int8)sub_44BB00(v124, (int *)a4) )
            {
              v134 = v156;
              v128 = v158[0];
              *v156 = 48;
              v156 = v134 + 1;
              goto LABEL_298;
            }
          }
          if ( v153[0] )
          {
            v135 = v156;
            *v156 = 48;
            v156 = v135 + 1;
          }
        }
LABEL_298:
        while ( !(unsigned __int8)sub_44BB00(v124, (int *)a4) )
        {
          if ( !*(_BYTE *)(a4 + 4) )
          {
            v136 = *(_DWORD *)a4;
            if ( !*(_DWORD *)a4
              || ((v137 = *(__int16 ***)(v136 + 32), !*v137) || **(int **)(v136 + 48) <= 0
                ? (v138 = (*(int (__thiscall **)(int))(*(_DWORD *)v136 + 24))(v136))
                : (v138 = **v137),
                  v138 == -1) )
            {
              *(_DWORD *)a4 = 0;
            }
            else
            {
              *(_WORD *)(a4 + 6) = v138;
            }
            *(_BYTE *)(a4 + 4) = 1;
          }
          if ( v128 > *(_WORD *)(a4 + 6) )
            break;
          if ( !*(_BYTE *)(a4 + 4) )
          {
            v139 = *(_DWORD *)a4;
            if ( !*(_DWORD *)a4
              || ((v140 = *(__int16 ***)(v139 + 32), !*v140) || **(int **)(v139 + 48) <= 0
                ? (v141 = (*(int (__thiscall **)(int))(*(_DWORD *)v139 + 24))(v139))
                : (v141 = **v140),
                  v141 == -1) )
            {
              *(_DWORD *)a4 = 0;
            }
            else
            {
              *(_WORD *)(a4 + 6) = v141;
            }
            *(_BYTE *)(a4 + 4) = 1;
          }
          if ( *(unsigned __int16 *)(a4 + 6) > v128 + 9 )
            break;
          if ( v159 < 8 )
          {
            if ( !*(_BYTE *)(a4 + 4) )
            {
              v142 = *(_DWORD *)a4;
              if ( !*(_DWORD *)a4
                || ((v143 = *(__int16 ***)(v142 + 32), !*v143) || **(int **)(v142 + 48) <= 0
                  ? (v144 = (*(int (__thiscall **)(int))(*(_DWORD *)v142 + 24))(v142))
                  : (v144 = **v143),
                    v144 == -1) )
              {
                *(_DWORD *)a4 = 0;
              }
              else
              {
                *(_WORD *)(a4 + 6) = v144;
              }
              *(_BYTE *)(a4 + 4) = 1;
            }
            v145 = v156;
            *v156 = *(_BYTE *)(a4 + 6) - v128 + 48;
            ++v159;
            v156 = v145 + 1;
          }
          v146 = *(_DWORD *)a4;
          v153[0] = 1;
          if ( !v146
            || (!**(_DWORD **)(v146 + 32) || (v147 = *(int **)(v146 + 48), *v147 <= 0)
              ? (v150 = (*(int (__thiscall **)(int))(*(_DWORD *)v146 + 28))(v146))
              : (--*v147, v148 = *(__int16 ***)(v146 + 32), v149 = *v148, ++*v148, v150 = *v149),
                v150 == -1) )
          {
            *(_DWORD *)a4 = 0;
            *(_BYTE *)(a4 + 4) = 1;
          }
          else
          {
            *(_BYTE *)(a4 + 4) = 0;
          }
        }
        goto LABEL_342;
      }
LABEL_272:
      *(_BYTE *)(a4 + 4) = 1;
      *(_DWORD *)a4 = 0;
      goto LABEL_273;
    }
  }
LABEL_342:
  if ( !v155[0] && v153[0] )
    v151 = v156;
  else
    v151 = *(char **)&v162._Byte;
  v152 = v166 < 0x10;
  *v151 = 0;
  if ( !v152 )
    operator delete(v165[0]);
  return *(_DWORD *)v157;
}
