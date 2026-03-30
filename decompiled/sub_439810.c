int sub_439810()
{
  _DWORD *EngineInstance; // esi
  int v1; // eax
  int v2; // eax
  _DWORD *v3; // esi
  int v4; // esi

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
  {
    EnterCriticalSection(&CriticalSection);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
  }
  dword_4D55F0 = 0;
  dword_4D55F4 = 0;
  v1 = EngineInstance[10];
  dword_4D55F8 = EngineInstance[9];
  dword_4D55FC = v1;
  dword_4D5604 = -10319154;
  dword_4D5608 = -13211200;
  dword_4D560C = -13211200;
  dword_4D5610 = -16102989;
  dword_4D58E0 = 0;
  dword_4D58E4 = 0;
  v2 = EngineInstance[10];
  dword_4D58E8 = EngineInstance[9];
  dword_4D58EC = v2;
  dword_4D58F4 = -10319154;
  dword_4D58F8 = -13211200;
  dword_4D58FC = -13211200;
  dword_4D5900 = -16102989;
  v3 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = v3[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int))(*(_DWORD *)v4 + 240))(v4);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v4 + 228))(v4, 8, 3);
  (*(void (__stdcall **)(int, int *))(*(_DWORD *)v4 + 244))(v4, &dword_4D53C8);
  return 0;
}
