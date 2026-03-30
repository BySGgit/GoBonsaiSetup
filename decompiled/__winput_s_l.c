int __cdecl _winput_s_l(FILE *a1, wint_t *a2, struct localeinfo_struct *a3, char **a4)
{
  int result; // eax
  wint_t v5; // ax
  wint_t v6; // ax
  wint_t *v7; // esi
  wint_t *v8; // esi
  int v9; // ebx
  int v10; // ecx
  char *v11; // ebx
  int v12; // eax
  int v13; // edi
  wint_t v14; // ax
  rsize_t v15; // eax
  int v16; // eax
  int v17; // ebx
  int v18; // ebx
  wchar_t v20; // si
  wint_t v24; // ax
  size_t v27; // esi
  char *v28; // edi
  errno_t v29; // eax
  void (__cdecl *v30)(int, char *, char *, _DWORD *); // eax
  char *v31; // esi
  wint_t v33; // ax
  unsigned __int16 *v34; // edi
  _BYTE *v35; // esi
  void *v36; // eax
  unsigned __int16 v37; // dx
  int v38; // ecx
  unsigned __int16 v39; // ax
  unsigned int v40; // ebx
  unsigned __int16 v41; // ax
  wint_t v42; // ax
  int v43; // eax
  wint_t v44; // ax
  wint_t v45; // cx
  int *v46; // eax
  bool v47; // zf
  int v48; // [esp-14h] [ebp-364h]
  char *v49; // [esp-10h] [ebp-360h]
  FILE *v50; // [esp-8h] [ebp-358h]
  _DWORD v51[2]; // [esp+Ch] [ebp-344h] BYREF
  int v52; // [esp+14h] [ebp-33Ch]
  char v53; // [esp+18h] [ebp-338h]
  int v54; // [esp+1Ch] [ebp-334h]
  int v55; // [esp+20h] [ebp-330h]
  char **v56; // [esp+24h] [ebp-32Ch]
  char **v57; // [esp+28h] [ebp-328h]
  void *Block; // [esp+2Ch] [ebp-324h]
  int v59; // [esp+30h] [ebp-320h] BYREF
  size_t v60; // [esp+34h] [ebp-31Ch] BYREF
  int v61; // [esp+38h] [ebp-318h]
  int v62; // [esp+3Ch] [ebp-314h]
  rsize_t SizeInBytes; // [esp+40h] [ebp-310h]
  int v64; // [esp+44h] [ebp-30Ch]
  char *v65; // [esp+48h] [ebp-308h]
  wint_t *v66; // [esp+4Ch] [ebp-304h]
  char v67; // [esp+53h] [ebp-2FDh]
  __int64 v68; // [esp+54h] [ebp-2FCh]
  int v69; // [esp+5Ch] [ebp-2F4h]
  int SizeConverted; // [esp+60h] [ebp-2F0h] BYREF
  int v71; // [esp+64h] [ebp-2ECh]
  wchar_t *Src; // [esp+68h] [ebp-2E8h] BYREF
  char v73; // [esp+6Dh] [ebp-2E3h]
  char v74; // [esp+6Eh] [ebp-2E2h]
  char v75; // [esp+6Fh] [ebp-2E1h]
  FILE *Stream; // [esp+70h] [ebp-2E0h]
  char v77; // [esp+77h] [ebp-2D9h]
  int v78; // [esp+78h] [ebp-2D8h]
  char v79; // [esp+7Fh] [ebp-2D1h]
  int v80; // [esp+80h] [ebp-2D0h]
  char v81; // [esp+87h] [ebp-2C9h]
  int v82; // [esp+88h] [ebp-2C8h] BYREF
  char v83; // [esp+8Fh] [ebp-2C1h]
  _BYTE v84[700]; // [esp+90h] [ebp-2C0h] BYREF

  v57 = a4;
  Stream = a1;
  v66 = a2;
  Src = (wchar_t *)v84;
  v60 = 350;
  v59 = 0;
  Block = 0;
  v55 = 0;
  v80 = 0;
  v54 = 0;
  if ( !a2 || !a1 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v51, a3);
  v5 = *a2;
  v74 = 0;
  v82 = 0;
  v62 = 0;
  if ( !v5 )
    goto LABEL_289;
  while ( 2 )
  {
    if ( iswctype(v5, 8u) )
    {
      v50 = Stream;
      --v82;
      v6 = _whiteout(&v82, Stream);
      _un_inc(v6, v50);
      v7 = v66;
      do
        ++v7;
      while ( iswctype(*v7, 8u) );
      v66 = v7;
      goto LABEL_265;
    }
    v8 = v66;
    if ( *v66 != 37 )
      goto LABEL_260;
    if ( v66[1] == 37 )
    {
      v8 = v66 + 1;
LABEL_260:
      ++v82;
      v44 = _fgetwc_nolock(Stream);
      v45 = *v8;
      v7 = v8 + 1;
      v80 = v44;
      v66 = v7;
      if ( v45 == v44 )
        goto LABEL_261;
LABEL_276:
      _un_inc(v80, Stream);
      goto $error_return$29803;
    }
    v69 = 0;
    v71 = 0;
    v64 = 0;
    v78 = 0;
    SizeInBytes = 0;
    v67 = 0;
    v73 = 0;
    v79 = 0;
    v83 = 0;
    v75 = 0;
    v81 = 0;
    v77 = 1;
    SizeConverted = 0;
    do
    {
      v9 = *++v8;
      if ( (v9 & 0xFF00) == 0 && isdigit((unsigned __int8)v9) )
      {
        ++v64;
        v78 = 10 * v78 + v9 - 48;
        continue;
      }
      if ( v9 > 78 )
      {
        if ( v9 == 104 )
        {
          --v77;
          --v81;
        }
        else
        {
          if ( v9 == 108 )
          {
            if ( v8[1] == 108 )
            {
              ++v8;
              goto LABEL_25;
            }
            ++v77;
          }
          else if ( v9 != 119 )
          {
            goto $DEFAULT_LABEL$29775;
          }
          ++v81;
        }
      }
      else
      {
        switch ( v9 )
        {
          case 'N':
            continue;
          case '*':
            ++v79;
            continue;
          case 'F':
            continue;
        }
        if ( v9 != 73 )
        {
          if ( v9 == 76 )
          {
            ++v77;
            continue;
          }
$DEFAULT_LABEL$29775:
          ++v83;
          continue;
        }
        v10 = v8[1];
        if ( v10 == 54 && v8[2] == 52 )
        {
          v8 += 2;
LABEL_25:
          ++SizeConverted;
          v68 = 0;
          continue;
        }
        if ( v10 == 51 && v8[2] == 50 )
        {
          v8 += 2;
          continue;
        }
        if ( v10 != 100 && v10 != 105 && v10 != 111 && v10 != 120 && v10 != 88 )
          goto $DEFAULT_LABEL$29775;
      }
    }
    while ( !v83 );
    v66 = v8;
    if ( v79 )
    {
      v11 = 0;
    }
    else
    {
      v11 = *v57;
      v56 = v57++;
    }
    v65 = v11;
    v83 = 0;
    if ( !v81 )
    {
      v12 = *v8;
      if ( v12 == 83 || (v81 = 1, v12 == 67) )
        v81 = -1;
    }
    v13 = *v8 | 0x20;
    v61 = v13;
    if ( v13 != 110 )
    {
      if ( v13 == 99 || v13 == 123 )
      {
        ++v82;
        v14 = _fgetwc_nolock(Stream);
      }
      else
      {
        v14 = _whiteout(&v82, Stream);
      }
      v80 = v14;
      if ( v14 == 0xFFFF )
        goto $error_return$29803;
      v11 = v65;
      v8 = v66;
    }
    if ( v64 && !v78 )
      goto LABEL_276;
    if ( !v79 && (v13 == 99 || v13 == 115 || v13 == 123) )
    {
      v11 = *v56++;
      v57 = v56 + 1;
      v15 = (rsize_t)*v56;
      v65 = v11;
      SizeInBytes = v15;
      if ( !v15 )
      {
        if ( v81 <= 0 )
          *v11 = 0;
        else
          *(_WORD *)v11 = 0;
        *_errno() = 12;
        goto $error_return$29803;
      }
    }
    if ( v13 <= 111 )
    {
      if ( v13 == 111 )
        goto LABEL_205;
      if ( v13 != 99 )
      {
        if ( v13 != 100 )
        {
          if ( v13 <= 100 )
            goto LABEL_148;
          if ( v13 > 103 )
          {
            if ( v13 != 105 )
            {
              if ( v13 == 110 )
              {
                v16 = v82;
                if ( v79 )
                  goto LABEL_258;
                goto $assign_num$29984;
              }
LABEL_148:
              if ( *v8 == (_WORD)v80 )
              {
                --v74;
                if ( !v79 )
                  v57 = v56;
                goto LABEL_258;
              }
              _un_inc(v80, Stream);
              v54 = 1;
              goto $error_return$29803;
            }
            v61 = 100;
            v13 = 100;
LABEL_78:
            LOWORD(v17) = v80;
            if ( (_WORD)v80 == 45 )
            {
              v73 = 1;
              goto $x_incwidth$29909;
            }
            if ( (_WORD)v80 == 43 )
            {
$x_incwidth$29909:
              if ( --v78 || !v64 )
              {
                ++v82;
                LOWORD(v17) = _fgetwc_nolock(Stream);
                v80 = (unsigned __int16)v17;
              }
              else
              {
                v83 = 1;
              }
            }
            if ( (_WORD)v17 == 48 )
            {
              ++v82;
              v42 = _fgetwc_nolock(Stream);
              LOWORD(v17) = v42;
              v80 = v42;
              if ( v42 == 120 || v42 == 88 )
              {
                ++v82;
                LOWORD(v17) = _fgetwc_nolock(Stream);
                v80 = (unsigned __int16)v17;
                if ( v64 )
                {
                  v78 -= 2;
                  if ( v78 < 1 )
                    ++v83;
                }
                v61 = 120;
LABEL_192:
                v13 = v61;
              }
              else
              {
                v71 = 1;
                if ( v13 != 120 )
                {
                  if ( v64 )
                  {
                    if ( !--v78 )
                      ++v83;
                  }
                  v61 = 111;
                  goto LABEL_192;
                }
                --v82;
                _un_inc(v42, Stream);
                v17 = 48;
LABEL_212:
                v80 = v17;
              }
            }
            goto $getnum$29926;
          }
          v18 = 0;
          if ( (_WORD)v80 == 45 )
          {
            *Src = 45;
            v18 = 1;
            goto $f_incwidth$30002;
          }
          if ( (_WORD)v80 == 43 )
          {
$f_incwidth$30002:
            --v78;
            ++v82;
            v80 = _fgetwc_nolock(Stream);
          }
          if ( !v64 )
            v78 = -1;
          for ( ; (v80 & 0xFF00) == 0; v80 = _fgetwc_nolock(Stream) )
          {
            if ( !isdigit((unsigned __int8)v80) )
              break;
            if ( !v78-- )
              break;
            ++v71;
            Src[v18++] = (char)v80;
            if ( !__check_float_string((void **)&Src, &v60, v18, v84, &v59) )
              goto $error_return$29803;
            ++v82;
          }
          v20 = **(_WORD **)(*(_DWORD *)(v51[0] + 188) + 48);
          if ( v20 == (char)v80 )
          {
            if ( v78-- )
            {
              ++v82;
              v80 = _fgetwc_nolock(Stream);
              Src[v18++] = v20;
              if ( !__check_float_string((void **)&Src, &v60, v18, v84, &v59) )
                goto $error_return$29803;
              for ( ; (v80 & 0xFF00) == 0; v80 = _fgetwc_nolock(Stream) )
              {
                if ( !isdigit((unsigned __int8)v80) )
                  break;
                if ( !v78-- )
                  break;
                ++v71;
                Src[v18++] = v80;
                if ( !__check_float_string((void **)&Src, &v60, v18, v84, &v59) )
                  goto $error_return$29803;
                ++v82;
              }
            }
          }
          if ( v71 && ((_WORD)v80 == 101 || (_WORD)v80 == 69) )
          {
            if ( v78-- )
            {
              Src[v18++] = 101;
              if ( !__check_float_string((void **)&Src, &v60, v18, v84, &v59) )
                goto $error_return$29803;
              ++v82;
              v24 = _fgetwc_nolock(Stream);
              v80 = v24;
              if ( v24 == 45 )
              {
                Src[v18++] = 45;
                if ( !__check_float_string((void **)&Src, &v60, v18, v84, &v59) )
                  goto $error_return$29803;
$f_incwidth2$30030:
                if ( v78-- )
                {
                  ++v82;
                  v80 = _fgetwc_nolock(Stream);
                }
                else
                {
                  v78 = 0;
                }
              }
              else if ( (_WORD)v80 == 43 )
              {
                goto $f_incwidth2$30030;
              }
              for ( ; (v80 & 0xFF00) == 0; v80 = _fgetwc_nolock(Stream) )
              {
                if ( !isdigit((unsigned __int8)v80) )
                  break;
                if ( !v78-- )
                  break;
                ++v71;
                Src[v18++] = v80;
                if ( !__check_float_string((void **)&Src, &v60, v18, v84, &v59) )
                  goto $error_return$29803;
                ++v82;
              }
            }
          }
          --v82;
          _un_inc(v80, Stream);
          if ( v71 )
          {
            if ( v79 )
              goto LABEL_258;
            ++v62;
            v27 = 2 * v60 + 2;
            Src[v18] = 0;
            v28 = (char *)_malloc_crt(v27);
            if ( v28 )
            {
              v29 = wcstombs_s(0, v28, v27, Src, v27 - 1);
              if ( v29 && (v29 == 22 || v29 == 34) )
                _invoke_watson(0, 0, 0, 0, 0);
              v49 = v65;
              v48 = v77 - 1;
              v30 = (void (__cdecl *)(int, char *, char *, _DWORD *))DecodePointer(off_4C9EEC);
              v30(v48, v49, v28, v51);
              free(v28);
              goto LABEL_258;
            }
          }
          goto $error_return$29803;
        }
LABEL_205:
        LOWORD(v17) = v80;
        if ( (_WORD)v80 == 45 )
        {
          v73 = 1;
        }
        else if ( (_WORD)v80 != 43 )
        {
          goto $getnum$29926;
        }
        if ( --v78 || !v64 )
        {
          ++v82;
          v17 = _fgetwc_nolock(Stream);
          goto LABEL_212;
        }
        v83 = 1;
$getnum$29926:
        if ( SizeConverted )
        {
          if ( !v83 )
          {
            while ( 1 )
            {
              if ( v13 == 120 || v13 == 112 )
              {
                if ( (v17 & 0xFF00) != 0 || !isxdigit((unsigned __int8)v17) )
                {
LABEL_229:
                  --v82;
                  _un_inc(v17, Stream);
                  break;
                }
                v68 *= 16;
                LOWORD(v17) = _hextodec(v17);
                v80 = (unsigned __int16)v17;
              }
              else
              {
                if ( (v17 & 0xFF00) != 0 || !isdigit((unsigned __int8)v17) )
                  goto LABEL_229;
                if ( v13 == 111 )
                {
                  if ( (unsigned __int16)v17 >= 0x38u )
                    goto LABEL_229;
                  v68 *= 8;
                }
                else
                {
                  v68 *= 10;
                }
              }
              ++v71;
              v68 += (unsigned __int16)v17 - 48;
              if ( v64 )
              {
                if ( !--v78 )
                  break;
              }
              ++v82;
              LOWORD(v17) = _fgetwc_nolock(Stream);
              v80 = (unsigned __int16)v17;
            }
          }
          if ( v73 )
            v68 = -v68;
        }
        else
        {
          if ( !v83 )
          {
            while ( 1 )
            {
              if ( v13 == 120 || v13 == 112 )
              {
                if ( (v17 & 0xFF00) != 0 || !isxdigit((unsigned __int8)v17) )
                {
LABEL_247:
                  --v82;
                  _un_inc(v17, Stream);
                  break;
                }
                v69 *= 16;
                v17 = (unsigned __int16)_hextodec(v17);
                v43 = v69;
                v80 = v17;
              }
              else
              {
                if ( (v17 & 0xFF00) != 0 || !isdigit((unsigned __int8)v17) )
                  goto LABEL_247;
                if ( v13 == 111 )
                {
                  if ( (unsigned __int16)v17 >= 0x38u )
                    goto LABEL_247;
                  v43 = 8 * v69;
                }
                else
                {
                  v43 = 10 * v69;
                }
              }
              ++v71;
              v69 = v43 + (unsigned __int16)v17 - 48;
              if ( v64 )
              {
                if ( !--v78 )
                  break;
              }
              ++v82;
              LOWORD(v17) = _fgetwc_nolock(Stream);
              v80 = (unsigned __int16)v17;
            }
          }
          if ( v73 )
            v69 = -v69;
        }
        if ( !v71 )
          goto $error_return$29803;
        if ( v79 )
          goto LABEL_258;
        ++v62;
        v11 = v65;
        v16 = v69;
$assign_num$29984:
        if ( SizeConverted )
        {
          *(_QWORD *)v11 = v68;
        }
        else if ( v77 )
        {
          *(_DWORD *)v11 = v16;
        }
        else
        {
          *(_WORD *)v11 = v16;
        }
        goto LABEL_258;
      }
      if ( !v64 )
      {
        ++v78;
        v64 = 1;
      }
LABEL_125:
      if ( v81 > 0 )
        v75 = 1;
$scanit$29836:
      --v82;
      v31 = v11;
      _un_inc(v80, Stream);
      if ( v13 != 99 )
LABEL_128:
        --SizeInBytes;
      while ( 2 )
      {
        if ( v64 )
        {
          if ( !v78-- )
            goto LABEL_198;
        }
        ++v82;
        v33 = _fgetwc_nolock(Stream);
        v80 = v33;
        if ( v33 == 0xFFFF )
          break;
        if ( v13 == 99 )
          goto LABEL_139;
        if ( v13 != 115 )
          goto LABEL_137;
        if ( v33 < 9u || v33 > 0xDu )
        {
          if ( v33 == 32 )
          {
LABEL_137:
            if ( v13 != 123 )
              break;
            v13 = v61;
            if ( ((1 << (v33 & 7)) & (v67 ^ *((char *)Block + (v33 >> 3)))) == 0 )
              break;
          }
LABEL_139:
          if ( v79 )
          {
            v31 += 2;
          }
          else
          {
            if ( !SizeInBytes )
              goto LABEL_273;
            if ( v75 )
            {
              *(_WORD *)v11 = v33;
              v11 += 2;
              v65 = v11;
              goto LABEL_128;
            }
            SizeConverted = 0;
            if ( wctomb_s(&SizeConverted, v11, SizeInBytes, v33) == 34 )
            {
LABEL_273:
              v46 = _errno();
              v47 = v75 == 0;
              *v46 = 12;
              if ( v47 )
                *v31 = 0;
              else
                *(_WORD *)v31 = 0;
              goto $error_return$29803;
            }
            if ( SizeConverted > 0 )
            {
              v11 += SizeConverted;
              SizeInBytes -= SizeConverted;
              v65 = v11;
            }
          }
          continue;
        }
        break;
      }
      --v82;
      _un_inc(v33, Stream);
LABEL_198:
      if ( v31 == v11 )
        goto $error_return$29803;
      if ( !v79 )
      {
        ++v62;
        if ( v13 != 99 )
        {
          if ( v75 )
            *(_WORD *)v65 = 0;
          else
            *v65 = 0;
        }
      }
LABEL_258:
      ++v74;
      v7 = ++v66;
LABEL_261:
      if ( (_WORD)v80 == 0xFFFF )
      {
        if ( *v7 == 37 && v66[1] == 110 )
        {
          v7 = v66;
          goto LABEL_265;
        }
        goto $error_return$29803;
      }
LABEL_265:
      v5 = *v7;
      if ( !*v7 )
        goto $error_return$29803;
      continue;
    }
    break;
  }
  switch ( v13 )
  {
    case 'p':
      v77 = 1;
      goto LABEL_205;
    case 's':
      goto LABEL_125;
    case 'u':
      goto LABEL_205;
    case 'x':
      goto LABEL_78;
  }
  if ( v13 != 123 )
    goto LABEL_148;
  if ( v81 > 0 )
    v75 = 1;
  v34 = v8 + 1;
  if ( v8[1] == 94 )
  {
    v34 = v8 + 2;
    v67 = -1;
  }
  v35 = Block;
  if ( !Block )
  {
    v36 = _malloc_crt(0x2000u);
    Block = v36;
    if ( !v36 )
      goto $error_return$29803;
    v55 = 1;
    v35 = v36;
  }
  memset(v35, 0, 0x2000u);
  if ( *v34 == 93 )
  {
    v37 = 93;
    ++v34;
    v35[11] = 32;
  }
  else
  {
    v37 = 0;
  }
  while ( 1 )
  {
    v41 = *v34;
    if ( *v34 == 93 )
      break;
    ++v34;
    if ( v41 == 45 && v37 && (v38 = *v34, (_WORD)v38 != 93) )
    {
      v39 = *v34++;
      if ( v37 >= (unsigned __int16)v38 )
      {
        v38 = v37;
        v37 = v39;
      }
      SizeConverted = v38;
      if ( v37 < (unsigned __int16)v38 )
      {
        v40 = v37;
        v69 = (unsigned __int16)(v38 - v37);
        do
        {
          v35[v40 >> 3] |= 1 << (v40 & 7);
          ++v40;
          --v69;
        }
        while ( v69 );
      }
      v35[(unsigned __int16)SizeConverted >> 3] |= 1 << (SizeConverted & 7);
      v37 = 0;
    }
    else
    {
      v37 = v41;
      v35[v41 >> 3] |= 1 << (v41 & 7);
    }
  }
  if ( *v34 )
  {
    v11 = v65;
    v66 = v34;
    v13 = v61;
    goto $scanit$29836;
  }
$error_return$29803:
  if ( v55 == 1 )
    free(Block);
  if ( v59 == 1 )
    free(Src);
  if ( (_WORD)v80 == 0xFFFF )
  {
    result = v62;
    if ( !v62 && !v74 )
      result = -1;
    if ( v53 )
      *(_DWORD *)(v52 + 112) &= ~2u;
    return result;
  }
  if ( v54 == 1 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
  }
LABEL_289:
  if ( v53 )
    *(_DWORD *)(v52 + 112) &= ~2u;
  return v62;
}
