int __cdecl sub_403A90(int a1)
{
  int v1; // eax
  int v2; // eax

  if ( (dword_4D7CF8 & 1) == 0 )
  {
    dword_4D7CF8 |= 1u;
    v1 = sub_403B40();
    sub_403A90(v1);
  }
  if ( a1 == 5 )
    byte_4D82A1 = 1;
  byte_4D8225[11 * a1] = 1;
  if ( (dword_4D7CF8 & 1) == 0 )
  {
    dword_4D7CF8 |= 1u;
    v2 = sub_403B40();
    sub_403A90(v2);
  }
  return sub_401730(a1);
}
