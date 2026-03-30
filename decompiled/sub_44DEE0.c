struct std::ios_base *__thiscall sub_44DEE0(struct std::ios_base *this, char a2)
{
  *(_DWORD *)this = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
