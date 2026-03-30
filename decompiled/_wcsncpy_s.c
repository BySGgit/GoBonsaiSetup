errno_t __cdecl wcsncpy_s(wchar_t *Destination, rsize_t SizeInWords, const wchar_t *Source, rsize_t MaxCount)
{
  rsize_t v4; // ebx
  rsize_t v6; // edi
  errno_t v7; // esi
  const wchar_t *v8; // ecx
  wchar_t *v9; // eax
  wchar_t v10; // ax
  wchar_t v11; // cx

  v4 = MaxCount;
  if ( MaxCount )
  {
    if ( !Destination )
    {
LABEL_7:
      v7 = 22;
      *_errno() = 22;
LABEL_8:
      _invalid_parameter_noinfo();
      return v7;
    }
  }
  else if ( !Destination )
  {
    if ( !SizeInWords )
      return 0;
    goto LABEL_7;
  }
  v6 = SizeInWords;
  if ( !SizeInWords )
    goto LABEL_7;
  if ( !MaxCount )
  {
    *Destination = 0;
    return 0;
  }
  v8 = Source;
  if ( !Source )
  {
    *Destination = 0;
    goto LABEL_7;
  }
  v9 = Destination;
  if ( MaxCount == -1 )
  {
    do
    {
      v10 = *v8;
      *(const wchar_t *)((char *)v8 + (char *)Destination - (char *)Source) = *v8;
      ++v8;
      if ( !v10 )
        break;
      --v6;
    }
    while ( v6 );
  }
  else
  {
    do
    {
      v11 = *(wchar_t *)((char *)v9 + (char *)Source - (char *)Destination);
      *v9++ = v11;
      if ( !v11 )
        break;
      if ( !--v6 )
        break;
      --v4;
    }
    while ( v4 );
    if ( !v4 )
      *v9 = 0;
  }
  if ( v6 )
    return 0;
  if ( v4 != -1 )
  {
    *Destination = 0;
    *_errno() = 34;
    v7 = 34;
    goto LABEL_8;
  }
  Destination[SizeInWords - 1] = 0;
  return 80;
}
