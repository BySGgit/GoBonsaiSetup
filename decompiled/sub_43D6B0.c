int __usercall sub_43D6B0@<eax>(int a1@<eax>)
{
  if ( dword_4D7DF0 )
  {
    if ( dword_4D7DF0 == 1 )
    {
      *(_DWORD *)dword_4D7E20 = sub_43E630(a1);
      return 0;
    }
  }
  else
  {
    *(_DWORD *)dword_4D7E18 = sub_43E470(a1);
  }
  return 0;
}
