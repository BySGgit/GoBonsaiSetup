LONG __stdcall __CxxUnhandledExceptionFilter(struct _EXCEPTION_POINTERS *ExceptionInfo)
{
  PEXCEPTION_RECORD ExceptionRecord; // eax
  ULONG_PTR v2; // eax

  ExceptionRecord = ExceptionInfo->ExceptionRecord;
  if ( ExceptionInfo->ExceptionRecord->ExceptionCode == -529697949 && ExceptionRecord->NumberParameters == 3 )
  {
    v2 = ExceptionRecord->ExceptionInformation[0];
    if ( v2 == 429065504 || v2 == 429065505 || v2 == 429065506 || v2 == 26820608 )
      terminate();
  }
  return 0;
}
