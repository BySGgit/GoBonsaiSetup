int __thiscall sub_432920(_DWORD *this, int a2)
{
  int result; // eax

  result = *(_DWORD *)(*(this + 8) + 4);
  if ( result )
    *(_DWORD *)(result + 68) = a2;
  return result;
}
