void *__stdcall sub_44C980(size_t Size)
{
  void *result; // eax
  _DWORD pExceptionObject[3]; // [esp+0h] [ebp-Ch] BYREF

  result = 0;
  if ( Size )
  {
    result = operator new(Size);
    if ( !result )
    {
      Size = 0;
      std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&Size);
      pExceptionObject[0] = &std::bad_alloc::`vftable';
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
    }
  }
  return result;
}
