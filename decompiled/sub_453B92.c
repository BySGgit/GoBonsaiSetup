struct type_info *__thiscall sub_453B92(struct type_info *this, char a2)
{
  sub_453B82(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
