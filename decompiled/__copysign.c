double __cdecl _copysign(double Number, double Sign)
{
  double v3; // [esp+0h] [ebp-8h]

  LODWORD(v3) = LODWORD(Number);
  HIDWORD(v3) = HIDWORD(Sign) ^ (HIDWORD(Number) ^ HIDWORD(Sign)) & 0x7FFFFFFF;
  return v3;
}
