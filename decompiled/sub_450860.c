double __userpurge sub_450860@<st0>(float *a1@<ecx>, float *a2@<edi>, float *a3@<esi>, float *a4, float a5)
{
  double v5; // st7
  float *v6; // eax
  float *v8; // eax
  float *v9; // eax
  float v10; // [esp+4h] [ebp-1Ch]
  float v11[3]; // [esp+8h] [ebp-18h] BYREF
  float v12[3]; // [esp+14h] [ebp-Ch] BYREF
  float v15; // [esp+28h] [ebp+8h]

  v10 = (a3[1] - a2[1]) * a1[1] + (*a3 - *a2) * *a1 + (a3[2] - a2[2]) * a1[2];
  v5 = v10;
  if ( a5 > (double)v10 )
  {
    if ( v5 > 0.0 )
    {
      v15 = v5 / a5;
      v9 = sub_401470(v12, a1, v15);
      sub_4013F0(v11, v9, a2);
      v8 = sub_401430(v12, v11, a3);
    }
    else
    {
      v8 = sub_401430(v11, a2, a3);
    }
    return (float)(v8[1] * v8[1] + *v8 * *v8 + v8[2] * v8[2]);
  }
  else
  {
    v6 = sub_401430(v11, a4, a3);
    return (float)(v6[1] * v6[1] + *v6 * *v6 + v6[2] * v6[2]);
  }
}
