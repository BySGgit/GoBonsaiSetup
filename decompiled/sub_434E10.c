char __thiscall sub_434E10(int this, int a2, POINT pt, int a4, int a5)
{
  HWND v6; // eax
  int v7; // eax
  char result; // al
  HWND v9; // eax
  int v10; // eax
  HWND v11; // eax
  int v12; // ecx
  HWND v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // ecx
  int v17; // ecx
  int v18; // eax
  int v19; // edi

  *(POINT *)(this + 164) = pt;
  switch ( a2 )
  {
    case 512:
      if ( !*(_BYTE *)(this + 81) )
        goto LABEL_21;
      v14 = pt.y - *(_DWORD *)(this + 136);
      v15 = pt.y - dword_4D8EA0;
      v16 = *(_DWORD *)(this + 120);
      *(_DWORD *)(this + 144) += v14 - dword_4D8EA0;
      *(_DWORD *)(this + 136) = v15;
      if ( v15 >= v16 )
      {
        v17 = *(_DWORD *)(this + 144);
        v18 = *(_DWORD *)(this + 128);
        if ( v17 > v18 )
          OffsetRect((LPRECT)(this + 132), 0, v18 - v17);
      }
      else
      {
        OffsetRect((LPRECT)(this + 132), 0, v16 - v15);
      }
      v19 = *(_DWORD *)(this + 160) - *(_DWORD *)(this + 152) - *(_DWORD *)(this + 156);
      *(_DWORD *)(this + 148) = *(_DWORD *)(this + 156)
                              + v19
                              * (*(_DWORD *)(this + 136)
                               + (*(_DWORD *)(this + 128)
                                + *(_DWORD *)(this + 136)
                                - *(_DWORD *)(this + 144)
                                - *(_DWORD *)(this + 120))
                               / (2
                                * v19)
                               - *(_DWORD *)(this + 120))
                              / (*(_DWORD *)(this + 128)
                               + *(_DWORD *)(this + 136)
                               - *(_DWORD *)(this + 144)
                               - *(_DWORD *)(this + 120));
      result = 1;
      break;
    case 513:
    case 515:
      if ( PtInRect((const RECT *)(this + 84), pt) )
      {
        v6 = (HWND)sub_41B5D0();
        SetCapture(v6);
        v7 = *(_DWORD *)(this + 148);
        if ( v7 > *(_DWORD *)(this + 156) )
          *(_DWORD *)(this + 148) = v7 - 1;
        sub_434D20(this);
        *(_DWORD *)(this + 172) = 1;
        *(double *)(this + 176) = sub_41B820();
        result = 1;
      }
      else if ( PtInRect((const RECT *)(this + 100), pt) )
      {
        v9 = (HWND)sub_41B5D0();
        SetCapture(v9);
        v10 = *(_DWORD *)(this + 148);
        if ( v10 + *(_DWORD *)(this + 152) < *(_DWORD *)(this + 160) )
          *(_DWORD *)(this + 148) = v10 + 1;
        sub_434D20(this);
        *(_DWORD *)(this + 172) = 2;
        *(double *)(this + 176) = sub_41B820();
        result = 1;
      }
      else if ( PtInRect((const RECT *)(this + 132), pt) )
      {
        v11 = (HWND)sub_41B5D0();
        SetCapture(v11);
        v12 = pt.y - *(_DWORD *)(this + 136);
        *(_BYTE *)(this + 81) = 1;
        dword_4D8EA0 = v12;
        result = 1;
      }
      else
      {
        if ( *(_DWORD *)(this + 132) > pt.x || *(_DWORD *)(this + 140) <= pt.x )
          goto LABEL_21;
        v13 = (HWND)sub_41B5D0();
        SetCapture(v13);
        if ( *(_DWORD *)(this + 136) <= pt.y || *(_DWORD *)(this + 120) > pt.y )
        {
          if ( *(_DWORD *)(this + 144) > pt.y || *(_DWORD *)(this + 128) <= pt.y )
            goto LABEL_21;
          sub_434DA0(this, *(_DWORD *)(this + 152) - 1);
          result = 1;
        }
        else
        {
          sub_434DA0(this, 1 - *(_DWORD *)(this + 152));
          result = 1;
        }
      }
      break;
    case 514:
      *(_BYTE *)(this + 81) = 0;
      ReleaseCapture();
      sub_434D20(this);
      *(_DWORD *)(this + 172) = 0;
      goto LABEL_21;
    default:
LABEL_21:
      result = 0;
      break;
  }
  return result;
}
