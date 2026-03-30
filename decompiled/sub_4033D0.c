int __usercall sub_4033D0@<eax>(const void *a1@<eax>, int a2@<ecx>)
{
  *(_DWORD *)(a2 + 20) = 7;
  *(_DWORD *)(a2 + 16) = 0;
  *(_WORD *)a2 = 0;
  sub_4032D0(a1, a2, wcslen((const unsigned __int16 *)a1));
  return a2;
}
