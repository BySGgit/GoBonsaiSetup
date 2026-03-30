int sub_470360()
{
  char *v0; // eax
  char *v2; // [esp+0h] [ebp-10h] BYREF
  _DWORD pExceptionObject[3]; // [esp+4h] [ebp-Ch] BYREF

  v0 = (char *)operator new(0xCu);
  if ( !v0 )
  {
    v2 = 0;
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&v2);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  dword_4D866C = v0;
  *(_DWORD *)v0 = v0;
  *((_DWORD *)dword_4D866C + 1) = dword_4D866C;
  return atexit(sub_472120);
}
