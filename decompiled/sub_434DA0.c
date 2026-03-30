int __usercall sub_434DA0@<eax>(int this@<ecx>, int a2@<eax>)
{
  int v2; // esi
  int v3; // edi
  int v4; // eax
  int v5; // edx

  *(_DWORD *)(this + 148) += a2;
  v2 = *(_DWORD *)(this + 156);
  v3 = *(_DWORD *)(this + 148);
  if ( v3 < v2 || (v4 = *(_DWORD *)(this + 160), v5 = *(_DWORD *)(this + 152), v4 - v2 <= v5) )
  {
    *(_DWORD *)(this + 148) = v2;
  }
  else if ( v5 + v3 > v4 )
  {
    *(_DWORD *)(this + 148) = v4 - v5;
    return sub_434D20(this);
  }
  return sub_434D20(this);
}
