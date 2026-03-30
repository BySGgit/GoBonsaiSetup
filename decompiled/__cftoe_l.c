int __cdecl _cftoe_l(_DWORD *a1, _BYTE *a2, unsigned int a3, int a4, int a5, struct localeinfo_struct *a6)
{
  int result; // eax
  int v7; // eax
  int v8[4]; // [esp+Ch] [ebp-2Ch] BYREF
  int v9[6]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(*a1, a1[1], (int)v8, (int)v9, 0x16u);
  if ( a2 && (v7 = a3) != 0 )
  {
    if ( a3 != -1 )
      v7 = a3 - (v8[0] == 45) - (a4 > 0);
    result = _fptostr(&a2[(v8[0] == 45) + (a4 > 0)], v7, a4 + 1, (int)v8);
    if ( result )
      *a2 = 0;
    else
      return _cftoe2_l(a2, a3, a4, a5, (int)v8, 0, a6);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}
