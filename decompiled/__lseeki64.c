__int64 __cdecl _lseeki64(int FileHandle, __int64 Offset, int Origin)
{
  int v4; // esi
  __int64 v5; // [esp+10h] [ebp-24h]

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
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(FileHandle);
  if ( (*(_BYTE *)(dword_4DCF40[FileHandle >> 5] + v4 + 4) & 1) != 0 )
  {
    v5 = _lseeki64_nolock(FileHandle, Offset, SHIDWORD(Offset), Origin);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    v5 = -1;
  }
  _unlock_fhandle(FileHandle);
  return v5;
}
