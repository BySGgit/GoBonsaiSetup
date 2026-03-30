void *__thiscall sub_444AC0(void *this, char a2)
{
  sub_4443F0(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
