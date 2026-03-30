char __usercall sub_44F3F0@<al>(int a1@<eax>, wchar_t *Source)
{
  int v2; // esi
  _DWORD *EngineInstance; // edi
  int v4; // edi
  __int16 *v6; // esi
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v2 = 34 * a1;
  if ( !dword_4D8040[17 * a1] )
  {
    EngineInstance = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = EngineInstance[1];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( D3DXCreateTextureFromFileW(v4, Source, &v7) < 0 )
      return 0;
    v6 = &word_4D8000[v2];
    wcsncpy_s((wchar_t *)v6, 0x20u, Source, 0x20u);
    *((_DWORD *)v6 + 16) = v7;
  }
  return 1;
}
