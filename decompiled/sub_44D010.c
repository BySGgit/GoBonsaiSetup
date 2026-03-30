char *__thiscall sub_44D010(struct std::ios_base *this, char a2)
{
  char *v2; // esi

  v2 = (char *)this - 8;
  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this - 2) + 4) - 8) = &std::wostream::`vftable';
  *(_DWORD *)this = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(this);
  if ( (a2 & 1) != 0 )
    operator delete(v2);
  return v2;
}
