void *__thiscall sub_40D840(void *this, char a2)
{
  sub_40D860(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
