int __cdecl memcmp(const void *Buf1, const void *Buf2, size_t Size)
{
  size_t v3; // edi
  unsigned __int8 *v4; // ecx
  unsigned __int8 *v5; // eax
  int v6; // esi
  BOOL v7; // ebx
  int v8; // esi
  int v9; // esi
  BOOL v10; // ebx
  int v11; // esi
  BOOL v12; // ebx
  int v13; // esi
  BOOL v14; // ebx
  int v15; // esi
  BOOL v16; // ebx
  int v17; // esi
  BOOL v18; // ebx
  int v19; // esi
  BOOL v20; // ebx
  int v21; // esi
  BOOL v22; // ebx
  int v23; // esi
  BOOL v24; // ebx
  int v25; // esi
  BOOL v26; // ebx
  int v27; // esi
  BOOL v28; // ebx
  int v29; // esi
  BOOL v30; // ebx
  int v31; // esi
  BOOL v32; // ebx
  int v33; // esi
  BOOL v34; // ebx
  int v35; // esi
  BOOL v36; // ebx
  int v37; // esi
  BOOL v38; // ebx
  int v39; // esi
  BOOL v40; // ebx
  int v41; // esi
  BOOL v42; // ebx
  int v43; // esi
  BOOL v44; // ebx
  int v45; // esi
  BOOL v46; // ebx
  int v47; // esi
  BOOL v48; // ebx
  int v49; // esi
  BOOL v50; // ebx
  int v51; // esi
  BOOL v52; // ebx
  int v53; // esi
  BOOL v54; // ebx
  unsigned __int8 *v55; // eax
  unsigned __int8 *v56; // ecx
  int result; // eax
  int v58; // edx
  int v59; // esi
  BOOL v60; // edx
  int v61; // esi
  BOOL v62; // edx
  int v63; // esi
  BOOL v64; // edx
  int v65; // edx
  int v66; // esi
  BOOL v67; // edx
  int v68; // esi
  BOOL v69; // edx
  int v70; // esi
  BOOL v71; // edx
  int v72; // edx
  int v73; // esi
  BOOL v74; // edx
  int v75; // esi
  BOOL v76; // edx
  int v77; // esi
  BOOL v78; // edx
  int v79; // edx
  int v80; // esi
  BOOL v81; // edx
  int v82; // esi
  BOOL v83; // edx
  int v84; // esi
  BOOL v85; // edx
  int v86; // esi
  BOOL v87; // edx
  int v88; // esi
  BOOL v89; // edx
  int v90; // esi
  BOOL v91; // edx
  int v92; // edx
  int v93; // esi
  BOOL v94; // edx
  int v95; // esi
  BOOL v96; // edx
  int v97; // esi
  BOOL v98; // edx
  int v99; // edx
  int v100; // esi
  int v101; // edx
  int v102; // esi
  int v103; // esi
  int v104; // edx
  int v105; // esi
  BOOL v106; // edx
  int v107; // esi
  BOOL v108; // edx
  int v109; // esi
  BOOL v110; // edx
  int v111; // edx
  int v112; // esi
  BOOL v113; // edx
  int v114; // esi
  BOOL v115; // edx
  int v116; // esi
  BOOL v117; // edx
  int v118; // edx
  int v119; // esi
  BOOL v120; // edx
  int v121; // esi
  BOOL v122; // edx
  int v123; // esi
  BOOL v124; // edx
  int v125; // edx
  int v126; // esi
  BOOL v127; // edx
  int v128; // esi
  BOOL v129; // edx
  int v130; // esi
  BOOL v131; // edx
  int v132; // edx
  int v133; // esi
  BOOL v134; // edx
  int v135; // esi
  BOOL v136; // edx
  int v137; // esi
  BOOL v138; // edx
  int v139; // esi
  BOOL v140; // edx
  int v141; // esi
  BOOL v142; // edx
  int v143; // esi
  BOOL v144; // edx
  int v145; // edx
  int v146; // esi
  BOOL v147; // edx
  int v148; // esi
  BOOL v149; // edx
  int v150; // esi
  BOOL v151; // edx
  int v152; // edx
  int v153; // esi
  BOOL v154; // edx
  int v155; // esi
  BOOL v156; // edx
  int v157; // esi
  BOOL v158; // edx
  int v159; // edx
  int v160; // esi
  BOOL v161; // edx
  int v162; // esi
  BOOL v163; // edx
  int v164; // esi
  BOOL v165; // edx
  int v166; // edx
  int v167; // esi
  BOOL v168; // edx
  int v169; // esi
  BOOL v170; // edx
  int v171; // esi
  BOOL v172; // edx
  int v173; // edx
  int v174; // esi
  BOOL v175; // edx
  int v176; // esi
  BOOL v177; // edx
  int v178; // esi
  BOOL v179; // edx
  int v180; // edx
  int v181; // esi
  BOOL v182; // edx
  int v183; // esi
  BOOL v184; // edx
  int v185; // esi
  BOOL v186; // edx
  int v187; // esi
  BOOL v188; // edx
  int v189; // esi
  BOOL v190; // edx
  int v191; // esi
  BOOL v192; // edx
  int v193; // edx
  int v194; // esi
  BOOL v195; // edx
  int v196; // esi
  BOOL v197; // edx
  int v198; // esi
  BOOL v199; // edx
  int v200; // esi
  int v201; // edx
  int v202; // esi
  BOOL v203; // edx
  int v204; // esi
  BOOL v205; // edx
  int v206; // esi
  BOOL v207; // edx
  int v208; // edx
  int v209; // esi
  BOOL v210; // edx
  int v211; // esi
  BOOL v212; // edx
  int v213; // esi
  BOOL v214; // edx
  int v215; // edx
  int v216; // esi
  BOOL v217; // edx
  int v218; // esi
  BOOL v219; // edx
  int v220; // esi
  BOOL v221; // edx
  int v222; // edx
  int v223; // esi
  BOOL v224; // edx
  int v225; // esi
  BOOL v226; // edx
  int v227; // esi
  BOOL v228; // edx
  int v229; // esi
  BOOL v230; // edx
  int v231; // esi
  BOOL v232; // edx
  int v233; // esi
  BOOL v234; // edx
  int v235; // edx
  int v236; // esi
  BOOL v237; // edx
  int v238; // esi
  BOOL v239; // edx
  int v240; // esi
  BOOL v241; // edx
  int v242; // edx
  int v243; // esi
  BOOL v244; // edx
  int v245; // esi
  BOOL v246; // edx
  int v247; // esi
  BOOL v248; // edx
  int v249; // esi
  int v250; // eax
  BOOL v251; // edx
  int v252; // eax
  BOOL v253; // edx
  int v254; // eax
  BOOL v255; // edx
  int v256; // eax
  int v257; // ecx
  int v258; // eax
  BOOL v259; // edx
  int v260; // eax
  BOOL v261; // edx
  int v262; // eax
  BOOL v263; // edx

  v3 = Size;
  switch ( Size )
  {
    case 0u:
      return 0;
    case 1u:
      v256 = *(unsigned __int8 *)Buf1;
      v257 = *(unsigned __int8 *)Buf2;
LABEL_426:
      result = v256 - v257;
      if ( result )
        return 2 * (result > 0) - 1;
      return result;
    case 2u:
      v262 = *(unsigned __int8 *)Buf1 - *(unsigned __int8 *)Buf2;
      if ( v262 )
      {
        v263 = v262 > 0;
        result = 2 * v263 - 1;
        if ( 2 * v263 != 1 )
          return result;
      }
      v256 = *((unsigned __int8 *)Buf1 + 1);
      v257 = *((unsigned __int8 *)Buf2 + 1);
      goto LABEL_426;
    case 3u:
      v258 = *(unsigned __int8 *)Buf1 - *(unsigned __int8 *)Buf2;
      if ( v258 )
      {
        v259 = v258 > 0;
        result = 2 * v259 - 1;
        if ( 2 * v259 != 1 )
          return result;
      }
      v260 = *((unsigned __int8 *)Buf1 + 1) - *((unsigned __int8 *)Buf2 + 1);
      if ( v260 )
      {
        v261 = v260 > 0;
        result = 2 * v261 - 1;
        if ( 2 * v261 != 1 )
          return result;
      }
      v256 = *((unsigned __int8 *)Buf1 + 2);
      v257 = *((unsigned __int8 *)Buf2 + 2);
      goto LABEL_426;
    case 4u:
      v250 = *(unsigned __int8 *)Buf1 - *(unsigned __int8 *)Buf2;
      if ( v250 )
      {
        v251 = v250 > 0;
        result = 2 * v251 - 1;
        if ( 2 * v251 != 1 )
          return result;
      }
      v252 = *((unsigned __int8 *)Buf1 + 1) - *((unsigned __int8 *)Buf2 + 1);
      if ( v252 )
      {
        v253 = v252 > 0;
        result = 2 * v253 - 1;
        if ( 2 * v253 != 1 )
          return result;
      }
      v254 = *((unsigned __int8 *)Buf1 + 2) - *((unsigned __int8 *)Buf2 + 2);
      if ( v254 )
      {
        v255 = v254 > 0;
        result = 2 * v255 - 1;
        if ( 2 * v255 != 1 )
          return result;
      }
      v256 = *((unsigned __int8 *)Buf1 + 3);
      v257 = *((unsigned __int8 *)Buf2 + 3);
      goto LABEL_426;
  }
  v4 = (unsigned __int8 *)Buf2;
  v5 = (unsigned __int8 *)Buf1;
  while ( v3 >= 0x20 )
  {
    if ( *(_DWORD *)v5 == *(_DWORD *)v4 )
    {
      v8 = 0;
    }
    else
    {
      v6 = *v5 - *v4;
      if ( v6 )
      {
        v7 = v6 > 0;
        v8 = 2 * v7 - 1;
        if ( 2 * v7 != 1 )
          return v8;
      }
      v9 = v5[1] - v4[1];
      if ( v9 )
      {
        v10 = v9 > 0;
        v8 = 2 * v10 - 1;
        if ( 2 * v10 != 1 )
          return v8;
      }
      v11 = v5[2] - v4[2];
      if ( v11 )
      {
        v12 = v11 > 0;
        v8 = 2 * v12 - 1;
        if ( 2 * v12 != 1 )
          return v8;
      }
      v8 = v5[3] - v4[3];
      if ( v8 )
        v8 = 2 * (v8 > 0) - 1;
    }
    if ( v8 )
      return v8;
    if ( *((_DWORD *)v5 + 1) == *((_DWORD *)v4 + 1) )
    {
      v8 = 0;
    }
    else
    {
      v13 = v5[4] - v4[4];
      if ( v13 )
      {
        v14 = v13 > 0;
        v8 = 2 * v14 - 1;
        if ( 2 * v14 != 1 )
          return v8;
      }
      v15 = v5[5] - v4[5];
      if ( v15 )
      {
        v16 = v15 > 0;
        v8 = 2 * v16 - 1;
        if ( 2 * v16 != 1 )
          return v8;
      }
      v17 = v5[6] - v4[6];
      if ( v17 )
      {
        v18 = v17 > 0;
        v8 = 2 * v18 - 1;
        if ( 2 * v18 != 1 )
          return v8;
      }
      v8 = v5[7] - v4[7];
      if ( v8 )
        v8 = 2 * (v8 > 0) - 1;
    }
    if ( v8 )
      return v8;
    if ( *((_DWORD *)v5 + 2) == *((_DWORD *)v4 + 2) )
    {
      v8 = 0;
    }
    else
    {
      v19 = v5[8] - v4[8];
      if ( v19 )
      {
        v20 = v19 > 0;
        v8 = 2 * v20 - 1;
        if ( 2 * v20 != 1 )
          return v8;
      }
      v21 = v5[9] - v4[9];
      if ( v21 )
      {
        v22 = v21 > 0;
        v8 = 2 * v22 - 1;
        if ( 2 * v22 != 1 )
          return v8;
      }
      v23 = v5[10] - v4[10];
      if ( v23 )
      {
        v24 = v23 > 0;
        v8 = 2 * v24 - 1;
        if ( 2 * v24 != 1 )
          return v8;
      }
      v8 = v5[11] - v4[11];
      if ( v8 )
        v8 = 2 * (v8 > 0) - 1;
    }
    if ( v8 )
      return v8;
    if ( *((_DWORD *)v5 + 3) == *((_DWORD *)v4 + 3) )
    {
      v8 = 0;
    }
    else
    {
      v25 = v5[12] - v4[12];
      if ( v25 )
      {
        v26 = v25 > 0;
        v8 = 2 * v26 - 1;
        if ( 2 * v26 != 1 )
          return v8;
      }
      v27 = v5[13] - v4[13];
      if ( v27 )
      {
        v28 = v27 > 0;
        v8 = 2 * v28 - 1;
        if ( 2 * v28 != 1 )
          return v8;
      }
      v29 = v5[14] - v4[14];
      if ( v29 )
      {
        v30 = v29 > 0;
        v8 = 2 * v30 - 1;
        if ( 2 * v30 != 1 )
          return v8;
      }
      v8 = v5[15] - v4[15];
      if ( v8 )
        v8 = 2 * (v8 > 0) - 1;
    }
    if ( v8 )
      return v8;
    if ( *((_DWORD *)v5 + 4) == *((_DWORD *)v4 + 4) )
    {
      v8 = 0;
    }
    else
    {
      v31 = v5[16] - v4[16];
      if ( v31 )
      {
        v32 = v31 > 0;
        v8 = 2 * v32 - 1;
        if ( 2 * v32 != 1 )
          return v8;
      }
      v33 = v5[17] - v4[17];
      if ( v33 )
      {
        v34 = v33 > 0;
        v8 = 2 * v34 - 1;
        if ( 2 * v34 != 1 )
          return v8;
      }
      v35 = v5[18] - v4[18];
      if ( v35 )
      {
        v36 = v35 > 0;
        v8 = 2 * v36 - 1;
        if ( 2 * v36 != 1 )
          return v8;
      }
      v8 = v5[19] - v4[19];
      if ( v8 )
        v8 = 2 * (v8 > 0) - 1;
    }
    if ( v8 )
      return v8;
    if ( *((_DWORD *)v5 + 5) == *((_DWORD *)v4 + 5) )
    {
      v8 = 0;
    }
    else
    {
      v37 = v5[20] - v4[20];
      if ( v37 )
      {
        v38 = v37 > 0;
        v8 = 2 * v38 - 1;
        if ( 2 * v38 != 1 )
          return v8;
      }
      v39 = v5[21] - v4[21];
      if ( v39 )
      {
        v40 = v39 > 0;
        v8 = 2 * v40 - 1;
        if ( 2 * v40 != 1 )
          return v8;
      }
      v41 = v5[22] - v4[22];
      if ( v41 )
      {
        v42 = v41 > 0;
        v8 = 2 * v42 - 1;
        if ( 2 * v42 != 1 )
          return v8;
      }
      v8 = v5[23] - v4[23];
      if ( v8 )
        v8 = 2 * (v8 > 0) - 1;
    }
    if ( v8 )
      return v8;
    if ( *((_DWORD *)v5 + 6) == *((_DWORD *)v4 + 6) )
    {
      v8 = 0;
    }
    else
    {
      v43 = v5[24] - v4[24];
      if ( v43 )
      {
        v44 = v43 > 0;
        v8 = 2 * v44 - 1;
        if ( 2 * v44 != 1 )
          return v8;
      }
      v45 = v5[25] - v4[25];
      if ( v45 )
      {
        v46 = v45 > 0;
        v8 = 2 * v46 - 1;
        if ( 2 * v46 != 1 )
          return v8;
      }
      v47 = v5[26] - v4[26];
      if ( v47 )
      {
        v48 = v47 > 0;
        v8 = 2 * v48 - 1;
        if ( 2 * v48 != 1 )
          return v8;
      }
      v8 = v5[27] - v4[27];
      if ( v8 )
        v8 = 2 * (v8 > 0) - 1;
    }
    if ( v8 )
      return v8;
    if ( *((_DWORD *)v5 + 7) == *((_DWORD *)v4 + 7) )
    {
      v8 = 0;
    }
    else
    {
      v49 = v5[28] - v4[28];
      if ( v49 )
      {
        v50 = v49 > 0;
        v8 = 2 * v50 - 1;
        if ( 2 * v50 != 1 )
          return v8;
      }
      v51 = v5[29] - v4[29];
      if ( v51 )
      {
        v52 = v51 > 0;
        v8 = 2 * v52 - 1;
        if ( 2 * v52 != 1 )
          return v8;
      }
      v53 = v5[30] - v4[30];
      if ( v53 )
      {
        v54 = v53 > 0;
        v8 = 2 * v54 - 1;
        if ( 2 * v54 != 1 )
          return v8;
      }
      v8 = v5[31] - v4[31];
      if ( v8 )
        v8 = 2 * (v8 > 0) - 1;
    }
    if ( v8 )
      return v8;
    v5 += 32;
    v4 += 32;
    v3 -= 32;
  }
  v55 = &v5[v3];
  v56 = &v4[v3];
  switch ( v3 )
  {
    case 1u:
      goto LABEL_256;
    case 2u:
      goto LABEL_335;
    case 3u:
      goto LABEL_416;
    case 4u:
      goto LABEL_165;
    case 5u:
      goto LABEL_245;
    case 6u:
      goto LABEL_324;
    case 7u:
      goto LABEL_405;
    case 8u:
      goto LABEL_154;
    case 9u:
      goto LABEL_234;
    case 0xAu:
      goto LABEL_313;
    case 0xBu:
      goto LABEL_394;
    case 0xCu:
      goto LABEL_143;
    case 0xDu:
      goto LABEL_223;
    case 0xEu:
      goto LABEL_302;
    case 0xFu:
      goto LABEL_383;
    case 0x10u:
      goto LABEL_132;
    case 0x11u:
      goto LABEL_212;
    case 0x12u:
      goto LABEL_291;
    case 0x13u:
      goto LABEL_372;
    case 0x14u:
      goto LABEL_121;
    case 0x15u:
      goto LABEL_201;
    case 0x16u:
      goto LABEL_280;
    case 0x17u:
      goto LABEL_361;
    case 0x18u:
      goto LABEL_110;
    case 0x19u:
      goto LABEL_190;
    case 0x1Au:
      goto LABEL_269;
    case 0x1Bu:
      goto LABEL_350;
    case 0x1Cu:
      v58 = *((_DWORD *)v55 - 7);
      if ( v58 == *((_DWORD *)v56 - 7) )
      {
        v8 = 0;
      }
      else
      {
        v59 = (unsigned __int8)v58 - *(v56 - 28);
        if ( v59 )
        {
          v60 = v59 > 0;
          v8 = 2 * v60 - 1;
          if ( 2 * v60 != 1 )
            return v8;
        }
        v61 = *(v55 - 27) - *(v56 - 27);
        if ( v61 )
        {
          v62 = v61 > 0;
          v8 = 2 * v62 - 1;
          if ( 2 * v62 != 1 )
            return v8;
        }
        v63 = *(v55 - 26) - *(v56 - 26);
        if ( v63 )
        {
          v64 = v63 > 0;
          v8 = 2 * v64 - 1;
          if ( 2 * v64 != 1 )
            return v8;
        }
        v8 = *(v55 - 25) - *(v56 - 25);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_110:
      v65 = *((_DWORD *)v55 - 6);
      if ( v65 == *((_DWORD *)v56 - 6) )
      {
        v8 = 0;
      }
      else
      {
        v66 = (unsigned __int8)v65 - *(v56 - 24);
        if ( v66 )
        {
          v67 = v66 > 0;
          v8 = 2 * v67 - 1;
          if ( 2 * v67 != 1 )
            return v8;
        }
        v68 = *(v55 - 23) - *(v56 - 23);
        if ( v68 )
        {
          v69 = v68 > 0;
          v8 = 2 * v69 - 1;
          if ( 2 * v69 != 1 )
            return v8;
        }
        v70 = *(v55 - 22) - *(v56 - 22);
        if ( v70 )
        {
          v71 = v70 > 0;
          v8 = 2 * v71 - 1;
          if ( 2 * v71 != 1 )
            return v8;
        }
        v8 = *(v55 - 21) - *(v56 - 21);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_121:
      v72 = *((_DWORD *)v55 - 5);
      if ( v72 == *((_DWORD *)v56 - 5) )
      {
        v8 = 0;
      }
      else
      {
        v73 = (unsigned __int8)v72 - *(v56 - 20);
        if ( v73 )
        {
          v74 = v73 > 0;
          v8 = 2 * v74 - 1;
          if ( 2 * v74 != 1 )
            return v8;
        }
        v75 = *(v55 - 19) - *(v56 - 19);
        if ( v75 )
        {
          v76 = v75 > 0;
          v8 = 2 * v76 - 1;
          if ( 2 * v76 != 1 )
            return v8;
        }
        v77 = *(v55 - 18) - *(v56 - 18);
        if ( v77 )
        {
          v78 = v77 > 0;
          v8 = 2 * v78 - 1;
          if ( 2 * v78 != 1 )
            return v8;
        }
        v8 = *(v55 - 17) - *(v56 - 17);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_132:
      v79 = *((_DWORD *)v55 - 4);
      if ( v79 == *((_DWORD *)v56 - 4) )
      {
        v8 = 0;
      }
      else
      {
        v80 = (unsigned __int8)v79 - *(v56 - 16);
        if ( v80 )
        {
          v81 = v80 > 0;
          v8 = 2 * v81 - 1;
          if ( 2 * v81 != 1 )
            return v8;
        }
        v82 = *(v55 - 15) - *(v56 - 15);
        if ( v82 )
        {
          v83 = v82 > 0;
          v8 = 2 * v83 - 1;
          if ( 2 * v83 != 1 )
            return v8;
        }
        v84 = *(v55 - 14) - *(v56 - 14);
        if ( v84 )
        {
          v85 = v84 > 0;
          v8 = 2 * v85 - 1;
          if ( 2 * v85 != 1 )
            return v8;
        }
        v8 = *(v55 - 13) - *(v56 - 13);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_143:
      if ( *((_DWORD *)v55 - 3) == *((_DWORD *)v56 - 3) )
      {
        v8 = 0;
      }
      else
      {
        v86 = *(v55 - 12) - *(v56 - 12);
        if ( v86 )
        {
          v87 = v86 > 0;
          v8 = 2 * v87 - 1;
          if ( 2 * v87 != 1 )
            return v8;
        }
        v88 = *(v55 - 11) - *(v56 - 11);
        if ( v88 )
        {
          v89 = v88 > 0;
          v8 = 2 * v89 - 1;
          if ( 2 * v89 != 1 )
            return v8;
        }
        v90 = *(v55 - 10) - *(v56 - 10);
        if ( v90 )
        {
          v91 = v90 > 0;
          v8 = 2 * v91 - 1;
          if ( 2 * v91 != 1 )
            return v8;
        }
        v8 = *(v55 - 9) - *(v56 - 9);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_154:
      v92 = *((_DWORD *)v55 - 2);
      if ( v92 == *((_DWORD *)v56 - 2) )
      {
        v8 = 0;
      }
      else
      {
        v93 = (unsigned __int8)v92 - *(v56 - 8);
        if ( v93 )
        {
          v94 = v93 > 0;
          v8 = 2 * v94 - 1;
          if ( 2 * v94 != 1 )
            return v8;
        }
        v95 = *(v55 - 7) - *(v56 - 7);
        if ( v95 )
        {
          v96 = v95 > 0;
          v8 = 2 * v96 - 1;
          if ( 2 * v96 != 1 )
            return v8;
        }
        v97 = *(v55 - 6) - *(v56 - 6);
        if ( v97 )
        {
          v98 = v97 > 0;
          v8 = 2 * v98 - 1;
          if ( 2 * v98 != 1 )
            return v8;
        }
        v8 = *(v55 - 5) - *(v56 - 5);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_165:
      v99 = *((_DWORD *)v55 - 1);
      if ( v99 == *((_DWORD *)v56 - 1) )
      {
        result = 0;
      }
      else
      {
        v100 = (unsigned __int8)v99 - *(v56 - 4);
        if ( (!v100 || (v101 = 2 * (v100 > 0) - 1, 2 * (v100 > 0) == 1))
          && ((v102 = *(v55 - 3) - *(v56 - 3)) == 0 || (v101 = 2 * (v102 > 0) - 1, 2 * (v102 > 0) == 1))
          && ((v103 = *(v55 - 2) - *(v56 - 2)) == 0 || (v101 = 2 * (v103 > 0) - 1, 2 * (v103 > 0) == 1)) )
        {
          result = *(v55 - 1) - *(v56 - 1);
          if ( result )
            result = 2 * (result > 0) - 1;
        }
        else
        {
          result = v101;
        }
      }
      if ( !result )
        return 0;
      return result;
    case 0x1Du:
      v104 = *(_DWORD *)(v55 - 29);
      if ( v104 == *(_DWORD *)(v56 - 29) )
      {
        v8 = 0;
      }
      else
      {
        v105 = (unsigned __int8)v104 - *(v56 - 29);
        if ( v105 )
        {
          v106 = v105 > 0;
          v8 = 2 * v106 - 1;
          if ( 2 * v106 != 1 )
            return v8;
        }
        v107 = *(v55 - 28) - *(v56 - 28);
        if ( v107 )
        {
          v108 = v107 > 0;
          v8 = 2 * v108 - 1;
          if ( 2 * v108 != 1 )
            return v8;
        }
        v109 = *(v55 - 27) - *(v56 - 27);
        if ( v109 )
        {
          v110 = v109 > 0;
          v8 = 2 * v110 - 1;
          if ( 2 * v110 != 1 )
            return v8;
        }
        v8 = *(v55 - 26) - *(v56 - 26);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_190:
      v111 = *(_DWORD *)(v55 - 25);
      if ( v111 == *(_DWORD *)(v56 - 25) )
      {
        v8 = 0;
      }
      else
      {
        v112 = (unsigned __int8)v111 - *(v56 - 25);
        if ( v112 )
        {
          v113 = v112 > 0;
          v8 = 2 * v113 - 1;
          if ( 2 * v113 != 1 )
            return v8;
        }
        v114 = *(v55 - 24) - *(v56 - 24);
        if ( v114 )
        {
          v115 = v114 > 0;
          v8 = 2 * v115 - 1;
          if ( 2 * v115 != 1 )
            return v8;
        }
        v116 = *(v55 - 23) - *(v56 - 23);
        if ( v116 )
        {
          v117 = v116 > 0;
          v8 = 2 * v117 - 1;
          if ( 2 * v117 != 1 )
            return v8;
        }
        v8 = *(v55 - 22) - *(v56 - 22);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_201:
      v118 = *(_DWORD *)(v55 - 21);
      if ( v118 == *(_DWORD *)(v56 - 21) )
      {
        v8 = 0;
      }
      else
      {
        v119 = (unsigned __int8)v118 - *(v56 - 21);
        if ( v119 )
        {
          v120 = v119 > 0;
          v8 = 2 * v120 - 1;
          if ( 2 * v120 != 1 )
            return v8;
        }
        v121 = *(v55 - 20) - *(v56 - 20);
        if ( v121 )
        {
          v122 = v121 > 0;
          v8 = 2 * v122 - 1;
          if ( 2 * v122 != 1 )
            return v8;
        }
        v123 = *(v55 - 19) - *(v56 - 19);
        if ( v123 )
        {
          v124 = v123 > 0;
          v8 = 2 * v124 - 1;
          if ( 2 * v124 != 1 )
            return v8;
        }
        v8 = *(v55 - 18) - *(v56 - 18);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_212:
      v125 = *(_DWORD *)(v55 - 17);
      if ( v125 == *(_DWORD *)(v56 - 17) )
      {
        v8 = 0;
      }
      else
      {
        v126 = (unsigned __int8)v125 - *(v56 - 17);
        if ( v126 )
        {
          v127 = v126 > 0;
          v8 = 2 * v127 - 1;
          if ( 2 * v127 != 1 )
            return v8;
        }
        v128 = *(v55 - 16) - *(v56 - 16);
        if ( v128 )
        {
          v129 = v128 > 0;
          v8 = 2 * v129 - 1;
          if ( 2 * v129 != 1 )
            return v8;
        }
        v130 = *(v55 - 15) - *(v56 - 15);
        if ( v130 )
        {
          v131 = v130 > 0;
          v8 = 2 * v131 - 1;
          if ( 2 * v131 != 1 )
            return v8;
        }
        v8 = *(v55 - 14) - *(v56 - 14);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_223:
      v132 = *(_DWORD *)(v55 - 13);
      if ( v132 == *(_DWORD *)(v56 - 13) )
      {
        v8 = 0;
      }
      else
      {
        v133 = (unsigned __int8)v132 - *(v56 - 13);
        if ( v133 )
        {
          v134 = v133 > 0;
          v8 = 2 * v134 - 1;
          if ( 2 * v134 != 1 )
            return v8;
        }
        v135 = *(v55 - 12) - *(v56 - 12);
        if ( v135 )
        {
          v136 = v135 > 0;
          v8 = 2 * v136 - 1;
          if ( 2 * v136 != 1 )
            return v8;
        }
        v137 = *(v55 - 11) - *(v56 - 11);
        if ( v137 )
        {
          v138 = v137 > 0;
          v8 = 2 * v138 - 1;
          if ( 2 * v138 != 1 )
            return v8;
        }
        v8 = *(v55 - 10) - *(v56 - 10);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_234:
      if ( *(_DWORD *)(v55 - 9) == *(_DWORD *)(v56 - 9) )
      {
        v8 = 0;
      }
      else
      {
        v139 = *(v55 - 9) - *(v56 - 9);
        if ( v139 )
        {
          v140 = v139 > 0;
          v8 = 2 * v140 - 1;
          if ( 2 * v140 != 1 )
            return v8;
        }
        v141 = *(v55 - 8) - *(v56 - 8);
        if ( v141 )
        {
          v142 = v141 > 0;
          v8 = 2 * v142 - 1;
          if ( 2 * v142 != 1 )
            return v8;
        }
        v143 = *(v55 - 7) - *(v56 - 7);
        if ( v143 )
        {
          v144 = v143 > 0;
          v8 = 2 * v144 - 1;
          if ( 2 * v144 != 1 )
            return v8;
        }
        v8 = *(v55 - 6) - *(v56 - 6);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_245:
      v145 = *(_DWORD *)(v55 - 5);
      if ( v145 == *(_DWORD *)(v56 - 5) )
      {
        v8 = 0;
      }
      else
      {
        v146 = (unsigned __int8)v145 - *(v56 - 5);
        if ( v146 )
        {
          v147 = v146 > 0;
          v8 = 2 * v147 - 1;
          if ( 2 * v147 != 1 )
            return v8;
        }
        v148 = *(v55 - 4) - *(v56 - 4);
        if ( v148 )
        {
          v149 = v148 > 0;
          v8 = 2 * v149 - 1;
          if ( 2 * v149 != 1 )
            return v8;
        }
        v150 = *(v55 - 3) - *(v56 - 3);
        if ( v150 )
        {
          v151 = v150 > 0;
          v8 = 2 * v151 - 1;
          if ( 2 * v151 != 1 )
            return v8;
        }
        v8 = *(v55 - 2) - *(v56 - 2);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
      goto LABEL_256;
    case 0x1Eu:
      v152 = *(_DWORD *)(v55 - 30);
      if ( v152 == *(_DWORD *)(v56 - 30) )
      {
        v8 = 0;
      }
      else
      {
        v153 = (unsigned __int8)v152 - *(v56 - 30);
        if ( v153 )
        {
          v154 = v153 > 0;
          v8 = 2 * v154 - 1;
          if ( 2 * v154 != 1 )
            return v8;
        }
        v155 = *(v55 - 29) - *(v56 - 29);
        if ( v155 )
        {
          v156 = v155 > 0;
          v8 = 2 * v156 - 1;
          if ( 2 * v156 != 1 )
            return v8;
        }
        v157 = *(v55 - 28) - *(v56 - 28);
        if ( v157 )
        {
          v158 = v157 > 0;
          v8 = 2 * v158 - 1;
          if ( 2 * v158 != 1 )
            return v8;
        }
        v8 = *(v55 - 27) - *(v56 - 27);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_269:
      v159 = *(_DWORD *)(v55 - 26);
      if ( v159 == *(_DWORD *)(v56 - 26) )
      {
        v8 = 0;
      }
      else
      {
        v160 = (unsigned __int8)v159 - *(v56 - 26);
        if ( v160 )
        {
          v161 = v160 > 0;
          v8 = 2 * v161 - 1;
          if ( 2 * v161 != 1 )
            return v8;
        }
        v162 = *(v55 - 25) - *(v56 - 25);
        if ( v162 )
        {
          v163 = v162 > 0;
          v8 = 2 * v163 - 1;
          if ( 2 * v163 != 1 )
            return v8;
        }
        v164 = *(v55 - 24) - *(v56 - 24);
        if ( v164 )
        {
          v165 = v164 > 0;
          v8 = 2 * v165 - 1;
          if ( 2 * v165 != 1 )
            return v8;
        }
        v8 = *(v55 - 23) - *(v56 - 23);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_280:
      v166 = *(_DWORD *)(v55 - 22);
      if ( v166 == *(_DWORD *)(v56 - 22) )
      {
        v8 = 0;
      }
      else
      {
        v167 = (unsigned __int8)v166 - *(v56 - 22);
        if ( v167 )
        {
          v168 = v167 > 0;
          v8 = 2 * v168 - 1;
          if ( 2 * v168 != 1 )
            return v8;
        }
        v169 = *(v55 - 21) - *(v56 - 21);
        if ( v169 )
        {
          v170 = v169 > 0;
          v8 = 2 * v170 - 1;
          if ( 2 * v170 != 1 )
            return v8;
        }
        v171 = *(v55 - 20) - *(v56 - 20);
        if ( v171 )
        {
          v172 = v171 > 0;
          v8 = 2 * v172 - 1;
          if ( 2 * v172 != 1 )
            return v8;
        }
        v8 = *(v55 - 19) - *(v56 - 19);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_291:
      v173 = *(_DWORD *)(v55 - 18);
      if ( v173 == *(_DWORD *)(v56 - 18) )
      {
        v8 = 0;
      }
      else
      {
        v174 = (unsigned __int8)v173 - *(v56 - 18);
        if ( v174 )
        {
          v175 = v174 > 0;
          v8 = 2 * v175 - 1;
          if ( 2 * v175 != 1 )
            return v8;
        }
        v176 = *(v55 - 17) - *(v56 - 17);
        if ( v176 )
        {
          v177 = v176 > 0;
          v8 = 2 * v177 - 1;
          if ( 2 * v177 != 1 )
            return v8;
        }
        v178 = *(v55 - 16) - *(v56 - 16);
        if ( v178 )
        {
          v179 = v178 > 0;
          v8 = 2 * v179 - 1;
          if ( 2 * v179 != 1 )
            return v8;
        }
        v8 = *(v55 - 15) - *(v56 - 15);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_302:
      v180 = *(_DWORD *)(v55 - 14);
      if ( v180 == *(_DWORD *)(v56 - 14) )
      {
        v8 = 0;
      }
      else
      {
        v181 = (unsigned __int8)v180 - *(v56 - 14);
        if ( v181 )
        {
          v182 = v181 > 0;
          v8 = 2 * v182 - 1;
          if ( 2 * v182 != 1 )
            return v8;
        }
        v183 = *(v55 - 13) - *(v56 - 13);
        if ( v183 )
        {
          v184 = v183 > 0;
          v8 = 2 * v184 - 1;
          if ( 2 * v184 != 1 )
            return v8;
        }
        v185 = *(v55 - 12) - *(v56 - 12);
        if ( v185 )
        {
          v186 = v185 > 0;
          v8 = 2 * v186 - 1;
          if ( 2 * v186 != 1 )
            return v8;
        }
        v8 = *(v55 - 11) - *(v56 - 11);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_313:
      if ( *(_DWORD *)(v55 - 10) == *(_DWORD *)(v56 - 10) )
      {
        v8 = 0;
      }
      else
      {
        v187 = *(v55 - 10) - *(v56 - 10);
        if ( v187 )
        {
          v188 = v187 > 0;
          v8 = 2 * v188 - 1;
          if ( 2 * v188 != 1 )
            return v8;
        }
        v189 = *(v55 - 9) - *(v56 - 9);
        if ( v189 )
        {
          v190 = v189 > 0;
          v8 = 2 * v190 - 1;
          if ( 2 * v190 != 1 )
            return v8;
        }
        v191 = *(v55 - 8) - *(v56 - 8);
        if ( v191 )
        {
          v192 = v191 > 0;
          v8 = 2 * v192 - 1;
          if ( 2 * v192 != 1 )
            return v8;
        }
        v8 = *(v55 - 7) - *(v56 - 7);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_324:
      v193 = *(_DWORD *)(v55 - 6);
      if ( v193 == *(_DWORD *)(v56 - 6) )
      {
        v8 = 0;
      }
      else
      {
        v194 = (unsigned __int8)v193 - *(v56 - 6);
        if ( v194 )
        {
          v195 = v194 > 0;
          v8 = 2 * v195 - 1;
          if ( 2 * v195 != 1 )
            return v8;
        }
        v196 = *(v55 - 5) - *(v56 - 5);
        if ( v196 )
        {
          v197 = v196 > 0;
          v8 = 2 * v197 - 1;
          if ( 2 * v197 != 1 )
            return v8;
        }
        v198 = *(v55 - 4) - *(v56 - 4);
        if ( v198 )
        {
          v199 = v198 > 0;
          v8 = 2 * v199 - 1;
          if ( 2 * v199 != 1 )
            return v8;
        }
        v8 = *(v55 - 3) - *(v56 - 3);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_335:
      if ( *((_WORD *)v55 - 1) == *((_WORD *)v56 - 1) )
        return 0;
      goto LABEL_336;
    case 0x1Fu:
      if ( *(_DWORD *)(v55 - 31) == *(_DWORD *)(v56 - 31) )
      {
        v8 = 0;
      }
      else
      {
        v202 = *(v55 - 31) - *(v56 - 31);
        if ( v202 )
        {
          v203 = v202 > 0;
          v8 = 2 * v203 - 1;
          if ( 2 * v203 != 1 )
            return v8;
        }
        v204 = *(v55 - 30) - *(v56 - 30);
        if ( v204 )
        {
          v205 = v204 > 0;
          v8 = 2 * v205 - 1;
          if ( 2 * v205 != 1 )
            return v8;
        }
        v206 = *(v55 - 29) - *(v56 - 29);
        if ( v206 )
        {
          v207 = v206 > 0;
          v8 = 2 * v207 - 1;
          if ( 2 * v207 != 1 )
            return v8;
        }
        v8 = *(v55 - 28) - *(v56 - 28);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_350:
      v208 = *(_DWORD *)(v55 - 27);
      if ( v208 == *(_DWORD *)(v56 - 27) )
      {
        v8 = 0;
      }
      else
      {
        v209 = (unsigned __int8)v208 - *(v56 - 27);
        if ( v209 )
        {
          v210 = v209 > 0;
          v8 = 2 * v210 - 1;
          if ( 2 * v210 != 1 )
            return v8;
        }
        v211 = *(v55 - 26) - *(v56 - 26);
        if ( v211 )
        {
          v212 = v211 > 0;
          v8 = 2 * v212 - 1;
          if ( 2 * v212 != 1 )
            return v8;
        }
        v213 = *(v55 - 25) - *(v56 - 25);
        if ( v213 )
        {
          v214 = v213 > 0;
          v8 = 2 * v214 - 1;
          if ( 2 * v214 != 1 )
            return v8;
        }
        v8 = *(v55 - 24) - *(v56 - 24);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_361:
      v215 = *(_DWORD *)(v55 - 23);
      if ( v215 == *(_DWORD *)(v56 - 23) )
      {
        v8 = 0;
      }
      else
      {
        v216 = (unsigned __int8)v215 - *(v56 - 23);
        if ( v216 )
        {
          v217 = v216 > 0;
          v8 = 2 * v217 - 1;
          if ( 2 * v217 != 1 )
            return v8;
        }
        v218 = *(v55 - 22) - *(v56 - 22);
        if ( v218 )
        {
          v219 = v218 > 0;
          v8 = 2 * v219 - 1;
          if ( 2 * v219 != 1 )
            return v8;
        }
        v220 = *(v55 - 21) - *(v56 - 21);
        if ( v220 )
        {
          v221 = v220 > 0;
          v8 = 2 * v221 - 1;
          if ( 2 * v221 != 1 )
            return v8;
        }
        v8 = *(v55 - 20) - *(v56 - 20);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_372:
      v222 = *(_DWORD *)(v55 - 19);
      if ( v222 == *(_DWORD *)(v56 - 19) )
      {
        v8 = 0;
      }
      else
      {
        v223 = (unsigned __int8)v222 - *(v56 - 19);
        if ( v223 )
        {
          v224 = v223 > 0;
          v8 = 2 * v224 - 1;
          if ( 2 * v224 != 1 )
            return v8;
        }
        v225 = *(v55 - 18) - *(v56 - 18);
        if ( v225 )
        {
          v226 = v225 > 0;
          v8 = 2 * v226 - 1;
          if ( 2 * v226 != 1 )
            return v8;
        }
        v227 = *(v55 - 17) - *(v56 - 17);
        if ( v227 )
        {
          v228 = v227 > 0;
          v8 = 2 * v228 - 1;
          if ( 2 * v228 != 1 )
            return v8;
        }
        v8 = *(v55 - 16) - *(v56 - 16);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_383:
      if ( *(_DWORD *)(v55 - 15) == *(_DWORD *)(v56 - 15) )
      {
        v8 = 0;
      }
      else
      {
        v229 = *(v55 - 15) - *(v56 - 15);
        if ( v229 )
        {
          v230 = v229 > 0;
          v8 = 2 * v230 - 1;
          if ( 2 * v230 != 1 )
            return v8;
        }
        v231 = *(v55 - 14) - *(v56 - 14);
        if ( v231 )
        {
          v232 = v231 > 0;
          v8 = 2 * v232 - 1;
          if ( 2 * v232 != 1 )
            return v8;
        }
        v233 = *(v55 - 13) - *(v56 - 13);
        if ( v233 )
        {
          v234 = v233 > 0;
          v8 = 2 * v234 - 1;
          if ( 2 * v234 != 1 )
            return v8;
        }
        v8 = *(v55 - 12) - *(v56 - 12);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_394:
      v235 = *(_DWORD *)(v55 - 11);
      if ( v235 == *(_DWORD *)(v56 - 11) )
      {
        v8 = 0;
      }
      else
      {
        v236 = (unsigned __int8)v235 - *(v56 - 11);
        if ( v236 )
        {
          v237 = v236 > 0;
          v8 = 2 * v237 - 1;
          if ( 2 * v237 != 1 )
            return v8;
        }
        v238 = *(v55 - 10) - *(v56 - 10);
        if ( v238 )
        {
          v239 = v238 > 0;
          v8 = 2 * v239 - 1;
          if ( 2 * v239 != 1 )
            return v8;
        }
        v240 = *(v55 - 9) - *(v56 - 9);
        if ( v240 )
        {
          v241 = v240 > 0;
          v8 = 2 * v241 - 1;
          if ( 2 * v241 != 1 )
            return v8;
        }
        v8 = *(v55 - 8) - *(v56 - 8);
        if ( v8 )
          v8 = 2 * (v8 > 0) - 1;
      }
      if ( v8 )
        return v8;
LABEL_405:
      v242 = *(_DWORD *)(v55 - 7);
      if ( v242 != *(_DWORD *)(v56 - 7) )
      {
        v243 = (unsigned __int8)v242 - *(v56 - 7);
        if ( !v243 || (v244 = v243 > 0, v8 = 2 * v244 - 1, 2 * v244 == 1) )
        {
          v245 = *(v55 - 6) - *(v56 - 6);
          if ( !v245 || (v246 = v245 > 0, v8 = 2 * v246 - 1, 2 * v246 == 1) )
          {
            v247 = *(v55 - 5) - *(v56 - 5);
            if ( !v247 || (v248 = v247 > 0, v8 = 2 * v248 - 1, 2 * v248 == 1) )
            {
              v8 = *(v55 - 4) - *(v56 - 4);
              if ( v8 )
                v8 = 2 * (v8 > 0) - 1;
              goto LABEL_415;
            }
          }
        }
        return v8;
      }
      v8 = 0;
LABEL_415:
      if ( v8 )
        return v8;
LABEL_416:
      v249 = *(v55 - 3) - *(v56 - 3);
      if ( v249 )
      {
        v201 = 2 * (v249 > 0) - 1;
        if ( 2 * (v249 > 0) != 1 )
          return v201;
      }
LABEL_336:
      v200 = *(v55 - 2) - *(v56 - 2);
      if ( v200 )
      {
        v201 = 2 * (v200 > 0) - 1;
        if ( 2 * (v200 > 0) != 1 )
          return v201;
      }
LABEL_256:
      result = *(v55 - 1) - *(v56 - 1);
      if ( result )
        return 2 * (result > 0) - 1;
      return result;
    default:
      return 0;
  }
}
