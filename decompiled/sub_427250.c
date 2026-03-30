BOOL sub_427250()
{
  _DWORD *EngineInstance; // esi
  _DWORD *v1; // esi
  _DWORD *v2; // esi
  int v3; // esi
  void *v4; // eax
  HWND v5; // eax
  int v6; // eax
  int v7; // eax
  _BYTE *v8; // esi
  char v9; // bl
  HWND v10; // eax
  _BYTE *v12; // esi
  char v13; // bl
  struct tagRECT Rect; // [esp+14h] [ebp-18h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = (_DWORD *)EngineInstance[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v1 || *v1 )
  {
    if ( !sub_41B9C0() )
    {
      v12 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v13 = v12[756];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( v13 )
        goto LABEL_22;
    }
  }
  else
  {
    v2 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v3 = v2[1];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( !sub_41B9C0() && v3 )
    {
      v4 = GetEngineInstance();
      if ( sub_41A260((int)v4) )
      {
        SetCursor(0);
        v5 = (HWND)sub_41B680();
        GetClassLongW(v5, -12);
        sub_421370(v3);
        v6 = sub_41B510();
        (*(void (__stdcall **)(int, int))(*(_DWORD *)v6 + 48))(v6, 1);
      }
      else
      {
        SetCursor(0);
        v7 = sub_41B510();
        (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v7 + 48))(v7, 0);
      }
    }
    if ( !sub_41B9C0() )
    {
      v8 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v9 = v8[756];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( v9 )
      {
LABEL_22:
        v10 = (HWND)sub_41B680();
        GetWindowRect(v10, &Rect);
        return ClipCursor(&Rect);
      }
    }
  }
  return ClipCursor(0);
}
