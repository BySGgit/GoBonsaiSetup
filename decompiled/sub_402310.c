float *__usercall sub_402310@<eax>(int a1@<edi>)
{
  double v1; // st7
  double v2; // st6
  float *v3; // eax
  float *v4; // eax
  float *v5; // eax
  double v6; // st7
  int v7; // ecx
  int v8; // edx
  double v9; // st6
  double v10; // st7
  float *v11; // eax
  float *v12; // eax
  float *v13; // eax
  float *v14; // eax
  float *v15; // ebx
  float *v16; // eax
  float *v17; // eax
  float *v18; // eax
  float *v19; // ebp
  float *v20; // eax
  float *v21; // eax
  float *result; // eax
  float v23; // [esp+0h] [ebp-A0h]
  int v24; // [esp+0h] [ebp-A0h]
  float v25; // [esp+8h] [ebp-98h]
  float v26; // [esp+8h] [ebp-98h]
  float v27; // [esp+14h] [ebp-8Ch]
  float v28; // [esp+18h] [ebp-88h] BYREF
  int v29; // [esp+1Ch] [ebp-84h]
  int v30; // [esp+20h] [ebp-80h]
  float v31; // [esp+24h] [ebp-7Ch]
  float v32[3]; // [esp+28h] [ebp-78h] BYREF
  float v33[3]; // [esp+34h] [ebp-6Ch] BYREF
  float v34[3]; // [esp+40h] [ebp-60h] BYREF
  float v35[3]; // [esp+4Ch] [ebp-54h] BYREF
  float v36[3]; // [esp+58h] [ebp-48h] BYREF
  float v37[3]; // [esp+64h] [ebp-3Ch] BYREF
  float v38[3]; // [esp+70h] [ebp-30h] BYREF
  float v39[3]; // [esp+7Ch] [ebp-24h] BYREF
  float v40[3]; // [esp+88h] [ebp-18h] BYREF
  float v41[3]; // [esp+94h] [ebp-Ch] BYREF

  if ( 0.0 == flt_4D8CA8 )
  {
    v1 = 0.0;
  }
  else
  {
    v1 = 0.0;
    *(float *)(a1 + 416) = *(float *)(a1 + 416) - flt_4D8CA8 * 0.03333333507180214;
    if ( *(float *)(a1 + 416) >= 0.05235987901687622 )
    {
      if ( *(float *)(a1 + 416) > 1.0471976 )
        *(float *)(a1 + 416) = 1.0471976;
      flt_4D8CA8 = 0.0;
    }
    else
    {
      *(float *)(a1 + 416) = 0.052359879;
      flt_4D8CA8 = 0.0;
    }
  }
  v31 = *(float *)(a1 + 416) - *(float *)(a1 + 196);
  v31 = v31 * 0.1000000014901161 + *(float *)(a1 + 196);
  v2 = v31;
  *(float *)(a1 + 196) = v31;
  if ( (_BYTE)word_4D8CA3 )
  {
    v28 = flt_4D8CBC;
    *(float *)&v29 = flt_4D8CC0;
    *(float *)&v30 = v1;
    v27 = v2;
    v3 = sub_401470(v32, &v28, 0.07);
    v4 = sub_401470(&v28, v3, 0.033333335);
    v5 = sub_401470(v33, v4, v27);
    *(float *)(a1 + 212) = *v5 + *(float *)(a1 + 212);
    *(float *)(a1 + 216) = v5[1] + *(float *)(a1 + 216);
    *(float *)(a1 + 220) = v5[2] + *(float *)(a1 + 220);
    if ( *(float *)(a1 + 216) >= -1.570796370506287 )
    {
      if ( *(float *)(a1 + 216) <= 1.570796370506287 )
      {
LABEL_15:
        v7 = *(_DWORD *)(a1 + 216);
        v8 = *(_DWORD *)(a1 + 220);
        *(_DWORD *)(a1 + 352) = *(_DWORD *)(a1 + 212);
        *(_DWORD *)(a1 + 356) = v7;
        *(_DWORD *)(a1 + 360) = v8;
        goto LABEL_16;
      }
      v6 = flt_4D6388;
    }
    else
    {
      v6 = -1.5707964;
    }
    *(float *)(a1 + 216) = v6;
    goto LABEL_15;
  }
LABEL_16:
  v28 = *(float *)&dword_4D82D4;
  v29 = dword_4D82D8;
  v30 = dword_4D82DC;
  if ( (_BYTE)dword_4D8C94 )
  {
    v9 = 100.0;
    v10 = -100.0;
    *(float *)&v30 = 100.0;
  }
  else
  {
    if ( BYTE1(dword_4D8C94) )
      *(float *)&v30 = -100.0;
    v9 = 100.0;
    v10 = -100.0;
  }
  if ( HIBYTE(dword_4D8C94) || (v10 = v9, BYTE2(dword_4D8C94)) )
    v28 = v10;
  v25 = *(float *)(a1 + 196);
  v23 = v28;
  v11 = sub_401AF0(a1, v33);
  v12 = sub_401470(v32, v11, v23);
  v13 = sub_401470(v36, v12, 0.033333335);
  v14 = sub_401470(v34, v13, v25);
  v26 = *(float *)(a1 + 196);
  v15 = v14;
  v24 = v30;
  v16 = sub_401B00(a1, &v28);
  v17 = sub_401470(v40, v16, *(float *)&v24);
  v18 = sub_401470(v38, v17, 0.033333335);
  v19 = sub_401470(v35, v18, v26);
  v20 = sub_401AE0(a1, v37);
  v21 = sub_4013F0(v39, v19, v20);
  result = sub_4013F0(v41, v15, v21);
  *(float *)(a1 + 88) = *result;
  *(float *)(a1 + 92) = result[1];
  *(float *)(a1 + 96) = result[2];
  return result;
}
