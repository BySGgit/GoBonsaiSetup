std::exception *__thiscall sub_4528DD(std::exception *this, struct exception *a2)
{
  std::exception::exception(this, a2);
  *(_DWORD *)this = &std::out_of_range::`vftable';
  return this;
}
