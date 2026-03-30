int __cdecl _read(int FileHandle, void *DstBuf, unsigned int MaxCharCount)
{
  int v4; // esi
  unsigned int nolock; // [esp+14h] [ebp-1Ch]

  if ( FileHandle == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( FileHandle < 0
    || FileHandle >= uNumber
    || (v4 = (FileHandle & 0x1F) << 6, (*(_BYTE *)(dword_4DCF40[FileHandle >> 5] + v4 + 4) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_7:
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( MaxCharCount > 0x7FFFFFFF )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_7;
  }
  __lock_fhandle(FileHandle);
  if ( (*(_BYTE *)(dword_4DCF40[FileHandle >> 5] + v4 + 4) & 1) != 0 )
  {
    nolock = _read_nolock(FileHandle, (CHAR *)DstBuf, MaxCharCount);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    nolock = -1;
  }
  _unlock_fhandle(FileHandle);
  return nolock;
}
