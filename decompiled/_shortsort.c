_BYTE *__usercall shortsort@<eax>(
        _BYTE *result@<eax>,
        unsigned int a2,
        int a3,
        int (__cdecl *a4)(unsigned int, unsigned int))
{
  unsigned int v4; // edx
  unsigned int v5; // edi
  int v6; // ecx
  unsigned int v7; // esi
  unsigned int v8; // ebx
  int v9; // esi
  unsigned int v10; // ecx
  char v11; // dl

  v4 = a2;
  v5 = (unsigned int)result;
  if ( (unsigned int)result > a2 )
  {
    v6 = a3;
    do
    {
      v7 = a2 + a3;
      v8 = v4;
      if ( a2 + a3 <= v5 )
      {
        do
        {
          if ( a4(v7, v8) > 0 )
            v8 = v7;
          v7 += a3;
        }
        while ( v7 <= v5 );
        v6 = a3;
        v4 = a2;
      }
      v9 = v6;
      result = (_BYTE *)v5;
      if ( v8 != v5 && v6 )
      {
        v10 = v8 - v5;
        do
        {
          v11 = result[v10];
          result[v10] = *result;
          *result++ = v11;
          --v9;
        }
        while ( v9 );
        v6 = a3;
        v4 = a2;
      }
      v5 -= v6;
    }
    while ( v5 > v4 );
  }
  return result;
}
