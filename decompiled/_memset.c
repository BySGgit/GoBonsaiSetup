void *__cdecl memset(void *a1, int Val, size_t Size)
{
  size_t v3; // edx
  _BYTE *v4; // ecx
  int v5; // eax
  _BYTE *v6; // edi
  int v7; // ecx
  size_t v8; // ecx
  unsigned int v9; // ecx
  int v11; // eax
  size_t v12; // eax
  unsigned int v13; // edx
  size_t j; // eax
  unsigned int k; // eax
  unsigned int v16; // edx
  char v17; // al
  unsigned int m; // edx
  int n; // eax
  int v20; // edx
  unsigned int i; // ebx

  v3 = Size;
  v4 = a1;
  if ( !Size )
    return a1;
  LOBYTE(v5) = Val;
  if ( !(_BYTE)Val && Size >= 0x80 && dword_4DD054 )
  {
    v11 = (unsigned __int8)a1 & 0xF;
    if ( ((unsigned __int8)a1 & 0xF) != 0 )
    {
      v20 = (16 - (_BYTE)v11) & 3;
      if ( ((16 - (_BYTE)v11) & 3) != 0 )
      {
        do
        {
          *v4++ = 0;
          --v20;
        }
        while ( v20 );
      }
      for ( i = (unsigned int)(16 - v11) >> 2; i; --i )
      {
        *(_DWORD *)v4 = 0;
        v4 += 4;
      }
      v3 = Size - (16 - v11);
    }
    v12 = v3;
    v13 = v3 & 0x7F;
    for ( j = v12 >> 7; j; --j )
    {
      *(_OWORD *)v4 = 0;
      *((_OWORD *)v4 + 1) = 0;
      *((_OWORD *)v4 + 2) = 0;
      *((_OWORD *)v4 + 3) = 0;
      *((_OWORD *)v4 + 4) = 0;
      *((_OWORD *)v4 + 5) = 0;
      *((_OWORD *)v4 + 6) = 0;
      *((_OWORD *)v4 + 7) = 0;
      v4 += 128;
    }
    if ( v13 )
    {
      for ( k = v13 >> 4; k; --k )
      {
        *(_OWORD *)v4 = 0;
        v4 += 16;
      }
      v16 = v13 & 0xF;
      if ( v16 )
      {
        v17 = v16;
        for ( m = v16 >> 2; m; --m )
        {
          *(_DWORD *)v4 = 0;
          v4 += 4;
        }
        for ( n = v17 & 3; n; --n )
          *v4++ = 0;
      }
    }
    return a1;
  }
  else
  {
    v6 = a1;
    if ( Size < 4 )
      goto LABEL_33;
    v7 = -(int)a1 & 3;
    if ( v7 )
    {
      v3 = Size - v7;
      do
      {
        *v6++ = Val;
        --v7;
      }
      while ( v7 );
    }
    v5 = 16843009 * (unsigned __int8)Val;
    v8 = v3;
    v3 &= 3u;
    v9 = v8 >> 2;
    if ( !v9 || (memset32(v6, v5, v9), v6 += 4 * v9, v3) )
    {
LABEL_33:
      do
      {
        *v6++ = v5;
        --v3;
      }
      while ( v3 );
    }
    return a1;
  }
}
