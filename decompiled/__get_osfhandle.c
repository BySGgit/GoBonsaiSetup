intptr_t __cdecl _get_osfhandle(int FileHandle)
{
  int v2; // ecx
  int v3; // eax

  if ( FileHandle == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( FileHandle < 0
    || FileHandle >= uNumber
    || (v2 = dword_4DCF40[FileHandle >> 5], v3 = (FileHandle & 0x1F) << 6, (*(_BYTE *)(v3 + v2 + 4) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  return *(_DWORD *)(v3 + v2);
}
