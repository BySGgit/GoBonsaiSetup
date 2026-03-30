_DWORD *__thiscall sub_410200(_DWORD *this, char a2)
{
  *this = &Sky::`vftable';
  `eh vector destructor iterator'(this + 49, 0xF0u, 10, sub_4102A0);
  sub_4019F0(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
