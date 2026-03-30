std::exception *__thiscall sub_4034D0(std::exception *this, char a2)
{
  *(_DWORD *)this = &std::bad_alloc::`vftable';
  sub_453AF0(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
