int __thiscall sub_4443C0(_DWORD *this)
{
  int result; // eax

  *(_DWORD *)((char *)this + *(_DWORD *)(*(this - 6) + 4) - 24) = &std::wiostream::`vftable';
  *(_DWORD *)((char *)this + *(_DWORD *)(*(this - 2) + 4) - 8) = &std::wostream::`vftable';
  result = *(this - 6);
  *(_DWORD *)((char *)this + *(_DWORD *)(result + 4) - 24) = &std::wistream::`vftable';
  return result;
}
