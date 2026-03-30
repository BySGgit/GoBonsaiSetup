FARPROC __cdecl sub_438A80(unsigned __int8 a1)
{
  FARPROC result; // eax
  HMODULE LibraryW; // eax

  result = (FARPROC)dword_4D8DBC;
  if ( dword_4D8DBC )
    return (FARPROC)((int (__stdcall *)(_DWORD))result)(a1);
  LibraryW = LoadLibraryW(L"xinput1_3.dll");
  if ( LibraryW )
  {
    result = GetProcAddress(LibraryW, "XInputEnable");
    dword_4D8DBC = (int)result;
  }
  else
  {
    result = (FARPROC)dword_4D8DBC;
  }
  if ( result )
    return (FARPROC)((int (__stdcall *)(_DWORD))result)(a1);
  return result;
}
