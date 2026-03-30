const void *__stdcall sub_43AC20(int a1, int a2)
{
  const void *result; // eax
  HWND v3; // eax
  LONG bottom; // eax
  LONG right; // ecx
  LONG *v6; // eax
  bool v7; // zf
  HWND v8; // eax
  LONG v9; // eax
  LONG v10; // ecx
  LONG *v11; // eax
  int *v12; // [esp+8h] [ebp-1CCh]
  char v13; // [esp+1Bh] [ebp-1B9h]
  _DWORD v14[24]; // [esp+1Ch] [ebp-1B8h] BYREF
  _DWORD v15[4]; // [esp+7Ch] [ebp-158h] BYREF
  _DWORD v16[4]; // [esp+8Ch] [ebp-148h] BYREF
  _DWORD v17[24]; // [esp+9Ch] [ebp-138h] BYREF
  _BYTE v18[96]; // [esp+FCh] [ebp-D8h] BYREF
  _BYTE v19[100]; // [esp+15Ch] [ebp-78h] BYREF
  struct tagRECT Rect; // [esp+1C0h] [ebp-14h] BYREF

  result = (const void *)(a2 - 1);
  switch ( a2 )
  {
    case 1:
      v13 = 0;
      qmemcpy(v14, sub_427EC0(v18), sizeof(v14));
      if ( !dword_4D7DF0 )
      {
        if ( dword_4D7E24 )
        {
          *(_DWORD *)dword_4D7E34 = 0;
          if ( sub_41B9C0() )
          {
            v3 = (HWND)sub_41B5D0();
            GetClientRect(v3, &Rect);
            bottom = Rect.bottom;
            right = Rect.right;
          }
          else
          {
            v6 = sub_41B700(v16);
            Rect.left = *v6;
            Rect.top = v6[1];
            right = v6[2];
            Rect.right = right;
            bottom = v6[3];
          }
          *(_DWORD *)Args = right - Rect.left;
          dword_4D7E08 = bottom - Rect.top;
        }
        else if ( *(_DWORD *)Args != v14[5] || dword_4D7E08 != v14[6] || (v13 = 0, *(_DWORD *)dword_4D7E34 != v14[17]) )
        {
          v13 = 1;
        }
        if ( dword_4D7E14 )
          dword_4D7E30 &= ~1u;
        v7 = v13 == 0;
LABEL_36:
        if ( !v7 )
          goto LABEL_37;
LABEL_44:
        result = (const void *)sub_41E700(&dword_4D7DF0);
        goto LABEL_45;
      }
      if ( dword_4D7E30 )
      {
        dword_4D7E08 = 0;
        dword_4D7E0C = 0;
        if ( sub_41B9C0() )
        {
          v8 = (HWND)sub_41B5D0();
          GetClientRect(v8, &Rect);
          v9 = Rect.bottom;
          v10 = Rect.right;
        }
        else
        {
          v11 = sub_41B700(v15);
          Rect.left = *v11;
          Rect.top = v11[1];
          v10 = v11[2];
          Rect.right = v10;
          v9 = v11[3];
        }
        *(_DWORD *)dword_4D7E00 = v10 - Rect.left;
        *(_DWORD *)Args = v9 - Rect.top;
        goto LABEL_44;
      }
      if ( *(_DWORD *)dword_4D7E00 == v14[4] && *(_DWORD *)Args == v14[5] && dword_4D7E0C == v14[7] )
      {
        v7 = dword_4D7E08 == v14[6];
        goto LABEL_36;
      }
LABEL_37:
      qmemcpy(v17, &dword_4D7DF0, sizeof(v17));
      *(_DWORD *)Args = v14[5];
      if ( dword_4D7DF0 )
      {
        *(_DWORD *)dword_4D7E00 = v14[4];
        dword_4D7E0C = v14[7];
        dword_4D7E30 = v14[16];
      }
      else
      {
        *(_DWORD *)dword_4D7E34 = v14[17];
        dword_4D7E24 = v14[13];
      }
      dword_4D7E08 = v14[6];
      sub_41E700(v17);
      *(_DWORD *)(a1 + 8) = a1 + 768;
      *(_DWORD *)(a1 + 1520) = 15;
      sub_43EDC0(a1, 15);
      return (const void *)sub_425320(1.0, (_DWORD *)(a1 + 1524), a1);
    case 2:
LABEL_45:
      *(_BYTE *)(a1 + 1528) = 0;
      return result;
    case 3:
      return (const void *)sub_43B5A0((int *)a1);
    case 4:
      return (const void *)sub_43B760((int *)a1);
    case 5:
    case 6:
      return (const void *)sub_43B930((int *)a1);
    case 7:
      v12 = (int *)a1;
      return (const void *)sub_43C2F0(v12);
    case 9:
      return (const void *)sub_43C650((int *)a1);
    case 11:
    case 32:
      return (const void *)sub_43C9C0(a1);
    case 13:
    case 34:
      v12 = (int *)a1;
      return (const void *)sub_43CA00(v12);
    case 15:
      return (const void *)sub_43CF10(a1);
    case 17:
    case 36:
      return (const void *)sub_43D1B0(a1);
    case 19:
    case 38:
      return (const void *)sub_43D6B0(a1);
    case 21:
      return (const void *)sub_43D6E0(a1);
    case 23:
    case 40:
      return (const void *)sub_43D710(a1);
    case 25:
      return (const void *)sub_43D790(a1);
    case 26:
      v12 = (int *)a1;
      if ( dword_4D7DF0 )
        return (const void *)sub_43CA00(v12);
      else
        return (const void *)sub_43C2F0(v12);
    case 27:
      return (const void *)sub_43B270((int *)a1, 0);
    case 28:
      return (const void *)sub_43C070((int *)a1);
    case 30:
      return (const void *)sub_43C7D0((int *)a1);
    case 42:
      return (const void *)sub_43D740(a1);
    case 43:
      sub_425490(*(_DWORD *)(a1 + 1524));
      result = sub_427EC0(v19);
      qmemcpy(&dword_4D7DF0, result, 0x60u);
      *(_DWORD *)(a1 + 8) = a1 + 16;
      *(_BYTE *)(a1 + 1528) = 0;
      return result;
    case 44:
      sub_425490(*(_DWORD *)(a1 + 1524));
      *(_DWORD *)(a1 + 8) = a1 + 16;
      *(_DWORD *)(a1 + 1524) = 0;
      *(_DWORD *)(a1 + 1520) = 0;
      sub_41E700(&dword_4D7DF0);
      return (const void *)sub_4392B0(a1);
    default:
      return result;
  }
}
