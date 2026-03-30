void (__noreturn *_initp_misc_cfltcvt_tab())()
{
  unsigned int i; // edi
  void (__noreturn *result)(); // eax

  for ( i = 0; i < 10; ++i )
  {
    result = (void (__noreturn *)())EncodePointer(off_4C9ED0[i]);
    off_4C9ED0[i] = result;
  }
  return result;
}
