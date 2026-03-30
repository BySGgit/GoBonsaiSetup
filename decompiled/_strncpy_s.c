errno_t __cdecl strncpy_s(char *Destination, rsize_t SizeInBytes, const char *Source, rsize_t MaxCount)
{
  rsize_t v5; // edi
  errno_t v6; // esi
  const char *v7; // edx
  char *v8; // ecx
  char v9; // cl
  char v10; // dl

  if ( MaxCount )
  {
    if ( !Destination )
    {
LABEL_7:
      v6 = 22;
      *_errno() = 22;
LABEL_8:
      _invalid_parameter_noinfo();
      return v6;
    }
  }
  else if ( !Destination )
  {
    if ( !SizeInBytes )
      return 0;
    goto LABEL_7;
  }
  v5 = SizeInBytes;
  if ( !SizeInBytes )
    goto LABEL_7;
  if ( !MaxCount )
  {
    *Destination = 0;
    return 0;
  }
  v7 = Source;
  if ( !Source )
  {
    *Destination = 0;
    goto LABEL_7;
  }
  v8 = Destination;
  if ( MaxCount == -1 )
  {
    do
    {
      v9 = *v7;
      v7[Destination - Source] = *v7;
      ++v7;
      if ( !v9 )
        break;
      --v5;
    }
    while ( v5 );
  }
  else
  {
    do
    {
      v10 = v8[Source - Destination];
      *v8++ = v10;
      if ( !v10 )
        break;
      if ( !--v5 )
        break;
      --MaxCount;
    }
    while ( MaxCount );
    if ( !MaxCount )
      *v8 = 0;
  }
  if ( v5 )
    return 0;
  if ( MaxCount != -1 )
  {
    *Destination = 0;
    *_errno() = 34;
    v6 = 34;
    goto LABEL_8;
  }
  Destination[SizeInBytes - 1] = 0;
  return 80;
}
