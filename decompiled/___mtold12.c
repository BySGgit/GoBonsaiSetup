unsigned int *__cdecl __mtold12(char *a1, int a2, unsigned int *a3)
{
  unsigned int *result; // eax
  __int64 v4; // rcx
  unsigned int v5; // edx
  unsigned int v6; // esi
  int v7; // edx
  unsigned int v8; // edi
  unsigned int v9; // esi
  unsigned int v11; // edx
  unsigned int v12; // edx
  unsigned int v13; // esi
  unsigned int v14; // esi
  int v15; // edx
  int v16; // esi
  unsigned int v17; // edx
  unsigned int v18; // edi
  unsigned int v19; // ecx
  int v20; // edi
  unsigned int v21; // ecx
  __int64 v22; // kr08_8
  unsigned int v23; // [esp+Ch] [ebp-18h]
  unsigned int v24; // [esp+10h] [ebp-14h]
  unsigned int v25; // [esp+14h] [ebp-10h]
  int v26; // [esp+18h] [ebp-Ch]
  unsigned int v27; // [esp+1Ch] [ebp-8h]
  int v28; // [esp+1Ch] [ebp-8h]
  __int16 v29; // [esp+20h] [ebp-4h]
  unsigned int v30; // [esp+34h] [ebp+10h]
  int v31; // [esp+34h] [ebp+10h]
  int v32; // [esp+34h] [ebp+10h]
  int v33; // [esp+34h] [ebp+10h]

  result = a3;
  HIDWORD(v4) = 0;
  v29 = 16462;
  *a3 = 0;
  a3[1] = 0;
  a3[2] = 0;
  if ( a2 )
  {
    LODWORD(v4) = 0;
    v30 = 0;
    do
    {
      v23 = *result;
      v24 = result[1];
      v25 = result[2];
      v5 = v30;
      v31 = 0;
      v6 = HIDWORD(v4);
      HIDWORD(v4) = v4 >> 31;
      v7 = (v6 >> 31) | (2 * v5);
      v8 = __SPAIR64__(HIDWORD(v4), 2 * (int)v4) >> 31;
      v27 = v8;
      v9 = 4 * v4;
      LODWORD(v4) = (HIDWORD(v4) >> 31) | (2 * v7);
      v11 = v9 + *result;
      *result = v9;
      result[1] = v8;
      result[2] = v4;
      if ( v11 < v9 || v11 < v23 )
        v31 = 1;
      *result = v11;
      if ( v31 )
      {
        v32 = 0;
        ++v8;
        if ( v27 + 1 < v27 || v27 == -1 )
          v32 = 1;
        result[1] = v8;
        if ( v32 )
        {
          LODWORD(v4) = v4 + 1;
          result[2] = v4;
        }
      }
      v33 = 0;
      HIDWORD(v4) = v8 + v24;
      if ( v8 + v24 < v8 || HIDWORD(v4) < v24 )
        v33 = 1;
      result[1] = HIDWORD(v4);
      if ( v33 )
      {
        LODWORD(v4) = v4 + 1;
        result[2] = v4;
      }
      v28 = 0;
      LODWORD(v4) = (HIDWORD(v4) >> 31) | (2 * (v25 + v4));
      __SET_PAIR__(v13, v12, 2LL * v11);
      HIDWORD(v4) = v13 | (2 * HIDWORD(v4));
      result[2] = v4;
      v26 = v4;
      v30 = v4;
      *result = v12;
      result[1] = HIDWORD(v4);
      v14 = *a1;
      LODWORD(v4) = v12 + v14;
      if ( v12 + v14 < v12 || (unsigned int)v4 < v14 )
        v28 = 1;
      *result = v4;
      if ( v28 )
      {
        v15 = HIDWORD(v4) + 1;
        v16 = 0;
        if ( (unsigned int)(HIDWORD(v4) + 1) < HIDWORD(v4) || HIDWORD(v4) == -1 )
          v16 = 1;
        ++HIDWORD(v4);
        result[1] = v15;
        if ( v16 )
        {
          v30 = v26 + 1;
          result[2] = v26 + 1;
        }
      }
      --a2;
      ++a1;
      result[1] = HIDWORD(v4);
      result[2] = v30;
    }
    while ( a2 );
  }
  if ( !result[2] )
  {
    v17 = result[1];
    do
    {
      v29 -= 16;
      v18 = HIWORD(v17);
      v17 = HIWORD(*result) | (v17 << 16);
      v19 = *result << 16;
      result[1] = v17;
      *result = v19;
    }
    while ( !v18 );
    result[2] = v18;
  }
  v20 = result[2];
  if ( (v20 & 0x8000) == 0 )
  {
    v21 = result[1];
    do
    {
      --v29;
      v20 = (v21 >> 31) | (2 * v20);
      v22 = 2LL * *result;
      v21 = HIDWORD(v22) | (2 * v21);
      *result = v22;
      result[1] = v21;
      result[2] = v20;
    }
    while ( (v20 & 0x8000) == 0 );
  }
  *((_WORD *)result + 5) = v29;
  return result;
}
