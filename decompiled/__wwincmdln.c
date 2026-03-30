unsigned __int16 *_wwincmdln()
{
  unsigned __int16 *result; // eax
  BOOL v1; // edx
  unsigned int v2; // ecx

  result = (unsigned __int16 *)dword_4DD058;
  v1 = 0;
  if ( !dword_4DD058 )
    result = word_4B765C;
  while ( 1 )
  {
    v2 = *result;
    if ( v2 <= 0x20 )
    {
      if ( !(_WORD)v2 )
        return result;
      if ( !v1 )
        break;
    }
    if ( v2 == 34 )
      v1 = !v1;
    ++result;
  }
  while ( *result && *result <= 0x20u )
    ++result;
  return result;
}
