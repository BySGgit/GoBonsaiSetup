// positive sp value has been detected, the output may be wrong!
void __usercall _ffexpm1(char a1@<ch>, int _EBP@<ebp>)
{
  __asm
  {
    fld     st
    fabs
    fld     ds:tbyte_4C00EE
    fcompp
    fstsw   word ptr [ebp-0A0h]
  }
  if ( (*(_BYTE *)(_EBP - 159) & 0x41) != 0 )
  {
    __asm
    {
      ftst
      fstsw   word ptr [ebp-0A0h]
    }
    if ( (*(_BYTE *)(_EBP - 159) & 1) != 0 )
    {
      *(_BYTE *)(_EBP - 144) = 4;
      __asm
      {
        fstp    st
        fldz
      }
    }
    else
    {
      __asm
      {
        fstp    st
        fld     ds:tbyte_4C00D0
      }
      if ( a1 )
        __asm { fchs }
      expbigret();
    }
  }
  else
  {
    __asm
    {
      fld     st
      frndint
      ftst
      fstsw   word ptr [ebp-0A0h]
    }
    __asm
    {
      fxch    st(1)
      fsub    st, st(1)
      ftst
      fstsw   word ptr [ebp-0A0h]
      fabs
      f2xm1
    }
  }
}
