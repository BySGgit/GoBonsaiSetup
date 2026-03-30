std::exception *__thiscall sub_44DD80(std::exception *this, struct exception *a2)
{
  std::exception::exception(this, a2);
  *(_DWORD *)this = &std::runtime_error::`vftable';
  return this;
}
