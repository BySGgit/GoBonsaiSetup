double __usercall _except2@<st0>(int a1@<ebp>, DWORD a2, int a3, int a4, int a5, double a6, double a7, int a8)
{
  int v8; // eax
  double v10[8]; // [esp+1Ch] [ebp-8Ch] BYREF
  unsigned int v11; // [esp+5Ch] [ebp-4Ch]
  int v12; // [esp+9Ch] [ebp-Ch]
  void *v13; // [esp+A0h] [ebp-8h]
  void *retaddr; // [esp+A8h] [ebp+0h]

  v12 = a1;
  v13 = retaddr;
  if ( !_handle_exc(a2, &a7, a8) )
  {
    v10[6] = a6;
    v11 = v11 & 0xFFFFFFE0 | 3;
    _raise_exc_ex((ULONG_PTR)v10, (unsigned int *)&a8, a2, a3, (float *)&a4, (float *)&a7, 0);
  }
  v8 = _errcode(a2);
  if ( !dword_4CA1B0 && v8 )
    return _umatherr(v8, a3, a4, a5, SLODWORD(a6), SHIDWORD(a6), a7, a8);
  _set_errno_from_matherr(v8);
  _ctrlfp(a8, 0xFFFF);
  return a7;
}
