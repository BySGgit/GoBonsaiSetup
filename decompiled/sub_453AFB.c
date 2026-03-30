std::exception *__thiscall sub_453AFB(std::exception *this, char *a2)
{
  std::exception::exception(this, (const char *const *)&a2);
  *(_DWORD *)this = &std::bad_cast::`vftable';
  return this;
}
