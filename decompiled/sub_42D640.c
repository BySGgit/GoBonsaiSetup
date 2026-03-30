int __usercall sub_42D640@<eax>(int a1@<edx>, int a2, int a3, int a4, int a5, int a6, int a7, int a8, unsigned int *a9)
{
  unsigned int *v9; // ebx
  int v10; // ecx
  int v11; // esi
  int v12; // edi
  void *EngineInstance; // ebp
  HWND v14; // ebp
  LONG WindowLongW; // eax
  unsigned int v16; // eax
  unsigned int v17; // ecx
  int v19; // edx
  char *v20; // ebp
  signed int v21; // ebx
  int v22; // [esp+10h] [ebp-5Ch]
  int v23; // [esp+14h] [ebp-58h]
  int v24; // [esp+18h] [ebp-54h]
  _BYTE Rect[28]; // [esp+20h] [ebp-4Ch] BYREF
  struct tagMONITORINFO mi; // [esp+3Ch] [ebp-30h] BYREF

  v9 = a9;
  memset(Rect, 0, sizeof(Rect));
  if ( *(_DWORD *)(a1 + 12) )
  {
    qmemcpy(a9, &a2, 0x1Cu);
    v10 = *(_DWORD *)(a1 + 52);
    mi.cbSize = 40;
    GetMonitorInfoW(*(HMONITOR *)(v10 + 100), &mi);
    v11 = mi.rcWork.right - mi.rcWork.left;
    v12 = mi.rcWork.bottom - mi.rcWork.top;
    *(RECT *)Rect = mi.rcWork;
    EngineInstance = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v14 = (HWND)*((_DWORD *)EngineInstance + 142);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    WindowLongW = GetWindowLongW(v14, -16);
    AdjustWindowRect((LPRECT)Rect, WindowLongW, 0);
    v16 = *(_DWORD *)Rect + 2 * v11 - *(_DWORD *)&Rect[8];
    v17 = *(_DWORD *)&Rect[4] + 2 * v12 - *(_DWORD *)&Rect[12];
    if ( *v9 < v16 )
      v16 = *v9;
    *v9 = v16;
    if ( v9[1] < v17 )
      v17 = v9[1];
    v9[1] = v17;
    return 0;
  }
  else
  {
    v19 = *(_DWORD *)(a1 + 52);
    v23 = 0;
    v22 = 100000;
    v24 = *(_DWORD *)(v19 + 108);
    if ( v24 > 0 )
    {
      v20 = *(char **)(v19 + 104);
      do
      {
        qmemcpy(&mi, v20, 0x1Cu);
        v21 = abs32(mi.cbSize - a2) + abs32(mi.rcMonitor.left - a3);
        if ( v21 < v22 )
        {
          qmemcpy(Rect, v20, sizeof(Rect));
          v22 = v21;
          if ( !v21 )
            break;
        }
        v20 += 28;
        ++v23;
      }
      while ( v23 < v24 );
      v9 = a9;
    }
    if ( *(_DWORD *)Rect )
    {
      qmemcpy(v9, Rect, 0x1Cu);
      return 0;
    }
    else
    {
      qmemcpy(v9, &a2, 0x1Cu);
      return -2147467259;
    }
  }
}
