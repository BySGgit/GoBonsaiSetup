char __thiscall sub_433860(char *this, int a2, POINT pt, int a4, int a5)
{
  int i; // edi
  int v7; // eax
  HWND v9; // eax
  bool v10; // al
  int v11; // edi
  int v12; // eax
  int v13; // eax
  void (__stdcall *v14)(int, _DWORD, char *, _DWORD); // ecx
  int v15; // eax
  int v16; // eax
  void (__stdcall *v17)(int, _DWORD, char *, _DWORD); // ecx
  int v18; // ecx
  int v19; // edi
  int v20; // eax
  int v21; // eax
  int v22; // eax
  void (__stdcall *v23)(int, _DWORD, char *, _DWORD); // ecx
  int pvParam; // [esp+14h] [ebp-4h] BYREF

  if ( *(this + 60) && *(this + 4) )
  {
    if ( (*(unsigned __int8 (__thiscall **)(char *, int, LONG, LONG, int, int))(*((_DWORD *)this + 154) + 24))(
           this + 616,
           a2,
           pt.x,
           pt.y,
           a4,
           a5) )
    {
      return 1;
    }
    switch ( a2 )
    {
      case 512:
        if ( !*(this + 804) || !PtInRect((const RECT *)(this + 840), pt) )
          return 0;
        for ( i = 0; i < *((_DWORD *)this + 219); ++i )
        {
          v7 = *(_DWORD *)(*((_DWORD *)this + 218) + 4 * i);
          if ( *(_BYTE *)(v7 + 532) )
          {
            if ( PtInRect((const RECT *)(v7 + 516), pt) )
              *((_DWORD *)this + 152) = i;
          }
        }
        return 1;
      case 513:
      case 515:
        if ( (*(int (__thiscall **)(char *, LONG, LONG))(*(_DWORD *)this + 52))(this, pt.x, pt.y) )
        {
          *(this + 600) = 1;
          v9 = (HWND)sub_41B5D0();
          SetCapture(v9);
          if ( *(this + 6) )
            goto LABEL_18;
          if ( (char *)dword_4D7F28 != this )
            sub_4302A0((int)this);
          if ( *(this + 6) )
          {
LABEL_18:
            v10 = *(this + 804) == 0;
            *(this + 804) = v10;
            if ( !v10 && !*(_BYTE *)(*((_DWORD *)this + 6) + 1) )
              sub_4315F0();
          }
          return 1;
        }
        if ( !*(this + 804) )
          goto LABEL_37;
        if ( PtInRect((const RECT *)(this + 840), pt) )
        {
          v11 = *((_DWORD *)this + 191);
          if ( v11 >= *((_DWORD *)this + 219) )
            return 1;
          while ( 1 )
          {
            v12 = *(_DWORD *)(*((_DWORD *)this + 218) + 4 * v11);
            if ( *(_BYTE *)(v12 + 532) )
            {
              if ( PtInRect((const RECT *)(v12 + 516), pt) )
                break;
            }
            if ( ++v11 >= *((_DWORD *)this + 219) )
              return 1;
          }
          v13 = *((_DWORD *)this + 6);
          *((_DWORD *)this + 151) = v11;
          *((_DWORD *)this + 152) = v11;
          v14 = *(void (__stdcall **)(int, _DWORD, char *, _DWORD))(v13 + 576);
          if ( v14 )
            v14(513, *((_DWORD *)this + 11), this, *(_DWORD *)(v13 + 580));
          v15 = *((_DWORD *)this + 6);
          *(this + 804) = 0;
          if ( *(_BYTE *)(v15 + 1) )
            return 1;
          sub_4315F0();
          return 1;
        }
        if ( *(this + 804) )
        {
          v16 = *((_DWORD *)this + 6);
          *((_DWORD *)this + 152) = *((_DWORD *)this + 151);
          v17 = *(void (__stdcall **)(int, _DWORD, char *, _DWORD))(v16 + 576);
          if ( v17 )
            v17(513, *((_DWORD *)this + 11), this, *(_DWORD *)(v16 + 580));
          *(this + 804) = 0;
        }
LABEL_37:
        v18 = *((_DWORD *)this + 6);
        *(this + 600) = 0;
        if ( !*(_BYTE *)(v18 + 1) )
          sub_4315F0();
        break;
      case 514:
        if ( !*(this + 600) || !(*(int (__thiscall **)(char *, LONG, LONG))(*(_DWORD *)this + 52))(this, pt.x, pt.y) )
          return 0;
        *(this + 600) = 0;
        ReleaseCapture();
        return 1;
      case 522:
        v19 = SHIWORD(a4) / 120;
        if ( *(this + 804) )
        {
          SystemParametersInfoW(0x68u, 0, &pvParam, 0);
          sub_434DA0((int)(this + 616), -(v19 * pvParam));
          return 1;
        }
        v20 = *((_DWORD *)this + 152);
        if ( v19 <= 0 )
        {
          v21 = v20 + 1;
          if ( v21 >= *((_DWORD *)this + 219) )
            return 1;
        }
        else
        {
          if ( v20 <= 0 )
            return 1;
          v21 = v20 - 1;
        }
        *((_DWORD *)this + 152) = v21;
        *((_DWORD *)this + 151) = v21;
        v22 = *((_DWORD *)this + 6);
        v23 = *(void (__stdcall **)(int, _DWORD, char *, _DWORD))(v22 + 576);
        if ( v23 )
          v23(513, *((_DWORD *)this + 11), this, *(_DWORD *)(v22 + 580));
        return 1;
      default:
        return 0;
    }
  }
  return 0;
}
