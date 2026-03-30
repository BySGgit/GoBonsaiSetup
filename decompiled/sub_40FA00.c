void *__cdecl sub_40FA00()
{
  if ( (dword_4D8CD0 & 1) == 0 )
  {
    dword_4D8CD0 |= 1u;
    sub_40FA00();
    if ( (dword_4D8CD0 & 1) == 0 )
    {
      dword_4D8CD0 |= 1u;
      sub_40FA00();
    }
  }
  byte_4D82A4 = 1;
  byte_4D8280 = 1;
  if ( (dword_4D8CD0 & 1) == 0 )
  {
    dword_4D8CD0 |= 1u;
    sub_40FA00();
  }
  sub_403A90(8);
  return &unk_4D8CD4;
}
