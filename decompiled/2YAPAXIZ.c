void *__cdecl operator new(size_t Size)
{
  void *result; // eax
  _DWORD pExceptionObject[3]; // [esp+0h] [ebp-10h] BYREF
  char *v3; // [esp+Ch] [ebp-4h] BYREF

  while ( 1 )
  {
    result = malloc(Size);
    if ( result )
      break;
    if ( !_callnewh(Size) )
    {
      if ( (dword_4D6F18 & 1) == 0 )
      {
        dword_4D6F18 |= 1u;
        v3 = "bad allocation";
        std::exception::exception((const char **)dword_4D6F0C, (const char *const *)&v3, 1);
        dword_4D6F0C[0] = &std::bad_alloc::`vftable';
        atexit(sub_472724);
      }
      std::exception::exception((std::exception *)pExceptionObject, (const struct exception *)dword_4D6F0C);
      pExceptionObject[0] = &std::bad_alloc::`vftable';
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
    }
  }
  return result;
}
