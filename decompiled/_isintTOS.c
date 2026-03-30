int __usercall isintTOS@<eax>(double a1@<st0>)
{
  _ST6 = a1;
  __asm { frndint }
  if ( _ST6 != a1 )
    return notanint();
  _ST5 = a1 * 0.5;
  __asm { frndint }
  if ( _ST5 == a1 * 0.5 )
    return evenint();
  else
    return isintTOSret();
}
