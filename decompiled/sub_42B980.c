int __thiscall sub_42B980(char *this, int a2)
{
  char *v2; // esi
  _BYTE *EngineInstance; // edi
  char v4; // bl
  DWORD *v5; // ebx
  int v6; // edi
  int v7; // eax
  int v8; // ebp
  DWORD dmPelsHeight; // ecx
  _DWORD *v10; // ebp
  int v12; // [esp+3Ch] [ebp-10Ch]
  unsigned int v13; // [esp+40h] [ebp-108h] BYREF
  int v14; // [esp+44h] [ebp-104h]
  int v15; // [esp+48h] [ebp-100h]
  DWORD *v16; // [esp+4Ch] [ebp-FCh]
  unsigned int v17; // [esp+50h] [ebp-F8h]
  char *v18; // [esp+54h] [ebp-F4h]
  DEVMODEW DevMode; // [esp+58h] [ebp-F0h] BYREF
  int v20; // [esp+134h] [ebp-14h]
  int v21; // [esp+138h] [ebp-10h]
  int v22; // [esp+13Ch] [ebp-Ch]
  int v23; // [esp+140h] [ebp-8h]

  v2 = this;
  v18 = this;
  v20 = 29;
  v21 = 28;
  v22 = 10;
  v23 = 24;
  v15 = 4;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = EngineInstance[863];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v4 )
  {
    v20 = 28;
    v21 = 29;
  }
  if ( !*(_BYTE *)(a2 + 52) )
    v15 = 1;
  v14 = 0;
  while ( 1 )
  {
    v13 = 512;
    v5 = (DWORD *)operator new[](0x3800u);
    if ( !v5 )
      return -2147024882;
    v6 = *(&v20 + v14);
    v7 = (*(int (__stdcall **)(_DWORD, int, int, unsigned int *, DWORD *))(**((_DWORD **)v2 + 2) + 32))(
           *((_DWORD *)v2 + 2),
           v6,
           2,
           &v13,
           v5);
    v8 = v7;
    v12 = v7;
    if ( v7 == -2005270526 )
      break;
    if ( v7 == -2005270494 )
    {
      if ( v6 != 28 )
        goto LABEL_22;
      if ( !GetSystemMetrics(4096) )
        goto LABEL_22;
      DevMode.dmSize = 220;
      if ( !EnumDisplaySettingsW(0, 0xFFFFFFFF, &DevMode) )
        goto LABEL_22;
      dmPelsHeight = DevMode.dmPelsHeight;
      v13 = 1;
      *v5 = DevMode.dmPelsWidth;
      v5[1] = dmPelsHeight;
      v5[4] = 28;
      v5[2] = 60;
      v5[3] = 1;
      v5[5] = 1;
      v5[6] = 1;
      v12 = 0;
      goto LABEL_21;
    }
    if ( v7 != -2005270525 )
      goto LABEL_22;
    operator delete[](v5);
    v12 = (*(int (__stdcall **)(_DWORD, int, int, unsigned int *, _DWORD))(**((_DWORD **)v2 + 2) + 32))(
            *((_DWORD *)v2 + 2),
            v6,
            2,
            &v13,
            0);
    if ( v12 < 0 )
      return v12;
    v5 = (DWORD *)operator new[](28 * v13);
    if ( !v5 )
      return -2147024882;
    v12 = (*(int (__stdcall **)(_DWORD, int, int, unsigned int *, DWORD *))(**((_DWORD **)v2 + 2) + 32))(
            *((_DWORD *)v2 + 2),
            v6,
            2,
            &v13,
            v5);
    if ( v12 < 0 )
      break;
LABEL_21:
    v8 = v12;
LABEL_22:
    if ( v13 || v14 )
    {
      if ( v8 >= 0 )
      {
        v17 = 0;
        if ( v13 )
        {
          v10 = v2 + 104;
          v16 = v5;
          do
          {
            if ( sub_42DC80(v10[1] + 1, (int)v10) >= 0 )
            {
              qmemcpy((void *)(*v10 + 28 * v10[1]++), v16, 0x1Cu);
              v2 = v18;
            }
            v16 += 7;
            ++v17;
          }
          while ( v17 < v13 );
        }
      }
    }
    else
    {
      v15 = 4;
    }
    operator delete[](v5);
    if ( ++v14 >= v15 )
      return v12;
  }
  operator delete[](v5);
  return v12;
}
