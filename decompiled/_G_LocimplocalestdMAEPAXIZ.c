void **__thiscall std::locale::_Locimp::`scalar deleting destructor'(void **this, char a2)
{
  std::locale::_Locimp::~_Locimp(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
