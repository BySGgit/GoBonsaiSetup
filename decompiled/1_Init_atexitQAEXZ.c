void __thiscall _Init_atexit::~_Init_atexit(_Init_atexit *this)
{
  PVOID v1; // eax
  void (*v2)(void); // eax

  while ( (unsigned int)dword_4C9150 < 0xA )
  {
    v1 = dword_4D6EE0[dword_4C9150++];
    v2 = (void (*)(void))DecodePointer(v1);
    if ( v2 )
      v2();
  }
}
