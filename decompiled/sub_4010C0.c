double __usercall sub_4010C0@<st0>(float *a1@<eax>, float *a2@<ecx>)
{
  double v2; // st7
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+0h] [ebp-4h]

  v4 = a1[1] * a2[1] + *a1 * *a2 + a1[2] * a2[2];
  v2 = 1.0;
  if ( v4 > 1.0 || (v2 = -1.0, v4 < -1.0) )
  {
    v5 = v2;
    return (float)acos(v5);
  }
  else
  {
    return (float)acos(v4);
  }
}
