void __cdecl __noreturn std::_Xout_of_range(char *a1)
{
  _DWORD pExceptionObject[3]; // [esp+0h] [ebp-Ch] BYREF

  std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&a1);
  pExceptionObject[0] = &std::out_of_range::`vftable';
  _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI3_AVout_of_range_std__);
}
