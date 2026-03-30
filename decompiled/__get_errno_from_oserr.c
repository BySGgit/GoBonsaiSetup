int __cdecl _get_errno_from_oserr(int a1)
{
  unsigned int i; // ecx

  for ( i = 0; i < 0x2D; ++i )
  {
    if ( a1 == dword_4C9268[2 * i] )
      return dword_4C926C[2 * i];
  }
  if ( (unsigned int)(a1 - 19) > 0x11 )
    return (unsigned int)(a1 - 188) > 0xE ? 22 : 8;
  else
    return 13;
}
