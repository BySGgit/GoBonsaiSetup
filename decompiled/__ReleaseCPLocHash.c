void __cdecl _ReleaseCPLocHash()
{
  volatile LONG *v0; // ebx
  _locale_t *v1; // esi
  _locale_t v2; // edi

  v0 = Target;
  do
  {
    v1 = (_locale_t *)InterlockedExchange(v0, 0);
    if ( v1 )
    {
      do
      {
        v2 = *v1;
        _free_locale(v1[2]);
        free(v1);
        v1 = (_locale_t *)v2;
      }
      while ( v2 );
    }
    ++v0;
  }
  while ( (int)v0 < (int)dword_4D6EC0 );
}
