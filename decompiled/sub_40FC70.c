int __usercall sub_40FC70@<eax>(int a1@<esi>)
{
  if ( !a1 )
    return 0;
  if ( (dword_4D8CD8 & 1) == 0 )
  {
    dword_4D8CD8 |= 1u;
    sub_40FAD0();
  }
  if ( byte_4D8227[11 * *(_DWORD *)(a1 + 4)] )
    return a1;
  else
    return 0;
}
