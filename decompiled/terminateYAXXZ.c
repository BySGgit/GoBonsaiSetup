void __cdecl __noreturn terminate()
{
  void (*v0)(void); // eax

  v0 = *(void (**)(void))(_getptd() + 120);
  if ( v0 )
    v0();
  abort();
}
