int __cdecl _output_s_l(FILE *Stream, _BYTE *a2, struct localeinfo_struct *a3, int *a4)
{
  _BYTE *v4; // ebx
  int *v5; // edi
  int v7; // eax
  _BYTE *v8; // ecx
  char *v9; // eax
  unsigned __int8 v10; // dl
  _BYTE *v11; // ebx
  int v12; // eax
  int v13; // eax
  char v14; // al
  bool v15; // zf
  int v16; // eax
  int v17; // ecx
  char *v18; // edi
  char *v19; // eax
  _DWORD *v20; // edi
  __int16 *v21; // eax
  char *v22; // ecx
  int v23; // eax
  _WORD *v24; // esi
  _DWORD *v25; // edi
  __int64 v26; // rax
  char *v27; // ebx
  int v28; // esi
  void *v29; // eax
  int v30; // eax
  _DWORD *v31; // edi
  void (__cdecl *v32)(_DWORD *, char *, int, int, int, int, __crt_locale_pointers *); // eax
  int v33; // edi
  void (__cdecl *v34)(char *, __crt_locale_pointers *); // eax
  void (__cdecl *v35)(char *, __crt_locale_pointers *); // eax
  unsigned int v36; // edi
  unsigned int v37; // ebx
  char *j; // esi
  int v39; // eax
  unsigned __int64 v40; // rcx
  int v41; // ecx
  char *v42; // eax
  char *v43; // esi
  char *i; // eax
  int v45; // eax
  int v46; // edi
  FILE *v47; // ebx
  int v48; // eax
  int v49; // edi
  wchar_t *v50; // esi
  wchar_t v51; // ax
  errno_t v52; // eax
  int v53; // edi
  unsigned __int8 v54; // al
  int v55; // [esp-14h] [ebp-2A0h]
  int v56; // [esp-10h] [ebp-29Ch]
  unsigned __int64 v57; // [esp-10h] [ebp-29Ch]
  int v58; // [esp-Ch] [ebp-298h]
  int v59; // [esp-8h] [ebp-294h]
  _DWORD v60[2]; // [esp+Ch] [ebp-280h] BYREF
  int v61; // [esp+14h] [ebp-278h] BYREF
  int v62; // [esp+18h] [ebp-274h]
  int v63; // [esp+1Ch] [ebp-270h]
  int v64; // [esp+24h] [ebp-268h]
  int *v65; // [esp+28h] [ebp-264h]
  void *Block; // [esp+2Ch] [ebp-260h]
  int v67; // [esp+30h] [ebp-25Ch]
  int v68; // [esp+34h] [ebp-258h]
  __crt_locale_pointers Locale; // [esp+38h] [ebp-254h] BYREF
  int v70; // [esp+40h] [ebp-24Ch]
  char v71; // [esp+44h] [ebp-248h]
  int v72; // [esp+48h] [ebp-244h]
  _BYTE *v73; // [esp+4Ch] [ebp-240h]
  int v74; // [esp+50h] [ebp-23Ch]
  int v75; // [esp+54h] [ebp-238h]
  int v76; // [esp+58h] [ebp-234h]
  FILE *File; // [esp+5Ch] [ebp-230h]
  _BYTE v78[4]; // [esp+60h] [ebp-22Ch] BYREF
  int SizeConverted; // [esp+64h] [ebp-228h] BYREF
  int v80; // [esp+68h] [ebp-224h] BYREF
  char *v81; // [esp+6Ch] [ebp-220h]
  int v82; // [esp+70h] [ebp-21Ch]
  int v83; // [esp+74h] [ebp-218h]
  unsigned __int8 v84; // [esp+7Bh] [ebp-211h]
  int v85; // [esp+7Ch] [ebp-210h]
  char MbCh[511]; // [esp+80h] [ebp-20Ch] BYREF
  char v87; // [esp+27Fh] [ebp-Dh] BYREF
  char v88[8]; // [esp+280h] [ebp-Ch] BYREF

  v4 = a2;
  v5 = a4;
  File = Stream;
  v82 = (int)a4;
  v68 = 0;
  v85 = 0;
  v75 = 0;
  v83 = 0;
  v76 = 0;
  v67 = 0;
  v74 = 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&Locale, a3);
  v65 = _errno();
  if ( !Stream )
    goto LABEL_2;
  if ( (Stream->_flag & 0x40) == 0 )
  {
    v7 = _fileno(Stream);
    if ( v7 == -1 || v7 == -2 )
      v8 = &unk_4C9CB0;
    else
      v8 = (_BYTE *)(dword_4DCF40[v7 >> 5] + ((v7 & 0x1F) << 6));
    if ( (v8[36] & 0x7F) != 0 )
      goto LABEL_2;
    v9 = v7 == -1 || v7 == -2 ? (char *)&unk_4C9CB0 : (char *)(dword_4DCF40[v7 >> 5] + ((v7 & 0x1F) << 6));
    if ( v9[36] < 0 )
      goto LABEL_2;
  }
  if ( !a2 )
    goto LABEL_2;
  v10 = *a2;
  v80 = 0;
  SizeConverted = 0;
  v72 = 0;
  Block = 0;
  v84 = v10;
  if ( !v10 )
    goto LABEL_232;
  while ( 1 )
  {
    v11 = v4 + 1;
    v73 = v11;
    if ( v80 < 0 )
      break;
    if ( (unsigned __int8)(v10 - 32) > 0x58u )
      v12 = 0;
    else
      v12 = byte_476200[(char)v10] & 0xF;
    v13 = (unsigned __int8)byte_476220[9 * v12 + v72] >> 4;
    v72 = v13;
    if ( v13 == 8 )
      goto LABEL_2;
    switch ( v13 )
    {
      case 0:
        goto $NORMAL_STATE$29171;
      case 1:
        v83 = -1;
        v62 = 0;
        v67 = 0;
        v75 = 0;
        v76 = 0;
        v85 = 0;
        v74 = 0;
        goto LABEL_228;
      case 2:
        switch ( v10 )
        {
          case ' ':
            v85 |= 2u;
            break;
          case '#':
            v85 |= 0x80u;
            break;
          case '+':
            v85 |= 1u;
            break;
          case '-':
            v85 |= 4u;
            break;
          case '0':
            v85 |= 8u;
            break;
        }
        goto LABEL_228;
      case 3:
        if ( v10 == 42 )
        {
          v82 = (int)(v5 + 1);
          v75 = *v5;
          if ( v75 < 0 )
          {
            v85 |= 4u;
            v75 = -v75;
          }
        }
        else
        {
          v75 = 10 * v75 + (char)v10 - 48;
        }
        goto LABEL_228;
      case 4:
        v83 = 0;
        goto LABEL_228;
      case 5:
        if ( v10 == 42 )
        {
          v82 = (int)(v5 + 1);
          v83 = *v5;
          if ( v83 < 0 )
            v83 = -1;
        }
        else
        {
          v83 = 10 * v83 + (char)v10 - 48;
        }
        goto LABEL_228;
      case 6:
        switch ( v10 )
        {
          case 'I':
            v14 = *v11;
            if ( *v11 == 54 && v11[1] == 52 )
            {
              v85 |= 0x8000u;
              v73 = v11 + 2;
            }
            else if ( v14 == 51 && v11[1] == 50 )
            {
              v85 &= ~0x8000u;
              v73 = v11 + 2;
            }
            else if ( v14 != 100 && v14 != 105 && v14 != 111 && v14 != 117 && v14 != 120 && v14 != 88 )
            {
              v72 = 0;
$NORMAL_STATE$29171:
              v74 = 0;
              v16 = _isleadbyte_l(v10, &Locale);
              v15 = v16 == 0;
              LOBYTE(v16) = v84;
              if ( !v15 )
              {
                v16 = write_char_0(File, v16, &v80);
                LOBYTE(v16) = *v11;
                v73 = v11 + 1;
                if ( !(_BYTE)v16 )
                  goto LABEL_2;
              }
              write_char_0(File, v16, &v80);
            }
            break;
          case 'h':
            v85 |= 0x20u;
            break;
          case 'l':
            if ( *v11 == 108 )
            {
              v85 |= 0x1000u;
              v73 = v11 + 1;
            }
            else
            {
              v85 |= 0x10u;
            }
            break;
          case 'w':
            v85 |= 0x800u;
            break;
        }
        goto LABEL_228;
      case 7:
        if ( (char)v10 <= 100 )
        {
          if ( v10 == 100 )
            goto LABEL_119;
          if ( (char)v10 > 83 )
          {
            switch ( v10 )
            {
              case 'X':
                goto LABEL_144;
              case 'Z':
                v21 = (__int16 *)*v5;
                v82 = (int)(v5 + 1);
                if ( v21 && (v22 = (char *)*((_DWORD *)v21 + 1)) != 0 )
                {
                  v23 = *v21;
                  v81 = v22;
                  if ( (v85 & 0x800) != 0 )
                  {
                    v23 /= 2;
                    v74 = 1;
                  }
                  else
                  {
                    v74 = 0;
                  }
                }
                else
                {
                  v81 = off_4C9B78;
                  v23 = strlen(off_4C9B78);
                }
                goto LABEL_193;
              case 'a':
                goto LABEL_124;
            }
            if ( v10 != 99 )
              goto LABEL_194;
            v5 = (int *)v82;
          }
          else
          {
            if ( v10 == 83 )
            {
              if ( (v85 & 0x830) == 0 )
                v85 |= 0x800u;
              goto LABEL_82;
            }
            if ( v10 == 65 )
            {
LABEL_77:
              v10 += 32;
              v62 = 1;
              v84 = v10;
              goto LABEL_124;
            }
            if ( v10 != 67 )
            {
              if ( v10 != 69 && v10 != 71 )
                goto LABEL_194;
              goto LABEL_77;
            }
            if ( (v85 & 0x830) == 0 )
              v85 |= 0x800u;
          }
          v20 = v5 + 1;
          v82 = (int)v20;
          if ( (v85 & 0x810) != 0 )
          {
            if ( wctomb_s(&SizeConverted, MbCh, 0x200u, *((_WORD *)v20 - 2)) )
              v67 = 1;
          }
          else
          {
            MbCh[0] = *((_BYTE *)v20 - 4);
            SizeConverted = 1;
          }
          v81 = MbCh;
          goto LABEL_194;
        }
        if ( (char)v10 > 112 )
        {
          if ( v10 != 115 )
          {
            if ( v10 == 117 )
              goto LABEL_120;
            if ( v10 != 120 )
              goto LABEL_194;
            v5 = (int *)v82;
            v68 = 39;
            goto $COMMON_HEX$29332;
          }
LABEL_82:
          v17 = v83;
          if ( v83 == -1 )
            v17 = 0x7FFFFFFF;
          v82 = (int)(v5 + 1);
          v18 = (char *)*v5;
          v81 = v18;
          if ( (v85 & 0x810) != 0 )
          {
            if ( !v18 )
              v81 = (char *)off_4C9B7C;
            v19 = v81;
            v74 = 1;
            while ( v17 )
            {
              --v17;
              if ( !*(_WORD *)v19 )
                break;
              v19 += 2;
            }
            v23 = (v19 - v81) >> 1;
          }
          else
          {
            if ( !v18 )
              v81 = off_4C9B78;
            for ( i = v81; v17; ++i )
            {
              --v17;
              if ( !*i )
                break;
            }
            v23 = i - v81;
          }
          goto LABEL_193;
        }
        if ( v10 == 112 )
        {
          v83 = 8;
LABEL_144:
          v68 = 7;
$COMMON_HEX$29332:
          SizeConverted = 16;
          if ( (v85 & 0x80u) != 0 )
          {
            v78[0] = 48;
            v78[1] = v68 + 81;
            v76 = 2;
          }
          goto $COMMON_INT$29325;
        }
        if ( (char)v10 < 101 )
          goto LABEL_194;
        if ( (char)v10 <= 103 )
        {
          v5 = (int *)v82;
LABEL_124:
          v85 |= 0x40u;
          v27 = MbCh;
          v81 = MbCh;
          v64 = 512;
          if ( v83 >= 0 )
          {
            if ( v83 )
            {
              if ( v83 > 512 )
                v83 = 512;
              if ( v83 > 163 )
              {
                v28 = v83 + 349;
                v29 = _malloc_crt(v83 + 349);
                v10 = v84;
                Block = v29;
                if ( v29 )
                {
                  v81 = (char *)v29;
                  v64 = v28;
                  v27 = (char *)v29;
                }
                else
                {
                  v83 = 163;
                }
              }
            }
            else
            {
              v83 = v10 == 103;
            }
          }
          else
          {
            v83 = 6;
          }
          v30 = *v5;
          v31 = v5 + 2;
          v60[0] = v30;
          v60[1] = *(v31 - 1);
          v59 = v62;
          v58 = v83;
          v82 = (int)v31;
          v56 = (char)v10;
          v55 = v64;
          v32 = (void (__cdecl *)(_DWORD *, char *, int, int, int, int, __crt_locale_pointers *))DecodePointer(off_4C9EE8);
          v32(v60, v27, v55, v56, v58, v59, &Locale);
          v33 = v85 & 0x80;
          if ( (v85 & 0x80) != 0 && !v83 )
          {
            v34 = (void (__cdecl *)(char *, __crt_locale_pointers *))DecodePointer(off_4C9EF4);
            v34(v27, &Locale);
          }
          if ( v84 == 103 && !v33 )
          {
            v35 = (void (__cdecl *)(char *, __crt_locale_pointers *))DecodePointer(off_4C9EF0);
            v35(v27, &Locale);
          }
          if ( *v27 == 45 )
          {
            v85 |= 0x100u;
            v81 = ++v27;
          }
          v23 = strlen(v27);
LABEL_193:
          SizeConverted = v23;
LABEL_194:
          if ( v67 )
            goto LABEL_226;
          if ( (v85 & 0x40) != 0 )
          {
            if ( (v85 & 0x100) != 0 )
            {
              v78[0] = 45;
              goto LABEL_202;
            }
            if ( (v85 & 1) != 0 )
            {
              v78[0] = 43;
              goto LABEL_202;
            }
            if ( (v85 & 2) != 0 )
            {
              v78[0] = 32;
LABEL_202:
              v76 = 1;
            }
          }
          v45 = v75 - SizeConverted - v76;
          v64 = v45;
          if ( (v85 & 0xC) == 0 )
          {
            v46 = v75 - SizeConverted - v76;
            do
            {
              if ( v46 <= 0 )
                break;
              LOBYTE(v45) = 32;
              --v46;
              v45 = write_char_0(File, v45, &v80);
            }
            while ( v80 != -1 );
          }
          v47 = File;
          v48 = write_string_0(&v80, (int)File, v65, v78, v76);
          if ( (v85 & 8) != 0 && (v85 & 4) == 0 )
          {
            v49 = v64;
            do
            {
              if ( v49 <= 0 )
                break;
              LOBYTE(v48) = 48;
              --v49;
              v48 = write_char_0(v47, v48, &v80);
            }
            while ( v80 != -1 );
          }
          if ( v74 && SizeConverted > 0 )
          {
            v50 = (wchar_t *)v81;
            v63 = SizeConverted;
            while ( 1 )
            {
              v51 = *v50;
              --v63;
              ++v50;
              v52 = wctomb_s(&v61, v88, 6u, v51);
              if ( v52 || !v61 )
                break;
              v52 = write_string_0(&v80, (int)File, v65, v88, v61);
              if ( !v63 )
                goto LABEL_221;
            }
            v80 = -1;
          }
          else
          {
            v52 = write_string_0(&v80, (int)v47, v65, v81, SizeConverted);
          }
LABEL_221:
          if ( v80 >= 0 && (v85 & 4) != 0 )
          {
            v53 = v64;
            do
            {
              if ( v53 <= 0 )
                break;
              LOBYTE(v52) = 32;
              --v53;
              v52 = write_char_0(File, v52, &v80);
            }
            while ( v80 != -1 );
          }
          goto LABEL_226;
        }
        if ( v10 == 105 )
        {
          v5 = (int *)v82;
LABEL_119:
          v85 |= 0x40u;
LABEL_120:
          SizeConverted = 10;
$COMMON_INT$29325:
          if ( (v85 & 0x8000) != 0 || (v85 & 0x1000) != 0 )
          {
            v25 = v5 + 2;
            v26 = *((_QWORD *)v25 - 1);
          }
          else
          {
            v25 = v5 + 1;
            if ( (v85 & 0x20) != 0 )
            {
              v82 = (int)v25;
              if ( (v85 & 0x40) != 0 )
                LODWORD(v26) = *((__int16 *)v25 - 2);
              else
                LODWORD(v26) = *((unsigned __int16 *)v25 - 2);
              v26 = (int)v26;
LABEL_161:
              if ( (v85 & 0x40) != 0 && v26 < 0 )
              {
                v26 = -v26;
                v85 |= 0x100u;
              }
              v36 = HIDWORD(v26);
              v37 = v26;
              if ( (v85 & 0x9000) == 0 )
                v36 = 0;
              if ( v83 >= 0 )
              {
                v85 &= ~8u;
                if ( v83 > 512 )
                  v83 = 512;
              }
              else
              {
                v83 = 1;
              }
              if ( !(v36 | (unsigned int)v26) )
                v76 = 0;
              for ( j = &v87; ; --j )
              {
                v39 = v83--;
                if ( v39 <= 0 && !(v36 | v37) )
                  break;
                v57 = __PAIR64__(v36, v37);
                v40 = __PAIR64__(v36, v37) % SizeConverted;
                v41 = v40 + 48;
                v64 = HIDWORD(v40);
                v36 = (v57 / SizeConverted) >> 32;
                v37 = v57 / SizeConverted;
                if ( v41 > 57 )
                  LOBYTE(v41) = v68 + v41;
                *j = v41;
              }
              v42 = (char *)(&v87 - j);
              v43 = j + 1;
              SizeConverted = (int)v42;
              v81 = v43;
              if ( (v85 & 0x200) != 0 && (!v42 || *v43 != 48) )
              {
                *--v81 = 48;
                v23 = (int)(v42 + 1);
                goto LABEL_193;
              }
              goto LABEL_194;
            }
            LODWORD(v26) = *(v25 - 1);
            if ( (v85 & 0x40) != 0 )
              v26 = (int)v26;
            else
              HIDWORD(v26) = 0;
          }
          v82 = (int)v25;
          goto LABEL_161;
        }
        if ( v10 != 110 )
        {
          if ( v10 != 111 )
            goto LABEL_194;
          v5 = (int *)v82;
          SizeConverted = 8;
          if ( (v85 & 0x80u) != 0 )
            v85 |= 0x200u;
          goto $COMMON_INT$29325;
        }
        v82 += 4;
        v24 = *(_WORD **)(v82 - 4);
        if ( !_get_printf_count_output() )
          goto LABEL_2;
        if ( (v85 & 0x20) != 0 )
          *v24 = v80;
        else
          *(_DWORD *)v24 = v80;
        v67 = 1;
LABEL_226:
        if ( Block )
        {
          free(Block);
          Block = 0;
        }
LABEL_228:
        v4 = v73;
        v54 = *v73;
        v84 = v54;
        if ( !v54 )
          goto LABEL_230;
        v5 = (int *)v82;
        v10 = v54;
        break;
      default:
        goto LABEL_228;
    }
  }
LABEL_230:
  if ( !v72 || v72 == 7 )
  {
LABEL_232:
    if ( v71 )
      *(_DWORD *)(v70 + 112) &= ~2u;
    return v80;
  }
  else
  {
LABEL_2:
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( v71 )
      *(_DWORD *)(v70 + 112) &= ~2u;
    return -1;
  }
}
