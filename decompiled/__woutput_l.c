int __cdecl _woutput_l(int a1, unsigned __int16 *a2, struct localeinfo_struct *a3, unsigned __int16 *a4)
{
  unsigned __int16 *v4; // esi
  unsigned __int16 *v5; // edi
  bool v6; // zf
  int v8; // ecx
  int v9; // edx
  unsigned __int16 *v10; // esi
  int v11; // eax
  int v12; // eax
  const char *v13; // ebx
  int v14; // ebx
  char *v15; // edi
  char *j; // esi
  int v17; // eax
  __int16 *v18; // eax
  char *v19; // ecx
  int v20; // eax
  int v21; // eax
  _WORD *v22; // esi
  __int64 v23; // rax
  unsigned __int16 *v24; // edi
  int v25; // esi
  void *v26; // eax
  int v27; // eax
  unsigned __int16 *v28; // edi
  void (__cdecl *v29)(_DWORD *, const char *, int, int, int, int, __crt_locale_pointers *); // eax
  int v30; // edi
  void (__cdecl *v31)(const char *, __crt_locale_pointers *); // eax
  void (__cdecl *v32)(const char *, __crt_locale_pointers *); // eax
  unsigned int v33; // edi
  unsigned int v34; // ebx
  _BYTE *i; // esi
  int v36; // eax
  int v37; // ecx
  unsigned __int64 v38; // kr00_8
  _BYTE *v39; // eax
  char *v40; // esi
  char *v41; // eax
  int v42; // edi
  int v43; // ebx
  int v44; // edi
  int v45; // ebx
  char *v46; // edi
  int v47; // edi
  int v48; // eax
  int v49; // [esp-14h] [ebp-498h]
  int v50; // [esp-10h] [ebp-494h]
  int v51; // [esp-Ch] [ebp-490h]
  int v52; // [esp-8h] [ebp-48Ch]
  __int16 v53; // [esp-4h] [ebp-488h]
  int v54; // [esp+10h] [ebp-474h]
  _DWORD v55[2]; // [esp+14h] [ebp-470h] BYREF
  int v56; // [esp+1Ch] [ebp-468h]
  int *v57; // [esp+20h] [ebp-464h]
  int v58; // [esp+24h] [ebp-460h]
  wchar_t v59[2]; // [esp+28h] [ebp-45Ch] BYREF
  __crt_locale_pointers Locale; // [esp+2Ch] [ebp-458h] BYREF
  int v61; // [esp+34h] [ebp-450h]
  char v62; // [esp+38h] [ebp-44Ch]
  int v63; // [esp+3Ch] [ebp-448h]
  int v64; // [esp+40h] [ebp-444h]
  unsigned __int16 *v65; // [esp+44h] [ebp-440h]
  void *Block; // [esp+48h] [ebp-43Ch]
  char SrcCh[4]; // [esp+4Ch] [ebp-438h] BYREF
  _WORD v68[2]; // [esp+50h] [ebp-434h] BYREF
  int v69; // [esp+54h] [ebp-430h]
  int v70; // [esp+58h] [ebp-42Ch]
  int v71; // [esp+5Ch] [ebp-428h]
  int v72; // [esp+60h] [ebp-424h]
  int v73; // [esp+64h] [ebp-420h]
  int v74; // [esp+68h] [ebp-41Ch]
  int v75; // [esp+6Ch] [ebp-418h] BYREF
  int v76; // [esp+70h] [ebp-414h]
  char *v77; // [esp+74h] [ebp-410h]
  int v78; // [esp+78h] [ebp-40Ch]
  int v79; // [esp+7Ch] [ebp-408h]
  wchar_t DstCh[255]; // [esp+80h] [ebp-404h] BYREF
  _BYTE v81[513]; // [esp+27Fh] [ebp-205h] BYREF

  v4 = a2;
  v5 = a4;
  v72 = a1;
  v73 = (int)a4;
  v64 = 0;
  v79 = 0;
  v69 = 0;
  v78 = 0;
  v71 = 0;
  v63 = 0;
  v70 = 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&Locale, a3);
  v57 = _errno();
  if ( !v72 || !a2 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    v6 = v62 == 0;
    goto LABEL_3;
  }
  v8 = *a2;
  v9 = 0;
  v75 = 0;
  v76 = 0;
  Block = 0;
  v74 = v8;
  if ( !(_WORD)v8 )
  {
LABEL_216:
    if ( v62 )
      *(_DWORD *)(v61 + 112) &= ~2u;
    return v75;
  }
  while ( 2 )
  {
    v10 = v4 + 1;
    v65 = v10;
    if ( v75 < 0 )
      goto LABEL_216;
    if ( (unsigned __int16)(v8 - 32) > 0x58u )
      v11 = 0;
    else
      v11 = byte_474D60[(unsigned __int16)v8] & 0xF;
    v58 = byte_474D80[8 * v11 + v9] >> 4;
    switch ( v58 )
    {
      case 0:
        goto $NORMAL_STATE$29657;
      case 1:
        v78 = -1;
        v56 = 0;
        v63 = 0;
        v69 = 0;
        v71 = 0;
        v79 = 0;
        v70 = 0;
        goto LABEL_213;
      case 2:
        switch ( (unsigned __int16)v8 )
        {
          case ' ':
            v79 |= 2u;
            break;
          case '#':
            v79 |= 0x80u;
            break;
          case '+':
            v79 |= 1u;
            break;
          case '-':
            v79 |= 4u;
            break;
          case '0':
            v79 |= 8u;
            break;
        }
        goto LABEL_213;
      case 3:
        if ( (_WORD)v8 == 42 )
        {
          v73 = (int)(v5 + 2);
          v69 = *(_DWORD *)v5;
          if ( v69 < 0 )
          {
            v79 |= 4u;
            v69 = -v69;
          }
        }
        else
        {
          v69 = 10 * v69 + (unsigned __int16)v8 - 48;
        }
        goto LABEL_213;
      case 4:
        v78 = 0;
        goto LABEL_213;
      case 5:
        if ( (_WORD)v8 == 42 )
        {
          v73 = (int)(v5 + 2);
          v78 = *(_DWORD *)v5;
          if ( v78 < 0 )
            v78 = -1;
        }
        else
        {
          v78 = 10 * v78 + (unsigned __int16)v8 - 48;
        }
        goto LABEL_213;
      case 6:
        switch ( (unsigned __int16)v8 )
        {
          case 'I':
            v12 = *v10;
            if ( v12 == 54 && v10[1] == 52 )
            {
              v79 |= 0x8000u;
              v65 = v10 + 2;
            }
            else if ( v12 == 51 && v10[1] == 50 )
            {
              v79 &= ~0x8000u;
              v65 = v10 + 2;
            }
            else if ( v12 != 100 && v12 != 105 && v12 != 111 && v12 != 117 && v12 != 120 && v12 != 88 )
            {
              v58 = 0;
$NORMAL_STATE$29657:
              v70 = 1;
              write_char(v72, &v75, v8);
            }
            break;
          case 'h':
            v79 |= 0x20u;
            break;
          case 'l':
            if ( *v10 == 108 )
            {
              v79 |= 0x1000u;
              v65 = v10 + 1;
            }
            else
            {
              v79 |= 0x10u;
            }
            break;
          case 'w':
            v79 |= 0x800u;
            break;
        }
        goto LABEL_213;
      case 7:
        if ( (unsigned __int16)v8 <= 0x64u )
        {
          if ( (unsigned __int16)v8 == 100 )
            goto LABEL_111;
          if ( (unsigned __int16)v8 > 0x53u )
          {
            if ( (unsigned __int16)v8 != 88 )
            {
              if ( (unsigned __int16)v8 == 90 )
              {
                v18 = *(__int16 **)v5;
                v73 = (int)(v5 + 2);
                if ( v18 && (v19 = (char *)*((_DWORD *)v18 + 1)) != 0 )
                {
                  v20 = *v18;
                  v77 = v19;
                  if ( (v79 & 0x800) != 0 )
                  {
                    v21 = v20 - (v20 >> 31);
                    v70 = 1;
                    goto LABEL_178;
                  }
                  v70 = 0;
                }
                else
                {
                  v77 = off_4C9B78;
                  v20 = strlen(off_4C9B78);
                }
LABEL_179:
                v76 = v20;
                goto LABEL_180;
              }
              if ( (unsigned __int16)v8 == 97 )
                goto LABEL_65;
              if ( (unsigned __int16)v8 != 99 )
                goto LABEL_180;
              goto LABEL_86;
            }
LABEL_133:
            v64 = 7;
$COMMON_HEX$29806:
            v74 = 16;
            if ( (v79 & 0x80u) != 0 )
            {
              v68[0] = 48;
              v68[1] = v64 + 81;
              v71 = 2;
            }
$COMMON_INT$29799:
            if ( (v79 & 0x8000) != 0 || (v79 & 0x1000) != 0 )
            {
              v23 = *(_QWORD *)v5;
              v24 = v5 + 4;
            }
            else
            {
              v24 = v5 + 2;
              if ( (v79 & 0x20) != 0 )
              {
                v73 = (int)v24;
                if ( (v79 & 0x40) != 0 )
                  LODWORD(v23) = (__int16)*(v24 - 2);
                else
                  LODWORD(v23) = *(v24 - 2);
                v23 = (int)v23;
                goto LABEL_150;
              }
              LODWORD(v23) = *((_DWORD *)v24 - 1);
              if ( (v79 & 0x40) != 0 )
                v23 = (int)v23;
              else
                HIDWORD(v23) = 0;
            }
            v73 = (int)v24;
LABEL_150:
            if ( (v79 & 0x40) != 0 && v23 < 0 )
            {
              v23 = -v23;
              v79 |= 0x100u;
            }
            v33 = HIDWORD(v23);
            v34 = v23;
            if ( (v79 & 0x9000) == 0 )
              v33 = 0;
            if ( v78 >= 0 )
            {
              v79 &= ~8u;
              if ( v78 > 512 )
                v78 = 512;
            }
            else
            {
              v78 = 1;
            }
            if ( !(v33 | (unsigned int)v23) )
              v71 = 0;
            for ( i = v81; ; --i )
            {
              v36 = v78--;
              if ( v36 <= 0 && !(v33 | v34) )
                break;
              v37 = __PAIR64__(v33, v34) % v74 + 48;
              v38 = __PAIR64__(v33, v34) / v74;
              v33 = HIDWORD(v38);
              v34 = v38;
              if ( v37 > 57 )
                LOBYTE(v37) = v64 + v37;
              *i = v37;
            }
            v39 = (_BYTE *)(v81 - i);
            v40 = i + 1;
            v76 = (int)v39;
            v77 = v40;
            if ( (v79 & 0x200) != 0 && (!v39 || *v40 != 48) )
            {
              --v77;
              ++v76;
              *v77 = 48;
            }
            goto LABEL_180;
          }
          switch ( (unsigned __int16)v8 )
          {
            case 'S':
              if ( (v79 & 0x830) == 0 )
                v79 |= 0x20u;
LABEL_71:
              v14 = v78;
              if ( v78 == -1 )
                v14 = 0x7FFFFFFF;
              v73 = (int)(v5 + 2);
              v15 = *(char **)v5;
              v77 = v15;
              if ( (v79 & 0x20) == 0 )
              {
                if ( !v15 )
                  v77 = (char *)off_4C9B7C;
                v41 = v77;
                v70 = 1;
                while ( v14 )
                {
                  --v14;
                  if ( !*(_WORD *)v41 )
                    break;
                  v41 += 2;
                }
                v21 = v41 - v77;
LABEL_178:
                v20 = v21 >> 1;
                goto LABEL_179;
              }
              if ( !v15 )
                v77 = off_4C9B78;
              v76 = 0;
              for ( j = v77; v76 < v14; ++v76 )
              {
                if ( !*j )
                  break;
                if ( _isleadbyte_l((unsigned __int8)*j, &Locale) )
                  ++j;
                ++j;
              }
              break;
            case 'A':
              goto LABEL_64;
            case 'C':
              if ( (v79 & 0x830) == 0 )
                v79 |= 0x20u;
LABEL_86:
              v17 = *v5;
              v70 = 1;
              v73 = (int)(v5 + 2);
              *(_DWORD *)v59 = v17;
              if ( (v79 & 0x20) != 0 )
              {
                SrcCh[0] = v17;
                SrcCh[1] = 0;
                if ( _mbtowc_l(DstCh, SrcCh, *((_DWORD *)Locale.locinfo + 43), &Locale) < 0 )
                  v63 = 1;
              }
              else
              {
                DstCh[0] = v17;
              }
              v77 = (char *)DstCh;
              v76 = 1;
              break;
            case 'E':
            case 'G':
LABEL_64:
              v56 = 1;
              v74 = v8 + 32;
LABEL_65:
              v79 |= 0x40u;
              v13 = (const char *)DstCh;
              v77 = (char *)DstCh;
              v76 = 512;
              if ( v78 >= 0 )
              {
                if ( v78 )
                {
                  if ( v78 > 512 )
                    v78 = 512;
                  if ( v78 > 163 )
                  {
                    v25 = v78 + 349;
                    v26 = _malloc_crt(v78 + 349);
                    Block = v26;
                    if ( v26 )
                    {
                      v77 = (char *)v26;
                      v76 = v25;
                      v13 = (const char *)v26;
                    }
                    else
                    {
                      v78 = 163;
                    }
                  }
                }
                else
                {
                  v78 = (_WORD)v74 == 103;
                }
              }
              else
              {
                v78 = 6;
              }
              v27 = *(_DWORD *)v5;
              v28 = v5 + 4;
              v55[0] = v27;
              v55[1] = *((_DWORD *)v28 - 1);
              v52 = v56;
              v51 = v78;
              v73 = (int)v28;
              v50 = (char)v74;
              v49 = v76;
              v29 = (void (__cdecl *)(_DWORD *, const char *, int, int, int, int, __crt_locale_pointers *))DecodePointer(off_4C9EE8);
              v29(v55, v13, v49, v50, v51, v52, &Locale);
              v30 = v79 & 0x80;
              if ( (v79 & 0x80) != 0 && !v78 )
              {
                v31 = (void (__cdecl *)(const char *, __crt_locale_pointers *))DecodePointer(off_4C9EF4);
                v31(v13, &Locale);
              }
              if ( (_WORD)v74 == 103 && !v30 )
              {
                v32 = (void (__cdecl *)(const char *, __crt_locale_pointers *))DecodePointer(off_4C9EF0);
                v32(v13, &Locale);
              }
              if ( *v13 == 45 )
              {
                v79 |= 0x100u;
                v77 = (char *)++v13;
              }
              v20 = strlen(v13);
              goto LABEL_179;
          }
LABEL_180:
          if ( v63 )
            goto LABEL_211;
          if ( (v79 & 0x40) == 0 )
            goto LABEL_189;
          if ( (v79 & 0x100) != 0 )
          {
            v53 = 45;
LABEL_188:
            v68[0] = v53;
            v71 = 1;
            goto LABEL_189;
          }
          if ( (v79 & 1) != 0 )
          {
            v53 = 43;
            goto LABEL_188;
          }
          if ( (v79 & 2) != 0 )
          {
            v53 = 32;
            goto LABEL_188;
          }
LABEL_189:
          v42 = v69 - v76 - v71;
          v74 = v42;
          if ( (v79 & 0xC) == 0 )
          {
            do
            {
              if ( v42 <= 0 )
                break;
              --v42;
              write_char(v72, &v75, 0x20u);
            }
            while ( v75 != -1 );
          }
          v43 = v72;
          write_string(v68, v71);
          if ( (v79 & 8) != 0 && (v79 & 4) == 0 )
          {
            v44 = v74;
            do
            {
              if ( v44 <= 0 )
                break;
              --v44;
              write_char(v43, &v75, 0x30u);
            }
            while ( v75 != -1 );
          }
          if ( v70 || (v45 = v76, v76 <= 0) )
          {
            write_string(v77, v76);
          }
          else
          {
            v46 = v77;
            while ( 1 )
            {
              --v45;
              v54 = _mbtowc_l(v59, v46, *((_DWORD *)Locale.locinfo + 43), &Locale);
              if ( v54 <= 0 )
                break;
              write_char(v72, &v75, v59[0]);
              v46 += v54;
              if ( v45 <= 0 )
                goto LABEL_206;
            }
            v75 = -1;
          }
LABEL_206:
          if ( v75 >= 0 && (v79 & 4) != 0 )
          {
            v47 = v74;
            do
            {
              if ( v47 <= 0 )
                break;
              --v47;
              write_char(v72, &v75, 0x20u);
            }
            while ( v75 != -1 );
          }
LABEL_211:
          if ( Block )
          {
            free(Block);
            Block = 0;
          }
LABEL_213:
          v4 = v65;
          v48 = *v65;
          v74 = v48;
          if ( !(_WORD)v48 )
            goto LABEL_216;
          v9 = v58;
          v5 = (unsigned __int16 *)v73;
          v8 = v48;
          continue;
        }
        if ( (unsigned __int16)v8 > 0x70u )
        {
          if ( (unsigned __int16)v8 != 115 )
          {
            if ( (unsigned __int16)v8 != 117 )
            {
              if ( (unsigned __int16)v8 != 120 )
                goto LABEL_180;
              v64 = 39;
              goto $COMMON_HEX$29806;
            }
            goto LABEL_112;
          }
          goto LABEL_71;
        }
        if ( (unsigned __int16)v8 == 112 )
        {
          v78 = 8;
          goto LABEL_133;
        }
        if ( (unsigned __int16)v8 < 0x65u )
          goto LABEL_180;
        if ( (unsigned __int16)v8 <= 0x67u )
          goto LABEL_65;
        if ( (unsigned __int16)v8 == 105 )
        {
LABEL_111:
          v79 |= 0x40u;
LABEL_112:
          v74 = 10;
          goto $COMMON_INT$29799;
        }
        if ( (unsigned __int16)v8 != 110 )
        {
          if ( (unsigned __int16)v8 != 111 )
            goto LABEL_180;
          v74 = 8;
          if ( (v79 & 0x80u) != 0 )
            v79 |= 0x200u;
          goto $COMMON_INT$29799;
        }
        v22 = *(_WORD **)v5;
        v73 = (int)(v5 + 2);
        if ( _get_printf_count_output() )
        {
          if ( (v79 & 0x20) != 0 )
            *v22 = v75;
          else
            *(_DWORD *)v22 = v75;
          v63 = 1;
          goto LABEL_211;
        }
        *_errno() = 22;
        _invalid_parameter_noinfo();
        v6 = v62 == 0;
LABEL_3:
        if ( !v6 )
          *(_DWORD *)(v61 + 112) &= ~2u;
        return -1;
      default:
        goto LABEL_213;
    }
  }
}
