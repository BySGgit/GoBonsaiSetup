void **__thiscall sub_4355D0(void **this, char a2)
{
  *this = &CDXUTEditBox::`vftable';
  operator delete[](*(this + 20));
  if ( *(this + 24) )
    off_4D5254[0]((int)(this + 24));
  sub_4325B0(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
