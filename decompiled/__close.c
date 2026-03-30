int __cdecl _close(int FileHandle)
{
  int v2; // esi
  int v3; // [esp+14h] [ebp-1Ch]

  if ( FileHandle == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( FileHandle < 0
    || FileHandle >= uNumber
    || (v2 = (FileHandle & 0x1F) << 6, (*(_BYTE *)(dword_4DCF40[FileHandle >> 5] + v2 + 4) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(FileHandle);
  if ( (*(_BYTE *)(dword_4DCF40[FileHandle >> 5] + v2 + 4) & 1) != 0 )
  {
    v3 = _close_nolock(FileHandle);
  }
  else
  {
    *_errno() = 9;
    v3 = -1;
  }
  _unlock_fhandle(FileHandle);
  return v3;
}
