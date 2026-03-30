void *__cdecl sub_413C20()
{
  if ( (dword_4D8CF8 & 1) == 0 )
  {
    dword_4D8CF8 |= 1u;
    sub_413C20();
    if ( (dword_4D8CF8 & 1) == 0 )
    {
      dword_4D8CF8 |= 1u;
      sub_413C20();
    }
  }
  byte_4D82A5 = 1;
  byte_4D828C = 1;
  if ( (dword_4D8CF8 & 1) == 0 )
  {
    dword_4D8CF8 |= 1u;
    sub_413C20();
  }
  sub_403A90(9);
  return &unk_4D8CFC;
}
