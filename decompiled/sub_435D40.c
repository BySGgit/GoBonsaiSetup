char __thiscall sub_435D40(int this, int a2, int a3, int a4, int a5, int a6)
{
  HWND v7; // eax
  int v8; // ecx
  int v9; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // [esp+Ch] [ebp-Ch] BYREF
  int v14; // [esp+10h] [ebp-8h] BYREF
  int v15; // [esp+14h] [ebp-4h] BYREF

  if ( *(_BYTE *)(this + 60) && *(_BYTE *)(this + 4) )
  {
    switch ( a2 )
    {
      case 512:
        if ( !*(_BYTE *)(this + 324) )
          return 0;
        sub_436E90(this + 80, &v15, *(_DWORD *)(this + 304), 0);
        if ( sub_436ED0(this + 80, &v13, a3 + v15 - *(_DWORD *)(this + 108), &v14) < 0 )
          return 0;
        if ( v14 )
        {
          v11 = lstrlenW(*(LPCWSTR *)(this + 80));
          v12 = v13;
          if ( v13 < v11 )
          {
            sub_435650(v13 + 1, (_DWORD *)this);
            return 0;
          }
        }
        else
        {
          v12 = v13;
        }
        sub_435650(v12, (_DWORD *)this);
        break;
      case 513:
      case 515:
        if ( !*(_BYTE *)(this + 6) && dword_4D7F28 != this )
          sub_4302A0(this);
        if ( !(*(int (__thiscall **)(int, int, int))(*(_DWORD *)this + 52))(this, a3, a4) )
          return 0;
        *(_BYTE *)(this + 324) = 1;
        v7 = (HWND)sub_41B5D0();
        SetCapture(v7);
        sub_436E90(this + 80, &v14, *(_DWORD *)(this + 304), 0);
        if ( sub_436ED0(this + 80, &v13, v14 + a3 - *(_DWORD *)(this + 108), &v15) >= 0 )
        {
          if ( v15 )
          {
            v8 = lstrlenW(*(LPCWSTR *)(this + 80));
            v9 = v13;
            if ( v13 < v8 )
              v9 = v13 + 1;
          }
          else
          {
            v9 = v13;
          }
          sub_435650(v9, (_DWORD *)this);
          *(_DWORD *)(this + 300) = *(_DWORD *)(this + 292);
          sub_4370C0(this);
        }
        return 1;
      case 514:
        ReleaseCapture();
        *(_BYTE *)(this + 324) = 0;
        return 0;
      default:
        return 0;
    }
  }
  return 0;
}
