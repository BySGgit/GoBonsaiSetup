int __thiscall sub_4333E0(_DWORD **this, int a2)
{
  int v2; // eax
  int result; // eax

  v2 = **(this + 8);
  if ( v2 )
    *(_DWORD *)(v2 + 68) = a2;
  result = (*(this + 8))[2];
  if ( result )
    *(_DWORD *)(result + 68) = a2;
  return result;
}
