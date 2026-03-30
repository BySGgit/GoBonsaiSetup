int sub_427F30()
{
  int *EngineInstance; // esi
  int v1; // esi
  _DWORD *v3; // edi
  int v4; // edi
  _BYTE v5[8]; // [esp+14h] [ebp-18h] BYREF
  int v6; // [esp+1Ch] [ebp-10h]

  sub_41F750();
  EngineInstance = (int *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = *EngineInstance;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v1 )
    return 0;
  v3 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = v3[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v4 )
    return 0;
  (*(void (__stdcall **)(int, _DWORD, _BYTE *))(*(_DWORD *)v1 + 32))(v1, *(_DWORD *)(v4 + 4), v5);
  return v6;
}
