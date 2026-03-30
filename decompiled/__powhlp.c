int __cdecl _powhlp(long double a1, double a2, double *a3)
{
  long double v3; // st7
  int v4; // esi
  double v5; // st7
  bool v6; // c3
  double *v7; // eax
  int v8; // eax

  v3 = fabs(a1);
  v4 = 0;
  if ( HIDWORD(a2) == 2146435072 )
  {
    if ( !LODWORD(a2) )
    {
      if ( v3 <= 1.0 )
      {
        v6 = 1.0 == v3;
        v5 = 1.0;
        v7 = a3;
        if ( !v6 )
          v5 = 0.0;
        goto LABEL_27;
      }
      goto LABEL_4;
    }
  }
  else if ( a2 == -INFINITY )
  {
    if ( v3 <= 1.0 )
    {
      v7 = a3;
      if ( v3 >= 1.0 )
      {
        v5 = dbl_4C9B88;
        v4 = 1;
      }
      else
      {
        v5 = dbl_4C9B80;
      }
      goto LABEL_27;
    }
    v5 = 0.0;
LABEL_26:
    v7 = a3;
LABEL_27:
    *v7 = v5;
    return v4;
  }
  if ( HIDWORD(a1) == 2146435072 )
  {
    if ( !LODWORD(a1) )
    {
      v5 = 0.0;
      if ( a2 <= 0.0 )
      {
        v7 = a3;
        if ( a2 >= 0.0 )
          v5 = 1.0;
        goto LABEL_27;
      }
LABEL_4:
      v5 = dbl_4C9B80;
      goto LABEL_26;
    }
  }
  else if ( a1 == -INFINITY )
  {
    v8 = _d_inttype(a2);
    v5 = 0.0;
    if ( a2 <= 0.0 )
    {
      if ( a2 >= 0.0 )
      {
        v5 = 1.0;
      }
      else if ( v8 == 1 )
      {
        v5 = dbl_4C9BA0;
      }
    }
    else
    {
      v5 = dbl_4C9B80;
      if ( v8 == 1 )
        v5 = -dbl_4C9B80;
    }
    goto LABEL_26;
  }
  return v4;
}
