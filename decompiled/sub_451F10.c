char __stdcall sub_451F10(int *a1, int a2)
{
  int *EngineInstance; // edi
  int v3; // edi
  bool v4; // zf
  int v5; // eax
  char v7[28]; // [esp+8h] [ebp-138h] BYREF
  int v8; // [esp+24h] [ebp-11Ch]
  unsigned int v9; // [esp+CCh] [ebp-74h]

  if ( !*a1 )
  {
    sub_41F750();
    EngineInstance = (int *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v3 = *EngineInstance;
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    (*(void (__stdcall **)(int, int, int, char *))(*(_DWORD *)v3 + 56))(v3, a1[1], a1[2], v7);
    v4 = (v8 & 0x10000) == 0;
    a1[18] = 0;
    if ( v4 || v9 < 0xFFFE0101 )
      a1[4] = 32;
  }
  if ( byte_4D6C9F )
  {
    if ( (v5 = *a1, byte_4D6C9F = 0, !v5) && a1[2] == 2 || v5 == 1 && a1[2] == 1 )
      sub_43EF30(v5);
  }
  return 1;
}
