_DWORD *__thiscall sub_401CB0(_DWORD *this, char a2)
{
  *this = &Camera::`vftable';
  sub_4019F0(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
