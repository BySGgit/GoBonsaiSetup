void __cdecl sub_4256B0(int a1)
{
  int v1; // ebx
  WCHAR *v2; // eax
  int v3; // edx
  WCHAR v4; // cx
  WCHAR *v5; // eax
  int v6; // edx
  WCHAR v7; // cx
  bool v8; // zf
  int v9; // edx
  WCHAR *v10; // eax
  WCHAR v11; // cx
  WCHAR v12; // cx
  WCHAR *v13; // eax
  int v14; // edx
  WCHAR v15; // cx
  WCHAR *v16; // eax
  int v17; // edx
  WCHAR v18; // cx
  WCHAR *v19; // eax
  int v20; // edx
  WCHAR v21; // cx
  WCHAR *v22; // eax
  int v23; // edx
  WCHAR v24; // cx
  WCHAR *v25; // eax
  int v26; // edx
  WCHAR v27; // cx
  WCHAR *v28; // eax
  int v29; // edx
  WCHAR v30; // cx
  WCHAR *v31; // eax
  int v32; // edx
  WCHAR v33; // cx
  int EngineInstance; // esi
  int v35; // esi
  char v36; // bl
  int v37; // esi
  HWND v38; // eax
  const WCHAR *v39; // [esp-8h] [ebp-420h]
  char v40; // [esp+13h] [ebp-405h]
  WCHAR Text[512]; // [esp+14h] [ebp-404h] BYREF

  v40 = 1;
  switch ( a1 )
  {
    case -2147219199:
      v1 = 2;
      if ( !sub_41FE70() || sub_41FD50() )
      {
        v5 = Text;
        v6 = 512;
        while ( v6 != -2147483134 )
        {
          v7 = *(WCHAR *)((char *)v5
                        + (char *)L"Could not initialize Direct3D 9. Check that the latest version of DirectX is correctly"
                                   " installed on your system.  Also make sure that this program was compiled with header"
                                   " files that match the installed DirectX DLLs."
                        - (char *)Text);
          if ( !v7 )
            break;
          *v5++ = v7;
          if ( !--v6 )
          {
            *(v5 - 1) = 0;
            goto LABEL_70;
          }
        }
        *v5 = 0;
      }
      else
      {
        v2 = Text;
        v3 = 512;
        while ( v3 != -2147483134 )
        {
          v4 = *(WCHAR *)((char *)v2
                        + (char *)L"Could not initialize Direct3D 10. This application requires a Direct3D 10 class\n"
                                   "device (hardware or reference rasterizer) running on Windows Vista (or later)."
                        - (char *)Text);
          if ( !v4 )
            break;
          *v2++ = v4;
          if ( !--v3 )
          {
            *(v2 - 1) = 0;
            goto LABEL_70;
          }
        }
        *v2 = 0;
      }
      break;
    case -2147219198:
      v1 = 3;
      v8 = GetSystemMetrics(4096) == 0;
      v9 = 512;
      v10 = Text;
      if ( v8 )
      {
        while ( v9 != -2147483134 )
        {
          v12 = *(WCHAR *)((char *)v10 + (char *)L"Could not find any compatible Direct3D devices." - (char *)Text);
          if ( !v12 )
            break;
          *v10++ = v12;
          if ( !--v9 )
          {
            *(v10 - 1) = 0;
            goto LABEL_70;
          }
        }
        *v10 = 0;
      }
      else
      {
        while ( v9 != -2147483134 )
        {
          v11 = *(WCHAR *)((char *)v10 + (char *)L"Direct3D does not work over a remote session." - (char *)Text);
          if ( !v11 )
            break;
          *v10++ = v11;
          if ( !--v9 )
          {
            *(v10 - 1) = 0;
            goto LABEL_70;
          }
        }
        *v10 = 0;
      }
      break;
    case -2147219197:
      v13 = Text;
      v1 = 4;
      v14 = 512;
      while ( v14 != -2147483134 )
      {
        v15 = *(WCHAR *)((char *)v13 + (char *)L"Could not find required media." - (char *)Text);
        if ( !v15 )
          break;
        *v13++ = v15;
        if ( !--v14 )
        {
          *(v13 - 1) = 0;
          goto LABEL_70;
        }
      }
      *v13 = 0;
      break;
    case -2147219196:
      v16 = Text;
      v1 = 5;
      v17 = 512;
      while ( v17 != -2147483134 )
      {
        v18 = *(WCHAR *)((char *)v16
                       + (char *)L"The Direct3D device has a non-zero reference count, meaning some objects were not released."
                       - (char *)Text);
        if ( !v18 )
          break;
        *v16++ = v18;
        if ( !--v17 )
        {
          *(v16 - 1) = 0;
          goto LABEL_70;
        }
      }
      *v16 = 0;
      break;
    case -2147219195:
      v19 = Text;
      v1 = 6;
      v20 = 512;
      while ( v20 != -2147483134 )
      {
        v21 = *(WCHAR *)((char *)v19 + (char *)L"Failed creating the Direct3D device." - (char *)Text);
        if ( !v21 )
          break;
        *v19++ = v21;
        if ( !--v20 )
        {
          *(v19 - 1) = 0;
          goto LABEL_70;
        }
      }
      *v19 = 0;
      break;
    case -2147219194:
      v22 = Text;
      v1 = 7;
      v23 = 512;
      while ( v23 != -2147483134 )
      {
        v24 = *(WCHAR *)((char *)v22 + (char *)L"Failed resetting the Direct3D device." - (char *)Text);
        if ( !v24 )
          break;
        *v22++ = v24;
        if ( !--v23 )
        {
          *(v22 - 1) = 0;
          goto LABEL_70;
        }
      }
      *v22 = 0;
      break;
    case -2147219193:
      v25 = Text;
      v1 = 8;
      v26 = 512;
      while ( v26 != -2147483134 )
      {
        v27 = *(WCHAR *)((char *)v25
                       + (char *)L"An error occurred in the device create callback function."
                       - (char *)Text);
        if ( !v27 )
          break;
        *v25++ = v27;
        if ( !--v26 )
        {
          *(v25 - 1) = 0;
          goto LABEL_70;
        }
      }
      *v25 = 0;
      break;
    case -2147219192:
      v28 = Text;
      v1 = 9;
      v29 = 512;
      while ( v29 != -2147483134 )
      {
        v30 = *(WCHAR *)((char *)v28 + (char *)L"An error occurred in the device reset callback function."
                                     - (char *)Text);
        if ( !v30 )
          break;
        *v28++ = v30;
        if ( !--v29 )
        {
          *(v28 - 1) = 0;
          goto LABEL_70;
        }
      }
      *v28 = 0;
      break;
    case -2147219190:
      v31 = Text;
      v1 = 11;
      v32 = 512;
      while ( v32 != -2147483134 )
      {
        v33 = *(WCHAR *)((char *)v31 + (char *)L"The Direct3D device was removed." - (char *)Text);
        if ( !v33 )
          break;
        *v31++ = v33;
        if ( !--v32 )
        {
          *(v31 - 1) = 0;
          goto LABEL_70;
        }
      }
      *v31 = 0;
      break;
    default:
      v40 = 0;
      v1 = 1;
      break;
  }
LABEL_70:
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v8 = byte_4CA649 == 0;
  *(_DWORD *)(EngineInstance + 768) = v1;
  if ( !v8 )
    LeaveCriticalSection(&CriticalSection);
  v35 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v36 = *(_BYTE *)(v35 + 754);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v40 && v36 )
  {
    v37 = GetEngineInstance();
    if ( byte_4CA649 )
    {
      EnterCriticalSection(&CriticalSection);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
    }
    if ( *(_WORD *)(v37 + 7292) )
      v39 = (const WCHAR *)sub_41B8C0();
    else
      v39 = L"DXUT Application";
    v38 = (HWND)sub_41B5D0();
    MessageBoxW(v38, Text, v39, 0x10u);
  }
}
