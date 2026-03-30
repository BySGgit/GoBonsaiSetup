int __usercall sub_413D70@<eax>(int a1@<esi>)
{
  if ( !a1 )
    return 0;
  if ( (dword_4D8CF8 & 1) == 0 )
  {
    dword_4D8CF8 |= 1u;
    sub_413C20();
  }
  if ( byte_4D8229[11 * *(_DWORD *)(a1 + 4)] )
    return a1;
  else
    return 0;
}
