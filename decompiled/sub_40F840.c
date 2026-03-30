int __thiscall sub_40F840(float *this)
{
  int result; // eax
  _BYTE v3[68]; // [esp+14h] [ebp-48h] BYREF

  result = D3DXMatrixRotationYawPitchRoll(v3, *(this + 56), *(this + 57), *(this + 58));
  qmemcpy(this + 10, v3, 0x40u);
  return result;
}
