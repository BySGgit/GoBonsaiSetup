_DWORD *__thiscall sub_434C60(_DWORD *this, char a2)
{
  *this = &CDXUTScrollBar::`vftable';
  sub_4325B0(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
