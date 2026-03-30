void __cdecl __noreturn _inconsistency()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))DecodePointer(dword_4D72B8);
  if ( v0 )
    v0();
  terminate();
}
