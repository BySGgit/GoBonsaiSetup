void __cdecl _freea(void *Memory)
{
  if ( Memory )
  {
    if ( *((_DWORD *)Memory - 2) == 56797 )
      free((char *)Memory - 8);
  }
}
