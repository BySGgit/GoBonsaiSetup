std::exception *__thiscall sub_4528FA(std::exception *this, char a2)
{
  sub_453AF0(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
