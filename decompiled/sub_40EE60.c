double __usercall sub_40EE60@<st0>(int a1@<eax>)
{
  float v2; // [esp+0h] [ebp-8h]
  float v3; // [esp+0h] [ebp-8h]
  float v4; // [esp+0h] [ebp-8h]
  float v5; // [esp+4h] [ebp-4h]

  v2 = *(float *)(a1 + 216) / 365.0;
  v3 = v2 - (double)(int)v2;
  v4 = v3 * 12.0;
  v5 = v4 - (double)(int)v4;
  return (float)(flt_4B786C[v4] + (flt_4B786C[((int)v4 + 1) % 12] - flt_4B786C[v4]) * v5);
}
