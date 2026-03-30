std::_Lockit *__thiscall std::_Lockit::_Lockit(std::_Lockit *this, int a2)
{
  *(_DWORD *)this = a2;
  if ( a2 < 4 )
    unknown_libname_4(&stru_4D6D38 + a2);
  return this;
}
