_DWORD *__userpurge sub_403230@<eax>(_DWORD *a1@<esi>, char *a2, int a3)
{
  _DWORD *result; // eax
  int v4; // edx
  _DWORD pExceptionObject[3]; // [esp+0h] [ebp-Ch] BYREF

  result = operator new(0x10u);
  if ( !result )
  {
    a2 = 0;
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&a2);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  v4 = a3;
  *result = a2;
  result[1] = v4;
  if ( result != (_DWORD *)-8 )
  {
    result[2] = *a1;
    result[3] = a1[1];
  }
  return result;
}
