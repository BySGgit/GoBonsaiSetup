int __fastcall sub_437460(int this, int a2)
{
  int v2; // esi
  int v3; // edi
  int v4; // eax

  v2 = *(_DWORD *)(this + 156);
  v3 = *(_DWORD *)(this + 148);
  *(_DWORD *)(this + 152) = a2;
  if ( v3 < v2 || (v4 = *(_DWORD *)(this + 160), v4 - v2 <= a2) )
  {
    *(_DWORD *)(this + 148) = v2;
  }
  else if ( a2 + v3 > v4 )
  {
    *(_DWORD *)(this + 148) = v4 - a2;
    return sub_434D20(this);
  }
  return sub_434D20(this);
}
