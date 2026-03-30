void sub_441EF0()
{
  float v0; // [esp+10h] [ebp-5Ch] BYREF
  float v1; // [esp+14h] [ebp-58h]
  float v2; // [esp+18h] [ebp-54h]
  float v3; // [esp+1Ch] [ebp-50h]
  void *v4[5]; // [esp+20h] [ebp-4Ch] BYREF
  unsigned int v5; // [esp+34h] [ebp-38h]
  void *v6[4]; // [esp+3Ch] [ebp-30h] BYREF
  int v7; // [esp+4Ch] [ebp-20h]
  unsigned int v8; // [esp+50h] [ebp-1Ch]
  int v9; // [esp+68h] [ebp-4h]

  LOWORD(v6[0]) = 0;
  v8 = 7;
  v7 = 0;
  sub_4032D0(word_4B765C, (int)v6, 0);
  v9 = 0;
  if ( (dword_4D8EC0 & 1) == 0 )
  {
    dword_4D8EC0 |= 1u;
    LOBYTE(v9) = 1;
    sub_43FD00();
    atexit(sub_472560);
    LOBYTE(v9) = 0;
  }
  v0 = 1.0;
  v1 = 1.0;
  v2 = 1.0;
  v3 = 1.0;
  sub_441E00((int *)&v0, (int)&dword_4D8E20, v6);
  v9 = -1;
  if ( v8 >= 8 )
    operator delete(v6[0]);
  LOWORD(v6[0]) = 0;
  v8 = 7;
  v7 = 0;
  sub_4032D0(L"Press ~ anytime to bring up the debug console.", (int)v6, 0x2Eu);
  v9 = 2;
  if ( (dword_4D8EC0 & 1) == 0 )
  {
    dword_4D8EC0 |= 1u;
    LOBYTE(v9) = 3;
    sub_43FD00();
    atexit(sub_472560);
    LOBYTE(v9) = 2;
  }
  v0 = 1.0;
  v1 = 1.0;
  v2 = 1.0;
  v3 = 1.0;
  sub_441E00((int *)&v0, (int)&dword_4D8E20, v6);
  v9 = -1;
  if ( v8 >= 8 )
    operator delete(v6[0]);
  LOWORD(v6[0]) = 0;
  v8 = 7;
  v7 = 0;
  sub_4032D0(L"While the console is active it will block all keyboard input to the game.", (int)v6, 0x49u);
  v9 = 4;
  if ( (dword_4D8EC0 & 1) == 0 )
  {
    dword_4D8EC0 |= 1u;
    LOBYTE(v9) = 5;
    sub_43FD00();
    atexit(sub_472560);
    LOBYTE(v9) = 4;
  }
  v0 = 1.0;
  v1 = 1.0;
  v2 = 1.0;
  v3 = 1.0;
  sub_441E00((int *)&v0, (int)&dword_4D8E20, v6);
  v9 = -1;
  if ( v8 >= 8 )
    operator delete(v6[0]);
  LOWORD(v6[0]) = 0;
  v8 = 7;
  v7 = 0;
  sub_4032D0(L"Use up and down to cycle through previous commands.", (int)v6, 0x33u);
  v9 = 6;
  if ( (dword_4D8EC0 & 1) == 0 )
  {
    dword_4D8EC0 |= 1u;
    LOBYTE(v9) = 7;
    sub_43FD00();
    atexit(sub_472560);
    LOBYTE(v9) = 6;
  }
  v0 = 1.0;
  v1 = 1.0;
  v2 = 1.0;
  v3 = 1.0;
  sub_441E00((int *)&v0, (int)&dword_4D8E20, v6);
  v9 = -1;
  if ( v8 >= 8 )
    operator delete(v6[0]);
  LOWORD(v6[0]) = 0;
  v8 = 7;
  v7 = 0;
  sub_4032D0(L"To search for a command just type the sub string and press tab.", (int)v6, 0x3Fu);
  v9 = 8;
  if ( (dword_4D8EC0 & 1) == 0 )
  {
    dword_4D8EC0 |= 1u;
    LOBYTE(v9) = 9;
    sub_43FD00();
    atexit(sub_472560);
    LOBYTE(v9) = 8;
  }
  v0 = 1.0;
  v1 = 1.0;
  v2 = 1.0;
  v3 = 1.0;
  sub_441E00((int *)&v0, (int)&dword_4D8E20, v6);
  v9 = -1;
  if ( v8 >= 8 )
    operator delete(v6[0]);
  LOWORD(v6[0]) = 0;
  v8 = 7;
  v7 = 0;
  sub_4032D0(L"When searching you can press up and down to cycle through matches.", (int)v6, 0x42u);
  v9 = 10;
  if ( (dword_4D8EC0 & 1) == 0 )
  {
    dword_4D8EC0 |= 1u;
    LOBYTE(v9) = 11;
    sub_43FD00();
    atexit(sub_472560);
    LOBYTE(v9) = 10;
  }
  v0 = 1.0;
  v1 = 1.0;
  v2 = 1.0;
  v3 = 1.0;
  sub_441E00((int *)&v0, (int)&dword_4D8E20, v6);
  v9 = -1;
  if ( v8 >= 8 )
    operator delete(v6[0]);
  LOWORD(v6[0]) = 0;
  v8 = 7;
  v7 = 0;
  sub_4032D0(L"You can also just press tab on a blank line and cycle through all commands.", (int)v6, 0x4Bu);
  v9 = 12;
  if ( (dword_4D8EC0 & 1) == 0 )
  {
    dword_4D8EC0 |= 1u;
    LOBYTE(v9) = 13;
    sub_43FD00();
    atexit(sub_472560);
    LOBYTE(v9) = 12;
  }
  v0 = 1.0;
  v1 = 1.0;
  v2 = 1.0;
  v3 = 1.0;
  sub_441E00((int *)&v0, (int)&dword_4D8E20, v6);
  v9 = -1;
  if ( v8 >= 8 )
    operator delete(v6[0]);
  LOWORD(v4[0]) = 0;
  v5 = 7;
  v4[4] = 0;
  sub_4032D0(word_4B765C, (int)v4, 0);
  v9 = 14;
  if ( (dword_4D8EC0 & 1) == 0 )
  {
    dword_4D8EC0 |= 1u;
    LOBYTE(v9) = 15;
    sub_43FD00();
    atexit(sub_472560);
    LOBYTE(v9) = 14;
  }
  v0 = 1.0;
  v1 = 1.0;
  v2 = 1.0;
  v3 = 1.0;
  sub_441E00((int *)&v0, (int)&dword_4D8E20, v4);
  if ( v5 >= 8 )
    operator delete(v4[0]);
}
