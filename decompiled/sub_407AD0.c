char *sub_407AD0()
{
  char *result; // eax
  char *v1; // esi

  result = *(char **)dword_4D8E08;
  *(_DWORD *)dword_4D8E08 = dword_4D8E08;
  *((_DWORD *)dword_4D8E08 + 1) = dword_4D8E08;
  dword_4D8E0C = 0;
  if ( result != dword_4D8E08 )
  {
    do
    {
      v1 = *(char **)result;
      operator delete(result);
      result = v1;
    }
    while ( v1 != dword_4D8E08 );
  }
  return result;
}
