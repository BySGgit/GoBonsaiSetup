char *__thiscall sub_444A60(struct std::ios_base *this, char a2)
{
  char *v2; // esi

  v2 = (char *)this - 24;
  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this - 6) + 4) - 24) = &std::wiostream::`vftable';
  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this - 2) + 4) - 8) = &std::wostream::`vftable';
  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this - 6) + 4) - 24) = &std::wistream::`vftable';
  *(_DWORD *)this = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(this);
  if ( (a2 & 1) != 0 )
    operator delete(v2);
  return v2;
}
