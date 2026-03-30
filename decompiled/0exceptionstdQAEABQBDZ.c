std::exception *__thiscall std::exception::exception(std::exception *this, char **a2)
{
  *((_DWORD *)this + 1) = 0;
  *(_DWORD *)this = &off_473664;
  *((_BYTE *)this + 8) = 0;
  std::exception::_Copy_str(this, *a2);
  return this;
}
