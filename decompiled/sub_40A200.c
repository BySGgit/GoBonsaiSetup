void *__cdecl sub_40A200()
{
  int v0; // eax
  int v1; // eax

  if ( (dword_4D8CC8 & 1) == 0 )
  {
    dword_4D8CC8 |= 1u;
    sub_40A200();
    if ( (dword_4D8CC8 & 1) == 0 )
    {
      dword_4D8CC8 |= 1u;
      sub_40A200();
    }
  }
  byte_4D829D = 1;
  byte_4D822C = 1;
  if ( (dword_4D8CC8 & 1) == 0 )
  {
    dword_4D8CC8 |= 1u;
    sub_40A200();
  }
  if ( (dword_4D7CEC & 1) == 0 )
  {
    dword_4D7CEC |= 1u;
    v0 = sub_4017D0();
    sub_401730(v0);
  }
  byte_4D822B = 1;
  if ( (dword_4D7CEC & 1) == 0 )
  {
    dword_4D7CEC |= 1u;
    v1 = sub_4017D0();
    sub_401730(v1);
  }
  return &unk_4D8CCC;
}
