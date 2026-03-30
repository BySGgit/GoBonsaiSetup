void __userpurge _UnwindNestedFrames(
        struct _EXCEPTION_REGISTRATION_RECORD **a1@<ebx>,
        PVOID TargetFrame,
        PEXCEPTION_RECORD ExceptionRecord)
{
  RtlUnwind(TargetFrame, &_ReturnPoint_27112, ExceptionRecord, 0);
  ExceptionRecord->ExceptionFlags &= ~2u;
  *a1 = NtCurrentTeb()->NtTib.ExceptionList;
}
