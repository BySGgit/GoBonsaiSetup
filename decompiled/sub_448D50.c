void *__thiscall sub_448D50(void *this, char a2)
{
  void *v4; // [esp-4h] [ebp-8h]

  v4 = (void *)*((_DWORD *)this + 2);
  *(_DWORD *)this = &std::numpunct<wchar_t>::`vftable';
  operator delete[](v4);
  operator delete[](*((void **)this + 4));
  operator delete[](*((void **)this + 5));
  *(_DWORD *)this = &std::locale::facet::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
