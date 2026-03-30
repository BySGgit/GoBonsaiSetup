char *__cdecl strerror(int ErrorMessage)
{
  int v1; // eax
  int v2; // esi
  int v4; // eax
  char *v5; // esi
  char *sys_err_msg; // eax

  v1 = _getptd_noexit();
  v2 = v1;
  if ( !v1 )
    return "Visual C++ CRT: Not enough memory to complete call to strerror.";
  if ( !*(_DWORD *)(v1 + 36) )
  {
    v4 = _calloc_crt(134, 1);
    *(_DWORD *)(v2 + 36) = v4;
    if ( !v4 )
      return "Visual C++ CRT: Not enough memory to complete call to strerror.";
  }
  v5 = *(char **)(v2 + 36);
  sys_err_msg = _get_sys_err_msg(ErrorMessage);
  if ( strcpy_s(v5, 0x86u, sys_err_msg) )
    _invoke_watson(0, 0, 0, 0, 0);
  return v5;
}
