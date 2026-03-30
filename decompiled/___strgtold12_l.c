int __cdecl __strgtold12_l(int a1, char **a2, char *a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // ecx
  _BYTE *v9; // edi
  char *v11; // edx
  char v12; // al
  char v13; // al
  int v14; // eax
  int v15; // eax
  char *v16; // edx
  int v17; // eax
  int v18; // eax
  bool v19; // zf
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  char *v24; // ecx
  char v25; // al
  char *v26; // ecx
  int v27; // eax
  char *v28; // ebx
  __int16 v29; // ax
  __int16 v30; // si
  unsigned __int16 v31; // cx
  int v32; // eax
  _WORD *v33; // edi
  unsigned int v34; // eax
  unsigned int v35; // edx
  unsigned int v36; // esi
  __int16 v37; // cx
  unsigned int v38; // eax
  int v39; // esi
  int v40; // eax
  int v41; // esi
  int v42; // eax
  int v43; // edi
  int v44; // eax
  __int16 v45; // cx
  int v46; // esi
  unsigned int v47; // edx
  __int16 v48; // ax
  int v49; // [esp-8h] [ebp-8Ch]
  int v50; // [esp-8h] [ebp-8Ch]
  char *v51; // [esp+8h] [ebp-7Ch]
  __int16 v52; // [esp+10h] [ebp-74h]
  __int16 v53; // [esp+14h] [ebp-70h]
  int v54; // [esp+18h] [ebp-6Ch]
  int v55; // [esp+1Ch] [ebp-68h]
  int v56; // [esp+1Ch] [ebp-68h]
  int v57; // [esp+20h] [ebp-64h]
  int v58; // [esp+20h] [ebp-64h]
  int v59; // [esp+24h] [ebp-60h]
  unsigned __int16 *v60; // [esp+24h] [ebp-60h]
  int v61; // [esp+28h] [ebp-5Ch]
  unsigned __int16 *v62; // [esp+28h] [ebp-5Ch]
  int v63; // [esp+2Ch] [ebp-58h]
  int i; // [esp+2Ch] [ebp-58h]
  char *v65; // [esp+30h] [ebp-54h]
  int v66; // [esp+30h] [ebp-54h]
  int v67; // [esp+34h] [ebp-50h]
  int v68; // [esp+34h] [ebp-50h]
  unsigned int v69; // [esp+38h] [ebp-4Ch]
  int v70; // [esp+38h] [ebp-4Ch]
  __int64 v71; // [esp+3Ch] [ebp-48h] BYREF
  int v72; // [esp+44h] [ebp-40h]
  _DWORD v73[7]; // [esp+48h] [ebp-3Ch] BYREF
  _BYTE v74[23]; // [esp+64h] [ebp-20h] BYREF
  char v75; // [esp+7Bh] [ebp-9h]

  v8 = 0;
  v9 = v74;
  v52 = 0;
  v55 = 1;
  v69 = 0;
  v63 = 0;
  v61 = 0;
  v59 = 0;
  v57 = 0;
  v67 = 0;
  v54 = 0;
  if ( !a8 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  v11 = a3;
  v65 = a3;
  while ( 1 )
  {
    v12 = *v11;
    if ( *v11 != 32 && v12 != 9 && v12 != 10 && v12 != 13 )
      break;
    ++v11;
  }
  while ( 2 )
  {
    v13 = *v11++;
    switch ( v8 )
    {
      case 0:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == ***(_BYTE ***)(*(_DWORD *)a8 + 188) )
          goto LABEL_14;
        v14 = v13 - 43;
        if ( !v14 )
        {
          v52 = 0;
          v8 = 2;
          continue;
        }
        v15 = v14 - 2;
        if ( !v15 )
        {
          v8 = 2;
          v52 = 0x8000;
          continue;
        }
        if ( v15 != 3 )
          goto LABEL_74;
        goto LABEL_19;
      case 1:
        v63 = 1;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == ***(_BYTE ***)(*(_DWORD *)a8 + 188) )
          goto LABEL_24;
        if ( v13 == 43 || v13 == 45 )
          goto LABEL_32;
        if ( v13 == 48 )
          goto LABEL_19;
LABEL_28:
        if ( v13 <= 67 || v13 > 69 && (unsigned __int8)(v13 - 100) > 1u )
          goto LABEL_74;
        v50 = 6;
        goto LABEL_15;
      case 2:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
        {
LABEL_11:
          v49 = 3;
LABEL_12:
          v8 = v49;
          --v11;
        }
        else
        {
          if ( v13 == ***(_BYTE ***)(*(_DWORD *)a8 + 188) )
          {
LABEL_14:
            v50 = 5;
            goto LABEL_15;
          }
          if ( v13 != 48 )
          {
LABEL_36:
            v16 = v65;
            goto LABEL_81;
          }
LABEL_19:
          v8 = 1;
        }
        continue;
      case 3:
        v63 = 1;
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( v69 >= 0x19 )
          {
            ++v67;
          }
          else
          {
            ++v69;
            *v9++ = v13 - 48;
          }
          v13 = *v11++;
        }
        if ( v13 != ***(_BYTE ***)(*(_DWORD *)a8 + 188) )
          goto LABEL_45;
LABEL_24:
        v50 = 4;
        goto LABEL_15;
      case 4:
        v63 = 1;
        v61 = 1;
        if ( !v69 )
        {
          while ( v13 == 48 )
          {
            --v67;
            v13 = *v11++;
          }
        }
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( v69 < 0x19 )
          {
            ++v69;
            *v9++ = v13 - 48;
            --v67;
          }
          v13 = *v11++;
        }
LABEL_45:
        if ( v13 != 43 && v13 != 45 )
          goto LABEL_28;
LABEL_32:
        --v11;
        v50 = 11;
        goto LABEL_15;
      case 5:
        v61 = 1;
        if ( (unsigned __int8)(v13 - 48) > 9u )
          goto LABEL_36;
        v49 = 4;
        goto LABEL_12;
      case 6:
        v65 = v11 - 2;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_62;
        v17 = v13 - 43;
        if ( !v17 )
          goto LABEL_69;
        v18 = v17 - 2;
        if ( !v18 )
          goto LABEL_68;
        v19 = v18 == 3;
LABEL_66:
        if ( !v19 )
          goto LABEL_36;
        v50 = 8;
        goto LABEL_15;
      case 7:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_62;
        v19 = v13 == 48;
        goto LABEL_66;
      case 8:
        v59 = 1;
        while ( v13 == 48 )
          v13 = *v11++;
        if ( (unsigned __int8)(v13 - 49) > 8u )
          goto LABEL_74;
LABEL_62:
        v49 = 9;
        goto LABEL_12;
      case 9:
        v59 = 1;
        v21 = 0;
        while ( 2 )
        {
          if ( v13 >= 48 && v13 <= 57 )
          {
            v21 = 10 * v21 + v13 - 48;
            if ( v21 <= 5200 )
            {
              v13 = *v11++;
              continue;
            }
            v21 = 5201;
          }
          break;
        }
        v57 = v21;
        while ( v13 >= 48 && v13 <= 57 )
          v13 = *v11++;
LABEL_74:
        v16 = v11 - 1;
        goto LABEL_81;
      case 11:
        if ( a7 )
        {
          v20 = v13 - 43;
          v65 = v11 - 1;
          if ( v20 )
          {
            if ( v20 != 2 )
            {
              v16 = v11 - 1;
              goto LABEL_81;
            }
LABEL_68:
            v55 = -1;
            v8 = 7;
          }
          else
          {
LABEL_69:
            v50 = 7;
LABEL_15:
            v8 = v50;
          }
          continue;
        }
        v16 = v11 - 1;
LABEL_81:
        *a2 = v16;
        if ( !v63 )
        {
          v54 = 4;
LABEL_176:
          v45 = 0;
          v48 = 0;
          v47 = 0;
          v46 = 0;
          goto LABEL_177;
        }
        if ( v69 > 0x18 )
        {
          if ( v75 >= 5 )
            ++v75;
          --v9;
          ++v67;
          v69 = 24;
        }
        if ( !v69 )
          goto LABEL_176;
        while ( !*--v9 )
        {
          --v69;
          ++v67;
        }
        __mtold12(v74, v69, v73);
        v22 = v57;
        if ( v55 < 0 )
          v22 = -v57;
        v23 = v67 + v22;
        if ( !v59 )
          v23 += a5;
        if ( !v61 )
          v23 -= a6;
        if ( v23 > 5200 )
        {
          v46 = 0;
          v48 = 0x7FFF;
          v47 = 0x80000000;
          v45 = 0;
          v54 = 2;
          goto LABEL_177;
        }
        if ( v23 < -5200 )
        {
          v54 = 1;
          goto LABEL_176;
        }
        v24 = (char *)&unk_4CA1D0 - 96;
        v66 = v23;
        if ( v23 )
        {
          if ( v23 < 0 )
          {
            v66 = -v23;
            v24 = (char *)&unk_4CA330 - 96;
          }
          if ( !a4 )
            LOWORD(v73[0]) = 0;
          if ( v66 )
          {
            while ( 1 )
            {
              v25 = v66;
              v66 >>= 3;
              v26 = v24 + 84;
              v27 = v25 & 7;
              v51 = v26;
              if ( !v27 )
                goto LABEL_171;
              v28 = &v26[12 * v27];
              if ( *(_WORD *)v28 >= 0x8000u )
              {
                v71 = *(_QWORD *)v28;
                v72 = *((_DWORD *)v28 + 2);
                --*(_DWORD *)((char *)&v71 + 2);
                v28 = (char *)&v71;
              }
              v68 = 0;
              memset(&v73[4], 0, 12);
              v29 = *((_WORD *)v28 + 5) & 0x7FFF;
              v30 = (HIWORD(v73[2]) ^ *((_WORD *)v28 + 5)) & 0x8000;
              v53 = v30;
              v31 = v29 + (HIWORD(v73[2]) & 0x7FFF);
              if ( (HIWORD(v73[2]) & 0x7FFF) == 0x7FFF || (*((_WORD *)v28 + 5) & 0x7FFF) == 0x7FFF || v31 > 0xBFFDu )
                break;
              if ( v31 <= 0x3FBFu )
              {
                v32 = 0;
                v73[1] = 0;
                v73[0] = 0;
LABEL_170:
                v73[2] = v32;
                goto LABEL_171;
              }
              if ( (v73[2] & 0x7FFF0000) != 0 || (++v31, (v73[2] & 0x7FFFFFFF) != 0) || v73[1] || v73[0] )
              {
                if ( v29 || (++v31, (*((_DWORD *)v28 + 2) & 0x7FFFFFFF) != 0) || *((_DWORD *)v28 + 1) || *(_DWORD *)v28 )
                {
                  v56 = 0;
                  v33 = &v73[5];
                  for ( i = 5; i > 0; --i )
                  {
                    v58 = i;
                    v62 = (unsigned __int16 *)v73 + v56;
                    v60 = (unsigned __int16 *)(v28 + 8);
                    do
                    {
                      v70 = 0;
                      v34 = *v62 * *v60;
                      v35 = *((_DWORD *)v33 - 1);
                      v36 = v35 + v34;
                      if ( v35 + v34 < v35 || v36 < v34 )
                        v70 = 1;
                      *((_DWORD *)v33 - 1) = v36;
                      if ( v70 )
                        ++*v33;
                      ++v62;
                      --v60;
                      --v58;
                    }
                    while ( v58 > 0 );
                    ++v33;
                    ++v56;
                  }
                  v37 = v31 - 16382;
                  if ( v37 <= 0 )
                    goto LABEL_180;
                  do
                  {
                    if ( v73[6] < 0 )
                      break;
                    v38 = v73[4];
                    v73[4] *= 2;
                    v39 = (v38 >> 31) | (2 * v73[5]);
                    v40 = *(__int64 *)&v73[5] >> 31;
                    --v37;
                    v73[5] = v39;
                    v73[6] = v40;
                  }
                  while ( v37 > 0 );
                  if ( v37 <= 0 )
                  {
LABEL_180:
                    if ( --v37 < 0 )
                    {
                      v41 = (unsigned __int16)-v37;
                      v37 = 0;
                      do
                      {
                        if ( (v73[4] & 1) != 0 )
                          ++v68;
                        v42 = v73[6];
                        v73[6] >>= 1;
                        v43 = (v42 << 31) | (v73[5] >> 1);
                        v44 = *(__int64 *)&v73[4] >> 1;
                        --v41;
                        v73[5] = v43;
                        v73[4] = v44;
                      }
                      while ( v41 );
                      if ( v68 )
                        LOWORD(v73[4]) |= 1u;
                    }
                  }
                  if ( LOWORD(v73[4]) > 0x8000u || (v73[4] & 0x1FFFF) == 0x18000 )
                  {
                    if ( *(_DWORD *)((char *)&v73[4] + 2) == -1 )
                    {
                      *(_DWORD *)((char *)&v73[4] + 2) = 0;
                      if ( *(_DWORD *)((char *)&v73[5] + 2) == -1 )
                      {
                        *(_DWORD *)((char *)&v73[5] + 2) = 0;
                        if ( HIWORD(v73[6]) == 0xFFFF )
                        {
                          HIWORD(v73[6]) = 0x8000;
                          ++v37;
                        }
                        else
                        {
                          ++HIWORD(v73[6]);
                        }
                      }
                      else
                      {
                        ++*(_DWORD *)((char *)&v73[5] + 2);
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)((char *)&v73[4] + 2);
                    }
                  }
                  if ( (unsigned __int16)v37 < 0x7FFFu )
                  {
                    LOWORD(v73[0]) = HIWORD(v73[4]);
                    *(_QWORD *)((char *)v73 + 2) = *(_QWORD *)&v73[5];
                    HIWORD(v73[2]) = v53 | v37;
                  }
                  else
                  {
                    v73[1] = 0;
                    v73[0] = 0;
                    v73[2] = v53 == 0 ? 2147450880 : -32768;
                  }
                }
                else
                {
                  memset(v73, 0, 12);
                }
              }
              else
              {
                HIWORD(v73[2]) = 0;
              }
LABEL_171:
              if ( !v66 )
                goto LABEL_172;
              v24 = v51;
            }
            v73[1] = 0;
            v32 = v30 == 0 ? 2147450880 : -32768;
            v73[0] = 0;
            goto LABEL_170;
          }
        }
LABEL_172:
        v45 = v73[0];
        v46 = *(_DWORD *)((char *)v73 + 2);
        v47 = *(_DWORD *)((char *)&v73[1] + 2);
        v48 = HIWORD(v73[2]);
LABEL_177:
        *(_WORD *)a1 = v45;
        *(_WORD *)(a1 + 10) = v52 | v48;
        *(_DWORD *)(a1 + 2) = v46;
        *(_DWORD *)(a1 + 6) = v47;
        return v54;
    }
  }
}
