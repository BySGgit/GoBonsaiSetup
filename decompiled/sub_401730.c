int __cdecl sub_401730(int a1)
{
  int v1; // eax
  int result; // eax
  int v3; // eax

  if ( (dword_4D7CEC & 1) == 0 )
  {
    dword_4D7CEC |= 1u;
    v1 = sub_4017D0();
    sub_401730(v1);
  }
  if ( !a1 )
    byte_4D829C = 1;
  result = 11 * a1;
  byte_4D8220[11 * a1] = 1;
  if ( (dword_4D7CEC & 1) == 0 )
  {
    dword_4D7CEC |= 1u;
    v3 = sub_4017D0();
    return sub_401730(v3);
  }
  return result;
}
