int __usercall sub_44A600@<eax>(char *a1@<eax>, int a2@<ecx>)
{
  char *v3; // eax

  v3 = sub_44BC80(a1, (char *)L"v0.276", 6u);
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 7;
  *(_WORD *)a2 = 0;
  sub_444AE0(v3, a2);
  return a2;
}
