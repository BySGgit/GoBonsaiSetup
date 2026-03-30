void *__thiscall sub_432900(void *this, char a2)
{
  sub_4325B0(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
