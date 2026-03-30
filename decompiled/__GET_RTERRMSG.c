wchar_t *__cdecl _GET_RTERRMSG(int a1)
{
  int v1; // eax

  v1 = 0;
  while ( a1 != dword_474BF8[2 * v1] )
  {
    if ( (unsigned int)++v1 >= 0x16 )
      return 0;
  }
  return (&off_474BFC)[2 * v1];
}
