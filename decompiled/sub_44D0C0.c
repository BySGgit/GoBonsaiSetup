void *__thiscall sub_44D0C0(void *this, char a2)
{
  bool v3; // zf

  v3 = *((_DWORD *)this + 5) == 0;
  *(_DWORD *)this = &std::ctype<wchar_t>::`vftable';
  if ( !v3 )
    free(*((void **)this + 4));
  *(_DWORD *)this = &std::locale::facet::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
