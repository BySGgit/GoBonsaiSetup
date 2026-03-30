int __usercall sub_43D6E0@<eax>(int a1@<eax>)
{
  unsigned int v1; // esi
  int v2; // eax

  v1 = *(_DWORD *)dword_4D7E00 & 0xFFFFFF0F;
  v2 = sub_43E880(a1);
  if ( (v2 & 0x10) != 0 )
    v2 |= 0x40u;
  *(_DWORD *)dword_4D7E00 = v1 | v2;
  return 0;
}
