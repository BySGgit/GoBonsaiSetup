char __stdcall sub_42C1D0(int a1, int a2)
{
  int v2; // ebx
  _DWORD *EngineInstance; // esi
  int v4; // esi
  D3D10_DRIVER_TYPE v5; // esi
  IDXGIAdapter *v6; // edi
  HRESULT Device; // eax
  int i; // esi
  IDXGIAdapter *v10; // [esp+30h] [ebp-8h] BYREF
  int v11; // [esp+34h] [ebp-4h] BYREF

  v2 = a2;
  a2 = 0;
  v10 = 0;
  if ( !*(_DWORD *)(v2 + 4) )
  {
    sub_41F640();
    EngineInstance = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = EngineInstance[88];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    (*(void (__stdcall **)(int, _DWORD, IDXGIAdapter **))(*(_DWORD *)v4 + 28))(v4, **(_DWORD **)(v2 + 44), &v10);
  }
  v5 = *(_DWORD *)(v2 + 4);
  v6 = v10;
  LOBYTE(Device) = sub_4380B0();
  if ( (_BYTE)Device )
  {
    LOBYTE(Device) = (_BYTE)D3D10CreateDevice;
    if ( D3D10CreateDevice )
    {
      Device = D3D10CreateDevice(v6, v5, 0, 0, 0x1Du, (ID3D10Device **)&a2);
      if ( Device >= 0 )
      {
        for ( i = 1; i <= 32; ++i )
        {
          if ( (*(int (__stdcall **)(int, int, int, int *))(*(_DWORD *)a2 + 364))(a2, a1, i, &v11) >= 0 && v11 )
          {
            if ( sub_42DBC0(*(_DWORD *)(v2 + 24) + 1, v2 + 20) >= 0 )
              *(_DWORD *)(*(_DWORD *)(v2 + 20) + 4 * (*(_DWORD *)(v2 + 24))++) = i;
            if ( sub_42DBC0(*(_DWORD *)(v2 + 36) + 1, v2 + 32) >= 0 )
              *(_DWORD *)(*(_DWORD *)(v2 + 32) + 4 * (*(_DWORD *)(v2 + 36))++) = v11;
          }
        }
        LOBYTE(Device) = a2;
        if ( a2 )
          LOBYTE(Device) = (*(int (__stdcall **)(int))(*(_DWORD *)a2 + 8))(a2);
      }
    }
  }
  return Device;
}
