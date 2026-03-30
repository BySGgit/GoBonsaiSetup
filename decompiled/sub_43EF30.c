void __stdcall sub_43EF30(int a1)
{
  _BYTE *EngineInstance; // esi
  HWND v2; // eax
  int v3; // edx
  WCHAR *v4; // eax
  HANDLE FileW; // esi
  void *v6; // esi
  HINSTANCE v7; // esi
  HWND v8; // eax
  char v9; // di
  HWND v10; // eax
  int v11; // edx
  WCHAR *v12; // eax
  int v13; // edx
  WCHAR *v14; // eax
  HANDLE v15; // eax
  void *v16; // esi
  char v17; // [esp+13h] [ebp-2E5h]
  int Buffer; // [esp+14h] [ebp-2E4h] BYREF
  DWORD NumberOfBytesRead; // [esp+18h] [ebp-2E0h] BYREF
  DWORD NumberOfBytesWritten; // [esp+1Ch] [ebp-2DCh] BYREF
  _DWORD hDialogTemplate[5]; // [esp+20h] [ebp-2D8h] BYREF
  __int16 v22; // [esp+34h] [ebp-2C4h]
  int v23; // [esp+36h] [ebp-2C2h]
  __int16 v24; // [esp+3Ah] [ebp-2BEh]
  _BYTE v25[30]; // [esp+3Ch] [ebp-2BCh] BYREF
  __int16 v26; // [esp+5Ah] [ebp-29Eh]
  int v27; // [esp+5Ch] [ebp-29Ch]
  int v28; // [esp+60h] [ebp-298h]
  int v29; // [esp+64h] [ebp-294h]
  int v30; // [esp+68h] [ebp-290h]
  int v31; // [esp+6Ch] [ebp-28Ch]
  int v32; // [esp+70h] [ebp-288h]
  int v33; // [esp+74h] [ebp-284h]
  int v34; // [esp+78h] [ebp-280h]
  int v35; // [esp+7Ch] [ebp-27Ch]
  int v36; // [esp+80h] [ebp-278h]
  int v37; // [esp+84h] [ebp-274h]
  int v38; // [esp+88h] [ebp-270h]
  int v39; // [esp+8Ch] [ebp-26Ch]
  int v40; // [esp+90h] [ebp-268h]
  int v41; // [esp+94h] [ebp-264h]
  int v42; // [esp+98h] [ebp-260h]
  int v43; // [esp+9Ch] [ebp-25Ch]
  int v44; // [esp+A0h] [ebp-258h]
  int v45; // [esp+A4h] [ebp-254h]
  int v46; // [esp+A8h] [ebp-250h]
  int v47; // [esp+ACh] [ebp-24Ch]
  int v48; // [esp+B0h] [ebp-248h]
  int v49; // [esp+B4h] [ebp-244h]
  int v50; // [esp+B8h] [ebp-240h]
  int v51; // [esp+BCh] [ebp-23Ch]
  int v52; // [esp+C0h] [ebp-238h]
  int v53; // [esp+C4h] [ebp-234h]
  int v54; // [esp+C8h] [ebp-230h]
  int v55; // [esp+CCh] [ebp-22Ch]
  int v56; // [esp+D0h] [ebp-228h]
  int v57; // [esp+D4h] [ebp-224h]
  int v58; // [esp+D8h] [ebp-220h]
  int v59; // [esp+DCh] [ebp-21Ch]
  int v60; // [esp+E0h] [ebp-218h]
  int v61; // [esp+E4h] [ebp-214h]
  WCHAR pszPath[262]; // [esp+E8h] [ebp-210h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v17 = EngineInstance[754];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v17 )
  {
    Buffer = 0;
    NumberOfBytesRead = 0;
    NumberOfBytesWritten = 0;
    v2 = (HWND)sub_41B5D0();
    SHGetFolderPathW(v2, 28, 0, 0, pszPath);
    v3 = 260;
    v4 = pszPath;
    while ( *v4 )
    {
      ++v4;
      if ( !--v3 )
        goto LABEL_11;
    }
    sub_4193D0(v3, &pszPath[260 - v3], (int)&off_4BB870, 0x7FFFFFFF);
LABEL_11:
    FileW = CreateFileW(pszPath, 0x80000000, 1u, 0, 3u, 0, 0);
    if ( FileW != (HANDLE)-1 )
    {
      ReadFile(FileW, &Buffer, 4u, &NumberOfBytesRead, 0);
      CloseHandle(FileW);
    }
    if ( !Buffer )
    {
      v24 = 8;
      hDialogTemplate[0] = -1865938747;
      hDialogTemplate[1] = 0;
      hDialogTemplate[2] = 5;
      hDialogTemplate[3] = 17629184;
      hDialogTemplate[4] = 82;
      v22 = 0;
      v23 = 32;
      qmemcpy(v25, L"MS Shell Dlg 2", sizeof(v25));
      v26 = 0;
      v27 = 1342177795;
      v28 = 0;
      v29 = 458759;
      v30 = 1572888;
      v31 = -65280;
      v32 = 130;
      v33 = 0;
      v34 = 1342177280;
      v35 = 0;
      v36 = 458792;
      v37 = 1638630;
      v38 = -65279;
      v39 = 130;
      v40 = 0;
      v41 = 1342242817;
      v42 = 0;
      v43 = 2555984;
      v44 = 917554;
      v45 = -65530;
      v46 = 128;
      v47 = 0;
      v48 = 1342242816;
      v49 = 0;
      v50 = 2556037;
      v51 = 917554;
      v52 = -65529;
      v53 = 128;
      v54 = 0;
      v55 = 1342242818;
      v56 = 0;
      v57 = 3866631;
      v58 = 1048646;
      v59 = -65531;
      v60 = 128;
      v61 = 0;
      v6 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v7 = (HINSTANCE)*((_DWORD *)v6 + 169);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      v8 = (HWND)sub_41B5D0();
      v9 = DialogBoxIndirectParamW(v7, (LPCDLGTEMPLATEW)hDialogTemplate, v8, DialogFunc, (a1 != 0) + 9);
      if ( (v9 & 0x80) == 0x80 )
      {
        Buffer = 1;
        v10 = (HWND)sub_41B5D0();
        SHGetFolderPathW(v10, 28, 0, 0, pszPath);
        v11 = 260;
        v12 = pszPath;
        while ( *v12 )
        {
          ++v12;
          if ( !--v11 )
            goto LABEL_24;
        }
        sub_4193D0(v11, &pszPath[260 - v11], (int)&off_4BB8C8, 0x7FFFFFFF);
LABEL_24:
        CreateDirectoryW(pszPath, 0);
        v13 = 260;
        v14 = pszPath;
        while ( *v14 )
        {
          ++v14;
          if ( !--v13 )
            goto LABEL_29;
        }
        sub_4193D0(v13, &pszPath[260 - v13], (int)L"\\SkipRefWarning.dat", 0x7FFFFFFF);
LABEL_29:
        v15 = CreateFileW(pszPath, 0x40000000u, 0, 0, 2u, 0, 0);
        v16 = v15;
        if ( v15 != (HANDLE)-1 )
        {
          WriteFile(v15, &Buffer, 4u, &NumberOfBytesWritten, 0);
          CloseHandle(v16);
        }
      }
      if ( (v9 & 0xF) == 7 )
        sub_428190(1);
    }
  }
}
