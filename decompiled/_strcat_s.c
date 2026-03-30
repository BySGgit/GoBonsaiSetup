errno_t __cdecl strcat_s(char *Destination, rsize_t SizeInBytes, const char *Source)
{
  rsize_t v3; // edi
  errno_t v4; // esi
  const char *v6; // edx
  char *v7; // esi
  int v8; // esi
  char v9; // al

  if ( !Destination )
    goto LABEL_3;
  v3 = SizeInBytes;
  if ( !SizeInBytes )
    goto LABEL_3;
  v6 = Source;
  if ( !Source )
    goto LABEL_6;
  v7 = Destination;
  do
  {
    if ( !*v7 )
      break;
    ++v7;
    --v3;
  }
  while ( v3 );
  if ( !v3 )
  {
LABEL_6:
    *Destination = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter_noinfo();
    return v4;
  }
  v8 = v7 - Source;
  do
  {
    v9 = *v6;
    v6[v8] = *v6;
    ++v6;
    if ( !v9 )
      break;
    --v3;
  }
  while ( v3 );
  if ( !v3 )
  {
    *Destination = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}
