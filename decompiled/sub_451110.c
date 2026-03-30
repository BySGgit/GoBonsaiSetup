char *__stdcall sub_451110(char *a1)
{
  _DWORD *v1; // eax
  _DWORD pExceptionObject[6]; // [esp+Ch] [ebp-18h] BYREF

  byte_4D8C0C = *a1;
  dword_4D8C14 = 0;
  v1 = operator new(0x10u);
  if ( !v1 )
  {
    a1 = 0;
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&a1);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  dword_4D8C10 = (int)v1;
  *v1 = v1;
  *(_DWORD *)(dword_4D8C10 + 4) = dword_4D8C10;
  pExceptionObject[5] = 1;
  dword_4D8C1C = 0;
  dword_4D8C20 = 0;
  dword_4D8C24 = 0;
  flt_4D8C34 = 1.0;
  a1 = (char *)dword_4D8C10;
  sub_402F60(0x10u, &dword_4D8C1C, 0, (void **)&a1);
  dword_4D8C2C = 7;
  dword_4D8C30 = 8;
  return &byte_4D8C0C;
}
