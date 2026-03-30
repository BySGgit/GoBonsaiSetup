errno_t __cdecl strcpy_s(char *Destination, rsize_t SizeInBytes, const char *Source)
{
  rsize_t v3; // edi
  errno_t v4; // esi
  const char *v6; // eax
  char v7; // cl

  if ( !Destination )
    goto LABEL_3;
  v3 = SizeInBytes;
  if ( !SizeInBytes )
    goto LABEL_3;
  v6 = Source;
  if ( !Source )
  {
    *Destination = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter_noinfo();
    return v4;
  }
  do
  {
    v7 = *v6;
    v6[Destination - Source] = *v6;
    ++v6;
    if ( !v7 )
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
