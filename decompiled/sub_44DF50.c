int __thiscall sub_44DF50(float *this)
{
  void *v2; // edi
  double v3; // st7
  int result; // eax
  float v5[3]; // [esp+2Ch] [ebp-94h] BYREF
  _BYTE v6[64]; // [esp+38h] [ebp-88h] BYREF
  _BYTE v7[68]; // [esp+78h] [ebp-48h] BYREF

  v2 = this + 10;
  sub_4015F0(v5, this + 10);
  D3DXMatrixRotationYawPitchRoll(v6, *(this + 53), *(this + 54), *(this + 55));
  v3 = v5[0];
  qmemcpy(v2, v6, 0x40u);
  *(this + 22) = v3;
  *(this + 23) = v5[1];
  *(this + 24) = v5[2];
  result = D3DXMatrixPerspectiveFovLH(v7, *(this + 49), *(this + 50), *(this + 51), *(this + 52));
  qmemcpy(this + 72, v7, 0x40u);
  return result;
}
