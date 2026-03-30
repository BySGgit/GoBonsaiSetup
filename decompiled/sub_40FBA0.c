void *__cdecl sub_40FBA0()
{
  if ( (dword_4D8CE0 & 1) == 0 )
  {
    dword_4D8CE0 |= 1u;
    sub_40FBA0();
    if ( (dword_4D8CE0 & 1) == 0 )
    {
      dword_4D8CE0 |= 1u;
      sub_40FBA0();
    }
  }
  byte_4D82A6 = 1;
  byte_4D8298 = 1;
  if ( (dword_4D8CE0 & 1) == 0 )
  {
    dword_4D8CE0 |= 1u;
    sub_40FBA0();
  }
  sub_403A90(10);
  return &unk_4D8CE4;
}
