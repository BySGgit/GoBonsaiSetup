int __cdecl _commit(int FileHandle)
{
  int v2; // esi
  void *osfhandle; // eax
  DWORD LastError; // [esp+14h] [ebp-1Ch]

  if ( FileHandle == -2 )
  {
    *_errno() = 9;
    return -1;
  }
  if ( FileHandle < 0
    || FileHandle >= uNumber
    || (v2 = (FileHandle & 0x1F) << 6, (*(_BYTE *)(v2 + dword_4DCF40[FileHandle >> 5] + 4) & 1) == 0) )
  {
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(FileHandle);
  if ( (*(_BYTE *)(v2 + dword_4DCF40[FileHandle >> 5] + 4) & 1) != 0 )
  {
    osfhandle = (void *)_get_osfhandle(FileHandle);
    if ( FlushFileBuffers(osfhandle) )
      LastError = 0;
    else
      LastError = GetLastError();
    if ( !LastError )
      goto $good$28895;
    *__doserrno() = LastError;
  }
  *_errno() = 9;
  LastError = -1;
$good$28895:
  _unlock_fhandle(FileHandle);
  return LastError;
}
