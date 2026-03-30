double __cdecl _Stodx(char *String, char **EndPtr, int a3, int *a4)
{
  int v4; // esi
  int v6; // eax
  double v8; // [esp+4h] [ebp-8h]

  v4 = *_errno();
  *_errno() = 0;
  v8 = strtod(String, EndPtr);
  *a4 = *_errno();
  *_errno() = v4;
  while ( a3 > 0 )
  {
    --a3;
    v8 = v8 * 10.0;
  }
  if ( a3 < 0 )
  {
    v6 = -a3;
    do
    {
      --v6;
      v8 = v8 / 10.0;
    }
    while ( v6 );
  }
  return v8;
}
