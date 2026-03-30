int __cdecl _isatty(int FileHandle)
{
  if ( FileHandle == -2 )
  {
    *_errno() = 9;
    return 0;
  }
  if ( FileHandle < 0 || FileHandle >= uNumber )
  {
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return 0;
  }
  return *(_BYTE *)(dword_4DCF40[FileHandle >> 5] + ((FileHandle & 0x1F) << 6) + 4) & 0x40;
}
