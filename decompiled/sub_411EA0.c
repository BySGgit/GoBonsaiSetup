float *__thiscall sub_411EA0(float *this, int a2)
{
  double v3; // st7
  float v5; // [esp+0h] [ebp-ACh]
  int v6[21]; // [esp+54h] [ebp-58h] BYREF

  *(float *)v6 = flt_4CA5E8;
  *(float *)&v6[16] = flt_4CA5E8;
  *(float *)&v6[4] = 0.40000001;
  *(float *)&v6[5] = 0.30000001;
  *(float *)&v6[6] = 0.69999999;
  *(float *)&v6[7] = 1.0;
  *(float *)&v6[8] = 0.60000002;
  *(float *)&v6[9] = 0.69999999;
  *(float *)&v6[10] = 0.94999999;
  *(float *)&v6[11] = 1.0;
  *(float *)&v6[12] = 0.30000001;
  *(float *)&v6[13] = 0.2;
  v3 = *(float *)(a2 + 2608);
  *(float *)&v6[1] = flt_4CA5E8;
  v5 = v3;
  *(float *)&v6[17] = flt_4CA5E8;
  *(float *)&v6[14] = 0.60000002;
  *(float *)&v6[2] = 0.34999999;
  *(float *)&v6[3] = 1.0;
  *(float *)&v6[15] = 1.0;
  *(float *)&v6[18] = 0.34999999;
  *(float *)&v6[19] = 1.0;
  sub_40FDE0(5, this, (int)v6, v5);
  return this;
}
