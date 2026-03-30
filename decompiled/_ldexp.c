double __cdecl ldexp(double X, int Y)
{
  int v2; // edi
  int v3; // eax
  double v5; // st7
  int v6; // eax
  double Number; // [esp+8h] [ebp-20h]
  double v8; // [esp+10h] [ebp-18h]
  int v9; // [esp+18h] [ebp-10h]
  int v10; // [esp+24h] [ebp-4h] BYREF

  v2 = _ctrlfp(4927, 0xFFFF);
  if ( (HIWORD(X) & 0x7FF0) != 0x7FF0 )
  {
    if ( 0.0 == X )
    {
LABEL_6:
      _ctrlfp(v2, 0xFFFF);
      return X;
    }
    v5 = X;
    _decomp(X, (int)&v10);
    if ( Y >= 0 )
    {
      if ( v10 > 0x7FFFFFFF - Y )
      {
LABEL_15:
        v9 = v2;
        v8 = _copysign(dbl_4C9B80, X);
        Number = (double)Y;
        return _except2(17, 25, LODWORD(X), HIDWORD(X), LODWORD(Number), HIDWORD(Number), LODWORD(v8), HIDWORD(v8), v9);
      }
    }
    else if ( v10 < (int)(0x80000000 - Y) )
    {
      goto LABEL_20;
    }
    v6 = v10 + Y;
    if ( v10 + Y > 2560 )
      goto LABEL_15;
    if ( v6 > 1024 )
    {
      _set_exp(X, v6 - 1536);
      v9 = v2;
      v8 = X;
      Number = (double)Y;
      return _except2(17, 25, LODWORD(X), HIDWORD(X), LODWORD(Number), HIDWORD(Number), LODWORD(v8), HIDWORD(v8), v9);
    }
    if ( v6 >= -2557 )
    {
      if ( v6 >= -1021 )
      {
        _set_exp(X, v6);
        _ctrlfp(v2, 0xFFFF);
        return X;
      }
      _set_exp(X, v6 + 1536);
      return _except2(
               18,
               25,
               LODWORD(X),
               HIDWORD(X),
               COERCE_UNSIGNED_INT64((double)Y),
               HIDWORD(COERCE_UNSIGNED_INT64((double)Y)),
               LODWORD(v5),
               HIDWORD(*(unsigned __int64 *)&v5),
               v2);
    }
LABEL_20:
    v5 = X * 0.0;
    return _except2(
             18,
             25,
             LODWORD(X),
             HIDWORD(X),
             COERCE_UNSIGNED_INT64((double)Y),
             HIDWORD(COERCE_UNSIGNED_INT64((double)Y)),
             LODWORD(v5),
             HIDWORD(*(unsigned __int64 *)&v5),
             v2);
  }
  v3 = _sptype(LODWORD(X), HIDWORD(X));
  if ( v3 > 0 )
  {
    if ( v3 > 2 )
    {
      if ( v3 == 3 )
      {
        _handle_qnan2(25, X, (double)Y, v2);
        return X;
      }
      return _except2(
               8,
               25,
               LODWORD(X),
               HIDWORD(X),
               COERCE_UNSIGNED_INT64((double)Y),
               HIDWORD(COERCE_UNSIGNED_INT64((double)Y)),
               COERCE_UNSIGNED_INT64(X + 1.0),
               HIDWORD(COERCE_UNSIGNED_INT64(X + 1.0)),
               v2);
    }
    goto LABEL_6;
  }
  return _except2(
           8,
           25,
           LODWORD(X),
           HIDWORD(X),
           COERCE_UNSIGNED_INT64((double)Y),
           HIDWORD(COERCE_UNSIGNED_INT64((double)Y)),
           COERCE_UNSIGNED_INT64(X + 1.0),
           HIDWORD(COERCE_UNSIGNED_INT64(X + 1.0)),
           v2);
}
