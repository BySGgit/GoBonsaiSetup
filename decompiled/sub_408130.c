float *__usercall sub_408130@<eax>(int a1@<eax>, float *a2@<edx>)
{
  double v2; // st7
  double v3; // st7
  float v5; // [esp+8h] [ebp-48h]
  float v6; // [esp+Ch] [ebp-44h]
  float v7[16]; // [esp+10h] [ebp-40h] BYREF

  v2 = *(float *)(a1 + 24) * 2.0 / (double)dword_4CA628;
  qmemcpy(v7, (const void *)(dword_4D7EEC + 288), sizeof(v7));
  v5 = (v2 - 1.0) / v7[0];
  v6 = -((2.0 * *(float *)(a1 + 28) / (double)dword_4CA62C - 1.0) / v7[5]);
  *a2 = v5;
  a2[1] = v6;
  a2[2] = 1.0;
  if ( v5 >= -0.5 )
  {
    v3 = flt_4D63B0;
    if ( flt_4D63B0 < (double)v5 )
      *a2 = flt_4D63B0;
  }
  else
  {
    v3 = flt_4D63B0;
    *a2 = -0.5;
  }
  if ( a2[1] < -0.5 )
  {
    v3 = -0.5;
LABEL_7:
    a2[1] = v3;
    return a2;
  }
  if ( v3 < a2[1] )
    goto LABEL_7;
  return a2;
}
