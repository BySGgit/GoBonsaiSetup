void __stdcall sub_406770(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // eax

  if ( (dword_4D8EC0 & 1) == 0 )
  {
    dword_4D8EC0 |= 1u;
    sub_43FD00();
    atexit(sub_472560);
  }
  if ( !byte_4D8E90 )
  {
    sub_4077D0(a2, a3);
    switch ( a2 )
    {
      case 12:
        sub_412510();
        break;
      case 15:
        sub_4123C0();
        break;
      case 16:
        byte_4D7F9D = 1;
        break;
      case 17:
        *(_BYTE *)(dword_4D7EE8 + 220) = *(_BYTE *)(dword_4D7EE8 + 220) == 0;
        v4 = sub_4301A0();
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 64))(v4, 1);
        break;
      case 18:
        byte_4D7E50 = byte_4D7E50 == 0;
        break;
      case 19:
        byte_4D7E51 = byte_4D7E51 == 0;
        sub_4075C0((unsigned __int8)byte_4D7E51);
        break;
      case 21:
        dword_4D8644 = 0;
        break;
      case 22:
        dword_4D8644 = 1;
        break;
      case 23:
        dword_4D8644 = 2;
        break;
      case 24:
        dword_4D8644 = 3;
        break;
      case 25:
        dword_4D8644 = 4;
        break;
      case 26:
        dword_4D8644 = 5;
        break;
      case 27:
        flt_4D526C = 0.0;
        break;
      case 28:
        flt_4D526C = 1.0;
        break;
      case 29:
        flt_4D526C = 8.0;
        break;
      case 30:
        flt_4D526C = flt_4D52E8;
        break;
      case 31:
        v5 = sub_407B60();
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 64))(v5, 1);
        flt_4D526C = 150.0;
        break;
      default:
        return;
    }
  }
}
