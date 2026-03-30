void __cdecl sub_4724C0()
{
  void *v0; // esi

  if ( dword_4D7F04 )
  {
    v0 = dword_4D7F04;
    sub_419520((int)dword_4D7F04);
    operator delete(v0);
    dword_4D7F04 = 0;
  }
}
