int __cdecl tolower(int C)
{
  int result; // eax

  if ( dword_4D6F30 )
    return _tolower_l(C, 0);
  result = C;
  if ( (unsigned int)(C - 65) <= 0x19 )
    return C + 32;
  return result;
}
