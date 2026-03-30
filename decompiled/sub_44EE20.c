double __usercall sub_44EE20@<st0>(float *a1@<eax>, float *a2@<edi>)
{
  double v3; // st7
  double v4; // st5
  double v5; // st6
  double v6; // st4
  double v7; // st5
  double v8; // st3
  double v9; // st4
  double v10; // st4
  double v11; // st7
  double v12; // st6
  double v13; // st5
  double v14; // st3
  double v15; // st6
  double v16; // rtt
  double v17; // st5
  double v18; // st4
  double v19; // st5
  float *v20; // esi
  float *v21; // eax
  float *v22; // eax
  float v24; // [esp+Ch] [ebp-4Ch]
  float v25; // [esp+Ch] [ebp-4Ch]
  float v26; // [esp+10h] [ebp-48h]
  float v27; // [esp+14h] [ebp-44h]
  float v28; // [esp+14h] [ebp-44h]
  float v29; // [esp+18h] [ebp-40h]
  float v30; // [esp+18h] [ebp-40h]
  float v31; // [esp+18h] [ebp-40h]
  double v32[2]; // [esp+1Ch] [ebp-3Ch] BYREF
  float v33; // [esp+30h] [ebp-28h] BYREF
  float v34; // [esp+34h] [ebp-24h]
  float v35; // [esp+38h] [ebp-20h]
  float v36; // [esp+3Ch] [ebp-1Ch] BYREF
  float v37; // [esp+40h] [ebp-18h]
  float v38; // [esp+44h] [ebp-14h]
  float v39; // [esp+48h] [ebp-10h] BYREF
  float v40; // [esp+4Ch] [ebp-Ch]
  float v41; // [esp+50h] [ebp-8h]

  sub_401430(&v36, a2, a2 + 3);
  sub_401430(&v33, a1, a1 + 3);
  sub_401430(&v39, a1, a2);
  v24 = v38 * v38 + v36 * v36 + v37 * v37;
  v29 = v33 * v36 + v34 * v37 + v35 * v38;
  v32[0] = v35;
  v27 = v33 * v33 + v34 * v34 + v35 * v35;
  *(float *)v32 = v38 * v41 + v36 * v39 + v37 * v40;
  v26 = v41 * v35 + v40 * v34 + v39 * v33;
  v3 = v29;
  v4 = v27;
  v5 = v24;
  v30 = v27 * v24 - v29 * v29;
  v28 = v30;
  if ( v30 >= 1.000000013351432e-10 )
  {
    v8 = v26;
    v25 = v26 * v3 - *(float *)v32 * v4;
    v26 = v26 * v5 - *(float *)v32 * v3;
    if ( v25 >= 0.0 )
    {
      if ( v25 <= (double)v30 )
      {
        v7 = 0.0;
      }
      else
      {
        v25 = v30;
        v26 = v8 + v3;
        v10 = v4;
        v7 = 0.0;
        v30 = v10;
      }
    }
    else
    {
      v25 = 0.0;
      v26 = v8;
      v9 = v4;
      v7 = 0.0;
      v30 = v9;
    }
  }
  else
  {
    v25 = 0.0;
    v28 = 1.0;
    v6 = v4;
    v7 = 0.0;
    v30 = v6;
  }
  if ( v26 < v7 )
  {
    v11 = 0.0;
    v26 = v7;
    *(float *)v32 = -*(float *)v32;
    if ( *(float *)v32 >= v7 )
    {
      if ( *(float *)v32 <= v5 )
      {
        v25 = *(float *)v32;
        v13 = v5;
        v12 = v30;
        v28 = v13;
      }
      else
      {
        v12 = v30;
        v25 = v28;
      }
    }
    else
    {
      v12 = v30;
      v25 = v7;
    }
    goto LABEL_19;
  }
  if ( v30 < (double)v26 )
  {
    v26 = v30;
    v14 = v3 - *(float *)v32;
    if ( v14 >= 0.0 )
    {
      if ( v14 <= v5 )
      {
        v25 = v14;
        v19 = v5;
        v15 = 0.0;
        v28 = v19;
        goto LABEL_18;
      }
      v15 = 0.0;
      v7 = v28;
    }
    else
    {
      v15 = 0.0;
    }
    v25 = v7;
LABEL_18:
    v16 = v15;
    v12 = v30;
    v11 = v16;
    goto LABEL_19;
  }
  v11 = 0.0;
  v12 = v30;
LABEL_19:
  *(float *)v32 = fabs(v25);
  if ( *(float *)v32 >= 1.000000013351432e-10 )
  {
    v18 = v25 / v28;
    v17 = 1.000000013351432e-10;
  }
  else
  {
    v17 = 1.000000013351432e-10;
    v18 = v11;
  }
  *(float *)v32 = fabs(v26);
  if ( *(float *)v32 >= v17 )
    v11 = v26 / v12;
  *(float *)v32 = v11;
  v20 = sub_401500((float *)v32, &v33, *(float *)v32);
  v31 = v18;
  v21 = sub_401500(&v33, &v36, v31);
  v22 = sub_4013F0(&v36, v21, &v39);
  sub_401430(&v39, v20, v22);
  *(float *)v32 = v40 * v40 + v39 * v39 + v41 * v41;
  return *(float *)v32;
}
