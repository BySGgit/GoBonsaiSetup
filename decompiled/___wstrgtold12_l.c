int __cdecl __wstrgtold12_l(int a1, _DWORD *a2, _WORD *a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // ecx
  _WORD *v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  _WORD *v15; // edx
  _BYTE *v16; // ecx
  _BYTE *v17; // ecx
  int v18; // eax
  int v19; // eax
  bool v20; // zf
  int v21; // eax
  _BYTE *v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // eax
  char *v26; // ecx
  char v27; // al
  char *v28; // ecx
  int v29; // eax
  char *v30; // ebx
  __int16 v31; // ax
  __int16 v32; // si
  unsigned __int16 v33; // cx
  int v34; // eax
  _WORD *v35; // edi
  unsigned int v36; // eax
  unsigned int v37; // edx
  unsigned int v38; // esi
  __int16 v39; // cx
  unsigned int v40; // eax
  int v41; // esi
  int v42; // eax
  int v43; // esi
  int v44; // eax
  int v45; // edi
  int v46; // eax
  __int16 v47; // cx
  int v48; // esi
  unsigned int v49; // edx
  __int16 v50; // ax
  int v51; // [esp-Ch] [ebp-8Ch]
  int v52; // [esp-Ch] [ebp-8Ch]
  char *v53; // [esp+8h] [ebp-78h]
  __int16 v54; // [esp+Ch] [ebp-74h]
  int v55; // [esp+10h] [ebp-70h]
  int v56; // [esp+14h] [ebp-6Ch]
  unsigned __int16 *v57; // [esp+14h] [ebp-6Ch]
  int v58; // [esp+18h] [ebp-68h]
  int v59; // [esp+18h] [ebp-68h]
  int v60; // [esp+1Ch] [ebp-64h]
  int v61; // [esp+1Ch] [ebp-64h]
  int v62; // [esp+20h] [ebp-60h]
  unsigned __int16 *v63; // [esp+20h] [ebp-60h]
  int v64; // [esp+24h] [ebp-5Ch]
  int i; // [esp+24h] [ebp-5Ch]
  _BYTE *v66; // [esp+28h] [ebp-58h]
  int v67; // [esp+28h] [ebp-58h]
  _WORD *v68; // [esp+2Ch] [ebp-54h]
  int v69; // [esp+2Ch] [ebp-54h]
  int v70; // [esp+30h] [ebp-50h]
  int v71; // [esp+30h] [ebp-50h]
  unsigned int v72; // [esp+34h] [ebp-4Ch]
  __int16 v73; // [esp+34h] [ebp-4Ch]
  __int64 v74; // [esp+38h] [ebp-48h] BYREF
  int v75; // [esp+40h] [ebp-40h]
  _DWORD v76[7]; // [esp+44h] [ebp-3Ch] BYREF
  _BYTE v77[23]; // [esp+60h] [ebp-20h] BYREF
  char v78; // [esp+77h] [ebp-9h]

  v8 = 0;
  v66 = v77;
  v54 = 0;
  v60 = 1;
  v72 = 0;
  v64 = 0;
  v56 = 0;
  v62 = 0;
  v58 = 0;
  v70 = 0;
  v55 = 0;
  if ( !a8 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  v10 = a3;
  v68 = a3;
  while ( 1 )
  {
    v11 = (unsigned __int16)*v10;
    if ( v11 != 32 && v11 != 9 && v11 != 10 && v11 != 13 )
      break;
    ++v10;
  }
  while ( 2 )
  {
    v12 = (unsigned __int16)*v10++;
    switch ( v8 )
    {
      case 0:
        if ( (unsigned __int16)(v12 - 49) <= 8u )
          goto LABEL_11;
        if ( v12 == ***(char ***)(*(_DWORD *)a8 + 188) )
          goto LABEL_14;
        v13 = v12 - 43;
        if ( !v13 )
        {
          v54 = 0;
          v8 = 2;
          continue;
        }
        v14 = v13 - 2;
        if ( !v14 )
        {
          v8 = 2;
          v54 = 0x8000;
          continue;
        }
        if ( v14 != 3 )
          goto LABEL_74;
        goto LABEL_19;
      case 1:
        v64 = 1;
        if ( (unsigned __int16)(v12 - 49) <= 8u )
          goto LABEL_11;
        if ( v12 == ***(char ***)(*(_DWORD *)a8 + 188) )
          goto LABEL_24;
        if ( v12 == 43 || v12 == 45 )
          goto LABEL_32;
        if ( v12 == 48 )
          goto LABEL_19;
LABEL_28:
        if ( v12 <= 67 || v12 > 69 && (unsigned int)(v12 - 100) > 1 )
          goto LABEL_74;
        v52 = 6;
        goto LABEL_15;
      case 2:
        if ( (unsigned __int16)(v12 - 49) <= 8u )
        {
LABEL_11:
          v51 = 3;
LABEL_12:
          v8 = v51;
          --v10;
        }
        else
        {
          if ( v12 == ***(char ***)(*(_DWORD *)a8 + 188) )
          {
LABEL_14:
            v52 = 5;
            goto LABEL_15;
          }
          if ( v12 != 48 )
          {
LABEL_36:
            v15 = v68;
            goto LABEL_81;
          }
LABEL_19:
          v8 = 1;
        }
        continue;
      case 3:
        v64 = 1;
        while ( (unsigned __int16)v12 >= 0x30u && (unsigned __int16)v12 <= 0x39u )
        {
          if ( v72 >= 0x19 )
          {
            ++v70;
          }
          else
          {
            v16 = v66;
            ++v72;
            ++v66;
            *v16 = v12 - 48;
          }
          LOWORD(v12) = *v10++;
        }
        v12 = (unsigned __int16)v12;
        if ( (unsigned __int16)v12 != ***(char ***)(*(_DWORD *)a8 + 188) )
          goto LABEL_45;
LABEL_24:
        v52 = 4;
        goto LABEL_15;
      case 4:
        v64 = 1;
        v56 = 1;
        if ( !v72 )
        {
          while ( (_WORD)v12 == 48 )
          {
            --v70;
            LOWORD(v12) = *v10++;
          }
        }
        while ( (unsigned __int16)v12 >= 0x30u && (unsigned __int16)v12 <= 0x39u )
        {
          if ( v72 < 0x19 )
          {
            ++v72;
            v17 = v66++;
            --v70;
            *v17 = v12 - 48;
          }
          LOWORD(v12) = *v10++;
        }
        v12 = (unsigned __int16)v12;
LABEL_45:
        if ( v12 != 43 && v12 != 45 )
          goto LABEL_28;
LABEL_32:
        --v10;
        v52 = 11;
        goto LABEL_15;
      case 5:
        v56 = 1;
        if ( (unsigned __int16)(v12 - 48) > 9u )
          goto LABEL_36;
        v51 = 4;
        goto LABEL_12;
      case 6:
        v68 = v10 - 2;
        if ( (unsigned __int16)(v12 - 49) <= 8u )
          goto LABEL_62;
        v18 = v12 - 43;
        if ( !v18 )
          goto LABEL_69;
        v19 = v18 - 2;
        if ( !v19 )
          goto LABEL_68;
        v20 = v19 == 3;
LABEL_66:
        if ( !v20 )
          goto LABEL_36;
        v52 = 8;
        goto LABEL_15;
      case 7:
        if ( (unsigned __int16)(v12 - 49) <= 8u )
          goto LABEL_62;
        v20 = (_WORD)v12 == 48;
        goto LABEL_66;
      case 8:
        v62 = 1;
        while ( (_WORD)v12 == 48 )
          LOWORD(v12) = *v10++;
        if ( (unsigned __int16)(v12 - 49) > 8u )
          goto LABEL_74;
LABEL_62:
        v51 = 9;
        goto LABEL_12;
      case 9:
        v62 = 1;
        v23 = 0;
        while ( 2 )
        {
          if ( (unsigned __int16)v12 >= 0x30u && (unsigned __int16)v12 <= 0x39u )
          {
            v23 = 10 * v23 + (unsigned __int16)v12 - 48;
            if ( v23 <= 5200 )
            {
              LOWORD(v12) = *v10++;
              continue;
            }
            v23 = 5201;
          }
          break;
        }
        v58 = v23;
        while ( (unsigned __int16)v12 >= 0x30u && (unsigned __int16)v12 <= 0x39u )
          LOWORD(v12) = *v10++;
LABEL_74:
        v15 = v10 - 1;
        goto LABEL_81;
      case 11:
        if ( a7 )
        {
          v21 = v12 - 43;
          v68 = v10 - 1;
          if ( v21 )
          {
            if ( v21 != 2 )
            {
              v15 = v10 - 1;
              goto LABEL_81;
            }
LABEL_68:
            v60 = -1;
            v8 = 7;
          }
          else
          {
LABEL_69:
            v52 = 7;
LABEL_15:
            v8 = v52;
          }
          continue;
        }
        v15 = v10 - 1;
LABEL_81:
        *a2 = v15;
        if ( !v64 )
        {
          v55 = 4;
LABEL_177:
          v47 = 0;
          v50 = 0;
          v49 = 0;
          v48 = 0;
          goto LABEL_178;
        }
        if ( v72 <= 0x18 )
        {
          v22 = v66;
        }
        else
        {
          if ( v78 >= 5 )
            ++v78;
          v72 = 24;
          v22 = v66 - 1;
          ++v70;
        }
        if ( !v72 )
          goto LABEL_177;
        while ( !*--v22 )
        {
          --v72;
          ++v70;
        }
        __mtold12(v77, v72, v76);
        v24 = v58;
        if ( v60 < 0 )
          v24 = -v58;
        v25 = v70 + v24;
        if ( !v62 )
          v25 += a5;
        if ( !v56 )
          v25 -= a6;
        if ( v25 > 5200 )
        {
          v48 = 0;
          v50 = 0x7FFF;
          v49 = 0x80000000;
          v47 = 0;
          v55 = 2;
          goto LABEL_178;
        }
        if ( v25 < -5200 )
        {
          v55 = 1;
          goto LABEL_177;
        }
        v26 = (char *)&unk_4CA1D0 - 96;
        v69 = v25;
        if ( v25 )
        {
          if ( v25 < 0 )
          {
            v69 = -v25;
            v26 = (char *)&unk_4CA330 - 96;
          }
          if ( !a4 )
            LOWORD(v76[0]) = 0;
          if ( v69 )
          {
            while ( 1 )
            {
              v27 = v69;
              v69 >>= 3;
              v28 = v26 + 84;
              v29 = v27 & 7;
              v53 = v28;
              if ( !v29 )
                goto LABEL_172;
              v30 = &v28[12 * v29];
              if ( *(_WORD *)v30 >= 0x8000u )
              {
                v74 = *(_QWORD *)v30;
                v75 = *((_DWORD *)v30 + 2);
                --*(_DWORD *)((char *)&v74 + 2);
                v30 = (char *)&v74;
              }
              v67 = 0;
              memset(&v76[4], 0, 12);
              v31 = *((_WORD *)v30 + 5) & 0x7FFF;
              v32 = (HIWORD(v76[2]) ^ *((_WORD *)v30 + 5)) & 0x8000;
              v73 = v32;
              v33 = v31 + (HIWORD(v76[2]) & 0x7FFF);
              if ( (HIWORD(v76[2]) & 0x7FFF) == 0x7FFF || (*((_WORD *)v30 + 5) & 0x7FFF) == 0x7FFF || v33 > 0xBFFDu )
                break;
              if ( v33 <= 0x3FBFu )
              {
                v34 = 0;
                v76[1] = 0;
                v76[0] = 0;
LABEL_171:
                v76[2] = v34;
                goto LABEL_172;
              }
              if ( (v76[2] & 0x7FFF0000) != 0 || (++v33, (v76[2] & 0x7FFFFFFF) != 0) || v76[1] || v76[0] )
              {
                if ( v31 || (++v33, (*((_DWORD *)v30 + 2) & 0x7FFFFFFF) != 0) || *((_DWORD *)v30 + 1) || *(_DWORD *)v30 )
                {
                  v61 = 0;
                  v35 = &v76[5];
                  for ( i = 5; i > 0; --i )
                  {
                    v59 = i;
                    v57 = (unsigned __int16 *)v76 + v61;
                    v63 = (unsigned __int16 *)(v30 + 8);
                    do
                    {
                      v71 = 0;
                      v36 = *v63 * *v57;
                      v37 = *((_DWORD *)v35 - 1);
                      v38 = v37 + v36;
                      if ( v37 + v36 < v37 || v38 < v36 )
                        v71 = 1;
                      *((_DWORD *)v35 - 1) = v38;
                      if ( v71 )
                        ++*v35;
                      ++v57;
                      --v63;
                      --v59;
                    }
                    while ( v59 > 0 );
                    ++v35;
                    ++v61;
                  }
                  v39 = v33 - 16382;
                  if ( v39 <= 0 )
                    goto LABEL_181;
                  do
                  {
                    if ( v76[6] < 0 )
                      break;
                    v40 = v76[4];
                    v76[4] *= 2;
                    v41 = (v40 >> 31) | (2 * v76[5]);
                    v42 = *(__int64 *)&v76[5] >> 31;
                    --v39;
                    v76[5] = v41;
                    v76[6] = v42;
                  }
                  while ( v39 > 0 );
                  if ( v39 <= 0 )
                  {
LABEL_181:
                    if ( --v39 < 0 )
                    {
                      v43 = (unsigned __int16)-v39;
                      v39 = 0;
                      do
                      {
                        if ( (v76[4] & 1) != 0 )
                          ++v67;
                        v44 = v76[6];
                        v76[6] >>= 1;
                        v45 = (v44 << 31) | (v76[5] >> 1);
                        v46 = *(__int64 *)&v76[4] >> 1;
                        --v43;
                        v76[5] = v45;
                        v76[4] = v46;
                      }
                      while ( v43 );
                      if ( v67 )
                        LOWORD(v76[4]) |= 1u;
                    }
                  }
                  if ( LOWORD(v76[4]) > 0x8000u || (v76[4] & 0x1FFFF) == 0x18000 )
                  {
                    if ( *(_DWORD *)((char *)&v76[4] + 2) == -1 )
                    {
                      *(_DWORD *)((char *)&v76[4] + 2) = 0;
                      if ( *(_DWORD *)((char *)&v76[5] + 2) == -1 )
                      {
                        *(_DWORD *)((char *)&v76[5] + 2) = 0;
                        if ( HIWORD(v76[6]) == 0xFFFF )
                        {
                          HIWORD(v76[6]) = 0x8000;
                          ++v39;
                        }
                        else
                        {
                          ++HIWORD(v76[6]);
                        }
                      }
                      else
                      {
                        ++*(_DWORD *)((char *)&v76[5] + 2);
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)((char *)&v76[4] + 2);
                    }
                  }
                  if ( (unsigned __int16)v39 < 0x7FFFu )
                  {
                    LOWORD(v76[0]) = HIWORD(v76[4]);
                    *(_QWORD *)((char *)v76 + 2) = *(_QWORD *)&v76[5];
                    HIWORD(v76[2]) = v73 | v39;
                  }
                  else
                  {
                    v76[1] = 0;
                    v76[0] = 0;
                    v76[2] = v73 == 0 ? 2147450880 : -32768;
                  }
                }
                else
                {
                  memset(v76, 0, 12);
                }
              }
              else
              {
                HIWORD(v76[2]) = 0;
              }
LABEL_172:
              if ( !v69 )
                goto LABEL_173;
              v26 = v53;
            }
            v76[1] = 0;
            v34 = v32 == 0 ? 2147450880 : -32768;
            v76[0] = 0;
            goto LABEL_171;
          }
        }
LABEL_173:
        v47 = v76[0];
        v48 = *(_DWORD *)((char *)v76 + 2);
        v49 = *(_DWORD *)((char *)&v76[1] + 2);
        v50 = HIWORD(v76[2]);
LABEL_178:
        *(_DWORD *)(a1 + 2) = v48;
        *(_WORD *)(a1 + 10) = v54 | v50;
        *(_WORD *)a1 = v47;
        *(_DWORD *)(a1 + 6) = v49;
        return v55;
    }
  }
}
