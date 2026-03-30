int __cdecl _I10_OUTPUT(__int64 a1, __int16 a2, int a3, char a4, int a5)
{
  unsigned __int16 v5; // dx
  errno_t v7; // eax
  errno_t v8; // eax
  __int16 v9; // ax
  int v10; // ebx
  bool v11; // zf
  char v12; // cl
  int v13; // ecx
  char *v14; // eax
  int *v15; // esi
  __int16 v16; // cx
  unsigned __int16 v17; // di
  _WORD *v18; // esi
  unsigned int v19; // edx
  unsigned int v20; // ecx
  unsigned int v21; // eax
  __int16 v22; // di
  unsigned int v23; // ecx
  unsigned int v24; // edx
  int v25; // eax
  unsigned int v26; // ecx
  int v27; // esi
  int v28; // ecx
  unsigned __int16 v29; // si
  int v30; // eax
  _WORD *v31; // edi
  unsigned __int16 *v32; // eax
  unsigned int v33; // ecx
  unsigned int v34; // edx
  unsigned int v35; // ebx
  __int16 v36; // si
  unsigned int v37; // ecx
  unsigned int v38; // edx
  int v39; // eax
  unsigned int v40; // ecx
  int v41; // edi
  int v42; // ecx
  int v43; // edi
  int v44; // esi
  unsigned int v45; // eax
  int v46; // ebx
  int v47; // eax
  int v48; // esi
  int v49; // eax
  int v50; // ebx
  int v51; // eax
  _BYTE *v52; // ebx
  unsigned int v53; // edx
  unsigned int v54; // edi
  unsigned int v55; // ecx
  int v56; // esi
  int v57; // ecx
  unsigned int v58; // esi
  unsigned int v59; // edi
  int v60; // edx
  unsigned int v61; // edx
  char v62; // al
  _BYTE *v63; // ebx
  int v64; // eax
  char v65; // bl
  unsigned __int16 *v66; // [esp+10h] [ebp-70h]
  unsigned __int16 *v67; // [esp+14h] [ebp-6Ch]
  char *v68; // [esp+18h] [ebp-68h]
  __int16 v69; // [esp+20h] [ebp-60h]
  int v70; // [esp+24h] [ebp-5Ch]
  __int16 v71; // [esp+24h] [ebp-5Ch]
  __int16 v72; // [esp+28h] [ebp-58h]
  int *v73; // [esp+28h] [ebp-58h]
  int v74; // [esp+2Ch] [ebp-54h]
  int v75; // [esp+2Ch] [ebp-54h]
  int v76; // [esp+30h] [ebp-50h]
  int v77; // [esp+30h] [ebp-50h]
  __int16 v78; // [esp+34h] [ebp-4Ch]
  int k; // [esp+34h] [ebp-4Ch]
  int v80; // [esp+38h] [ebp-48h]
  int v81; // [esp+38h] [ebp-48h]
  char *v82; // [esp+3Ch] [ebp-44h]
  int v83; // [esp+3Ch] [ebp-44h]
  int v84; // [esp+3Ch] [ebp-44h]
  unsigned int v85; // [esp+3Ch] [ebp-44h]
  int i; // [esp+40h] [ebp-40h]
  int j; // [esp+40h] [ebp-40h]
  _BYTE *v88; // [esp+40h] [ebp-40h]
  __int64 v89; // [esp+44h] [ebp-3Ch] BYREF
  int v90; // [esp+4Ch] [ebp-34h]
  int v91; // [esp+50h] [ebp-30h]
  int v92; // [esp+54h] [ebp-2Ch]
  int v93; // [esp+58h] [ebp-28h] BYREF
  _BYTE v94[12]; // [esp+60h] [ebp-20h] BYREF
  _BYTE v95[12]; // [esp+70h] [ebp-10h] BYREF

  v69 = a2 & 0x8000;
  v5 = a2 & 0x7FFF;
  v91 = -858993460;
  v92 = -858993460;
  v93 = 1073466572;
  if ( a2 >= 0 )
    *(_BYTE *)(a5 + 2) = 32;
  else
    *(_BYTE *)(a5 + 2) = 45;
  if ( v5 )
  {
    if ( v5 != 0x7FFF )
      goto LABEL_25;
    *(_WORD *)a5 = 1;
    if ( a1 != 0x8000000000000000uLL && (a1 & 0x4000000000000000LL) == 0 )
    {
      v7 = strcpy_s((char *)(a5 + 4), 0x16u, "1#SNAN");
      goto LABEL_22;
    }
    if ( v69 && HIDWORD(a1) == -1073741824 )
    {
      if ( !(_DWORD)a1 )
      {
        v8 = strcpy_s((char *)(a5 + 4), 0x16u, "1#IND");
        goto LABEL_19;
      }
    }
    else if ( a1 == 0x8000000000000000uLL )
    {
      v8 = strcpy_s((char *)(a5 + 4), 0x16u, "1#INF");
LABEL_19:
      if ( !v8 )
      {
        *(_BYTE *)(a5 + 3) = 5;
        return 0;
      }
LABEL_12:
      _invoke_watson(0, 0, 0, 0, 0);
    }
    v7 = strcpy_s((char *)(a5 + 4), 0x16u, "1#QNAN");
LABEL_22:
    if ( !v7 )
    {
      *(_BYTE *)(a5 + 3) = 6;
      return 0;
    }
    goto LABEL_12;
  }
  if ( !a1 )
  {
    *(_WORD *)a5 = 0;
    *(_BYTE *)(a5 + 2) = v69 != -32768 ? 32 : 45;
    *(_WORD *)(a5 + 3) = 12289;
    *(_BYTE *)(a5 + 5) = 0;
    return 1;
  }
LABEL_25:
  v9 = (77 * (HIBYTE(v5) + 2 * HIBYTE(HIDWORD(a1))) + 19728 * (unsigned int)v5 - 323162868) >> 16;
  *(_WORD *)v94 = 0;
  v10 = -v9;
  v78 = v9;
  *(_WORD *)&v94[10] = a2 & 0x7FFF;
  *(_QWORD *)&v94[2] = a1;
  v68 = (char *)&unk_4CA1D0 - 96;
  if ( v9 )
  {
    v11 = v9 == 0;
    if ( v9 > 0 )
    {
      v10 = v9;
      v68 = (char *)&unk_4CA330 - 96;
      v11 = v9 == 0;
    }
    if ( !v11 )
    {
      do
      {
        v68 += 84;
        v12 = v10;
        v10 >>= 3;
        v13 = v12 & 7;
        if ( v13 )
        {
          v14 = &v68[12 * v13];
          v82 = v14;
          if ( *(_WORD *)v14 >= 0x8000u )
          {
            v89 = *(_QWORD *)v14;
            v15 = (int *)(v14 + 8);
            v14 = (char *)&v89;
            v90 = *v15;
            --*(_DWORD *)((char *)&v89 + 2);
            v82 = (char *)&v89;
          }
          v80 = 0;
          memset(v95, 0, sizeof(v95));
          v72 = (*(_WORD *)&v94[10] ^ *((_WORD *)v14 + 5)) & 0x8000;
          v16 = *((_WORD *)v14 + 5) & 0x7FFF;
          v17 = v16 + (*(_WORD *)&v94[10] & 0x7FFF);
          if ( (*(_WORD *)&v94[10] & 0x7FFF) == 0x7FFF || (*((_WORD *)v14 + 5) & 0x7FFF) == 0x7FFF || v17 > 0xBFFDu )
          {
            *(_DWORD *)&v94[8] = ((*(_WORD *)&v94[10] ^ *((_WORD *)v14 + 5)) & 0x8000u) == 0 ? 2147450880 : -32768;
          }
          else
          {
            if ( v17 > 0x3FBFu )
            {
              if ( (*(_WORD *)&v94[10] & 0x7FFF) == 0 )
              {
                ++v17;
                if ( (*(_DWORD *)&v94[8] & 0x7FFFFFFF) == 0 && !*(_DWORD *)&v94[4] && !*(_DWORD *)v94 )
                {
                  *(_WORD *)&v94[10] = 0;
                  continue;
                }
              }
              if ( v16 || (++v17, (*((_DWORD *)v14 + 2) & 0x7FFFFFFF) != 0) || *((_DWORD *)v14 + 1) || *(_DWORD *)v14 )
              {
                v74 = 0;
                v18 = &v95[4];
                for ( i = 5; i > 0; --i )
                {
                  v76 = i;
                  v66 = (unsigned __int16 *)&v94[2 * v74];
                  v67 = (unsigned __int16 *)(v14 + 8);
                  do
                  {
                    v19 = *((_DWORD *)v18 - 1);
                    v20 = *v67 * *v66;
                    v70 = 0;
                    v21 = v19 + v20;
                    if ( v19 + v20 < v19 || v21 < v20 )
                      v70 = 1;
                    *((_DWORD *)v18 - 1) = v21;
                    if ( v70 )
                      ++*v18;
                    ++v66;
                    --v67;
                    --v76;
                  }
                  while ( v76 > 0 );
                  v14 = v82;
                  ++v18;
                  ++v74;
                }
                v22 = v17 - 16382;
                if ( v22 <= 0 )
                  goto LABEL_169;
                do
                {
                  if ( *(int *)&v95[8] < 0 )
                    break;
                  v23 = *(_DWORD *)v95;
                  *(_DWORD *)v95 *= 2;
                  v24 = *(_DWORD *)&v95[4];
                  *(_DWORD *)&v95[4] = (v23 >> 31) | (2 * *(_DWORD *)&v95[4]);
                  --v22;
                  *(_DWORD *)&v95[8] = (v24 >> 31) | (2 * *(_DWORD *)&v95[8]);
                }
                while ( v22 > 0 );
                if ( v22 <= 0 )
                {
LABEL_169:
                  if ( --v22 < 0 )
                  {
                    v25 = (unsigned __int16)-v22;
                    v22 = 0;
                    do
                    {
                      if ( (v95[0] & 1) != 0 )
                        ++v80;
                      v26 = *(_DWORD *)&v95[8];
                      *(_DWORD *)&v95[8] >>= 1;
                      v27 = __SPAIR64__(v26, *(unsigned int *)&v95[4]) >> 1;
                      v28 = *(__int64 *)v95 >> 1;
                      --v25;
                      *(_DWORD *)&v95[4] = v27;
                      *(_DWORD *)v95 = v28;
                    }
                    while ( v25 );
                    if ( v80 )
                      *(_WORD *)v95 |= 1u;
                  }
                }
                if ( *(_WORD *)v95 > 0x8000u || (*(_DWORD *)v95 & 0x1FFFF) == 0x18000 )
                {
                  if ( *(_DWORD *)&v95[2] == -1 )
                  {
                    *(_DWORD *)&v95[2] = 0;
                    if ( *(_DWORD *)&v95[6] == -1 )
                    {
                      *(_DWORD *)&v95[6] = 0;
                      if ( *(_WORD *)&v95[10] == 0xFFFF )
                      {
                        *(_WORD *)&v95[10] = 0x8000;
                        ++v22;
                      }
                      else
                      {
                        ++*(_WORD *)&v95[10];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v95[6];
                    }
                  }
                  else
                  {
                    ++*(_DWORD *)&v95[2];
                  }
                }
                if ( (unsigned __int16)v22 < 0x7FFFu )
                {
                  *(_WORD *)v94 = *(_WORD *)&v95[2];
                  *(_DWORD *)&v94[2] = *(_DWORD *)&v95[4];
                  *(_DWORD *)&v94[6] = *(_DWORD *)&v95[8];
                  *(_WORD *)&v94[10] = v72 | v22;
                }
                else
                {
                  *(_DWORD *)&v94[4] = 0;
                  *(_DWORD *)v94 = 0;
                  *(_DWORD *)&v94[8] = v72 == 0 ? 2147450880 : -32768;
                }
                continue;
              }
            }
            *(_DWORD *)&v94[8] = 0;
          }
          *(_QWORD *)v94 = 0;
        }
      }
      while ( v10 );
    }
  }
  if ( *(_WORD *)&v94[10] < 0x3FFFu )
    goto LABEL_131;
  ++v78;
  v77 = 0;
  memset(v95, 0, sizeof(v95));
  v71 = (*(_WORD *)&v94[10] ^ HIWORD(v93)) & 0x8000;
  v29 = (HIWORD(v93) & 0x7FFF) + (*(_WORD *)&v94[10] & 0x7FFF);
  if ( (*(_WORD *)&v94[10] & 0x7FFF) == 0x7FFF || (HIWORD(v93) & 0x7FFF) == 0x7FFF || v29 > 0xBFFDu )
  {
    *(_DWORD *)&v94[4] = 0;
    v30 = ((*(_WORD *)&v94[10] ^ HIWORD(v93)) & 0x8000u) == 0 ? 2147450880 : -32768;
    *(_DWORD *)v94 = 0;
  }
  else
  {
    if ( v29 > 0x3FBFu )
    {
      v30 = 0;
      if ( (*(_WORD *)&v94[10] & 0x7FFF) == 0 )
      {
        ++v29;
        if ( (*(_DWORD *)&v94[8] & 0x7FFFFFFF) == 0 && !*(_DWORD *)&v94[4] && !*(_DWORD *)v94 )
        {
          *(_WORD *)&v94[10] = 0;
          goto LABEL_131;
        }
      }
      if ( (v93 & 0x7FFF0000) != 0 || (++v29, (v93 & 0x7FFFFFFF) != 0) || v92 || v91 )
      {
        v75 = 0;
        v31 = &v95[4];
        for ( j = 5; j > 0; --j )
        {
          v81 = j;
          v73 = &v93;
          v32 = (unsigned __int16 *)&v94[2 * v75];
          do
          {
            v83 = 0;
            v33 = *v32 * *(unsigned __int16 *)v73;
            v34 = *((_DWORD *)v31 - 1);
            v35 = v34 + v33;
            if ( v34 + v33 < v34 || v35 < v33 )
              v83 = 1;
            *((_DWORD *)v31 - 1) = v35;
            if ( v83 )
              ++*v31;
            v73 = (int *)((char *)v73 - 2);
            ++v32;
            --v81;
          }
          while ( v81 > 0 );
          ++v31;
          ++v75;
        }
        v36 = v29 - 16382;
        if ( v36 <= 0 )
          goto LABEL_170;
        do
        {
          if ( *(int *)&v95[8] < 0 )
            break;
          v37 = *(_DWORD *)v95;
          *(_DWORD *)v95 *= 2;
          v38 = *(_DWORD *)&v95[4];
          *(_DWORD *)&v95[4] = (v37 >> 31) | (2 * *(_DWORD *)&v95[4]);
          --v36;
          *(_DWORD *)&v95[8] = (v38 >> 31) | (2 * *(_DWORD *)&v95[8]);
        }
        while ( v36 > 0 );
        if ( v36 <= 0 )
        {
LABEL_170:
          if ( --v36 < 0 )
          {
            v39 = (unsigned __int16)-v36;
            v36 = 0;
            do
            {
              if ( (v95[0] & 1) != 0 )
                ++v77;
              v40 = *(_DWORD *)&v95[8];
              *(_DWORD *)&v95[8] >>= 1;
              v41 = __SPAIR64__(v40, *(unsigned int *)&v95[4]) >> 1;
              v42 = *(__int64 *)v95 >> 1;
              --v39;
              *(_DWORD *)&v95[4] = v41;
              *(_DWORD *)v95 = v42;
            }
            while ( v39 );
            if ( v77 )
              *(_WORD *)v95 |= 1u;
          }
        }
        if ( *(_WORD *)v95 > 0x8000u || (*(_DWORD *)v95 & 0x1FFFF) == 0x18000 )
        {
          if ( *(_DWORD *)&v95[2] == -1 )
          {
            *(_DWORD *)&v95[2] = 0;
            if ( *(_DWORD *)&v95[6] == -1 )
            {
              *(_DWORD *)&v95[6] = 0;
              if ( *(_WORD *)&v95[10] == 0xFFFF )
              {
                *(_WORD *)&v95[10] = 0x8000;
                ++v36;
              }
              else
              {
                ++*(_WORD *)&v95[10];
              }
            }
            else
            {
              ++*(_DWORD *)&v95[6];
            }
          }
          else
          {
            ++*(_DWORD *)&v95[2];
          }
        }
        if ( (unsigned __int16)v36 < 0x7FFFu )
        {
          *(_WORD *)v94 = *(_WORD *)&v95[2];
          *(_DWORD *)&v94[2] = *(_DWORD *)&v95[4];
          *(_DWORD *)&v94[6] = *(_DWORD *)&v95[8];
          *(_WORD *)&v94[10] = v71 | v36;
        }
        else
        {
          *(_DWORD *)&v94[4] = 0;
          *(_DWORD *)v94 = 0;
          *(_DWORD *)&v94[8] = v71 == 0 ? 2147450880 : -32768;
        }
        goto LABEL_131;
      }
    }
    else
    {
      v30 = 0;
    }
    *(_QWORD *)v94 = 0;
  }
  *(_DWORD *)&v94[8] = v30;
LABEL_131:
  v43 = a3;
  *(_WORD *)a5 = v78;
  if ( (a4 & 1) != 0 )
  {
    v43 = v78 + a3;
    if ( v43 <= 0 )
    {
      *(_WORD *)a5 = 0;
      *(_WORD *)(a5 + 3) = 12289;
      *(_BYTE *)(a5 + 2) = v69 != -32768 ? 32 : 45;
      *(_BYTE *)(a5 + 5) = 0;
      return 1;
    }
  }
  if ( v43 > 21 )
    v43 = 21;
  v44 = *(unsigned __int16 *)&v94[10] - 16382;
  *(_WORD *)&v94[10] = 0;
  v84 = 8;
  do
  {
    v45 = *(_DWORD *)v94;
    *(_DWORD *)v94 *= 2;
    v46 = (v45 >> 31) | (2 * *(_DWORD *)&v94[4]);
    v47 = *(__int64 *)&v94[4] >> 31;
    v11 = v84-- == 1;
    *(_DWORD *)&v94[4] = v46;
    *(_DWORD *)&v94[8] = v47;
  }
  while ( !v11 );
  if ( v44 < 0 )
  {
    v48 = (unsigned __int8)-(char)v44;
    if ( v48 )
    {
      do
      {
        v49 = *(_DWORD *)&v94[8];
        *(_DWORD *)&v94[8] >>= 1;
        v50 = (v49 << 31) | (*(_DWORD *)&v94[4] >> 1);
        v51 = *(__int64 *)v94 >> 1;
        --v48;
        *(_DWORD *)&v94[4] = v50;
        *(_DWORD *)v94 = v51;
      }
      while ( v48 > 0 );
    }
  }
  v52 = (_BYTE *)(a5 + 4);
  v88 = (_BYTE *)(a5 + 4);
  for ( k = v43 + 1; k > 0; v94[11] = 0 )
  {
    v53 = *(_DWORD *)v94;
    v89 = *(_QWORD *)v94;
    v90 = *(_DWORD *)&v94[8];
    *(_DWORD *)v94 *= 2;
    v54 = *(_DWORD *)v94;
    *(_DWORD *)v94 *= 2;
    v55 = __SPAIR64__(*(unsigned int *)&v94[4], v53) >> 31;
    v56 = 2 * v55;
    v57 = (v55 >> 31) | (2 * (*(__int64 *)&v94[4] >> 31));
    v58 = (v54 >> 31) | v56;
    v59 = v89 + *(_DWORD *)v94;
    if ( (unsigned int)(v89 + *(_DWORD *)v94) < *(_DWORD *)v94 || v59 < (unsigned int)v89 )
    {
      v60 = 0;
      if ( v58 + 1 < v58 || v58 == -1 )
        v60 = 1;
      ++v58;
      if ( v60 )
        ++v57;
    }
    v61 = HIDWORD(v89) + v58;
    v85 = HIDWORD(v89) + v58;
    if ( HIDWORD(v89) + v58 < v58 || v61 < HIDWORD(v89) )
      ++v57;
    *(_DWORD *)v94 = 2 * v59;
    *(_DWORD *)&v94[8] = (v61 >> 31) | (2 * (v90 + v57));
    *v52++ = v94[11] + 48;
    --k;
    *(_DWORD *)&v94[4] = (v59 >> 31) | (2 * v85);
  }
  v62 = *(v52 - 1);
  v63 = v52 - 2;
  if ( v62 >= 53 )
  {
    while ( v63 >= v88 && *v63 == 57 )
      *v63-- = 48;
    v64 = a5;
    if ( v63 < v88 )
    {
      ++v63;
      ++*(_WORD *)a5;
    }
    ++*v63;
  }
  else
  {
    while ( v63 >= v88 && *v63 == 48 )
      --v63;
    v64 = a5;
    if ( v63 < v88 )
    {
      *(_WORD *)a5 = 0;
      *(_BYTE *)(a5 + 3) = 1;
      *(_BYTE *)(a5 + 2) = v69 != -32768 ? 32 : 45;
      *v88 = 48;
      *(_BYTE *)(a5 + 5) = 0;
      return 1;
    }
  }
  v65 = (_BYTE)v63 - v64 - 3;
  *(_BYTE *)(v64 + 3) = v65;
  *(_BYTE *)(v65 + v64 + 4) = 0;
  return 1;
}
