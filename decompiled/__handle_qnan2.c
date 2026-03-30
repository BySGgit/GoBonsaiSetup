double __cdecl _handle_qnan2(int a1, double a2, double a3, int a4)
{
  double v5; // [esp+1Ch] [ebp-8h]

  v5 = a2 + a3;
  if ( !dword_4CA1B0 )
    return _umatherr(1, a1, SLODWORD(a2), SHIDWORD(a2), SLODWORD(a3), SHIDWORD(a3), v5, a4);
  *_errno() = 33;
  _ctrlfp(a4, 0xFFFF);
  return v5;
}
