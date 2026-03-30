errno_t __cdecl wcscat_s(wchar_t *Destination, rsize_t SizeInWords, const wchar_t *Source)
{
  rsize_t v3; // edi
  errno_t v4; // esi
  errno_t result; // eax
  const wchar_t *v6; // ecx
  wchar_t *v7; // edx
  int v8; // edx
  wchar_t v9; // ax

  if ( !Destination )
    goto LABEL_3;
  v3 = SizeInWords;
  if ( !SizeInWords )
    goto LABEL_3;
  v6 = Source;
  if ( !Source )
    goto LABEL_7;
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
LABEL_7:
    *Destination = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter_noinfo();
    return v4;
  }
  v8 = (char *)v7 - (char *)Source;
  do
  {
    v9 = *v6;
    *(const wchar_t *)((char *)v6 + v8) = *v6;
    ++v6;
    if ( !v9 )
      break;
    --v3;
  }
  while ( v3 );
  result = 0;
  if ( !v3 )
  {
    *Destination = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return result;
}
