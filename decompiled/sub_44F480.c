char __usercall sub_44F480@<al>(int a1@<eax>, unsigned __int16 a2, wchar_t *Source)
{
  int v3; // esi
  _DWORD *EngineInstance; // edi
  int v5; // edi
  __int16 *v7; // esi
  int v8; // [esp+10h] [ebp-4h] BYREF

  v3 = 34 * a1;
  if ( !dword_4D8040[17 * a1] )
  {
    EngineInstance = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v5 = EngineInstance[1];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( D3DXCreateTextureFromResourceW(v5, 0, a2, &v8) < 0 )
      return 0;
    v7 = &word_4D8000[v3];
    wcsncpy_s((wchar_t *)v7, 0x20u, Source, 0x20u);
    *((_DWORD *)v7 + 16) = v8;
  }
  return 1;
}
