int __stdcall sub_44E030(int a1)
{
  _DWORD *EngineInstance; // esi
  int v2; // ebx
  _BYTE v4[68]; // [esp+10h] [ebp-48h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = EngineInstance[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  D3DXMatrixInverse(v4, 0, a1 + 104);
  qmemcpy((void *)(a1 + 224), v4, 0x40u);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v2 + 176))(v2, 2, a1 + 224);
  return (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v2 + 176))(v2, 3, a1 + 288);
}
