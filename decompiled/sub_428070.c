void __stdcall sub_428070(float a1)
{
  _BYTE *EngineInstance; // esi
  char v2; // bl
  _BYTE *v3; // esi
  char v4; // bl
  float *v5; // esi
  _BYTE *v6; // esi
  bool v7; // zf
  float *v8; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = EngineInstance[845];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v2 )
  {
    v3 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = v3[845];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v5 = (float *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    a1 = v5[212];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
  }
  else
  {
    v4 = 1;
  }
  v6 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v7 = byte_4CA649 == 0;
  v6[758] = v4;
  if ( !v7 )
    LeaveCriticalSection(&CriticalSection);
  v8 = (float *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v7 = byte_4CA649 == 0;
  v8[190] = a1;
  if ( !v7 )
    LeaveCriticalSection(&CriticalSection);
}
