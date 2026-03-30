void sub_4267B0()
{
  _BYTE *EngineInstance; // esi
  char v1; // bl
  _BYTE *v2; // esi
  char v3; // bl
  HWND v4; // eax
  _DWORD v5[24]; // [esp+10h] [ebp-DCh] BYREF
  _BYTE v6[100]; // [esp+70h] [ebp-7Ch] BYREF
  struct tagRECT Rect; // [esp+D4h] [ebp-18h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[648];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v1 )
  {
    v2 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v3 = v2[774];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v3 && (!sub_41B490() || sub_41B9C0()) )
    {
      qmemcpy(v5, sub_427EC0(v6), sizeof(v5));
      if ( v5[0] )
      {
        sub_426710();
      }
      else
      {
        v4 = (HWND)sub_41B5D0();
        GetClientRect(v4, &Rect);
        if ( Rect.right != v5[5] || Rect.bottom != v5[6] )
        {
          v5[5] = 0;
          v5[6] = 0;
          sub_41E880(v5, 0, 0, 0, 0);
        }
      }
    }
  }
}
