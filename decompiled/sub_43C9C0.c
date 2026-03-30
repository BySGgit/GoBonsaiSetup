int __stdcall sub_43C9C0(int a1)
{
  int result; // eax

  if ( dword_4D7DF0 )
  {
    result = dword_4D7DF0 - 1;
    if ( dword_4D7DF0 == 1 )
    {
      dword_4D7E08 = 0;
      dword_4D7E0C = 1;
      return result;
    }
  }
  else
  {
    *(_DWORD *)dword_4D7E34 = sub_43DFD0(a1);
  }
  return 0;
}
