void __stdcall sub_402600(float *a1)
{
  double v1; // st7
  int v2; // esi
  float *v3; // eax
  double v4; // st7
  float v5; // [esp+14h] [ebp-40h]
  float v6; // [esp+14h] [ebp-40h]
  float v7; // [esp+14h] [ebp-40h]
  float v8; // [esp+18h] [ebp-3Ch]
  float v9; // [esp+18h] [ebp-3Ch]
  float v10; // [esp+18h] [ebp-3Ch]
  float v11; // [esp+18h] [ebp-3Ch]
  float v12; // [esp+1Ch] [ebp-38h] BYREF
  float v13; // [esp+20h] [ebp-34h]
  float v14[3]; // [esp+34h] [ebp-20h] BYREF
  float v15[4]; // [esp+40h] [ebp-14h] BYREF

  v5 = a1[94];
  if ( v5 >= 10.0 )
    v1 = v5;
  else
    v1 = (float)10.0;
  if ( 0.0 != flt_4D8CA8 )
  {
    a1[95] = a1[95] - flt_4D8CA8 * 0.03333333507180214 * 4.0 * v1;
    flt_4D8CA8 = 0.0;
  }
  v6 = v1 + 5.0;
  v8 = v1 + v1 + 40.0;
  if ( v6 <= (double)a1[95] )
  {
    if ( v8 < (double)a1[95] )
      a1[95] = v8;
  }
  else
  {
    a1[95] = v6;
  }
  v2 = dword_4D7EE8;
  sub_401B10(dword_4D7EE8, &v12);
  v13 = v13 - *(float *)(*(_DWORD *)(v2 + 236) + 200);
  sub_401690(&v12, (int)v15);
  sub_401430(v14, a1 + 91, v15);
  v3 = sub_401470(&v12, v14, 0.02);
  a1[91] = *v3 + a1[91];
  a1[92] = v3[1] + a1[92];
  a1[93] = v3[2] + a1[93];
  v9 = v15[3] - a1[94];
  a1[94] = v9 * 0.05999999865889549 + a1[94];
  if ( a1[95] < (double)v6 )
    a1[95] = v6;
  v10 = a1[95] - a1[96];
  a1[96] = v10 * 0.1000000014901161 + a1[96];
  if ( (_BYTE)word_4D8CA3 )
  {
    v7 = flt_4D8CC0 * 0.03500000014901161;
    v11 = 0.03500000014901161 * -flt_4D8CBC;
    a1[88] = a1[88] - v11 * 0.03333333507180214;
    a1[89] = 0.03333333507180214 * v7 + a1[89];
    sub_401000(a1 + 88);
    v4 = -0.52359879;
    if ( a1[89] >= -0.52359879 )
    {
      if ( a1[89] <= 1.570796370506287 )
        return;
      v4 = flt_4D6388;
    }
    a1[89] = v4;
  }
}
