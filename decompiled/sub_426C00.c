HMONITOR __usercall sub_426C00@<eax>(_DWORD *a1@<eax>)
{
  int *EngineInstance; // esi
  int v3; // esi
  _DWORD *v5; // eax
  int v6; // esi
  int v7; // ebx
  int v8; // ecx
  int v9; // edi
  _DWORD *i; // eax
  _DWORD *v11; // edx
  int v12; // eax

  if ( *a1 )
  {
    v5 = sub_42B3D0();
    v6 = v5[15];
    v7 = a1[3];
    v8 = 0;
    if ( v6 <= 0 )
      return 0;
    v9 = a1[1];
    for ( i = (_DWORD *)v5[14]; ; ++i )
    {
      v11 = (_DWORD *)*i;
      if ( *(_DWORD *)*i == v9 )
        break;
      if ( ++v8 >= v6 )
        return 0;
    }
    if ( v11[140] > v7 && (v12 = *(_DWORD *)(v11[139] + 4 * v7)) != 0 )
      return sub_438390((const RECT *)(v12 + 76));
    else
      return 0;
  }
  else
  {
    sub_41F750();
    EngineInstance = (int *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v3 = *EngineInstance;
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    return (HMONITOR)(*(int (__stdcall **)(int, _DWORD))(*(_DWORD *)v3 + 60))(v3, a1[1]);
  }
}
