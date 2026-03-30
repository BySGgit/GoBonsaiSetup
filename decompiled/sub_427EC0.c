void *__stdcall sub_427EC0(void *a1)
{
  _DWORD *EngineInstance; // esi
  _BYTE *v2; // esi
  _BYTE v4[96]; // [esp+10h] [ebp-60h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = (_BYTE *)EngineInstance[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v2 )
  {
    memset(v4, 0, sizeof(v4));
    v2 = v4;
  }
  qmemcpy(a1, v2, 0x60u);
  return a1;
}
