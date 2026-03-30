void sub_442410()
{
  char *i; // esi
  _DWORD *v1; // ecx
  float v2; // [esp+14h] [ebp-58h] BYREF
  float v3; // [esp+18h] [ebp-54h]
  float v4; // [esp+1Ch] [ebp-50h]
  float v5; // [esp+20h] [ebp-4Ch]
  void *v6[5]; // [esp+24h] [ebp-48h] BYREF
  unsigned int v7; // [esp+38h] [ebp-34h]
  void *v8[5]; // [esp+40h] [ebp-2Ch] BYREF
  unsigned int v9; // [esp+54h] [ebp-18h]
  int v10; // [esp+68h] [ebp-4h]

  LOWORD(v6[0]) = 0;
  v7 = 7;
  v6[4] = 0;
  sub_4032D0(word_4B765C, (int)v6, 0);
  v10 = 0;
  if ( (dword_4D8EC0 & 1) == 0 )
  {
    dword_4D8EC0 |= 1u;
    LOBYTE(v10) = 1;
    sub_43FD00();
    atexit(sub_472560);
    LOBYTE(v10) = 0;
  }
  v2 = 1.0;
  v3 = 1.0;
  v4 = 1.0;
  v5 = 1.0;
  sub_441E00((int *)&v2, (int)&dword_4D8E20, v6);
  v10 = -1;
  if ( v7 >= 8 )
    operator delete(v6[0]);
  if ( (dword_4D8EC0 & 1) == 0 )
  {
    dword_4D8EC0 |= 1u;
    v10 = 2;
    sub_43FD00();
    atexit(sub_472560);
    v10 = -1;
  }
  for ( i = *(char **)dword_4D8E20; ; i = *(char **)i )
  {
    if ( (dword_4D8EC0 & 1) == 0 )
    {
      dword_4D8EC0 |= 1u;
      v10 = 3;
      sub_43FD00();
      atexit(sub_472560);
      v10 = -1;
    }
    if ( i == dword_4D8E20 )
      break;
    if ( (dword_4D8EC0 & 1) == 0 )
    {
      dword_4D8EC0 |= 1u;
      v10 = 4;
      sub_43FD00();
      atexit(sub_472560);
      v10 = -1;
    }
    v1 = (_DWORD *)*((_DWORD *)i + 2);
    v2 = 1.0;
    v3 = 1.0;
    v4 = 1.0;
    v5 = 1.0;
    sub_441E00((int *)&v2, (int)&dword_4D8E20, v1);
  }
  v9 = 7;
  v8[4] = 0;
  LOWORD(v8[0]) = 0;
  sub_4032D0(word_4B765C, (int)v8, 0);
  v10 = 5;
  if ( (dword_4D8EC0 & 1) == 0 )
  {
    dword_4D8EC0 |= 1u;
    LOBYTE(v10) = 6;
    sub_43FD00();
    atexit(sub_472560);
    LOBYTE(v10) = 5;
  }
  v2 = 1.0;
  v3 = 1.0;
  v4 = 1.0;
  v5 = 1.0;
  sub_441E00((int *)&v2, (int)&dword_4D8E20, v8);
  if ( v9 >= 8 )
    operator delete(v8[0]);
}
