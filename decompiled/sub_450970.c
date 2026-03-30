double __userpurge sub_450970@<st0>(
        float *a1@<eax>,
        float *a2@<ecx>,
        float *a3@<edi>,
        float *a4@<esi>,
        float *a5,
        float a6)
{
  double v6; // st6
  float *v7; // eax
  float *v9; // eax
  float *v10; // eax
  float v11; // [esp+4h] [ebp-1Ch]
  float v12[3]; // [esp+8h] [ebp-18h] BYREF
  float v13[3]; // [esp+14h] [ebp-Ch] BYREF
  float v14; // [esp+28h] [ebp+8h]

  v11 = (a4[1] - a3[1]) * a2[1] + (*a4 - *a3) * *a2 + (a4[2] - a3[2]) * a2[2];
  v6 = a6;
  v14 = v11 / a6;
  *a1 = v14;
  if ( v6 > v11 )
  {
    if ( v11 > 0.0 )
    {
      v10 = sub_401470(v13, a2, v14);
      sub_4013F0(v12, v10, a3);
      v9 = sub_401430(v13, v12, a4);
    }
    else
    {
      v9 = sub_401430(v12, a3, a4);
    }
    return (float)(v9[1] * v9[1] + *v9 * *v9 + v9[2] * v9[2]);
  }
  else
  {
    v7 = sub_401430(v12, a5, a4);
    return (float)(v7[1] * v7[1] + *v7 * *v7 + v7[2] * v7[2]);
  }
}
