void **__thiscall sub_433350(void **this, char a2)
{
  sub_433370(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
