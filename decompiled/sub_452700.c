int __stdcall sub_452700(int a1, int a2, int a3, int a4)
{
  int result; // eax

  if ( a2 == 1 )
    return sub_425B80();
  if ( a2 == 2 )
    return sub_425E90();
  result = a2 - 3;
  if ( a2 == 3 )
  {
    result = byte_4D59C0 == 0;
    byte_4D59C0 = result;
    if ( (_BYTE)result )
      return sub_4392B0((int)&dword_4D53C8);
  }
  return result;
}
