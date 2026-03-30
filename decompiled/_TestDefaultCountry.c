int __cdecl TestDefaultCountry(__int16 a1)
{
  int v1; // eax

  v1 = 0;
  while ( a1 != word_475A48[v1] )
  {
    if ( (unsigned int)++v1 >= 10 )
      return 1;
  }
  return 0;
}
