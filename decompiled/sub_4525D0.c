int __stdcall sub_4525D0(HWND hWnd, int a2, int a3, int a4, char *a5, int a6)
{
  char v7; // al
  char v8; // al

  *a5 = 0;
  if ( byte_4D59C0 )
  {
    sub_42F490(dword_4D53D0, (int)hWnd, a2, a3, a4);
    if ( a2 == 256 && a3 == 113 )
    {
      byte_4D59C0 = 0;
      return 0;
    }
  }
  else
  {
    if ( a2 == 522 )
      sub_408060(a3, 522);
    v7 = sub_42F490((int)&unk_4D59C8, (int)hWnd, a2, a3, a4);
    *a5 = v7;
    if ( !v7 )
    {
      v8 = sub_42F490((int)&unk_4D5FA8, (int)hWnd, a2, a3, a4);
      *a5 = v8;
      if ( !v8 )
      {
        switch ( a2 )
        {
          case 513:
          case 516:
          case 519:
            SetCapture(hWnd);
            sub_408060(a3, a2);
            return 0;
          case 514:
          case 517:
          case 520:
            ReleaseCapture();
            goto LABEL_12;
          case 515:
          case 518:
          case 521:
LABEL_12:
            sub_408060(a3, a2);
            break;
          default:
            return 0;
        }
      }
    }
  }
  return 0;
}
