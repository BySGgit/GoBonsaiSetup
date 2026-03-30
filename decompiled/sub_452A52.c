_DWORD *__thiscall sub_452A52(_DWORD *this, char a2)
{
  *this = &std::error_category::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
