int __cdecl _cftof_l(_DWORD *a1, char *Str, int a3, size_t Size, struct localeinfo_struct *a5)
{
  int result; // eax
  int v6; // eax
  int v7[4]; // [esp+8h] [ebp-2Ch] BYREF
  int v8[6]; // [esp+18h] [ebp-1Ch] BYREF

  _fltout2(*a1, a1[1], (int)v7, (int)v8, 0x16u);
  if ( Str && a3 )
  {
    v6 = -1;
    if ( a3 != -1 )
      v6 = a3 - (v7[0] == 45);
    result = _fptostr(&Str[v7[0] == 45], v6, Size + v7[1], (int)v7);
    if ( result )
      *Str = 0;
    else
      return _cftof2_l(Str, v7, a3, Size, 0, a5);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}
