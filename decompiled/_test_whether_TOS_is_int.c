void __usercall test_whether_TOS_is_int(double a1@<st0>)
{
  _ST6 = a1;
  __asm { frndint }
  if ( _ST6 == a1 )
  {
    _ST6 = a1 * dbl_4D6CA0;
    __asm { frndint }
  }
}
