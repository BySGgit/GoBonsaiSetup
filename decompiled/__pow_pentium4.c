double __usercall _pow_pentium4@<st0>(
        __m128d a1@<xmm0>,
        __m128d a2@<xmm1>,
        __m128d a3@<xmm2>,
        __m128d a4@<xmm3>,
        __m128d a5@<xmm4>,
        __m128d a6@<xmm5>,
        __m128d a7@<xmm7>,
        double a8,
        double a9)
{
  __m128d v9; // xmm7
  __m128d inserted; // xmm0
  int epi16; // ecx
  int v12; // eax
  __m128d v13; // xmm7
  __m128d v14; // xmm6
  int v15; // edx
  unsigned int v16; // ecx
  unsigned int v17; // edx
  __m128d v18; // xmm1
  __m128d v19; // xmm0
  __m128d v20; // xmm7
  int v21; // eax
  __m128d v22; // xmm6
  double v23; // xmm2_8
  int v24; // eax
  double v25; // xmm2_8
  double v26; // xmm5_8
  __m128d v27; // xmm3
  double v28; // xmm2_8
  double v29; // xmm2_8
  __m128i v30; // xmm1
  int v31; // edx
  double v32; // xmm2_8
  __m128d v33; // xmm0
  __m128d v34; // xmm6
  __m128d v35; // xmm7
  unsigned int v36; // eax
  double v37; // xmm2_8
  double v38; // xmm4_8
  double v39; // xmm3_8
  double v40; // xmm1_8
  double v41; // xmm3_8
  double v42; // xmm5_8
  double v43; // xmm5_8
  double v44; // xmm4_8
  double v45; // xmm5_8
  int v46; // eax
  __m128d v47; // xmm2
  __m128d v48; // xmm7
  __m128i v49; // xmm2
  __m128i v50; // xmm3
  __m128d v51; // xmm0
  __m128d v52; // xmm6
  double v53; // xmm4_8
  __m128d v54; // xmm0
  __m128i v55; // xmm7
  double result; // st7
  int v57; // eax
  __m128i v58; // xmm1
  unsigned int v59; // ecx
  __m128i v60; // xmm2
  __m128d v61; // xmm1
  __m128i v62; // xmm2
  unsigned __int8 v63; // al
  unsigned int v64; // edx
  __m128i v65; // xmm1
  int v66; // edx
  int v67; // eax
  __m128d v68; // xmm7
  int v69; // eax
  __m128d v70; // xmm0
  int v71; // edx
  __m128d v72; // xmm1
  int v73; // eax
  int v74; // eax
  int v75; // eax
  __m128i v76; // xmm4
  int v77; // ecx
  unsigned int v78; // eax
  int v79; // eax
  unsigned int v80; // ecx
  unsigned int v81; // edx
  unsigned int v82; // edi
  double v83; // xmm4_8
  __m128d v84; // xmm2
  __m128d v85; // xmm7
  __m128i v86; // xmm2
  __m128i v87; // xmm3
  __m128d v88; // xmm0
  __m128d v89; // xmm6
  double v90; // xmm4_8
  __m128i v91; // xmm7
  double v92; // xmm7_8
  double v93; // xmm1_8
  __int64 v94; // xmm4_8
  double v95; // xmm1_8
  double v96; // xmm6_8
  int v97; // eax
  int v98; // eax
  int v99; // eax
  int v100; // edx
  unsigned int v101; // eax
  int v102; // [esp+0h] [ebp-1Ch] BYREF
  double v103; // [esp+10h] [ebp-Ch] BYREF

  a1.m128d_f64[0] = a8;
  a7.m128d_f64[0] = COERCE_DOUBLE(0xFFFFFFFFFFFFFLL);
  a3.m128d_f64[0] = 1.0;
  v9 = _mm_and_pd(a7, a1);
  a5.m128d_f64[0] = a8;
  inserted = (__m128d)_mm_srli_epi64((__m128i)a1, 0x2Cu);
  v13 = _mm_or_pd(v9, a3);
  epi16 = _mm_extract_epi16((__m128i)a5, 3);
  v12 = ((unsigned __int8)_mm_extract_epi16((__m128i)inserted, 0) + 1) & 0x1FE;
  v13.m128d_f64[0] = v13.m128d_f64[0] * *(double *)((char *)&qword_4BC790 + 4 * v12);
  a6.m128d_f64[0] = *(double *)((char *)&qword_4BC790 + 4 * v12);
  v14 = *(__m128d *)((char *)&xmmword_4BCBA0 + 8 * v12);
  v15 = 32751 - epi16;
  if ( ((32751 - epi16) | (unsigned int)(epi16 - 16)) < 0x80000000 )
  {
    v16 = 0;
    v17 = 261759;
    goto BACK_MAIN;
  }
  a2.m128d_f64[0] = a9;
  a4.m128d_f64[0] = NAN;
  v57 = _mm_cvtsi128_si32((__m128i)a2);
  a3.m128d_f64[0] = a9;
  v58 = _mm_srli_epi64((__m128i)_mm_and_pd(a2, a4), 0x20u);
  v59 = _mm_cvtsi128_si32(v58);
  if ( v59 >= 0x7FF00000 )
  {
    v13.m128d_f64[0] = a8;
    a5.m128d_f64[0] = a8;
    v31 = _mm_cvtsi128_si32((__m128i)v13);
    v16 = _mm_cvtsi128_si32(_mm_srli_epi64((__m128i)v13, 0x20u));
    if ( (v16 & 0x7FFFFFFF) < 0x7FF00000 || (v16 & 0x7FFFFFFF) <= 0x7FF00000 && !v31 )
      goto Y_INF_NAN;
    goto X_NAN;
  }
  if ( !(v59 | v57) )
  {
    v75 = _mm_cvtsi128_si32((__m128i)a5);
    v76 = _mm_srli_epi64((__m128i)a5, 0x20u);
    v77 = v75;
    v70.m128d_f64[0] = 1.0;
    v71 = 26;
    if ( _mm_cvtsi128_si32(v76) & 0x7FFFFFFF | v75 )
    {
      v71 = 29;
      v78 = _mm_cvtsi128_si32(v76) & 0x7FFFFFFF;
      if ( v78 <= 0x7FF00000 && (v78 < 0x7FF00000 || !v77) )
      {
        v103 = 1.0;
        return 1.0;
      }
    }
    goto CALL_LIBM_ERROR;
  }
  if ( v15 >= 0 )
  {
    v16 = 0;
    goto DENORMAL_X;
  }
  v60 = (__m128i)_mm_or_pd(a3, (__m128d)_mm_slli_epi64((__m128i)a4, 0x34u));
  a4 = 0;
  v61 = (__m128d)_mm_max_epi16(_mm_sub_epi32(_mm_srli_epi64(v58, 0x14u), _mm_cvtsi32_si128(0x3F3u)), (__m128i)0LL);
  v62 = _mm_cmpeq_epi32(_mm_sll_epi64(v60, (__m128i)v61), (__m128i)0LL);
  v63 = _mm_movemask_epi8(v62);
  v64 = (32751 - v15) & 0x7FFF;
  if ( v64 >= 0x7FF0 )
  {
    a4.m128d_f64[0] = COERCE_DOUBLE(0xFFFFFFFFFFFFFLL);
    v72 = (__m128d)_mm_cmpeq_epi32((__m128i)0LL, (__m128i)_mm_and_pd(a4, a5));
    if ( (unsigned __int8)_mm_movemask_epi8((__m128i)v72) == 255 )
    {
      if ( (_mm_extract_epi16((__m128i)a5, 3) & 0x8000) != 0 )
      {
        if ( v63 == 255 )
        {
          v72.m128d_f64[0] = a9;
          *(double *)v62.m128i_i64 = a9;
          v72 = (__m128d)_mm_sub_epi32(
                           _mm_srli_epi64((__m128i)_mm_and_pd(v72, (__m128d)xmmword_4C0040), 0x34u),
                           _mm_cvtsi32_si128(0x3F4u));
          if ( (unsigned __int8)_mm_movemask_epi8(_mm_cmpeq_epi32(_mm_sll_epi64(v62, (__m128i)v72), (__m128i)0LL)) != 255 )
          {
            v72.m128d_f64[0] = a9;
            if ( (_mm_extract_epi16((__m128i)v72, 3) & 0x8000) == 0 )
              return -INFINITY;
            return -0.0;
          }
        }
        v72.m128d_f64[0] = a9;
        if ( (_mm_extract_epi16((__m128i)v72, 3) & 0x8000) != 0 )
          return 0.0;
      }
      else
      {
        v72.m128d_f64[0] = a9;
        if ( (_mm_extract_epi16((__m128i)v72, 3) & 0x8000) != 0 )
          return 0.0;
      }
      return INFINITY;
    }
X_NAN:
    v70.m128d_f64[0] = a5.m128d_f64[0] + a5.m128d_f64[0];
    v71 = 1006;
    goto CALL_LIBM_ERROR;
  }
  if ( v63 != 255 )
  {
    *(double *)v62.m128i_i64 = a8;
    v73 = _mm_cvtsi128_si32(v62);
    a3 = (__m128d)_mm_srli_epi64(v62, 0x20u);
    v67 = _mm_cvtsi128_si32((__m128i)a3) & 0x7FFFFFFF | v73;
    v16 = 0;
    if ( v67 )
    {
      v70.m128d_f64[0] = NAN;
      v71 = 28;
      goto CALL_LIBM_ERROR;
    }
    goto ZERO_X;
  }
  v61.m128d_f64[0] = a9;
  *(double *)v62.m128i_i64 = a9;
  a4 = (__m128d)_mm_cvtsi32_si128(0x3F4u);
  v65 = _mm_sub_epi32(_mm_srli_epi64((__m128i)_mm_and_pd(v61, (__m128d)xmmword_4C0040), 0x34u), (__m128i)a4);
  a4.m128d_f64[0] = -0.0;
  a3 = (__m128d)_mm_cmpeq_epi32(_mm_sll_epi64(v62, v65), (__m128i)a4);
  v16 = ((unsigned __int8)_mm_movemask_epi8((__m128i)a3) + 261889) & 0x40000;
  if ( v64 >= 0x10 )
  {
    v17 = 786047;
    goto BACK_MAIN;
  }
DENORMAL_X:
  inserted = (__m128d)_mm_insert_epi16((__m128i)0LL, 0x43F0u, 3);
  v13.m128d_f64[0] = COERCE_DOUBLE(0xFFFFFFFFFFFFFLL);
  a3.m128d_f64[0] = 1.0;
  inserted.m128d_f64[0] = inserted.m128d_f64[0] * a8;
  v66 = _mm_cvtsi128_si32((__m128i)a5);
  a5 = (__m128d)_mm_srli_epi64((__m128i)a5, 0x20u);
  v67 = _mm_cvtsi128_si32((__m128i)a5);
  if ( !v66 )
  {
ZERO_X:
    if ( (v67 & 0x7FFFFFFF) != 0 )
      goto BACK_DEN;
    if ( a9 < 0.0 )
    {
      *(_QWORD *)&v70.m128d_f64[0] = _mm_cvtsi32_si128((v16 << 13) & v67 | 0x7FF00000).m128i_u64[0] << 32;
      v71 = 27;
      goto CALL_LIBM_ERROR;
    }
    if ( ((v16 << 13) & v67) == 0 )
      return 0.0;
    return -0.0;
  }
BACK_DEN:
  v68 = _mm_and_pd(v13, inserted);
  a5.m128d_f64[0] = inserted.m128d_f64[0];
  inserted = (__m128d)_mm_srli_epi64((__m128i)_mm_and_pd(inserted, (__m128d)xmmword_4C0040), 0x2Cu);
  v13 = _mm_or_pd(v68, a3);
  v69 = ((unsigned __int8)_mm_extract_epi16((__m128i)inserted, 0) + 1) & 0x1FE;
  v13.m128d_f64[0] = v13.m128d_f64[0] * *(double *)((char *)&qword_4BC790 + 4 * v69);
  a6.m128d_f64[0] = *(double *)((char *)&qword_4BC790 + 4 * v69);
  v14 = *(__m128d *)((char *)&xmmword_4BCBA0 + 8 * v69);
  v17 = 278143;
BACK_MAIN:
  v18 = (__m128d)_mm_cvtsi32_si128(v17);
  v19 = _mm_cvtepi32_pd(_mm_srli_epi64(_mm_sub_epi64((__m128i)inserted, (__m128i)v18), 8u));
  v18.m128d_f64[0] = NAN;
  a4.m128d_f64[0] = v13.m128d_f64[0];
  v20 = (__m128d)_mm_srli_epi64((__m128i)v13, 0x26u);
  v21 = ((unsigned __int8)_mm_extract_epi16((__m128i)v20, 0) + 1) & 0x1FE;
  a4.m128d_f64[0] = a4.m128d_f64[0] * *(double *)((char *)&qword_4BD3B0 + 4 * v21);
  a6.m128d_f64[0] = a6.m128d_f64[0] * *(double *)((char *)&qword_4BD3B0 + 4 * v21);
  v22 = _mm_add_pd(v14, *(__m128d *)((char *)&xmmword_4BD7C0 + 8 * v21));
  a5 = _mm_or_pd(_mm_and_pd(a5, (__m128d)xmmword_4C0020), (__m128d)xmmword_4C0030);
  v22.m128d_f64[0] = v22.m128d_f64[0] + v19.m128d_f64[0];
  v30 = (__m128i)_mm_and_pd(v18, a5);
  v23 = a4.m128d_f64[0];
  v27 = (__m128d)_mm_srli_epi64((__m128i)a4, 0x1Fu);
  v19.m128d_f64[0] = NAN;
  a5.m128d_f64[0] = a5.m128d_f64[0] - *(double *)v30.m128i_i64;
  v24 = ((_mm_extract_epi16((__m128i)v27, 0) & 0x1FF) + 1) & 0x3FE;
  a6.m128d_f64[0] = a6.m128d_f64[0] * *(double *)((char *)&qword_4BDFD0 + 4 * v24);
  v25 = v23 * *(double *)((char *)&qword_4BDFD0 + 4 * v24);
  v34 = _mm_add_pd(v22, *(__m128d *)((char *)&xmmword_4BE7E0 + 8 * v24));
  v33 = _mm_and_pd(v19, a6);
  v26 = a6.m128d_f64[0] - v33.m128d_f64[0];
  v20.m128d_f64[0] = v25 + -1.442694902420044;
  v27.m128d_f64[0] = v33.m128d_f64[0];
  v28 = v25 - v33.m128d_f64[0] * *(double *)v30.m128i_i64;
  v33.m128d_f64[0] = v34.m128d_f64[0];
  v29 = v28 - *(double *)v30.m128i_i64 * v26;
  v34.m128d_f64[0] = v34.m128d_f64[0] + v20.m128d_f64[0];
  *(double *)v30.m128i_i64 = a9;
  v31 = _mm_extract_epi16((__m128i)v34, 3);
  v32 = v29 - v27.m128d_f64[0] * a5.m128d_f64[0] - a5.m128d_f64[0] * v26;
  a5.m128d_f64[0] = v34.m128d_f64[0];
  v33.m128d_f64[0] = v33.m128d_f64[0] - v34.m128d_f64[0] + v20.m128d_f64[0];
  v20.m128d_f64[0] = v20.m128d_f64[0] - v32;
  v34.m128d_f64[0] = v34.m128d_f64[0] - v32;
  v35 = _mm_unpacklo_pd(v20, v20);
  v36 = _mm_extract_epi16(v30, 3) & 0x7FF0;
  if ( v36 >= 0x7FF0 )
  {
    a5.m128d_f64[0] = a8;
    a3.m128d_f64[0] = a9;
    v27.m128d_f64[0] = COERCE_DOUBLE(0xFFFFFFFFFFFFFLL);
    a4 = _mm_and_pd(v27, a3);
    if ( (unsigned __int8)_mm_movemask_epi8(_mm_cmpeq_epi32((__m128i)0LL, (__m128i)a4)) != 255 )
      goto RET_Y_NAN;
    if ( !_mm_cvtsi128_si32((__m128i)a5) )
    {
      a5 = (__m128d)_mm_srli_epi64((__m128i)a5, 0x20u);
      v31 = _mm_cvtsi128_si32((__m128i)a5);
      if ( v31 == 1072693248 )
        goto RET_ONE;
      if ( v31 == -1074790400 )
        return 1.0;
    }
Y_INF_NAN:
    a4.m128d_f64[0] = COERCE_DOUBLE(0xFFFFFFFFFFFFFLL);
    if ( (unsigned __int8)_mm_movemask_epi8(_mm_cmpeq_epi32((__m128i)0LL, (__m128i)_mm_and_pd(a4, a3))) == 255 )
    {
      a5.m128d_f64[0] = a8;
      v74 = _mm_extract_epi16((__m128i)a3, 3) & 0x8000;
      if ( v16 ^ 0xBFF00000 | v31 )
      {
        if ( v74 )
        {
          if ( (_mm_extract_epi16((__m128i)a5, 3) & 0x7FF0u) >= 0x3FF0 )
            return 0.0;
        }
        else if ( (_mm_extract_epi16((__m128i)a5, 3) & 0x7FF0u) < 0x3FF0 )
        {
          return 0.0;
        }
        return INFINITY;
      }
RET_ONE:
      v70.m128d_f64[0] = 1.0;
      v71 = 28;
      goto CALL_LIBM_ERROR;
    }
RET_Y_NAN:
    v70.m128d_f64[0] = a3.m128d_f64[0] + a3.m128d_f64[0];
    v71 = 1006;
    goto CALL_LIBM_ERROR;
  }
  if ( (((v31 & 0x7FF0) + v36 - 16368 - 15472) | (16544 - ((v31 & 0x7FF0) + v36 - 16368))) < 0x80000000
    || (a5 = _mm_mul_pd((__m128d)_mm_shuffle_epi32(v30, 68), v34),
        v99 = _mm_extract_epi16((__m128i)a5, 3) & 0x7FF0,
        v100 = 16544 - v99,
        v101 = v99 - 15472,
        (v101 | v100) < 0x80000000) )
  {
    v37 = v32 - (a5.m128d_f64[0] - v34.m128d_f64[0]);
    *(_QWORD *)&v38 = COERCE_UNSIGNED_INT64(NAN) & *(_QWORD *)&v34.m128d_f64[0];
    v33.m128d_f64[0] = v33.m128d_f64[0] - v37;
    v39 = COERCE_DOUBLE(COERCE_UNSIGNED_INT64(NAN) & *(_QWORD *)&a9)
        * COERCE_DOUBLE(COERCE_UNSIGNED_INT64(NAN) & *(_QWORD *)&v34.m128d_f64[0]);
    v34.m128d_f64[0] = v34.m128d_f64[0] - COERCE_DOUBLE(COERCE_UNSIGNED_INT64(NAN) & *(_QWORD *)&v34.m128d_f64[0]);
    v40 = a9 - COERCE_DOUBLE(COERCE_UNSIGNED_INT64(NAN) & *(_QWORD *)&a9);
    v41 = v39 * *(double *)_mm_insert_epi16((__m128i)0LL, 0x4060u, 3).m128i_i64;
    v42 = COERCE_DOUBLE(COERCE_UNSIGNED_INT64(NAN) & *(_QWORD *)&a9) * v34.m128d_f64[0];
    v34.m128d_f64[0] = v34.m128d_f64[0] * v40;
    v43 = v42 + v38 * v40;
    *(_QWORD *)&v44 = _mm_shuffle_epi32((__m128i)v34, 238).m128i_u64[0];
    v45 = v43 + v34.m128d_f64[0];
    v46 = (int)v41;
    if ( (((int)v41 + 123391) | (130943 - (int)v41)) > 0 )
    {
      v47 = _mm_mul_pd((__m128d)xmmword_4BF7F0, v35);
      v48 = _mm_mul_pd(v35, v35);
      v49 = (__m128i)_mm_add_pd(v47, _mm_mul_pd((__m128d)xmmword_4BF800, v48));
      *(double *)v49.m128i_i64 = *(double *)v49.m128i_i64 * v48.m128d_f64[0]
                               + *(double *)_mm_shuffle_epi32(v49, 238).m128i_i64
                               + v44
                               + v33.m128d_f64[0];
      v33.m128d_f64[0] = (v41 - (v41 + 6.755399441055744e15 - 6.755399441055744e15))
                       * *(double *)_mm_insert_epi16((__m128i)0LL, 0x3F80u, 3).m128i_i64;
      v50 = (__m128i)_mm_mul_pd(
                       *((__m128d *)&unk_4BF810 + ((int)v41 & 0x7F)),
                       (__m128d)_mm_shuffle_epi32(
                                  _mm_slli_epi64(_mm_cvtsi32_si128((((int)v41 + v16) & 0xFFFFFF80) + 130944), 0x2Du),
                                  68));
      v33.m128d_f64[0] = v33.m128d_f64[0] + v45 + *(double *)v49.m128i_i64 * a9;
      v51 = _mm_unpacklo_pd(v33, v33);
      v52 = _mm_mul_pd((__m128d)xmmword_4C0050, v51);
      v53 = 0.6931471805599453 * v51.m128d_f64[0];
      v54 = _mm_mul_pd(v51, v51);
      v55 = (__m128i)_mm_mul_pd(_mm_add_pd((__m128d)xmmword_4C0060, v52), v54);
      return v54.m128d_f64[0] * *(double *)v50.m128i_i64 * *(double *)v55.m128i_i64
           + *(double *)_mm_shuffle_epi32(v50, 238).m128i_i64
           + *(double *)_mm_shuffle_epi32(v55, 238).m128i_i64 * *(double *)v50.m128i_i64
           + v53 * *(double *)v50.m128i_i64
           + *(double *)v50.m128i_i64;
    }
    if ( v46 <= 0 )
    {
      if ( v46 <= -261632 )
      {
RET_ZERO_UF:
        *(_QWORD *)&v70.m128d_f64[0] = COERCE_UNSIGNED_INT64(2.225073858507201e-308 * 2.225073858507201e-308)
                                     | (_mm_cvtsi32_si128(v16).m128i_u64[0] << 45);
        v71 = 25;
        goto CALL_LIBM_ERROR;
      }
      v79 = (int)v41 & 0x7F;
      v80 = v16 + 128;
      v81 = ((int)v41 & 0xFFFFFF80) + 261760;
      v82 = 0;
    }
    else
    {
      if ( (unsigned int)v46 >= 0x40000 )
        goto RET_INF_OF;
      v79 = (int)v41 & 0x7F;
      v80 = v16 + 261888;
      v81 = ((int)v41 - 128) & 0xFFFFFF80;
      v82 = 16368;
    }
    v83 = v44 + v33.m128d_f64[0];
    v84 = _mm_mul_pd((__m128d)xmmword_4BF7F0, v35);
    v85 = _mm_mul_pd(v35, v35);
    v33.m128d_f64[0] = v41 - (v41 + 6.755399441055744e15 - 6.755399441055744e15);
    v86 = (__m128i)_mm_add_pd(v84, _mm_mul_pd((__m128d)xmmword_4BF800, v85));
    v87 = (__m128i)_mm_mul_pd(
                     *((__m128d *)&unk_4BF810 + v79),
                     (__m128d)_mm_shuffle_epi32(_mm_slli_epi64(_mm_cvtsi32_si128(v81), 0x2Du), 68));
    v33.m128d_f64[0] = v33.m128d_f64[0] * *(double *)_mm_insert_epi16((__m128i)0LL, 0x3F80u, 3).m128i_i64
                     + v45
                     + (*(double *)v86.m128i_i64 * v85.m128d_f64[0]
                      + *(double *)_mm_shuffle_epi32(v86, 238).m128i_i64
                      + v83)
                     * a9;
    v88 = _mm_unpacklo_pd(v33, v33);
    v89 = _mm_mul_pd((__m128d)xmmword_4C0050, v88);
    v90 = 0.6931471805599453 * v88.m128d_f64[0];
    v70 = _mm_mul_pd(v88, v88);
    v91 = (__m128i)_mm_mul_pd(_mm_add_pd((__m128d)xmmword_4C0060, v89), v70);
    v89.m128d_f64[0] = *(double *)_mm_shuffle_epi32(v91, 238).m128i_i64;
    v70.m128d_f64[0] = v70.m128d_f64[0] * *(double *)v87.m128i_i64 * *(double *)v91.m128i_i64;
    *(_QWORD *)&v92 = _mm_cvtsi32_si128(v80).m128i_u64[0] << 45;
    v86.m128i_i8[0] = _mm_cvtsi32_si128((((unsigned __int8)((int)(130944 - v81) >> 7) + 2) & 0x20u) + ((int)(130944 - v81) >> 7) + 2).m128i_u8[0];
    *(_QWORD *)&v93 = (-1LL << v86.m128i_i8[0]) & v87.m128i_i64[0];
    v70.m128d_f64[0] = v70.m128d_f64[0]
                     + *(double *)_mm_shuffle_epi32(v87, 238).m128i_i64
                     + v89.m128d_f64[0] * *(double *)v87.m128i_i64
                     + v90 * *(double *)v87.m128i_i64;
    v94 = -1LL << v86.m128i_i8[0];
    *(double *)v87.m128i_i64 = *(double *)v87.m128i_i64 - v93;
    *(double *)v86.m128i_i64 = v93;
    *(_QWORD *)&v95 = COERCE_UNSIGNED_INT64(v93 + v70.m128d_f64[0]) & v94;
    *(_QWORD *)&v96 = _mm_insert_epi16((__m128i)0LL, v82, 3).m128i_u64[0];
    v70.m128d_f64[0] = v70.m128d_f64[0] + *(double *)v86.m128i_i64 - v95 + *(double *)v87.m128i_i64;
    if ( (int)(v81 - 130944) > 0 )
    {
      v70.m128d_f64[0] = (v70.m128d_f64[0] + v95) * v92 + v96 * ((v70.m128d_f64[0] + v95) * v92);
      v98 = _mm_extract_epi16((__m128i)v70, 3) & 0x7FF0;
      v71 = 24;
      if ( v98 != 32752 )
      {
        v71 = 25;
        if ( v98 )
        {
          v103 = v70.m128d_f64[0];
          return v70.m128d_f64[0];
        }
      }
    }
    else
    {
      v70.m128d_f64[0] = v70.m128d_f64[0] * v92 + v95 * v92 + v96 * (v70.m128d_f64[0] * v92 + v95 * v92);
      v97 = _mm_extract_epi16((__m128i)v70, 3) & 0x7FF0;
      v71 = 24;
      if ( v97 != 32752 )
      {
        v71 = 25;
        if ( v97 )
        {
          v103 = v70.m128d_f64[0];
          return v70.m128d_f64[0];
        }
      }
    }
CALL_LIBM_ERROR:
    v103 = v70.m128d_f64[0];
    __libm_error_support(&v102 + 8, &a9, &v103, v71);
    return v103;
  }
  if ( v101 < 0x80000000 )
  {
    a5.m128d_f64[0] = a8;
    if ( (((unsigned __int16)((_mm_extract_epi16((__m128i)a5, 3) & 0x7FF0) - 16368)
         ^ (unsigned __int16)_mm_extract_epi16(v30, 3))
        & 0x8000) == 0 )
    {
RET_INF_OF:
      v71 = 24;
      if ( v16 )
        v70.m128d_f64[0] = -8.98846567431158e307 * 8.98846567431158e307;
      else
        v70.m128d_f64[0] = 8.98846567431158e307 * 8.98846567431158e307;
      goto CALL_LIBM_ERROR;
    }
    goto RET_ZERO_UF;
  }
  *(_QWORD *)&result = _mm_cvtsi32_si128(v16 | 0x1FF80).m128i_u64[0] << 45;
  return result;
}
