void __cdecl __noreturn _invoke_watson(
        const wchar_t *Expression,
        const wchar_t *FunctionName,
        const wchar_t *FileName,
        unsigned int LineNo,
        uintptr_t Reserved)
{
  int v5; // edi
  HANDLE CurrentProcess; // eax

  _call_reportfault(v5, -1073740777, 2, -1073740777, 1);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(CurrentProcess, 0xC0000417);
}
