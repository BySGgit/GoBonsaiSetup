int __cdecl _vsnprintf_helper(
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
  File._cnt = 0x7FFFFFFF;
  if ( a3 <= 0x7FFFFFFF )
    File._cnt = a3;
  File._flag = 66;
  File._base = a2;
  File._ptr = a2;
  result = a1(&File, a4, a5, a6);
  v9 = result;
  if ( a2 )
  {
    if ( result >= 0 )
    {
      if ( --File._cnt >= 0 )
      {
        *File._ptr = 0;
        return v9;
      }
      if ( _flsbuf(0, &File) != -1 )
        return v9;
    }
    v7 = File._cnt < 0;
    a2[a3 - 1] = 0;
    return !v7 - 2;
  }
  return result;
}
