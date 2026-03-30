void __stdcall __noreturn _CxxThrowException(void *pExceptionObject, _ThrowInfo *pThrowInfo)
{
  DWORD dwExceptionCode[8]; // [esp+8h] [ebp-20h] BYREF

  qmemcpy(dwExceptionCode, &unk_4736A4, sizeof(dwExceptionCode));
  dwExceptionCode[6] = (DWORD)pExceptionObject;
  dwExceptionCode[7] = (DWORD)pThrowInfo;
  if ( pThrowInfo && (pThrowInfo->attributes & 8) != 0 )
    dwExceptionCode[5] = 26820608;
  RaiseException(dwExceptionCode[0], dwExceptionCode[1], dwExceptionCode[4], &dwExceptionCode[5]);
}
