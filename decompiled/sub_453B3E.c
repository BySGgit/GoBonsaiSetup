std::exception *__thiscall sub_453B3E(std::exception *this, char a2)
{
  *(_DWORD *)this = &off_473664;
  std::exception::_Tidy(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
