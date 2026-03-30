int __cdecl _write_nolock(int FileHandle, const void *a2, DWORD nNumberOfBytesToWrite)
{
  int v4; // eax
  int v5; // edi
  char v6; // cl
  BOOL v7; // esi
  UINT ConsoleCP; // eax
  const char *v9; // ebx
  CHAR v10; // cl
  int *v11; // esi
  int v12; // eax
  int v13; // eax
  DWORD v14; // eax
  signed int v15; // esi
  int v16; // eax
  int v17; // esi
  int v18; // ecx
  char v19; // dl
  CHAR *v20; // ebx
  unsigned int v21; // esi
  DWORD v22; // ecx
  CHAR *v23; // eax
  CHAR v24; // dl
  signed int v25; // esi
  char *v26; // ebx
  DWORD v27; // ecx
  CHAR *v28; // eax
  int v29; // edx
  signed int v30; // esi
  DWORD v31; // ecx
  WCHAR *v32; // eax
  int v33; // edx
  int v34; // esi
  int v35; // ebx
  BOOL v36; // [esp+8h] [ebp-1AE4h]
  DWORD Mode; // [esp+Ch] [ebp-1AE0h] BYREF
  int *v38; // [esp+10h] [ebp-1ADCh]
  DWORD v39; // [esp+14h] [ebp-1AD8h] BYREF
  DWORD NumberOfBytesWritten; // [esp+18h] [ebp-1AD4h] BYREF
  int v41; // [esp+1Ch] [ebp-1AD0h]
  LPCVOID lpBuffer; // [esp+20h] [ebp-1ACCh]
  DWORD v43; // [esp+24h] [ebp-1AC8h]
  char v44; // [esp+2Bh] [ebp-1AC1h]
  DWORD v45; // [esp+2Ch] [ebp-1AC0h]
  WCHAR WideCharStr[2]; // [esp+30h] [ebp-1ABCh] BYREF
  CHAR Buffer[1704]; // [esp+34h] [ebp-1AB8h] BYREF
  CHAR v48[3416]; // [esp+6DCh] [ebp-1410h] BYREF
  WCHAR v49[854]; // [esp+1434h] [ebp-6B8h] BYREF
  CHAR MultiByteStr[8]; // [esp+1AE0h] [ebp-Ch] BYREF

  lpBuffer = a2;
  v43 = 0;
  v41 = 0;
  if ( !nNumberOfBytesToWrite )
    return 0;
  if ( !a2 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v4 = dword_4DCF40[FileHandle >> 5];
  v5 = (FileHandle & 0x1F) << 6;
  v6 = (char)(2 * *(_BYTE *)(v4 + v5 + 36)) >> 1;
  v38 = (int *)(4 * (FileHandle >> 5) + 5099328);
  v44 = v6;
  if ( (v6 == 2 || v6 == 1) && (nNumberOfBytesToWrite & 1) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( (*(_BYTE *)(v4 + v5 + 4) & 0x20) != 0 )
    _lseeki64_nolock(FileHandle, 0, 0, 2u);
  if ( _isatty(FileHandle) )
  {
    if ( *(char *)(v5 + dword_4DCF40[FileHandle >> 5] + 4) < 0 )
    {
      v7 = *(_DWORD *)(_getptd()[27] + 20) == 0;
      if ( GetConsoleMode(*(HANDLE *)(v5 + dword_4DCF40[FileHandle >> 5]), &Mode) )
      {
        if ( !v7 || v44 )
        {
          ConsoleCP = GetConsoleCP();
          v9 = (const char *)lpBuffer;
          Mode = ConsoleCP;
          NumberOfBytesWritten = 0;
          v45 = 0;
          while ( 1 )
          {
            if ( v44 )
            {
              if ( v44 == 1 || v44 == 2 )
              {
                v17 = *(unsigned __int16 *)v9;
                v9 += 2;
                v45 += 2;
                *(_DWORD *)WideCharStr = v17;
                v36 = v17 == 10;
              }
              if ( v44 == 1 || v44 == 2 )
              {
                if ( _putwch_nolock(WideCharStr[0]) != WideCharStr[0] )
                  goto LABEL_85;
                v43 += 2;
                if ( v36 )
                {
                  wcscpy(WideCharStr, L"\r");
                  if ( _putwch_nolock(0xDu) != WideCharStr[0] )
                    goto LABEL_85;
                  ++v43;
                  ++v41;
                }
              }
              goto LABEL_43;
            }
            v10 = *v9;
            v11 = v38;
            v36 = *v9 == 10;
            v12 = v5 + *v38;
            if ( *(_DWORD *)(v12 + 56) )
            {
              MultiByteStr[0] = *(_BYTE *)(v12 + 52);
              MultiByteStr[1] = v10;
              *(_DWORD *)(v12 + 56) = 0;
              v13 = mbtowc(WideCharStr, MultiByteStr, 2u);
            }
            else
            {
              if ( isleadbyte(v10) )
              {
                if ( nNumberOfBytesToWrite + (_BYTE *)lpBuffer - v9 <= 1 )
                {
                  v18 = *v11;
                  v19 = *v9;
                  ++v43;
                  *(_BYTE *)(v5 + v18 + 52) = v19;
                  *(_DWORD *)(v5 + *v11 + 56) = 1;
                  goto LABEL_86;
                }
                if ( mbtowc(WideCharStr, v9, 2u) == -1 )
                  goto LABEL_86;
                ++v9;
                ++v45;
                goto LABEL_27;
              }
              v13 = mbtowc(WideCharStr, v9, 1u);
            }
            if ( v13 == -1 )
              goto LABEL_86;
LABEL_27:
            ++v9;
            ++v45;
            v14 = WideCharToMultiByte(Mode, 0, WideCharStr, 1, MultiByteStr, 5, 0, 0);
            v15 = v14;
            if ( !v14 )
              goto LABEL_86;
            if ( !WriteFile(*(HANDLE *)(v5 + *v38), MultiByteStr, v14, &NumberOfBytesWritten, 0) )
              goto LABEL_85;
            v43 = v41 + v45;
            if ( (int)NumberOfBytesWritten < v15 )
              goto LABEL_86;
            if ( v36 )
            {
              v16 = *v38;
              MultiByteStr[0] = 13;
              if ( !WriteFile(*(HANDLE *)(v5 + v16), MultiByteStr, 1u, &NumberOfBytesWritten, 0) )
                goto LABEL_85;
              if ( (int)NumberOfBytesWritten < 1 )
                goto LABEL_86;
              ++v41;
              ++v43;
            }
LABEL_43:
            if ( v45 >= nNumberOfBytesToWrite )
              goto LABEL_86;
          }
        }
      }
    }
  }
  if ( *(char *)(dword_4DCF40[FileHandle >> 5] + v5 + 4) >= 0 )
  {
    if ( WriteFile(
           *(HANDLE *)(dword_4DCF40[FileHandle >> 5] + ((FileHandle & 0x1F) << 6)),
           lpBuffer,
           nNumberOfBytesToWrite,
           &v39,
           0) )
    {
      *(_DWORD *)WideCharStr = 0;
      v43 = v39;
      goto LABEL_86;
    }
  }
  else
  {
    *(_DWORD *)WideCharStr = 0;
    if ( v44 )
    {
      if ( v44 == 2 )
      {
        v26 = (char *)lpBuffer;
        while ( 1 )
        {
          v45 = 0;
          v27 = v26 - (_BYTE *)lpBuffer;
          v28 = Buffer;
          do
          {
            if ( v27 >= nNumberOfBytesToWrite )
              break;
            v29 = *(unsigned __int16 *)v26;
            v26 += 2;
            v27 += 2;
            Mode = (DWORD)v26;
            if ( v29 == 10 )
            {
              v41 += 2;
              *(_WORD *)v28 = 13;
              v26 = (char *)Mode;
              v28 += 2;
              v45 += 2;
            }
            v45 += 2;
            *(_WORD *)v28 = v29;
            v28 += 2;
          }
          while ( v45 < 0x13FE );
          v30 = v28 - Buffer;
          if ( !WriteFile(*(HANDLE *)(v5 + *v38), Buffer, v28 - Buffer, &v39, 0) )
            break;
          v43 += v39;
          if ( (int)v39 < v30 || v26 - (_BYTE *)lpBuffer >= nNumberOfBytesToWrite )
            goto LABEL_86;
        }
      }
      else
      {
        NumberOfBytesWritten = (DWORD)lpBuffer;
        while ( 1 )
        {
          v45 = 0;
          v31 = NumberOfBytesWritten - (_DWORD)lpBuffer;
          v32 = v49;
          do
          {
            if ( v31 >= nNumberOfBytesToWrite )
              break;
            v33 = *(unsigned __int16 *)NumberOfBytesWritten;
            NumberOfBytesWritten += 2;
            v31 += 2;
            if ( v33 == 10 )
            {
              *v32++ = 13;
              v45 += 2;
            }
            v45 += 2;
            *v32++ = v33;
          }
          while ( v45 < 0x6A8 );
          v34 = 0;
          v35 = WideCharToMultiByte(0xFDE9u, 0, v49, v32 - v49, v48, 3413, 0, 0);
          if ( !v35 )
            break;
          while ( WriteFile(*(HANDLE *)(v5 + *v38), &v48[v34], v35 - v34, &v39, 0) )
          {
            v34 += v39;
            if ( v35 <= v34 )
              goto LABEL_80;
          }
          *(_DWORD *)WideCharStr = GetLastError();
LABEL_80:
          if ( v35 <= v34 )
          {
            v43 = NumberOfBytesWritten - (_DWORD)lpBuffer;
            if ( NumberOfBytesWritten - (unsigned int)lpBuffer < nNumberOfBytesToWrite )
              continue;
          }
          goto LABEL_86;
        }
      }
    }
    else
    {
      v20 = (CHAR *)lpBuffer;
      while ( 1 )
      {
        v21 = 0;
        v22 = v20 - (_BYTE *)lpBuffer;
        v23 = Buffer;
        do
        {
          if ( v22 >= nNumberOfBytesToWrite )
            break;
          v24 = *v20++;
          ++v22;
          Mode = (DWORD)v20;
          if ( v24 == 10 )
          {
            ++v41;
            *v23++ = 13;
            ++v21;
          }
          *v23++ = v24;
          ++v21;
        }
        while ( v21 < 0x13FF );
        v25 = v23 - Buffer;
        if ( !WriteFile(*(HANDLE *)(v5 + *v38), Buffer, v23 - Buffer, &v39, 0) )
          break;
        v43 += v39;
        if ( (int)v39 < v25 || v20 - (_BYTE *)lpBuffer >= nNumberOfBytesToWrite )
          goto LABEL_86;
      }
    }
  }
LABEL_85:
  *(_DWORD *)WideCharStr = GetLastError();
LABEL_86:
  if ( !v43 )
  {
    if ( *(_DWORD *)WideCharStr )
    {
      if ( *(_DWORD *)WideCharStr == 5 )
      {
        *_errno() = 9;
        *__doserrno() = 5;
      }
      else
      {
        _dosmaperr(*(unsigned int *)WideCharStr);
      }
    }
    else
    {
      if ( (*(_BYTE *)(v5 + *v38 + 4) & 0x40) != 0 && *(_BYTE *)lpBuffer == 26 )
        return 0;
      *_errno() = 28;
      *__doserrno() = 0;
    }
    return -1;
  }
  return v43 - v41;
}
