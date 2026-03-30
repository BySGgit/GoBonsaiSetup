int __thiscall sub_402AA0(float *this)
{
  void *v2; // edi
  double v3; // st7
  int result; // eax
  float v5[3]; // [esp+48h] [ebp-114h] BYREF
  _BYTE v6[64]; // [esp+54h] [ebp-108h] BYREF
  _BYTE v7[64]; // [esp+94h] [ebp-C8h] BYREF
  _BYTE v8[64]; // [esp+D4h] [ebp-88h] BYREF
  _BYTE v9[68]; // [esp+114h] [ebp-48h] BYREF

  v2 = this + 10;
  sub_4015F0(v5, this + 10);
  D3DXMatrixRotationYawPitchRoll(v8, *(this + 53), *(this + 54), *(this + 55));
  D3DXMatrixRotationYawPitchRoll(v6, *(this + 98), *(this + 99), *(this + 100));
  D3DXMatrixMultiply(v7, v6, v8);
  v3 = v5[0];
  qmemcpy(v2, v7, 0x40u);
  *(this + 22) = v3;
  *(this + 23) = v5[1];
  *(this + 24) = v5[2];
  result = D3DXMatrixPerspectiveFovLH(v9, *(this + 49), *(this + 50), *(this + 51), *(this + 52));
  qmemcpy(this + 72, v9, 0x40u);
  return result;
}
