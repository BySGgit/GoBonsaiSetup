int __cdecl sub_4017D0()
{
  int v0; // eax

  if ( (dword_4D7CEC & 1) == 0 )
  {
    dword_4D7CEC |= 1u;
    v0 = sub_4017D0();
    sub_401730(v0);
  }
  return 0;
}
