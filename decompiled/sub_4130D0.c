char __stdcall sub_4130D0(int a1)
{
  double v1; // st7
  double v2; // st6
  double v3; // st6
  bool v4; // c0
  double v5; // st7
  char v7; // [esp+1Bh] [ebp-31h]
  float v8; // [esp+1Ch] [ebp-30h]
  void *v9[4]; // [esp+20h] [ebp-2Ch] BYREF
  int v10; // [esp+30h] [ebp-1Ch]
  unsigned int v11; // [esp+34h] [ebp-18h]
  int v12; // [esp+48h] [ebp-4h]

  v7 = 0;
  v8 = flt_4D526C * 0.03333333507180214;
  v1 = 0.0;
  if ( dword_4D8C14 > dword_4D52DC )
    v8 = 0.0;
  flt_4D7EF8 = flt_4D7EF8 + v8;
  v2 = flt_4D7EF8;
  if ( flt_4D7EF8 > 0.0 )
  {
    v7 = 1;
    do
    {
      flt_4D7EF8 = v2 - 1.0;
      sub_40DC90();
      (*(void (__thiscall **)(int))(*(_DWORD *)(a1 + 32) + 16))(a1 + 32);
      v1 = 0.0;
      v2 = flt_4D7EF8;
      if ( flt_4D7EF8 >= 0.0 )
      {
        if ( !sub_406AC0() )
        {
          v8 = 1.0;
          v1 = 0.0;
          flt_4D7EF8 = 0.0;
          break;
        }
        v1 = 0.0;
        v2 = flt_4D7EF8;
      }
    }
    while ( v2 > v1 );
  }
  if ( byte_4CA64A )
  {
    if ( (dword_4DBE40 & 1) == 0 )
    {
      dword_4DBE40 |= 1u;
      v12 = 0;
      v11 = 7;
      v10 = 0;
      LOWORD(v9[0]) = 0;
      sub_4032D0(L"lightUpdatesPerDay", (int)v9, 0x12u);
      LOBYTE(v12) = 1;
      sub_408600(v9, (int)&unk_4DBE1C, (int)&flt_4D6334);
      if ( v11 >= 8 )
        operator delete(v9[0]);
      v11 = 7;
      v10 = 0;
      LOWORD(v9[0]) = 0;
      atexit(sub_4723F0);
      v12 = -1;
      v1 = 0.0;
    }
    flt_4D8D18 = flt_4D6334 * v8 + flt_4D8D18;
    v3 = flt_4D8D18;
    if ( flt_4D8D18 < 1.0 )
    {
      flt_4D8D18 = v3 + 1.0;
      v3 = flt_4D8D18;
    }
    v4 = v3 < v1;
    v5 = v3;
    if ( !v4 )
    {
      do
      {
        flt_4D8D18 = v5 - 1.0;
        sub_40E0A0();
        v5 = flt_4D8D18;
      }
      while ( flt_4D8D18 >= 0.0 );
    }
  }
  sub_44E6C0(COERCE_INT(0.033333335));
  sub_407BB0();
  sub_412D20();
  (*(void (__thiscall **)(int))(*(_DWORD *)(a1 + 32) + 12))(a1 + 32);
  sub_412A50(a1);
  (*(void (__thiscall **)(int))(*(_DWORD *)(a1 + 32) + 16))(a1 + 32);
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(dword_4D7EE8 + 240) + 48))(*(_DWORD *)(dword_4D7EE8 + 240));
  sub_450F00();
  sub_402040();
  byte_4D8C9D = 0;
  byte_4D8CA1 = 0;
  byte_4D8CA6 = 0;
  return v7;
}
