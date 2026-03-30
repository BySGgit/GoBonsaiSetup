void *__cdecl memcpy(void *a1, const void *Src, size_t Size)
{
  const __m128i *v3; // esi
  size_t v4; // ecx
  __m128i *v5; // edi
  size_t v6; // ecx
  void *result; // eax
  char *v8; // esi
  char *v9; // edi
  size_t v10; // ecx
  int v11; // eax
  size_t v12; // edx
  unsigned int v13; // ecx
  size_t j; // edx
  __m128i si128; // xmm1
  __m128i v16; // xmm2
  __m128i v17; // xmm3
  __m128i v18; // xmm5
  __m128i v19; // xmm6
  __m128i v20; // xmm7
  unsigned int k; // edx
  unsigned int v22; // ecx
  char v23; // al
  unsigned int m; // ecx
  int v25; // ecx
  unsigned int v26; // eax
  int v27; // ecx
  unsigned int i; // eax
  size_t v29; // [esp-8h] [ebp-10h]

  v3 = (const __m128i *)Src;
  v4 = Size;
  v5 = (__m128i *)a1;
  if ( a1 > Src && a1 < (char *)Src + Size )
  {
    v8 = (char *)Src + Size - 4;
    v9 = (char *)a1 + Size - 4;
    if ( ((unsigned __int8)v9 & 3) == 0 )
    {
      v10 = Size >> 2;
      if ( Size >> 2 >= 8 )
      {
        while ( v10 )
        {
          *(_DWORD *)v9 = *(_DWORD *)v8;
          v8 -= 4;
          v9 -= 4;
          --v10;
        }
        switch ( Size & 3 )
        {
          case 0u:
            goto TrailDown0;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
      switch ( Size & 3 )
      {
        case 0u:
          goto TrailDown0;
        case 1u:
          goto TrailDown1;
        case 2u:
          goto TrailDown2;
        case 3u:
          goto TrailDown3;
      }
    }
    switch ( Size )
    {
      case 0u:
TrailDown0:
        result = a1;
        break;
      case 1u:
TrailDown1:
        v9[3] = v8[3];
        result = a1;
        break;
      case 2u:
TrailDown2:
        v9[3] = v8[3];
        v9[2] = v8[2];
        result = a1;
        break;
      case 3u:
TrailDown3:
        v9[3] = v8[3];
        v9[2] = v8[2];
        v9[1] = v8[1];
        result = a1;
        break;
      default:
        __asm { jmp     dword ptr ds:ByteCopyDown+4[eax*4] }
        return result;
    }
  }
  else if ( Size >= 0x80
         && dword_4DD054
         && (v3 = (const __m128i *)Src, v5 = (__m128i *)a1, ((unsigned __int8)a1 & 0xF) == ((unsigned __int8)Src & 0xF)) )
  {
    v11 = (unsigned __int8)Src & 0xF;
    if ( ((unsigned __int8)Src & 0xF) != 0 )
    {
      v29 = Size - (16 - v11);
      v26 = 16 - v11;
      v27 = v26 & 3;
      if ( (v26 & 3) != 0 )
      {
        do
        {
          v5->m128i_i8[0] = v3->m128i_i8[0];
          v3 = (const __m128i *)((char *)v3 + 1);
          v5 = (__m128i *)((char *)v5 + 1);
          --v27;
        }
        while ( v27 );
      }
      for ( i = v26 >> 2; i; --i )
      {
        v5->m128i_i32[0] = v3->m128i_i32[0];
        v3 = (const __m128i *)((char *)v3 + 4);
        v5 = (__m128i *)((char *)v5 + 4);
      }
      v4 = v29;
    }
    v12 = v4;
    v13 = v4 & 0x7F;
    for ( j = v12 >> 7; j; --j )
    {
      si128 = _mm_load_si128(v3 + 1);
      v16 = _mm_load_si128(v3 + 2);
      v17 = _mm_load_si128(v3 + 3);
      *v5 = _mm_load_si128(v3);
      v5[1] = si128;
      v5[2] = v16;
      v5[3] = v17;
      v18 = _mm_load_si128(v3 + 5);
      v19 = _mm_load_si128(v3 + 6);
      v20 = _mm_load_si128(v3 + 7);
      v5[4] = _mm_load_si128(v3 + 4);
      v5[5] = v18;
      v5[6] = v19;
      v5[7] = v20;
      v3 += 8;
      v5 += 8;
    }
    if ( v13 )
    {
      for ( k = v13 >> 4; k; --k )
        *v5++ = _mm_load_si128(v3++);
      v22 = v13 & 0xF;
      if ( v22 )
      {
        v23 = v22;
        for ( m = v22 >> 2; m; --m )
        {
          v5->m128i_i32[0] = v3->m128i_i32[0];
          v3 = (const __m128i *)((char *)v3 + 4);
          v5 = (__m128i *)((char *)v5 + 4);
        }
        v25 = v23 & 3;
        if ( (v23 & 3) != 0 )
        {
          do
          {
            v5->m128i_i8[0] = v3->m128i_i8[0];
            v3 = (const __m128i *)((char *)v3 + 1);
            v5 = (__m128i *)((char *)v5 + 1);
            --v25;
          }
          while ( v25 );
        }
      }
    }
    return a1;
  }
  else
  {
    if ( ((unsigned __int8)v5 & 3) != 0 )
    {
      if ( Size >= 4 )
        __asm { jmp     dword ptr ds:CopyUnwindUp+4[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0[ecx*4]; jumptable 00453CB9 case 0 }
    }
    v6 = Size >> 2;
    switch ( v6 )
    {
      case 0u:
        goto UnwindUp0;
      case 1u:
        goto UnwindUp1;
      case 2u:
        goto UnwindUp2;
      case 3u:
        goto UnwindUp3;
      case 4u:
        goto UnwindUp4;
      case 5u:
        goto UnwindUp5;
      case 6u:
        goto UnwindUp6;
      case 7u:
        *((_DWORD *)&v5[-1] + v6 - 3) = *((_DWORD *)&v3[-1] + v6 - 3);
UnwindUp6:
        *((_DWORD *)&v5[-1] + v6 - 2) = *((_DWORD *)&v3[-1] + v6 - 2);
UnwindUp5:
        *((_DWORD *)&v5[-1] + v6 - 1) = *((_DWORD *)&v3[-1] + v6 - 1);
UnwindUp4:
        v5[-1].m128i_i32[v6] = v3[-1].m128i_i32[v6];
UnwindUp3:
        v5->m128i_i32[v6 - 3] = v3->m128i_i32[v6 - 3];
UnwindUp2:
        v5->m128i_i32[v6 - 2] = v3->m128i_i32[v6 - 2];
UnwindUp1:
        v5->m128i_i32[v6 - 1] = v3->m128i_i32[v6 - 1];
        v3 = (const __m128i *)((char *)v3 + 4 * v6);
        v5 = (__m128i *)((char *)v5 + 4 * v6);
UnwindUp0:
        switch ( Size & 3 )
        {
          case 0u:
            goto TrailUp0;
          case 1u:
            goto TrailUp1;
          case 2u:
            goto TrailUp2;
          case 3u:
            goto TrailUp3;
        }
      default:
        qmemcpy(v5, v3, 4 * v6);
        v3 = (const __m128i *)((char *)v3 + 4 * v6);
        v5 = (__m128i *)((char *)v5 + 4 * v6);
        switch ( Size & 3 )
        {
          case 0u:
TrailUp0:
            result = a1;
            break;
          case 1u:
TrailUp1:
            v5->m128i_i8[0] = v3->m128i_i8[0];
            result = a1;
            break;
          case 2u:
TrailUp2:
            v5->m128i_i8[0] = v3->m128i_i8[0];
            v5->m128i_i8[1] = v3->m128i_i8[1];
            result = a1;
            break;
          case 3u:
TrailUp3:
            v5->m128i_i8[0] = v3->m128i_i8[0];
            v5->m128i_i8[1] = v3->m128i_i8[1];
            v5->m128i_i8[2] = v3->m128i_i8[2];
            result = a1;
            break;
        }
        break;
    }
  }
  return result;
}
