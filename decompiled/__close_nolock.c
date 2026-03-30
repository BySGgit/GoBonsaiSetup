int __cdecl _close_nolock(int FileHandle)
{
  intptr_t osfhandle; // edi
  void *v2; // eax
  DWORD LastError; // edi

  if ( _get_osfhandle(FileHandle) == -1
    || (FileHandle == 1 && (*(_BYTE *)(dword_4DCF40[0] + 132) & 1) != 0
     || FileHandle == 2 && (*(_BYTE *)(dword_4DCF40[0] + 68) & 1) != 0)
    && (osfhandle = _get_osfhandle(2), _get_osfhandle(1) == osfhandle)
    || (v2 = (void *)_get_osfhandle(FileHandle), CloseHandle(v2)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  _free_osfhnd(FileHandle);
  *(_BYTE *)(dword_4DCF40[FileHandle >> 5] + ((FileHandle & 0x1F) << 6) + 4) = 0;
  if ( !LastError )
    return 0;
  _dosmaperr(LastError);
  return -1;
}
