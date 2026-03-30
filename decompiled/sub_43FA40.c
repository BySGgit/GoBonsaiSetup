int __cdecl sub_43FA40(int a1)
{
  int v1; // ecx
  _DWORD *EngineInstance; // esi
  int v3; // esi
  int result; // eax
  int v5; // esi
  int v6; // [esp+28h] [ebp-4h] BYREF

  v6 = v1;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = EngineInstance[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v3 )
    return -2147467259;
  v6 = 0;
  result = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD, int *))(*(_DWORD *)v3 + 72))(v3, 0, 0, 0, &v6);
  if ( result >= 0 )
  {
    v5 = D3DXSaveSurfaceToFileW(a1, 1, v6, 0, 0);
    (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v6);
    return v5;
  }
  return result;
}
