BOOL __cdecl TranslateName(int a1, int a2, const char **a3)
{
  int v3; // ebx
  int v4; // eax
  int v5; // esi
  const char **v6; // edi

  v3 = 0;
  v4 = 1;
  while ( v3 <= a2 )
  {
    if ( !v4 )
      break;
    v5 = (v3 + a2) / 2;
    v6 = (const char **)(a1 + 8 * v5);
    v4 = _stricmp(*a3, *v6);
    if ( v4 )
    {
      if ( v4 >= 0 )
        v3 = v5 + 1;
      else
        a2 = v5 - 1;
    }
    else
    {
      *a3 = (const char *)(v6 + 1);
    }
  }
  return v4 == 0;
}
