void __cdecl __noreturn sub_44DDA0(char *a1)
{
  int v1; // ecx
  int v2; // eax
  int (__thiscall **v3)(void *, char); // edi
  int (__thiscall **v4)(void *, char); // edi
  int (__thiscall **v5)(void *, char); // edi
  _DWORD pExceptionObject[3]; // [esp+Ch] [ebp-14h] BYREF
  int v7; // [esp+18h] [ebp-8h]
  int (__thiscall **v8)(void *, char); // [esp+1Ch] [ebp-4h]

  if ( (_BYTE)a1 )
    _CxxThrowException(0, 0);
  v2 = *(_DWORD *)(v1 + 12) & *(_DWORD *)(v1 + 16);
  if ( (v2 & 4) != 0 )
  {
    v3 = sub_452A4C();
    a1 = "ios_base::badbit set";
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&a1);
    v7 = 1;
    v8 = v3;
    pExceptionObject[0] = &std::ios_base::failure::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI4_AVfailure_ios_base_std__);
  }
  if ( (v2 & 2) != 0 )
  {
    v4 = sub_452A4C();
    a1 = "ios_base::failbit set";
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&a1);
    v7 = 1;
    v8 = v4;
    pExceptionObject[0] = &std::ios_base::failure::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI4_AVfailure_ios_base_std__);
  }
  v5 = sub_452A4C();
  a1 = "ios_base::eofbit set";
  std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&a1);
  v7 = 1;
  v8 = v5;
  pExceptionObject[0] = &std::ios_base::failure::`vftable';
  _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI4_AVfailure_ios_base_std__);
}
