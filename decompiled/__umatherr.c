double __cdecl _umatherr(int a1, int a2, int a3, int a4, int a5, int a6, double a7, int a8)
{
  int v8; // eax
  char *v9; // eax

  v8 = 0;
  while ( dword_4C9BA8[2 * v8] != a2 )
  {
    if ( ++v8 >= 29 )
    {
      v9 = 0;
      goto LABEL_5;
    }
  }
  v9 = (&off_4C9BAC)[2 * v8];
LABEL_5:
  if ( v9 )
  {
    _ctrlfp(a8, 0xFFFF);
    if ( !sub_46673E() )
      _set_errno_from_matherr(a1);
    return a7;
  }
  else
  {
    _ctrlfp(a8, 0xFFFF);
    _set_errno_from_matherr(a1);
    return a7;
  }
}
