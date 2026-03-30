void sub_427400()
{
  _BYTE *EngineInstance; // esi
  char v1; // bl
  _DWORD *v2; // esi
  _DWORD *v3; // ebx
  void *v4; // ecx
  int v5; // eax
  int v6; // esi
  int v7; // eax
  const wchar_t *v8; // eax
  wchar_t *v9; // ecx
  int v10; // edx
  int v11; // esi
  wchar_t v12; // ax
  const wchar_t *v13; // eax
  const wchar_t *v14; // eax
  int v15; // eax
  bool v16; // zf
  wchar_t *v17; // eax
  int v18; // edx
  wchar_t v19; // cx
  int v20; // edx
  wchar_t v21; // cx
  void *v22; // eax
  wchar_t *v23; // eax
  const wchar_t *v24; // ecx
  void *v25; // eax
  int v26; // eax
  const wchar_t *v27; // eax
  wchar_t *v28; // ecx
  int v29; // edx
  int v30; // esi
  wchar_t v31; // ax
  int v32; // eax
  void *v33; // eax
  wchar_t *v34; // eax
  const wchar_t *v35; // ecx
  const wchar_t *v36; // [esp-4h] [ebp-278h]
  wchar_t Buffer[100]; // [esp+10h] [ebp-264h] BYREF
  wchar_t v38[100]; // [esp+D8h] [ebp-19Ch] BYREF
  wchar_t v39[102]; // [esp+1A0h] [ebp-D4h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[755];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v1 )
  {
    v2 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v3 = (_DWORD *)v2[2];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v3 )
    {
      if ( !*v3 )
      {
        v4 = sub_428650();
        if ( !v4 )
          return;
        v5 = sub_429610(v3[2], (int)v4, v3[1], v3[3], v3[7], v3[13]);
        v6 = v5;
        if ( !v5 )
          return;
        v7 = *(_DWORD *)(v5 + 8);
        if ( v7 == *(_DWORD *)(v6 + 12) )
        {
          v8 = sub_437720(v7, 0);
          v9 = Buffer;
          v10 = 100;
          v11 = (char *)v8 - (char *)Buffer;
          while ( v10 != -2147483546 )
          {
            v12 = *(wchar_t *)((char *)v9 + v11);
            if ( !v12 )
              break;
            *v9++ = v12;
            if ( !--v10 )
            {
              *(v9 - 1) = 0;
              goto LABEL_22;
            }
          }
          *v9 = 0;
        }
        else
        {
          v36 = sub_437720(v7, 0);
          v13 = sub_437720(*(_DWORD *)(v6 + 12), 0);
          sub_419310(Buffer, (wchar_t *)L"backbuf %s, adapter %s", v13, v36);
        }
LABEL_22:
        if ( v3[14] )
        {
          v14 = sub_437720(v3[15], 0);
          sub_419310(v39, (wchar_t *)L" (%s)", v14);
        }
        else
        {
          v39[0] = 0;
        }
        v15 = v3[9];
        if ( v15 )
        {
          v16 = v15 == 1;
          v17 = v38;
          if ( !v16 )
          {
            sub_419310(v38, (wchar_t *)L" (%dx Multisample)", v3[9]);
LABEL_41:
            v22 = GetEngineInstance();
            v23 = (wchar_t *)sub_41B360((int)v22);
            v24 = L"off";
            if ( v3[18] != 0x80000000 )
              v24 = L"on";
            sub_419310(v23, (wchar_t *)L"D3D9 %%sVsync %s (%dx%d), %s%s%s", v24, v3[5], v3[6], Buffer, v39, v38);
            return;
          }
          v18 = 100;
          while ( v18 != -2147483546 )
          {
            v19 = *(wchar_t *)((char *)v17 + (char *)L" (Nonmaskable Multisample)" - (char *)v38);
            if ( !v19 )
              break;
            *v17++ = v19;
            if ( !--v18 )
              goto LABEL_39;
          }
        }
        else
        {
          v17 = v38;
          v20 = 100;
          while ( v20 != -2147483546 )
          {
            v21 = *(wchar_t *)((char *)v17 + &word_4B765C - (_UNKNOWN *)v38);
            if ( !v21 )
              break;
            *v17++ = v21;
            if ( !--v20 )
            {
LABEL_39:
              --v17;
              break;
            }
          }
        }
        *v17 = 0;
        goto LABEL_41;
      }
      v25 = sub_42B3D0();
      if ( v25 )
      {
        v26 = sub_42C300((int)v25, v3[1], v3[8], v3[16]);
        if ( v26 )
        {
          v27 = sub_437B00(*(_DWORD *)(v26 + 8), 0);
          v28 = v39;
          v29 = 100;
          v30 = (char *)v27 - (char *)v39;
          while ( v29 != -2147483546 )
          {
            v31 = *(wchar_t *)((char *)v28 + v30);
            if ( !v31 )
              break;
            *v28++ = v31;
            if ( !--v29 )
            {
              --v28;
              break;
            }
          }
          v32 = v3[12];
          *v28 = 0;
          sub_419310(Buffer, (wchar_t *)L" (MS%u, Q%u)", v3[11], v32);
          v33 = GetEngineInstance();
          v34 = (wchar_t *)sub_41B360((int)v33);
          v35 = L"off";
          if ( v3[20] )
            v35 = L"on";
          sub_419310(v34, (wchar_t *)L"D3D10 %%sVsync %s (%dx%d), %s%s", v35, v3[4], v3[5], v39, Buffer);
        }
      }
    }
  }
}
