errno_t __cdecl wcscpy_s(wchar_t *Destination, rsize_t SizeInWords, const wchar_t *Source)
{
  rsize_t v3; // edi
  errno_t v4; // esi
  errno_t result; // eax
  const wchar_t *v6; // eax
  wchar_t v7; // cx

  if ( !Destination )
    goto LABEL_3;
  v3 = SizeInWords;
  if ( !SizeInWords )
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
    *(const wchar_t *)((char *)v6 + (char *)Destination - (char *)Source) = *v6;
    ++v6;
    if ( !v7 )
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
