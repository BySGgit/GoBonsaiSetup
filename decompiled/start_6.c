double __usercall start_6@<st0>(int a1@<ecx>, __m128d a2@<xmm0>, __m128d a3@<xmm1>, int a4)
{
  __int16 v4; // ax
  double v5; // xmm3_8
  __m128d v6; // xmm1
  double v7; // xmm4_8
  double *v8; // eax
  __m128d v9; // xmm2
  __m128d v10; // xmm0
  double v11; // xmm3_8
  double v12; // xmm4_8
  __m128d v13; // xmm5
  __m128d v14; // xmm0
  double v15; // xmm7_8
  __m128d v16; // xmm5
  __m128d v17; // xmm0
  double v18; // xmm3_8
  __m128d v19; // xmm2
  double v20; // xmm3_8
  double v21; // xmm7_8
  __m128d v22; // xmm6
  __m128d v23; // xmm2
  __m128d v24; // xmm5
  double v25; // xmm3_8
  __m128d v26; // xmm6
  double result; // st7
  unsigned int epi16; // eax

  v4 = (_mm_extract_epi16((__m128i)a2, 3) & 0x7FFF) - 12336;
  if ( (unsigned __int16)v4 > 0x10C5u )
  {
    if ( v4 > 4293 )
    {
      result = _fload_withFB(a1, &a4);
      start_2(a4);
    }
    else
    {
      epi16 = _mm_extract_epi16((__m128i)a2, 3);
      LOWORD(epi16) = epi16 & 0x7FFF;
      return 1.0 - *(double *)_mm_insert_epi16((__m128i)a2, epi16, 3).m128i_i64;
    }
  }
  else
  {
    a3.m128d_f64[0] = 10.1859163578813 * a2.m128d_f64[0] + 6.755399441055744e15 - 6.755399441055744e15;
    v5 = 0.09817477042088285 * a3.m128d_f64[0];
    v6 = _mm_unpacklo_pd(a3, a3);
    v7 = a2.m128d_f64[0];
    v8 = (double *)((char *)&unk_4C0A50 + 32
                                        * (((unsigned __int8)(int)(10.1859163578813 * a2.m128d_f64[0]) + 16) & 0x3F));
    v9 = _mm_mul_pd((__m128d)xmmword_4C12A0, v6);
    a2.m128d_f64[0] = a2.m128d_f64[0] - v5;
    v10 = _mm_unpacklo_pd(a2, a2);
    v11 = v7 - v5;
    v12 = v11 - v9.m128d_f64[0];
    v13 = _mm_mul_pd((__m128d)xmmword_4C1280, v10);
    v14 = _mm_sub_pd(v10, v9);
    v15 = v8[1] * (v11 - v9.m128d_f64[0]);
    v16 = _mm_mul_pd(v13, v14);
    v17 = _mm_mul_pd(v14, v14);
    v18 = v11 - (v11 - v9.m128d_f64[0]) - v9.m128d_f64[0];
    v19 = *(__m128d *)v8;
    v6.m128d_f64[0] = v6.m128d_f64[0] * 1.263916405497469e-22 - v18;
    v20 = v8[3];
    v19.m128d_f64[0] = *v8 + v20;
    v21 = v15 - v19.m128d_f64[0];
    v19.m128d_f64[0] = v19.m128d_f64[0] * v12;
    v22 = _mm_mul_pd((__m128d)xmmword_4C1260, v17);
    v23 = _mm_mul_pd(v19, v17);
    v24 = _mm_mul_pd(_mm_add_pd(v16, (__m128d)xmmword_4C1270), _mm_mul_pd(v17, v17));
    v17.m128d_f64[0] = v20 * v12;
    v25 = v17.m128d_f64[0] + v8[1];
    v26 = _mm_mul_pd(_mm_add_pd(_mm_add_pd(v22, (__m128d)xmmword_4C1250), v24), v23);
    return v12 * *v8
         + v25
         + v6.m128d_f64[0] * v21
         + v8[2]
         + v8[1]
         - v25
         + v17.m128d_f64[0]
         + v25
         - (v12 * *v8
          + v25)
         + v12 * *v8
         + v26.m128d_f64[0]
         + _mm_unpackhi_pd(v26, v26).m128d_f64[0];
  }
  return result;
}
