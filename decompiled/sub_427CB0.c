void __usercall sub_427CB0(int a1@<eax>, int a2)
{
  _BYTE *EngineInstance; // esi
  char v4; // bl
  char *v5; // esi
  char *v6; // ebx
  int v7; // edx
  _WORD *v8; // eax
  __int16 v9; // cx
  int v10; // edx
  _WORD *v11; // eax
  __int16 v12; // cx
  int v13; // edx
  _WORD *v14; // eax
  int v15; // edx
  _WORD *v16; // eax
  __int16 v17; // cx
  void *v18; // esi
  int *v19; // esi
  void *v20; // eax
  int v21; // eax

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = EngineInstance[755];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v4 )
  {
    v5 = (char *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v6 = v5 + 2684;
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( a1 == 1 )
    {
      v7 = 256;
      v8 = v5 + 2684;
      while ( v7 != -2147483390 )
      {
        v9 = *(_WORD *)((char *)v8 + (char *)&off_4B8CC0 - v6);
        if ( !v9 )
          break;
        *v8++ = v9;
        if ( !--v7 )
        {
          *(v8 - 1) = 0;
          return;
        }
      }
      *v8 = 0;
    }
    else if ( a1 )
    {
      if ( a1 == 3 )
      {
        v15 = 256;
        v16 = v5 + 2684;
        while ( v15 != -2147483390 )
        {
          v17 = *(_WORD *)((char *)v16 + (char *)L"SOFTWARE" - v6);
          if ( !v17 )
            break;
          *v16++ = v17;
          if ( !--v15 )
          {
            *(v16 - 1) = 0;
            return;
          }
        }
        *v16 = 0;
      }
    }
    else
    {
      v10 = 256;
      v11 = v5 + 2684;
      while ( v10 != -2147483390 )
      {
        v12 = *(_WORD *)((char *)v11 + (char *)&off_4B8CD4 - v6);
        if ( !v12 )
          break;
        *v11++ = v12;
        if ( !--v10 )
        {
          --v11;
          break;
        }
      }
      *v11 = 0;
      v13 = 256;
      v14 = v5 + 2684;
      while ( *v14 )
      {
        ++v14;
        if ( !--v13 )
          goto LABEL_35;
      }
      sub_4193D0(v13, &v6[2 * (256 - v13)], (int)L": ", 0x7FFFFFFF);
LABEL_35:
      v18 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v19 = (int *)*((_DWORD *)v18 + 2);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( v19 )
      {
        v20 = sub_42B3D0();
        v21 = sub_42C300((int)v20, v19[1], v19[8], v19[16]);
        if ( v21 )
          sub_4192D0(256, v6, *(_DWORD *)(v21 + 44) + 296);
        else
          sub_4192D0(256, v6, a2);
      }
    }
  }
}
