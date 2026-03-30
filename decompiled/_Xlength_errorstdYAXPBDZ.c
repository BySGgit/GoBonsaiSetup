void __cdecl __noreturn std::_Xlength_error(char *a1)
{
  _DWORD pExceptionObject[3]; // [esp+0h] [ebp-Ch] BYREF

  std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&a1);
  pExceptionObject[0] = &std::length_error::`vftable';
  _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI3_AVlength_error_std__);
}
