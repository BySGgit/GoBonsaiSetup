int (__cdecl *__cdecl _fpmath(int a1))(int, char *Str, int, int, size_t Size, int)
{
  int (__cdecl *result)(int, char *, int, int, size_t, int); // eax

  result = _cfltcvt_init_0();
  if ( a1 )
    result = (int (__cdecl *)(int, char *, int, int, size_t, int))_setdefaultprecision();
  __asm { fnclex }
  return result;
}
