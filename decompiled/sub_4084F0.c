double __usercall sub_4084F0@<st0>(float *a1@<esi>)
{
  double result; // st7
  float v2; // [esp+0h] [ebp-10h]
  float v3; // [esp+0h] [ebp-10h]
  float v4; // [esp+0h] [ebp-10h]

  v2 = a1[1] * a1[1] + *a1 * *a1 + a1[2] * a1[2];
  v3 = sqrt(v2);
  result = v3;
  if ( v3 <= 1.000000013351432e-10 )
  {
    *a1 = 0.0;
    a1[1] = 0.0;
    a1[2] = 1.0;
    return 0.0;
  }
  else
  {
    v4 = 1.0 / result;
    *a1 = *a1 * v4;
    a1[1] = v4 * a1[1];
    a1[2] = v4 * a1[2];
  }
  return result;
}
