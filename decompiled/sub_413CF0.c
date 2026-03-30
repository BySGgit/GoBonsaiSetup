int __usercall sub_413CF0@<eax>(int a1@<esi>)
{
  if ( !a1 )
    return 0;
  if ( (dword_4D7CF8 & 1) == 0 )
  {
    dword_4D7CF8 |= 1u;
    sub_4079C0();
  }
  if ( byte_4D8225[11 * *(_DWORD *)(a1 + 4)] )
    return a1;
  else
    return 0;
}
