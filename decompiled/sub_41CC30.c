signed int __stdcall sub_41CC30(const WCHAR *a1)
{
  int EngineInstance; // esi
  char v2; // bl
  signed int result; // eax
  int v4; // esi
  bool v5; // zf
  int v6; // esi
  char v7; // bl
  int v8; // esi
  char v9; // bl
  int v10; // esi
  int v11; // esi
  HINSTANCE ModuleHandleW; // ebp
  int v13; // eax
  HICON IconW; // edi
  HICON v15; // esi
  bool v16; // cc
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // ebx
  int v22; // eax
  int v23; // eax
  int v24; // edi
  int v25; // esi
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char *v31; // eax
  int v32; // esi
  int v33; // edx
  __int16 v34; // cx
  HWND Window; // esi
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  unsigned int X; // [esp+14h] [ebp-25Ch]
  WNDCLASSEXW v41; // [esp+20h] [ebp-250h] BYREF
  struct tagRECT rc; // [esp+50h] [ebp-220h] BYREF
  WCHAR Filename[262]; // [esp+60h] [ebp-210h] BYREF

  X = 0x80000000;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = *(_BYTE *)(EngineInstance + 780);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v2 )
    return -2147467259;
  v4 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v5 = byte_4CA649 == 0;
  *(_BYTE *)(v4 + 776) = 1;
  if ( !v5 )
    LeaveCriticalSection(&CriticalSection);
  v6 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v7 = *(_BYTE *)(v6 + 772);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v7 )
    goto LABEL_22;
  v8 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v9 = *(_BYTE *)(v8 + 775);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v9 )
    return -2147467259;
  result = sub_41C130();
  if ( result >= 0 )
  {
LABEL_22:
    v10 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v11 = *(_DWORD *)(v10 + 560);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( !v11 )
    {
      ModuleHandleW = GetModuleHandleW(0);
      v13 = GetEngineInstance();
      sub_419E10(v13, ModuleHandleW);
      GetModuleFileNameW(0, Filename, 0x104u);
      IconW = ExtractIconW(ModuleHandleW, Filename, 0);
      v15 = ExtractIconW(ModuleHandleW, Filename, 1u);
      if ( !v15 )
        v15 = IconW;
      v41.cbSize = 48;
      v41.style = 8;
      v41.lpfnWndProc = (WNDPROC)sub_41D000;
      v41.cbClsExtra = 0;
      v41.cbWndExtra = 0;
      v41.hInstance = ModuleHandleW;
      v41.hIcon = IconW;
      v41.hCursor = LoadCursorW(0, (LPCWSTR)0x7F00);
      v41.hbrBackground = (HBRUSH)GetStockObject(4);
      v41.lpszMenuName = 0;
      v41.lpszClassName = L"Direct3DWindowClass";
      v41.hIconSm = v15;
      if ( !RegisterClassExW(&v41) )
      {
        result = GetLastError();
        if ( result != 1410 )
        {
          v16 = result <= 0;
          goto LABEL_32;
        }
      }
      v17 = GetEngineInstance();
      if ( sub_41A8E0(v17) != -1 )
      {
        v18 = GetEngineInstance();
        X = sub_41A8E0(v18);
      }
      v19 = GetEngineInstance();
      if ( sub_41A960(v19) == -1 )
      {
        v21 = 0x80000000;
      }
      else
      {
        v20 = GetEngineInstance();
        v21 = sub_41A960(v20);
      }
      v22 = GetEngineInstance();
      sub_41A320(v22, 0);
      if ( X == 0x80000000 && v21 == 0x80000000 )
      {
        v23 = GetEngineInstance();
        sub_41A320(v23, 1);
      }
      v24 = 640;
      v25 = 480;
      v26 = GetEngineInstance();
      if ( sub_41A9E0(v26) )
      {
        v27 = GetEngineInstance();
        v24 = sub_41A9E0(v27);
      }
      v28 = GetEngineInstance();
      if ( sub_41AA60(v28) )
      {
        v29 = GetEngineInstance();
        v25 = sub_41AA60(v29);
      }
      SetRect(&rc, 0, 0, v24, v25);
      AdjustWindowRect(&rc, 0xCF0000u, 0);
      v30 = GetEngineInstance();
      v31 = (char *)sub_41B3A0(v30);
      v32 = 256;
      v33 = (char *)a1 - v31;
      while ( v32 != -2147483390 )
      {
        v34 = *(_WORD *)&v31[v33];
        if ( !v34 )
          break;
        *(_WORD *)v31 = v34;
        v31 += 2;
        if ( !--v32 )
        {
          v31 -= 2;
          break;
        }
      }
      *(_WORD *)v31 = 0;
      Window = CreateWindowExW(
                 0,
                 L"Direct3DWindowClass",
                 a1,
                 0xCF0000u,
                 X,
                 v21,
                 rc.right - rc.left,
                 rc.bottom - rc.top,
                 0,
                 0,
                 ModuleHandleW,
                 0);
      if ( !Window )
      {
        result = GetLastError();
        v16 = result <= 0;
LABEL_32:
        if ( !v16 )
          return (unsigned __int16)result | 0x80070000;
        return result;
      }
      v36 = GetEngineInstance();
      sub_41A420(v36);
      v37 = GetEngineInstance();
      sub_419850(v37, Window);
      v38 = GetEngineInstance();
      sub_419890(v38, Window);
      v39 = GetEngineInstance();
      sub_4198D0(v39, Window);
    }
    return 0;
  }
  return result;
}
