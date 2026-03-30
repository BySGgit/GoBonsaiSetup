struct std::_Locinfo *__userpurge sub_44D440@<eax>(const char *a1@<edi>, struct std::_Locinfo *a2)
{
  char *v3; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD pExceptionObject[3]; // [esp+10h] [ebp-18h] BYREF
  int v5; // [esp+24h] [ebp-4h]

  std::_Lockit::_Lockit(a2, 0);
  v5 = 0;
  *((_DWORD *)a2 + 1) = 0;
  *((_BYTE *)a2 + 8) = 0;
  *((_DWORD *)a2 + 3) = 0;
  *((_BYTE *)a2 + 16) = 0;
  *((_DWORD *)a2 + 5) = 0;
  *((_BYTE *)a2 + 24) = 0;
  *((_DWORD *)a2 + 7) = 0;
  *((_BYTE *)a2 + 32) = 0;
  LOBYTE(v5) = 4;
  if ( !a1 )
  {
    v3 = "bad locale name";
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&v3);
    pExceptionObject[0] = &std::runtime_error::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVruntime_error_std__);
  }
  std::_Locinfo::_Locinfo_ctor(a2, a1);
  return a2;
}
