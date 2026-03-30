void __cdecl sub_4724F0()
{
  void *v0; // esi

  if ( dword_4D7F18 )
  {
    v0 = dword_4D7F18;
    sub_428790((int)dword_4D7F18);
    operator delete(v0);
    dword_4D7F18 = 0;
  }
}
