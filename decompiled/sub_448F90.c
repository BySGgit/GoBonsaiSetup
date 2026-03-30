void *__fastcall sub_448F90(unsigned int a1)
{
  void *result; // eax
  char *v2; // [esp+0h] [ebp-10h] BYREF
  _DWORD pExceptionObject[3]; // [esp+4h] [ebp-Ch] BYREF

  result = 0;
  if ( a1 )
  {
    if ( a1 > 0x9249249 || (result = operator new(28 * a1)) == 0 )
    {
      v2 = 0;
      std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&v2);
      pExceptionObject[0] = &std::bad_alloc::`vftable';
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
    }
  }
  return result;
}
