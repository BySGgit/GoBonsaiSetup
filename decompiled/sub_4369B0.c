void sub_4369B0()
{
  HMODULE LibraryW; // eax
  HRESULT (__stdcall *ScriptApplyDigitSubstitution)(const SCRIPT_DIGITSUBSTITUTE *, SCRIPT_CONTROL *, SCRIPT_STATE *); // eax
  HRESULT (__stdcall *ScriptStringAnalyse)(HDC, const void *, int, int, int, DWORD, int, SCRIPT_CONTROL *, SCRIPT_STATE *, const int *, SCRIPT_TABDEF *, const BYTE *, SCRIPT_STRING_ANALYSIS *); // eax
  HRESULT (__stdcall *ScriptStringCPtoX)(SCRIPT_STRING_ANALYSIS, int, BOOL, int *); // eax
  HRESULT (__stdcall *ScriptStringXtoCP)(SCRIPT_STRING_ANALYSIS, int, int *, int *); // eax
  HRESULT (__stdcall *ScriptStringFree)(SCRIPT_STRING_ANALYSIS *); // eax
  const SCRIPT_LOGATTR *(__stdcall *ScriptString_pLogAttr)(SCRIPT_STRING_ANALYSIS); // eax
  const int *(__stdcall *ScriptString_pcOutChars)(SCRIPT_STRING_ANALYSIS); // eax

  if ( !hModule )
  {
    LibraryW = LoadLibraryW(L"usp10.dll");
    hModule = LibraryW;
    if ( LibraryW )
    {
      ScriptApplyDigitSubstitution = (HRESULT (__stdcall *)(const SCRIPT_DIGITSUBSTITUTE *, SCRIPT_CONTROL *, SCRIPT_STATE *))GetProcAddress(LibraryW, "ScriptApplyDigitSubstitution");
      if ( ScriptApplyDigitSubstitution )
        off_4D5244 = (int (__stdcall *)(int, int, int))ScriptApplyDigitSubstitution;
      ScriptStringAnalyse = (HRESULT (__stdcall *)(HDC, const void *, int, int, int, DWORD, int, SCRIPT_CONTROL *, SCRIPT_STATE *, const int *, SCRIPT_TABDEF *, const BYTE *, SCRIPT_STRING_ANALYSIS *))GetProcAddress(hModule, "ScriptStringAnalyse");
      if ( ScriptStringAnalyse )
        off_4D5248 = (int (__stdcall *)(int, int, int, int, int, int, int, int, int, int, int, int, int))ScriptStringAnalyse;
      ScriptStringCPtoX = (HRESULT (__stdcall *)(SCRIPT_STRING_ANALYSIS, int, BOOL, int *))GetProcAddress(
                                                                                             hModule,
                                                                                             "ScriptStringCPtoX");
      if ( ScriptStringCPtoX )
        off_4D524C[0] = (int (__stdcall *)(int, int, int, int))ScriptStringCPtoX;
      ScriptStringXtoCP = (HRESULT (__stdcall *)(SCRIPT_STRING_ANALYSIS, int, int *, int *))GetProcAddress(
                                                                                              hModule,
                                                                                              "ScriptStringXtoCP");
      if ( ScriptStringXtoCP )
        off_4D5250 = (int (__stdcall *)(int, int, int, int))ScriptStringXtoCP;
      ScriptStringFree = (HRESULT (__stdcall *)(SCRIPT_STRING_ANALYSIS *))GetProcAddress(hModule, "ScriptStringFree");
      if ( ScriptStringFree )
        off_4D5254[0] = (int (__stdcall *)(int))ScriptStringFree;
      ScriptString_pLogAttr = (const SCRIPT_LOGATTR *(__stdcall *)(SCRIPT_STRING_ANALYSIS))GetProcAddress(
                                                                                             hModule,
                                                                                             "ScriptString_pLogAttr");
      if ( ScriptString_pLogAttr )
        off_4D5258[0] = (int (__stdcall *)(int))ScriptString_pLogAttr;
      ScriptString_pcOutChars = (const int *(__stdcall *)(SCRIPT_STRING_ANALYSIS))GetProcAddress(
                                                                                    hModule,
                                                                                    "ScriptString_pcOutChars");
      if ( ScriptString_pcOutChars )
        off_4D525C = (int (__stdcall *)(int))ScriptString_pcOutChars;
    }
  }
}
