void __cdecl __noreturn __report_gsfailure()
{
  int v0; // eax
  int v1; // edx
  int v2; // ecx
  int v3; // ebx
  int v4; // edi
  int v5; // esi
  unsigned int v6; // kr00_4
  HANDLE CurrentProcess; // eax
  int vars0; // [esp+328h] [ebp+0h]
  int retaddr; // [esp+32Ch] [ebp+4h]
  char v10; // [esp+330h] [ebp+8h] BYREF

  dword_4D7048 = v0;
  dword_4D7044 = v2;
  dword_4D7040 = v1;
  dword_4D703C = v3;
  dword_4D7038 = v5;
  dword_4D7034 = v4;
  word_4D7060 = __SS__;
  word_4D7054 = __CS__;
  word_4D7030 = __DS__;
  word_4D702C = __ES__;
  word_4D7028 = __FS__;
  word_4D7024 = __GS__;
  v6 = __readeflags();
  dword_4D7058 = v6;
  dword_4D704C = vars0;
  dword_4D7050 = retaddr;
  dword_4D705C = (int)&v10;
  dword_4D6F98 = 65537;
  dword_4D6F4C = retaddr;
  dword_4D6F40 = -1073740791;
  dword_4D6F44 = 1;
  dword_4D6F90 = IsDebuggerPresent();
  sub_462469();
  SetUnhandledExceptionFilter(0);
  UnhandledExceptionFilter((struct _EXCEPTION_POINTERS *)&ExceptionInfo);
  if ( !dword_4D6F90 )
    sub_462469();
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(CurrentProcess, 0xC0000409);
}
