BOOL __cdecl _IsNonwritableInCurrentImage(int a1)
{
  int PESection; // eax

  return _ValidateImageBase(0x400000)
      && (PESection = _FindPESection(0x400000, a1 - 0x400000)) != 0
      && *(int *)(PESection + 36) >= 0;
}
