int __cdecl __ascii_stricmp(unsigned __int8 *a1, unsigned __int8 *a2)
{
  int v4; // eax
  int v5; // ecx

  do
  {
    v4 = *a1++;
    if ( (unsigned int)(v4 - 65) <= 0x19 )
      v4 += 32;
    v5 = *a2++;
    if ( (unsigned int)(v5 - 65) <= 0x19 )
      v5 += 32;
  }
  while ( v4 && v4 == v5 );
  return v4 - v5;
}
