BOOL __cdecl _handle_exc(char a1, double *a2, __int16 a3)
{
  int v3; // esi
  int v4; // eax
  double *v5; // ecx
  double v6; // st7
  BOOL v7; // esi
  int v8; // ecx
  double v9; // st7
  BOOL v10; // edx
  int v11; // eax
  double v13; // [esp+18h] [ebp-14h]
  int v14; // [esp+24h] [ebp-8h] BYREF
  int v15; // [esp+28h] [ebp-4h]

  v3 = a1 & 0x1F;
  v15 = v3;
  if ( (a1 & 8) != 0 && (a3 & 1) != 0 )
  {
    _set_statfp(1);
    v3 = a1 & 0x17;
    goto LABEL_46;
  }
  if ( (a1 & 4) != 0 && (a3 & 4) != 0 )
  {
    _set_statfp(4);
    v3 = a1 & 0x1B;
    goto LABEL_46;
  }
  if ( (a1 & 1) != 0 && (a3 & 8) != 0 )
  {
    _set_statfp(8);
    v4 = a3 & 0xC00;
    if ( (a3 & 0xC00) != 0 )
    {
      if ( v4 != 1024 )
      {
        if ( v4 != 2048 )
        {
          if ( v4 != 3072 )
          {
LABEL_24:
            v3 = a1 & 0x1E;
            goto LABEL_46;
          }
          v5 = a2;
          v6 = dbl_4C9B90;
          if ( *a2 <= 0.0 )
            goto LABEL_22;
LABEL_23:
          *v5 = v6;
          goto LABEL_24;
        }
        v5 = a2;
        if ( *a2 <= 0.0 )
        {
          v6 = dbl_4C9B90;
LABEL_22:
          v6 = -v6;
          goto LABEL_23;
        }
LABEL_20:
        v6 = dbl_4C9B80;
        goto LABEL_23;
      }
      v5 = a2;
      if ( *a2 > 0.0 )
      {
        v6 = dbl_4C9B90;
        goto LABEL_23;
      }
    }
    else
    {
      v5 = a2;
      if ( *a2 > 0.0 )
        goto LABEL_20;
    }
    v6 = dbl_4C9B80;
    goto LABEL_22;
  }
  if ( (a1 & 2) != 0 && (a3 & 0x10) != 0 )
  {
    v7 = (a1 & 0x10) != 0;
    if ( 0.0 == *a2 )
    {
      v7 = 1;
      goto LABEL_43;
    }
    v13 = _decomp(*a2, &v14);
    v8 = v14 - 1536;
    if ( v14 - 1536 >= -1074 )
    {
      v10 = v13 < 0.0;
      HIWORD(v13) = BYTE6(v13) & 0xF | 0x10;
      if ( v8 < -1021 )
      {
        v11 = -1021 - v8;
        do
        {
          if ( (LOBYTE(v13) & 1) != 0 && !v7 )
            v7 = 1;
          LODWORD(v13) >>= 1;
          if ( (BYTE4(v13) & 1) != 0 )
            LODWORD(v13) |= 0x80000000;
          HIDWORD(v13) >>= 1;
          --v11;
        }
        while ( v11 );
      }
      if ( !v10 )
        goto LABEL_41;
      v9 = -v13;
    }
    else
    {
      v7 = 1;
      v9 = v13 * 0.0;
    }
    v13 = v9;
LABEL_41:
    *a2 = v13;
LABEL_43:
    if ( v7 )
      _set_statfp(16);
    v15 &= ~2u;
    v3 = v15;
  }
LABEL_46:
  if ( (a1 & 0x10) != 0 && (a3 & 0x20) != 0 )
  {
    _set_statfp(32);
    v3 &= ~0x10u;
  }
  return v3 == 0;
}
