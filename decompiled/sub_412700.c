void __stdcall sub_412700(float a1)
{
  void *v1; // edi
  _DWORD *EngineInstance; // esi
  _DWORD *v3; // esi
  double v5; // st7
  int v6; // [esp+14h] [ebp-40h]
  char v7; // [esp+14h] [ebp-40h]
  float v8; // [esp+18h] [ebp-3Ch]
  float v9; // [esp+18h] [ebp-3Ch]
  void *v10[4]; // [esp+24h] [ebp-30h] BYREF
  int v11; // [esp+34h] [ebp-20h]
  unsigned int v12; // [esp+38h] [ebp-1Ch]
  int v13; // [esp+50h] [ebp-4h]
  float v14; // [esp+58h] [ebp+4h]

  v1 = dword_4D82D0;
  *((float *)dword_4D82D0 + 66) = a1 + *((float *)dword_4D82D0 + 66);
  dword_4D7F94 += (__int64)(1000.0 * a1);
  if ( a1 > 0.06666667 )
    a1 = 0.06666667;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = (_DWORD *)EngineInstance[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v3 )
  {
    if ( !(*v3 ? v3[20] == 0 : v3[18] == 0x80000000) )
    {
      v14 = flt_4D8D00 + a1;
      v8 = (float)sub_427F30();
      v5 = v8;
      v6 = (int)(v8 * v14 + 1.0);
      if ( v6 <= 0 )
        v6 = 1;
      v9 = v14;
      a1 = (double)v6 / v5;
      flt_4D8D00 = v9 - a1;
    }
  }
  v7 = 0;
  if ( (dword_4DBEE8 & 1) == 0 )
  {
    dword_4DBEE8 |= 1u;
    flt_4DBEE4 = 0.033333335;
  }
  flt_4D8D04 = flt_4D8D04 + a1;
  if ( flt_4D8D04 > 0.0 )
  {
    flt_4D8D04 = flt_4D8D04 - flt_4DBEE4;
    sub_4130D0((int)v1);
    v7 = 1;
    if ( flt_4D8D04 > 0.0 )
      flt_4D8D04 = 0.0;
  }
  if ( (dword_4DBEE8 & 2) == 0 )
  {
    dword_4DBEE8 |= 2u;
    v13 = 0;
    v12 = 7;
    v11 = 0;
    LOWORD(v10[0]) = 0;
    sub_4032D0(L"updateTreeVerts", (int)v10, 0xFu);
    LOBYTE(v13) = 1;
    sub_4038B0(v10, (int)&unk_4DBEC0, (int)&byte_4D6329);
    if ( v12 >= 8 )
      operator delete(v10[0]);
    atexit(sub_4723A0);
    v13 = -1;
  }
  if ( (dword_4DBEE8 & 4) == 0 )
  {
    dword_4DBEE8 |= 4u;
    v13 = 2;
    LOWORD(v10[0]) = 0;
    v12 = 7;
    v11 = 0;
    sub_4032D0(L"updateVertInterval", (int)v10, 0x12u);
    LOBYTE(v13) = 3;
    sub_4039A0(v10, (int)&unk_4DBE9C, (int)&dword_4D8D08);
    if ( v12 >= 8 )
      operator delete(v10[0]);
    v12 = 7;
    v11 = 0;
    LOWORD(v10[0]) = 0;
    atexit(sub_472390);
    v13 = -1;
  }
  if ( v7 && byte_4D6329 )
    ++dword_4D8D0C;
  if ( dword_4D8D0C > dword_4D8D08 )
  {
    dword_4D8D0C = 0;
    sub_40CD30();
    sub_4093B0();
  }
  sub_404C10();
  if ( (dword_4D8EC0 & 1) == 0 )
  {
    dword_4D8EC0 |= 1u;
    v13 = 4;
    sub_43FD00();
    atexit(sub_472560);
    v13 = -1;
  }
  sub_4400E0((int)&dword_4D8E20, a1);
}
