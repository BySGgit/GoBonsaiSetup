void *__thiscall sub_44CCD0(void *this, char a2)
{
  sub_44CFA0(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
