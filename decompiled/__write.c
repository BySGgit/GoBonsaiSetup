int __cdecl _write(int FileHandle, const void *Buf, unsigned int MaxCharCount)
{
  int v4; // esi
  int v5; // [esp+14h] [ebp-1Ch]

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
    v5 = _write_nolock(FileHandle, Buf, MaxCharCount);
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
