unsigned int __cdecl _raise_exc(
        ULONG_PTR Arguments,
        unsigned int *a2,
        DWORD dwExceptionCode,
        int a4,
        float *a5,
        float *a6)
{
  return _raise_exc_ex(Arguments, a2, dwExceptionCode, a4, a5, a6, 0);
}
