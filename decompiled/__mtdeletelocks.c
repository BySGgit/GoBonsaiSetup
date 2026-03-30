void _mtdeletelocks()
{
  LPCRITICAL_SECTION *v0; // esi
  LPCRITICAL_SECTION v1; // edi
  LPCRITICAL_SECTION *v2; // esi

  v0 = &lpCriticalSection;
  do
  {
    v1 = *v0;
    if ( *v0 && v0[1] != (LPCRITICAL_SECTION)1 )
    {
      DeleteCriticalSection(*v0);
      free(v1);
      *v0 = 0;
    }
    v0 += 2;
  }
  while ( (int)v0 < (int)off_4C9ED0 );
  v2 = &lpCriticalSection;
  do
  {
    if ( *v2 )
    {
      if ( v2[1] == (LPCRITICAL_SECTION)1 )
        DeleteCriticalSection(*v2);
    }
    v2 += 2;
  }
  while ( (int)v2 < (int)off_4C9ED0 );
}
