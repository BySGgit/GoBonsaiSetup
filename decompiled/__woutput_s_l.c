int __cdecl _woutput_s_l(int a1, unsigned __int16 *a2, struct localeinfo_struct *a3, unsigned __int16 *a4)
{
  unsigned __int16 *v4; // ebx
  unsigned __int16 *v5; // edi
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  const char *v14; // edi
  int v15; // edi
  char *v16; // ebx
  char *i; // esi
  int v18; // eax
  __int16 *v19; // eax
  char *v20; // ecx
  int v21; // eax
  int v22; // eax
  _WORD *v23; // ebx
  unsigned __int16 *v24; // ebx
  __int64 v25; // rax
  int v26; // esi
  void *v27; // eax
  int v28; // eax
  unsigned __int16 *v29; // ebx
  void (__cdecl *v30)(_DWORD *, const char *, int, int, int, int, __crt_locale_pointers *); // eax
  int v31; // ebx
  void (__cdecl *v32)(const char *, __crt_locale_pointers *); // eax
  void (__cdecl *v33)(const char *, __crt_locale_pointers *); // eax
  unsigned int v34; // edi
  unsigned int v35; // ebx
  _BYTE *j; // esi
  int v37; // eax
  int v38; // ecx
  unsigned __int64 v39; // kr00_8
  _BYTE *v40; // eax
  char *v41; // esi
  char *v42; // eax
  int v43; // edi
  int v44; // ebx
  int v45; // edi
  int v46; // ebx
  char *v47; // edi
  int v48; // edi
  int v49; // eax
  int v50; // [esp-14h] [ebp-498h]
  int v51; // [esp-10h] [ebp-494h]
  int v52; // [esp-Ch] [ebp-490h]
  int v53; // [esp-8h] [ebp-48Ch]
  wchar_t v54; // [esp-4h] [ebp-488h]
  int v55; // [esp+10h] [ebp-474h]
  _DWORD v56[2]; // [esp+14h] [ebp-470h] BYREF
  int v57; // [esp+1Ch] [ebp-468h]
  int *v58; // [esp+20h] [ebp-464h]
  unsigned __int16 *v59; // [esp+24h] [ebp-460h]
  wchar_t v60[2]; // [esp+28h] [ebp-45Ch] BYREF
  void *Block; // [esp+2Ch] [ebp-458h]
  int v62; // [esp+30h] [ebp-454h]
  int v63; // [esp+34h] [ebp-450h]
  __crt_locale_pointers Locale; // [esp+38h] [ebp-44Ch] BYREF
  int v65; // [esp+40h] [ebp-444h]
  char v66; // [esp+44h] [ebp-440h]
  int v67; // [esp+48h] [ebp-43Ch]
  char SrcCh[4]; // [esp+4Ch] [ebp-438h] BYREF
  wchar_t v69[2]; // [esp+50h] [ebp-434h] BYREF
  int v70; // [esp+54h] [ebp-430h]
  int v71; // [esp+58h] [ebp-42Ch]
  int v72; // [esp+5Ch] [ebp-428h]
  int v73; // [esp+60h] [ebp-424h]
  int v74; // [esp+64h] [ebp-420h]
  int v75; // [esp+68h] [ebp-41Ch]
  int v76; // [esp+6Ch] [ebp-418h] BYREF
  int v77; // [esp+70h] [ebp-414h]
  char *v78; // [esp+74h] [ebp-410h]
  int v79; // [esp+78h] [ebp-40Ch]
  int v80; // [esp+7Ch] [ebp-408h]
  wchar_t DstCh[255]; // [esp+80h] [ebp-404h] BYREF
  _BYTE v82[513]; // [esp+27Fh] [ebp-205h] BYREF

  v4 = a4;
  v5 = a2;
  v71 = a1;
  v75 = (int)a4;
  v62 = 0;
  v80 = 0;
  v72 = 0;
  v79 = 0;
  v73 = 0;
  v63 = 0;
  v70 = 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&Locale, a3);
  v58 = _errno();
  if ( !a1 || !a2 )
    goto LABEL_2;
  v7 = *a2;
  v76 = 0;
  v77 = 0;
  v67 = 0;
  Block = 0;
  v74 = v7;
  if ( !(_WORD)v7 )
    goto LABEL_218;
  while ( 1 )
  {
    v59 = ++v5;
    if ( v76 < 0 )
      break;
    if ( (unsigned __int16)(v7 - 32) > 0x58u )
      v8 = 0;
    else
      v8 = byte_476200[(unsigned __int16)v7] & 0xF;
    v9 = (unsigned __int8)byte_476220[9 * v8 + v67] >> 4;
    v67 = v9;
    if ( v9 == 8 )
      goto LABEL_2;
    switch ( v9 )
    {
      case 0:
        goto $NORMAL_STATE$29664;
      case 1:
        v79 = -1;
        v57 = 0;
        v63 = 0;
        v72 = 0;
        v73 = 0;
        v80 = 0;
        v70 = 0;
        goto LABEL_214;
      case 2:
        switch ( (unsigned __int16)v7 )
        {
          case ' ':
            v80 |= 2u;
            break;
          case '#':
            v80 |= 0x80u;
            break;
          case '+':
            v80 |= 1u;
            break;
          case '-':
            v80 |= 4u;
            break;
          case '0':
            v80 |= 8u;
            break;
          default:
            goto LABEL_213;
        }
        goto LABEL_214;
      case 3:
        if ( (_WORD)v7 == 42 )
        {
          v10 = *(_DWORD *)v4;
          v4 += 2;
          v75 = (int)v4;
          v72 = v10;
          if ( v10 < 0 )
          {
            v80 |= 4u;
            v72 = -v72;
          }
        }
        else
        {
          v72 = 10 * v72 + (unsigned __int16)v7 - 48;
        }
        goto LABEL_214;
      case 4:
        v79 = 0;
        goto LABEL_214;
      case 5:
        if ( (_WORD)v7 == 42 )
        {
          v11 = *(_DWORD *)v4;
          v4 += 2;
          v75 = (int)v4;
          v79 = v11;
          if ( v11 < 0 )
            v79 = -1;
        }
        else
        {
          v79 = 10 * v79 + (unsigned __int16)v7 - 48;
        }
        goto LABEL_214;
      case 6:
        switch ( (unsigned __int16)v7 )
        {
          case 'I':
            v12 = *v5;
            if ( v12 == 54 && v5[1] == 52 )
            {
              v5 += 2;
              v80 |= 0x8000u;
            }
            else if ( v12 == 51 && v5[1] == 50 )
            {
              v5 += 2;
              v80 &= ~0x8000u;
            }
            else if ( v12 != 100 && v12 != 105 && v12 != 111 && v12 != 117 && v12 != 120 && v12 != 88 )
            {
              v67 = 0;
$NORMAL_STATE$29664:
              v70 = 1;
              write_char(v71, &v76, v7);
            }
            break;
          case 'h':
            v80 |= 0x20u;
            break;
          case 'l':
            if ( *v5 == 108 )
            {
              ++v5;
              v80 |= 0x1000u;
            }
            else
            {
              v80 |= 0x10u;
            }
            break;
          case 'w':
            v80 |= 0x800u;
            break;
        }
        goto LABEL_214;
      case 7:
        if ( (unsigned __int16)v7 <= 0x64u )
        {
          if ( (unsigned __int16)v7 == 100 )
          {
LABEL_111:
            v80 |= 0x40u;
            goto LABEL_112;
          }
          if ( (unsigned __int16)v7 > 0x53u )
          {
            if ( (unsigned __int16)v7 == 88 )
              goto LABEL_133;
            if ( (unsigned __int16)v7 == 90 )
            {
              v19 = *(__int16 **)v4;
              v75 = (int)(v4 + 2);
              if ( v19 && (v20 = (char *)*((_DWORD *)v19 + 1)) != 0 )
              {
                v21 = *v19;
                v78 = v20;
                if ( (v80 & 0x800) != 0 )
                {
                  v22 = v21 - (v21 >> 31);
                  v70 = 1;
                  goto LABEL_178;
                }
                v70 = 0;
              }
              else
              {
                v78 = off_4C9B78;
                v21 = strlen(off_4C9B78);
              }
LABEL_179:
              v77 = v21;
              goto LABEL_180;
            }
            if ( (unsigned __int16)v7 != 97 )
            {
              if ( (unsigned __int16)v7 != 99 )
                goto LABEL_180;
              goto LABEL_86;
            }
          }
          else
          {
            if ( (unsigned __int16)v7 == 83 )
            {
              if ( (v80 & 0x830) == 0 )
                v80 |= 0x20u;
              goto LABEL_71;
            }
            if ( (unsigned __int16)v7 != 65 )
            {
              if ( (unsigned __int16)v7 != 67 )
              {
                if ( (unsigned __int16)v7 != 69 && (unsigned __int16)v7 != 71 )
                  goto LABEL_180;
                goto LABEL_64;
              }
              if ( (v80 & 0x830) == 0 )
                v80 |= 0x20u;
LABEL_86:
              v18 = *v4;
              v70 = 1;
              v75 = (int)(v4 + 2);
              *(_DWORD *)v60 = v18;
              if ( (v80 & 0x20) != 0 )
              {
                SrcCh[0] = v18;
                SrcCh[1] = 0;
                if ( _mbtowc_l(DstCh, SrcCh, *((_DWORD *)Locale.locinfo + 43), &Locale) < 0 )
                  v63 = 1;
              }
              else
              {
                DstCh[0] = v18;
              }
              v78 = (char *)DstCh;
              v77 = 1;
              goto LABEL_180;
            }
LABEL_64:
            v7 += 32;
            v57 = 1;
            v74 = v7;
          }
LABEL_65:
          v13 = v79;
          v80 |= 0x40u;
          v14 = (const char *)DstCh;
          v78 = (char *)DstCh;
          v77 = 512;
          if ( v79 >= 0 )
          {
            if ( v79 )
            {
              if ( v79 > 512 )
              {
                v79 = 512;
                v13 = 512;
              }
              if ( v13 > 163 )
              {
                v26 = v13 + 349;
                v27 = _malloc_crt(v13 + 349);
                LOBYTE(v7) = v74;
                Block = v27;
                if ( v27 )
                {
                  v78 = (char *)v27;
                  v77 = v26;
                  v14 = (const char *)v27;
                }
                else
                {
                  v79 = 163;
                }
              }
            }
            else
            {
              v79 = (_WORD)v7 == 103;
            }
          }
          else
          {
            v79 = 6;
          }
          v28 = *(_DWORD *)v4;
          v29 = v4 + 4;
          v56[0] = v28;
          v56[1] = *((_DWORD *)v29 - 1);
          v53 = v57;
          v52 = v79;
          v75 = (int)v29;
          v51 = (char)v7;
          v50 = v77;
          v30 = (void (__cdecl *)(_DWORD *, const char *, int, int, int, int, __crt_locale_pointers *))DecodePointer(off_4C9EE8);
          v30(v56, v14, v50, v51, v52, v53, &Locale);
          v31 = v80 & 0x80;
          if ( (v80 & 0x80) != 0 && !v79 )
          {
            v32 = (void (__cdecl *)(const char *, __crt_locale_pointers *))DecodePointer(off_4C9EF4);
            v32(v14, &Locale);
          }
          if ( (_WORD)v74 == 103 && !v31 )
          {
            v33 = (void (__cdecl *)(const char *, __crt_locale_pointers *))DecodePointer(off_4C9EF0);
            v33(v14, &Locale);
          }
          if ( *v14 == 45 )
          {
            v80 |= 0x100u;
            v78 = (char *)++v14;
          }
          v21 = strlen(v14);
          goto LABEL_179;
        }
        if ( (unsigned __int16)v7 > 0x70u )
        {
          if ( (unsigned __int16)v7 != 115 )
          {
            if ( (unsigned __int16)v7 != 117 )
            {
              if ( (unsigned __int16)v7 != 120 )
                goto LABEL_180;
              v62 = 39;
              goto $COMMON_HEX$29813;
            }
LABEL_112:
            v74 = 10;
            goto $COMMON_INT$29806;
          }
LABEL_71:
          v15 = v79;
          if ( v79 == -1 )
            v15 = 0x7FFFFFFF;
          v75 = (int)(v4 + 2);
          v16 = *(char **)v4;
          v78 = v16;
          if ( (v80 & 0x20) != 0 )
          {
            if ( !v16 )
              v78 = off_4C9B78;
            v77 = 0;
            for ( i = v78; v77 < v15; ++v77 )
            {
              if ( !*i )
                break;
              if ( _isleadbyte_l((unsigned __int8)*i, &Locale) )
                ++i;
              ++i;
            }
            goto LABEL_180;
          }
          if ( !v16 )
            v78 = (char *)off_4C9B7C;
          v42 = v78;
          v70 = 1;
          while ( v15 )
          {
            --v15;
            if ( !*(_WORD *)v42 )
              break;
            v42 += 2;
          }
          v22 = v42 - v78;
LABEL_178:
          v21 = v22 >> 1;
          goto LABEL_179;
        }
        if ( (unsigned __int16)v7 == 112 )
        {
          v79 = 8;
LABEL_133:
          v62 = 7;
$COMMON_HEX$29813:
          v74 = 16;
          if ( (v80 & 0x80u) != 0 )
          {
            v69[0] = 48;
            v69[1] = v62 + 81;
            v73 = 2;
          }
          goto $COMMON_INT$29806;
        }
        if ( (unsigned __int16)v7 < 0x65u )
          goto LABEL_180;
        if ( (unsigned __int16)v7 <= 0x67u )
          goto LABEL_65;
        if ( (unsigned __int16)v7 == 105 )
          goto LABEL_111;
        if ( (unsigned __int16)v7 != 110 )
        {
          if ( (unsigned __int16)v7 != 111 )
            goto LABEL_180;
          v74 = 8;
          if ( (v80 & 0x80u) != 0 )
            v80 |= 0x200u;
$COMMON_INT$29806:
          if ( (v80 & 0x8000) != 0 || (v80 & 0x1000) != 0 )
          {
            v24 = v4 + 4;
            v25 = *((_QWORD *)v24 - 1);
          }
          else
          {
            v24 = v4 + 2;
            if ( (v80 & 0x20) != 0 )
            {
              v75 = (int)v24;
              if ( (v80 & 0x40) != 0 )
                LODWORD(v25) = (__int16)*(v24 - 2);
              else
                LODWORD(v25) = *(v24 - 2);
              v25 = (int)v25;
LABEL_150:
              if ( (v80 & 0x40) != 0 && v25 < 0 )
              {
                v25 = -v25;
                v80 |= 0x100u;
              }
              v34 = HIDWORD(v25);
              v35 = v25;
              if ( (v80 & 0x9000) == 0 )
                v34 = 0;
              if ( v79 >= 0 )
              {
                v80 &= ~8u;
                if ( v79 > 512 )
                  v79 = 512;
              }
              else
              {
                v79 = 1;
              }
              if ( !(v34 | (unsigned int)v25) )
                v73 = 0;
              for ( j = v82; ; --j )
              {
                v37 = v79--;
                if ( v37 <= 0 && !(v34 | v35) )
                  break;
                v38 = __PAIR64__(v34, v35) % v74 + 48;
                v39 = __PAIR64__(v34, v35) / v74;
                v34 = HIDWORD(v39);
                v35 = v39;
                if ( v38 > 57 )
                  LOBYTE(v38) = v62 + v38;
                *j = v38;
              }
              v40 = (_BYTE *)(v82 - j);
              v41 = j + 1;
              v77 = (int)v40;
              v78 = v41;
              if ( (v80 & 0x200) != 0 && (!v40 || *v41 != 48) )
              {
                --v78;
                ++v77;
                *v78 = 48;
              }
LABEL_180:
              if ( v63 )
                goto LABEL_211;
              if ( (v80 & 0x40) != 0 )
              {
                if ( (v80 & 0x100) != 0 )
                {
                  v54 = 45;
                  goto LABEL_188;
                }
                if ( (v80 & 1) != 0 )
                {
                  v54 = 43;
                  goto LABEL_188;
                }
                if ( (v80 & 2) != 0 )
                {
                  v54 = 32;
LABEL_188:
                  v69[0] = v54;
                  v73 = 1;
                }
              }
              v43 = v72 - v77 - v73;
              v74 = v43;
              if ( (v80 & 0xC) == 0 )
              {
                do
                {
                  if ( v43 <= 0 )
                    break;
                  --v43;
                  write_char(v71, &v76, 0x20u);
                }
                while ( v76 != -1 );
              }
              v44 = v71;
              write_string(&v76, v71, v58, v69, v73);
              if ( (v80 & 8) != 0 && (v80 & 4) == 0 )
              {
                v45 = v74;
                do
                {
                  if ( v45 <= 0 )
                    break;
                  --v45;
                  write_char(v44, &v76, 0x30u);
                }
                while ( v76 != -1 );
              }
              if ( v70 || (v46 = v77, v77 <= 0) )
              {
                write_string(&v76, v71, v58, (wchar_t *)v78, v77);
              }
              else
              {
                v47 = v78;
                while ( 1 )
                {
                  --v46;
                  v55 = _mbtowc_l(v60, v47, *((_DWORD *)Locale.locinfo + 43), &Locale);
                  if ( v55 <= 0 )
                    break;
                  write_char(v71, &v76, v60[0]);
                  v47 += v55;
                  if ( v46 <= 0 )
                    goto LABEL_206;
                }
                v76 = -1;
              }
LABEL_206:
              if ( v76 >= 0 && (v80 & 4) != 0 )
              {
                v48 = v74;
                do
                {
                  if ( v48 <= 0 )
                    break;
                  --v48;
                  write_char(v71, &v76, 0x20u);
                }
                while ( v76 != -1 );
              }
              goto LABEL_211;
            }
            LODWORD(v25) = *((_DWORD *)v24 - 1);
            if ( (v80 & 0x40) != 0 )
              v25 = (int)v25;
            else
              HIDWORD(v25) = 0;
          }
          v75 = (int)v24;
          goto LABEL_150;
        }
        v75 = (int)(v4 + 2);
        v23 = *(_WORD **)v4;
        if ( !_get_printf_count_output() )
          goto LABEL_2;
        if ( (v80 & 0x20) != 0 )
          *v23 = v76;
        else
          *(_DWORD *)v23 = v76;
        v63 = 1;
LABEL_211:
        if ( Block )
        {
          free(Block);
          Block = 0;
        }
LABEL_213:
        v5 = v59;
        v4 = (unsigned __int16 *)v75;
LABEL_214:
        v49 = *v5;
        v74 = v49;
        if ( !(_WORD)v49 )
          goto LABEL_216;
        v7 = v49;
        break;
      default:
        goto LABEL_213;
    }
  }
LABEL_216:
  if ( !v67 || v67 == 7 )
  {
LABEL_218:
    if ( v66 )
      *(_DWORD *)(v65 + 112) &= ~2u;
    return v76;
  }
  else
  {
LABEL_2:
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( v66 )
      *(_DWORD *)(v65 + 112) &= ~2u;
    return -1;
  }
}
