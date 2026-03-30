int __usercall _ctrandisp2@<eax>(double a1@<st1>, double a2@<st0>, double a3, double a4)
{
  _fload(a3);
  _fload(a4);
  _trandisp2(a2, a1);
  return ctranexit();
}
