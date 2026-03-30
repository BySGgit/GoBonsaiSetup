std::exception *__thiscall sub_455DCF(std::exception *this, char a2)
{
  *(_DWORD *)this = &std::bad_exception::`vftable';
  sub_453AF0(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
