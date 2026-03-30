double sub_41B870()
{
  float *EngineInstance; // esi
  float v2; // [esp+0h] [ebp-4h]

  EngineInstance = (float *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = EngineInstance[168];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return v2;
}
