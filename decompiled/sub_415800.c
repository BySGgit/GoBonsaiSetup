void *__cdecl sub_415800()
{
  if ( (dword_4D8DA0 & 1) == 0 )
  {
    dword_4D8DA0 |= 1u;
    sub_415800();
    if ( (dword_4D8DA0 & 1) == 0 )
    {
      dword_4D8DA0 |= 1u;
      sub_415800();
    }
  }
  byte_4D82A2 = 1;
  byte_4D8268 = 1;
  if ( (dword_4D8DA0 & 1) == 0 )
  {
    dword_4D8DA0 |= 1u;
    sub_415800();
  }
  sub_403A90(6);
  return &unk_4D8DA4;
}
