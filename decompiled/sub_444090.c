void __thiscall sub_444090(_DWORD *this)
{
  _DWORD *v2; // eax
  char *v3; // [esp+4h] [ebp-10h] BYREF
  _DWORD pExceptionObject[3]; // [esp+8h] [ebp-Ch] BYREF

  *(this + 1) = 0;
  v2 = operator new(0xCu);
  if ( !v2 )
  {
    v3 = 0;
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&v3);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  *this = v2;
  *v2 = v2;
  *(_DWORD *)(*this + 4) = *this;
}
