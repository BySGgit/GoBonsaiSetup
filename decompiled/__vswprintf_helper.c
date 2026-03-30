int __cdecl _vswprintf_helper(
        int (__cdecl *a1)(FILE *, int, int, int),
        char *a2,
        unsigned int a3,
        int a4,
        int a5,
        int a6)
{
  int result; // eax
  bool v7; // sf
  FILE File; // [esp+8h] [ebp-20h] BYREF
  int v9; // [esp+3Ch] [ebp+14h]

  memset(&File, 0, sizeof(File));
  if ( !a4 || a3 && !a2 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  File._flag = 66;
  File._base = a2;
  File._ptr = a2;
  if ( a3 <= 0x3FFFFFFF )
    File._cnt = 2 * a3;
  else
    File._cnt = 0x7FFFFFFF;
  result = a1(&File, a4, a5, a6);
  v9 = result;
  if ( a2 )
  {
    if ( result >= 0 )
    {
      if ( --File._cnt >= 0 )
      {
        *File._ptr++ = 0;
LABEL_13:
        if ( --File._cnt >= 0 )
        {
          *File._ptr = 0;
          return v9;
        }
        if ( _flsbuf(0, &File) != -1 )
          return v9;
        goto LABEL_17;
      }
      if ( _flsbuf(0, &File) != -1 )
        goto LABEL_13;
    }
LABEL_17:
    v7 = File._cnt < 0;
    *(_WORD *)&a2[2 * a3 - 2] = 0;
    return !v7 - 2;
  }
  return result;
}
