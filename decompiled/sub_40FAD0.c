void *__cdecl sub_40FAD0()
{
  if ( (dword_4D8CD8 & 1) == 0 )
  {
    dword_4D8CD8 |= 1u;
    sub_40FAD0();
    if ( (dword_4D8CD8 & 1) == 0 )
    {
      dword_4D8CD8 |= 1u;
      sub_40FAD0();
    }
  }
  byte_4D82A3 = 1;
  byte_4D8274 = 1;
  if ( (dword_4D8CD8 & 1) == 0 )
  {
    dword_4D8CD8 |= 1u;
    sub_40FAD0();
  }
  sub_403A90(7);
  return &unk_4D8CDC;
}
