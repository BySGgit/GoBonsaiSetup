double sub_41B820()
{
  double *EngineInstance; // esi
  double result; // st7

  EngineInstance = (double *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  result = EngineInstance[82];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return result;
}
