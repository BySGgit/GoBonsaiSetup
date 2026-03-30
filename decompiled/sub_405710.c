void sub_405710()
{
  int v0; // eax
  int *v1; // ecx
  int v2; // edx
  int v3; // eax
  _DWORD *v4; // ecx
  void (*v5)(void); // eax
  int v6; // eax
  _DWORD *v7; // ecx
  void (*v8)(void); // eax
  int v9; // eax
  _DWORD *v10; // ecx
  void (*v11)(void); // eax
  int v12; // eax
  _DWORD *v13; // ecx
  void (*v14)(void); // eax
  int v15; // eax
  _DWORD *v16; // ecx
  void (*v17)(void); // eax
  int v18; // eax
  _DWORD *v19; // ecx
  void (*v20)(void); // eax
  int v21; // eax
  _DWORD *v22; // ecx
  void (*v23)(void); // eax
  int v24; // eax
  _DWORD *v25; // ecx
  void (*v26)(void); // eax
  int v27; // eax
  _DWORD *v28; // ecx
  void (*v29)(void); // eax
  int v30; // eax
  _DWORD *v31; // ecx
  void (*v32)(void); // eax
  int v33; // eax
  _DWORD *v34; // ecx
  void (*v35)(void); // eax
  int v36; // eax
  int v37; // ebx
  _DWORD *v38; // ecx
  void (*v39)(void); // eax
  int v40; // eax
  _DWORD *v41; // ecx
  void (*v42)(void); // eax
  int v43; // eax
  _DWORD *v44; // ecx
  void (*v45)(void); // eax
  int v46; // eax
  _DWORD *v47; // ecx
  void (*v48)(void); // eax
  int v49; // eax
  _DWORD *v50; // ecx
  void (*v51)(void); // eax
  int v52; // eax
  _DWORD *v53; // ecx
  void (*v54)(void); // eax
  int v55; // eax
  _DWORD *v56; // ecx
  void (*v57)(void); // eax
  int v58; // eax
  _DWORD *v59; // ecx
  void (*v60)(void); // eax
  int v61; // eax
  _DWORD *v62; // ecx
  void (*v63)(void); // eax
  int v64; // eax
  _DWORD *v65; // ecx
  void (*v66)(void); // eax
  int v67; // eax
  _DWORD *v68; // ecx
  void (*v69)(void); // eax
  int v70; // eax
  _DWORD *v71; // ecx
  void (*v72)(void); // eax
  int v73; // eax
  _DWORD *v74; // ecx
  void (*v75)(void); // eax
  int v76; // eax
  _DWORD *v77; // ecx
  void (*v78)(void); // eax
  int v79; // eax
  _DWORD *v80; // ecx
  void (*v81)(void); // eax
  int v82; // eax
  _DWORD *v83; // ecx
  void (*v84)(void); // eax
  int v85; // eax
  _DWORD *v86; // ecx
  void (*v87)(void); // eax
  int v88; // eax
  _DWORD *v89; // ecx
  void (*v90)(void); // eax
  int v91; // eax
  _DWORD *v92; // ecx
  void (*v93)(void); // eax
  int v94; // eax
  _DWORD *v95; // ecx
  void (*v96)(void); // eax
  int v97; // eax
  _DWORD *v98; // ecx
  void (*v99)(void); // eax
  int v100; // eax
  _DWORD *v101; // ecx
  void (*v102)(void); // eax
  int v103; // eax
  int v104; // ebp
  _DWORD *v105; // ecx
  void (*v106)(void); // eax
  int v107; // eax
  _DWORD *v108; // ecx
  void (*v109)(void); // eax
  int v110; // eax
  _DWORD *v111; // ecx
  void (*v112)(void); // eax
  int v113; // eax
  _DWORD *v114; // ecx
  void (*v115)(void); // eax
  int v116; // eax
  _DWORD *v117; // ecx
  void (*v118)(void); // eax
  int v119; // eax
  _DWORD *v120; // ecx
  void (*v121)(void); // eax
  int v122; // eax
  _DWORD *v123; // ecx
  void (*v124)(void); // eax
  int v125; // eax
  _DWORD *v126; // ecx
  void (*v127)(void); // eax
  int v128; // eax
  _DWORD *v129; // ecx
  void (*v130)(void); // eax
  int v131; // eax
  int *v132; // ecx
  int v133; // edx
  int v134; // eax
  int v135; // ebx
  int v136; // ebp
  _DWORD *v137; // ecx
  void (*v138)(void); // eax
  int v139; // eax
  int *v140; // ecx
  int v141; // edx
  int v142; // eax
  int v143; // ebx
  _DWORD *v144; // ecx
  void (*v145)(void); // eax
  int v146; // eax
  _DWORD *v147; // ecx
  void (*v148)(void); // eax
  int v149; // eax
  int v150; // ebx
  _DWORD *v151; // ecx
  void (*v152)(void); // eax
  int v153; // eax
  _DWORD *v154; // ecx
  void (*v155)(void); // eax
  int v156; // eax
  int v157; // ebx
  _DWORD *v158; // ecx
  void (*v159)(void); // eax
  int v160; // eax
  _DWORD *v161; // ecx
  void (*v162)(void); // eax
  int v163; // eax
  int *v164; // ecx
  int v165; // eax
  void (*v166)(void); // edx

  dword_4D61C8 = dword_4CA628;
  v0 = 0;
  dword_4D61C0 = 0;
  dword_4D61C4 = 0;
  dword_4D61CC = dword_4CA62C;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_4:
    v1 = 0;
  }
  else
  {
    while ( 1 )
    {
      v1 = *(int **)(dword_4D5F18 + 4 * v0);
      if ( v1[11] == 1 )
        break;
      if ( ++v0 >= dword_4D5F1C )
        goto LABEL_4;
    }
  }
  v2 = *v1;
  v1[2] = 10;
  v1[3] = 10;
  (*(void (**)(void))(v2 + 76))();
  v3 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_8:
    v4 = 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = *(_DWORD **)(dword_4D5F18 + 4 * v3);
      if ( v4[11] == 1 )
        break;
      if ( ++v3 >= dword_4D5F1C )
        goto LABEL_8;
    }
  }
  v5 = *(void (**)(void))(*v4 + 76);
  v4[4] = 200;
  v4[5] = 26;
  v5();
  v6 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_12:
    v7 = 0;
  }
  else
  {
    while ( 1 )
    {
      v7 = *(_DWORD **)(dword_4D5F18 + 4 * v6);
      if ( v7[11] == 2 )
        break;
      if ( ++v6 >= dword_4D5F1C )
        goto LABEL_12;
    }
  }
  v8 = *(void (**)(void))(*v7 + 76);
  v7[2] = 10;
  v7[3] = 36;
  v8();
  v9 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_16:
    v10 = 0;
  }
  else
  {
    while ( 1 )
    {
      v10 = *(_DWORD **)(dword_4D5F18 + 4 * v9);
      if ( v10[11] == 2 )
        break;
      if ( ++v9 >= dword_4D5F1C )
        goto LABEL_16;
    }
  }
  v11 = *(void (**)(void))(*v10 + 76);
  v10[4] = 200;
  v10[5] = 26;
  v11();
  v12 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_20:
    v13 = 0;
  }
  else
  {
    while ( 1 )
    {
      v13 = *(_DWORD **)(dword_4D5F18 + 4 * v12);
      if ( v13[11] == 3 )
        break;
      if ( ++v12 >= dword_4D5F1C )
        goto LABEL_20;
    }
  }
  v14 = *(void (**)(void))(*v13 + 76);
  v13[2] = 10;
  v13[3] = 62;
  v14();
  v15 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_24:
    v16 = 0;
  }
  else
  {
    while ( 1 )
    {
      v16 = *(_DWORD **)(dword_4D5F18 + 4 * v15);
      if ( v16[11] == 3 )
        break;
      if ( ++v15 >= dword_4D5F1C )
        goto LABEL_24;
    }
  }
  v17 = *(void (**)(void))(*v16 + 76);
  v16[4] = 200;
  v16[5] = 26;
  v17();
  v18 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_28:
    v19 = 0;
  }
  else
  {
    while ( 1 )
    {
      v19 = *(_DWORD **)(dword_4D5F18 + 4 * v18);
      if ( v19[11] == 4 )
        break;
      if ( ++v18 >= dword_4D5F1C )
        goto LABEL_28;
    }
  }
  v20 = *(void (**)(void))(*v19 + 76);
  v19[2] = 10;
  v19[3] = 88;
  v20();
  v21 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_32:
    v22 = 0;
  }
  else
  {
    while ( 1 )
    {
      v22 = *(_DWORD **)(dword_4D5F18 + 4 * v21);
      if ( v22[11] == 4 )
        break;
      if ( ++v21 >= dword_4D5F1C )
        goto LABEL_32;
    }
  }
  v23 = *(void (**)(void))(*v22 + 76);
  v22[4] = 200;
  v22[5] = 26;
  v23();
  v24 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_36:
    v25 = 0;
  }
  else
  {
    while ( 1 )
    {
      v25 = *(_DWORD **)(dword_4D5F18 + 4 * v24);
      if ( v25[11] == 5 )
        break;
      if ( ++v24 >= dword_4D5F1C )
        goto LABEL_36;
    }
  }
  v26 = *(void (**)(void))(*v25 + 76);
  v25[2] = 10;
  v25[3] = 114;
  v26();
  v27 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_40:
    v28 = 0;
  }
  else
  {
    while ( 1 )
    {
      v28 = *(_DWORD **)(dword_4D5F18 + 4 * v27);
      if ( v28[11] == 5 )
        break;
      if ( ++v27 >= dword_4D5F1C )
        goto LABEL_40;
    }
  }
  v29 = *(void (**)(void))(*v28 + 76);
  v28[4] = 200;
  v28[5] = 26;
  v29();
  v30 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_44:
    v31 = 0;
  }
  else
  {
    while ( 1 )
    {
      v31 = *(_DWORD **)(dword_4D5F18 + 4 * v30);
      if ( v31[11] == 6 )
        break;
      if ( ++v30 >= dword_4D5F1C )
        goto LABEL_44;
    }
  }
  v32 = *(void (**)(void))(*v31 + 76);
  v31[2] = 10;
  v31[3] = 140;
  v32();
  v33 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_48:
    v34 = 0;
  }
  else
  {
    while ( 1 )
    {
      v34 = *(_DWORD **)(dword_4D5F18 + 4 * v33);
      if ( v34[11] == 6 )
        break;
      if ( ++v33 >= dword_4D5F1C )
        goto LABEL_48;
    }
  }
  v35 = *(void (**)(void))(*v34 + 76);
  v34[4] = 200;
  v34[5] = 26;
  v35();
  v36 = 0;
  v37 = dword_4CA628 - 10;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_52:
    v38 = 0;
  }
  else
  {
    while ( 1 )
    {
      v38 = *(_DWORD **)(dword_4D5F18 + 4 * v36);
      if ( v38[11] == 10 )
        break;
      if ( ++v36 >= dword_4D5F1C )
        goto LABEL_52;
    }
  }
  v39 = *(void (**)(void))(*v38 + 76);
  v38[2] = v37;
  v38[3] = 10;
  v39();
  v40 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_56:
    v41 = 0;
  }
  else
  {
    while ( 1 )
    {
      v41 = *(_DWORD **)(dword_4D5F18 + 4 * v40);
      if ( v41[11] == 10 )
        break;
      if ( ++v40 >= dword_4D5F1C )
        goto LABEL_56;
    }
  }
  v42 = *(void (**)(void))(*v41 + 76);
  v41[4] = 0;
  v41[5] = 26;
  v42();
  v43 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_60:
    v44 = 0;
  }
  else
  {
    while ( 1 )
    {
      v44 = *(_DWORD **)(dword_4D5F18 + 4 * v43);
      if ( v44[11] == 7 )
        break;
      if ( ++v43 >= dword_4D5F1C )
        goto LABEL_60;
    }
  }
  v45 = *(void (**)(void))(*v44 + 76);
  v44[2] = v37;
  v44[3] = 36;
  v45();
  v46 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_64:
    v47 = 0;
  }
  else
  {
    while ( 1 )
    {
      v47 = *(_DWORD **)(dword_4D5F18 + 4 * v46);
      if ( v47[11] == 7 )
        break;
      if ( ++v46 >= dword_4D5F1C )
        goto LABEL_64;
    }
  }
  v48 = *(void (**)(void))(*v47 + 76);
  v47[4] = 0;
  v47[5] = 26;
  v48();
  v49 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_68:
    v50 = 0;
  }
  else
  {
    while ( 1 )
    {
      v50 = *(_DWORD **)(dword_4D5F18 + 4 * v49);
      if ( v50[11] == 8 )
        break;
      if ( ++v49 >= dword_4D5F1C )
        goto LABEL_68;
    }
  }
  v51 = *(void (**)(void))(*v50 + 76);
  v50[2] = v37;
  v50[3] = 62;
  v51();
  v52 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_72:
    v53 = 0;
  }
  else
  {
    while ( 1 )
    {
      v53 = *(_DWORD **)(dword_4D5F18 + 4 * v52);
      if ( v53[11] == 8 )
        break;
      if ( ++v52 >= dword_4D5F1C )
        goto LABEL_72;
    }
  }
  v54 = *(void (**)(void))(*v53 + 76);
  v53[4] = 0;
  v53[5] = 26;
  v54();
  v55 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_76:
    v56 = 0;
  }
  else
  {
    while ( 1 )
    {
      v56 = *(_DWORD **)(dword_4D5F18 + 4 * v55);
      if ( v56[11] == 9 )
        break;
      if ( ++v55 >= dword_4D5F1C )
        goto LABEL_76;
    }
  }
  v57 = *(void (**)(void))(*v56 + 76);
  v56[2] = v37;
  v56[3] = 88;
  v57();
  v58 = 0;
  if ( dword_4D5F1C <= 0 )
  {
LABEL_80:
    v59 = 0;
  }
  else
  {
    while ( 1 )
    {
      v59 = *(_DWORD **)(dword_4D5F18 + 4 * v58);
      if ( v59[11] == 9 )
        break;
      if ( ++v58 >= dword_4D5F1C )
        goto LABEL_80;
    }
  }
  v60 = *(void (**)(void))(*v59 + 76);
  v59[4] = 0;
  v59[5] = 26;
  v60();
  v61 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_84:
    v62 = 0;
  }
  else
  {
    while ( 1 )
    {
      v62 = *(_DWORD **)(dword_4D6208 + 4 * v61);
      if ( v62[11] == 21 )
        break;
      if ( ++v61 >= dword_4D620C )
        goto LABEL_84;
    }
  }
  v63 = *(void (**)(void))(*v62 + 76);
  v62[2] = 10;
  v62[3] = 182;
  v63();
  v64 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_88:
    v65 = 0;
  }
  else
  {
    while ( 1 )
    {
      v65 = *(_DWORD **)(dword_4D6208 + 4 * v64);
      if ( v65[11] == 21 )
        break;
      if ( ++v64 >= dword_4D620C )
        goto LABEL_88;
    }
  }
  v66 = *(void (**)(void))(*v65 + 76);
  v65[4] = 150;
  v65[5] = 26;
  v66();
  v67 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_92:
    v68 = 0;
  }
  else
  {
    while ( 1 )
    {
      v68 = *(_DWORD **)(dword_4D6208 + 4 * v67);
      if ( v68[11] == 22 )
        break;
      if ( ++v67 >= dword_4D620C )
        goto LABEL_92;
    }
  }
  v69 = *(void (**)(void))(*v68 + 76);
  v68[2] = 10;
  v68[3] = 208;
  v69();
  v70 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_96:
    v71 = 0;
  }
  else
  {
    while ( 1 )
    {
      v71 = *(_DWORD **)(dword_4D6208 + 4 * v70);
      if ( v71[11] == 22 )
        break;
      if ( ++v70 >= dword_4D620C )
        goto LABEL_96;
    }
  }
  v72 = *(void (**)(void))(*v71 + 76);
  v71[4] = 150;
  v71[5] = 26;
  v72();
  v73 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_100:
    v74 = 0;
  }
  else
  {
    while ( 1 )
    {
      v74 = *(_DWORD **)(dword_4D6208 + 4 * v73);
      if ( v74[11] == 23 )
        break;
      if ( ++v73 >= dword_4D620C )
        goto LABEL_100;
    }
  }
  v75 = *(void (**)(void))(*v74 + 76);
  v74[2] = 10;
  v74[3] = 234;
  v75();
  v76 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_104:
    v77 = 0;
  }
  else
  {
    while ( 1 )
    {
      v77 = *(_DWORD **)(dword_4D6208 + 4 * v76);
      if ( v77[11] == 23 )
        break;
      if ( ++v76 >= dword_4D620C )
        goto LABEL_104;
    }
  }
  v78 = *(void (**)(void))(*v77 + 76);
  v77[4] = 150;
  v77[5] = 26;
  v78();
  v79 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_108:
    v80 = 0;
  }
  else
  {
    while ( 1 )
    {
      v80 = *(_DWORD **)(dword_4D6208 + 4 * v79);
      if ( v80[11] == 24 )
        break;
      if ( ++v79 >= dword_4D620C )
        goto LABEL_108;
    }
  }
  v81 = *(void (**)(void))(*v80 + 76);
  v80[2] = 10;
  v80[3] = 260;
  v81();
  v82 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_112:
    v83 = 0;
  }
  else
  {
    while ( 1 )
    {
      v83 = *(_DWORD **)(dword_4D6208 + 4 * v82);
      if ( v83[11] == 24 )
        break;
      if ( ++v82 >= dword_4D620C )
        goto LABEL_112;
    }
  }
  v84 = *(void (**)(void))(*v83 + 76);
  v83[4] = 150;
  v83[5] = 26;
  v84();
  v85 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_116:
    v86 = 0;
  }
  else
  {
    while ( 1 )
    {
      v86 = *(_DWORD **)(dword_4D6208 + 4 * v85);
      if ( v86[11] == 25 )
        break;
      if ( ++v85 >= dword_4D620C )
        goto LABEL_116;
    }
  }
  v87 = *(void (**)(void))(*v86 + 76);
  v86[2] = 10;
  v86[3] = 286;
  v87();
  v88 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_120:
    v89 = 0;
  }
  else
  {
    while ( 1 )
    {
      v89 = *(_DWORD **)(dword_4D6208 + 4 * v88);
      if ( v89[11] == 25 )
        break;
      if ( ++v88 >= dword_4D620C )
        goto LABEL_120;
    }
  }
  v90 = *(void (**)(void))(*v89 + 76);
  v89[4] = 150;
  v89[5] = 26;
  v90();
  v91 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_124:
    v92 = 0;
  }
  else
  {
    while ( 1 )
    {
      v92 = *(_DWORD **)(dword_4D6208 + 4 * v91);
      if ( v92[11] == 26 )
        break;
      if ( ++v91 >= dword_4D620C )
        goto LABEL_124;
    }
  }
  v93 = *(void (**)(void))(*v92 + 76);
  v92[2] = 10;
  v92[3] = 312;
  v93();
  v94 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_128:
    v95 = 0;
  }
  else
  {
    while ( 1 )
    {
      v95 = *(_DWORD **)(dword_4D6208 + 4 * v94);
      if ( v95[11] == 26 )
        break;
      if ( ++v94 >= dword_4D620C )
        goto LABEL_128;
    }
  }
  v96 = *(void (**)(void))(*v95 + 76);
  v95[4] = 150;
  v95[5] = 26;
  v96();
  v97 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_132:
    v98 = 0;
  }
  else
  {
    while ( 1 )
    {
      v98 = *(_DWORD **)(dword_4D6208 + 4 * v97);
      if ( v98[11] == 19 )
        break;
      if ( ++v97 >= dword_4D620C )
        goto LABEL_132;
    }
  }
  v99 = *(void (**)(void))(*v98 + 76);
  v98[2] = 10;
  v98[3] = 338;
  v99();
  v100 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_136:
    v101 = 0;
  }
  else
  {
    while ( 1 )
    {
      v101 = *(_DWORD **)(dword_4D6208 + 4 * v100);
      if ( v101[11] == 19 )
        break;
      if ( ++v100 >= dword_4D620C )
        goto LABEL_136;
    }
  }
  v102 = *(void (**)(void))(*v101 + 76);
  v101[4] = 150;
  v101[5] = 26;
  v102();
  v103 = 0;
  v104 = dword_4CA62C - 62;
  if ( dword_4D620C <= 0 )
  {
LABEL_141:
    v105 = 0;
  }
  else
  {
    while ( 1 )
    {
      v105 = *(_DWORD **)(dword_4D6208 + 4 * v103);
      if ( v105[11] == 27 && !v105[12] )
        break;
      if ( ++v103 >= dword_4D620C )
        goto LABEL_141;
    }
  }
  v106 = *(void (**)(void))(*v105 + 76);
  v105[2] = 10;
  v105[3] = v104;
  v106();
  v107 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_146:
    v108 = 0;
  }
  else
  {
    while ( 1 )
    {
      v108 = *(_DWORD **)(dword_4D6208 + 4 * v107);
      if ( v108[11] == 27 && !v108[12] )
        break;
      if ( ++v107 >= dword_4D620C )
        goto LABEL_146;
    }
  }
  v109 = *(void (**)(void))(*v108 + 76);
  v108[4] = 52;
  v108[5] = 52;
  v109();
  v110 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_151:
    v111 = 0;
  }
  else
  {
    while ( 1 )
    {
      v111 = *(_DWORD **)(dword_4D6208 + 4 * v110);
      if ( v111[11] == 28 && !v111[12] )
        break;
      if ( ++v110 >= dword_4D620C )
        goto LABEL_151;
    }
  }
  v112 = *(void (**)(void))(*v111 + 76);
  v111[2] = 72;
  v111[3] = v104;
  v112();
  v113 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_156:
    v114 = 0;
  }
  else
  {
    while ( 1 )
    {
      v114 = *(_DWORD **)(dword_4D6208 + 4 * v113);
      if ( v114[11] == 28 && !v114[12] )
        break;
      if ( ++v113 >= dword_4D620C )
        goto LABEL_156;
    }
  }
  v115 = *(void (**)(void))(*v114 + 76);
  v114[4] = 52;
  v114[5] = 52;
  v115();
  v116 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_161:
    v117 = 0;
  }
  else
  {
    while ( 1 )
    {
      v117 = *(_DWORD **)(dword_4D6208 + 4 * v116);
      if ( v117[11] == 29 && !v117[12] )
        break;
      if ( ++v116 >= dword_4D620C )
        goto LABEL_161;
    }
  }
  v118 = *(void (**)(void))(*v117 + 76);
  v117[2] = 134;
  v117[3] = v104;
  v118();
  v119 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_166:
    v120 = 0;
  }
  else
  {
    while ( 1 )
    {
      v120 = *(_DWORD **)(dword_4D6208 + 4 * v119);
      if ( v120[11] == 29 && !v120[12] )
        break;
      if ( ++v119 >= dword_4D620C )
        goto LABEL_166;
    }
  }
  v121 = *(void (**)(void))(*v120 + 76);
  v120[4] = 52;
  v120[5] = 52;
  v121();
  v122 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_171:
    v123 = 0;
  }
  else
  {
    while ( 1 )
    {
      v123 = *(_DWORD **)(dword_4D6208 + 4 * v122);
      if ( v123[11] == 30 && !v123[12] )
        break;
      if ( ++v122 >= dword_4D620C )
        goto LABEL_171;
    }
  }
  v124 = *(void (**)(void))(*v123 + 76);
  v123[2] = 196;
  v123[3] = v104;
  v124();
  v125 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_176:
    v126 = 0;
  }
  else
  {
    while ( 1 )
    {
      v126 = *(_DWORD **)(dword_4D6208 + 4 * v125);
      if ( v126[11] == 30 && !v126[12] )
        break;
      if ( ++v125 >= dword_4D620C )
        goto LABEL_176;
    }
  }
  v127 = *(void (**)(void))(*v126 + 76);
  v126[4] = 52;
  v126[5] = 52;
  v127();
  v128 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_181:
    v129 = 0;
  }
  else
  {
    while ( 1 )
    {
      v129 = *(_DWORD **)(dword_4D6208 + 4 * v128);
      if ( v129[11] == 31 && !v129[12] )
        break;
      if ( ++v128 >= dword_4D620C )
        goto LABEL_181;
    }
  }
  v130 = *(void (**)(void))(*v129 + 76);
  v129[2] = 258;
  v129[3] = v104;
  v130();
  v131 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_186:
    v132 = 0;
  }
  else
  {
    while ( 1 )
    {
      v132 = *(int **)(dword_4D6208 + 4 * v131);
      if ( v132[11] == 31 && !v132[12] )
        break;
      if ( ++v131 >= dword_4D620C )
        goto LABEL_186;
    }
  }
  v133 = *v132;
  v132[4] = 52;
  v132[5] = 52;
  (*(void (**)(void))(v133 + 76))();
  v134 = 0;
  v135 = dword_4CA628 - 62;
  v136 = dword_4CA62C - 62;
  if ( dword_4D620C <= 0 )
  {
LABEL_190:
    v137 = 0;
  }
  else
  {
    while ( 1 )
    {
      v137 = *(_DWORD **)(dword_4D6208 + 4 * v134);
      if ( v137[11] == 18 )
        break;
      if ( ++v134 >= dword_4D620C )
        goto LABEL_190;
    }
  }
  v138 = *(void (**)(void))(*v137 + 76);
  v137[2] = v135;
  v137[3] = v136;
  v138();
  v139 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_194:
    v140 = 0;
  }
  else
  {
    while ( 1 )
    {
      v140 = *(int **)(dword_4D6208 + 4 * v139);
      if ( v140[11] == 18 )
        break;
      if ( ++v139 >= dword_4D620C )
        goto LABEL_194;
    }
  }
  v141 = *v140;
  v140[4] = 52;
  v140[5] = 52;
  (*(void (**)(void))(v141 + 76))();
  v142 = 0;
  v143 = v135 - 160;
  if ( dword_4D620C <= 0 )
  {
LABEL_198:
    v144 = 0;
  }
  else
  {
    while ( 1 )
    {
      v144 = *(_DWORD **)(dword_4D6208 + 4 * v142);
      if ( v144[11] == 15 )
        break;
      if ( ++v142 >= dword_4D620C )
        goto LABEL_198;
    }
  }
  v145 = *(void (**)(void))(*v144 + 76);
  v144[2] = v143;
  v144[3] = v136;
  v145();
  v146 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_202:
    v147 = 0;
  }
  else
  {
    while ( 1 )
    {
      v147 = *(_DWORD **)(dword_4D6208 + 4 * v146);
      if ( v147[11] == 15 )
        break;
      if ( ++v146 >= dword_4D620C )
        goto LABEL_202;
    }
  }
  v148 = *(void (**)(void))(*v147 + 76);
  v147[4] = 150;
  v147[5] = 52;
  v148();
  v149 = 0;
  v150 = v143 - 160;
  if ( dword_4D620C <= 0 )
  {
LABEL_206:
    v151 = 0;
  }
  else
  {
    while ( 1 )
    {
      v151 = *(_DWORD **)(dword_4D6208 + 4 * v149);
      if ( v151[11] == 16 )
        break;
      if ( ++v149 >= dword_4D620C )
        goto LABEL_206;
    }
  }
  v152 = *(void (**)(void))(*v151 + 76);
  v151[2] = v150;
  v151[3] = v136;
  v152();
  v153 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_210:
    v154 = 0;
  }
  else
  {
    while ( 1 )
    {
      v154 = *(_DWORD **)(dword_4D6208 + 4 * v153);
      if ( v154[11] == 16 )
        break;
      if ( ++v153 >= dword_4D620C )
        goto LABEL_210;
    }
  }
  v155 = *(void (**)(void))(*v154 + 76);
  v154[4] = 150;
  v154[5] = 52;
  v155();
  v156 = 0;
  v157 = v150 - 160;
  if ( dword_4D620C <= 0 )
  {
LABEL_214:
    v158 = 0;
  }
  else
  {
    while ( 1 )
    {
      v158 = *(_DWORD **)(dword_4D6208 + 4 * v156);
      if ( v158[11] == 17 )
        break;
      if ( ++v156 >= dword_4D620C )
        goto LABEL_214;
    }
  }
  v159 = *(void (**)(void))(*v158 + 76);
  v158[2] = v157;
  v158[3] = v136;
  v159();
  v160 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_218:
    v161 = 0;
  }
  else
  {
    while ( 1 )
    {
      v161 = *(_DWORD **)(dword_4D6208 + 4 * v160);
      if ( v161[11] == 17 )
        break;
      if ( ++v160 >= dword_4D620C )
        goto LABEL_218;
    }
  }
  v162 = *(void (**)(void))(*v161 + 76);
  v161[4] = 150;
  v161[5] = 52;
  v162();
  v163 = 0;
  if ( dword_4D620C <= 0 )
  {
LABEL_222:
    v164 = 0;
  }
  else
  {
    while ( 1 )
    {
      v164 = *(int **)(dword_4D6208 + 4 * v163);
      if ( v164[11] == 32 )
        break;
      if ( ++v163 >= dword_4D620C )
        goto LABEL_222;
    }
  }
  v165 = *v164;
  v164[2] = dword_4CA628 - 10;
  v166 = *(void (**)(void))(v165 + 76);
  v164[3] = v136 - 10;
  v166();
  sub_407060();
}
