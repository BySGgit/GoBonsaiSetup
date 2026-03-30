int __cdecl _initterm_e(_PIFV *First, _PIFV *Last)
{
  int result; // eax

  result = 0;
  while ( First < Last && !result )
  {
    if ( *First )
      result = (*First)();
    ++First;
  }
  return result;
}
