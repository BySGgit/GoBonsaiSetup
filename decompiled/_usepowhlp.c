double __usercall usepowhlp@<st0>(double a1@<st1>, double a2@<st0>)
{
  int v3; // eax
  double result; // st7
  double *v5; // [esp+10h] [ebp-7Ch]
  double v6[15]; // [esp+14h] [ebp-78h] BYREF

  _ESI = v6;
  v5 = v6;
  __asm { fsave   byte ptr [esi+8] }
  v3 = _powhlp(a2, a1, (int)v6);
  __asm { frstor  byte ptr [esi+8] }
  result = v6[0];
  if ( v3 )
    _rttosnpopde();
  return result;
}
