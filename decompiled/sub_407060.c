void sub_407060()
{
  char *v0; // eax
  char *v1; // esi
  int v2; // ebp
  char *v3; // eax
  int v4; // ebx
  int v5; // edx
  int v6; // ecx
  int *v7; // eax
  int v8; // esi
  double v9; // st7
  double v10; // st6
  int v11; // ecx
  int **v12; // eax
  int *v13; // esi
  int v14; // eax
  int v15; // edx
  int v16; // eax
  void (__stdcall *v17)(int, int, int *, _DWORD); // ecx
  int v18; // esi
  int v19; // edx
  int v20; // eax
  _DWORD *v21; // ecx
  void (*v22)(void); // eax
  int v23; // esi
  int v24; // eax
  int v25; // edx
  _DWORD *v26; // ecx
  void (*v27)(void); // eax
  int v28; // esi
  int v29; // eax
  int v30; // edx
  _DWORD *v31; // ecx
  void (*v32)(void); // eax
  int v33; // esi
  int v34; // eax
  int v35; // edx
  _DWORD *v36; // ecx
  void (*v37)(void); // eax
  int v38; // edx
  int v39; // eax
  int *v40; // ecx
  int v41; // esi
  int v42; // esi
  int v43; // edx
  int v44; // eax
  _DWORD *v45; // ecx
  void (*v46)(void); // edx
  int v47; // esi
  int v48; // eax
  int v49; // edx
  _DWORD *v50; // ecx
  void (*v51)(void); // edx
  int v52; // edx
  int v53; // eax
  int *v54; // ecx
  int v55; // esi
  int v56; // esi
  int v57; // eax
  int v58; // edx
  _DWORD *v59; // ecx
  void (*v60)(void); // edx
  int v61; // esi
  int v62; // eax
  int v63; // edx
  _DWORD *v64; // ecx
  void (*v65)(void); // edx
  int v66; // edx
  int v67; // eax
  int *v68; // ecx
  int v69; // esi
  float v70; // [esp+14h] [ebp-40h]
  int v71; // [esp+18h] [ebp-3Ch]
  char *i; // [esp+1Ch] [ebp-38h]
  char *v73; // [esp+20h] [ebp-34h] BYREF
  int v74; // [esp+24h] [ebp-30h]
  char *v75; // [esp+28h] [ebp-2Ch] BYREF
  _DWORD pExceptionObject[3]; // [esp+2Ch] [ebp-28h] BYREF
  _DWORD v77[4]; // [esp+38h] [ebp-1Ch] BYREF
  int v78; // [esp+50h] [ebp-4h]

  v71 = 180;
  if ( (dword_4D8E14 & 1) == 0 )
  {
    dword_4D8E14 |= 1u;
    v78 = 0;
    dword_4D8E0C = 0;
    v0 = (char *)operator new(0xCu);
    if ( !v0 )
    {
      v73 = 0;
      std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&v73);
      pExceptionObject[0] = &std::bad_alloc::`vftable';
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
    }
    dword_4D8E08 = v0;
    *(_DWORD *)v0 = v0;
    *((_DWORD *)dword_4D8E08 + 1) = dword_4D8E08;
    atexit(sub_472020);
    v78 = -1;
  }
  v1 = *(char **)dword_4D8E08;
  v2 = dword_4D7E54;
  for ( i = *(char **)dword_4D8E08; ; v1 = i )
  {
    if ( (dword_4D8E14 & 1) == 0 )
    {
      dword_4D8E14 |= 1u;
      v78 = 1;
      dword_4D8E0C = 0;
      v3 = (char *)operator new(0xCu);
      if ( !v3 )
      {
        v75 = 0;
        std::exception::exception((std::exception *)v77, (const char *const *)&v75);
        v77[0] = &std::bad_alloc::`vftable';
        _CxxThrowException(v77, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
      }
      dword_4D8E08 = v3;
      *(_DWORD *)v3 = v3;
      *((_DWORD *)dword_4D8E08 + 1) = dword_4D8E08;
      atexit(sub_472020);
      v78 = -1;
      v2 = dword_4D7E54;
    }
    if ( v1 == dword_4D8E08 )
      break;
    v4 = *((_DWORD *)v1 + 2);
    if ( *(_BYTE *)(v4 + 532) )
    {
      v5 = *(_DWORD *)(v2 + 612);
      v6 = 0;
      if ( v5 <= 0 )
      {
LABEL_14:
        v8 = 0;
      }
      else
      {
        v7 = *(int **)(v2 + 608);
        while ( 1 )
        {
          v8 = *v7;
          if ( *(_DWORD *)(*v7 + 44) == *(_DWORD *)(v4 + 524) )
            break;
          ++v6;
          ++v7;
          if ( v6 >= v5 )
            goto LABEL_14;
        }
      }
      v9 = **(float **)v4 - *(float *)(v4 + 8);
      v10 = *(float *)(v4 + 4) - *(float *)(v4 + 8);
      v74 = *(_DWORD *)(v8 + 88) - *(_DWORD *)(v8 + 84);
      v70 = v9 / v10;
      if ( v70 >= 0.0 )
      {
        if ( v70 > 1.0 )
          v70 = 1.0;
      }
      else
      {
        v70 = 0.0;
      }
      v11 = 0;
      if ( v5 <= 0 )
      {
LABEL_24:
        v13 = 0;
      }
      else
      {
        v12 = *(int ***)(v2 + 608);
        while ( 1 )
        {
          v13 = *v12;
          if ( (*v12)[11] == *(_DWORD *)(v4 + 524) )
            break;
          ++v11;
          ++v12;
          if ( v11 >= v5 )
            goto LABEL_24;
        }
      }
      v14 = (int)((double)v74 * v70);
      if ( v13[21] > v14 )
        v14 = v13[21];
      if ( v13[22] < v14 )
        v14 = v13[22];
      if ( v14 != v13[20] )
      {
        v15 = *v13;
        v13[20] = v14;
        (*(void (__thiscall **)(int *))(v15 + 76))(v13);
        v16 = v13[6];
        v17 = *(void (__stdcall **)(int, int, int *, _DWORD))(v16 + 576);
        if ( v17 )
        {
          if ( *(_BYTE *)v16 )
            v17(1281, v13[11], v13, *(_DWORD *)(v16 + 580));
        }
        v2 = dword_4D7E54;
      }
      v18 = *(_DWORD *)(v2 + 612);
      v19 = 0;
      if ( v18 <= 0 )
      {
LABEL_38:
        v21 = 0;
      }
      else
      {
        v20 = *(_DWORD *)(v2 + 608);
        while ( 1 )
        {
          v21 = *(_DWORD **)v20;
          if ( *(_DWORD *)(*(_DWORD *)v20 + 44) == *(_DWORD *)(v4 + 524) )
            break;
          ++v19;
          v20 += 4;
          if ( v19 >= v18 )
            goto LABEL_38;
        }
      }
      v22 = *(void (**)(void))(*v21 + 76);
      v21[2] = 10;
      v21[3] = v71;
      v22();
      v23 = *(_DWORD *)(dword_4D7E54 + 612);
      v24 = 0;
      if ( v23 <= 0 )
      {
LABEL_43:
        v26 = 0;
      }
      else
      {
        v25 = *(_DWORD *)(dword_4D7E54 + 608);
        while ( 1 )
        {
          v26 = *(_DWORD **)v25;
          if ( *(_DWORD *)(*(_DWORD *)v25 + 44) == *(_DWORD *)(v4 + 524) )
            break;
          ++v24;
          v25 += 4;
          if ( v24 >= v23 )
            goto LABEL_43;
        }
      }
      v27 = *(void (**)(void))(*v26 + 76);
      v26[4] = 200;
      v26[5] = 25;
      v27();
      v28 = *(_DWORD *)(dword_4D7E54 + 612);
      v29 = 0;
      if ( v28 <= 0 )
      {
LABEL_48:
        v31 = 0;
      }
      else
      {
        v30 = *(_DWORD *)(dword_4D7E54 + 608);
        while ( 1 )
        {
          v31 = *(_DWORD **)v30;
          if ( *(_DWORD *)(*(_DWORD *)v30 + 44) == *(_DWORD *)(v4 + 528) )
            break;
          ++v29;
          v30 += 4;
          if ( v29 >= v28 )
            goto LABEL_48;
        }
      }
      v32 = *(void (**)(void))(*v31 + 76);
      v31[2] = 220;
      v31[3] = v71;
      v32();
      v33 = *(_DWORD *)(dword_4D7E54 + 612);
      v34 = 0;
      if ( v33 <= 0 )
      {
LABEL_53:
        v36 = 0;
      }
      else
      {
        v35 = *(_DWORD *)(dword_4D7E54 + 608);
        while ( 1 )
        {
          v36 = *(_DWORD **)v35;
          if ( *(_DWORD *)(*(_DWORD *)v35 + 44) == *(_DWORD *)(v4 + 528) )
            break;
          ++v34;
          v35 += 4;
          if ( v34 >= v33 )
            goto LABEL_53;
        }
      }
      v37 = *(void (**)(void))(*v36 + 76);
      v36[4] = 300;
      v36[5] = 25;
      v37();
      v2 = dword_4D7E54;
      v38 = *(_DWORD *)(dword_4D7E54 + 612);
      v39 = 0;
      if ( v38 <= 0 )
      {
LABEL_58:
        v41 = 0;
      }
      else
      {
        v40 = *(int **)(dword_4D7E54 + 608);
        while ( 1 )
        {
          v41 = *v40;
          if ( *(_DWORD *)(*v40 + 44) == *(_DWORD *)(v4 + 528) )
            break;
          ++v39;
          ++v40;
          if ( v39 >= v38 )
            goto LABEL_58;
        }
      }
      *(_DWORD *)(**(_DWORD **)(v41 + 32) + 8) = 16;
    }
    else
    {
      v42 = *(_DWORD *)(v2 + 612);
      v43 = 0;
      if ( v42 <= 0 )
      {
LABEL_64:
        v45 = 0;
      }
      else
      {
        v44 = *(_DWORD *)(v2 + 608);
        while ( 1 )
        {
          v45 = *(_DWORD **)v44;
          if ( *(_DWORD *)(*(_DWORD *)v44 + 44) == *(_DWORD *)(v4 + 524) )
            break;
          ++v43;
          v44 += 4;
          if ( v43 >= v42 )
            goto LABEL_64;
        }
      }
      v46 = *(void (**)(void))(*v45 + 76);
      v45[2] = 10;
      v45[3] = v71;
      v46();
      v47 = *(_DWORD *)(dword_4D7E54 + 612);
      v48 = 0;
      if ( v47 <= 0 )
      {
LABEL_69:
        v50 = 0;
      }
      else
      {
        v49 = *(_DWORD *)(dword_4D7E54 + 608);
        while ( 1 )
        {
          v50 = *(_DWORD **)v49;
          if ( *(_DWORD *)(*(_DWORD *)v49 + 44) == *(_DWORD *)(v4 + 524) )
            break;
          ++v48;
          v49 += 4;
          if ( v48 >= v47 )
            goto LABEL_69;
        }
      }
      v51 = *(void (**)(void))(*v50 + 76);
      v50[4] = 150;
      v50[5] = 25;
      v51();
      v52 = *(_DWORD *)(dword_4D7E54 + 612);
      v53 = 0;
      if ( v52 <= 0 )
      {
LABEL_74:
        v55 = 0;
      }
      else
      {
        v54 = *(int **)(dword_4D7E54 + 608);
        while ( 1 )
        {
          v55 = *v54;
          if ( *(_DWORD *)(*v54 + 44) == *(_DWORD *)(v4 + 524) )
            break;
          ++v53;
          ++v54;
          if ( v53 >= v52 )
            goto LABEL_74;
        }
      }
      sub_436890(*(float **)v4, v55);
      v56 = *(_DWORD *)(dword_4D7E54 + 612);
      v57 = 0;
      if ( v56 <= 0 )
      {
LABEL_79:
        v59 = 0;
      }
      else
      {
        v58 = *(_DWORD *)(dword_4D7E54 + 608);
        while ( 1 )
        {
          v59 = *(_DWORD **)v58;
          if ( *(_DWORD *)(*(_DWORD *)v58 + 44) == *(_DWORD *)(v4 + 528) )
            break;
          ++v57;
          v58 += 4;
          if ( v57 >= v56 )
            goto LABEL_79;
        }
      }
      v60 = *(void (**)(void))(*v59 + 76);
      v59[2] = 170;
      v59[3] = v71;
      v60();
      v61 = *(_DWORD *)(dword_4D7E54 + 612);
      v62 = 0;
      if ( v61 <= 0 )
      {
LABEL_84:
        v64 = 0;
      }
      else
      {
        v63 = *(_DWORD *)(dword_4D7E54 + 608);
        while ( 1 )
        {
          v64 = *(_DWORD **)v63;
          if ( *(_DWORD *)(*(_DWORD *)v63 + 44) == *(_DWORD *)(v4 + 528) )
            break;
          ++v62;
          v63 += 4;
          if ( v62 >= v61 )
            goto LABEL_84;
        }
      }
      v65 = *(void (**)(void))(*v64 + 76);
      v64[4] = 300;
      v64[5] = 25;
      v65();
      v2 = dword_4D7E54;
      v66 = *(_DWORD *)(dword_4D7E54 + 612);
      v67 = 0;
      if ( v66 <= 0 )
      {
LABEL_89:
        v69 = 0;
      }
      else
      {
        v68 = *(int **)(dword_4D7E54 + 608);
        while ( 1 )
        {
          v69 = *v68;
          if ( *(_DWORD *)(*v68 + 44) == *(_DWORD *)(v4 + 528) )
            break;
          ++v67;
          ++v68;
          if ( v67 >= v66 )
            goto LABEL_89;
        }
      }
      *(_DWORD *)(**(_DWORD **)(v69 + 32) + 8) = 16;
    }
    v71 += 27;
    i = *(char **)i;
  }
}
