int __usercall sub_435400@<eax>(int this@<ecx>, int a2@<eax>)
{
  int v2; // esi
  int v3; // edx

  v2 = *(_DWORD *)(this + 148);
  *(_DWORD *)(this + 156) = 0;
  *(_DWORD *)(this + 160) = a2;
  if ( v2 < 0 || (v3 = *(_DWORD *)(this + 152), a2 <= v3) )
  {
    *(_DWORD *)(this + 148) = 0;
  }
  else if ( v3 + v2 > a2 )
  {
    *(_DWORD *)(this + 148) = a2 - v3;
    return sub_434D20(this);
  }
  return sub_434D20(this);
}
