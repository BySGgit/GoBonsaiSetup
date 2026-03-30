void *__crtGetEnvironmentStringsW()
{
  LPWCH EnvironmentStringsW; // eax
  LPWCH v1; // esi
  size_t v3; // ebx
  void *v4; // eax
  void *v5; // edi

  EnvironmentStringsW = GetEnvironmentStringsW();
  v1 = EnvironmentStringsW;
  if ( !EnvironmentStringsW )
    return 0;
  for ( ; *EnvironmentStringsW; ++EnvironmentStringsW )
  {
    do
      ++EnvironmentStringsW;
    while ( *EnvironmentStringsW );
  }
  v3 = (char *)EnvironmentStringsW - (char *)v1 + 2;
  v4 = _malloc_crt(v3);
  v5 = v4;
  if ( v4 )
    memcpy_0(v4, v1, v3);
  FreeEnvironmentStringsW(v1);
  return v5;
}
