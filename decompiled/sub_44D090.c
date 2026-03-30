int __thiscall sub_44D090(_DWORD *this)
{
  int result; // eax

  result = *(this - 4);
  *(_DWORD *)((char *)this + *(_DWORD *)(result + 4) - 16) = &std::wistream::`vftable';
  return result;
}
