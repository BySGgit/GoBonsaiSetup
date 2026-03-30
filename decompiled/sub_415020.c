double __stdcall sub_415020(int a1)
{
  double result; // st7
  float v2; // [esp+8h] [ebp-30h]
  void *v3[4]; // [esp+Ch] [ebp-2Ch] BYREF
  int v4; // [esp+1Ch] [ebp-1Ch]
  unsigned int v5; // [esp+20h] [ebp-18h]
  int v6; // [esp+34h] [ebp-4h]

  if ( (dword_4DBBF0 & 1) == 0 )
  {
    dword_4DBBF0 |= 1u;
    v6 = 0;
    LOWORD(v3[0]) = 0;
    v5 = 7;
    v4 = 0;
    sub_4032D0(L"lightAmbientCoeff", (int)v3, 0x11u);
    LOBYTE(v6) = 1;
    sub_408600(v3, (int)&unk_4DBBCC, (int)&flt_4D6360);
    if ( v5 >= 8 )
      operator delete(v3[0]);
    atexit(sub_472450);
    v6 = -1;
  }
  if ( (dword_4DBBF0 & 2) == 0 )
  {
    dword_4DBBF0 |= 2u;
    v6 = 2;
    v5 = 7;
    v4 = 0;
    LOWORD(v3[0]) = 0;
    sub_4032D0(L"lightAmbientMin", (int)v3, 0xFu);
    LOBYTE(v6) = 3;
    sub_408600(v3, (int)&unk_4DBBA8, (int)&flt_4D6364);
    if ( v5 >= 8 )
      operator delete(v3[0]);
    atexit(sub_472440);
  }
  v2 = *(float *)(a1 + 232) * flt_4D6360 + flt_4D6364;
  if ( v2 < 0.0 )
    return (float)0.0;
  result = v2;
  if ( v2 > 1.0 )
    return (float)1.0;
  return result;
}
