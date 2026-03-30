int __thiscall sub_414BB0(float *this)
{
  float v3; // [esp+14h] [ebp-34h]
  float v4; // [esp+14h] [ebp-34h]
  float v5; // [esp+14h] [ebp-34h]
  void *v6[5]; // [esp+18h] [ebp-30h] BYREF
  unsigned int v7; // [esp+2Ch] [ebp-1Ch]
  int v8; // [esp+44h] [ebp-4h]

  if ( (dword_4DBC18 & 1) == 0 )
  {
    dword_4DBC18 |= 1u;
    v8 = 0;
    v6[4] = 0;
    LOWORD(v6[0]) = 0;
    v7 = 7;
    sub_4032D0(L"resistanceRadiusBias", (int)v6, 0x14u);
    LOBYTE(v8) = 1;
    sub_408600(v6, (int)&unk_4DBBF4, (int)&flt_4D635C);
    if ( v7 >= 8 )
      operator delete(v6[0]);
    atexit(sub_472430);
  }
  v3 = *(this + 111) + flt_4D635C;
  v4 = pow(v3, *(float *)flt_4D8604);
  v5 = v4 * *(float *)flt_4D8608;
  if ( v5 > 1.0 )
    v5 = 1.0;
  return D3DXQuaternionSlerp(this + 80, this + 80, this + 76, LODWORD(v5));
}
