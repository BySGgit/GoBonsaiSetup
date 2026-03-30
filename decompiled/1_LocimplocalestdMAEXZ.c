void __thiscall std::locale::_Locimp::~_Locimp(void **this)
{
  *this = &off_4735B8;
  std::locale::_Locimp::_Locimp_dtor((struct std::locale::_Locimp *)this);
  if ( *(this + 6) )
    free(*(this + 6));
  *(this + 6) = 0;
  *this = &std::locale::facet::`vftable';
}
