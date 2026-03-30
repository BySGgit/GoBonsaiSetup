void __usercall sub_412A50(int a1@<esi>)
{
  double v1; // st7
  float *v2; // eax
  float v3; // [esp+4h] [ebp-28h]
  float v4; // [esp+4h] [ebp-28h]
  float v5; // [esp+4h] [ebp-28h]
  float v6; // [esp+8h] [ebp-24h] BYREF
  float v7; // [esp+Ch] [ebp-20h]
  float v8; // [esp+10h] [ebp-1Ch]
  float v9; // [esp+14h] [ebp-18h] BYREF
  float v10; // [esp+18h] [ebp-14h]
  float v11; // [esp+1Ch] [ebp-10h]
  float v12[3]; // [esp+20h] [ebp-Ch] BYREF

  if ( (dword_4D8E9C & 1) == 0 )
  {
    dword_4D8E9C |= 1u;
    flt_4D8DFC = 0.0;
    flt_4D8E00 = 0.0;
    flt_4D8E04 = 1.0;
    atexit(nullsub_3);
  }
  sub_4081F0(&v9, (int)&dword_4D8C94);
  if ( (_BYTE)word_4D8C9A )
  {
    while ( v9 != flt_4D8DFC || v10 != flt_4D8E00 || v11 != flt_4D8E04 )
    {
      sub_401430(&v6, &flt_4D8DFC, &v9);
      v3 = v6 * v6 + v7 * v7 + v8 * v8;
      v4 = sqrt(v3);
      v1 = v4;
      v5 = 1.0 / v4;
      v6 = v5 * v6;
      v7 = v5 * v7;
      v8 = v5 * v8;
      if ( flt_4D6358 >= v1 )
        break;
      v2 = sub_401500(v12, &v6, flt_4D6358);
      flt_4D8DFC = *v2 + flt_4D8DFC;
      flt_4D8E00 = v2[1] + flt_4D8E00;
      flt_4D8E04 = v2[2] + flt_4D8E04;
      sub_412BF0(a1);
    }
  }
  flt_4D8E04 = v11;
  flt_4D8DFC = v9;
  flt_4D8E00 = v10;
  sub_412BF0(a1);
}
