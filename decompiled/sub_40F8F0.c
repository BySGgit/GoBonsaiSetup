void *__cdecl sub_40F8F0()
{
  int v0; // eax
  int v1; // eax

  if ( (dword_4D8CE8 & 1) == 0 )
  {
    dword_4D8CE8 |= 1u;
    sub_40F8F0();
    if ( (dword_4D8CE8 & 1) == 0 )
    {
      dword_4D8CE8 |= 1u;
      sub_40F8F0();
    }
  }
  byte_4D82A0 = 1;
  byte_4D8250 = 1;
  if ( (dword_4D8CE8 & 1) == 0 )
  {
    dword_4D8CE8 |= 1u;
    sub_40F8F0();
  }
  if ( (dword_4D7CEC & 1) == 0 )
  {
    dword_4D7CEC |= 1u;
    v0 = sub_4017D0();
    sub_401730(v0);
  }
  byte_4D824C = 1;
  if ( (dword_4D7CEC & 1) == 0 )
  {
    dword_4D7CEC |= 1u;
    v1 = sub_4017D0();
    sub_401730(v1);
  }
  return &unk_4D8CEC;
}
