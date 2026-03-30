void __cdecl sub_427980(int a1, char a2, int a3)
{
  _BYTE *EngineInstance; // esi
  char v4; // bl
  char *v5; // esi
  char *v6; // edi
  int v7; // edx
  _WORD *v8; // eax
  __int16 v9; // cx
  int v10; // edx
  __int16 v11; // cx
  int v12; // edx
  __int16 v13; // cx
  int v14; // eax
  _WORD *v15; // ecx
  int v16; // eax
  _WORD *v17; // ecx
  void *v18; // esi
  int *v19; // esi
  void *v20; // eax
  int v21; // eax
  WCHAR WideCharStr[514]; // [esp+18h] [ebp-408h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = EngineInstance[755];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v4 )
    return;
  v5 = (char *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v6 = v5 + 2684;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  switch ( a1 )
  {
    case 2:
      v7 = 256;
      v8 = v5 + 2684;
      while ( v7 != -2147483390 )
      {
        v9 = *(_WORD *)((char *)v8 + (char *)&off_4B8BC0 - v6);
        if ( !v9 )
          break;
        *v8++ = v9;
        if ( !--v7 )
          goto LABEL_29;
      }
LABEL_30:
      *v8 = 0;
      break;
    case 1:
      v10 = 256;
      v8 = v5 + 2684;
      while ( v10 != -2147483390 )
      {
        v11 = *(_WORD *)((char *)v8 + (char *)&off_4B8BC8 - v6);
        if ( !v11 )
          break;
        *v8++ = v11;
        if ( !--v10 )
          goto LABEL_29;
      }
      goto LABEL_30;
    case 3:
      v12 = 256;
      v8 = v5 + 2684;
      while ( v12 != -2147483390 )
      {
        v13 = *(_WORD *)((char *)v8 + (char *)L"SW" - v6);
        if ( !v13 )
          break;
        *v8++ = v13;
        if ( !--v12 )
        {
LABEL_29:
          --v8;
          goto LABEL_30;
        }
      }
      goto LABEL_30;
  }
  if ( (a2 & 0x40) != 0 && (a2 & 0x10) != 0 )
  {
    if ( a1 == 1 )
    {
      sub_4192D0(256, v6, (int)L" (pure hw vp)");
      goto LABEL_53;
    }
    sub_4192D0(256, v6, (int)L" (simulated pure hw vp)");
LABEL_52:
    if ( a1 != 1 )
      return;
    goto LABEL_53;
  }
  if ( (a2 & 0x40) != 0 )
  {
    v14 = 256;
    v15 = v5 + 2684;
    if ( a1 == 1 )
    {
      while ( *v15 )
      {
        ++v15;
        if ( !--v14 )
          goto LABEL_53;
      }
      sub_4193D0(v14, &v6[2 * (256 - v14)], (int)L" (hw vp)", 0x7FFFFFFF);
      goto LABEL_53;
    }
    while ( *v15 )
    {
      ++v15;
      if ( !--v14 )
        goto LABEL_52;
    }
    sub_4193D0(v14, &v6[2 * (256 - v14)], (int)L" (simulated hw vp)", 0x7FFFFFFF);
    goto LABEL_52;
  }
  if ( a2 >= 0 )
  {
    if ( (a2 & 0x20) != 0 )
      sub_4192D0(256, v6, (int)L" (sw vp)");
    goto LABEL_52;
  }
  if ( a1 != 1 )
  {
    sub_4192D0(256, v6, (int)L" (simulated mixed vp)");
    goto LABEL_52;
  }
  sub_4192D0(256, v6, (int)L" (mixed vp)");
LABEL_53:
  v16 = 256;
  v17 = v5 + 2684;
  while ( *v17 )
  {
    ++v17;
    if ( !--v16 )
      goto LABEL_58;
  }
  sub_4193D0(v16, &v6[2 * (256 - v16)], (int)L": ", 0x7FFFFFFF);
LABEL_58:
  v18 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v19 = (int *)*((_DWORD *)v18 + 2);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v19 )
  {
    v20 = sub_428650();
    v21 = sub_429610(v19[2], (int)v20, v19[1], v19[3], v19[7], v19[13]);
    if ( v21 )
    {
      sub_4192D0(256, v6, *(_DWORD *)(v21 + 80) + 1104);
    }
    else
    {
      MultiByteToWideChar(0, 0, (LPCCH)(a3 + 512), -1, WideCharStr, 512);
      WideCharStr[511] = 0;
      sub_4192D0(256, v6, (int)WideCharStr);
    }
  }
}
