_DWORD *__stdcall sub_44ECA0(char *a1, int a2, const void *a3)
{
  _DWORD *result; // eax
  int v4; // edx
  _DWORD pExceptionObject[3]; // [esp+0h] [ebp-Ch] BYREF

  result = operator new(0x30u);
  if ( !result )
  {
    a1 = 0;
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&a1);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  v4 = a2;
  *result = a1;
  result[1] = v4;
  if ( result != (_DWORD *)-8 )
    qmemcpy(result + 2, a3, 0x28u);
  return result;
}
