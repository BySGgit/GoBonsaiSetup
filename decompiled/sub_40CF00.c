float *__usercall sub_40CF00@<eax>(float *a1@<esi>)
{
  float v2; // [esp+0h] [ebp-10h]
  float v3; // [esp+0h] [ebp-10h]
  float v4; // [esp+0h] [ebp-10h]

  v2 = a1[1] * a1[1] + *a1 * *a1 + a1[2] * a1[2];
  v3 = sqrt(v2);
  if ( v3 <= 1.000000013351432e-10 )
  {
    *a1 = 0.0;
    a1[1] = 0.0;
    a1[2] = 1.0;
    return a1;
  }
  else
  {
    v4 = 1.0 / v3;
    *a1 = *a1 * v4;
    a1[1] = v4 * a1[1];
    a1[2] = v4 * a1[2];
    return a1;
  }
}
