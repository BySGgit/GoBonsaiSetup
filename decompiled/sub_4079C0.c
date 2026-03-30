void *__cdecl sub_4079C0()
{
  int v0; // eax
  int v1; // eax

  if ( (dword_4D7CF8 & 1) == 0 )
  {
    dword_4D7CF8 |= 1u;
    sub_4079C0();
    if ( (dword_4D7CF8 & 1) == 0 )
    {
      dword_4D7CF8 |= 1u;
      sub_4079C0();
    }
  }
  byte_4D82A1 = 1;
  byte_4D825C = 1;
  if ( (dword_4D7CF8 & 1) == 0 )
  {
    dword_4D7CF8 |= 1u;
    sub_4079C0();
  }
  if ( (dword_4D7CEC & 1) == 0 )
  {
    dword_4D7CEC |= 1u;
    v0 = sub_4017D0();
    sub_401730(v0);
  }
  byte_4D8257 = 1;
  if ( (dword_4D7CEC & 1) == 0 )
  {
    dword_4D7CEC |= 1u;
    v1 = sub_4017D0();
    sub_401730(v1);
  }
  return &unk_4D7CFC;
}
