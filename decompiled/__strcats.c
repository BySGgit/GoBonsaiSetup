void __cdecl _strcats(char *Destination, rsize_t SizeInBytes, int a3)
{
  int v3; // edi
  const char **v4; // esi

  v3 = 0;
  if ( a3 > 0 )
  {
    v4 = (const char **)&a3;
    do
    {
      if ( strcat_s(Destination, SizeInBytes, *++v4) )
        _invoke_watson(0, 0, 0, 0, 0);
      ++v3;
    }
    while ( v3 < a3 );
  }
}
