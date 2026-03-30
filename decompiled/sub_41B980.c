char sub_41B980()
{
  _BYTE *EngineInstance; // esi
  char v1; // bl

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[782];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return v1;
}
