char sub_41BA60()
{
  _BYTE *EngineInstance; // esi
  char v1; // bl

  sub_41F640();
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[348];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return v1;
}
