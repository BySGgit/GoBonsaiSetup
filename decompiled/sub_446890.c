_DWORD *__thiscall sub_446890(_DWORD *this, char a2)
{
  *this = &std::locale::facet::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
