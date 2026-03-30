void __fastcall _EH4_GlobalUnwind2(PVOID TargetFrame, PEXCEPTION_RECORD ExceptionRecord)
{
  RtlUnwind(TargetFrame, &ReturnPoint, ExceptionRecord, 0);
}
