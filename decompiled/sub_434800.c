char __thiscall sub_434800(int this, int a2, POINT pt, int a4, int a5)
{
  HWND v6; // eax
  int v7; // ecx
  bool v8; // zf
  char result; // al
  LONG x; // eax
  int v11; // ecx
  int v12; // eax
  void (__stdcall *v13)(int, _DWORD, int, _DWORD); // ecx
  int v14; // eax

  if ( !*(_BYTE *)(this + 60) || !*(_BYTE *)(this + 4) )
    return 0;
  switch ( a2 )
  {
    case 512:
      if ( !*(_BYTE *)(this + 104) )
        goto LABEL_23;
      v14 = sub_4346A0((_DWORD *)this, pt.x + *(_DWORD *)(this + 8) + *(_DWORD *)(this + 96));
      sub_434A20(v14, (_DWORD *)this, 1);
      result = 1;
      break;
    case 513:
    case 515:
      if ( PtInRect((const RECT *)(this + 108), pt) )
      {
        *(_BYTE *)(this + 104) = 1;
        v6 = (HWND)sub_41B5D0();
        SetCapture(v6);
        v7 = *(_DWORD *)(this + 100) - pt.x;
        v8 = *(_BYTE *)(this + 6) == 0;
        *(_DWORD *)(this + 92) = pt.x;
        *(_DWORD *)(this + 96) = v7;
        if ( !v8 || dword_4D7F28 == this )
          goto LABEL_14;
        sub_4302A0(this);
        result = 1;
      }
      else
      {
        if ( !PtInRect((const RECT *)(this + 64), pt) )
          goto LABEL_23;
        v8 = *(_BYTE *)(this + 6) == 0;
        x = pt.x;
        *(_DWORD *)(this + 92) = pt.x;
        *(_DWORD *)(this + 96) = 0;
        *(_BYTE *)(this + 104) = 1;
        if ( v8 && dword_4D7F28 != this )
        {
          sub_4302A0(this);
          x = pt.x;
        }
        v11 = *(_DWORD *)(this + 100) + *(_DWORD *)(this + 8);
        if ( x > v11 )
        {
          sub_434A20(*(_DWORD *)(this + 80) + 1, (_DWORD *)this, 1);
          goto LABEL_14;
        }
        if ( x >= v11 )
          goto LABEL_23;
        sub_434A20(*(_DWORD *)(this + 80) - 1, (_DWORD *)this, 1);
        result = 1;
      }
      break;
    case 514:
      if ( !*(_BYTE *)(this + 104) )
        goto LABEL_23;
      *(_BYTE *)(this + 104) = 0;
      ReleaseCapture();
      v12 = *(_DWORD *)(this + 24);
      v13 = *(void (__stdcall **)(int, _DWORD, int, _DWORD))(v12 + 576);
      if ( v13 )
      {
        v13(1281, *(_DWORD *)(this + 44), this, *(_DWORD *)(v12 + 580));
        result = 1;
      }
      else
      {
LABEL_14:
        result = 1;
      }
      break;
    case 522:
      sub_434A20(*(_DWORD *)(this + 80) - SHIWORD(a4) / 120, (_DWORD *)this, 1);
      result = 1;
      break;
    default:
LABEL_23:
      result = 0;
      break;
  }
  return result;
}
