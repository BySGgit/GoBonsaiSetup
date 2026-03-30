std::exception *__thiscall sub_4569AA(std::exception *this, struct exception *a2)
{
  std::exception::exception(this, a2);
  *(_DWORD *)this = &std::bad_exception::`vftable';
  return this;
}
