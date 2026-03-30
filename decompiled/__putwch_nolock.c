wint_t __cdecl _putwch_nolock(wchar_t Character)
{
  DWORD v1; // ecx
  DWORD NumberOfCharsWritten; // [esp+0h] [ebp-4h] BYREF

  NumberOfCharsWritten = v1;
  if ( hConsoleOutput == (HANDLE)-2 )
    __initconout(NumberOfCharsWritten);
  if ( hConsoleOutput == (HANDLE)-1 || !WriteConsoleW(hConsoleOutput, &Character, 1u, &NumberOfCharsWritten, 0) )
    return -1;
  else
    return Character;
}
