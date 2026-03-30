int sub_4224F0()
{
  _BYTE *EngineInstance; // esi
  bool v1; // zf
  _DWORD *v2; // esi
  _DWORD *v3; // edi
  _DWORD *v4; // esi
  int v5; // esi
  HWND v6; // eax
  int v7; // edx
  int v8; // edx
  int result; // eax
  _BYTE *v10; // ebp
  void *v11; // eax
  int v12; // ecx
  _BYTE *v13; // esi
  struct tagRECT Rect; // [esp+10h] [ebp-54h] BYREF
  int v15; // [esp+20h] [ebp-44h] BYREF
  int v16; // [esp+24h] [ebp-40h]
  int v17; // [esp+30h] [ebp-34h]
  int v18; // [esp+50h] [ebp-14h]

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  EngineInstance[779] = 0;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
  sub_4250D0(1, 1);
  v2 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = (_DWORD *)v2[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v4 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v5 = v4[94];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, int *))(*(_DWORD *)v5 + 48))(v5, &v15);
  if ( v3[16] && v18 )
  {
    v6 = (HWND)sub_41B5D0();
    GetClientRect(v6, &Rect);
    v7 = Rect.bottom - Rect.top;
    v3[4] = Rect.right - Rect.left;
    v3[5] = v7;
  }
  v8 = v3[16];
  if ( v18 == v8 )
  {
    v12 = v3[4];
    if ( v12 == v15 )
    {
      if ( v3[5] == v16 && v3[8] != v17 )
      {
        sub_426190(v8 == 0);
        goto LABEL_39;
      }
      if ( v12 == v15 && v3[5] == v16 )
      {
        v13 = GetEngineInstance();
        if ( byte_4CA649 )
          EnterCriticalSection(&CriticalSection);
        v1 = byte_4CA649 == 0;
        v13[779] = 1;
        if ( !v1 )
          LeaveCriticalSection(&CriticalSection);
        goto LABEL_39;
      }
    }
    result = (*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)v5 + 56))(v5, v3 + 4);
    if ( result >= 0 )
      goto LABEL_39;
  }
  else
  {
    if ( v8 )
    {
      result = (*(int (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)v5 + 40))(v5, 0, 0);
      if ( result < 0 )
        return result;
LABEL_39:
      sub_4250D0(0, 0);
      return 0;
    }
    v10 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v1 = byte_4CA649 == 0;
    v10[413] = 1;
    if ( !v1 )
      LeaveCriticalSection(&CriticalSection);
    result = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v5 + 40))(v5, 1, 0);
    if ( result >= 0 )
    {
      v11 = GetEngineInstance();
      sub_419810((int)v11, 0);
      result = (*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)v5 + 56))(v5, v3 + 4);
      if ( result >= 0 )
        goto LABEL_39;
    }
  }
  return result;
}
