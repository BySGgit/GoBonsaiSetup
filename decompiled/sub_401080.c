double __usercall sub_401080@<st0>(float *a1@<eax>)
{
  float v2; // [esp+4h] [ebp-4h]

  v2 = a1[1] * a1[1] + *a1 * *a1 + a1[2] * a1[2];
  return (float)sqrt(v2);
}
