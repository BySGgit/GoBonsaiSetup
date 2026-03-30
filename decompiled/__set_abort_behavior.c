unsigned int __cdecl _set_abort_behavior(unsigned int Flags, unsigned int Mask)
{
  unsigned int result; // eax

  result = dword_4C93E8;
  dword_4C93E8 = Mask & Flags | dword_4C93E8 & ~Mask;
  return result;
}
