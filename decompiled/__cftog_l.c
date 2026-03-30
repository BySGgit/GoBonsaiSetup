int __cdecl _cftog_l(_DWORD *a1, char *Str, int a3, signed int Size, int a5, struct localeinfo_struct *a6)
{
  int result; // eax
  int v7; // ecx
  int v8; // ebx
  BOOL v9; // eax
  char *v10; // edi
  int v11; // [esp+8h] [ebp-2Ch] BYREF
  int v12; // [esp+Ch] [ebp-28h]
  int v13[6]; // [esp+18h] [ebp-1Ch] BYREF

  _fltout2(*a1, a1[1], (int)&v11, (int)v13, 0x16u);
  if ( Str && (v7 = a3) != 0 )
  {
    v8 = v12 - 1;
    v9 = v11 == 45;
    v10 = &Str[v9];
    if ( a3 != -1 )
      v7 = a3 - v9;
    result = _fptostr(v10, v7, Size, (int)&v11);
    if ( result )
    {
      *Str = 0;
    }
    else if ( v12 - 1 < -4 || v12 - 1 >= Size )
    {
      return _cftoe2_l(Str, a3, Size, a5, (int)&v11, 1, a6);
    }
    else
    {
      if ( v8 < v12 - 1 )
        v10[strlen(v10) - 1] = 0;
      return _cftof2_l(Str, &v11, a3, Size, 1, a6);
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}
