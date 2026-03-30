int _mtinitlocks()
{
  int v0; // esi
  struct _RTL_CRITICAL_SECTION *v1; // edi

  v0 = 0;
  v1 = (struct _RTL_CRITICAL_SECTION *)&unk_4D7B20;
  while ( 1 )
  {
    if ( dword_4C9DB4[2 * v0] == 1 )
    {
      *(&lpCriticalSection + 2 * v0) = v1++;
      if ( !InitializeCriticalSectionAndSpinCount(*(&lpCriticalSection + 2 * v0), 0xFA0u) )
        break;
    }
    if ( ++v0 >= 36 )
      return 1;
  }
  *(&lpCriticalSection + 2 * v0) = 0;
  return 0;
}
