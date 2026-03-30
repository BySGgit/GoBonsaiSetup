DWORD *__cdecl _getptd()
{
  DWORD *result; // eax

  result = _getptd_noexit();
  if ( !result )
    _amsg_exit(16);
  return result;
}
