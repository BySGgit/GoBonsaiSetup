int __usercall sub_40FCF0@<eax>(int a1@<esi>)
{
  if ( !a1 )
    return 0;
  if ( (dword_4D8CD0 & 1) == 0 )
  {
    dword_4D8CD0 |= 1u;
    sub_40FA00();
  }
  if ( byte_4D8228[11 * *(_DWORD *)(a1 + 4)] )
    return a1;
  else
    return 0;
}
