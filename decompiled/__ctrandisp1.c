int __usercall _ctrandisp1@<eax>(double a1@<st0>, double a2)
{
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _fload(a2);
  _trandisp1(a1);
  return ctranexit((int)&savedregs);
}
