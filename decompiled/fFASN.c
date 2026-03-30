double __usercall fFASN@<st0>(long double a1@<st1>, long double a2@<st0>)
{
  char v2; // cl
  double result; // st7
  char v4; // ch

  AugmentSinCos();
  result = atan2(a2, a1);
  if ( v4 )
    result = 3.141592653589793238 - result;
  if ( v2 )
    return -result;
  return result;
}
