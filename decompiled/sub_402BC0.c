void *__cdecl sub_402BC0()
{
  int v0; // eax
  int v1; // eax

  if ( (dword_4D7CF0 & 1) == 0 )
  {
    dword_4D7CF0 |= 1u;
    sub_402BC0();
    if ( (dword_4D7CF0 & 1) == 0 )
    {
      dword_4D7CF0 |= 1u;
      sub_402BC0();
    }
  }
  byte_4D829F = 1;
  byte_4D8244 = 1;
  if ( (dword_4D7CF0 & 1) == 0 )
  {
    dword_4D7CF0 |= 1u;
    sub_402BC0();
  }
  if ( (dword_4D7CEC & 1) == 0 )
  {
    dword_4D7CEC |= 1u;
    v0 = sub_4017D0();
    sub_401730(v0);
  }
  byte_4D8241 = 1;
  if ( (dword_4D7CEC & 1) == 0 )
  {
    dword_4D7CEC |= 1u;
    v1 = sub_4017D0();
    sub_401730(v1);
  }
  return &unk_4D7CF4;
}
