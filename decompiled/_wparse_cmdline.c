__int16 **__usercall wparse_cmdline@<eax>(
        __int16 *a1@<eax>,
        __int16 *a2@<ecx>,
        _DWORD *a3@<ebx>,
        __int16 **a4,
        _DWORD *a5)
{
  BOOL v5; // edx
  _DWORD *v6; // edi
  __int16 **v8; // ecx
  __int16 v9; // cx
  int v10; // ecx
  __int16 **v11; // ecx
  int v12; // edi
  unsigned int v13; // edx
  int v14; // ecx
  __int16 **result; // eax
  BOOL v16; // [esp+8h] [ebp-4h]

  v5 = 0;
  v6 = a5;
  *a3 = 0;
  *a5 = 1;
  if ( a4 )
  {
    v8 = a4++;
    *v8 = a2;
  }
  do
  {
    if ( *a1 == 34 )
    {
      v6 = a5;
      ++a1;
      v5 = !v5;
      v9 = 34;
    }
    else
    {
      ++*a3;
      if ( a2 )
        *a2++ = *a1;
      v9 = *a1++;
      if ( !v9 )
      {
        --a1;
        goto LABEL_13;
      }
    }
  }
  while ( v5 || v9 != 32 && v9 != 9 );
  if ( a2 )
    *(a2 - 1) = 0;
LABEL_13:
  v16 = 0;
  while ( *a1 )
  {
    while ( 1 )
    {
      v10 = (unsigned __int16)*a1;
      if ( v10 != 32 && v10 != 9 )
        break;
      ++a1;
    }
    if ( !*a1 )
      break;
    if ( a4 )
    {
      v11 = a4++;
      *v11 = a2;
    }
    ++*v6;
    while ( 1 )
    {
      v12 = 1;
      v13 = 0;
      while ( *a1 == 92 )
      {
        ++a1;
        ++v13;
      }
      if ( *a1 == 34 )
      {
        if ( (v13 & 1) == 0 )
        {
          if ( v16 && a1[1] == 34 )
          {
            ++a1;
          }
          else
          {
            v12 = 0;
            v16 = !v16;
          }
        }
        v13 >>= 1;
      }
      while ( v13 )
      {
        --v13;
        if ( a2 )
          *a2++ = 92;
        ++*a3;
      }
      v14 = (unsigned __int16)*a1;
      if ( !(_WORD)v14 || !v16 && (v14 == 32 || v14 == 9) )
        break;
      if ( v12 )
      {
        if ( a2 )
          *a2++ = v14;
        ++*a3;
      }
      ++a1;
    }
    if ( a2 )
      *a2++ = 0;
    ++*a3;
    v6 = a5;
  }
  result = a4;
  if ( a4 )
    *a4 = 0;
  ++*v6;
  return result;
}
