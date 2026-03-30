void sub_412480()
{
  _DWORD *v0; // edi
  _DWORD *EngineInstance; // esi
  int v2; // esi

  v0 = dword_4D82D0;
  sub_44F150();
  sub_40A440();
  sub_411B60();
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = EngineInstance[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  D3DXCreateSphere(v2, 1.0, 32, 32, &dword_4D7EC8, 0);
  sub_409910();
  sub_412510();
  if ( byte_4D6328 )
  {
    sub_412120(v0);
    byte_4D6328 = 0;
  }
}
