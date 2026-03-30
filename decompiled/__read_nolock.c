unsigned int __cdecl _read_nolock(int FileHandle, CHAR *lpBuffer, DWORD nNumberOfBytesToRead)
{
  DWORD v3; // edx
  unsigned int result; // eax
  int v5; // eax
  int v6; // esi
  char v7; // cl
  CHAR *v8; // ebx
  int v9; // ecx
  CHAR *v10; // eax
  CHAR v11; // cl
  bool v12; // zf
  int v13; // ecx
  CHAR v14; // cl
  int v15; // ecx
  CHAR v16; // cl
  int v17; // ecx
  int v18; // eax
  char *v19; // eax
  CHAR *v20; // ebx
  CHAR v21; // al
  _BYTE *v22; // eax
  _BYTE *v23; // ebx
  int v24; // ecx
  int v25; // eax
  char v26; // dl
  _BYTE *v27; // ebx
  int v28; // ebx
  DWORD LastError; // eax
  int v30; // edx
  BOOL v31; // ecx
  CHAR *v32; // ebx
  int v33; // ecx
  _BYTE *v34; // esi
  __int16 v35; // [esp-Ch] [ebp-2Ch]
  DWORD v36; // [esp+4h] [ebp-1Ch]
  DWORD NumberOfBytesRead; // [esp+8h] [ebp-18h] BYREF
  int v38; // [esp+Ch] [ebp-14h]
  LPCCH lpMultiByteStr; // [esp+10h] [ebp-10h]
  unsigned int v40; // [esp+14h] [ebp-Ch]
  __int16 v41; // [esp+18h] [ebp-8h] BYREF
  char v42; // [esp+1Eh] [ebp-2h]
  char Buffer; // [esp+1Fh] [ebp-1h] BYREF
  LPCCH nNumberOfBytesToReada; // [esp+30h] [ebp+10h]
  LPCCH nNumberOfBytesToReadb; // [esp+30h] [ebp+10h]

  v3 = nNumberOfBytesToRead;
  v38 = -2;
  v36 = nNumberOfBytesToRead;
  if ( FileHandle == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( FileHandle < 0 || FileHandle >= uNumber )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  v5 = dword_4DCF40[FileHandle >> 5];
  v6 = (FileHandle & 0x1F) << 6;
  v7 = *(_BYTE *)(v5 + v6 + 4);
  if ( (v7 & 1) == 0 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_19:
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( nNumberOfBytesToRead > 0x7FFFFFFF )
    goto LABEL_18;
  v40 = 0;
  if ( !nNumberOfBytesToRead || (v7 & 2) != 0 )
    return 0;
  if ( !lpBuffer )
    goto LABEL_18;
  v42 = (char)(2 * *(_BYTE *)(v5 + v6 + 36)) >> 1;
  if ( v42 != 1 )
  {
    if ( v42 != 2 )
    {
LABEL_16:
      v8 = lpBuffer;
      lpMultiByteStr = lpBuffer;
      goto LABEL_26;
    }
    if ( (nNumberOfBytesToRead & 1) == 0 )
    {
      nNumberOfBytesToRead &= ~1u;
      goto LABEL_16;
    }
LABEL_18:
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_19;
  }
  if ( (nNumberOfBytesToRead & 1) != 0 )
    goto LABEL_18;
  nNumberOfBytesToRead = 4;
  if ( v3 >> 1 >= 4 )
    nNumberOfBytesToRead = v3 >> 1;
  v8 = (CHAR *)_malloc_crt(nNumberOfBytesToRead);
  lpMultiByteStr = v8;
  if ( !v8 )
  {
    *_errno() = 12;
    *__doserrno() = 8;
    return -1;
  }
  *(_QWORD *)(v6 + dword_4DCF40[FileHandle >> 5] + 40) = _lseeki64_nolock(FileHandle, 0, 0, 1u);
LABEL_26:
  v9 = v6 + dword_4DCF40[FileHandle >> 5];
  v10 = v8;
  if ( (*(_BYTE *)(v9 + 4) & 0x48) != 0 )
  {
    v11 = *(_BYTE *)(v9 + 5);
    if ( v11 != 10 )
    {
      if ( nNumberOfBytesToRead )
      {
        --nNumberOfBytesToRead;
        v12 = v42 == 0;
        *v8 = v11;
        v13 = dword_4DCF40[FileHandle >> 5];
        v10 = v8 + 1;
        v40 = 1;
        *(_BYTE *)(v6 + v13 + 5) = 10;
        if ( !v12 )
        {
          v14 = *(_BYTE *)(v6 + dword_4DCF40[FileHandle >> 5] + 37);
          if ( v14 != 10 )
          {
            if ( nNumberOfBytesToRead )
            {
              *v10 = v14;
              v15 = dword_4DCF40[FileHandle >> 5];
              v10 = v8 + 2;
              --nNumberOfBytesToRead;
              v12 = v42 == 1;
              v40 = 2;
              *(_BYTE *)(v6 + v15 + 37) = 10;
              if ( v12 )
              {
                v16 = *(_BYTE *)(v6 + dword_4DCF40[FileHandle >> 5] + 38);
                if ( v16 != 10 )
                {
                  if ( nNumberOfBytesToRead )
                  {
                    *v10 = v16;
                    v17 = dword_4DCF40[FileHandle >> 5];
                    v10 = v8 + 3;
                    --nNumberOfBytesToRead;
                    v40 = 3;
                    *(_BYTE *)(v6 + v17 + 38) = 10;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( !ReadFile(*(HANDLE *)(v6 + dword_4DCF40[FileHandle >> 5]), v10, nNumberOfBytesToRead, &NumberOfBytesRead, 0)
    || (NumberOfBytesRead & 0x80000000) != 0
    || NumberOfBytesRead > nNumberOfBytesToRead )
  {
    LastError = GetLastError();
    if ( LastError == 5 )
    {
      *_errno() = 9;
      *__doserrno() = 5;
      goto LABEL_93;
    }
    if ( LastError == 109 )
    {
      v38 = 0;
      goto $error_return$29001;
    }
    goto LABEL_92;
  }
  v18 = dword_4DCF40[FileHandle >> 5];
  v40 += NumberOfBytesRead;
  v19 = (char *)(v6 + v18 + 4);
  if ( *v19 < 0 )
  {
    if ( v42 != 2 )
    {
      if ( NumberOfBytesRead && *v8 == 10 )
        *v19 |= 4u;
      else
        *v19 &= ~4u;
      v20 = (CHAR *)lpMultiByteStr;
      nNumberOfBytesToReada = lpMultiByteStr;
      v40 += (unsigned int)lpMultiByteStr;
      if ( (unsigned int)lpMultiByteStr < v40 )
      {
        do
        {
          v21 = *nNumberOfBytesToReada;
          if ( *nNumberOfBytesToReada == 26 )
          {
            v22 = (_BYTE *)(v6 + dword_4DCF40[FileHandle >> 5] + 4);
            if ( (*v22 & 0x40) != 0 )
              *v20++ = *nNumberOfBytesToReada;
            else
              *v22 |= 2u;
            break;
          }
          if ( v21 == 13 )
          {
            if ( (unsigned int)nNumberOfBytesToReada < v40 - 1 )
            {
              if ( nNumberOfBytesToReada[1] == 10 )
              {
                nNumberOfBytesToReada += 2;
                goto LABEL_52;
              }
              ++nNumberOfBytesToReada;
LABEL_63:
              *v20 = 13;
LABEL_64:
              ++v20;
              continue;
            }
            ++nNumberOfBytesToReada;
            if ( !ReadFile(*(HANDLE *)(v6 + dword_4DCF40[FileHandle >> 5]), &Buffer, 1u, &NumberOfBytesRead, 0)
              && GetLastError()
              || !NumberOfBytesRead )
            {
              goto LABEL_63;
            }
            if ( (*(_BYTE *)(v6 + dword_4DCF40[FileHandle >> 5] + 4) & 0x48) != 0 )
            {
              if ( Buffer != 10 )
              {
                *v20 = 13;
                *(_BYTE *)(v6 + dword_4DCF40[FileHandle >> 5] + 5) = Buffer;
                goto LABEL_64;
              }
LABEL_52:
              *v20 = 10;
              goto LABEL_64;
            }
            if ( v20 == lpMultiByteStr && Buffer == 10 )
              goto LABEL_52;
            _lseeki64_nolock(FileHandle, -1, -1, 1u);
            if ( Buffer != 10 )
              goto LABEL_63;
          }
          else
          {
            *v20++ = v21;
            ++nNumberOfBytesToReada;
          }
        }
        while ( (unsigned int)nNumberOfBytesToReada < v40 );
      }
      v40 = v20 - lpMultiByteStr;
      if ( v42 != 1 || v20 == lpMultiByteStr )
        goto $error_return$29001;
      v23 = v20 - 1;
      LOBYTE(v24) = *v23;
      if ( (char)*v23 < 0 )
      {
        v25 = 1;
        v24 = (unsigned __int8)v24;
        while ( !byte_4CA498[v24] && v25 <= 4 && v23 >= lpMultiByteStr )
        {
          v24 = (unsigned __int8)*--v23;
          ++v25;
        }
        v26 = *v23;
        if ( !byte_4CA498[(unsigned __int8)*v23] )
        {
          *_errno() = 42;
LABEL_93:
          v38 = -1;
          goto $error_return$29001;
        }
        if ( byte_4CA498[(unsigned __int8)*v23] + 1 == v25 )
        {
          v23 += v25;
        }
        else if ( (*(_BYTE *)(dword_4DCF40[FileHandle >> 5] + v6 + 4) & 0x48) != 0 )
        {
          v27 = v23 + 1;
          *(_BYTE *)(dword_4DCF40[FileHandle >> 5] + v6 + 5) = v26;
          if ( v25 >= 2 )
            *(_BYTE *)(v6 + dword_4DCF40[FileHandle >> 5] + 37) = *v27++;
          if ( v25 == 3 )
            *(_BYTE *)(v6 + dword_4DCF40[FileHandle >> 5] + 38) = *v27++;
          v23 = &v27[-v25];
        }
        else
        {
          _lseeki64_nolock(FileHandle, -v25, -v25 >> 31, 1u);
        }
      }
      else
      {
        ++v23;
      }
      v28 = v23 - lpMultiByteStr;
      v40 = MultiByteToWideChar(0xFDE9u, 0, lpMultiByteStr, v28, (LPWSTR)lpBuffer, v36 >> 1);
      if ( v40 )
      {
        v30 = dword_4DCF40[FileHandle >> 5];
        v31 = v40 != v28;
        v40 *= 2;
        *(_DWORD *)(v6 + v30 + 48) = v31;
        goto $error_return$29001;
      }
      LastError = GetLastError();
LABEL_92:
      _dosmaperr(LastError);
      goto LABEL_93;
    }
    if ( NumberOfBytesRead && *(_WORD *)v8 == 10 )
      *v19 |= 4u;
    else
      *v19 &= ~4u;
    v32 = (CHAR *)lpMultiByteStr;
    nNumberOfBytesToReadb = lpMultiByteStr;
    v40 += (unsigned int)lpMultiByteStr;
    if ( (unsigned int)lpMultiByteStr >= v40 )
    {
LABEL_129:
      v40 = v32 - lpMultiByteStr;
      goto $error_return$29001;
    }
    while ( 1 )
    {
      v33 = *(unsigned __int16 *)nNumberOfBytesToReadb;
      if ( v33 == 26 )
      {
        v34 = (_BYTE *)(v6 + dword_4DCF40[FileHandle >> 5] + 4);
        if ( (*v34 & 0x40) != 0 )
        {
          *(_WORD *)v32 = *(_WORD *)nNumberOfBytesToReadb;
          v32 += 2;
        }
        else
        {
          *v34 |= 2u;
        }
        goto LABEL_129;
      }
      if ( v33 == 13 )
      {
        if ( (unsigned int)nNumberOfBytesToReadb < v40 - 2 )
        {
          if ( *((_WORD *)nNumberOfBytesToReadb + 1) == 10 )
          {
            nNumberOfBytesToReadb += 4;
            goto LABEL_110;
          }
          nNumberOfBytesToReadb += 2;
LABEL_121:
          v35 = 13;
LABEL_122:
          *(_WORD *)v32 = v35;
          goto LABEL_123;
        }
        nNumberOfBytesToReadb += 2;
        if ( !ReadFile(*(HANDLE *)(v6 + dword_4DCF40[FileHandle >> 5]), &v41, 2u, &NumberOfBytesRead, 0)
          && GetLastError()
          || !NumberOfBytesRead )
        {
          goto LABEL_121;
        }
        if ( (*(_BYTE *)(v6 + dword_4DCF40[FileHandle >> 5] + 4) & 0x48) != 0 )
        {
          if ( v41 != 10 )
          {
            *(_WORD *)v32 = 13;
            *(_BYTE *)(v6 + dword_4DCF40[FileHandle >> 5] + 5) = v41;
            *(_BYTE *)(v6 + dword_4DCF40[FileHandle >> 5] + 37) = HIBYTE(v41);
            *(_BYTE *)(v6 + dword_4DCF40[FileHandle >> 5] + 38) = 10;
LABEL_123:
            v32 += 2;
            goto LABEL_124;
          }
LABEL_110:
          v35 = 10;
          goto LABEL_122;
        }
        if ( v32 == lpMultiByteStr && v41 == 10 )
          goto LABEL_110;
        _lseeki64_nolock(FileHandle, -2, -1, 1u);
        if ( v41 != 10 )
          goto LABEL_121;
      }
      else
      {
        *(_WORD *)v32 = v33;
        v32 += 2;
        nNumberOfBytesToReadb += 2;
      }
LABEL_124:
      if ( (unsigned int)nNumberOfBytesToReadb >= v40 )
        goto LABEL_129;
    }
  }
$error_return$29001:
  if ( lpMultiByteStr != lpBuffer )
    free((void *)lpMultiByteStr);
  result = v38;
  if ( v38 == -2 )
    return v40;
  return result;
}
