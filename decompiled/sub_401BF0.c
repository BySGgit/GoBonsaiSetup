void *__thiscall sub_401BF0(void *this, char a2)
{
  sub_4019F0(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
