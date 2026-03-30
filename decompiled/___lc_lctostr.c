void __cdecl __lc_lctostr(char *Destination, rsize_t SizeInBytes, char *Source)
{
  if ( strcpy_s(Destination, SizeInBytes, Source) )
    _invoke_watson(0, 0, 0, 0, 0);
  if ( Source[64] )
    _strcats(Destination, SizeInBytes, 2);
  if ( Source[128] )
    _strcats(Destination, SizeInBytes, 2);
}
