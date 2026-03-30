double __cdecl _fload(double a1)
{
  double v2; // [esp+6h] [ebp-Ah]

  if ( (HIWORD(a1) & 0x7FF0) != 0x7FF0 )
    return a1;
  HIDWORD(v2) = *(_QWORD *)&a1 >> 21;
  LODWORD(v2) = LODWORD(a1);
  return v2;
}
