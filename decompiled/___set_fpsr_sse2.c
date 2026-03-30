int __cdecl __set_fpsr_sse2(unsigned int a1)
{
  int result; // eax

  result = 0;
  if ( dword_4DD054 )
  {
    if ( (a1 & 0x40) != 0 && dword_4C9CA8 )
      _mm_setcsr(a1);
    else
      _mm_setcsr(a1 & 0xFFFFFFBF);
  }
  return result;
}
