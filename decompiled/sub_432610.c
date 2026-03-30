int __thiscall sub_432610(_DWORD **this, int a2)
{
  int result; // eax

  result = **(this + 8);
  if ( result )
    *(_DWORD *)(result + 68) = a2;
  return result;
}
